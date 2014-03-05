// SketchUp Ruby API Debugger. Copyright 2014 Trimble Navigation Ltd.
// Authors:
// - Orhun Birsoy
//
#include "stdafx.h"
#include "./RDIP.h"

#include <DebugServer/IDebugServer.h>
#include <Common/BreakPoint.h>
#include <Common/StackFrame.h>
#include <boost/asio/ip/tcp.hpp>
#include <boost/make_shared.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio.hpp>
#include <boost/regex.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include <cassert>

namespace SketchUp {
namespace RubyDebugger {

class RDIP::Connection : public boost::enable_shared_from_this<RDIP::Connection>
{
public:
    Connection(boost::asio::io_service& service, int port, IDebugServer* server,
               boost::condition_variable& serverWaitCond,
               boost::mutex& serverWaitMutex,
               bool& serverCanContinue,
               boost::function<void(void)>& serverResponse,
               boost::function<void(void)>& processServerResponse);

    void wait();
    void stopAtBreakpoint(BreakPoint bp);
    void suspendAt(const std::string& file, size_t line);

private:
    void start(const boost::system::error_code& err);
    void handleCommand(const boost::system::error_code& err);
    void evaluateCommand(const std::string& cmd);
    void getVariables(bool local);
    void evalExpression();
    void sendVariables(std::string kind);

private:
    boost::asio::ip::tcp::socket mSocket;
    boost::asio::ip::tcp::acceptor mAcceptor;
    boost::asio::streambuf mReadBuffer;
    boost::asio::streambuf mWriteBuffer;
    IDebugServer* mServer;
    boost::condition_variable &mServerWaitCond;
    boost::mutex &mServerWaitMutex;
    bool &mServerCanContinue;
    boost::function<void(void)>& mServerResponse;
    boost::function<void(void)>& mProcessServerResponse;
    std::string mExpressionToEval;
    IDebugServer::VariablesVector mVariablesToSend;
};

RDIP::RDIP()
    : mSignalSet(mService, SIGINT, SIGTERM, SIGSEGV)
    , mServerCanContinue(false)
{}

RDIP::~RDIP()
{
    mService.stop();
    mServiceThread.join();
}

void RDIP::Initialize(IDebugServer* server, const std::string& str_debugger) {
    server_ = server;
    auto breakpoints = server_->GetBreakPoints();
    for(auto bp : breakpoints)
    {
        server_->RemoveBreakPoint(bp.index);
    }

    int port = 1234;
    const boost::regex reg_port("port=(\\d+)");
    boost::smatch match;
    if (regex_search(str_debugger, match, reg_port)) {
      port = boost::lexical_cast<int>(match[1]);
    }

    mServiceThread = boost::thread(boost::bind(&RDIP::RunService, this, port));
}

void RDIP::WaitForContinue() {
    boost::mutex::scoped_lock lock(mServerWaitMutex);
    mServerCanContinue = false;
    while(!mServerCanContinue)
    {
        if (mServerResponse)
        {
            mServerResponse();
            if (mProcessServerResponse)
                mService.post(mProcessServerResponse);
            mServerResponse.clear();
        }
        mServerWaitCond.wait(lock);
    }
    ::OutputDebugStringA("Let sketchup Start\n");
}

void RDIP::Break(BreakPoint bp) {
    mService.post(boost::bind(&RDIP::Connection::stopAtBreakpoint, mConnection.get(), bp));
    WaitForContinue();
}

void RDIP::Break(const std::string& file, size_t line) {
    mService.post(boost::bind(&RDIP::Connection::suspendAt, mConnection.get(), file, line));
    WaitForContinue();
}

void RDIP::RunService(int port) {
    mSignalSet.async_wait(std::bind(&RDIP::HandleFatalFailure, this, std::placeholders::_1, std::placeholders::_2));
    mConnection = boost::make_shared<Connection>(mService, port, server_,
        mServerWaitCond, mServerWaitMutex, mServerCanContinue, mServerResponse,
        mProcessServerResponse);
    mConnection->wait();
    mService.run();
}

void RDIP::HandleFatalFailure(const boost::system::error_code& err, int signal)
{}

using boost::asio::ip::tcp;
using boost::asio::ip::address;

RDIP::Connection::Connection(boost::asio::io_service& service, int port,
                             IDebugServer* server,
                             boost::condition_variable& serverWaitCond,
                             boost::mutex& serverWaitMutex,
                             bool& serverCanContinue,
                             boost::function<void(void)>& serverResponse,
                             boost::function<void(void)>& processServerResponse)
    : mSocket(service)
    , mAcceptor(service, tcp::endpoint(tcp::v4(), port))
    , mServer(server)
    , mServerWaitCond(serverWaitCond)
    , mServerWaitMutex(serverWaitMutex)
    , mServerCanContinue(serverCanContinue)
    , mServerResponse(serverResponse)
    , mProcessServerResponse(processServerResponse)
{}

void RDIP::Connection::wait()
{
    mAcceptor.async_accept(mSocket, boost::bind(&Connection::start, this, _1));
}

void RDIP::Connection::start(const boost::system::error_code& err)
{
    async_read_until(mSocket, mReadBuffer, "\n", boost::bind(&Connection::handleCommand, this, _1));
}

void RDIP::Connection::handleCommand(const boost::system::error_code& err)
{
    if(!err)
    {
        std::ostringstream out;
        out << &mReadBuffer;
        std::string str = out.str();
        ::OutputDebugStringA("\nCommand from IDE => ");
        ::OutputDebugStringA(str.c_str());
        std::vector<std::string> commands;
        boost::split(commands, str, boost::is_any_of(";"));
        for(const auto& cmd : commands)
        {
            evaluateCommand(boost::trim_copy(cmd));
        }
        //assert(write(mSocket, boost::asio::buffer("<message>some text</message>\n")) > 0);
        async_read_until(mSocket, mReadBuffer, "\n", boost::bind(&Connection::handleCommand, this, _1));
    }
    else
    {
        std::ostringstream os;
        os << err;
        ::OutputDebugStringA(os.str().c_str());
    }
}

static std::string encodeXml(const std::string& str)
{
    std::string encoded = boost::replace_all_copy(str, "&", "&amp;");
    boost::replace_all(encoded, "\"", "&quot;");
    boost::replace_all(encoded, "<", "&lt;");
    boost::replace_all(encoded, ">", "&gt;");
    boost::replace_all(encoded, "'", "&apos;");
    return encoded;
}

void RDIP::Connection::evaluateCommand(const std::string& cmd)
{
    static const boost::regex reg_brk("^\\s*b(?:reak)?\\s+(?:(.+):)?([^.:]+)$");
    static const boost::regex reg_brk_del("^\\s*del(?:ete)?(?:\\s+(\\d+))?$");
    static const boost::regex reg_start("^\\s*start$");
    static const boost::regex reg_exit("^\\s*exit?$");
    static const boost::regex reg_cont("^\\s*c(?:ont)?$");
    static const boost::regex reg_where("^\\s*w(?:here)?$");
    static const boost::regex reg_frame("^\\s*f(?:rame)? ([0-9]+)$");
    static const boost::regex reg_step("^\\s*s(?:tep)?\\s?");
    static const boost::regex reg_next("^\\s*n(?:ext)?$");
    static const boost::regex reg_finish("^\\s*finish?$");
    static const boost::regex reg_var_inspect("v i(?:nspect)?\\s+");
    static const boost::regex reg_thr_lst("^\\s*th(?:read)? l(?:ist)?$");
    static const boost::regex reg_eval("^\\s*p\\s+");
    static const boost::regex reg_var_local("^\\s*v(?:ar)? l(?:ocal)?$");
    static const boost::regex reg_var_global("^\\s*v(?:ar)? g(?:lobal)?$");
    static const boost::regex reg_var_instance("^\\s*v(?:ar)? instance (.+)*$");

    boost::smatch what;
    if(regex_match(cmd, what, reg_brk))
    {
        if(what.size() == 3) 
        {
            BreakPoint bp;
            bp.file = what[1];
            boost::replace_all(bp.file, "\\", "/");
            try 
            {
                std::string s2 = what[2];
                bp.line = std::atoi(s2.c_str());
                bp.enabled = true;
                if(mServer->AddBreakPoint(bp, true)) 
                {
                    std::ostringstream reply;
                    reply << "<breakpointAdded no=\"" << bp.index << "\" location=\"" << bp.file << ":" << bp.line << "\"/>\n";
                    write(mSocket, boost::asio::buffer(reply.str()));
                    ::OutputDebugStringA(reply.str().c_str());
                    ::OutputDebugStringA("    => Breakpoint added\n");
                }
                else 
                {
                    ::OutputDebugStringA("Adding breakpoint failed\n.");
                }
            }
            catch(boost::bad_lexical_cast&) {
            }
        }
    }
    else if(regex_match(cmd, what, reg_start) || 
            regex_match(cmd, what, reg_exit) ||
            regex_match(cmd, what, reg_cont))
    {
        boost::mutex::scoped_lock lock(mServerWaitMutex);
        mServerCanContinue = true;
        mServerWaitCond.notify_all();
    }
    else if(regex_match(cmd, what, reg_where))
    {
        auto frames = mServer->GetStackFrames();
        write(mSocket, boost::asio::buffer("<frames>\n"));

        size_t activeFrameIdx = mServer->GetActiveFrameIndex();
        for(size_t i = 0; i < frames.size(); ++i)
        {
            std::vector<std::string> splitFrameInfo;
            boost::split(splitFrameInfo, frames[i].name, boost::is_any_of(":"));

            // TODO(bugra): Fix this hack
            if (splitFrameInfo.size() < 3)
            {
              splitFrameInfo.push_back("0");
            }
            std::string frameNo = splitFrameInfo[0];
            std::string file = encodeXml(splitFrameInfo[1]);
            std::string line = encodeXml(splitFrameInfo[2]);
            // TODO(bugra): Another hack! the top frame sometimes has a weird
            // name with "call" in it. Skip those to prevent IDE confusion.
            if (line.find("call") != std::string::npos)
              continue;

            std::string msg;
            if(activeFrameIdx != i)
            {
                boost::format fmt("<frame no=\"%1%\" file=\"%2%\" line=\"%3%\"/>");
                fmt % i % (frameNo + ":" + file) % line;
                msg = fmt.str();
            }
            else
            {
                boost::format fmt("<frame no=\"%1%\" file=\"%2%\" line=\"%3%\" current=\"yes\"/>");
                fmt % i % (frameNo + ":" + file) % line;
                msg = fmt.str();
            }

            ::OutputDebugStringA(msg.c_str());
            write(mSocket, boost::asio::buffer(msg));
        }
        write(mSocket, boost::asio::buffer("</frames>\n"));
    }
    else if(regex_match(cmd, what, reg_thr_lst))
    {
        write(mSocket, boost::asio::buffer("<threads>\n"));
        std::ostringstream reply;
        //reply << "<thread id=\"1\" status=\"run\" pid=\"" << GetCurrentProcessId() << "\"/>\n";
        reply << "<thread id=\"1\" status=\"run\"/>\n";
        write(mSocket, boost::asio::buffer(reply.str()));
        write(mSocket, boost::asio::buffer("</threads>\n"));
    }
    else if(regex_match(cmd, what, reg_frame))
    { 
        if(what.size() == 2)
        {
            size_t frameIndex = boost::lexical_cast<size_t>(what[1]);
            mServer->SetActiveFrameIndex(frameIndex);
        }
    }
    else if(regex_match(cmd, what, reg_step))
    {
        mServer->Step();
        boost::mutex::scoped_lock lock(mServerWaitMutex);
        mServerCanContinue = true;
        mServerWaitCond.notify_all();
    }
    else if(regex_match(cmd, what, reg_finish))
    {
        mServer->StepOut();
        boost::mutex::scoped_lock lock(mServerWaitMutex);
        mServerCanContinue = true;
        mServerWaitCond.notify_all();
    }
    else if(regex_match(cmd, what, reg_next))
    {
        mServer->StepOver();
        boost::mutex::scoped_lock lock(mServerWaitMutex);
        mServerCanContinue = true;
        mServerWaitCond.notify_all();
    }
    else if(regex_search(cmd, what, reg_var_inspect))
    {
        mExpressionToEval = what.suffix();
        mServerResponse = boost::bind(&RDIP::Connection::evalExpression, this);
        mProcessServerResponse = boost::bind(&RDIP::Connection::sendVariables, this, "watch");
        mServerWaitCond.notify_all();
    }
    else if(regex_search(cmd, what, reg_eval))
    {
        std::string expression_to_evaluate_ = what.suffix();
        OutputDebugStringA("reg_eval\n");
    }
    else if(regex_match(cmd, what, reg_var_local))
    {
        // Local variables must be retrieved in the server thread. Wake it up
        // and have it call us.
        mServerResponse = boost::bind(&RDIP::Connection::getVariables, this, true);
        mProcessServerResponse = boost::bind(&RDIP::Connection::sendVariables, this, "local");
        mServerWaitCond.notify_all();
    }
    else if(regex_match(cmd, what, reg_var_global))
    {
        // Global variables must be retrieved in the server thread. Wake it up
        // and have it call us.
        mServerResponse = boost::bind(&RDIP::Connection::getVariables, this, false);
        mProcessServerResponse = boost::bind(&RDIP::Connection::sendVariables, this, "global");
        mServerWaitCond.notify_all();
    }
    else if(regex_match(cmd, what, reg_var_instance))
    {
        std::string varName = what[1];
        OutputDebugStringA(varName.c_str());
        OutputDebugStringA("\n");
        //auto variables = mServer->GetLocalVariables();

        write(mSocket, boost::asio::buffer("<variables>\n"));
        //for(const auto var : variables)
        //{
        //    boost::format fmt("<variable name=\"%1%\" kind=\"local\" value=\"%2%\" type=\"Unknown\" hasChildren=\"false\" objectId=\"0xdead0000\"/>");
        //    fmt % var.first % var.second;
        //    write(mSocket, boost::asio::buffer(fmt.str()));
        //}
        write(mSocket, boost::asio::buffer("</variables>\n"));
    }
    else
    {
        OutputDebugStringA("Unknown command : ");
        OutputDebugStringA(cmd.c_str());
        OutputDebugStringA("\n");
    }
}

void RDIP::Connection::stopAtBreakpoint(BreakPoint bp)
{
    std::ostringstream ss;
    ss << "<breakpoint file=\"" << bp.file << "\" line=\"" << bp.line << "\" threadId=\"1\"/>\n";
    OutputDebugStringA("sending stopAtBreakpoint => ");

    auto str = ss.str(); //boost::replace_all_copy(ss.str(), "/", "\\");
    OutputDebugStringA(str.c_str());
    write(mSocket, boost::asio::buffer(str));
}

void RDIP::Connection::suspendAt(const std::string& file, size_t line)
{
    std::ostringstream ss;
    ss << "<suspended file=\"" << file << "\" line=\"" << line << "\" threadId=\"1\" frames=\"1\"/>\n";
    OutputDebugStringA("sending suspendAt => ");

    auto str = ss.str();
    OutputDebugStringA(str.c_str());
    write(mSocket, boost::asio::buffer(str));
}

void RDIP::Connection::getVariables(bool local)
{
    mVariablesToSend = local ? mServer->GetLocalVariables() :
                               mServer->GetGlobalVariables();
}

void RDIP::Connection::sendVariables(std::string kind)
{
    OutputDebugStringA("sending variables\n");
    std::string send_str = "<variables>\n";
    for(const auto var : mVariablesToSend)
    {
        boost::format fmt("<variable name=\"%s\" kind=\"%s\" value=\"%s\" type=\"%s\" hasChildren=\"%s\" objectId=\"%x\"/>\n");
        std::string value = encodeXml(var.value);
        std::string name = encodeXml(var.name);
        fmt % name % kind % value % var.type %
             (var.has_children ? "true" : "false") % var.object_id;
        send_str += fmt.str();
    }
    send_str += "</variables>\n";
    OutputDebugStringA(send_str.c_str());
    write(mSocket, boost::asio::buffer(send_str));
    mVariablesToSend.clear();
}

void RDIP::Connection::evalExpression()
{
    mVariablesToSend.clear();
    if (!mExpressionToEval.empty())
    {
        Variable var;
        var.name = mExpressionToEval;
        var.object_id = 0;
        var.value = mServer->EvaluateExpression(mExpressionToEval);
        mVariablesToSend.push_back(var);
    }
}

} // end namespace RubyDebugger
} // end namespace SketchUp
