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
 *   File: cmutex.hxx
 *
 * Author: $author$
 *   Date: 2/3/2008
 **********************************************************************
 */
#ifndef _CMUTEX_HXX
#define _CMUTEX_HXX

#include "cplatform_mutex.h"
#include "cmutexinterface.hxx"
#include "copened.hxx"
#include "cdebug.h"

#if defined(CMUTEX_WIN32_API) 
#include "cstring.hxx"
#endif /* defined(CMUTEX_WIN32_API) */

#undef CDB_CLASS
#define CDB_CLASS "cMutexT"
/**
 **********************************************************************
 *  Class: cMutexT
 *
 * Author: $author$
 *   Date: 2/3/2008
 **********************************************************************
 */
template
<class TExtends=cOpened,
 class TImplements=cMutexInterface>
 
class cMutexT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cMutexT cDerives;

    MUTEX m_mutex;
    MUTEX_ATTR m_mutexAttr;

#if defined(CMUTEX_WIN32_API) 
/* use Windows API
 */
    cTCHARString m_name;
    const TCHAR* m_nameChars;
#else /* defined(CMUTEX_WIN32_API) */
/* use Unix API
 */
#endif /* defined(CMUTEX_WIN32_API) */

    /**
     **********************************************************************
     * Constructor: cMutexT
     *
     *      Author: $author$
     *        Date: 2/3/2008
     **********************************************************************
     */
    cMutexT(MUTEX mutex=INVALID_MUTEX) 
    : m_mutex(mutex)
#if defined(CMUTEX_WIN32_API) 
/* use Windows API
 */
    , m_nameChars(0)
#else /* defined(CMUTEX_WIN32_API) */
/* use Unix API
 */
#endif /* defined(CMUTEX_WIN32_API) */
    {
    }
    /**
     **********************************************************************
     * Destructor: cMutexT
     *
     *     Author: $author$
     *       Date: 2/3/2008
     **********************************************************************
     */
    virtual ~cMutexT()
    {
        eError error;
        bool isOpen;
        if ((isOpen = (0 != CTHIS GetIsOpen())))
        if ((error = Close(isOpen)))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 2/3/2008
     **********************************************************************
     */
    virtual eError Create
    (const char* named=0,
     bool isAcquired=false,
     bool onlyClosed=true) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        eError error2;

        if ((error2 = Closed(onlyClosed)))
            return error;

#if defined(CMUTEX_WIN32_API) 
/* use Windows API
 */
        if (named)
        {
            LONG length;
            if (0 < (length = m_name.Assignc(named)))
                m_nameChars = m_name.HasChars(length);
        }
        else 
        m_nameChars = 0;

        if (!(InitMutexAttributes(&m_mutexAttr)))
            CDBE("() failed on InitMutexAttributes()\n");
        else
        if (INVALID_MUTEX != (m_mutex = CreateMutex
            (&m_mutexAttr, isAcquired, m_nameChars)))
        {
            CTHIS SetIsOpen();
            error = e_ERROR_NONE;
        }
        else 
        CDBE("() failed on CreateMutex()\n");
#else /* defined(CMUTEX_WIN32_API) */
/* use Unix API
 */
		int err;
        error = e_ERROR_FAILED;
		if ((err = pthread_mutexattr_init(&m_mutexAttr)))
            CDBE("() failed on pthread_mutexattr_init()\n");
        else
        {
		    if ((err = pthread_mutexattr_settype
			    (&m_mutexAttr, PTHREAD_MUTEX_RECURSIVE)))
                CDBE("() failed on pthread_mutexattr_settype()\n");
            else
		    if ((err = pthread_mutex_init(&m_mutex, &m_mutexAttr)))
                CDBE("() failed on pthread_mutex_init()\n");
            else
		    {
                CTHIS SetIsOpen();
                return error = e_ERROR_NONE;
		    }
		    pthread_mutexattr_destroy(&m_mutexAttr);
        }
#endif /* defined(CMUTEX_WIN32_API) */
        return error;
    }
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 2/3/2008
     **********************************************************************
     */
    virtual eError Open
    (const char* named,
     bool onlyClosed=true) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        eError error2;

        if ((error2 = Closed(onlyClosed)))
            return error;

#if defined(CMUTEX_WIN32_API) 
/* use Windows API
 */
#if defined(CMUTEX_WIN32_WCE_API) 
        error = e_ERROR_NOT_SUPPORTED;
#else /* defined(CMUTEX_WIN32_WCE_API) */
        DWORD dwDesiredAccess = MUTEX_ALL_ACCESS;
        BOOL bInheritHandle = FALSE;

        if (named)
        {
            LONG length;
            if (0 < (length = m_name.Assignc(named)))
                m_nameChars = m_name.HasChars(length);
        }
        else m_nameChars = 0;

        if (!m_nameChars)
            CDBE("() missing or blank name\n");
        else
        if (INVALID_MUTEX != (m_mutex = OpenMutex
            (dwDesiredAccess, bInheritHandle, m_nameChars)))
        {
            CTHIS SetIsOpen();
            error = e_ERROR_NONE;
        }
        else 
        CDBE("() failed on CreateMutex()\n");
