// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//
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

// Saves the given breakpoints to the settings file.
void SaveBreakPoints(const BreakPointsMap& resolved_bps,
                     const std::vector<BreakPoint>& unresolved_pbs);

// Loads breakpoints from the settings file.
void LoadBreakPoints(BreakPointsMap& resolved_bps,
                     std::vector<BreakPoint>& unresolved_pbs);

} // end namespace Settings
} // end namespace RubyDebugger
} // end namespace SketchUp

#endif // RDEBUGGER_DEBUGSERVER_DEBUGGERSETTINGS_H_
