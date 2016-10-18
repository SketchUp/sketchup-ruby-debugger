// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#define NOMINMAX
// Windows Header Files:
#include <windows.h>
#include <Shlobj.h>

#define BOOST_ALL_NO_LIB = 1

// Ruby was configured for /Md builds. These macros are needed to
// prevent compiler errors with Visual Studio when builds are compiled with MT.

// Ruby 2.0
#define HAVE_ACOSH 1
#define HAVE_CBRT 1
#define HAVE_ERF 1
#define HAVE_TGAMMA 1
#define HAVE_ROUND 1

// Ruby 2.2
#define HAVE_NEXTAFTER 1
