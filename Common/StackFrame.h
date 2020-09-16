// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//
#ifndef RDEBUGGER_COMMON_STACKFRAME_H_
#define RDEBUGGER_COMMON_STACKFRAME_H_

#include <string>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wdeprecated-register"
#include <ruby/ruby.h>
#pragma clang diagnostic pop

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
