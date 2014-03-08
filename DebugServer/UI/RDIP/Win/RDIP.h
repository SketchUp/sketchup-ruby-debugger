// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Orhun Birsoy
// - Bugra Barin
//
#ifndef RDEBUGGER_DEBUGSERVER_UI_CONSOLE_WIN_RDIP_H_
#define RDEBUGGER_DEBUGSERVER_UI_CONSOLE_WIN_RDIP_H_

#include <DebugServer/UI/IDebuggerUI.h>

#include <boost/thread.hpp>
#include <boost/atomic.hpp>
#include <boost/function.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/signal_set.hpp>

namespace SketchUp {
namespace RubyDebugger {
// http://debug-commons.rubyforge.org/#ruby-debug-ide
// ruby-debug-ide protocol implementation.
class RDIP : public IDebuggerUI
{
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
    class Connection;

    void RunService(int port);
    void HandleFatalFailure(const boost::system::error_code& err, int signal);
    void HandleConnection(const boost::system::error_code& err);

private:
    boost::asio::io_service mService;
    boost::asio::signal_set mSignalSet;
    boost::thread mServiceThread;
    boost::condition_variable mServerWaitCond;
    boost::mutex mServerWaitMutex;
    bool mServerCanContinue;

    boost::shared_ptr<Connection> mConnection;
    boost::function<void(void)> mServerResponse;
    boost::function<void(void)> mProcessServerResponse;
};

} // end namespace RubyDebugger
} // end namespace SketchUp

#endif // RDEBUGGER_DEBUGSERVER_UI_CONSOLE_WIN_RDIP_H_
