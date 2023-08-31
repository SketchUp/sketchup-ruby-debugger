SketchUp Ruby API Debugger
==========================

This is a Ruby debugger framework for SketchUp 2014 and later. The `ruby-debug-ide` protocol has been mostly implemented so any Ruby IDE that supports this protocol should work.

| IDE | Stable (1.2.0) | Stable (1.3.0) | Stable (1.4.0) | Stable (1.5.0) |
| --- | --- | --- | --- | --- |
| [RubyMine](https://github.com/SketchUp/sketchup-ruby-api-tutorials/wiki/RubyMine-Debugger-Setup) | *Untested* | Good | Good | Good |
| [VS Code](https://github.com/SketchUp/sketchup-ruby-api-tutorials/wiki/VSCode-Debugger-Setup) (with `vscode-ruby` extension) | Not supported | Good | Good | Good |

## Instructions for Windows:
- Download the pre-built dynamic library (SURubyDebugger.dll) from the [latest release](https://github.com/SketchUp/sketchup-ruby-debugger/releases) or build from the sources.
- Copy the DLL into the SketchUp installation directory. As the exact path will depend on the version of SketchUp you have installed, look for a folder similar to the following:
```
C:\Program Files\SketchUp\SketchUp 2024\

C:\Program Files (x86)\SketchUp\SketchUp 2015\
```
- Start SketchUp from the command line or the "Run..." dialog:
```
SketchUp.exe -rdebug "ide port=6123"
```

## Instructions for Mac OS X:
- Install SketchUp 2014 Maintenance 1 Release (version 14.1.1283) or later.
- Download `SURubyDebugger.dylib` into the Frameworks directory of the app bundle:
```
curl -L https://github.com/SketchUp/sketchup-ruby-debugger/releases/download/1.5.0.0/SURubyDebugger.dylib -o /Applications/SketchUp\ 2024/SketchUp.app/Contents/Frameworks/SURubyDebugger.dylib
```
- Run SketchUp from the command line:
```
/Applications/SketchUp\ 2024/SketchUp.app/Contents/MacOS/SketchUp -rdebug "ide port=6123"
```
Alternatively:
```
open -a /Applications/SketchUp\ 2024/SketchUp.app --args -rdebug "ide port=6123"
```

## Known Issues

If the connection cannot be made, for instance the port is in use, the debugger will crash.

These docs previously used port 7000 as an example, but as of macOS Monterey that is now in use by the OS itself.

To list active ports on macOS:

```
sudo lsof -i -P | grep LISTEN | grep :$PORT
```

## Command-line arguments:
When launching SketchUp with debugging enabled, the following command-line arguments are supported:

```
-rdebug "ide [port=<number>] [wait]"
```

- `port=<number>` - Configures the port on which the SketchUp debugger accepts connections from IDEs. This must match the remote debugger port setting configured in the IDE. If not specified, the port defaults to **1234**.

- `wait` - Instructs the SketchUp debugger to wait for an initial connection from an IDE before allowing execution to continue. This is necessary to debug scripts that run automatically, for instance when an extension is loaded. When using this option, the SketchUp process will appear to be frozen until an IDE is attached.

## Notes:
While most common debugging functionality has been implemented, there are few TODOs:
- Debugging of multi-threaded execution
- Function breakpoints
- Exception breakpoints
- *Are we missing something else?* Please report and contribute!

To contribute, please fork the repository, make your changes and submit a pull request.

Happy Debugging!
