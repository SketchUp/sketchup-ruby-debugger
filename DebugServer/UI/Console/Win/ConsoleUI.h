// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//
#ifndef RDEBUGGER_DEBUGSERVER_UI_CONSOLE_WIN_CONSOLEUI_H_
#define RDEBUGGER_DEBUGSERVER_UI_CONSOLE_WIN_CONSOLEUI_H_

#include <DebugServer/UI/IDebuggerUI.h>

#include <atomic>
#include <condition_variable>
#include <mutex>
#include <thread>

namespace SketchUp {
namespace RubyDebugger {

// Console debugger UI implementation.
class ConsoleUI : public IDebuggerUI
{
public:
  ConsoleUI();

  virtual void Initialize(IDebugServer* server,
                          const std::string& str_debugger);

  virtual bool IsIDE() { return false; }

  virtual void WaitForContinue();

  virtual void Break(BreakPoint bp);

  virtual void Break(const std::string& file, size_t line);

private:
  void ConsoleThreadFunc();
  bool EvaluateCommand(const std::string& str_command);
  void WritePrompt();
  void WriteFrames();
  void WriteCodeLines();
  void WriteCurrentLine();

private:
  std::thread console_thread_;
  bool server_will_continue_;

  std::mutex console_output_mutex_;

  std::condition_variable server_wait_cv_;
  std::mutex server_wait_mutex_;
  bool server_can_continue_;

  std::atomic<bool> need_server_response_;
  enum { NEED_NOTHING, NEED_EVAL, NEED_GLOBAL_VARS, NEED_LOCAL_VARS }
      need_what_from_server_;
  std::string expression_to_evaluate_;
};

} // end namespace RubyDebugger
} // end namespace SketchUp

#endif // RDEBUGGER_DEBUGSERVER_UI_CONSOLE_WIN_CONSOLEUI_H_
