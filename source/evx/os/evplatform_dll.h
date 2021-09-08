///////////////////////////////////////////////////////////////////////
//   File: evplatform_dll.h
//
// Author: $author$
//   Date: 4/11/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_DLL_H
#define _EVPLATFORM_DLL_H

#include "evplatform.h"

#if defined(WINDOWS) 
// Windows
typedef HMODULE DLL;
typedef DLL INVALID_DLL_T;
#define INVALID_DLL 0
#define DLL_FILE_EXTENSION_CHARS "dll"
#else // defined(WINDOWS) 
// Unix
#include <dlfcn.h>
typedef void* DLL;
typedef unsigned INVALID_DLL_T;
#define INVALID_DLL 0
#if defined(MACOSX)
#define DLL_FILE_EXTENSION_CHARS "dylib"
#else // defined(MACOSX)
#define DLL_FILE_EXTENSION_CHARS "so"
#endif // defined(MACOSX)
#endif // defined(WINDOWS)

#define DLL_SYMBOLX(identifier) "" #identifier ""
#define DLL_SYMBOL(identifier) DLL_SYMBOLX(identifier)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_DLL_H
