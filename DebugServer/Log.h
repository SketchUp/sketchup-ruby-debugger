// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//
#pragma once

namespace SketchUp {
namespace RubyDebugger {

inline void Log(const char* str) {
#ifdef _WIN32
  OutputDebugStringA(str);
#endif
}

} // end namespace RubyDebugger
} // end namespace SketchUp
