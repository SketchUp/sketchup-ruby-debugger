sketchup-ruby-debugger
======================

This is a Ruby API debugger framework for SketchUp 2014 and later. We currently support Windows only but Mac support will be added soon. The ruby-debug-ide protocol is mostly implemented so any Ruby IDE that supports this protocol should work in theory. We have tested with Aptana RadRails, NetBeans (with Ruby community plugin) and RubyMine.

Here's how to use it:
- The repository contains a pre-built SURubyDebugger.dll. Copy this DLL into the SketchUp installation folder:
```
C:\Program Files (x86)\SketchUp\SketchUp 2014\
```
- Run SketchUp with the following command line arguments:
```
SketchUp.exe -rdebug "ide port=7000"
```
- The port should match the remote debugger port setting configured in the IDE. Default port is 1234.
- SketchUp will start up and appear to be frozen. It is waiting for the debugger to show up.
- Launch remote debugging in the IDE, SketchUp should continue running. You should see any breakpoints hit when the Ruby code execution reaches the specified line.

Most common debugging functionality has been implemented but there are few TODOs:
- Multi-thread debugging
- Breakpoint conditions
- What else are we missing ? Please report and contribute!

To contribute, please fork the repository, make your changes and submit a pull request.

Happy Debugging!
