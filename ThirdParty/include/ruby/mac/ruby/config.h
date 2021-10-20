#ifndef RUBY_CONFIG_SHIM_H
#define RUBY_CONFIG_SHIM_H 1

#ifdef __aarch64__
  #include "../arm64-darwin20/ruby/config.h"
#else
  #include "../x86_64-darwin18/ruby/config.h"
#endif

#endif /* RUBY_CONFIG_SHIM_H */
