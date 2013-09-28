#ifndef RDEBUGGER_DEBUGSERVER_CONSOLEINPUTBUFFER_H_
#define RDEBUGGER_DEBUGSERVER_CONSOLEINPUTBUFFER_H_

// Code adapted from http://athile.net/library/blog/?p=44

#include <string>
#include <vector>

namespace SketchUp {
namespace RubyDebugger {

class ConsoleInputBuffer
{
public:
    bool ReadLine(std::string& line);

    static void RecordHistory(const std::string& command);

private:
    void AddPendingInputToBuffer();
    bool ReadNextLineFromBuffer(std::string& line);

    std::string buffer_;

    static std::vector<std::string> history_;
    static size_t history_index_;
};

} // end namespace RubyDebugger
} // end namespace SketchUp

#endif // RDEBUGGER_DEBUGSERVER_CONSOLEINPUTBUFFER_H_
