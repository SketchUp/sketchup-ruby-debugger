// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
// - Aaron Hill (@Seraku) - Enhanced logging function.
//
#pragma once

#include <chrono>
#include <iomanip>
#include <regex>
#include <sstream>
#include <string>

namespace SketchUp {
namespace RubyDebugger {

namespace Log {

static inline std::string Context(const char *filename, size_t line, const char *function) {
  std::ostringstream output;

  static auto start_time = std::chrono::high_resolution_clock::now();
  auto current_time = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(current_time - start_time).count() * 0.000001;
  output << std::fixed << std::setprecision(4) << elapsed << '\t';

  int thread_id = 0;
#ifdef WIN32
  thread_id = static_cast<int>(GetCurrentThreadId());
#else
  //thread_id = pthread_getthreadid_np();
#endif
  output << '[' << std::dec << thread_id << "]\t";

  if (filename) {
    static const std::regex filename_regex("[^/\\\\]+$");
    std::cmatch match;
    if (std::regex_search(filename, match, filename_regex)) {
      output << match.str() << ':' << std::dec << line << '\t';
    }
  }
  if (function) {
    static const std::regex function_regex("[^:]+$");
    std::cmatch match;
    if (std::regex_search(function, match, function_regex)) {
      output << match.str() << "()\t";
    }
  }

  return output.str();
}

#ifdef _DEBUG
#define LOG_CONTEXT (SketchUp::RubyDebugger::Log::Context(__FILE__, __LINE__, __FUNCTION__))
#else
#define LOG_CONTEXT (SketchUp::RubyDebugger::Log::Context(nullptr, 0, nullptr))
#endif

static inline void Write(const std::string &context, const std::string &message) {
  static const std::regex newline_regex("[\r\n]+");
  static const std::sregex_token_iterator end;
  for (std::sregex_token_iterator iter(message.begin(), message.end(), newline_regex, -1); iter != end; ++iter) {
#ifdef WIN32
    OutputDebugStringA((context + iter->str() + "\r\n").c_str());
#else
    std::cout << context << iter->str() << std::endl;
#endif
  }
}

#define LOG(msg) (SketchUp::RubyDebugger::Log::Write(LOG_CONTEXT, (msg)))
#define FMT(msg) ([=](){ std::ostringstream oss; (oss << msg); return oss.str(); }())

} // end namespace Log

} // end namespace RubyDebugger
} // end namespace SketchUp
