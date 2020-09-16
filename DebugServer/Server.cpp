// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//
#include "./Server.h"
#include "./DebuggerSettings.h"
#include "./FindSubstringCaseInsensitive.h"
#include "./Log.h"

#include <Common/BreakPoint.h>
#include <Common/StackFrame.h>

#include <ruby.h>
#include <ruby/debug.h>
#include <ruby/encoding.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcomma"
#include <boost/lexical_cast.hpp>
#pragma clang diagnostic pop

#include <atomic>
#include <string>
#include <iostream>
#include <map>
#include <mutex>
#include <regex>
#include <thread>

using namespace SketchUp::RubyDebugger;

namespace {

VALUE GetRubyInterface(const char* s) {
  VALUE str_val = rb_str_new2(s);
  // Mark all strings as UTF-8 encoded.
  static int enc_index = rb_utf8_encindex();
  rb_enc_associate_index(str_val, enc_index);
  return str_val;
}

std::string GetRubyString(VALUE obj) {
  std::string s;
  if (TYPE(obj) != T_STRING) {
    s = StringValuePtr(obj);
    return s;
  }
  // Grab the string pointer.
  const char* source = RSTRING_PTR(obj);
  // Assign assuming utf8.
  s = source;
  return s;
}

// Get a Ruby object as a string.
std::string GetRubyObjectAsString(VALUE obj) {
  // See if it is a string.
  if (TYPE(obj) == T_STRING) {
    return GetRubyString(obj);
  }
  // Look for true and false.
  std::string objString;
  if (obj == Qtrue) {
    objString = "true";
  } else if (obj == Qfalse) {
    objString = "false";
  } else if (obj == Qnil) {
    objString = "nil";
  } else {
    // See if we can convert it to a string.
    int error = 0;
    VALUE s = rb_protect(rb_obj_as_string, obj, &error);
    if (0 == error && s != Qnil) {
      objString = StringValueCStr(s);
    }
  }
  return objString;
}

int GetRubyInt(VALUE obj) {
  return NUM2INT(obj);
}

// Function for wrap the call to rb_funcall2 so that we will not exit SketchUp
// if there is an error in the Ruby code that we are calling.
VALUE WrapFuncall(VALUE data) {
  // The data is all wrapped in a single Ruby array.
  if (!(TYPE(data) == T_ARRAY)) {
    return Qnil;
  }
  int argc = (int)RARRAY_LEN(data);
  if (argc < 2) {
    return Qnil;
  }
  VALUE* argv = RARRAY_PTR(data);
  VALUE obj = argv[0];
  ID func = (ID) NUM2LONG(argv[1]);

  argc -= 2;
  argv += 2;

  return rb_funcall2(obj, func, argc, argv);
}

VALUE ProtectFuncall(VALUE obj, ID func, int argc, ...) {
  // First check to see if we have a valid object, and if it responds to the
  // desired method.
  if (obj == Qnil) {
    return Qnil;
  }
  if (!rb_respond_to(obj, func)) {
    return Qnil;
  }
  // rb_protect takes a pointer to a function that only takes a single argument
  // so we need to package up all of the arguments into a single array.  The
  // array will contain the object that the function is called on, the ID of the
  // method to call and the arguments to pass to the method.

  // Allocate the array and push on the object and the method ID
  VALUE data = rb_ary_new2(argc + 2);
  rb_ary_push(data, obj);
  rb_ary_push(data, SIZET2NUM(func));

  // Now push on all of the arguments.
  if (argc > 0) {
    va_list ar;
    va_start(ar, argc);
    for (int i = 0; i < argc; i++) {
      rb_ary_push(data, va_arg(ar, VALUE));
    }
    va_end(ar);
  }

  // Now call the wrapped function inside a protected context.
  int error;
  VALUE result = rb_protect(WrapFuncall, data, &error);
  if (error) {
    result = rb_errinfo();
  }

  return result;
}

VALUE EvaluateRubyExpressionAsValue(const std::string& expr, VALUE binding) {
  VALUE str_to_eval = GetRubyInterface(expr.c_str());
  static ID eval_method_id = rb_intern("eval");
  VALUE val = ProtectFuncall(rb_mKernel, eval_method_id, 2, str_to_eval,
                             binding);
  return val;
}

Variable EvaluateRubyExpression(const std::string& expr, VALUE binding) {
  Variable var;
  var.name = expr;
  var.object_id = EvaluateRubyExpressionAsValue(expr, binding);
  var.has_children = rb_ivar_count(var.object_id) > 0;
  var.type = rb_obj_classname(var.object_id);
  var.value = GetRubyObjectAsString(var.object_id);
  return var;
}

VALUE DebugInspectorFunc(const rb_debug_inspector_t* di, void* data) {
  auto frames = reinterpret_cast<std::vector<StackFrame>*>(data);
  VALUE bt = rb_debug_inspector_backtrace_locations(di);
  int bt_count = (int)RARRAY_LEN(bt);
  for (int i=0; i < bt_count; ++i) {
    VALUE bt_val = RARRAY_PTR(bt)[i];
    VALUE path_val = rb_funcall(bt_val, rb_intern("path"), 0);
    if (path_val == Qnil)
      continue; // Probably the top stack when run from console
    StackFrame frame;
    frame.file = RSTRING_PTR(path_val);
    if (frame.file == "<main>")
      continue; // Top frame when called from Ruby Console
    frame.name = GetRubyObjectAsString(bt_val);
    VALUE line_val = rb_funcall(bt_val, rb_intern("lineno"), 0);
    frame.line = FIX2INT(line_val);
    frame.binding = rb_debug_inspector_frame_binding_get(di, i);
    frame.self = rb_debug_inspector_frame_self_get(di, i);
    frame.klass = rb_debug_inspector_frame_class_get(di, i);
    frames->push_back(frame);
  }
  return Qnil;
}

bool SortBreakPoints(const SketchUp::RubyDebugger::BreakPoint& bp0,
                     const SketchUp::RubyDebugger::BreakPoint& bp1) {
  return bp0.index < bp1.index;
}

} // end anonymous namespace

