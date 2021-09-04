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
//   File: cWinThread.hpp
//
// Author: $author$
//   Date: 6/14/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWINTHREAD_HPP) || defined(CWINTHREAD_MEMBERS_ONLY)
#if !defined(_CWINTHREAD_HPP) && !defined(CWINTHREAD_MEMBERS_ONLY)
#define _CWINTHREAD_HPP
#endif // !defined(_CWINTHREAD_HPP) && !defined(CWINTHREAD_MEMBERS_ONLY) 

#if !defined(CWINTHREAD_MEMBERS_ONLY)
#include "cWinThreadInterface.hpp"
#include "cWinSecurityAttributes.hpp"
#include "cThreadBase.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWinThreadExtend
//
//  Author: $author$
//    Date: 6/14/2011
///////////////////////////////////////////////////////////////////////
typedef cThreadBase
cWinThreadExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cWinThread
//
// Author: $author$
//   Date: 6/14/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cWinThread
: virtual public cWinThreadImplement,
  public cWinThreadExtend
{
public:
    typedef cWinThreadImplement cImplements;
    typedef cWinThreadExtend cExtends;

    HANDLE m_attached;
    DWORD m_threadId;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWinThread
    //
    //       Author: $author$
    //         Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    cWinThread
    (HANDLE attached,
     DWORD threadId=0,
     bool isStarted=false,
     bool isCreated=false)
    : cExtends(isStarted, isCreated),
      m_attached(attached),
      m_threadId(threadId)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWinThread
    //
    //       Author: $author$
    //         Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    cWinThread
    (bool create=false,
     bool initiallyStopped=false)
    : m_attached(false),
      m_threadId(0)
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
    //  Destructor: ~cWinThread
    //
    //      Author: $author$
    //        Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cWinThread()
    {
        eError error;
        if ((error = Destroyed()))
            throw (error);
    }
#else // !defined(CWINTHREAD_MEMBERS_ONLY) 
#endif // !defined(CWINTHREAD_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Create
    //
    //    Author: $author$
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Create
    (bool initiallyStopped=false,
     bool onlyDestroyed=false)
#if defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT)
        LPTHREAD_START_ROUTINE lpStartAddress = ThreadProc;
        LPVOID lpParameter = (LPVOID)((cWinThreadInterface*)(this));
        DWORD dwCreationFlags = (initiallyStopped)?(CREATE_SUSPENDED):(0);
        DWORD dwStackSize = 0;
        DWORD dwThreadId = 0;
        SECURITY_ATTRIBUTES attr;
        cWinSecurityAttributes sa(attr);

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        if ((m_isCreated = (0 != (m_attached = CreateThread
            (&attr, dwStackSize, lpStartAddress, 
             lpParameter, dwCreationFlags, &dwThreadId)))))
        {
            SetIsStarted(!initiallyStopped);
            SetThreadId(dwThreadId);
            error = e_ERROR_NONE;
        }
        else
        c_DB_ERROR("() failed on CreateThread()");
#else // !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Destroy
    //
    //    Author: $author$
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Destroy
    (bool onlyCreated=false)
#if defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT)
        eError error2 = e_ERROR_NONE;
        HANDLE detached;

        if ((GetIsStarted()))
            error2 = Finish();

        if (!(detached = Detach()))
        if ((onlyCreated))
            return error = e_ERROR_FAILED;
        else
        return error = error2;

        if ((CloseHandle(detached)))
            error = error2;
        else
        c_DB_ERROR("() failed on CloseHandle()");
#else // !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Suspend
    //
    //    Author: $author$
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Suspend()
#if defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT)
        DWORD result;
        HANDLE attached;

        if ((attached = m_attached))
        if (0 <= (result = SuspendThread(attached)))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on SuspendThread()");
#else // !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Resume
    //
    //    Author: $author$
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Resume()
#if defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT)
        DWORD result;
        HANDLE attached;

        if ((attached = m_attached))
        if (0 <= (result = ResumeThread(attached)))
            error = e_ERROR_NONE;
        else
        c_DB_ERROR("() failed on ResumeThread()");
#else // !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Wait
    //
    //    Author: $author$
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Wait
    (mseconds_t waitMilliseconds)
#if defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT)
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
#else // !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: AttachCreated
    //
    //    Author: $author$
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual HANDLE AttachCreated
    (HANDLE detached,
     DWORD threadId,
     bool isStarted=true,
     bool isCreated=true)
#if defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 
    {
        HANDLE attached = 0;
#if !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT)
        if ((attached = (m_attached = detached)))
        {
            SetIsStarted(isStarted);
            SetIsCreated(isCreated);
        }
        else
        {
            SetIsStarted(false);
            SetIsCreated(false);
        }
#else // !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT) 
        return attached;
    }
#endif // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Attach
    //
    //    Author: $author$
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual HANDLE Attach
    (HANDLE detached)
#if defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 
    {
        HANDLE attached = 0;
#if !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT)
        attached = (m_attached = detached);
        SetIsCreated(false);
        SetIsStarted(false);
#else // !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT) 
        return attached;
    }
#endif // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Detach
    //
    //    Author: $author$
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual HANDLE Detach()
#if defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 
    {
        HANDLE detached = 0;
#if !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT)
        SetIsStarted(false);
        SetIsCreated(false);
        detached = (m_attached);
        m_attached = 0;
#else // !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT) 
        return detached;
    }
#endif // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetThreadId
    //
    //    Author: $author$
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual DWORD SetThreadId
    (DWORD threadId)
#if defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT)
        m_threadId = (threadId);
#else // !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT) 
        threadId = 0;
#endif // !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT) 
        return threadId;
    }
