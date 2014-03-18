// SketchUp Ruby API Debugger. Copyright 2013 Trimble Navigation Ltd.
// Authors:
// - Bugra Barin
//

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DEBUGSERVER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DEBUGSERVER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef WIN32

#ifdef DEBUGSERVER_EXPORTS
#define DEBUGSERVER_API __declspec(dllexport)
#else
#define DEBUGSERVER_API __declspec(dllimport)
#endif

#else // Mac

#define DEBUGSERVER_API __attribute__ ((visibility("default")))

#endif

extern "C" {

// The one and only exported function called by SketchUp at program startup.
DEBUGSERVER_API bool InitDebugger(const char*);

};
