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
//   File: cPThreadSemaphore.hpp
//
// Author: $author$
//   Date: 5/28/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CPTHREADSEMAPHORE_HPP) || defined(CPTHREADSEMAPHORE_MEMBERS_ONLY)
#if !defined(_CPTHREADSEMAPHORE_HPP) && !defined(CPTHREADSEMAPHORE_MEMBERS_ONLY)
#define _CPTHREADSEMAPHORE_HPP
#endif // !defined(_CPTHREADSEMAPHORE_HPP) && !defined(CPTHREADSEMAPHORE_MEMBERS_ONLY) 

#if !defined(CPTHREADSEMAPHORE_MEMBERS_ONLY)
#include "cPThreadSemaphoreInterface.hpp"
#include "cSemaphoreBase.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cPThreadSemaphoreExtend
//
//  Author: $author$
//    Date: 5/28/2011
///////////////////////////////////////////////////////////////////////
typedef cSemaphoreBase
cPThreadSemaphoreExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cPThreadSemaphore
//
// Author: $author$
//   Date: 5/28/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cPThreadSemaphore
: virtual public cPThreadSemaphoreImplement,
  public cPThreadSemaphoreExtend
{
public:
    typedef cPThreadSemaphoreImplement cImplements;
    typedef cPThreadSemaphoreExtend cExtends;

    sem_t m_sem;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cPThreadSemaphore
    //
    //       Author: $author$
    //         Date: 5/28/2011
    ///////////////////////////////////////////////////////////////////////
    cPThreadSemaphore
    (bool create=false,
     unsigned int initialCount=0, int maximumCount=-1)
    {
        eError error;
        if ((create))
        if ((error = Create(initialCount, maximumCount)))
        {
            c_DB_ERROR("() failed on Create()");
            throw(error);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cPThreadSemaphore
    //
    //      Author: $author$
    //        Date: 5/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cPThreadSemaphore()
    {
        eError error;
        if ((error = Destroyed()))
        {
            c_DB_ERROR("() failed on Destroyed()");
            throw(error);
        }
    }
#else // !defined(CPTHREADSEMAPHORE_MEMBERS_ONLY) 
#endif // !defined(CPTHREADSEMAPHORE_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Init
    //
    //    Author: $author$
    //      Date: 5/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Init
    (int processShared=0,
     unsigned int initialCount=0,
     bool onlyDestroyed=false)
#if defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_IMPLEMENT)
        bool isCreated;
        int err;

        if ((isCreated = GetIsCreated()))
        if ((onlyDestroyed))
            return error;
        else 
        if ((error = Destroyed(isCreated)))
            return error;

        if (!(err = sem_init(&m_sem, processShared, initialCount)))
        {
            SetIsCreated();
            error = e_ERROR_NONE;
        }
        else
        c_DB_ERROR("() failed on sem_init()");
#else // !defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Destroy
    //
    //    Author: $author$
    //      Date: 5/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Destroy
    (bool onlyCreated=false)
#if defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_IMPLEMENT)
        bool isCreated;
        int err;

        if ((isCreated = GetIsCreated()))
        {
            SetIsCreated(false);
            if ((err = sem_destroy(&m_sem)))
            {
                c_DB_ERROR("() failed on sem_destroy()");
                error = e_ERROR_FAILED;
            }
        }
        else
        if ((onlyCreated))
            error = e_ERROR_FAILED;
        else
        error = e_ERROR_NONE;
#else // !defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Post
    //
    //    Author: $author$
    //      Date: 5/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Post()
#if defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_IMPLEMENT)
        bool isCreated;
        int err;

        if ((isCreated = GetIsCreated()))
        if (!(err = sem_post(&m_sem)))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on sem_post()");
#else // !defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Wait
    //
    //    Author: $author$
    //      Date: 5/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Wait()
#if defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_IMPLEMENT)
        bool isCreated;
        int err;

        if ((isCreated = GetIsCreated()))
        if (!(err = sem_wait(&m_sem)))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on sem_wait()");
#else // !defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: TryWait
    //
    //    Author: $author$
    //      Date: 5/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError TryWait()
#if defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_IMPLEMENT)
        bool isCreated;
        int err;

        if ((isCreated = GetIsCreated()))
        if (!(err = sem_trywait(&m_sem)))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on sem_trywait()");
#else // !defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: TimedWait
    //
    //    Author: $author$
    //      Date: 5/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError TimedWait
    (const struct timespec& untilTime)
#if defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_IMPLEMENT)
        bool isCreated;
        int err;

        if ((isCreated = GetIsCreated()))
        if (!(err = sem_timedwait(&m_sem, &untilTime)))
            error = e_ERROR_NONE;
        else
        if (ETIMEDOUT != err)
            c_DB_ERROR("() failed on sem_timedwait()");
        else
        c_DB_TRACE("() timed out on sem_timedwait()");
#else // !defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CPTHREADSEMAPHORE_MEMBER_FUNCS_INTERFACE) 

#if !defined(CPTHREADSEMAPHORE_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Create
    //
    //    Author: $author$
    //      Date: 5/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Create
    (unsigned int initialCount=0,
     int maximumCount=-1,
     bool onlyDestroyed=false)
    {
        int processShared = 0;
        eError error = e_ERROR_FAILED;
        bool isCreated;
        int err;

        if ((isCreated = GetIsCreated()))
        if ((onlyDestroyed))
            return error;
        else 
        if ((error = Destroyed(isCreated)))
            return error;

        if (!(err = sem_init(&m_sem, processShared, initialCount)))
        {
            SetIsCreated();
            error = e_ERROR_NONE;
        }
        else
        c_DB_ERROR("() failed on sem_init()");

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: Acquire
    //
    //    Author: $author$
    //      Date: 5/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Acquire
    (mseconds_t waitMilliseconds)
    {
        eError error = e_ERROR_FAILED;
        bool isCreated;
        int err;

        if ((isCreated = GetIsCreated()))
        if (0 < (waitMilliseconds))
        {
            struct timespec untilTime;

            clock_gettime(CLOCK_REALTIME, &untilTime);
            untilTime.tv_sec +=  (waitMilliseconds/1000);
            untilTime.tv_nsec +=  ((waitMilliseconds%1000)*1000);

            if (!(err = sem_timedwait(&m_sem, &untilTime)))
                error = e_ERROR_NONE;
            else
            if (ETIMEDOUT != err)
                c_DB_ERROR("() failed on sem_timedwait()");
            else
            c_DB_TRACE("() timed out on sem_timedwait()");
        }
        else
        if (0 > (waitMilliseconds))
        {
            if (!(err = sem_wait(&m_sem)))
                error = e_ERROR_NONE;
            else
            c_DB_ERROR("() failed on sem_wait()");
        }
        else
        {
            if (!(err = sem_trywait(&m_sem)))
                error = e_ERROR_NONE;
            else
            c_DB_ERROR("() failed on sem_trywait()");
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Acquire
    //
    //    Author: $author$
    //      Date: 5/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Acquire()
    {
        eError error = e_ERROR_FAILED;
        bool isCreated;
        int err;

        if ((isCreated = GetIsCreated()))
        if (!(err = sem_wait(&m_sem)))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on sem_wait()");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: TryAcquire
    //
    //    Author: $author$
    //      Date: 5/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError TryAcquire()
    {
        eError error = e_ERROR_FAILED;
        bool isCreated;
        int err;

        if ((isCreated = GetIsCreated()))
        if (!(err = sem_trywait(&m_sem)))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on sem_trywait()");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Release
    //
    //    Author: $author$
    //      Date: 5/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Release
    (unsigned int count=1)
    {
        eError error = e_ERROR_FAILED;
        bool isCreated;
        int err;

        if ((isCreated = GetIsCreated()))
        if (!(err = sem_post(&m_sem)))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on sem_post()");
        return error;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CPTHREADSEMAPHORE_MEMBERS_ONLY) 
#endif // !defined(CPTHREADSEMAPHORE_MEMBERS_ONLY) 

#endif // !defined(_CPTHREADSEMAPHORE_HPP) || defined(CPTHREADSEMAPHORE_MEMBERS_ONLY) 
        

