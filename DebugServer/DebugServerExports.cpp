// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//
#include "./DebugServerExports.h"
#include "./Server.h"

#ifdef WIN32
#include <DebugServer/UI/Console/Win/ConsoleUI.h>
#endif

#include <DebugServer/UI/RDIP/Win/RDIP.h>

#include <boost/algorithm/string.hpp>

using namespace SketchUp::RubyDebugger;

bool InitDebugger(const char* debugger) {
  std::unique_ptr<IDebuggerUI> ui;

  std::string str_debugger(debugger);
  if (boost::iequals(str_debugger, "console")) {
#ifdef WIN32
    ui.reset(new ConsoleUI);
#endif
  } else if(boost::istarts_with(str_debugger, "ide")) {
      ui.reset(new RDIP);
  }

  if (ui) {
    Server& server = Server::Instance();
    server.Start(std::move(ui), str_debugger);
    return true;
  } else {
    return false;
  }
}
