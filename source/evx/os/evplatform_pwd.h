///////////////////////////////////////////////////////////////////////
//   File: evplatform_pwd.h
//
// Author: $author$
//   Date: 7/18/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_PWD_H
#define _EVPLATFORM_PWD_H

#include "evplatform_uid.h"
#include "evplatform_gid.h"

#if defined(WIN32) 
// Windows
struct passwd 
{
    char    *pw_name;	  // user name
    char    *pw_passwd;   // user password
    uid_t   pw_uid;	      // user id
    gid_t   pw_gid;	      // group id
    char    *pw_gecos;    // real name
    char    *pw_dir;	  // home directory
    char    *pw_shell;    // shell program
};
#else // defined(WIN32) 
// Unix
#include <pwd.h>
#include <sys/types.h>
#endif // defined(WIN32)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(WIN32) 
// Windows
///////////////////////////////////////////////////////////////////////
// Function: setpwent
//
//   Author: $author$
//     Date: 7/18/2007
///////////////////////////////////////////////////////////////////////
void setpwent(void);
///////////////////////////////////////////////////////////////////////
// Function: endpwent
//
//   Author: $author$
//     Date: 7/18/2007
///////////////////////////////////////////////////////////////////////
void endpwent(void);
///////////////////////////////////////////////////////////////////////
// Function: getpwent
//
//   Author: $author$
//     Date: 7/18/2007
///////////////////////////////////////////////////////////////////////
struct passwd* getpwent(void);
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_PWD_H
