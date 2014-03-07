// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//
#ifndef RDEBUGGER_COMMON_STACKFRAME_H_
#define RDEBUGGER_COMMON_STACKFRAME_H_

#include <string>
#include <ruby/ruby.h>

namespace SketchUp {
namespace RubyDebugger {

struct StackFrame {
  std::string name;
  VALUE binding;
  VALUE self;
  VALUE klass;
};

} // end namespace RubyDebugger
} // end namespace SketchUp

#endif // RDEBUGGER_COMMON_STACKFRAME_H_
