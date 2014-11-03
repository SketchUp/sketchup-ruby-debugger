// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//
#include "./ConsoleInputBuffer.h"
#include <iostream>

namespace SketchUp {
namespace RubyDebugger {

// Static history variables
std::vector<std::string> ConsoleInputBuffer::history_;
size_t ConsoleInputBuffer::history_index_ = 0;

/*!
    Adds all pending keyboard input to the internal buffer.   The
    implementation uses ReadConsoleInput() which is a non-blocking function.
    All non-keyboard events are ignored.
 */
void ConsoleInputBuffer::AddPendingInputToBuffer() {
  //
  // Read pending events
  //
  DWORD dwRead;
  INPUT_RECORD inRecords[128];
  ::ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &inRecords[0], 128, &dwRead);
  //
  // Process the events
  //
  for (unsigned int i = 0; i < dwRead; ++i) {
    if (inRecords[i].EventType == KEY_EVENT) {
      // Key events include non-character keys like SHIFT.  Filter
      // these out.
      const KEY_EVENT_RECORD& evt = inRecords[i].Event.KeyEvent;
      const char c = evt.uChar.AsciiChar;
      if (evt.bKeyDown) {
        if (c != 0) {
          // Unfortunately since keyboard input is being handled manually
          // behavior such as backspace needs to be manually emulated.
          if (c == '\b') {
            // Do not let the prompt be erased
            if (buffer_.empty())
              continue;

            // Emulate the default behavior by echoing the typed characters
            std::cout << c;

            HANDLE hStdOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO info;
            DWORD dwWritten;
            ::GetConsoleScreenBufferInfo(hStdOut, &info);
            ::WriteConsoleOutputCharacter(hStdOut, L" ", 1,
                info.dwCursorPosition, &dwWritten);
            buffer_.pop_back(); // pop the last character
          } else {
            // Emulate the default behavior by echoing the typed characters
            std::cout << c;

            // Add to the buffer
            buffer_ += c;
          }
        } else if (evt.wVirtualKeyCode == VK_UP ||
                   evt.wVirtualKeyCode == VK_DOWN) {
          // Move up/down the history
          bool up = (evt.wVirtualKeyCode == VK_UP);
          if (up) {
            if (history_index_ == 0)
              history_index_ = history_.size();
            else
              --history_index_;
          } else {
            if (history_index_ >= history_.size())
              history_index_ = 0;
            else
              ++history_index_;
          }
          std::string new_command;
          if (history_index_ < history_.size())
            new_command = history_[history_index_];
          // else empty string
          
          HANDLE hStdOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
          CONSOLE_SCREEN_BUFFER_INFO info;
          ::GetConsoleScreenBufferInfo(hStdOut, &info);
          // Clear first
          std::wstring clearStr(buffer_.size(), L' ');
          COORD pos = info.dwCursorPosition;
          pos.X -= static_cast<short>(clearStr.size());
          DWORD dwWritten;
          ::WriteConsoleOutputCharacter(hStdOut, clearStr.c_str(),
                                        static_cast<DWORD>(clearStr.size()),
                                        pos, &dwWritten);
          // Set cursor to the beginning
          SetConsoleCursorPosition(hStdOut, pos);
          // Write the new line
          std::cout << new_command;
          buffer_ = new_command;
        }
      }
    }
  }
}

/*!
    Scan the buffer for a full line of input.  Return true if there
    is a full line available.
 */
bool ConsoleInputBuffer::ReadNextLineFromBuffer(std::string& line) {
  size_t pos = buffer_.find('\r');
  if (pos != std::string::npos) {
    // Split the buffer at the first line break.  Set the return value
    // to all text prior to that line break and leave the remaining
    // characters in the buffer.
    //
    line = buffer_.substr(0, pos);
    buffer_ = buffer_.substr(pos + 1, buffer_.length() - (pos + 1));
    return true;
  } else {
    // No line break found.
    return false;
  }
}

bool ConsoleInputBuffer::ReadLine(std::string& line) {
  AddPendingInputToBuffer();
  return ReadNextLineFromBuffer(line);   
}

void ConsoleInputBuffer::RecordHistory(const std::string& command) {
  history_.push_back(command);
  history_index_ = history_.size();
}

} // end namespace RubyDebugger
} // end namespace SketchUp
