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
//   File: cWinCrtThread.hpp
//
// Author: $author$
//   Date: 6/21/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWINCRTTHREAD_HPP) || defined(CWINCRTTHREAD_MEMBERS_ONLY)
#if !defined(_CWINCRTTHREAD_HPP) && !defined(CWINCRTTHREAD_MEMBERS_ONLY)
#define _CWINCRTTHREAD_HPP
#endif // !defined(_CWINCRTTHREAD_HPP) && !defined(CWINCRTTHREAD_MEMBERS_ONLY) 

#if !defined(CWINCRTTHREAD_MEMBERS_ONLY)
#include "cWinCrtThreadInterface.hpp"
#include "cWinThread.hpp"
#include "cplatform_process.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWinCrtThreadExtend
//
//  Author: $author$
//    Date: 6/21/2011
///////////////////////////////////////////////////////////////////////
typedef cWinThread
cWinCrtThreadExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cWinCrtThread
//
// Author: $author$
//   Date: 6/21/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cWinCrtThread
: virtual public cWinCrtThreadImplement,
  public cWinCrtThreadExtend
{
public:
    typedef cWinCrtThreadImplement cImplements;
    typedef cWinCrtThreadExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWinCrtThread
    //
    //       Author: $author$
    //         Date: 6/21/2011
    ///////////////////////////////////////////////////////////////////////
    cWinCrtThread
    (HANDLE attached,
     DWORD threadId=0,
     bool isStarted=false,
     bool isCreated=false)
    : cExtends(attached, threadId, isStarted, isCreated)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWinCrtThread
    //
    //       Author: $author$
    //         Date: 6/21/2011
    ///////////////////////////////////////////////////////////////////////
    cWinCrtThread
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
#else // !defined(CWINCRTTHREAD_MEMBERS_ONLY) 
#endif // !defined(CWINCRTTHREAD_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Begin
    //
    //    Author: $author$
    //      Date: 6/21/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Begin
    (bool initiallyStopped=false,
     bool onlyDestroyed=false)
#if defined(CWINCRTTHREAD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINCRTTHREAD_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINCRTTHREAD_MEMBER_FUNCS_IMPLEMENT)
        unsigned (__stdcall*startAddress)(void*) = ThreadProc;
        void* parameter = (void*)((cWinThreadInterface*)(this));
        unsigned initFlags = (initiallyStopped)?(CREATE_SUSPENDED):(0);
        unsigned stackSize = 0;
        unsigned threadId = 0;
        SECURITY_ATTRIBUTES securityAttributes;
        cWinSecurityAttributes sa(securityAttributes);

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        if ((m_isCreated = (0 != (m_attached = (HANDLE)(_beginthreadex
            (&securityAttributes, stackSize, startAddress, 
             parameter, initFlags, &threadId))))))
        {
            SetIsStarted(!initiallyStopped);
            SetThreadId(threadId);
            error = e_ERROR_NONE;
        }
        else
        c_DB_ERROR("() failed on _beginthreadex()");
#else // !defined(CWINCRTTHREAD_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINCRTTHREAD_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWINCRTTHREAD_MEMBER_FUNCS_INTERFACE) 

#if defined(CWINCRTTHREAD_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: ThreadProc
    //
    //    Author: $author$
    //      Date: 6/21/2011
    ///////////////////////////////////////////////////////////////////////
    static unsigned __stdcall ThreadProc(void* parameter);
#else // defined(CWINCRTTHREAD_MEMBER_FUNCS_INTERFACE) 
#endif // defined(CWINCRTTHREAD_MEMBER_FUNCS_INTERFACE) 

#if !defined(CWINCRTTHREAD_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Create
    //
    //    Author: $author$
    //      Date: 6/21/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Create
    (bool initiallyStopped=false,
     bool onlyDestroyed=false)
    {
        eError error = Begin(initiallyStopped, onlyDestroyed);
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWINCRTTHREAD_MEMBERS_ONLY) 
#endif // !defined(CWINCRTTHREAD_MEMBERS_ONLY) 

#endif // !defined(_CWINCRTTHREAD_HPP) || defined(CWINCRTTHREAD_MEMBERS_ONLY) 
