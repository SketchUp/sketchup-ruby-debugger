// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Orhun Birsoy
// - Bugra Barin
// - Aaron Hill (@Seraku) - Refactored ruby-debug-ide protocol implementation.
//
#ifndef RDEBUGGER_DEBUGSERVER_UI_CONSOLE_WIN_RDIP_H_
#define RDEBUGGER_DEBUGSERVER_UI_CONSOLE_WIN_RDIP_H_

#include <DebugServer/UI/IDebuggerUI.h>

#include <memory>

namespace SketchUp {
namespace RubyDebugger {
// http://debug-commons.rubyforge.org/#ruby-debug-ide
// ruby-debug-ide protocol implementation.
class RDIP : public IDebuggerUI {
public:
  RDIP();
  ~RDIP();

  virtual void Initialize(IDebugServer* server,
                          const std::string& str_debugger);

  virtual bool IsIDE() { return true; }

  virtual void WaitForContinue();

  virtual void Break(BreakPoint bp);

  virtual void Break(const std::string& file, size_t line);

private:
  class Impl;
  std::shared_ptr<Impl> impl_;
  bool wait_for_client_;
};

} // end namespace RubyDebugger
} // end namespace SketchUp

#endif // RDEBUGGER_DEBUGSERVER_UI_CONSOLE_WIN_RDIP_H_