namespace SketchUp {
namespace RubyDebugger {

class Server::Impl {
public:
  Impl()
    : save_breakpoints_(false),
      tp_line_(Qnil),
      tp_return_(Qnil),
      tp_call_(Qnil),
      last_breakpoint_index(0),
      script_lines_hash_(Qnil),
      is_stopped_(false),
      break_at_next_line_(false),
      stepout_break_at_next_line_(false),
      stepover_break_at_next_line_(false),
      stepout_to_call_depth_(-1),
      stepover_to_call_depth_(-1),
      active_frame_index_(0),
      last_break_line_(0),
      call_depth_(0)
  {}

  void EnableTracePoint();

  void DisableTracePoint();

  BreakPoint* GetBreakPoint(const std::string& file, size_t line);

  BreakPoint* GetBreakPoint(size_t index);

  bool IsBreakPointActive(const BreakPoint &bp);

  void ReadScriptLinesHash();

  bool ResolveBreakPoint(BreakPoint& bp);

  void ResolveBreakPoints();

  void AddBreakPoint(BreakPoint& bp, bool is_resolved);

  void ClearBreakData();

  void ClearSuspensionData();

  void SaveBreakPoints() const;

  void LoadBreakPoints();

  void DoBreak(const std::string& file_path, size_t line);

  void DoBreak(const BreakPoint& bp);

  VALUE GetBinding(bool use_toplevel_binding);

  static std::vector<StackFrame> GetStackFrames();

  static void LineEvent(VALUE tp_val, void* data);

  static void ReturnEvent(VALUE tp_val, void* data);

  static void CallEvent(VALUE tp_val, void* data);

  std::unique_ptr<IDebuggerUI> ui_;

  bool save_breakpoints_;

  VALUE tp_line_;

  VALUE tp_return_;

  VALUE tp_call_;

  // Breakpoints with yet-unresolved file paths
  std::vector<BreakPoint> unresolved_breakpoints_;

  BreakPointsMap breakpoints_;

  size_t last_breakpoint_index;

  std::mutex break_point_mutex_;

  VALUE script_lines_hash_;

  std::map<std::string, std::vector<std::string>> script_lines_;

