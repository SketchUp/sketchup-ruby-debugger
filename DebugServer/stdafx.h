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

// Kludge from Server.cpp duplicated here because the Windows build uses pre-compiled
// headers. These includes must be done after the macros above that exclude bad things
// the Windows API does to the global namespace.
// 
// Ruby keeps messing with the global namespace.
// In this case it redefines memcpy which causes problems for boost.
// This kludge of undefining memcpy after the Ruby headers allows the
// standard memcpy to be available to boost.
#include <ruby.h>
#include <ruby/debug.h>
#include <ruby/encoding.h>
// Undo things Ruby do to the global namespace. This must be done before including
// any standard headers or Win32 API headers.
#undef memcpy
#undef access
#undef fstat
#undef lstat
#undef stati128

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
