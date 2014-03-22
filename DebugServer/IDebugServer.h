// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//
#ifndef RDEBUGGER_DEBUGSERVER_IDEBUGSERVER_H_
#define RDEBUGGER_DEBUGSERVER_IDEBUGSERVER_H_

#include <vector>
#include <string>

namespace SketchUp {
namespace RubyDebugger {

// Forward declarations
struct BreakPoint;
struct StackFrame;

// Information about a local or global variable
struct Variable {
  Variable() : has_children(false), object_id(0) {}

  std::string name;
  std::string type;
  std::string value;
  bool has_children;
  size_t object_id;
};

// Interface to the debugger server.
class IDebugServer {
public:

  // Stops the server
  virtual void Stop() = 0;

  // Adds the given breakpoint. Returns true on success.
  virtual bool AddBreakPoint(BreakPoint& bp, bool assume_resolved = false) = 0;

  // Removes the breakpoint at a given index. Returns true on success.
  virtual bool RemoveBreakPoint(size_t index) = 0;

  // Returns all breakpoints.
  virtual std::vector<BreakPoint> GetBreakPoints() const = 0;

  // Returns true if SketchUp has stopped and waiting for the debugger.
  // Returns false if it is running.
  virtual bool IsStopped() const = 0;

  // Evaluates the given Ruby expression and returns the result as a string.
  virtual Variable EvaluateExpression(const std::string& expr) = 0;

  // Returns current stack frames. Execution must have stopped.
  virtual std::vector<StackFrame> GetStackFrames() const = 0;

  // Shifts the active stack frame index up/down by one.
  virtual void ShiftActiveFrame(bool shift_up) = 0;

  // Returns the currently active stack frame index.
  virtual size_t GetActiveFrameIndex() const = 0;

  // Returns the currently active stack frame index.
  virtual void SetActiveFrameIndex(size_t index) const = 0;

  // Steps execution to the next line, stepping in methods.
  virtual void Step() = 0;

  // Steps execution to the next line, stepping over methods.
  virtual void StepOver() = 0;

  // Steps execution out of the current method.
  virtual void StepOut() = 0;

  // Returns the code lines around the current line. Execution must have stopped.
  virtual std::vector<std::pair<size_t, std::string>>
      GetCodeLines(size_t beg_line, size_t end_line) const = 0;

  // Returns the line number at the point of last execution break.
  virtual size_t GetBreakLineNumber() const = 0;

  // Data structure to return Ruby variables.
  typedef std::vector<Variable> VariablesVector;

  // Returns a list of global variables
  virtual VariablesVector GetGlobalVariables() const = 0;

  // Returns a list of local variables. Execution must have stopped.
  virtual VariablesVector GetLocalVariables() const = 0;

  // Returns the instance variables of a given object
  virtual VariablesVector GetInstanceVariables(size_t object_id) const = 0;
};

} // end namespace RubyDebugger
} // end namespace SketchUp

#endif // RDEBUGGER_DEBUGSERVER_IDEBUGSERVER_H_
