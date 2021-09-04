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
//   File: cPThreadMutex.hpp
//
// Author: $author$
//   Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CPTHREADMUTEX_HPP) || defined(CPTHREADMUTEX_MEMBERS_ONLY)
#if !defined(_CPTHREADMUTEX_HPP) && !defined(CPTHREADMUTEX_MEMBERS_ONLY)
#define _CPTHREADMUTEX_HPP
#endif // !defined(_CPTHREADMUTEX_HPP) && !defined(CPTHREADMUTEX_MEMBERS_ONLY) 

#if !defined(CPTHREADMUTEX_MEMBERS_ONLY)
#include "cPThreadMutexInterface.hpp"
#include "cMutexBase.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cPThreadMutexExtend
//
//  Author: $author$
//    Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
typedef cMutexBase
cPThreadMutexExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cPThreadMutex
//
// Author: $author$
//   Date: 3/20/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cPThreadMutex
: virtual public cPThreadMutexImplement,
  public cPThreadMutexExtend
{
public:
    typedef cPThreadMutexImplement cImplements;
    typedef cPThreadMutexExtend cExtends;
    
    pthread_mutex_t m_mutex;
    pthread_mutexattr_t m_mutexAttr;
    
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cPThreadMutex
    //
    //       Author: $author$
    //         Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    cPThreadMutex
    (bool create=false,
     bool initiallyLocked=false)
    {
        eError error;
        if ((create))
        if ((error = Create(initiallyLocked)))
        {
            c_DB_ERROR("() failed on Create()");
            throw (error);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cPThreadMutex
    //
    //      Author: $author$
    //        Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cPThreadMutex()
    {
        eError error;
        if ((error = Destroyed()))
        {
            c_DB_ERROR("() failed on Destroyed()");
            throw (error);
        }
    }
#else // !defined(CPTHREADMUTEX_MEMBERS_ONLY) 
#endif // !defined(CPTHREADMUTEX_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Init
    //
    //    Author: $author$
    //      Date: 6/12/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Init
    (int mutexType=PTHREAD_MUTEX_RECURSIVE,
     int processShared=PTHREAD_PROCESS_PRIVATE,
     bool onlyDestroyed=false)
#if defined(CPTHREADMUTEX_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREADMUTEX_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREADMUTEX_MEMBER_FUNCS_IMPLEMENT)
        int err;
        
		if ((error = Destroyed(onlyDestroyed)))
		    return error;

	    if (!(err = pthread_mutexattr_init(&m_mutexAttr)))
	    {
            pthread_mutexattr_settype(&m_mutexAttr, mutexType);
            pthread_mutexattr_setpshared(&m_mutexAttr, processShared);

            if (!(err = pthread_mutex_init(&m_mutex, &m_mutexAttr)))
		    {
			    SetIsCreated();
			    return error = e_ERROR_NONE;
		    }
            else
            c_DB_ERROR("() failed on pthread_mutex_init()");

		    pthread_mutexattr_destroy(&m_mutexAttr);
	    }
        else
        c_DB_ERROR("() failed on pthread_mutexattr_init()");
#else // !defined(CPTHREADMUTEX_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREADMUTEX_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREADMUTEX_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Destroy
    //
    //    Author: $author$
    //      Date: 6/12/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Destroy
    (bool onlyCreated=false)
#if defined(CPTHREADMUTEX_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREADMUTEX_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREADMUTEX_MEMBER_FUNCS_IMPLEMENT)
        int err;
        
	    if (!(IsCreated()))
		if (onlyCreated)
			return error = e_ERROR_FAILED;
		else return error = e_ERROR_NONE;
		
		SetIsCreated(false);
		
        if ((err = pthread_mutex_destroy(&m_mutex))) 
        {
            c_DB_ERROR("() failed on pthread_mutex_destroy()");
		    error = e_ERROR_FAILED;
        }
        if ((err = pthread_mutexattr_destroy(&m_mutexAttr))) 
        {
            c_DB_ERROR("() failed on pthread_mutexattr_destroy()");
		    error = e_ERROR_FAILED;
        }
#else // !defined(CPTHREADMUTEX_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREADMUTEX_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREADMUTEX_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Lock
    //
    //    Author: $author$
    //      Date: 6/12/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Lock()
#if defined(CPTHREADMUTEX_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREADMUTEX_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREADMUTEX_MEMBER_FUNCS_IMPLEMENT)
        int err;

        if ((IsCreated()))
        if (!(err = pthread_mutex_lock(&m_mutex)))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on pthread_mutex_lock()");
#else // !defined(CPTHREADMUTEX_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREADMUTEX_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREADMUTEX_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: TryLock
    //
    //    Author: $author$
    //      Date: 6/12/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError TryLock()
#if defined(CPTHREADMUTEX_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREADMUTEX_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREADMUTEX_MEMBER_FUNCS_IMPLEMENT)
        int err;

        if ((IsCreated()))
        if (!(err = pthread_mutex_trylock(&m_mutex)))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on pthread_mutex_trylock()");
#else // !defined(CPTHREADMUTEX_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREADMUTEX_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREADMUTEX_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: TimedLock
    //
    //    Author: $author$
    //      Date: 6/12/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError TimedLock
    (const struct timespec& untilTime)
#if defined(CPTHREADMUTEX_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREADMUTEX_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREADMUTEX_MEMBER_FUNCS_IMPLEMENT)
        bool isCreated;
        int err;

        if ((isCreated = GetIsCreated()))
        if (!(err = pthread_mutex_timedlock(&m_mutex, &untilTime)))
            error = e_ERROR_NONE;
        else
        if (ETIMEDOUT != err)
            c_DB_ERROR("() failed on pthread_mutex_timedlock()");
        else
        c_DB_TRACE("() timed out on pthread_mutex_timedlock()");
#else // !defined(CPTHREADMUTEX_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREADMUTEX_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREADMUTEX_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Unlock
    //
    //    Author: $author$
    //      Date: 6/12/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Unlock()
#if defined(CPTHREADMUTEX_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREADMUTEX_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREADMUTEX_MEMBER_FUNCS_IMPLEMENT)
        int err;
        
        if ((IsCreated()))
        if (!(err = pthread_mutex_unlock(&m_mutex)))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on pthread_mutex_unlock()");
#else // !defined(CPTHREADMUTEX_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREADMUTEX_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREADMUTEX_MEMBER_FUNCS_INTERFACE) 

#if !defined(CPTHREADMUTEX_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Create
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Create
    (bool initallyLocked=false,
     bool onlyDestroyed=false)
    {
        eError error = e_ERROR_FAILED;
        bool isCreated = false;
        if ((isCreated = !(error = Init())))
        if ((initallyLocked))
        if ((error = TryLock()))
            Destroy(isCreated);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: Lock
    //
    //    Author: $author$
    //      Date: 3/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Lock(mseconds_t waitMilliseconds)
    {
        eError error = e_ERROR_FAILED;

        if ((IsCreated()))
        if (0 < waitMilliseconds)
        {
            struct timespec untilTime;
            clock_gettime(CLOCK_REALTIME, &untilTime);
            untilTime.tv_sec +=  waitMilliseconds/1000;
            untilTime.tv_nsec +=  (waitMilliseconds%1000)*1000;
            error = TimedLock(untilTime);
        }
        else
        if (0 > waitMilliseconds)
            error = Lock();
        else
        error = TryLock();

        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CPTHREADMUTEX_MEMBERS_ONLY) 
#endif // !defined(CPTHREADMUTEX_MEMBERS_ONLY) 

#endif // !defined(_CPTHREADMUTEX_HPP) || defined(CPTHREADMUTEX_MEMBERS_ONLY) 
