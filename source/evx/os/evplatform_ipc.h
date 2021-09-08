///////////////////////////////////////////////////////////////////////
//   File: evplatform_ipc.h
//
// Author: $author$
//   Date: 7/18/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPLATFORM_IPC_H
#define _EVPLATFORM_IPC_H

#include "evplatform.h"

#if defined(WIN32) 
// Windows
enum 
{
    IPC_CREAT   = 1,
    IPC_RMID    = (1<<1),
    IPC_PRIVATE = (1<<2),
    IPC_EXCL    = (1<<3),
    IPC_NOWAIT  = (1<<4)
};
#else // defined(WIN32) 
// Unix
#include <sys/ipc.h>
#endif // defined(WIN32)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif // _EVPLATFORM_IPC_H
