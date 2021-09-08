///////////////////////////////////////////////////////////////////////
//   File: evplatform_chdir.h
//
// Author: $author$
//   Date: 7/20/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_CHDIR_H
#define _EVPLATFORM_CHDIR_H

#include "evplatform.h"

#if defined(WIN32) 
// Windows
#include <direct.h>
#if defined(WIN32_MSC_VER_8) 
// Visual C++ 8.0
#define chdir _chdir
#endif // defined(WIN32_MSC_VER_8)
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_CHDIR_H
