// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//
// License: Apache License, Version 2.0
#ifndef RDEBUGGER_DEBUGSERVER_SERVER_H_
#define RDEBUGGER_DEBUGSERVER_SERVER_H_

#include "./IDebugServer.h"
#include <DebugServer/UI/IDebuggerUI.h>

#include <memory>

namespace SketchUp {
namespace RubyDebugger {

class Server : public IDebugServer {
public:

  static Server& Instance();

  void Start(std::unique_ptr<IDebuggerUI> ui);

  virtual bool AddBreakPoint(BreakPoint& bp);

  virtual bool RemoveBreakPoint(size_t index);

  virtual std::vector<BreakPoint> GetBreakPoints() const;

  virtual bool IsStopped() const;

  virtual std::string EvaluateExpression(const std::string& expr);

  virtual std::vector<StackFrame> GetStackFrames() const;

  virtual void ShiftActiveFrame(bool shift_up);

  virtual size_t GetActiveFrameIndex() const;

  virtual void Step();

  virtual std::vector<std::pair<size_t, std::string>>
      GetCodeLines(size_t beg_line, size_t end_line) const;

  virtual size_t GetBreakLineNumber() const;

  class Impl; // Forward
private:
  Server();
  ~Server();

  std::unique_ptr<Impl> impl_;
};

} // end namespace RubyDebugger
} // end namespace SketchUp

#endif // RDEBUGGER_DEBUGSERVER_SERVER_H_
