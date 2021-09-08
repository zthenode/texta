///////////////////////////////////////////////////////////////////////
//   File: evplatform_semaphore.h
//
// Author: $author$
//   Date: 4/7/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_SEMAPHORE_H
#define _EVPLATFORM_SEMAPHORE_H

#include "evplatform.h"

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
#include <semaphore.h>
#include <time.h>
#endif // defined(WIN32)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_SEMAPHORE_H
