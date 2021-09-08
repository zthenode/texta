///////////////////////////////////////////////////////////////////////
//   File: evplatform_uid.h
//
// Author: $author$
//   Date: 7/18/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_UID_H
#define _EVPLATFORM_UID_H

#include "evplatform.h"

#if defined(WIN32) 
// Windows
typedef int UID;
typedef UID uid_t;
#else // defined(WIN32) 
// Unix
#include <unistd.h>
#include <sys/types.h>
typedef uid_t UID;
#endif // defined(WIN32)

#define INVALID_UID ((UID)-1)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(WIN32) 
// Windows
///////////////////////////////////////////////////////////////////////
// Function: setuid
//
//   Author: $author$
//     Date: 7/18/2007
///////////////////////////////////////////////////////////////////////
int setuid(uid_t uid);
///////////////////////////////////////////////////////////////////////
// Function: getuid
//
//   Author: $author$
//     Date: 7/18/2007
///////////////////////////////////////////////////////////////////////
uid_t getuid(void);

///////////////////////////////////////////////////////////////////////
// Function: seteuid
//
//   Author: $author$
//     Date: 7/18/2007
///////////////////////////////////////////////////////////////////////
int seteuid(uid_t uid);
///////////////////////////////////////////////////////////////////////
// Function: geteuid
//
//   Author: $author$
//     Date: 7/18/2007
///////////////////////////////////////////////////////////////////////
uid_t geteuid(void);

///////////////////////////////////////////////////////////////////////
// Function: setreuid
//
//   Author: $author$
//     Date: 7/18/2007
///////////////////////////////////////////////////////////////////////
int setreuid(uid_t uid);
///////////////////////////////////////////////////////////////////////
// Function: setfsuid
//
//   Author: $author$
//     Date: 7/18/2007
///////////////////////////////////////////////////////////////////////
int setfsuid(uid_t uid);
#endif // defined(WIN32)

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_UID_H
