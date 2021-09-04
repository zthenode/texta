/*
///////////////////////////////////////////////////////////////////////
//   File: evplatform.h
//
// Author: $author$
//   Date: 5/13/2008
///////////////////////////////////////////////////////////////////////
*/
#ifndef _EVPLATFORM_H
#define _EVPLATFORM_H

#include "cplatform.h"

#define EV_NO_STD_STRING_CLEAR NO_STD_STRING_CLEAR

#define EV_PLATFORM_EXPORT PLATFORM_EXPORT
#define EV_PLATFORM_IMPORT PLATFORM_IMPORT

#define EV_PLATFORM_CCAST(type) PLATFORM_CCAST(type)
#define EV_PLATFORM_DCAST(type) PLATFORM_DCAST(type)
#define EV_PLATFORM_SCAST(type) PLATFORM_SCAST(type)
#define EV_PLATFORM_RCAST(type) PLATFORM_RCAST(type)

#if defined(__cplusplus) 
extern "C" {
#endif /*// defined(__cplusplus) */

#if defined(__cplusplus) 
}
#endif /*// defined(__cplusplus) */

#endif /*// _EVPLATFORM_H */
