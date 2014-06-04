SketchUp Ruby API Debugger
==========================

This is a Ruby debugger framework for SketchUp 2014 and later. The ruby-debug-ide protocol has been mostly implemented so any Ruby IDE that supports this protocol should work. We have tested with Aptana RadRails, NetBeans (with Ruby community plugin) and RubyMine.

Instructions for Windows:
- The repository contains a pre-built dynamic library (SURubyDebugger.dll). Copy this DLL into the SketchUp installation directory:
```
C:\Program Files (x86)\SketchUp\SketchUp 2014\
```
- Run SketchUp with the following command line arguments:
```
SketchUp.exe -rdebug "ide port=7000"
```

Instructions for Mac OS X:
- Install SketchUp 2014 Maintenance 1 Release (version 14.1.1283) or later
- Copy SURubyDebugger.dylib into the Frameworks directory of the app bundle:
```
SketchUp.app/Contents/Frameworks
```
- Run SketchUp from the command line:
```
open -a /Applications/SketchUp\ 2014/SketchUp.app --args -rdebug "ide port=7000"
```

Notes:
- The port should match the remote debugger port setting configured in the IDE. Default port is 1234.
- SketchUp will start up and appear to be frozen. It is waiting for the debugger to show up.
- Launch remote debugging in the IDE, SketchUp should continue running. You should see breakpoints hit when Ruby code execution reaches the specified lines.


Most common debugging functionality has been implemented but there are few TODOs:
- Debugging of multi-threaded execution
- Exception breakpoints
- Conditional breakpoints
- What else are we missing ? Please report and contribute!

To contribute, please fork the repository, make your changes and submit a pull request.

Happy Debugging!
