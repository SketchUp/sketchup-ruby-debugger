// DebugServer.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DebugServerExports.h"
#include "Server.h"
#include "UI/ConsoleUI.h"

using namespace SketchUp::RubyDebugger;

bool InitDebugger() {
  Server& server = Server::Instance();
  std::unique_ptr<SketchUp::RubyDebugger::IDebuggerUI> ui(
      new SketchUp::RubyDebugger::ConsoleUI);
  server.Start(std::move(ui));
  return true;
}
