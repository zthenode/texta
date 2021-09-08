///////////////////////////////////////////////////////////////////////
//   File: cevthreadedqueuedrequestserver.hpp
//
// Author: $author$
//   Date: 4/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVTHREADEDQUEUEDREQUESTSERVER_HPP
#define _CEVTHREADEDQUEUEDREQUESTSERVER_HPP

#include <deque>
#include <vector>
#include "cevqueue.hpp"
#include "cevvector.hpp"
#include "cevsemaphore.hpp"
#include "cevmutex.hpp"
#include "cevbase.hpp"
#include "evdebug.h"

#undef CDB_CLASS
#define CDB_CLASS "CEvThreadedQueuedRequestServer"
///////////////////////////////////////////////////////////////////////
//  Class: CEvThreadedQueuedRequestServer
//
// Author: $author$
//   Date: 4/5/2007
///////////////////////////////////////////////////////////////////////
template
<class TThread,
 class TRequest,
 class TServer,
 class TRequestQueue,
 class TThreadVector,
 class TThreadVectorIterator>

class CEvThreadedQueuedRequestServer
: public TServer
{
public:
    typedef TServer CExtends;
    typedef CEvThreadedQueuedRequestServer CDerives;

    typedef TRequestQueue CEvRequestQueue;
    typedef TThreadVector CEvThreadVector;

	CEvMutex m_queueMutex;
	CEvMutex m_serverMutex;
	CEvSemaphore m_threadSemaphore;
	CEvRequestQueue m_queue;
	CEvThreadVector m_thread;
    UINT m_threads;
    bool m_hasEnded;
    bool m_restart;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvThreadedQueuedRequestServer
    //
    //       Author: $author$
    //         Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    CEvThreadedQueuedRequestServer()
    : m_threads(0),
      m_hasEnded(false),
      m_restart(false)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvThreadedQueuedRequestServer
    //
    //      Author: $author$
    //        Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvThreadedQueuedRequestServer()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Start
    //
    //   Author: $author$
    //     Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Start
    (UINT threads=1) 
    {
        EvError error = EV_ERROR_FAILED;
		CDBF("() in...\n");
		UINT thread;

        SetHasEnded(false);
        SetRestart(false);

		m_thread.resize(threads);

		if ((error = m_serverMutex.Create()))
		{
			CDBE("() failed to create server mutex\n");
			return error;
		}

		if ((error = m_queueMutex.Create()))
		{
			CDBE("() failed to create queue mutex\n");
			m_serverMutex.Destroy();
			return error;
		}

		if ((error = m_threadSemaphore.Create()))
		{
			CDBE("() failed to create thread semaphore\n");
			m_queueMutex.Destroy();
			m_serverMutex.Destroy();
			return error;
		}

		CDBF("() creating %d threads\n", threads);

		for (thread=0; thread<threads; thread++)
		{
			if ((error = m_thread[thread].Create(*this)))
				CDBE("() failed to create thread %d\n", thread);

			else if ((error = m_thread[thread].Start()))
			{
					CDBE("() failed to start thread %d\n", thread);
					m_thread[thread].Destroy(*this);
			}

			if (error)
			{
				while (thread>0)
				{
					--thread;
					m_thread[thread].Finish();
					m_thread[thread].Destroy(*this);
				}
				m_threadSemaphore.Destroy();
				m_queueMutex.Destroy();
				m_serverMutex.Destroy();
				break;
			}
		}
		m_threads = thread;
		CDBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finish
    //
    //   Author: $author$
    //     Date: 8/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finish
    (bool& restart, LONG waitMilliSeconds=INFINITE) 
    {
        EvError error;
        if (!(error = Finish(waitMilliSeconds)))
            restart = GetRestart();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finish
    //
    //   Author: $author$
    //     Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finish
    (LONG waitMilliSeconds=INFINITE) 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
		CDBF("() in...\n");

		while (m_threads>0)
		{
			--m_threads;
			if ((error2 = m_thread[m_threads].Finish(waitMilliSeconds)))
			{
				CDBE("() failed to finish thread %d\n", m_threads);
				if (!error)
					error = error2;
			}
		    else CDBF("() ...finished thread %d\n", m_threads);

			if ((error2 = m_thread[m_threads].Destroy(*this)))
			{
				CDBE("() failed to destroy thread %d\n", m_threads);
				if (!error)
					error = error2;
			}
		    else CDBF("() ...destroyed thread %d\n", m_threads);
		}

		if ((error2 = m_threadSemaphore.Destroy()))
		{
			CDBE("() failed to destroy thread semaphore\n");
			if (!error)
				error = error2;
		}

		if ((error2 = m_queueMutex.Destroy()))
		{
			CDBE("() failed to destroy queue mutex\n");
			if (!error)
				error = error2;
		}

		if ((error2 = m_serverMutex.Destroy()))
		{
			CDBE("() failed to destroy server mutex\n");
			if (!error)
				error = error2;
		}
		CDBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: End
    //
    //   Author: $author$
    //     Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError End() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        TThreadVectorIterator i;

		if ((error2 = m_queueMutex.Acquire()))
		{
			CDBE("() failed to acquire queue mutex\n");
			return error;
		}
        if (GetHasEnded())
        {
		    if ((error2 = m_queueMutex.Release()))
		    {
			    CDBE("() failed to release queue mutex\n");
			    return error;
		    }
            return EV_ERROR_NONE;
        }
        SetHasEnded();
		if ((error2  = m_queueMutex.Release()))
		{
			CDBE("() failed to release queue mutex\n");
			return error;
		}

        for (i = m_thread.begin(); i != m_thread.end(); i++)
        {
		    if ((error = m_threadSemaphore.Give()))
            {
                CDBE("() failed to give thread semaphore\n");
                break;
            }
        }
        error = (*this).Stop();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Restart
    //
    //   Author: $author$
    //     Date: 8/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Restart() 
    {
        EvError error;
        EvError error2;

        if ((error = End()))
            return error;

		if ((error2 = m_queueMutex.Acquire()))
		{
			CDBE("() failed to acquire queue mutex\n");
            return EV_ERROR_FAILED;
		}

        if (!GetRestart())
            SetRestart();

		if ((error2  = m_queueMutex.Release()))
		{
			CDBE("() failed to release queue mutex\n");
            return EV_ERROR_FAILED;
		}
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //   Author: $author$
    //     Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Run
    (TServer& requestServer) 
    {
        EvError error = EV_ERROR_NONE;
		CDBF("() in\n");
		bool notEmpty;

		do
		{
			if ((error = m_threadSemaphore.Take()))
			{
				CDBE("() failed to take thread semaphore\n");
				break;
			}
			if ((error = m_queueMutex.Acquire()))
			{
				CDBE("() failed to acquire queue mutex\n");
				break;
			}

			if ((notEmpty = !m_queue.empty()))
			{
				TRequest request = m_queue.front();
				m_queue.pop_front();
				m_queueMutex.Release();
				requestServer.Service(request, *this);
			}
			else 
			{
				CDBF("() request queue empty\n");
				m_queueMutex.Release();
			}
		}
		while(notEmpty);

		CDBF("() out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (TRequest& request) 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Add
    //
    //   Author: $author$
    //     Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Add
    (TRequest& request) 
    {
        EvError error = EV_ERROR_FAILED;

		if ((error = m_queueMutex.Acquire()))
		{
			CDBE("() failed to acquire queue mutex\n");
			return error;
		}

        if (GetHasEnded())
        {
		    m_queueMutex.Release();
            return EV_ERROR_FAILED;
        }

		m_queue.push_back(request);
		m_queueMutex.Release();
		m_threadSemaphore.Give();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Acquire
    //
    //   Author: $author$
    //     Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Acquire
    (LONG waitMilliSeconds=INFINITE) 
    {
        EvError error = m_serverMutex.Acquire(waitMilliSeconds);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Release
    //
    //   Author: $author$
    //     Date: 4/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Release() 
    {
        EvError error = m_serverMutex.Release();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetHasEnded
    //
    //   Author: $author$
    //     Date: 5/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetHasEnded
    (bool hasEnded=true) 
    {
        m_hasEnded = hasEnded;
        return m_hasEnded;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetHasEnded
    //
    //   Author: $author$
    //     Date: 5/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetHasEnded() const 
    {
        return m_hasEnded;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetRestart
    //
    //   Author: $author$
    //     Date: 8/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetRestart
    (bool restart=true) 
    {
        m_restart = restart;
        return m_restart;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetRestart
    //
    //   Author: $author$
    //     Date: 8/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetRestart() const 
    {
        return m_restart;
    }
};
#endif // _CEVTHREADEDQUEUEDREQUESTSERVER_HPP
