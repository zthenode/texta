///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2011 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cPThread.hpp
//
// Author: $author$
//   Date: 6/16/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CPTHREAD_HPP) || defined(CPTHREAD_MEMBERS_ONLY)
#if !defined(_CPTHREAD_HPP) && !defined(CPTHREAD_MEMBERS_ONLY)
#define _CPTHREAD_HPP
#endif // !defined(_CPTHREAD_HPP) && !defined(CPTHREAD_MEMBERS_ONLY) 

#if !defined(CPTHREAD_MEMBERS_ONLY)
#include "cPThreadInterface.hpp"
#include "cThreadBase.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cPThreadExtend
//
//  Author: $author$
//    Date: 6/16/2011
///////////////////////////////////////////////////////////////////////
typedef cThreadBase
cPThreadExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cPThread
//
// Author: $author$
//   Date: 6/16/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cPThread
: virtual public cPThreadImplement,
  public cPThreadExtend
{
public:
    typedef cPThreadImplement cImplements;
    typedef cPThreadExtend cExtends;

    pthread_t m_thread;
    pthread_attr_t m_threadAttr;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cPThread
    //
    //       Author: $author$
    //         Date: 6/16/2011
    ///////////////////////////////////////////////////////////////////////
    cPThread
    (bool create=false,
     bool initiallyStopped=false)
    {
        eError error;
        if ((create))
        if ((error = Create(initiallyStopped)))
        {
            c_DB_ERROR("() failed on Create()");
            throw (error);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cPThread
    //
    //      Author: $author$
    //        Date: 6/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cPThread()
    {
        eError error;
        if ((error = Destroyed()))
        {
            c_DB_ERROR("() failed on Destroyed()");
            throw (error);
        }
    }
#else // !defined(CPTHREAD_MEMBERS_ONLY) 
#endif // !defined(CPTHREAD_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Create
    //
    //    Author: $author$
    //      Date: 6/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Create
    (bool onlyDestroyed=false)
#if defined(CPTHREAD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREAD_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREAD_MEMBER_FUNCS_IMPLEMENT)
        int err;
        
		if ((error = Destroyed(onlyDestroyed)))
		    return error;

	    if (!(err = pthread_attr_init(&m_threadAttr)))
	    {
            if (!(err = pthread_create
                (&m_thread, &m_threadAttr, ThreadRoutine, 
                 (void*)((cPThreadInterface*)(this)))))
		    {
			    SetIsCreated();
			    return error = e_ERROR_NONE;
		    }
            else
            c_DB_ERROR("() failed on pthread_create()");

		    pthread_attr_destroy(&m_threadAttr);
	    }
        else
        c_DB_ERROR("() failed on pthread_xattr_init()");
#else // !defined(CPTHREAD_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREAD_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREAD_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Join
    //
    //    Author: $author$
    //      Date: 6/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Join
    (void*& result, mseconds_t waitMilliseconds)
#if defined(CPTHREAD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREAD_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREAD_MEMBER_FUNCS_IMPLEMENT)
        if ((IsCreated()))
        if (0 < waitMilliseconds)
        {
            struct timespec untilTime;
            clock_gettime(CLOCK_REALTIME, &untilTime);
            untilTime.tv_sec +=  waitMilliseconds/1000;
            untilTime.tv_nsec +=  (waitMilliseconds%1000)*1000;
            error = TimedJoin(result, untilTime);
        }
        else
        if (0 > waitMilliseconds)
            error = Join(result);
        else
        error = TryJoin(result);
#else // !defined(CPTHREAD_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREAD_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREAD_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Join
    //
    //    Author: $author$
    //      Date: 6/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Join(void*& result)
#if defined(CPTHREAD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREAD_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREAD_MEMBER_FUNCS_IMPLEMENT)
        int err;

        if ((GetIsStarted()))
        {
            if (!(err = pthread_join(m_thread, &result)))
                error = e_ERROR_NONE;
            else
            c_DB_ERROR("() failed on pthread_join()");

            SetIsStarted(false);
        }
#else // !defined(CPTHREAD_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREAD_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREAD_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: TryJoin
    //
    //    Author: $author$
    //      Date: 6/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError TryJoin(void*& result)
#if defined(CPTHREAD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREAD_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREAD_MEMBER_FUNCS_IMPLEMENT)
        int err = EINVAL;

        if ((GetIsStarted()))
        {
            if (!(err = pthread_tryjoin_np(m_thread, &result)))
                error = e_ERROR_NONE;
            else
            if (EBUSY != (err))
                c_DB_ERROR("() failed on pthread_tryjoin_np()");
            else
            c_DB_TRACE("() busy on pthread_tryjoin_np()");

            if (ETIMEDOUT != (err))
                SetIsStarted(false);
        }
#else // !defined(CPTHREAD_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREAD_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREAD_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: TimedJoin
    //
    //    Author: $author$
    //      Date: 6/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError TimedJoin
    (void*& result, const struct timespec& untilTime)
#if defined(CPTHREAD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREAD_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREAD_MEMBER_FUNCS_IMPLEMENT)
        int err = EINVAL;

        if ((GetIsStarted()))
        {
            if (!(err = pthread_timedjoin_np
                (m_thread, &result, &untilTime)))
                error = e_ERROR_NONE;
            else
            if (ETIMEDOUT != (err))
                c_DB_ERROR("() failed on pthread_timedjoin_np()");
            else
            c_DB_TRACE("() timed out on pthread_timedjoin_np()");

            if (ETIMEDOUT != (err))
                SetIsStarted(false);
        }
#else // !defined(CPTHREAD_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREAD_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREAD_MEMBER_FUNCS_INTERFACE) 

#if defined(CPTHREAD_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: ThreadRoutine
    //
    //    Author: $author$
    //      Date: 6/16/2011
    ///////////////////////////////////////////////////////////////////////
    static void* ThreadRoutine(void* arg);
#else // defined(CPTHREAD_MEMBER_FUNCS_INTERFACE) 
#endif // defined(CPTHREAD_MEMBER_FUNCS_INTERFACE) 

#if !defined(CPTHREAD_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Create
    //
    //    Author: $author$
    //      Date: 6/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Create
    (bool initiallyStopped,
     bool onlyDestroyed)
    {
        eError error = e_ERROR_NOT_SUPPORTED;
        if (!(initiallyStopped))
            error = Create(onlyDestroyed);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Destroy
    //
    //    Author: $author$
    //      Date: 6/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Destroy
    (bool onlyCreated=false)
    {
        eError error = e_ERROR_FAILED;
        eError error1 = e_ERROR_NONE;
        int err;
        void* result;

        if (!(GetIsCreated()))
        if ((onlyCreated))
            return error = e_ERROR_FAILED;
        else
        return error = e_ERROR_NONE;

        if ((GetIsStarted()))
            error1 = Join(result);

        if (!(err = pthread_attr_destroy(&m_threadAttr)))
            error = error1;
        else
        c_DB_ERROR("() failed on pthread_destroy_attr()");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: Finish
    //
    //    Author: $author$
    //      Date: 6/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finish
    (mseconds_t waitMilliseconds)
    {
        void* result = 0;
        eError error = Join(result,waitMilliseconds);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finish
    //
    //    Author: $author$
    //      Date: 6/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finish()
    {
        void* result = 0;
        eError error = Join(result);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: TryFinish
    //
    //    Author: $author$
    //      Date: 6/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError TryFinish()
    {
        void* result = 0;
        eError error = TryJoin(result);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: Wait
    //
    //    Author: $author$
    //      Date: 6/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Wait
    (mseconds_t waitMilliseconds)
    {
        eError error = e_ERROR_FAILED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Wait
    //
    //    Author: $author$
    //      Date: 6/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Wait()
    {
        eError error = e_ERROR_FAILED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: TryWait
    //
    //    Author: $author$
    //      Date: 6/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError TryWait()
    {
        eError error = e_ERROR_FAILED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Continue
    //
    //    Author: $author$
    //      Date: 6/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Continue()
    {
        eError error = e_ERROR_FAILED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetIsCreated
    //
    //    Author: $author$
    //      Date: 6/16/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsCreated(bool isTrue=true)
    {
        m_isStarted = (m_isCreated = isTrue);
        return isTrue;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CPTHREAD_MEMBERS_ONLY) 
#endif // !defined(CPTHREAD_MEMBERS_ONLY) 

#endif // !defined(_CPTHREAD_HPP) || defined(CPTHREAD_MEMBERS_ONLY) 
