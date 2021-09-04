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
//   File: cEventBase.hpp
//
// Author: $author$
//   Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CEVENTBASE_HPP) || defined(CEVENTBASE_MEMBERS_ONLY)
#if !defined(_CEVENTBASE_HPP) && !defined(CEVENTBASE_MEMBERS_ONLY)
#define _CEVENTBASE_HPP
#endif // !defined(_CEVENTBASE_HPP) && !defined(CEVENTBASE_MEMBERS_ONLY) 

#if !defined(CEVENTBASE_MEMBERS_ONLY)
#include "cEventInterface.hpp"
#include "cWait.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cEventBaseExtend
//
//  Author: $author$
//    Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
typedef cWait
cEventBaseExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cEventBase
//
// Author: $author$
//   Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cEventBase
: virtual public cEventImplement,
  public cEventBaseExtend
{
public:
    typedef cEventImplement cImplements;
    typedef cEventBaseExtend cExtends;

    bool m_manuallyReset;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cEventBase
    //
    //       Author: $author$
    //         Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    cEventBase
    (bool manuallyReset=false,
     bool isCreated=false)
    : cExtends(isCreated),
      m_manuallyReset(manuallyReset)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cEventBase
    //
    //      Author: $author$
    //        Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cEventBase()
    {
    }
#else // !defined(CEVENTBASE_MEMBERS_ONLY) 
#endif // !defined(CEVENTBASE_MEMBERS_ONLY) 

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
#if defined(CEVENTBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CEVENTBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CEVENTBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CEVENTBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CEVENTBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CEVENTBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Destroy
    //
    //    Author: $author$
    //      Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Destroy
    (bool onlyCreated=false)
#if defined(CEVENTBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CEVENTBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CEVENTBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CEVENTBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CEVENTBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CEVENTBASE_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Set
    //
    //    Author: $author$
    //      Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Set()
#if defined(CEVENTBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CEVENTBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CEVENTBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CEVENTBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CEVENTBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CEVENTBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Reset
    //
    //    Author: $author$
    //      Date: 6/13/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Reset()
#if defined(CEVENTBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CEVENTBASE_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CEVENTBASE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CEVENTBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CEVENTBASE_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CEVENTBASE_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetManuallyReset
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetManuallyReset
    (bool isTrue=true)
#if defined(CEVENTBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CEVENTBASE_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CEVENTBASE_MEMBER_FUNCS_IMPLEMENT)
        (m_manuallyReset = isTrue);
#else // !defined(CEVENTBASE_MEMBER_FUNCS_IMPLEMENT) 
        isTrue = false;
#endif // !defined(CEVENTBASE_MEMBER_FUNCS_IMPLEMENT) 
        return isTrue;
    }
#endif // defined(CEVENTBASE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetManuallyReset
    //
    //    Author: $author$
    //      Date: 6/14/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetManuallyReset() const
#if defined(CEVENTBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CEVENTBASE_MEMBER_FUNCS_INTERFACE) 
    {
        bool isTrue = false;
#if !defined(CEVENTBASE_MEMBER_FUNCS_IMPLEMENT)
        isTrue = (m_manuallyReset);
#else // !defined(CEVENTBASE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CEVENTBASE_MEMBER_FUNCS_IMPLEMENT) 
        return isTrue;
    }
#endif // defined(CEVENTBASE_MEMBER_FUNCS_INTERFACE) 

#if !defined(CEVENTBASE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CEVENTBASE_MEMBERS_ONLY) 
#endif // !defined(CEVENTBASE_MEMBERS_ONLY) 

#endif // !defined(_CEVENTBASE_HPP) || defined(CEVENTBASE_MEMBERS_ONLY) 
        