#endif // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetThreadId
    //
    //    Author: $author$
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual DWORD GetThreadId() const
#if defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 
    {
        DWORD threadId = 0;
#if !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT)
        threadId = (m_threadId);
#else // !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINTHREAD_MEMBER_FUNCS_IMPLEMENT) 
        return threadId;
    }
#endif // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 

#if defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: ThreadProc
    //
    //    Author: $author$
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    static DWORD WINAPI ThreadProc(LPVOID lpParameter);
#else // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 
#endif // defined(CWINTHREAD_MEMBER_FUNCS_INTERFACE) 

#if !defined(CWINTHREAD_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Start
    //
    //    Author: $author$
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Start
    (bool onlyStopped=false)
    {
        eError error = e_ERROR_FAILED;
        bool isStarted;

        if ((isStarted = GetIsStarted()))
        if ((onlyStopped))
            return error = e_ERROR_FAILED;
        else
        return error = e_ERROR_NONE;

        if (!(error = Resume()))
            SetIsStarted();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finish
    //
    //    Author: $author$
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finish
    (mseconds_t waitMilliseconds, 
     bool onlyStarted=false)
    {
        eError error = e_ERROR_FAILED;
        bool isStarted;

        if (!(isStarted = GetIsStarted()))
        if ((onlyStarted))
            return error = e_ERROR_FAILED;
        else
        return error = e_ERROR_NONE;

        error = Wait(waitMilliseconds);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finish
    //
    //    Author: $author$
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finish
    (bool onlyStarted=false)
    {
        eError error = Finish(-1, onlyStarted);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: TryFinish
    //
    //    Author: $author$
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError TryFinish
    (bool onlyStarted=false)
    {
        eError error = Finish(0, onlyStarted);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: Wait
    //
    //    Author: $author$
    //      Date: 6/15/2011
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
    //      Date: 6/15/2011
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
    //      Date: 6/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Continue()
    {
        eError error = Destroy();
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWINTHREAD_MEMBERS_ONLY) 
#endif // !defined(CWINTHREAD_MEMBERS_ONLY) 

#endif // !defined(_CWINTHREAD_HPP) || defined(CWINTHREAD_MEMBERS_ONLY) 
