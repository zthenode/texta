/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: cerror.h
 *
 * Author: $author$
 *   Date: 1/9/2007
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CERROR_H
#define _CERROR_H

#include "cplatform.h"

/**
 **********************************************************************
 * Typedef: eError
 *
 * Author: $author$
 * Date:   1/9/2007
 **********************************************************************
 */
typedef int eError;

/**
 **********************************************************************
 * Enum: 
 *
 * Author: $author$
 * Date:   1/9/2007
 **********************************************************************
 */
enum
{
    e_FIRST_ERROR = 0,

    e_ERROR_NONE = e_FIRST_ERROR,
    e_ERROR_FAILED,
    e_ERROR_NOT_DEFINED,
    e_ERROR_NOT_ALLOWED,
    e_ERROR_NOT_IMPLEMENTED,
    e_ERROR_NOT_SUPPORTED,
    e_ERROR_NULL_PARAMETER,
    e_ERROR_MISSING_PARAMETER,
    e_ERROR_EXTRA_PARAMETER,
    e_ERROR_INVALID_PARAMETER,
    e_ERROR_INVALID_PARAMETER_TYPE,
    e_ERROR_INVALID_PARAMETER_SIZE,
    e_ERROR_PARAMETER_SIZE_UNDER,
    e_ERROR_PARAMETER_SIZE_OVER,
    e_ERROR_INVALID_RETURN,
    e_ERROR_INVALID_RETURN_TYPE,
    e_ERROR_INVALID_RETURN_SIZE,
    e_ERROR_RETURN_SIZE_UNDER,
    e_ERROR_RETURN_SIZE_OVER,
    e_ERROR_INITIALIZE,
    e_ERROR_FINALIZE,
    e_ERROR_NOT_INITIALIZED,
    e_ERROR_ALREADY_INITIALIZED,
    e_ERROR_STARTUP,
    e_ERROR_CLEANUP,
    e_ERROR_SHUTDOWN,
    e_ERROR_START,
    e_ERROR_STOP,
    e_ERROR_FINISH,
    e_ERROR_NOT_STARTED,
    e_ERROR_ALREADY_STARTED,
    e_ERROR_WAIT,
    e_ERROR_WAIT_ABANDONED,
    e_ERROR_WAIT_TIMEOUT,
    e_ERROR_LOCK,
    e_ERROR_UNLOCK,
    e_ERROR_NOT_LOCKED,
    e_ERROR_MALLOC,
    e_ERROR_FREE,
    e_ERROR_NEW,
    e_ERROR_DELETE,
    e_ERROR_INSTANTIATE,
    e_ERROR_NOT_INSTANTIATED,
    e_ERROR_ALREADY_INSTANTIATED,
    e_ERROR_STATIC_INSTANCE,
    e_ERROR_GET_INSTANCE,
    e_ERROR_HOLD_INSTANCE,
    e_ERROR_FREE_INSTANCE,
    e_ERROR_ACQUIRE,
    e_ERROR_RELEASE,
    e_ERROR_NOT_ACQUIRED,
    e_ERROR_ALREADY_ACQUIRED,
    e_ERROR_ATTACH,
    e_ERROR_DETACH,
    e_ERROR_NOT_ATTACHED,
    e_ERROR_ALREADY_ATTACHED,
    e_ERROR_CREATE,
    e_ERROR_DESTROY,
    e_ERROR_NOT_CREATED,
    e_ERROR_ALREADY_CREATED,
    e_ERROR_FIND,
    e_ERROR_FOUND,
    e_ERROR_NOT_FOUND,
    e_ERROR_EXIST,
    e_ERROR_NOT_EXIST,
    e_ERROR_ALREADY_EXIST,
    e_ERROR_MEMBER,
    e_ERROR_NOT_MEMBER,
    e_ERROR_ALREADY_MEMBER,
    e_ERROR_OPEN,
    e_ERROR_CLOSE,
    e_ERROR_NOT_OPEN,
    e_ERROR_ALREADY_OPEN,
    e_ERROR_SET_MODE,
    e_ERROR_GET_MODE,
    e_ERROR_SET_HANDLE,
    e_ERROR_GET_HANDLE,
    e_ERROR_SET_BUFFER,
    e_ERROR_GET_BUFFER,
    e_ERROR_TELL,
    e_ERROR_SEEK,
    e_ERROR_FILL,
    e_ERROR_FLUSH,
    e_ERROR_CLEAR,
    e_ERROR_GET,
    e_ERROR_PUT,
    e_ERROR_READ,
    e_ERROR_WRITE,
    e_ERROR_COPY,
    e_ERROR_ENDOF,
    e_ERROR_BEGINOF,
    e_ERROR_FULL,
    e_ERROR_EMPTY,
    e_ERROR_INVALID_OPTION,
    e_ERROR_INVALID_MODE,
    e_ERROR_IOCTL,
    e_ERROR_IOCTL_COMMAND,
    e_ERROR_IOCTL_PARAMETER,
    e_ERROR_IOCTL_PARAMETER_SIZE,
    e_ERROR_IOCTL_RETURN_SIZE,
    e_ERROR_PRINT_FORMATTED,
    e_ERROR_VPRINT_FORMATTED,
    e_ERROR_INVALID_SYNTAX,

    e_NEXT_ERROR,
    e_LAST_ERROR = e_NEXT_ERROR-1
};

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif /* _CERROR_H */