  std::atomic<bool> is_stopped_;

  std::atomic<bool> break_at_next_line_;

  std::atomic<bool> stepout_break_at_next_line_;

  std::atomic<bool> stepover_break_at_next_line_;

  std::atomic<size_t> stepout_to_call_depth_;

  std::atomic<size_t> stepover_to_call_depth_;

  std::vector<StackFrame> frames_;

  size_t active_frame_index_;

  std::string last_break_file_path_;

  size_t last_break_line_;

  size_t call_depth_;
};

void Server::Impl::ClearBreakData() {
  frames_.clear();
  is_stopped_ = false;
}

void Server::Impl::EnableTracePoint() {
  tp_line_ = rb_tracepoint_new(Qnil, RUBY_EVENT_LINE, &LineEvent, this);
  rb_tracepoint_enable(tp_line_);

  tp_return_ = rb_tracepoint_new(Qnil, RUBY_EVENT_RETURN |
      RUBY_EVENT_B_RETURN | RUBY_EVENT_C_RETURN | RUBY_EVENT_END,
      &ReturnEvent, this);
  rb_tracepoint_enable(tp_return_);

  tp_call_ = rb_tracepoint_new(Qnil, RUBY_EVENT_CALL | RUBY_EVENT_B_CALL |
      RUBY_EVENT_C_CALL | RUBY_EVENT_CLASS, &CallEvent, this);
  rb_tracepoint_enable(tp_call_);
  /*
  tp_raise_ = rb_tracepoint_new(Qnil, RUBY_EVENT_RAISE, &RaiseEvent, this);
  rb_tracepoint_enable(tp_raise_);
  */
}

void Server::Impl::DisableTracePoint() {
  if (tp_line_ != Qnil) {
    rb_tracepoint_disable(tp_line_);
    tp_line_ = Qnil;
  }
  if (tp_return_ != Qnil) {
    rb_tracepoint_disable(tp_return_);
    tp_return_ = Qnil;
  }
  if (tp_call_ != Qnil) {
    rb_tracepoint_disable(tp_call_);
    tp_call_ = Qnil;
  }
}

BreakPoint* Server::Impl::GetBreakPoint(const std::string& file, size_t line) {
  BreakPoint* bp = nullptr;
  auto it = breakpoints_.find(line);
  if (it != breakpoints_.end()) {
    auto itf = it->second.find(file);
    if (itf != it->second.end()) {
      bp = &(itf->second);
    }
  }
  return bp;
}

BreakPoint* Server::Impl::GetBreakPoint(size_t index) {
  // Check resolved breakpoints
  for (auto it = breakpoints_.begin(), ite = breakpoints_.end(); it != ite; ++it) {
    auto& map = it->second;
    for (auto itm = map.begin(), itme = map.end(); itm != itme; ++itm) {
      if (itm->second.index == index) return &(itm->second);
    }
  }

  // Check unresolved breakpoints
  for (auto it = unresolved_breakpoints_.begin(),
      ite = unresolved_breakpoints_.end(); it != ite; ++it) {
    if (index == it->index) return &(*it);
  }

  return nullptr;
}

bool Server::Impl::IsBreakPointActive(const BreakPoint &bp) {
  if (!bp.enabled) return false;
  if (bp.condition.empty()) return true;

  assert(!frames_.empty());
  VALUE binding = frames_.front().binding;
  assert(binding != Qnil);
  VALUE condition_value = EvaluateRubyExpressionAsValue(bp.condition, binding);
  return (condition_value == Qtrue);
}

void Server::Impl::SaveBreakPoints() const {
  if (save_breakpoints_) {
    Settings::SaveBreakPoints(breakpoints_, unresolved_breakpoints_);
  }
}

void Server::Impl::LoadBreakPoints() {
  if (save_breakpoints_) {
    Settings::LoadBreakPoints(breakpoints_, unresolved_breakpoints_,
                              last_breakpoint_index);
  }
}

#define EVENT_COMMON_CODE \
  rb_trace_arg_t* trace_arg = rb_tracearg_from_tracepoint(tp_val);\
  Server::Impl* server = reinterpret_cast<Server::Impl*>(data);\
  server->ClearBreakData();\
  std::string file_path = GetRubyString(rb_tracearg_path(trace_arg));\
  int line = GetRubyInt(rb_tracearg_lineno(trace_arg));\
  VALUE event_sym = rb_tracearg_event(trace_arg);\
//   Log(("\n*** Debugger event: " +\
//       GetRubyString(rb_sym_to_s(event_sym)) + ", " + file_path.c_str() + ":" +\
//       boost::lexical_cast<std::string>(line).c_str() + "\n").c_str())

static void ProcessLine(Server::Impl* server, const std::string& file_path,
                        int line) {
  if (server->call_depth_ == 0)
    server->call_depth_ = 1;

  if (server->break_at_next_line_ ||
      (server->stepover_break_at_next_line_ &&
       server->stepover_to_call_depth_ >= server->call_depth_) ||
      (server->stepout_break_at_next_line_)) {
    server->ClearSuspensionData();
    server->DoBreak(file_path, line);
  } else {
    // Try to resolve any unresolved breakpoints
    if (!server->unresolved_breakpoints_.empty())
      server->ResolveBreakPoints();

    auto bp = server->GetBreakPoint(file_path, line);
    if (bp != nullptr) {
      // Breakpoint hit
      server->DoBreak(*bp);
    }
  }
}

void Server::Impl::LineEvent(VALUE tp_val, void* data) {
  EVENT_COMMON_CODE;
  (void)event_sym; // Suppress unused warning

  ProcessLine(server, file_path, line);
}

void Server::Impl::ReturnEvent(VALUE tp_val, void* data) {
  EVENT_COMMON_CODE;

  // C returns complicate things, do not process their lines.
  static const ID id_c_return = rb_intern("c_return");
  if (SYM2ID(event_sym) != id_c_return)
    ProcessLine(server, file_path, line);

  if(server->call_depth_ > 0)
    --server->call_depth_;

  if (server->call_depth_ == server->stepout_to_call_depth_) {
    server->ClearSuspensionData();
    server->stepout_break_at_next_line_ = true;
  }
}

void Server::Impl::CallEvent(VALUE tp_val, void* data) {
  EVENT_COMMON_CODE;

  ++server->call_depth_;

  // C calls complicate things, do not process their lines.
  static const ID id_c_call = rb_intern("c_call");
  if (SYM2ID(event_sym) != id_c_call)
    ProcessLine(server, file_path, line);
}

void Server::Impl::ClearSuspensionData() {
  break_at_next_line_ = false;
  stepout_break_at_next_line_ = false;
  stepover_break_at_next_line_ = false;
  stepout_to_call_depth_ = -1;
  stepover_to_call_depth_ = -1;
}

// Performs necessary operations when a suspension point is hit.
void Server::Impl::DoBreak(const std::string& file_path, size_t line) {
  frames_ = GetStackFrames();
  last_break_file_path_ = file_path;
  last_break_line_ = line;
  is_stopped_ = true;
  ui_->Break(file_path, line); // Blocked here until ui says continue
  ClearBreakData();
}

// Performs necessary operations when a break point is hit.
void Server::Impl::DoBreak(const BreakPoint& bp) {
  frames_ = GetStackFrames();

  // NOTE: This check can only be performed after calling `GetStackFrames`.
  if (IsBreakPointActive(bp)) {
    last_break_file_path_ = bp.file;
    last_break_line_ = bp.line;
    is_stopped_ = true;
    ui_->Break(bp); // Blocked here until ui says continue
  }
  ClearBreakData();
}

static int EachKeyValFunc(VALUE key, VALUE val, VALUE data) {
  Server::Impl* impl = reinterpret_cast<Server::Impl*>(data);
  std::string file_path = StringValueCStr(key);

  // See if we added this file yet
  auto itf = impl->script_lines_.find(file_path);
  if (itf == impl->script_lines_.end()) {
    // Add the source lines vector
    auto& lines_vec = impl->script_lines_[file_path];
    // Add the source code
    int n = (int)RARRAY_LEN(val);
    lines_vec.reserve(n);
    for (int i = 0; i < n; ++i) {
      VALUE arr_val = RARRAY_PTR(val)[i];
      const char* val_str = StringValueCStr(arr_val);
      lines_vec.push_back(val_str);
    }
  }
  return ST_CONTINUE;
}

void Server::Impl::ReadScriptLinesHash() {
  if (script_lines_hash_ != Qnil) {
    rb_hash_foreach(script_lines_hash_, (int(*)(VALUE, VALUE, VALUE))EachKeyValFunc, (VALUE)this);
  }
}

bool Server::Impl::ResolveBreakPoint(BreakPoint& bp) {
  bool resolved = false;
  for (auto it = script_lines_.cbegin(),
       ite = script_lines_.cend(); it != ite; ++it) {
    const std::string& file_path = it->first;
    if (FindSubstringCaseInsensitive(file_path, bp.file) >= 0) {
      if (bp.line <= it->second.size()) {
        bp.file = file_path;
        resolved = true;
        break;
      }
    }
  }
  return resolved;
}

void Server::Impl::ResolveBreakPoints() {
  // Make sure we have the loaded files
  ReadScriptLinesHash();

  for (auto it = unresolved_breakpoints_.begin();
       it != unresolved_breakpoints_.end(); ) {
    if (ResolveBreakPoint(*it)) {
      AddBreakPoint(*it, true);
      it = unresolved_breakpoints_.erase(it);
    } else {
      ++it;
    }
  }
  SaveBreakPoints();
}

void Server::Impl::AddBreakPoint(BreakPoint& bp, bool is_resolved) {
  auto existing = GetBreakPoint(bp.file, bp.line);
  if (existing) {
    bp.index = existing->index;
    existing->enabled = bp.enabled;
    existing->condition = bp.condition;
    return;
  }

  if (bp.index == 0)
    bp.index = ++last_breakpoint_index;

  if (is_resolved) {
    auto& bp_map = breakpoints_[bp.line];
    bp_map.insert(std::make_pair(bp.file, bp));
  } else {
    unresolved_breakpoints_.push_back(bp);
  }
}

std::vector<StackFrame> Server::Impl::GetStackFrames() {
  std::vector<StackFrame> frames;
  rb_debug_inspector_open(&DebugInspectorFunc, &frames);
  return frames;
}

VALUE Server::Impl::GetBinding(bool use_toplevel_binding) {
  VALUE binding = 0;
  if (use_toplevel_binding) {
    binding = rb_const_get(rb_cObject, rb_intern("TOPLEVEL_BINDING"));
  } else if (!frames_.empty() && active_frame_index_ < frames_.size()) {
    const auto& cur_frame = frames_[active_frame_index_];
    binding = cur_frame.binding;
  } else {
    assert(false);
  }
  return binding;
}

Server::Server()
  : impl_(new Impl) {
}

Server::~Server(){
}

Server& Server::Instance() {
  static Server ds;
  return ds;
}

void Server::Start(std::unique_ptr<IDebuggerUI> ui,
                   const std::string& str_debugger) {
  impl_->EnableTracePoint();

  bool is_ide = ui->IsIDE();

  if (!is_ide) {
    // Let Ruby collect source files and code into this hash
    impl_->script_lines_hash_ = rb_hash_new();
    rb_define_global_const("SCRIPT_LINES__", impl_->script_lines_hash_);
  } else {
    impl_->script_lines_hash_ = Qnil;
  }

  impl_->LoadBreakPoints();
  impl_->ui_ = std::move(ui);
  impl_->ui_->Initialize(this, str_debugger);
  impl_->is_stopped_ = true;
  impl_->save_breakpoints_ = !is_ide;
  impl_->ui_->WaitForContinue();
  impl_->ClearBreakData();
}

void Server::Stop() {
  impl_->DisableTracePoint();
}

bool Server::AddBreakPoint(BreakPoint& bp, bool assume_resolved) {
  std::lock_guard<std::mutex> lock(impl_->break_point_mutex_);

  // Make sure we have the loaded files
  impl_->ReadScriptLinesHash();

  // Find a matching full file path for the given file.
  bool file_resolved = assume_resolved || impl_->ResolveBreakPoint(bp);
  impl_->AddBreakPoint(bp, file_resolved);
  impl_->SaveBreakPoints();
  return true;
}

bool Server::RemoveBreakPoint(size_t index) {
  bool removed = false;

  // Check resolved breakpoints
  for (auto it = impl_->breakpoints_.begin(), ite = impl_->breakpoints_.end();
       it != ite; ++it) {
    auto& map = it->second;
    for (auto itm = map.begin(), itme = map.end(); itm != itme; ++itm) {
      if (itm->second.index == index) {
        map.erase(itm);
        if (map.empty())
          impl_->breakpoints_.erase(it);
        removed = true;
        break;
      }
    }
    if (removed)
      break;
  }

  // Check unresolved breakpoints
  if (!removed) {
    for (auto it = impl_->unresolved_breakpoints_.begin(),
         ite = impl_->unresolved_breakpoints_.end(); it != ite; ++it) {
      if (index == it->index) {
        impl_->unresolved_breakpoints_.erase(it);
        removed = true;
        break;
      }
    }
  }

  if (removed) {
    impl_->SaveBreakPoints();
  }
  return removed;
}

bool Server::RemoveAllBreakPoints() {
  bool removed = false;

  if (!impl_->breakpoints_.empty()) {
    impl_->breakpoints_.clear();
    removed = true;
  }

  if (!impl_->unresolved_breakpoints_.empty()) {
    impl_->unresolved_breakpoints_.clear();
    removed = true;
  }

  if (removed) {
    impl_->SaveBreakPoints();
  }
  return removed;
}

bool Server::EnableBreakPoint(size_t index, bool enable) {
  auto bp = impl_->GetBreakPoint(index);
  if (bp) {
    bp->enabled = enable;
    return true;
  } else {
    return false;
  }
}

bool Server::ConditionBreakPoint(size_t index, const std::string& condition) {
  auto bp = impl_->GetBreakPoint(index);
  if (bp) {
    bp->condition = condition;
    return true;
  } else {
    return false;
  }
}

std::vector<BreakPoint> Server::GetBreakPoints() const {
  // Try to resolve any unresolved breakpoints
  impl_->ResolveBreakPoints();

  std::vector<BreakPoint> bps;

  // Add resolved breakpoints
  for (auto it = impl_->breakpoints_.cbegin(), ite = impl_->breakpoints_.cend();
       it != ite; ++it) {
    auto& map = it->second;
    for (auto itm = map.cbegin(), itme = map.cend(); itm != itme; ++itm) {
      bps.push_back(itm->second);
    }
  }

  // Add unresolved breakpoints
  std::copy(impl_->unresolved_breakpoints_.cbegin(),
            impl_->unresolved_breakpoints_.cend(), std::back_inserter(bps));

  // Sort by index
  std::sort(bps.begin(), bps.end(), &SortBreakPoints);
  return bps;
}

bool Server::IsStopped() const {
  return impl_->is_stopped_;
}

Variable Server::EvaluateExpression(const std::string& expr) {
 Variable eval_res;
 if (!impl_->frames_.empty() &&
     impl_->active_frame_index_ < impl_->frames_.size()) {
   const auto& cur_frame = impl_->frames_[impl_->active_frame_index_];
   eval_res = EvaluateRubyExpression(expr, cur_frame.binding);
 } else {
   eval_res.value = "Expression cannot be evaluated";
 }
 return eval_res;
}

std::vector<StackFrame> Server::GetStackFrames() const {
  return impl_->frames_;
}

void Server::ShiftActiveFrame(bool shift_up) {
  if (IsStopped()) {
    if (shift_up) {
      if (impl_->active_frame_index_ + 1 < impl_->frames_.size())
        impl_->active_frame_index_ += 1;
    } else {
      if (impl_->active_frame_index_ > 0)
        impl_->active_frame_index_ -= 1;
    }
  }
}

size_t Server::GetActiveFrameIndex() const {
  return impl_->active_frame_index_;
}

void Server::SetActiveFrameIndex(size_t index) const {
  impl_->active_frame_index_ = index;
}

void Server::Step() {
  if (IsStopped())
    impl_->break_at_next_line_ = true;
}

void Server::StepOver() {
  if (IsStopped()) {
    impl_->stepover_break_at_next_line_ = true;
    impl_->stepover_to_call_depth_ = impl_->call_depth_;
  }
}

void Server::StepOut() {
  if (IsStopped() && impl_->call_depth_ > 1) {
    impl_->stepout_to_call_depth_ = impl_->call_depth_ - 1;
  }
}

void Server::Pause() {
  if (!IsStopped()) {
    impl_->break_at_next_line_ = true;
  }
}

std::vector<std::pair<size_t, std::string>>
      Server::GetCodeLines(size_t beg_line, size_t end_line) const {
  std::vector<std::pair<size_t, std::string>> lines;
  if (IsStopped()) {
    impl_->ReadScriptLinesHash();

    auto itf = impl_->script_lines_.find(impl_->last_break_file_path_);
    if (itf != impl_->script_lines_.end()) {
      const auto& lines_vec = itf->second;
      const size_t expand_lines = 5;
      if (beg_line == 0) {
        beg_line = impl_->last_break_line_;
        if (beg_line > expand_lines)
          beg_line -= expand_lines;
        else
          beg_line = 1;
      }
      if (end_line == 0) {
        end_line = impl_->last_break_line_ + expand_lines;
      }
      if (end_line >= lines_vec.size() + 1)
        end_line = lines_vec.size();
      if (end_line >= beg_line) {
        for (size_t i = beg_line - 1; i < end_line; ++i) {
          lines.push_back(std::make_pair(i+1, lines_vec[i]));
        }
      }
    }
  }
  return lines;
}

size_t Server::GetBreakLineNumber() const {
  return impl_->last_break_line_;
}

IDebugServer::VariablesVector Server::GetVariables(const char* type,
    bool use_toplevel_binding) const {
  static const std::regex excluded_global_regex("\\$(?:KCODE|-K|=|IGNORECASE|FILENAME)");
  std::smatch match;

  VariablesVector vec;
  VALUE binding = impl_->GetBinding(use_toplevel_binding);
  if (binding != 0) {
    VALUE arr_val = EvaluateRubyExpressionAsValue(type, binding);
    int count = (int)RARRAY_LEN(arr_val);
    for (int i = 0; i < count; ++i) {
      VALUE var_val = RARRAY_PTR(arr_val)[i];
      Variable var;
      var.name = GetRubyObjectAsString(var_val);
      if (!var.name.empty() && !std::regex_match(var.name, match, excluded_global_regex)) {
        VALUE eval_val =
            EvaluateRubyExpressionAsValue(var.name, binding);
        var.object_id = eval_val;
        var.value = GetRubyObjectAsString(eval_val);
        var.type = rb_obj_classname(eval_val);
        var.has_children = rb_ivar_count(eval_val) > 0;
        vec.push_back(var);
      }
    }
  }
  return vec;
}

IDebugServer::VariablesVector Server::GetGlobalVariables() const {
  return GetVariables("global_variables", true);
}

IDebugServer::VariablesVector Server::GetLocalVariables() const {
  return GetVariables("local_variables", false);
}

IDebugServer::VariablesVector Server::GetInstanceVariables(size_t object_id) const {
  VariablesVector vec;
  VALUE var_array = rb_obj_instance_variables(object_id);
  size_t num_vars = RARRAY_LEN(var_array);
  for (size_t i = 0; i < num_vars; ++i) {
    VALUE var_val = RARRAY_PTR(var_array)[i];
    Variable var;
    var.name = GetRubyObjectAsString(var_val);
    if (!var.name.empty()) {
      VALUE instance_str_val = GetRubyInterface(var.name.c_str());
      VALUE eval_val = rb_obj_instance_eval(1, &instance_str_val, object_id);
      var.object_id = eval_val;
      var.value = GetRubyObjectAsString(eval_val);
      var.type = rb_obj_classname(eval_val);
      var.has_children = rb_ivar_count(eval_val) > 0;
      vec.push_back(var);
    }
  }
  return vec;
}

} // end namespace RubyDebugger
} // end namespace SketchUp
