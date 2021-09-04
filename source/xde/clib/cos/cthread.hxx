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
 *   File: cthread.hxx
 *
 * Author: $author$
 *   Date: 2/14/2008
 **********************************************************************
 */
#ifndef _CTHREAD_HXX
#define _CTHREAD_HXX

#include "cplatform_thread.h"
#include "cthreadinterface.hxx"
#include "cbase.hxx"
#include "cdebug.h"

#if defined(CTHREAD_WINDOWS_API) 
/* use Windows API
 */
#if defined(CTHREAD_WINDOWS_API_USE_CREATETHREAD) 
/* Use CreateThread
 */
#else /* defined(CTHREAD_WINDOWS_API_USE_CREATETHREAD) */
/* Use beginthread
 */
#include <process.h>
#endif /* defined(CTHREAD_WINDOWS_API_USE_CREATETHREAD) */
#else /* defined(CTHREAD_WINDOWS_API) */
/* use Unix API
 */
#endif /* defined(CTHREAD_WINDOWS_API) */

#if defined(Yield) 
#define defined_Yield Yield
#undef Yield
#endif /* defined(Yield) */

#undef CDB_CLASS
#define CDB_CLASS "cThreadT"
/**
 **********************************************************************
 *  Class: cThreadT
 *
 * Author: $author$
 *   Date: 2/14/2008
 **********************************************************************
 */
template
<class TBase=cBase,
 class TThreadInterface=cThreadInterface,
 class TThreadImplement=cThreadImplement,
 class TImplements=TThreadImplement,
 class TExtends=TBase>
 
class cThreadT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cThreadT cDerives;

    THREAD m_thread;

#if defined(CTHREAD_WINDOWS_API) 
/* use Windows API
 */
#else /* defined(CTHREAD_WINDOWS_API) */
/* use Unix API
 */
    pthread_attr_t m_thread_attr;
