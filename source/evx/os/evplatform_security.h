///////////////////////////////////////////////////////////////////////
//   File: evplatform_security.h
//
// Author: $author$
//   Date: 5/4/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_SECURITY_H
#define _EVPLATFORM_SECURITY_H

#include "evplatform.h"

#if defined(WIN32) 
// Windows
#define DEFAULT_SECURITY_DESCRIPTOR_DATA_SIZE 4096
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_SECURITY_H
