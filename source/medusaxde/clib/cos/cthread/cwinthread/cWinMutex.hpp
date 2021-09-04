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
//   File: cWinMutex.hpp
//
// Author: $author$
//   Date: 6/3/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWINMUTEX_HPP) || defined(CWINMUTEX_MEMBERS_ONLY)
#if !defined(_CWINMUTEX_HPP) && !defined(CWINMUTEX_MEMBERS_ONLY)
#define _CWINMUTEX_HPP
#endif // !defined(_CWINMUTEX_HPP) && !defined(CWINMUTEX_MEMBERS_ONLY) 

#if !defined(CWINMUTEX_MEMBERS_ONLY)
#include "cWinMutexInterface.hpp"
#include "cWinSecurityAttributes.hpp"
#include "cMutexBase.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWinMutexExtend
//
//  Author: $author$
//    Date: 6/3/2011
///////////////////////////////////////////////////////////////////////
typedef cMutexBase
cWinMutexExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cWinMutex
//
// Author: $author$
//   Date: 6/3/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cWinMutex
: virtual public cWinMutexImplement,
  public cWinMutexExtend
{
public:
    typedef cWinMutexImplement cImplements;
    typedef cWinMutexExtend cExtends;

    HANDLE m_attached;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWinMutex
    //
    //       Author: $author$
    //         Date: 6/3/2011
    ///////////////////////////////////////////////////////////////////////
    cWinMutex
    (bool create=false, 
     bool initiallyLocked=false)
    : m_attached(0)
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
    //  Destructor: ~cWinMutex
    //
    //      Author: $author$
    //        Date: 6/3/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cWinMutex()
    {
        eError error;
        if ((error = Destroyed()))
        {
            c_DB_ERROR("() failed on Destroyed()");
            throw (error);
        }
    }
#else // !defined(CWINMUTEX_MEMBERS_ONLY) 
#endif // !defined(CWINMUTEX_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Create
    //
    //    Author: $author$
    //      Date: 6/12/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Create
    (bool initiallyLocked=false, 
     bool onlyDestroyed=false)
#if defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT)
        BOOL bInitialOwner = (initiallyLocked)?TRUE:FALSE;
        LPCTSTR lpName = NULL;
        SECURITY_ATTRIBUTES attr;
        cWinSecurityAttributes sa(attr);

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        if ((m_isCreated = (0 != (m_attached = CreateMutex
            (&attr, bInitialOwner, lpName)))))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on CreateMutex()");
#else // !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Destroy
    //
    //    Author: $author$
    //      Date: 6/12/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Destroy
    (bool onlyCreated=false)
#if defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT)
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
#else // !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Wait
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Wait
    (mseconds_t waitMilliseconds)
#if defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT)
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
#else // !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Release
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Release()
#if defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT)
        HANDLE attached;

        if ((attached = m_attached))
        if ((ReleaseMutex(attached)))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on ReleaseMutex()");
#else // !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: AttachCreated
    //
    //    Author: $author$
    //      Date: 6/12/2011
    ///////////////////////////////////////////////////////////////////////
    virtual HANDLE AttachCreated
    (HANDLE detached, bool isCreated=true)
#if defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE) 
    {
        HANDLE attached = 0;
#if !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT)
        if ((attached = (m_attached = detached)))
            SetIsCreated(isCreated);
        else
        SetIsCreated(false);
#else // !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT) 
        return attached;
    }
#endif // defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Attach
    //
    //    Author: $author$
    //      Date: 6/12/2011
    ///////////////////////////////////////////////////////////////////////
    virtual HANDLE Attach
    (HANDLE detached)
#if defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE) 
    {
        HANDLE attached = 0;
#if !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT)
        attached = (m_attached = detached);
        SetIsCreated(false);
#else // !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT) 
        return attached;
    }
#endif // defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Detach
    //
    //    Author: $author$
    //      Date: 6/12/2011
    ///////////////////////////////////////////////////////////////////////
    virtual HANDLE Detach()
#if defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE) 
    {
        HANDLE detached = 0;
#if !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT)
        SetIsCreated(false);
        detached = (m_attached);
        m_attached = 0;
#else // !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINMUTEX_MEMBER_FUNCS_IMPLEMENT) 
        return detached;
    }
#endif // defined(CWINMUTEX_MEMBER_FUNCS_INTERFACE) 

#if !defined(CWINMUTEX_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Lock
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Lock
    (mseconds_t waitMilliseconds)
    {
        eError error = Wait(waitMilliseconds);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Lock
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Lock()
    {
        eError error = Wait(-1);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: TryLock
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError TryLock()
    {
        eError error = Wait(0);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Unlock
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Unlock()
    {
        eError error = Release();
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
        eError error = Release();
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWINMUTEX_MEMBERS_ONLY) 
#endif // !defined(CWINMUTEX_MEMBERS_ONLY) 

#endif // !defined(_CWINMUTEX_HPP) || defined(CWINMUTEX_MEMBERS_ONLY) 