#endif /* defined(CMUTEX_WIN32_WCE_API) */
#else /* defined(CMUTEX_WIN32_API) */
/* use Unix API
 */
        error = e_ERROR_NOT_SUPPORTED;
#endif /* defined(CMUTEX_WIN32_API) */
        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 2/3/2008
     **********************************************************************
     */
    virtual eError Close
    (bool onlyOpened=false) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        int isOpen;

        if (0 > (isOpen = CTHIS Opened(onlyOpened)))
            return -isOpen;

        if (!isOpen)
            return e_ERROR_NONE;

#if defined(CMUTEX_WIN32_API) 
/* use Windows API
 */
#else /* defined(CMUTEX_WIN32_API) */
/* use Unix API
 */
        int err;
		if ((err = pthread_mutex_destroy(&m_mutex)))
        {
            CDBE("() failed on pthread_mutex_destroy()\n");
            error = e_ERROR_FAILED;
        }
        else error = e_ERROR_NONE;
		if ((err = pthread_mutexattr_destroy(&m_mutexAttr)))
        {
            CDBE("() failed on pthread_mutexattr_destroy()\n");
            error = e_ERROR_FAILED;
        }
#endif /* defined(CMUTEX_WIN32_API) */
        return error;
    }

    /**
     **********************************************************************
     * Function: Acquire
     *
     *   Author: $author$
     *     Date: 2/3/2008
     **********************************************************************
     */
    virtual eError Acquire
    (LONG waitMilliSeconds=INFINITE) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if defined(CMUTEX_WIN32_API) 
/* use Windows API
 */
        DWORD milliSeconds 
        = (0 > waitMilliSeconds)
          ?INFINITE :waitMilliSeconds;
		DWORD result;

		if (WAIT_OBJECT_0 != (result = 
            WaitForSingleObject(m_mutex, milliSeconds)))
        {
		    if (WAIT_TIMEOUT != result)
            {
		        if (WAIT_ABANDONED != result)
                {
                    CDBE("() failed on WaitForSingleObject()\n");
                    return error;
                }

                CDBE("() WAIT_ABANDONED on WaitForSingleObject()\n");
                return e_ERROR_WAIT_ABANDONED;
            }

            return e_ERROR_WAIT_TIMEOUT;
        }
        error = e_ERROR_NONE;
#else /* defined(CMUTEX_WIN32_API) */
/* use Unix API
 */
		int err;
		if (0 < waitMilliSeconds)
        {
            CDBE("() wait milliseconds not implemented\n");
			return e_ERROR_NOT_IMPLEMENTED;
        }
		else if (0 > waitMilliSeconds)
        {
		    if ((err = pthread_mutex_lock(&m_mutex)))
                CDBE("() failed on pthread_mutex_lock()\n");
        }
		else if ((err = pthread_mutex_trylock(&m_mutex)))
                return e_ERROR_WAIT_TIMEOUT;
		if (err)
            error = e_ERROR_FAILED;
        else error = e_ERROR_NONE;
#endif /* defined(CMUTEX_WIN32_API) */
        return error;
    }
    /**
     **********************************************************************
     * Function: Release
     *
     *   Author: $author$
     *     Date: 2/3/2008
     **********************************************************************
     */
    virtual eError Release
    (bool onlyAcquired=false) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if defined(CMUTEX_WIN32_API) 
/* use Windows API
 */
		if (ReleaseMutex(m_mutex))
            return error = e_ERROR_NONE;

        CDBE("() failed on ReleaseMutex()\n");
        error = e_ERROR_FAILED;
#else /* defined(CMUTEX_WIN32_API) */
/* use Unix API
 */
		int err;
		if ((err = pthread_mutex_unlock(&m_mutex)))
        {
            CDBE("() failed on pthread_mutex_unlock()\n");
            error = e_ERROR_FAILED;
        }
        else error = e_ERROR_NONE;
#endif /* defined(CMUTEX_WIN32_API) */
        return error;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cMutex
 *
 * Author: $author$
 *   Date: 2/2/2009
 **********************************************************************
 */
class cMutex
: public cMutexT<cOpened, cMutexInterface>
{
public:
    typedef cMutexT<cOpened, cMutexInterface> cExtends;
    /**
     **********************************************************************
     * Constructor: cMutex
     *
     *      Author: $author$
     *        Date: 2/2/2009
     **********************************************************************
     */
    cMutex(MUTEX mutex=INVALID_MUTEX) 
    : cExtends(mutex)
    {
    }
};

#endif /* _CMUTEX_HXX */
