@ECHO OFF

REM Comment/uncomment the next line to control deployment of files to the SketchUp program directory.
GOTO CopyFiles

ECHO postbuild.bat - Skipping deployment of files to the SketchUp program directory.
GOTO End

:CopyFiles
ECHO postbuild.bat - Deploying files to the SketchUp program directory.

SETLOCAL ENABLEDELAYEDEXPANSION

ECHO Locating SketchUp program directory...
SET SKETCHUP_DIR=
FOR /D %%i IN ("%PROGRAMW6432%\SketchUp\*") DO SET SKETCHUP_DIR=%%i
IF [!SKETCHUP_DIR!] == [] GOTO NotFound
ECHO Found SketchUp program directory: !SKETCHUP_DIR!

ECHO Verifying permissions to copy to SketchUp program directory...
(ECHO.>"!SKETCHUP_DIR!\.TEST" && (DEL "!SKETCHUP_DIR!\.TEST" & GOTO AccessOkay)) 2>NUL
ECHO ERROR: You may need elevated permissions to copy to the SketchUp program directory.
GOTO End
:AccessOkay

FOR %%i in (SURubyDebugger.dll SURubyDebugger.pdb) DO (
	ECHO Copying %TARGETDIR%%%i to !SKETCHUP_DIR!...
	XCOPY /DY "%TARGETDIR%%%i" "!SKETCHUP_DIR!" >NUL 2>&1
)
GOTO End

:NotFound
ECHO ERROR: Could not find SketchUp program directory.

:End