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
 *   File: crequestqueueserver.hxx
 *
 * Author: $author$
 *   Date: 2/17/2008
 **********************************************************************
 */
#ifndef _CREQUESTQUEUESERVER_HXX
#define _CREQUESTQUEUESERVER_HXX

#include "cqueuedrequestserver.hxx"
#include "cqueue.hxx"
#include "cbase.hxx"
#include "cdebug.h"

#undef CDB_CLASS
#define CDB_CLASS "cRequestQueueServerT"
/**
 **********************************************************************
 *  Class: cRequestQueueServerT
 *
 * Author: $author$
 *   Date: 2/17/2008
 **********************************************************************
 */
template
<class TRequest=CHAR,
 class TLength=LONG,
 class TRequestQueue=cQueue,
 class TRequestServer=cQueuedRequestServer>
 
class cRequestQueueServerT
: public TRequestServer
{
public:
    typedef TRequestServer cExtends;
    typedef cRequestQueueServerT cDerives;

    TRequestQueue m_queue;
    bool m_started;
    bool m_finished;
    bool m_stopped;
    bool m_restart;

    /**
     **********************************************************************
     * Constructor: cRequestQueueServerT
     *
     *      Author: $author$
     *        Date: 2/17/2008
     **********************************************************************
     */
    cRequestQueueServerT() 
    : m_started(false),
      m_finished(false),
      m_stopped(false),
      m_restart(false)
    {
    }
    /**
     **********************************************************************
     * Destructor: cRequestQueueServerT
     *
     *     Author: $author$
     *       Date: 2/17/2008
     **********************************************************************
     */
    virtual ~cRequestQueueServerT()
    {
    }

    /**
     **********************************************************************
     * Function: Start
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual eError Start
    (UINT threads=0, bool onlyStopped=false) 
    {
        eError error = e_ERROR_NONE;

        if (GetStarted())
        if (onlyStopped)
            return e_ERROR_ALREADY_STARTED;
        else return e_ERROR_NONE;

        SetFinished(false);
        SetStopped(false);
        SetRestart(false);

        if ((error = Initialize()))
            CDBE("() failed to initialize\n");
        else 
        if ((error = StartThreads(threads)))
            CDBE("() failed to start threads\n");
        else 
        SetStarted(true);
        return error;
    }
    /**
     **********************************************************************
     * Function: Finish
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual eError Finish
    (LONG waitMilliSeconds=INFINITE) 
    {
        eError error = e_ERROR_NONE;
        if ((error = FinishThreads(waitMilliSeconds)))
            CDBE("() failed to finish threads\n");
        else 
        if ((error = Finalize()))
            CDBE("() failed to finalize\n");
        else 
        SetFinished(true);
        return error;
    }
    /**
     **********************************************************************
     * Function: Stop
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual eError Stop() 
    {
        eError error = e_ERROR_NONE;

		if ((error = AcquireQueue()))
		{
			CDBE("() failed to acquire queue\n");
			return error;
		}
        if (GetStopped())
        {
		    if ((error = ReleaseQueue()))
			    CDBE("() failed to release queue\n");
			return error;
        }
        SetStopped();
		if ((error = ReleaseQueue()))
        {
		    CDBE("() failed to release queue\n");
		    return error;
        }
		if ((error = ReleaseThreads()))
            CDBE("() failed to release threads\n");
        return error;
    }
    /**
     **********************************************************************
     * Function: Restart
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual eError Restart() 
    {
        eError error = e_ERROR_NONE;

        if ((error = Stop()))
            return error;

		if ((error = AcquireQueue()))
		{
			CDBE("() failed to acquire queue\n");
			return error;
		}

        if (!GetRestart())
            SetRestart();

		if ((error = ReleaseQueue()))
		    CDBE("() failed to release queue\n");
        return error;
    }

    /**
     **********************************************************************
     * Function: StartThreads
     *
     *   Author: $author$
     *     Date: 2/18/2008
     **********************************************************************
     */
    virtual eError StartThreads
    (UINT threads=0) 
    {
        eError error = e_ERROR_NONE;
        if (0 < threads)
            return e_ERROR_NOT_ALLOWED;
        return error;
    }
    /**
     **********************************************************************
     * Function: FinishThreads
     *
     *   Author: $author$
     *     Date: 2/18/2008
     **********************************************************************
     */
    virtual eError FinishThreads
    (LONG waitMilliSeconds=INFINITE) 
    {
        eError error = AcceptRequests();
        return error;
    }
    /**
     **********************************************************************
     * Function: ReleaseThreads
     *
     *   Author: $author$
     *     Date: 2/18/2008
     **********************************************************************
     */
    virtual eError ReleaseThreads() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: Run
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual eError Run
    (TRequestServer& requestServer) 
    {
        eError error = e_ERROR_NONE;
        TLength count;
        do
        {
		    if ((error = AcquireSemaphore()))
            {
		        CDBE("() failed to acquire semaphore\n");
                break;
            }
            count = Service(requestServer);
        }
        while(0 < count);
        return error;
    }
    /**
     **********************************************************************
     * Function: Service
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual TLength Service
    (TRequestServer& requestServer) 
    {
        TLength count = 0;
        TLength count2;
        eError error;
        TRequest request;

        do
        {
			if ((error = AcquireQueue()))
			{
				CDBE("() failed to acquire queue\n");
                count = -error;
				break;
			}
            else
            if (0 >= (count2 = m_queue.Pop(request)))
            {
                CDBT("() request queue empty\n");
		        if ((error = ReleaseQueue()))
                {
		            CDBE("() failed to release queue\n");
                    count = -error;
                }
                break;
            }
            else
		    if ((error = ReleaseQueue()))
            {
		        CDBE("() failed to release queue\n");
                count = -error;
                break;
            }
            else
            if ((error = requestServer.Service(request, *this)))
                CDBE("() failed to service request\n");
            else count++;
        }
        while(0 < count);
        return count;
    }

    /**
     **********************************************************************
     * Function: AcceptRequests
     *
     *   Author: $author$
     *     Date: 2/28/2008
     **********************************************************************
     */
    virtual eError AcceptRequests
    (LONG waitMilliSeconds=INFINITE) 
    {
        eError error = e_ERROR_NONE;
        TLength count;

        do
        {
            if (0 > (count = AcceptRequest(waitMilliSeconds)))
                error = -count;
        }
        while (0 < count);
        return error;
    }
    /**
     **********************************************************************
     * Function: AcceptRequest
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual TLength AcceptRequest
    (LONG waitMilliSeconds=INFINITE) 
    {
        TLength count = 0;
        TLength count2;
        eError error;
        TRequest request;

        if (0 < (count = Accept(request, waitMilliSeconds)))
        if ((error = Submit(request)))
            count = -error;
        else
        if (0 > (count2 = Service(*this)))
            count = count2;
        return count;
    }
    /**
     **********************************************************************
     * Function: Accept
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual TLength Accept
    (TRequest& request, 
     LONG waitMilliSeconds=INFINITE) 
    {
        TLength count = 1;
        return count;
    }
    /**
     **********************************************************************
     * Function: Submit
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual eError Submit
    (TRequest& request) 
    {
        eError error = e_ERROR_NONE;
        TLength count;

		if ((error = AcquireQueue()))
			CDBE("() failed to acquire queue\n");
        else
        if (GetStopped())
        {
		    if ((error = ReleaseQueue()))
		        CDBE("() failed to release queue\n");
            error = e_ERROR_FAILED;
        }
        else
        if (0 > (count = m_queue.Add(request)))
        {
            CDBE("() failed to queue request\n");
		    if ((error = ReleaseQueue()))
		        CDBE("() failed to release queue\n");
            error = e_ERROR_FAILED;
        }
        else
		if ((error = ReleaseQueue()))
		    CDBE("() failed to release queue\n");
        else
		if ((error = ReleaseSemaphore()))
		    CDBE("() failed to release semaphore\n");
        return error;
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/19/2008
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 2/19/2008
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: AcquireSemaphore
     *
     *   Author: $author$
     *     Date: 2/18/2008
     **********************************************************************
     */
    virtual eError AcquireSemaphore
    (LONG waitMilliSeconds=INFINITE) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: ReleaseSemaphore
     *
     *   Author: $author$
     *     Date: 2/18/2008
     **********************************************************************
     */
    virtual eError ReleaseSemaphore() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: AcquireQueue
     *
     *   Author: $author$
     *     Date: 2/18/2008
     **********************************************************************
     */
    virtual eError AcquireQueue
    (LONG waitMilliSeconds=INFINITE) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: ReleaseQueue
     *
     *   Author: $author$
     *     Date: 2/18/2008
     **********************************************************************
     */
    virtual eError ReleaseQueue() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: Acquire
     *
     *   Author: $author$
     *     Date: 2/18/2008
     **********************************************************************
     */
    virtual eError Acquire
    (LONG waitMilliSeconds=INFINITE) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Release
     *
     *   Author: $author$
     *     Date: 2/18/2008
     **********************************************************************
     */
    virtual eError Release() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: SetRestart
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual int SetRestart
    (bool is=true) 
    {
        int restart = (m_restart = is);
        return restart;
    }
    /**
     **********************************************************************
     * Function: GetRestart
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual bool GetRestart() const 
    {
        return m_restart;
    }

    /**
     **********************************************************************
     * Function: SetStopped
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual int SetStopped
    (bool is=true) 
    {
        int stopped = (m_stopped = is);
        return stopped;
    }
    /**
     **********************************************************************
     * Function: GetStopped
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual bool GetStopped() const 
    {
        return m_stopped;
    }

    /**
     **********************************************************************
     * Function: SetFinished
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual int SetFinished
    (bool is=true) 
    {
        int finished = (m_finished = is);
        return finished;
    }
    /**
     **********************************************************************
     * Function: GetFinished
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual bool GetFinished() const 
    {
        return m_finished;
    }

    /**
     **********************************************************************
     * Function: SetStarted
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual int SetStarted
    (bool is=true) 
    {
        int started = (m_started = is);
        return started;
    }
    /**
     **********************************************************************
     * Function: GetStarted
     *
     *   Author: $author$
     *     Date: 2/17/2008
     **********************************************************************
     */
    virtual bool GetStarted() const 
    {
        return m_started;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cRequestQueueServer
 *
 *  Author: $author$
 *    Date: 2/18/2008
 **********************************************************************
 */
typedef cRequestQueueServerT
<CHAR, LONG, cQueue, cQueuedRequestServer>
cRequestQueueServer;

#endif /* _CREQUESTQUEUESERVER_HXX */
