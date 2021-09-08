///////////////////////////////////////////////////////////////////////
//   File: evplatform_ticks.h
//
// Author: $author$
//   Date: 6/12/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_TICKS_H
#define _EVPLATFORM_TICKS_H

#include "evplatform.h"

#if defined(WIN32) 
// Windows
#define GetMillisecondTicks GetTickCount
#else // defined(WIN32) 
// Unix
#define GetMillisecondTicks() 0
#endif // defined(WIN32)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_TICKS_H
