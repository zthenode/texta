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
 *   File: cplatform_msg.h
 *
 * Author: $author$
 *   Date: 2/6/2008
 **********************************************************************
 */
#ifndef _CPLATFORM_MSG_H
#define _CPLATFORM_MSG_H

#include "cplatform_types.h"
#include "cplatform_ipc.h"

#if defined(WIN32) 
/* Windows
 */
#define MSG_NOERROR 0x1
#define MSG_EXCEPT  0x2
typedef int key_t;
typedef int msgqnum_t;
typedef int msglen_t;
typedef struct msqid_ds
{
	char m_buff[1];
} msqid_ds_t;
#else /* defined(WIN32) */
/* Unix
 */
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define msgclose close
#endif /* defined(WIN32) */

#define INVALID_MSQID -1
typedef key_t KEY_T;
typedef long MSGTYPE_T;

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(WIN32) 
/* Windows
 */
int msgget(key_t key, int msgflg);
int msgctl(int msqid, int cmd, struct msqid_ds *buf);
int msgclose(int msqid);

int msgsnd
(int msqid, const void *msgp, size_t msgsz, int msgflg);
ssize_t	msgrcv
(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);

#else /* defined(WIN32) */
/* Unix
 */
#endif /* defined(WIN32) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_MSG_H */
