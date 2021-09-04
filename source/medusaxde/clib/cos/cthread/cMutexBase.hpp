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
//   File: cMutexBase.hpp
//
// Author: $author$
//   Date: 3/19/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CMUTEXBASE_HPP) || defined(CMUTEXBASE_MEMBERS_ONLY)
#if !defined(_CMUTEXBASE_HPP) && !defined(CMUTEXBASE_MEMBERS_ONLY)
#define _CMUTEXBASE_HPP
#endif // !defined(_CMUTEXBASE_HPP) && !defined(CMUTEXBASE_MEMBERS_ONLY) 

#if !defined(CMUTEXBASE_MEMBERS_ONLY)
#include "cMutexInterface.hpp"
#include "cWait.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cMutexBaseImplement
//
//  Author: $author$
//    Date: 3/19/2011
///////////////////////////////////////////////////////////////////////
typedef cWait
cMutexBaseExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cMutexBase
//
// Author: $author$
//   Date: 3/19/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cMutexBase
: virtual public cMutexImplement,
  public cMutexBaseExtend
{
public:
    typedef cMutexImplement cImplements;
    typedef cMutexBaseExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cMutexBase
    //
    //       Author: $author$
    //         Date: 3/19/2011
    ///////////////////////////////////////////////////////////////////////
    cMutexBase
    (bool create=false,
     bool initiallyLocked=false)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cMutexBase
    //
    //      Author: $author$
    //        Date: 3/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cMutexBase()
    {
    }
#else // !defined(CMUTEXBASE_MEMBERS_ONLY) 
#endif // !defined(CMUTEXBASE_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Create
    //
    //    Author: $author$
    //      Date: 3/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Create
    (bool initallyLocked=false,
     bool onlyDestroyed=false)
#if defined(CMUTEXBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CMUTEXBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CMUTEXBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CMUTEXBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CMUTEXBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CMUTEXBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Destroy
    //
    //    Author: $author$
    //      Date: 3/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Destroy
    (bool onlyCreated=false)
#if defined(CMUTEXBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CMUTEXBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CMUTEXBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CMUTEXBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CMUTEXBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CMUTEXBASE_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Lock
    //
    //    Author: $author$
    //      Date: 3/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Lock
    (mseconds_t milliseconds)
#if defined(CMUTEXBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CMUTEXBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CMUTEXBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CMUTEXBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CMUTEXBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CMUTEXBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Lock
    //
    //    Author: $author$
    //      Date: 3/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Lock()
#if defined(CMUTEXBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CMUTEXBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CMUTEXBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CMUTEXBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CMUTEXBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CMUTEXBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: TryLock
    //
    //    Author: $author$
    //      Date: 3/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError TryLock()
#if defined(CMUTEXBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CMUTEXBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CMUTEXBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CMUTEXBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CMUTEXBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CMUTEXBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Unlock
    //
    //    Author: $author$
    //      Date: 3/19/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Unlock()
#if defined(CMUTEXBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CMUTEXBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CMUTEXBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CMUTEXBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CMUTEXBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CMUTEXBASE_MEMBER_FUNCS_INTERFACE) 

#if !defined(CMUTEXBASE_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Wait
    //
    //    Author: $author$
    //      Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Wait
    (mseconds_t waitMilliseconds)
    {
        eError error = Lock(waitMilliseconds);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Wait
    //
    //    Author: $author$
    //      Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Wait()
    {
        eError error = Lock();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: TryWait
    //
    //    Author: $author$
    //      Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError TryWait()
    {
        eError error = TryLock();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Continue
    //
    //    Author: $author$
    //      Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Continue()
    {
        eError error = Unlock();
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CMUTEXBASE_MEMBERS_ONLY) 
#endif // !defined(CMUTEXBASE_MEMBERS_ONLY) 

#endif // !defined(_CMUTEXBASE_HPP) || defined(CMUTEXBASE_MEMBERS_ONLY) 
