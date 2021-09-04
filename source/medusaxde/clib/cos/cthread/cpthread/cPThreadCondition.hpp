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
//   File: cPThreadCondition.hpp
//
// Author: $author$
//   Date: 5/30/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CPTHREADCONDITION_HPP) || defined(CPTHREADCONDITION_MEMBERS_ONLY)
#if !defined(_CPTHREADCONDITION_HPP) && !defined(CPTHREADCONDITION_MEMBERS_ONLY)
#define _CPTHREADCONDITION_HPP
#endif // !defined(_CPTHREADCONDITION_HPP) && !defined(CPTHREADCONDITION_MEMBERS_ONLY) 

#if !defined(CPTHREADCONDITION_MEMBERS_ONLY)
#include "cPThreadConditionInterface.hpp"
#include "cConditionBase.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cPThreadConditionExtend
//
//  Author: $author$
//    Date: 5/30/2011
///////////////////////////////////////////////////////////////////////
typedef cConditionBase
cPThreadConditionExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cPThreadCondition
//
// Author: $author$
//   Date: 5/30/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cPThreadCondition
: virtual public cPThreadConditionImplement,
  public cPThreadConditionExtend
{
public:
    typedef cPThreadConditionImplement cImplements;
    typedef cPThreadConditionExtend cExtends;

    pthread_cond_t m_cond;
    pthread_condattr_t m_condAttr;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cPThreadCondition
    //
    //       Author: $author$
    //         Date: 5/30/2011
    ///////////////////////////////////////////////////////////////////////
    cPThreadCondition(bool create=false)
    {
        eError error;
        if ((create))
        if ((error = Create(true)))
        {
            c_DB_ERROR("() failed on Create()");
            throw (error);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cPThreadCondition
    //
    //      Author: $author$
    //        Date: 5/30/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cPThreadCondition()
    {
        eError error;
        if ((error = Destroyed()))
        {
            c_DB_ERROR("() failed on Destroyed()");
            throw (error);
        }
    }
#else // !defined(CPTHREADCONDITION_MEMBERS_ONLY) 
#endif // !defined(CPTHREADCONDITION_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Init
    //
    //    Author: $author$
    //      Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Init
    (int processShared=PTHREAD_PROCESS_PRIVATE,
     bool onlyDestroyed=false)
#if defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT)
        int err;
        
		if ((error = Destroyed(onlyDestroyed)))
		    return error;

	    if (!(err = pthread_condattr_init(&m_condAttr)))
	    {
            pthread_condattr_setpshared(&m_condAttr, processShared);

            if (!(err = pthread_cond_init(&m_cond, &m_condAttr)))
		    {
			    SetIsCreated();
			    return error = e_ERROR_NONE;
		    }
            else
            c_DB_ERROR("() failed on pthread_cond_init()");

		    pthread_condattr_destroy(&m_condAttr);
	    }
        else
        c_DB_ERROR("() failed on pthread_condattr_init()");
#else // !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Destroy
    //
    //    Author: $author$
    //      Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Destroy
    (bool onlyCreated=false)
#if defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT)
        int err;
        
	    if (!(IsCreated()))
		if (onlyCreated)
			return error = e_ERROR_FAILED;
		else return error;
		
		SetIsCreated(false);
		
        if ((err = pthread_cond_destroy(&m_cond))) 
        {
            c_DB_ERROR("() failed on pthread_cond_destroy()");
		    error = e_ERROR_FAILED;
        }
        if ((err = pthread_condattr_destroy(&m_condAttr))) 
        {
            c_DB_ERROR("() failed on pthread_condattr_destroy()");
		    error = e_ERROR_FAILED;
        }
#else // !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Broadcast
    //
    //    Author: $author$
    //      Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Broadcast()
#if defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT)
        bool isCreated;
        int err;

        if ((isCreated = GetIsCreated()))
        if (!(err = pthread_cond_broadcast(&m_cond)))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on pthread_cond_broadcast()");
#else // !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Signal
    //
    //    Author: $author$
    //      Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Signal()
#if defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT)
        bool isCreated;
        int err;

        if ((isCreated = GetIsCreated()))
        if (!(err = pthread_cond_signal(&m_cond)))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on pthread_cond_signal()");
#else // !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Wait
    //
    //    Author: $author$
    //      Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Wait(pthread_mutex_t& mutex)
#if defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT)
        bool isCreated;
        int err;

        if ((isCreated = GetIsCreated()))
        if (!(err = pthread_cond_wait(&m_cond, &mutex)))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on pthread_cond_wait()");
#else // !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: TryWait
    //
    //    Author: $author$
    //      Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError TryWait(pthread_mutex_t& mutex)
#if defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: TimedWait
    //
    //    Author: $author$
    //      Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError TimedWait
    (pthread_mutex_t& mutex, const struct timespec& untilTime)
#if defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT)
        bool isCreated;
        int err;

        if ((isCreated = GetIsCreated()))
        if (!(err = pthread_cond_timedwait(&m_cond, &mutex, &untilTime)))
            error = e_ERROR_NONE;
        else
        if (ETIMEDOUT != err)
            c_DB_ERROR("() failed on pthread_cond_timedwait()");
        else
        c_DB_TRACE("() timed out on pthread_cond_timedwait()");
#else // !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE) 

#if !defined(CPTHREADCONDITION_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Create
    //
    //    Author: $author$
    //      Date: 5/31/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Create
    (bool onlyDestroyed=false)
    {
        eError error = e_ERROR_FAILED;
        error = Init(PTHREAD_PROCESS_PRIVATE, onlyDestroyed);
        return error;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CPTHREADCONDITION_MEMBERS_ONLY) 
#endif // !defined(CPTHREADCONDITION_MEMBERS_ONLY) 

#endif // !defined(_CPTHREADCONDITION_HPP) || defined(CPTHREADCONDITION_MEMBERS_ONLY) 
