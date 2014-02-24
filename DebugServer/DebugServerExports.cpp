// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//
#include "stdafx.h"
#include "./DebugServerExports.h"
#include "./Server.h"

#ifdef WIN32
#include <DebugServer/UI/Console/Win/ConsoleUI.h>
#include <DebugServer/UI/RDIP/Win/RDIP.h>
#endif

#include <boost/algorithm/string.hpp>

using namespace SketchUp::RubyDebugger;

bool InitDebugger(const char* debugger) {
  std::unique_ptr<IDebuggerUI> ui;

  std::string str_debugger(debugger);
  if (boost::iequals(str_debugger, "console"))
    ui.reset(new ConsoleUI);
  else if(boost::starts_with(str_debugger, "rdip")) {
      ui.reset(new RDIP);
  }

  if (ui) {
    Server& server = Server::Instance();
    server.Start(std::move(ui));
    return true;
  } else {
    return false;
  }
}
