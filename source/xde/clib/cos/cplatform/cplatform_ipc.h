/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cplatform_ipc.h
 *
 * Author: $author$
 *   Date: 2/6/2008
 **********************************************************************
 */
#ifndef _CPLATFORM_IPC_H
#define _CPLATFORM_IPC_H

#include "cplatform.h"

#if defined(WIN32) 
/* Windows
 */
#include <time.h>
#define IPC_PRIVATE -1
#define IPC_CREAT  0x1
#define IPC_EXCL   0x2
#define IPC_RMID   0x4
#define IPC_NOWAIT 0x8
#else /* defined(WIN32) */
/* Unix
 */
#include <sys/ipc.h>
#endif /* defined(WIN32) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_IPC_H */
