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
 *   File: csemaphore.hxx
 *
 * Author: $author$
 *   Date: 2/5/2008
 **********************************************************************
 */
#ifndef _CSEMAPHORE_HXX
#define _CSEMAPHORE_HXX

#include "cplatform_semaphore.h"
#include "csemaphoreinterface.hxx"
#include "copened.hxx"
#include "cdebug.h"

#if defined(CSEMAPHORE_WIN32_API) 
/* use Windows API
 */
#include "cstring.hxx"
#include "cwinsecurityattributes.hxx"
#else /* defined(CSEMAPHORE_WIN32_API) */
/* use Unix API
 */
#endif /* defined(CSEMAPHORE_WIN32_API) */

#undef CDB_CLASS
#define CDB_CLASS "cSemaphoreT"
/**
 **********************************************************************
 *  Class: cSemaphoreT
 *
 * Author: $author$
 *   Date: 2/5/2008
 **********************************************************************
 */
template
<class TExtends=cOpened,
 class TImplements=cSemaphoreInterface>
 
class cSemaphoreT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cSemaphoreT cDerives;

    SEMAPHORE m_sem;

#if defined(CSEMAPHORE_WIN32_API) 
/* use Windows API
 */
    cWinSecurityAttributes m_attr;
    cTCHARString m_name;
    const TCHAR* m_nameChars;
#else /* defined(CSEMAPHORE_WIN32_API) */
/* use Unix API
 */
    sem_t m_unnamed;
#endif /* defined(CSEMAPHORE_WIN32_API) */

    /**
     **********************************************************************
     * Constructor: cSemaphoreT
     *
     *      Author: $author$
     *        Date: 2/5/2008
     **********************************************************************
     */
    cSemaphoreT
    (SEMAPHORE sem=INVALID_SEMAPHORE, bool isOpen=false) 
    : cExtends(isOpen)
    , m_sem(sem)
#if defined(CSEMAPHORE_WIN32_API) 
/* use Windows API
 */
    , m_nameChars(0)
#else /* defined(CSEMAPHORE_WIN32_API) */
/* use Unix API
 */
#endif /* defined(CSEMAPHORE_WIN32_API) */
    {
    }
    /**
     **********************************************************************
     * Destructor: cSemaphoreT
     *
     *     Author: $author$
     *       Date: 2/5/2008
     **********************************************************************
     */
    virtual ~cSemaphoreT()
    {
        eError error;
        bool isOpen;
        if ((isOpen = (0 < CTHIS GetIsOpen())))
        if ((error = Close(isOpen)))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 2/11/2008
     **********************************************************************
     */
    virtual eError Create
    (const char* named=0,
     UINT released=0,
     bool onlyClosed=true) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        eError error2;

        if ((error2 = CTHIS Closed(onlyClosed)))
            return error;

#if defined(CSEMAPHORE_WIN32_API) 
/* use Windows API
 */
#else /* defined(CSEMAPHORE_WIN32_API) */
/* use Unix API
 */
        int pshared = named
        ?SEMAPHORE_ATTR_SHARED_PROCESS
        :SEMAPHORE_ATTR_SHARED_THREAD;
        int oflag = O_CREAT;
        mode_t smode = S_IRUSR | S_IWUSR;
		int err;
        if (named)
        if (named[0])
        {
            CDBT("() sem_open(name=\"%s\", oflag=0x%x, smode=0x%x)\n", named, oflag, smode);
		    if (!(m_sem = sem_open(named, oflag, smode, released)))
            {
                CDBE("() failed on sem_open()\n");
                return e_ERROR_FAILED;
            }
            CTHIS SetIsOpen();
            return e_ERROR_NONE;
        }
        CDBT("() sem_init(..., pshared=%d, released=%u)\n", pshared, released);
		if ((err = sem_init(&m_unnamed, pshared, released)))
        {
            CDBE("() failed on sem_init()\n");
            return e_ERROR_FAILED;
        }
        CTHIS SetIsOpen();
        m_sem = &m_unnamed;
        error = e_ERROR_NONE;
#endif /* defined(CSEMAPHORE_WIN32_API) */
        return error;
    }
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 2/11/2008
     **********************************************************************
     */
    virtual eError Open
    (const char* named,
     bool onlyClosed=true) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        eError error2;

        if ((error2 = CTHIS Closed(onlyClosed)))
            return error;

#if defined(CSEMAPHORE_WIN32_API) 
/* use Windows API
 */
