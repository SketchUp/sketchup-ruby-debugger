// Copyright 2013 Trimble Navigation Ltd.  All Rights Reserved
// Author: bugra@sketchup.com (Bugra Barin)
#ifndef INCLUDE_RUBY_CONFIG_WRAPPER_H
#define INCLUDE_RUBY_CONFIG_WRAPPER_H

// Ruby build places the actual config.h into a platform-specific directory but
// expects to find it under ruby. Apparently the assumption is that the
// platform-specific directory will be added to C++ include paths of every
// project that uses Ruby. This is inconvenient and I chose to create this
// wrapper that simply includes the platform-specific config header.

#include "x86_64-darwin14/ruby/config.h"

#endif /* INCLUDE_RUBY_CONFIG_WRAPPER_H */
