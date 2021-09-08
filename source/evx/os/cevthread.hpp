///////////////////////////////////////////////////////////////////////
//   File: cevthread.hpp
//
// Author: $author$
//   Date: 4/6/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVTHREAD_HPP
#define _CEVTHREAD_HPP

#include "cevbase.hpp"
#include "evplatform_thread.h"
#include "evdebug.h"

#undef CDB_CLASS
#define CDB_CLASS "CEvThread"
///////////////////////////////////////////////////////////////////////
//  Class: CEvThread
//
// Author: $author$
//   Date: 4/6/2007
///////////////////////////////////////////////////////////////////////
template
<class TExtends=CEvBase>

class CEvThread
: public TExtends
{
public:
    typedef TExtends CExtends;
    typedef CEvThread CDerives;

	THREAD m_thread;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvThread
    //
    //       Author: $author$
    //         Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    CEvThread
    (THREAD thread=INVALID_THREAD) 
    : m_thread(thread)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvThread
    //
    //      Author: $author$
    //        Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvThread()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Start
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Start() 
    {
        EvError error = EV_ERROR_FAILED;

        if (((THREAD)INVALID_THREAD) != m_thread)
            return EV_ERROR_ALREADY_STARTED;

#if defined(WIN32) 
// Windows
		if (INVALID_THREAD != (m_thread = CreateThread
			(NULL, 0, ThreadFunc, this, 0, NULL)))
#else // defined(WIN32) 
// Unix
		int err;
		if (!(err = pthread_create
			(&m_thread, NULL, ThreadFunc, this)))
#endif // defined(WIN32)
        error = EV_ERROR_NONE;

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finish
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finish
    (LONG waitMilliSeconds=INFINITE) 
    {
        EvError error = EV_ERROR_FAILED;
        CDBT("() in...\n");

#if defined(WIN32) 
// Windows
        DWORD milliSeconds 
        = (0 > waitMilliSeconds)
          ?INFINITE
          :waitMilliSeconds;
		DWORD result;

		if (WAIT_OBJECT_0 != (result = WaitForSingleObject
			(m_thread, milliSeconds)))
		if (WAIT_TIMEOUT != result)
            return error;
        else return EV_ERROR_WAIT_TIMEOUT;

		if (CloseHandle(m_thread))
#else // defined(WIN32) 
// Unix
		int err;
        void* threadReturn;
		if (0 <= waitMilliSeconds)
			return EV_ERROR_NOT_IMPLEMENTED;
        CDBT("() joining thread...\n");
		if ((err = pthread_join(m_thread, &threadReturn)))
            CDBE("() failed to join thread\n");
        else
#endif // defined(WIN32)
        {
#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
            CDBT("() ...joined thread\n");
#endif // defined(WIN32)
            m_thread = INVALID_THREAD;
            error = EV_ERROR_NONE;
        }
        CDBT("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Run() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ThreadFunc
    //
    //   Author: $author$
    //     Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    static THREAD_RESULT THREAD_FUNC 
	ThreadFunc(THREAD_PARAM param)
	{
		THREAD_RESULT result = 0;
		CEvThread* thread;

        CDBT("() in...\n");
		if ((thread = (CEvThread*)(param)))
			thread->Run();
        CDBT("() ...exit...\n");
        THREAD_EXIT(result);
        CDBT("() ...out\n");
		return result;
	}
};
#undef CDB_CLASS
#endif // _CEVTHREAD_HPP
