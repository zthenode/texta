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
//   File: cSemaphoreBase.hpp
//
// Author: $author$
//   Date: 5/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CSEMAPHOREBASE_HPP) || defined(CSEMAPHOREBASE_MEMBERS_ONLY)
#if !defined(_CSEMAPHOREBASE_HPP) && !defined(CSEMAPHOREBASE_MEMBERS_ONLY)
#define _CSEMAPHOREBASE_HPP
#endif // !defined(_CSEMAPHOREBASE_HPP) && !defined(CSEMAPHOREBASE_MEMBERS_ONLY) 

#if !defined(CSEMAPHOREBASE_MEMBERS_ONLY)
#include "cSemaphoreInterface.hpp"
#include "cWait.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cSemaphoreBaseExtend
//
//  Author: $author$
//    Date: 5/25/2011
///////////////////////////////////////////////////////////////////////
typedef cWait
cSemaphoreBaseExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cSemaphoreBase
//
// Author: $author$
//   Date: 5/25/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cSemaphoreBase
: virtual public cSemaphoreImplement,
  public cSemaphoreBaseExtend
{
public:
    typedef cSemaphoreImplement cImplements;
    typedef cSemaphoreBaseExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cSemaphoreBase
    //
    //       Author: $author$
    //         Date: 5/25/2011
    ///////////////////////////////////////////////////////////////////////
    cSemaphoreBase
    (bool create=false,
     unsigned int initialCount=0,
     int maximumCount=-1)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cSemaphoreBase
    //
    //      Author: $author$
    //        Date: 5/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cSemaphoreBase()
    {
    }
#else // !defined(CSEMAPHOREBASE_MEMBERS_ONLY) 
#endif // !defined(CSEMAPHOREBASE_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Acquire
    //
    //    Author: $author$
    //      Date: 5/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Acquire
    (mseconds_t waitMilliseconds)
#if defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Acquire
    //
    //    Author: $author$
    //      Date: 5/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Acquire()
#if defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: TryAcquire
    //
    //    Author: $author$
    //      Date: 5/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError TryAcquire()
#if defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Release
    //
    //    Author: $author$
    //      Date: 5/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Release
    (unsigned int count)
#if defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Release
    //
    //    Author: $author$
    //      Date: 5/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Release()
#if defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Create
    //
    //    Author: $author$
    //      Date: 5/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Create
    (unsigned int initialCount=0,
     int maximumCount=-1,
     bool onlyDestroyed=false)
#if defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Destroy
    //
    //    Author: $author$
    //      Date: 5/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Destroy
    (bool onlyCreated=false)
#if defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE) 

#if !defined(CSEMAPHOREBASE_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Wait
    //
    //    Author: $author$
    //      Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Wait
    (mseconds_t waitMilliseconds)
    {
        eError error = Acquire(waitMilliseconds);
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
        eError error = Acquire();
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
        eError error = TryAcquire();
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
        eError error = Release();
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CSEMAPHOREBASE_MEMBERS_ONLY) 
#endif // !defined(CSEMAPHOREBASE_MEMBERS_ONLY) 

#endif // !defined(_CSEMAPHOREBASE_HPP) || defined(CSEMAPHOREBASE_MEMBERS_ONLY) 
        

