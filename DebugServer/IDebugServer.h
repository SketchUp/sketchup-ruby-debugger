// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//
// License: Apache License, Version 2.0
#ifndef RDEBUGGER_DEBUGSERVER_IDEBUGSERVER_H_
#define RDEBUGGER_DEBUGSERVER_IDEBUGSERVER_H_

#include <vector>

namespace SketchUp {
namespace RubyDebugger {

struct BreakPoint;
struct StackFrame;

class IDebugServer {
public:

  virtual bool AddBreakPoint(BreakPoint& bp) = 0;

  virtual bool RemoveBreakPoint(size_t index) = 0;

  virtual std::vector<BreakPoint> GetBreakPoints() const = 0;

  virtual bool IsStopped() const = 0;

  virtual std::string EvaluateExpression(const std::string& expr) = 0;

  virtual std::vector<StackFrame> GetStackFrames() const = 0;

  virtual void ShiftActiveFrame(bool shift_up) = 0;

  virtual size_t GetActiveFrameIndex() const = 0;

  virtual void Step() = 0;

  virtual std::vector<std::pair<size_t, std::string>>
      GetCodeLines(size_t beg_line, size_t end_line) const = 0;

  virtual size_t GetBreakLineNumber() const = 0;
};

} // end namespace RubyDebugger
} // end namespace SketchUp

#endif // RDEBUGGER_DEBUGSERVER_IDEBUGSERVER_H_
