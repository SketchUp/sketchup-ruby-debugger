// SketchUp Ruby API Debugger. Copyright 2014 Trimble Navigation Ltd.
// Authors:
// - Orhun Birsoy
// - Bugra Barin
// - Aaron Hill (@Seraku) - Refactored ruby-debug-ide protocol implementation.
//
#include "./RDIP.h"

#include <condition_variable>
#include <functional>
#include <mutex>
#include <regex>
#include <queue>
#include <thread>

#include <boost/algorithm/string.hpp>
#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/lexical_cast.hpp>

#include <DebugServer/IDebugServer.h>
#include <DebugServer/Log.h>
#include <Common/BreakPoint.h>
#include <Common/StackFrame.h>

namespace SketchUp {
namespace RubyDebugger {

static const int DefaultPort = 1234;

class RDIP::Impl : public std::enable_shared_from_this<Impl> {
public:
  Impl(IDebugServer *server, int port);
  ~Impl();

  bool isClientConnected() const { return socket_.is_open(); }

  void postResponse(const std::string &response);
  void wait();

private:
  void handleError(const boost::system::error_code &err, int signal);
  void closeConnection();

  void doAccept();
  void handleAccept(const boost::system::error_code &err);

  void doReadUntil();
  void handleReadUntil(const boost::system::error_code &err, size_t bytes);

  void evaluateCommand(const std::string &command);
  void sendResponse(const std::string &response);
  void sendVariables(const std::string &kind, const std::vector<Variable> &variables);

  void notifyWait(bool stop_waiting);
  void queueWork(const std::function<void(void)> &work);
  void processWorkQueue();

  void doCheckWorkQueue();
  void handleCheckWorkQueue(const boost::system::error_code &err);

  IDebugServer *server_;

  boost::asio::io_service io_service_;
  boost::asio::signal_set signal_set_;
  std::thread service_thread_;

  boost::asio::ip::tcp::socket socket_;
  boost::asio::ip::tcp::acceptor acceptor_;
  boost::asio::streambuf read_buffer_;

  bool is_waiting_;
  bool stop_waiting_;
  std::mutex wait_mutex_;
  std::condition_variable wait_cond_;

