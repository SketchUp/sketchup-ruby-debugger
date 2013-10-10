// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//
// License: Apache License, Version 2.0
#ifndef RDEBUGGER_COMMON_BREAKPOINT_H_
#define RDEBUGGER_COMMON_BREAKPOINT_H_

#include <string>

namespace SketchUp {
namespace RubyDebugger {

struct BreakPoint {
  BreakPoint() : index(0), enabled(false), line(0) {}

  size_t index;
  bool enabled;
  std::string file;
  size_t line;
};

} // end namespace RubyDebugger
} // end namespace SketchUp

#endif // RDEBUGGER_COMMON_BREAKPOINT_H_
