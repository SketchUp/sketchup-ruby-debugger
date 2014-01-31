sketchup-ruby-debugger
======================

This is a Ruby API debugger framework for SketchUp 2014 and later. We currently support Windows only with a command line debugger interface. However, the framework should allow implementing more sophisticated IDEs in the future. So please contribute!

Here's how to use it:
- The included VS2010 solution builds SURubyDebugger.dll. Copy this DLL into the SketchUp installation folder:
```
C:\Program Files (x86)\SketchUp\SketchUp 2014\
```
- Run SketchUp with the following command line arguments:
```
sketchup.exe -rdebug "console"
```
- SketchUp will start up, display a console window and pause for input.
- Try the command "help" or "h" in the console for help on available debugger commands
- You can add breakpoints via the command "break" or "b". You can type part of the file name and the first file that matches will be assigned the breakpoint. For instance:
```
sudb (stopped): b webtextures:55
Added breakpoint:
  1 webtextures:55
```
- Use the "continue" or "c" command to continue program execution:
```
sudb (stopped): c
sudb (running):
```
- When you run the "Add Photo Textures" command, the debugger will hit your breakpoint and stop execution:
```
BreakPoint 1 at C:/Users/<user>/AppData/Roaming/SketchUp/SketchUp 2014/SketchUp/Plugins/su_webtextures/webtextures_loader.rb:55
Line 55:     @is_online = false
```
- Now you can print the value of a variable:
```
sudb (stopped): p @is_mac
false
```
To contribute, please fork the repository, make your changes and submit a pull request.