#endif /* defined(CTHREAD_WINDOWS_API) */

    TThreadInterface* m_deligate;

    /**
     **********************************************************************
     * Constructor: cThreadT
     *
     *      Author: $author$
     *        Date: 2/14/2008
     **********************************************************************
     */
    cThreadT
    (TThreadInterface* deligate=0,
     THREAD thread=INVALID_THREAD) 
    : m_thread(thread),
      m_deligate(deligate)
    {
    }
    /**
     **********************************************************************
     * Destructor: cThreadT
     *
     *     Author: $author$
     *       Date: 2/14/2008
     **********************************************************************
     */
    virtual ~cThreadT()
    {
    }
    /**
     **********************************************************************
     * Function: Start
     *
     *   Author: $author$
     *     Date: 2/14/2008
     **********************************************************************
     */
    virtual eError Start() 
    {
        TThreadInterface* instance = this;
        eError error = e_ERROR_FAILED;
#if defined(CTHREAD_WINDOWS_API) 
/* use Windows API
 */
#if defined(CTHREAD_WINDOWS_API_USE_CREATETHREAD) 
/* Use CreateThread
 */
        LPSECURITY_ATTRIBUTES security_attributes=NULL;
        DWORD init_flag=0;
        DWORD stack_size=0;
        DWORD tid;
        if (!(INVALID_THREAD != (m_thread = CreateThread
            (security_attributes, stack_size, 
			 ThreadFunc, instance, init_flag, &tid))))
             CDBT("() failed on CreateThread()\n");
#else /* defined(CTHREAD_WINDOWS_API_USE_CREATETHREAD) */
/* Use beginthread
 */
        void* security_attributes=NULL;
        unsigned init_flag=0;
        unsigned stack_size=0;
        unsigned tid;
        if (!(INVALID_THREAD != (m_thread =(THREAD)_beginthreadex
            (security_attributes, stack_size, 
			 ThreadFunc, instance, init_flag, &tid))))
             CDBT("() failed on _beginthreadex()\n");
#endif /* defined(CTHREAD_WINDOWS_API_USE_CREATETHREAD) */
        else error = e_ERROR_NONE;
#else /* defined(CTHREAD_WINDOWS_API) */
/* use Unix API
 */
		int err;
		if ((err = pthread_attr_init(&m_thread_attr)))
            CDBE("() failed on pthread_attr_init()\n");
        else
		if ((err = pthread_create
            (&m_thread, &m_thread_attr, ThreadFunc, instance)))
        {
            CDBE("() failed on pthread_create()\n");
            pthread_attr_destroy(&m_thread_attr);
            m_thread = INVALID_THREAD;
        }
        else error = e_ERROR_NONE;
#endif /* defined(CTHREAD_WINDOWS_API) */
        return error;
    }
    /**
     **********************************************************************
     * Function: Finish
     *
     *   Author: $author$
     *     Date: 2/14/2008
     **********************************************************************
     */
    virtual eError Finish
    (LONG waitMilliSeconds=INFINITE,
     bool onlyStarted=false) 
    {
        eError error = e_ERROR_FAILED;

        if ((THREAD)(INVALID_THREAD) == m_thread)
        if (onlyStarted)
            return e_ERROR_NOT_STARTED;
        else return e_ERROR_NONE;

#if defined(CTHREAD_WINDOWS_API) 
/* use Windows API
 */
        DWORD result;
        BOOL closed;
        result = WaitForSingleObject(m_thread, waitMilliSeconds);
        switch(result)
        {
        case WAIT_OBJECT_0:
            if ((closed = CloseHandle(m_thread)))
            {
                m_thread = INVALID_THREAD;
                error = e_ERROR_NONE;
            }
            else error = e_ERROR_CLOSE;
            break;
        case WAIT_TIMEOUT:
            error = e_ERROR_WAIT_TIMEOUT;
            break;
        case WAIT_ABANDONED:
            error = e_ERROR_WAIT_ABANDONED;
            break;
        }
#else /* defined(CTHREAD_WINDOWS_API) */
/* use Unix API
 */
		int err;
        void* threadReturn;
		if (0 <= waitMilliSeconds)
			return e_ERROR_NOT_IMPLEMENTED;
        else error = e_ERROR_NONE;
        CDBT("() joining thread...\n");
		if ((err = pthread_join(m_thread, &threadReturn)))
        {
            CDBE("() failed on pthread_join()\n");
            error = e_ERROR_FAILED;
        }
        else CDBT("() ...joined thread\n");
        if ((err = pthread_attr_destroy(&m_thread_attr)))
        {
            CDBE("() failed on pthread_attr_destroy()\n");
            error = e_ERROR_FAILED;
        }
        m_thread = INVALID_THREAD;
#endif /* defined(CTHREAD_WINDOWS_API) */
        return error;
    }
    /**
     **********************************************************************
     * Function: Run
     *
     *   Author: $author$
     *     Date: 2/14/2008
     **********************************************************************
     */
    virtual eError Run() 
    {
        eError error = e_ERROR_NONE;
        TThreadInterface* deligate;
        CDBT("() in...\n");
        if ((deligate = GetDeligate()))
        {
            CDBT("() deligate->Run()...\n");
            error = deligate->Run();
        }
        CDBT("() ...out\n");
        return error;
    }
    /**
     **********************************************************************
     * Function: Yield
     *
     *   Author: $author$
     *     Date: 2/4/2009
     **********************************************************************
     */
    virtual eError Yield() 
    {
        eError error = e_ERROR_NONE;
#if defined(CTHREAD_WINDOWS_API) 
/* Windows
 */
        Sleep(0);
#else /* defined(CTHREAD_WINDOWS_API) */
/* Unix
 */
        usleep(0);
#endif /* defined(CTHREAD_WINDOWS_API) */
        return error;
    }
    /**
     **********************************************************************
     * Function: SetDeligate
     *
     *   Author: $author$
     *     Date: 2/14/2008
     **********************************************************************
     */
    virtual eError SetDeligate
    (TThreadInterface* deligate) 
    {
        eError error = e_ERROR_NONE;
        m_deligate = deligate;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetDeligate
     *
     *   Author: $author$
     *     Date: 2/14/2008
     **********************************************************************
     */
    virtual TThreadInterface* GetDeligate() const 
    {
        return m_deligate;
    }
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 2/14/2008
     **********************************************************************
     */
    virtual eError DeleteInstance() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: ThreadFunc
     *
     *   Author: $author$
     *     Date: 2/15/2008
     **********************************************************************
     */
    static THREAD_RESULT THREAD_FUNC 
	ThreadFunc(THREAD_PARAM param)
	{
		THREAD_RESULT result = 0;
		TThreadInterface* instance;

        CDBT("() in...\n");
		if ((instance = (TThreadInterface*)(param)))
        {
            CDBT("() instance->Run()...\n");
			instance->Run();
        }

        CDBT("() ...exit...\n");
        THREAD_EXIT(result);

        CDBT("() ...out\n");
		return result;
	}
};
#undef CDB_CLASS

#if defined(defined_Yield) 
#define Yield defined_Yield
#undef defined_Yield
#endif /* defined(Yield) */

/**
 **********************************************************************
 *  Class: cThread
 *
 * Author: $author$
 *   Date: 2/1/2009
 **********************************************************************
 */
class cThread
: public cThreadT
  <cBase,cThreadInterface,cThreadImplement>
{
public:
    typedef cThreadT
    <cBase,cThreadInterface,cThreadImplement> cExtends;
    /**
     **********************************************************************
     * Constructor: cThread
     *
     *      Author: $author$
     *        Date: 2/1/2009
     **********************************************************************
     */
    cThread
    (cThreadInterface* deligate=0,
     THREAD thread=INVALID_THREAD)
    : cExtends(deligate, thread)
    {
    }
};

#endif /* _CTHREAD_HXX */