  std::queue<std::function<void(void)>> work_queue_;
  std::mutex work_queue_mutex_;
  boost::asio::deadline_timer work_queue_timer_;
};

RDIP::Impl::Impl(IDebugServer *server, int port)
  : server_(server)
  , signal_set_(io_service_, SIGINT, SIGTERM, SIGSEGV)
  , socket_(io_service_)
  , acceptor_(io_service_, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
  , is_waiting_(false)
  , stop_waiting_(false)
  , work_queue_timer_(io_service_) {
  signal_set_.async_wait(std::bind(&RDIP::Impl::handleError, this, std::placeholders::_1, std::placeholders::_2));

  service_thread_ = std::thread([this](){
    doAccept();
    io_service_.run();
  });
}

RDIP::Impl::~Impl() {
  closeConnection();
  if (!io_service_.stopped()) io_service_.stop();
  if (service_thread_.joinable()) service_thread_.join();
}

void RDIP::Impl::postResponse(const std::string &response) {
  io_service_.post(std::bind(&RDIP::Impl::sendResponse, this, response));
}

void RDIP::Impl::wait() {
  std::unique_lock<std::mutex> lock(wait_mutex_);

  is_waiting_ = true;
  stop_waiting_ = false;
  do {
    wait_cond_.wait(lock);
    processWorkQueue();
  } while (!stop_waiting_);
  is_waiting_ = false;
}

void RDIP::Impl::handleError(const boost::system::error_code &err, int signal) {
  LOG(FMT("boost::system::error_code: " << err << ", signal: " << signal));
  closeConnection();
}

void RDIP::Impl::closeConnection() {
  if (socket_.is_open()) {
    LOG("Closing connection to ruby-debug-ide client.");
    socket_.shutdown(boost::asio::socket_base::shutdown_both);
    socket_.close();

    server_->RemoveAllBreakPoints();
  }
  notifyWait(true);
}

void RDIP::Impl::doAccept() {
  if (socket_.is_open()) return;

  LOG("Waiting for connection from ruby-debug-ide client.");
  acceptor_.async_accept(socket_, std::bind(&RDIP::Impl::handleAccept, this, std::placeholders::_1));
}

void RDIP::Impl::handleAccept(const boost::system::error_code &err) {
  if (err) {
    LOG(FMT("boost::system::error_code: " << err));
    closeConnection();
    doAccept();
    return;
  }

  LOG("Accepted connection from ruby-debug-ide client.");
  doReadUntil();
}

void RDIP::Impl::doReadUntil() {
  boost::asio::async_read_until(socket_, read_buffer_, "\n", std::bind(&RDIP::Impl::handleReadUntil, this, std::placeholders::_1, std::placeholders::_2));
}

void RDIP::Impl::handleReadUntil(const boost::system::error_code &err, size_t bytes) {
  if (err) {
    LOG(FMT("boost::system::error_code: " << err));
    closeConnection();
    doAccept();
    return;
  }

  std::istream is(&read_buffer_);
  std::vector<char> chars(bytes);
  is.read(chars.data(), bytes);
  std::string commands(chars.data(), bytes);

  static const std::regex separator_regex("[;\r\n]+");
  static const std::sregex_token_iterator end;
  for (std::sregex_token_iterator iter(commands.begin(), commands.end(), separator_regex, -1); iter != end; ++iter) {
    evaluateCommand(boost::trim_copy(iter->str()));
  }

  doReadUntil();
}

static std::string escapeXml(const std::string& str) {
  std::ostringstream escaped;
  std::for_each(str.begin(), str.end(), [&](char ch){
    // Strip all control characters.
    if (ch < ' ') return;

    switch (ch) {
      case '"': escaped << "&quot;"; break;
      case '\'': escaped << "&apos;"; break;
      case '<': escaped << "&lt;"; break;
      case '>': escaped << "&gt;"; break;
      case '&': escaped << "&amp;"; break;
      default: escaped << ch; break;
    }
  });
  return escaped.str();
}

void RDIP::Impl::evaluateCommand(const std::string &command) {
  LOG(FMT("Command from ruby-debug-ide client: " << command));
  std::smatch match;
  std::ostringstream response;

  // This represents only a subset of all commands defined by ruby-debug-ide.
  //
  // For reference, here are the commands that are not yet supported:
  //    catch, restart, detach, pp, expression_info,
  //    include, exclude, file-filter, up, down, jump, load,
  //    set_type, thread switch, thread inspect, thread stop,
  //    thread current, thread resume, var constant

  // Breakpoint-related commands.
  static const std::regex add_breakpoint_regex("^b(?:reak)?\\s+(.+?):(\\d+)(?:\\s+if\\s+(.+))?$", std::regex_constants::icase);
  static const std::regex breakpoints_regex("^(?:info\\s*)?b(?:reak)?$", std::regex_constants::icase);
  static const std::regex condition_regex("^cond(?:ition)?\\s+(\\d+)(?:\\s+(.+))?$", std::regex_constants::icase);
  static const std::regex delete_breakpoint_regex("^del(?:ete)?(?:\\s+(\\d+))?$", std::regex_constants::icase);
  static const std::regex enable_breakpoint_regex("^(en|dis)(?:able)?\\s+breakpoints((?:\\s+\\d+)+)$", std::regex_constants::icase);

  if (std::regex_match(command, match, add_breakpoint_regex)) {
    BreakPoint bp;
    bp.file = match[1];
    boost::replace_all(bp.file, "\\", "/");
    bp.line = boost::lexical_cast<size_t>(match[2]);
    bp.enabled = true;
    if (match[3].matched) bp.condition = match[3];
    server_->AddBreakPoint(bp, true);
    response << "<breakpointAdded no=\"" << bp.index << "\" location=\"" << escapeXml(bp.file) << ':' << bp.line << "\" />";
  } else if (std::regex_match(command, match, breakpoints_regex)) {
    response << "<breakpoints>";
    auto bps = server_->GetBreakPoints();
    std::for_each(bps.begin(), bps.end(), [&](auto &bp){
      response << "<breakpoint n=\"" << bp.index << "\" file=\"" << escapeXml(bp.file) << "\" line=\"" << bp.line << "\" />";
    });
    response << "</breakpoints>";
  } else if (std::regex_match(command, match, condition_regex)) {
    size_t index = boost::lexical_cast<size_t>(match[1]);
    std::string condition;
    if (match[2].matched) condition = match[2];
    if (server_->ConditionBreakPoint(index, condition)) {
      response << "<conditionSet bp_id=\"" << index << "\" />";
    }
  } else if (std::regex_match(command, match, delete_breakpoint_regex)) {
    if (match[1].matched) {
      size_t index = boost::lexical_cast<size_t>(match[1]);
      server_->RemoveBreakPoint(index);
      response << "<breakpointDeleted no=\"" << index << "\" />";
    } else {
      server_->RemoveAllBreakPoints();
    }
  } else if (std::regex_match(command, match, enable_breakpoint_regex)) {
    bool enable = std::tolower(match.str(1)[0]) == 'e';
    std::string indices = match[2];
    static const std::regex index_regex("\\d+");
    static const std::sregex_token_iterator end;
    for (std::sregex_token_iterator iter(indices.begin(), indices.end(), index_regex, 0); iter != end; ++iter) {
      size_t index = boost::lexical_cast<size_t>(iter->str());
      if (server_->EnableBreakPoint(index, enable)) {
        response << "<breakpoint" << (enable ? "Enabled" : "Disabled") << " bp_id=\"" << index << "\" />";
      }
    }
  }

  // Control-related commands.
  static const std::regex continue_regex("^c(?:ont)?$", std::regex_constants::icase);
  static const std::regex finish_regex("^fin(?:ish)?$", std::regex_constants::icase);
  static const std::regex next_regex("^n(?:ext)?$", std::regex_constants::icase);
  static const std::regex pause_regex("^(?:pause|i(?:nterrupt)?)$", std::regex_constants::icase);
  static const std::regex quit_regex("^(?:q(?:uit)?|exit)$", std::regex_constants::icase);
  static const std::regex start_regex("^start$", std::regex_constants::icase);
  static const std::regex step_regex("^s(?:tep)?$", std::regex_constants::icase);

  if (std::regex_match(command, match, continue_regex)) {
    notifyWait(true);
  } else if (std::regex_match(command, match, finish_regex)) {
    server_->StepOut();
    notifyWait(true);
  } else if (std::regex_match(command, match, next_regex)) {
    server_->StepOver();
    notifyWait(true);
  } else if (std::regex_match(command, match, pause_regex)) {
    server_->Pause();
  } else if (std::regex_match(command, match, quit_regex)) {
    notifyWait(true);
    closeConnection();
    doAccept();
  } else if (std::regex_match(command, match, start_regex)) {
    notifyWait(true);
  } else if (std::regex_match(command, match, step_regex)) {
    server_->Step();
    notifyWait(true);
  }

  // State-related commands.
  static const std::regex frame_regex("^f(?:rame)?\\s+(\\d+)$", std::regex_constants::icase);
  static const std::regex thread_list_regex("^th(?:read)?\\s+l(?:ist)?$", std::regex_constants::icase);
  static const std::regex where_regex("^(?:w(?:here)?|bt|backtrace)$", std::regex_constants::icase);

  if (std::regex_match(command, match, frame_regex)) {
    const auto &frames = server_->GetStackFrames();
    size_t index = boost::lexical_cast<size_t>(match[1]);
    if (index >= 1) {
      --index;
      if (index < frames.size()) {
        server_->SetActiveFrameIndex(index);
      }
    }
  } else if (std::regex_match(command, match, thread_list_regex)) {
    response << "<threads><thread id=\"1\" status=\"run\" /></threads>";
  } else if (std::regex_match(command, match, where_regex)) {
    response << "<frames>";
    const auto &frames = server_->GetStackFrames();
    size_t activeIndex = server_->GetActiveFrameIndex();
    for (size_t index = 0; index < frames.size(); ++index) {
      auto &frame = frames[index];
      response << "<frame no=\"" << (index + 1) << "\" file=\"" << escapeXml(frame.file) << "\" line=\"" << frame.line << "\"";
      if (activeIndex == index) response << " current=\"yes\"";
      response << " />";
    }
    response << "</frames>";
  }

  // Variable-related commands.
  static const std::regex eval_regex("^(?:p|e(?:val)?)\\s+(.+)$", std::regex_constants::icase);
  static const std::regex inspect_regex("^v(?:ar)?\\s+inspect\\s+(.+)$", std::regex_constants::icase);
  static const std::regex var_global_regex("^v(?:ar)?\\s+g(?:lobal)?$", std::regex_constants::icase);
  static const std::regex var_instance_regex("^v(?:ar)?\\s+i(?:nstance)?\\s+(?:0x)?([\\da-f]+)$", std::regex_constants::icase);
  static const std::regex var_local_regex("^v(?:ar)?\\s+l(?:ocal)?$", std::regex_constants::icase);

  if (std::regex_match(command, match, eval_regex)) {
    std::string expression = match[1];
    if (!is_waiting_) {
      response << "<eval expression=\"" << escapeXml(expression) << "\" value=\"Expression cannot be evaluated\" />";
    } else {
      queueWork([=](){
        const auto &var = server_->EvaluateExpression(expression);
        std::ostringstream response;
        response << "<eval expression=\"" << escapeXml(var.name) << "\" value=\"" << escapeXml(var.value) << "\" />";
        postResponse(response.str());
      });
    }
  } else if (std::regex_match(command, match, inspect_regex)) {
    std::string expression = match[1];
    if (!is_waiting_) {
      std::vector<Variable> variables;
      sendVariables("watch", variables);
    } else {
      queueWork([=](){
        std::vector<Variable> variables;
        variables.push_back(server_->EvaluateExpression(expression));
        sendVariables("watch", variables);
      });
    }
  } else if (std::regex_match(command, match, var_global_regex)) {
    if (!is_waiting_) {
      std::vector<Variable> variables;
      sendVariables("global", variables);
    } else {
      queueWork([=](){ sendVariables("global", server_->GetGlobalVariables()); });
    }
  } else if (std::regex_match(command, match, var_instance_regex)) {
    std::istringstream iss(match[1]);
    size_t object_id;
    iss >> std::hex >> object_id;
    if (!is_waiting_) {
      std::vector<Variable> variables;
      sendVariables("instance", variables);
    } else {
      queueWork([=](){ sendVariables("instance", server_->GetInstanceVariables(object_id)); });
    }
  } else if (std::regex_match(command, match, var_local_regex)) {
    if (!is_waiting_) {
      std::vector<Variable> variables;
      sendVariables("local", variables);
    } else {
      queueWork([=](){ sendVariables("local", server_->GetLocalVariables()); });
    }
  }

  sendResponse(response.str());
}

void RDIP::Impl::sendResponse(const std::string &response) {
  std::string str = boost::trim_copy(response);
  if (str.empty()) return;
  str.append("\r\n");

  if (socket_.is_open()) {
    LOG(FMT("Sending response to ruby-debug-ide client:\r\n" << str.substr(0, 4000)));
    boost::asio::write(socket_, boost::asio::buffer(str));
  } else {
    LOG(FMT("No ruby-debug-ide client connected.  Unable to send response:\r\n" << str.substr(0, 4000)));
  }
}

void RDIP::Impl::sendVariables(const std::string &kind, const std::vector<Variable> &variables) {
  std::ostringstream response;
  response << "<variables>";
  for (const auto &var : variables) {
    response << "<variable name=\"" << escapeXml(var.name) << "\" kind=\"" << kind << "\" value=\"" << escapeXml(var.value) << "\" type=\"" << var.type << "\" hasChildren=\"" << (var.has_children ? "true" : "false") << "\" objectId=\"0x" << std::hex << var.object_id << "\" />";
  }
  response << "</variables>";
  postResponse(response.str());
}

void RDIP::Impl::notifyWait(bool stop_waiting) {
  std::lock_guard<std::mutex> lock(wait_mutex_);
  if (stop_waiting) stop_waiting_ = true;
  wait_cond_.notify_all();
}

void RDIP::Impl::queueWork(const std::function<void(void)> &work) {
  std::lock_guard<std::mutex> lock(work_queue_mutex_);
  work_queue_.push(work);
  notifyWait(false);
  doCheckWorkQueue();
}

void RDIP::Impl::processWorkQueue() {
  std::lock_guard<std::mutex> lock(work_queue_mutex_);
  while (!work_queue_.empty()) {
    work_queue_.front()();
    work_queue_.pop();
  }
}

void RDIP::Impl::doCheckWorkQueue() {
  work_queue_timer_.expires_from_now(boost::posix_time::seconds(1));
  work_queue_timer_.async_wait(std::bind(&RDIP::Impl::handleCheckWorkQueue, this, std::placeholders::_1));
}

void RDIP::Impl::handleCheckWorkQueue(const boost::system::error_code &err) {
  if (err) return;

  std::lock_guard<std::mutex> lock(work_queue_mutex_);
  if (!work_queue_.empty()) {
    notifyWait(false);
    doCheckWorkQueue();
  }
}

RDIP::RDIP() : wait_for_client_(false) { }
RDIP::~RDIP() { }

void RDIP::Initialize(IDebugServer* server, const std::string& str_debugger) {
  LOG(FMT("Initializing ruby-debug-ide protocol: -rdebug \"" << str_debugger << '"'));

  server_ = server;
  std::smatch match;

  int port = DefaultPort;
  static const std::regex port_regex("\\bport\\s*=\\s*(\\d+)\\b", std::regex_constants::icase);
  if (std::regex_search(str_debugger, match, port_regex)) {
    port = boost::lexical_cast<int>(match[1]);
  }

  static const std::regex wait_regex("\\bwait\\b", std::regex_constants::icase);
  wait_for_client_ = std::regex_search(str_debugger, match, wait_regex);

  impl_ = std::make_shared<Impl>(server_, port);
}

void RDIP::WaitForContinue() {
  if (!wait_for_client_ && !impl_->isClientConnected()) return;

  LOG("Pausing SketchUp/Ruby execution.");
  impl_->wait();
  LOG("Resuming SketchUp/Ruby execution.");
}

void RDIP::Break(BreakPoint bp) {
  if (!impl_->isClientConnected()) return;

  std::ostringstream response;
  response << "<breakpoint file=\"" << escapeXml(bp.file) << "\" line=\"" << bp.line << "\" threadId=\"1\" />";
  impl_->postResponse(response.str());
  WaitForContinue();
}

void RDIP::Break(const std::string& file, size_t line) {
  if (!impl_->isClientConnected()) return;

  std::ostringstream response;
  response << "<suspended file=\"" << escapeXml(file) << "\" line=\"" << line << "\" threadId=\"1\" frames=\"1\" />";
  impl_->postResponse(response.str());
  WaitForContinue();
}

} // end namespace RubyDebugger
} // end namespace SketchUp