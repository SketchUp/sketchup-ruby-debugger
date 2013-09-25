#ifndef RDEBUGGER_DEBUGSERVER_UI_IDEBUGGERUI_H_
#define RDEBUGGER_DEBUGSERVER_UI_IDEBUGGERUI_H_

#include <string>

namespace SketchUp {
namespace RubyDebugger {

class IDebugServer;
struct BreakPoint;

class IDebuggerUI
{
public:
  virtual void Initialize(IDebugServer* server) = 0;

  virtual void WaitForContinue() = 0;

  virtual void Break(BreakPoint bp) = 0;

  virtual void Break(const std::string& file, size_t line) = 0;

protected:
  IDebuggerUI() : server_(nullptr) {}

  IDebugServer* server_; // Not owned by the UI.
};

} // namespace RubyDebugger
} // namespace SketchUp

#endif // RDEBUGGER_DEBUGSERVER_UI_IDEBUGGERUI_H_
