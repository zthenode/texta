///////////////////////////////////////////////////////////////////////
//   File: evplatform_mutex.h
//
// Author: $author$
//   Date: 4/7/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_MUTEX_H
#define _EVPLATFORM_MUTEX_H

#include "evplatform.h"

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
#include <pthread.h>
#endif // defined(WIN32)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_MUTEX_H
