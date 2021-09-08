///////////////////////////////////////////////////////////////////////
//   File: evplatform_exec.cpp
//
// Author: $author$
//   Date: 7/20/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "evplatform_exec.h"
#include "evdebug.h"

#if defined(WIN32) 
// Windows
///////////////////////////////////////////////////////////////////////
// Function: execvp
//
//   Author: $author$
//     Date: 7/20/2007
///////////////////////////////////////////////////////////////////////
int execvp
(const char* file,
 char*const argv[]) 
{
    int err = 1;
    int i;
    for (i = 0; argv[i]; i++)
        DBF("() argv[%d] = \"%s\"\n", i, argv[i]);
    return err;
}
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)
