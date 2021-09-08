/**
 **********************************************************************
 * Copyright (c) $year$ $author$
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
 *   File: error.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _ERROR_HXX
#define _ERROR_HXX

#include "platform.hxx"

/**
 **********************************************************************
 * Typedef: Error
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
typedef int Error;

/**
 **********************************************************************
 * Enum: 
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
enum
{
    FIRST_ERROR = 0,

    _ERROR_NONE = FIRST_ERROR,
    _ERROR_FAILED,

    _ERROR_NOT_DEFINED,
    _ERROR_NOT_ALLOWED,
    _ERROR_NOT_IMPLEMENTED,

    _ERROR_NULL_PARAMETER,
    _ERROR_MISSING_PARAMETER,
    _ERROR_EXTRA_PARAMETER,
    _ERROR_INVALID_PARAMETER,
    _ERROR_INVALID_PARAMETER_TYPE,
    _ERROR_INVALID_PARAMETER_SIZE,
    _ERROR_PARAMETER_SIZE_UNDER,
    _ERROR_PARAMETER_SIZE_OVER,

    _ERROR_INVALID_RETURN,
    _ERROR_INVALID_RETURN_TYPE,
    _ERROR_INVALID_RETURN_SIZE,
    _ERROR_RETURN_SIZE_UNDER,
    _ERROR_RETURN_SIZE_OVER,

    _ERROR_INVALID_OPTION,
    _ERROR_INVALID_MODE,

    _ERROR_INITIALIZE,
    _ERROR_FINALIZE,
    _ERROR_NOT_INITIALIZED,
    _ERROR_ALREADY_INITIALIZED,

    _ERROR_START,
    _ERROR_STOP,
    _ERROR_FINISH,
    _ERROR_NOT_STARTED,
    _ERROR_ALREADY_STARTED,

    _ERROR_WAIT,
    _ERROR_WAIT_ABANDONED,
    _ERROR_WAIT_TIMEOUT,

    _ERROR_LOCK,
    _ERROR_UNLOCK,
    _ERROR_NOT_LOCKED,
    _ERROR_ALREADY_LOCKED,

    _ERROR_MALLOC,
    _ERROR_FREE,
    _ERROR_NEW,
    _ERROR_DELETE,

    _ERROR_ATTACH,
    _ERROR_DETACH,
    _ERROR_NOT_ATTACHED,
    _ERROR_ALREADY_ATTACHED,

    _ERROR_CREATE,
    _ERROR_DESTROY,
    _ERROR_NOT_CREATED,
    _ERROR_ALREADY_CREATED,

    _ERROR_FIND,
    _ERROR_FOUND,
    _ERROR_NOT_FOUND,

    _ERROR_EXIST,
    _ERROR_NOT_EXIST,
    _ERROR_ALREADY_EXIST,

    _ERROR_OPEN,
    _ERROR_CLOSE,
    _ERROR_NOT_OPEN,
    _ERROR_ALREADY_OPEN,

    _ERROR_TELL,
    _ERROR_SEEK,
    _ERROR_FILL,
    _ERROR_FLUSH,
    _ERROR_CLEAR,

    _ERROR_GET,
    _ERROR_PUT,
    _ERROR_READ,
    _ERROR_WRITE,

    _ERROR_ENDOF,
    _ERROR_BEGINOF,
    _ERROR_FULL,
    _ERROR_EMPTY,

    NEXT_ERROR,
    LAST_ERROR = NEXT_ERROR-1
};

#endif /* _ERROR_HXX */
