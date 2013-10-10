// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//
// License: Apache License, Version 2.0
#include "stdafx.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include "./DebuggerSettings.h"

using namespace SketchUp::RubyDebugger;

namespace SketchUp {
namespace RubyDebugger {

static std::string GetFilePath() {
  static std::string file_path;
  if (file_path.empty()) {
    // TODO: Think about unicode user names.
    char path[MAX_PATH];
    path[0] = '\0';
    BOOL ok = SHGetSpecialFolderPathA(NULL, path, CSIDL_APPDATA, FALSE);
    file_path = std::string(path) + "\\SketchUp\\RubyDebugger.settings";
  }
  return file_path;
}

using boost::property_tree::ptree;

static void Save(const BreakPoint& bp, ptree& pt) {
  pt.put("file", bp.file);
  pt.put("line", bp.line);
  pt.put("index", bp.index);
  pt.put("enabled", bp.enabled);
}

static void Load(const ptree& pt, BreakPoint& bp) {
  bp.file = pt.get<std::string>("file");
  bp.line = pt.get<size_t>("line");
  bp.index = pt.get<size_t>("index");
  bp.enabled = pt.get<bool>("enabled");
}

void SaveBreakPoints(const BreakPointsMap& resolved_bps,
                     const std::vector<BreakPoint>& unresolved_pbs) {
  try {
    ptree pt_all;

    // Resolved breakpoints
    ptree pt_res;
    for (auto it = resolved_bps.cbegin(), ite = resolved_bps.cend(); it != ite;
         ++it) {
      for (auto it2 = it->second.cbegin(), it2e = it->second.cend();
           it2 != it2e; ++it2) {
        const BreakPoint& bp = it2->second;
        ptree pt;
        Save(bp, pt);
        pt_res.push_back(ptree::value_type("breakpoint", pt));
      }
    }
    pt_all.push_back(ptree::value_type("resolved_breakpoints", pt_res));

    // Unresolved breakpoints
    ptree pt_unres;
    for (auto it = unresolved_pbs.cbegin(), ite = unresolved_pbs.cend();
         it != ite; ++it) {
      const BreakPoint& bp = *it;
      ptree pt;
      Save(bp, pt);
      pt_unres.push_back(ptree::value_type("breakpoint", pt));
    }
    pt_all.push_back(ptree::value_type("unresolved_breakpoints", pt_unres));
    
    std::string file_path = GetFilePath();
    write_xml(file_path, pt_all);
  } catch (const std::exception&) {
  }
}

void LoadBreakPoints(BreakPointsMap& resolved_bps,
                     std::vector<BreakPoint>& unresolved_pbs) {
  ptree pt;
  resolved_bps.clear();
  unresolved_pbs.clear();

  // Load the XML file into the property tree.
  std::string file_path = GetFilePath();
  try {
    read_xml(file_path, pt);

    // Resolved breakpoints
    auto it = pt.find("resolved_breakpoints");
    if (it != pt.not_found()) {
      for (auto it2 = it->second.begin(), it2e = it->second.end(); it2 != it2e;
           ++it2) {
        const ptree& pt_bp = it2->second;
        BreakPoint bp;
        Load(pt_bp, bp);
        std::map<std::string, BreakPoint>& map = resolved_bps[bp.line];
        map[bp.file] = bp;
      }
    }

    // Unresolved breakpoints
    it = pt.find("unresolved_breakpoints");
    if (it != pt.not_found()) {
      for (auto it2 = it->second.begin(), it2e = it->second.end(); it2 != it2e;
           ++it2) {
        const ptree& pt_bp = it2->second;
        BreakPoint bp;
        Load(pt_bp, bp);
        unresolved_pbs.push_back(bp);
      }
    }
  } catch (const std::exception&) {
  }
}

} // end namespace RubyDebugger
} // end namespace SketchUp
