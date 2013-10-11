// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//
// License: Apache License, Version 2.0
#ifndef RDEBUGGER_DEBUGSERVER_DEBUGGERSETTINGS_H_
#define RDEBUGGER_DEBUGSERVER_DEBUGGERSETTINGS_H_

#include <Common/BreakPoint.h>

#include <map>
#include <vector>

namespace SketchUp {
namespace RubyDebugger {

// map<line, map<file, BreakPoint>>
typedef std::map<size_t, std::map<std::string, BreakPoint>> BreakPointsMap;

namespace Settings {

void SaveBreakPoints(const BreakPointsMap& resolved_bps,
                     const std::vector<BreakPoint>& unresolved_pbs);

void LoadBreakPoints(BreakPointsMap& resolved_bps,
                     std::vector<BreakPoint>& unresolved_pbs);

} // end namespace Settings
} // end namespace RubyDebugger
} // end namespace SketchUp

#endif // RDEBUGGER_DEBUGSERVER_DEBUGGERSETTINGS_H_