#else /* defined(CSEMAPHORE_WIN32_API) */
/* use Unix API
 */
        int oflag = 0;
        if (named)
        if (named[0])
        {
            CDBT("() sem_open(name=\"%s\", oflag=0x%x)\n", named, oflag);
		    if (!(m_sem = sem_open(named, oflag)))
            {
                CDBE("() failed on sem_open()\n");
                return e_ERROR_FAILED;
            }
            CTHIS SetIsOpen();
            return e_ERROR_NONE;
        }
#endif /* defined(CSEMAPHORE_WIN32_API) */
        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 2/11/2008
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

#if defined(CSEMAPHORE_WIN32_API) 
/* use Windows API
 */
#else /* defined(CSEMAPHORE_WIN32_API) */
/* use Unix API
 */
		int err;
        if (&m_unnamed == m_sem)
        {
		    if ((err = sem_destroy(&m_unnamed)))
            {
                CDBE("() failed on sem_destroy()\n");
                error = e_ERROR_FAILED;
            }
            else error = e_ERROR_NONE;
        }
        else if (m_sem)
        {
		    if ((err = sem_close(m_sem)))
            {
                CDBE("() failed on sem_close()\n");
                error = e_ERROR_FAILED;
            }
            else error = e_ERROR_NONE;
        }
        CTHIS SetIsOpen(false);
        m_sem = INVALID_SEMAPHORE;
#endif /* defined(CSEMAPHORE_WIN32_API) */
        return error;
    }
    /**
     **********************************************************************
     * Function: Acquire
     *
     *   Author: $author$
     *     Date: 2/12/2008
     **********************************************************************
     */
    virtual eError Acquire
    (UINT amount=1,
     LONG waitMilliSeconds=INFINITE) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        int isOpen;

        if (0 > (isOpen = CTHIS Opened(true)))
            return -isOpen;

#if defined(CSEMAPHORE_WIN32_API) 
/* use Windows API
 */
#else /* defined(CSEMAPHORE_WIN32_API) */
/* use Unix API
 */
		int err;
        if (!m_sem)
            return e_ERROR_FAILED;
        if (1 < amount)
            return e_ERROR_NOT_SUPPORTED;
        if (0 < waitMilliSeconds)
            return e_ERROR_NOT_IMPLEMENTED;
        else
        if (0 > waitMilliSeconds)
        {
		    if ((err = sem_wait(m_sem)))
            {
                if (EINTR == errno)
                {
                    CDBE("() sem_wait() abandoned\n");
                    return e_ERROR_WAIT_ABANDONED;
                }
                CDBE("() failed on sem_wait()\n");
                return e_ERROR_FAILED;
            }
        }
        else
		if ((err = sem_trywait(m_sem)))
        {
            if (EAGAIN == errno)
            {
                CDBT("() sem_trywait() timeout\n");
                return e_ERROR_WAIT_TIMEOUT;
            }
            else
            if (EINTR == errno)
            {
                CDBE("() sem_trywait() abandoned\n");
                return e_ERROR_WAIT_ABANDONED;
            }
            CDBE("() failed on sem_trywait()\n");
            return e_ERROR_FAILED;
        }
        error = e_ERROR_NONE;
#endif /* defined(CSEMAPHORE_WIN32_API) */
        return error;
    }
    /**
     **********************************************************************
     * Function: Release
     *
     *   Author: $author$
     *     Date: 2/12/2008
     **********************************************************************
     */
    virtual eError Release
    (UINT amount=1,
     bool onlyAcquired=false) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        int isOpen;

        if (0 > (isOpen = CTHIS Opened(true)))
            return -isOpen;

#if defined(CSEMAPHORE_WIN32_API) 
/* use Windows API
 */
#else /* defined(CSEMAPHORE_WIN32_API) */
/* use Unix API
 */
        if (!m_sem)
            return e_ERROR_FAILED;
		for (UINT i=0; i<amount; i++)
		{
			int err;
            CDBT("() sem_post()...\n");
			if ((err = sem_post(m_sem)))
            {
                CDBE("() failed on sem_post()\n");
				return e_ERROR_FAILED;
            }
            CDBT("() ...sem_post()\n");
		}
        error = e_ERROR_NONE;
#endif /* defined(CSEMAPHORE_WIN32_API) */
        return error;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cSemaphore
 *
 * Author: $author$
 *   Date: 2/11/2008
 **********************************************************************
 */
class cSemaphore
: public cSemaphoreT<cOpened, cSemaphoreInterface>
{
public:
    typedef cSemaphoreT<cOpened, cSemaphoreInterface> cExtends;
    typedef cSemaphore cDerives;
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 2/5/2008
     **********************************************************************
     */
    virtual eError DeleteInstance()
    {
        eError error = e_ERROR_NONE;
        delete this;
        return error;
    }
};
#endif /* _CSEMAPHORE_HXX */
