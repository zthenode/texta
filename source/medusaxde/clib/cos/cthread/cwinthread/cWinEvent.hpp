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
//   File: cWinEvent.hpp
//
// Author: $author$
//   Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWINEVENT_HPP) || defined(CWINEVENT_MEMBERS_ONLY)
#if !defined(_CWINEVENT_HPP) && !defined(CWINEVENT_MEMBERS_ONLY)
#define _CWINEVENT_HPP
#endif // !defined(_CWINEVENT_HPP) && !defined(CWINEVENT_MEMBERS_ONLY) 

#if !defined(CWINEVENT_MEMBERS_ONLY)
#include "cWinEventInterface.hpp"
#include "cWinSecurityAttributes.hpp"
#include "cEventBase.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWinEventExtend
//
//  Author: $author$
//    Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
typedef cEventBase
cWinEventExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cWinEvent
//
// Author: $author$
//   Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cWinEvent
: virtual public cWinEventImplement,
  public cWinEventExtend
{
public:
    typedef cWinEventImplement cImplements;
    typedef cWinEventExtend cExtends;

    HANDLE m_attached;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWinEvent
    //
    //       Author: $author$
    //         Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    cWinEvent
    (bool create=false,
     bool manuallyReset=false,
     bool initiallySet=false)
    : m_attached(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cWinEvent
    //
    //      Author: $author$
    //        Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cWinEvent()
    {
    }
#else // !defined(CWINEVENT_MEMBERS_ONLY) 
#endif // !defined(CWINEVENT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Create
    //
    //    Author: $author$
    //      Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Create
    (bool manuallyReset=false,
     bool initiallySet=false,
     bool onlyDestroyed=false)
#if defined(CWINEVENT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINEVENT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT)
        BOOL bManualReset = manuallyReset;
        BOOL bInitialState = initiallySet;
        LPCTSTR lpName = NULL;
        SECURITY_ATTRIBUTES attr;
        cWinSecurityAttributes sa(attr);

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        if ((m_isCreated = (0 != (m_attached = CreateEvent
            (&attr, bManualReset, bInitialState, lpName)))))
        {
            SetManuallyReset(manuallyReset);
            error = e_ERROR_NONE;
        }
        else
        c_DB_ERROR("() failed on CreateEvent()");
#else // !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINEVENT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Destroy
    //
    //    Author: $author$
    //      Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Destroy
    (bool onlyCreated=false)
#if defined(CWINEVENT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINEVENT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT)
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
#else // !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINEVENT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Set
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Set()
#if defined(CWINEVENT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINEVENT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT)
        HANDLE attached;

        if ((attached = m_attached))
        if ((SetEvent(attached)))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on SetEvent()");
#else // !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINEVENT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Reset
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Reset()
#if defined(CWINEVENT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINEVENT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT)
        HANDLE attached;

        if ((attached = m_attached))
        if ((ResetEvent(attached)))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on ResetEvent()");
#else // !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINEVENT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Wait
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Wait
    (mseconds_t waitMilliseconds)
#if defined(CWINEVENT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINEVENT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT)
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
#else // !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINEVENT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: AttachCreated
    //
    //    Author: $author$
    //      Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual HANDLE AttachCreated
    (HANDLE detached, bool manuallyReset=false, bool isCreated=true)
#if defined(CWINEVENT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINEVENT_MEMBER_FUNCS_INTERFACE) 
    {
        HANDLE attached = 0;
#if !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT)
        if ((attached = (m_attached = detached)))
        {
            SetManuallyReset(manuallyReset);
            SetIsCreated(isCreated);
        }
        else
        {
            SetManuallyReset(false);
            SetIsCreated(false);
        }
#else // !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT) 
        return attached;
    }
#endif // defined(CWINEVENT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Attach
    //
    //    Author: $author$
    //      Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual HANDLE Attach
    (HANDLE detached, bool manuallyReset=false)
#if defined(CWINEVENT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINEVENT_MEMBER_FUNCS_INTERFACE) 
    {
        HANDLE attached = 0;
#if !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT)
        attached = (m_attached = detached);
        SetManuallyReset(manuallyReset);
        SetIsCreated(false);
#else // !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT) 
        return attached;
    }
#endif // defined(CWINEVENT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Detach
    //
    //    Author: $author$
    //      Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual HANDLE Detach()
#if defined(CWINEVENT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINEVENT_MEMBER_FUNCS_INTERFACE) 
    {
        HANDLE detached = 0;
#if !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT)
        detached = (m_attached);
        SetIsCreated(false);
        SetManuallyReset(false);
        m_attached = 0;
#else // !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINEVENT_MEMBER_FUNCS_IMPLEMENT) 
        return detached;
    }
#endif // defined(CWINEVENT_MEMBER_FUNCS_INTERFACE) 

#if !defined(CWINEVENT_MEMBERS_ONLY)
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
        eError error = e_ERROR_NONE;
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWINEVENT_MEMBERS_ONLY) 
#endif // !defined(CWINEVENT_MEMBERS_ONLY) 

#endif // !defined(_CWINEVENT_HPP) || defined(CWINEVENT_MEMBERS_ONLY) 
