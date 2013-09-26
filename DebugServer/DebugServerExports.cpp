// DebugServer.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DebugServerExports.h"
#include "Server.h"
#include "UI/ConsoleUI.h"

#include <boost/algorithm/string.hpp>

using namespace SketchUp::RubyDebugger;

bool InitDebugger(const char* debugger) {
  std::unique_ptr<IDebuggerUI> ui;

  std::string str_debugger(debugger);
  if (boost::iequals(str_debugger, "console"))
    ui.reset(new ConsoleUI);

  if (ui) {
    Server& server = Server::Instance();
    server.Start(std::move(ui));
    return true;
  } else {
    return false;
  }
}
