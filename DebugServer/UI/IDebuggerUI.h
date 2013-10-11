// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//
// License: Apache License, Version 2.0
#ifndef RDEBUGGER_DEBUGSERVER_UI_IDEBUGGERUI_H_
#define RDEBUGGER_DEBUGSERVER_UI_IDEBUGGERUI_H_

#include <string>

namespace SketchUp {
namespace RubyDebugger {

// Forward declarations
class IDebugServer;
struct BreakPoint;

// Interface to be implemented by a debugger UI.
class IDebuggerUI
{
public:
  // Initializes the UI, given a server interface.
  virtual void Initialize(IDebugServer* server) = 0;

  // Blocks the calling thread until user issues a continuation command.
  virtual void WaitForContinue() = 0;

  // Called by the server when a breakpoint is hit during execution.
  virtual void Break(BreakPoint bp) = 0;

  // Called by the server when a file/line breakpoint is hit during execution.
  virtual void Break(const std::string& file, size_t line) = 0;

protected:
  IDebuggerUI() : server_(nullptr) {}

  IDebugServer* server_; // Not owned by the UI.
};

} // namespace RubyDebugger
} // namespace SketchUp

#endif // RDEBUGGER_DEBUGSERVER_UI_IDEBUGGERUI_H_
