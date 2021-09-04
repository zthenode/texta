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
//   File: cWinSemaphore.hpp
//
// Author: $author$
//   Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWINSEMAPHORE_HPP) || defined(CWINSEMAPHORE_MEMBERS_ONLY)
#if !defined(_CWINSEMAPHORE_HPP) && !defined(CWINSEMAPHORE_MEMBERS_ONLY)
#define _CWINSEMAPHORE_HPP
#endif // !defined(_CWINSEMAPHORE_HPP) && !defined(CWINSEMAPHORE_MEMBERS_ONLY) 

#if !defined(CWINSEMAPHORE_MEMBERS_ONLY)
#include "cWinSemaphoreInterface.hpp"
#include "cWinSecurityAttributes.hpp"
#include "cSemaphoreBase.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWinSemaphoreExtend
//
//  Author: $author$
//    Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
typedef cSemaphoreBase
cWinSemaphoreExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cWinSemaphore
//
// Author: $author$
//   Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cWinSemaphore
: virtual public cWinSemaphoreImplement,
  public cWinSemaphoreExtend
{
public:
    typedef cWinSemaphoreImplement cImplements;
    typedef cWinSemaphoreExtend cExtends;

    HANDLE m_attached;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWinSemaphore
    //
    //       Author: $author$
    //         Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    cWinSemaphore
    (HANDLE attached, bool isCreated=false)
    : m_attached(attached)
    {
        m_isCreated = isCreated;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWinSemaphore
    //
    //       Author: $author$
    //         Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    cWinSemaphore
    (bool create=false,
     unsigned int initialCount=0, int maximumCount=-1)
    : m_attached(0)
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
    //  Destructor: ~cWinSemaphore
    //
    //      Author: $author$
    //        Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cWinSemaphore()
    {
        eError error;
        if ((error = Destroyed()))
        {
            c_DB_ERROR("() failed on Destroyed()");
            throw(error);
        }
    }
#else // !defined(CWINSEMAPHORE_MEMBERS_ONLY) 
#endif // !defined(CWINSEMAPHORE_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Create
    //
    //    Author: $author$
    //      Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Create
    (unsigned int initialCount=0, int maximumCount=-1, 
     bool onlyDestroyed=false)
#if defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT)
        LONG lInitialCount = (LONG)(initialCount);
        LONG lMaximumCount =(LONG)((0 > maximumCount)?(((ULONG)(-1))>>1):(maximumCount));
        LPCTSTR lpName = NULL;
        SECURITY_ATTRIBUTES attr;
        cWinSecurityAttributes sa(attr);

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        if ((m_isCreated = (0 != (m_attached = CreateSemaphore
            (&attr, lInitialCount, lMaximumCount, lpName)))))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on CreateSemaphore()");
#else // !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Destroy
    //
    //    Author: $author$
    //      Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Destroy
    (bool onlyCreated=false)
#if defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT)
        HANDLE detached;

        if (!(detached = Detach()))
        if ((onlyCreated))
            return error = e_ERROR_FAILED;
        else
        return error = e_ERROR_NONE;

        if ((CloseHandle(detached)))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on CloseHandle()");
#else // !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Wait
    //
    //    Author: $author$
    //      Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Wait
    (mseconds_t waitMilliseconds)
#if defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT)
        LONG lWaitMilliSeconds = (LONG)((0 > waitMilliseconds)?(INFINITE):(waitMilliseconds));
        DWORD result = 0;
        HANDLE attached;

        if ((attached = m_attached))
        if (WAIT_OBJECT_0 == (result = WaitForSingleObject
            (attached, lWaitMilliSeconds)))
            error = e_ERROR_NONE;
        else
        if (WAIT_TIMEOUT == result)
            error = e_ERROR_WAIT_TIMEOUT;
        else
        c_DB_ERROR("() failed on WaitForSingleObject()");
#else // !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Release
    //
    //    Author: $author$
    //      Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Release
    (unsigned int count)
#if defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT)
        LONG lReleaseCount = (LONG)(count);
        LONG lPreviousCount = 0;
        HANDLE attached;

        if ((attached = m_attached))
        if ((ReleaseSemaphore(attached, lReleaseCount, &lPreviousCount)))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on ReleaseSemaphore()");
#else // !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: AttachCreated
    //
    //    Author: $author$
    //      Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual HANDLE AttachCreated
    (HANDLE detached, bool isCreated=true)
#if defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE) 
    {
        HANDLE attached = 0;
#if !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT)
        if ((attached = (m_attached = detached)))
            SetIsCreated(isCreated);
        else
        SetIsCreated(false);
#else // !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
        return attached;
    }
#endif // defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Attach
    //
    //    Author: $author$
    //      Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual HANDLE Attach
    (HANDLE detached)
#if defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE) 
    {
        HANDLE attached = 0;
#if !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT)
        attached = (m_attached = detached);
        SetIsCreated(false);
#else // !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
        return attached;
    }
#endif // defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Detach
    //
    //    Author: $author$
    //      Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual HANDLE Detach()
#if defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE) 
    {
        HANDLE detached = 0;
#if !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT)
        SetIsCreated(false);
        detached = (m_attached);
        m_attached = 0;
#else // !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT) 
        return detached;
    }
#endif // defined(CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE) 

#if !defined(CWINSEMAPHORE_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Acquire
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Acquire
    (mseconds_t waitMilliseconds)
    {
        eError error = Wait(waitMilliseconds);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Acquire
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Acquire()
    {
        eError error = Wait(-1);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: TryAcquire
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError TryAcquire()
    {
        eError error = Wait(0);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Release
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Release()
    {
        eError error = Release(1);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: Wait
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Wait()
    {
        eError error = Wait(-1);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: TryWait
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError TryWait()
    {
        eError error = Wait(0);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Continue
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Continue()
    {
        eError error = Release(1);
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWINSEMAPHORE_MEMBERS_ONLY) 
#endif // !defined(CWINSEMAPHORE_MEMBERS_ONLY) 

#endif // !defined(_CWINSEMAPHORE_HPP) || defined(CWINSEMAPHORE_MEMBERS_ONLY) 
        

