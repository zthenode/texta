///////////////////////////////////////////////////////////////////////
//   File: evplatform_error.h
//
// Author: $author$
//   Date: 7/23/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_ERROR_H
#define _EVPLATFORM_ERROR_H

#include "evplatform.h"

#include <errno.h>
#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_ERROR_H
