// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//
#ifndef RDEBUGGER_DEBUGSERVER_UI_FINDSUBSTRING_H_
#define RDEBUGGER_DEBUGSERVER_UI_FINDSUBSTRING_H_

#include <locale>
#include <iostream>
#include <algorithm>

namespace SketchUp {
namespace RubyDebugger {

// Templated version of EqualPred so it could work with both char and wchar_t
template<typename charT>
struct EqualPred {
    EqualPred( const std::locale& loc ) : loc_(loc) {}
    bool operator()(charT ch1, charT ch2) {
        return std::toupper(ch1, loc_) == std::toupper(ch2, loc_);
    }
private:
    const std::locale& loc_;
};

// Find substring (case insensitive)
template<typename T>
int FindSubstringCaseInsensitive(const T& str1, const T& str2,
                                 const std::locale& loc = std::locale())
{
    T::const_iterator it = std::search(str1.begin(), str1.end(), 
        str2.begin(), str2.end(), EqualPred<T::value_type>(loc));
    if (it != str1.end())
      return it - str1.begin();
    else return -1; // not found
}

} // end namespace RubyDebugger
} // end namespace SketchUp

#endif // RDEBUGGER_DEBUGSERVER_UI_FINDSUBSTRING_H_
