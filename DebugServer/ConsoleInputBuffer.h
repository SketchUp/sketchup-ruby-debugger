#ifndef RDEBUGGER_DEBUGSERVER_CONSOLEINPUTBUFFER_H_
#define RDEBUGGER_DEBUGSERVER_CONSOLEINPUTBUFFER_H_

// Code adapted from http://athile.net/library/blog/?p=44

#include <string>

namespace SketchUp {
namespace RubyDebugger {

class ConsoleInputBuffer
{
public:
    bool ReadLine(std::string& line);

private:
    void AddPendingInputToBuffer();
    bool ReadNextLineFromBuffer(std::string& line);

    std::string buffer_;
};

} // end namespace RubyDebugger
} // end namespace SketchUp

#endif // RDEBUGGER_DEBUGSERVER_CONSOLEINPUTBUFFER_H_
