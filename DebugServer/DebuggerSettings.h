// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//
#ifndef RDEBUGGER_DEBUGSERVER_DEBUGGERSETTINGS_H_
#define RDEBUGGER_DEBUGSERVER_DEBUGGERSETTINGS_H_

#include <Common/BreakPoint.h>

#include <map>
#include <vector>

#ifdef __APPLE__
#define _stricmp strcasecmp
#endif

namespace SketchUp {
namespace RubyDebugger {

struct CaseInsensitiveStringSort : public std::binary_function<std::string, std::string, bool>
{
    bool operator()(const std::string &lhs, const std::string &rhs) const
    {
        return _stricmp(lhs.c_str(), rhs.c_str()) < 0;
    }
};

// map<line, map<file, BreakPoint>>
typedef std::map<size_t, std::map<std::string, BreakPoint, CaseInsensitiveStringSort>> BreakPointsMap;

namespace Settings {

// Saves the given breakpoints to the settings file.
void SaveBreakPoints(const BreakPointsMap& resolved_bps,
                     const std::vector<BreakPoint>& unresolved_pbs);

// Loads breakpoints from the settings file. Also returns the largest
// breakpoint index loaded.
void LoadBreakPoints(BreakPointsMap& resolved_bps,
                     std::vector<BreakPoint>& unresolved_pbs,
                     size_t& last_breakpoint_index);

} // end namespace Settings
} // end namespace RubyDebugger
} // end namespace SketchUp

#endif // RDEBUGGER_DEBUGSERVER_DEBUGGERSETTINGS_H_
