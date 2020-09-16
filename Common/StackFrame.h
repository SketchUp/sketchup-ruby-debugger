// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//
#ifndef RDEBUGGER_COMMON_STACKFRAME_H_
#define RDEBUGGER_COMMON_STACKFRAME_H_

#include <string>

#pragma warning( push )
#pragma warning( disable : 4117 ) // warning C4117: macro name '_INTEGRAL_MAX_BITS' is reserved, '#define' ignored
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wdeprecated-register"
#include <ruby/ruby.h>
#pragma clang diagnostic pop
#pragma warning( pop )

namespace SketchUp {
namespace RubyDebugger {

struct StackFrame {
  std::string name;
  std::string file;
  int line;
  VALUE binding;
  VALUE self;
  VALUE klass;
};

} // end namespace RubyDebugger
} // end namespace SketchUp

#endif // RDEBUGGER_COMMON_STACKFRAME_H_
