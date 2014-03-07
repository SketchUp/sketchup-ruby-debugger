// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//
#ifndef RDEBUGGER_DEBUGSERVER_SERVER_H_
#define RDEBUGGER_DEBUGSERVER_SERVER_H_

#include "./IDebugServer.h"
#include <DebugServer/UI/IDebuggerUI.h>

#include <memory>

namespace SketchUp {
namespace RubyDebugger {

// Debugger server implementation 
class Server : public IDebugServer {
public:

  static Server& Instance();

  void Start(std::unique_ptr<IDebuggerUI> ui, const std::string& str_debugger);

  virtual bool AddBreakPoint(BreakPoint& bp, bool assume_resolved);

  virtual bool RemoveBreakPoint(size_t index);

  virtual std::vector<BreakPoint> GetBreakPoints() const;

  virtual bool IsStopped() const;

  virtual Variable EvaluateExpression(const std::string& expr);

  virtual std::vector<StackFrame> GetStackFrames() const;

  virtual void ShiftActiveFrame(bool shift_up);

  virtual size_t GetActiveFrameIndex() const;

  virtual void SetActiveFrameIndex(size_t index) const;

  virtual void Step();

  virtual void StepOver();

  virtual void StepOut();

  virtual std::vector<std::pair<size_t, std::string>>
      GetCodeLines(size_t beg_line, size_t end_line) const;

  virtual size_t GetBreakLineNumber() const;

  virtual VariablesVector GetGlobalVariables() const;

  virtual VariablesVector GetLocalVariables() const;

  virtual VariablesVector GetInstanceVariables(size_t object_id) const;

  class Impl; // Forward
private:
  Server();
  ~Server();

  VariablesVector GetVariables(const char* type,
                               bool use_toplevel_binding) const;

  std::unique_ptr<Impl> impl_;
};

} // end namespace RubyDebugger
} // end namespace SketchUp

#endif // RDEBUGGER_DEBUGSERVER_SERVER_H_
