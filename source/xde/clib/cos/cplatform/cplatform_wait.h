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
 *   File: cplatform_wait.h
 *
 * Author: $author$
 *   Date: 2/13/2008
 **********************************************************************
 */
#ifndef _CPLATFORM_WAIT_H
#define _CPLATFORM_WAIT_H

#include "cplatform_types.h"

#if defined(WIN32) 
/* Windows
 */
enum {
    WNOHANG = 0x1,
    WUNTRACED = 0x2,
    WCONTINUED = 0x4,

    WIFEXITED =0x8,
    WEXITSTATUS ,
    WIFSIGNALED,
    WTERMSIG,
    WCOREDUMP,
    WIFSTOPPED,
    WSTOPSIG,
    WIFCONTINUED
};
#else /* defined(WIN32) */
/* Unix
 */
#include <sys/types.h>
#include <sys/wait.h>
#endif /* defined(WIN32) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(WIN32) 
/* Windows
 */
pid_t wait(int *status);
pid_t waitpid(pid_t pid, int *status, int options);
#else /* defined(WIN32) */
/* Unix
 */
#endif /* defined(WIN32) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_WAIT_H */
