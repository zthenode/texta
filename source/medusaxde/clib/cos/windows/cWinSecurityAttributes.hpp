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
//   File: cWinSecurityAttributes.hpp
//
// Author: $author$
//   Date: 6/12/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWINSECURITYATTRIBUTES_HPP) || defined(CWINSECURITYATTRIBUTES_MEMBERS_ONLY)
#if !defined(_CWINSECURITYATTRIBUTES_HPP) && !defined(CWINSECURITYATTRIBUTES_MEMBERS_ONLY)
#define _CWINSECURITYATTRIBUTES_HPP
#endif // !defined(_CWINSECURITYATTRIBUTES_HPP) && !defined(CWINSECURITYATTRIBUTES_MEMBERS_ONLY) 

#if !defined(CWINSECURITYATTRIBUTES_MEMBERS_ONLY)
#include "cWinSecurityAttributesInterface.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWinSecurityAttributesExtend
//
//  Author: $author$
//    Date: 6/12/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cWinSecurityAttributesExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cWinSecurityAttributes
//
// Author: $author$
//   Date: 6/12/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cWinSecurityAttributes
: virtual public cWinSecurityAttributesImplement,
  public cWinSecurityAttributesExtend
{
public:
    typedef cWinSecurityAttributesImplement cImplements;
    typedef cWinSecurityAttributesExtend cExtends;

    SECURITY_ATTRIBUTES m_saDefault;
    SECURITY_ATTRIBUTES& m_sa;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWinSecurityAttributes
    //
    //       Author: $author$
    //         Date: 6/12/2011
    ///////////////////////////////////////////////////////////////////////
    cWinSecurityAttributes()
    : m_sa(m_saDefault)
    {
        memset(&m_sa, 0, sizeof(SECURITY_ATTRIBUTES));
        m_sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWinSecurityAttributes
    //
    //       Author: $author$
    //         Date: 6/12/2011
    ///////////////////////////////////////////////////////////////////////
    cWinSecurityAttributes
    (SECURITY_ATTRIBUTES& sa, 
     bool alreadyInitialized=false)
    : m_sa(sa)
    {
        if (!(alreadyInitialized))
        {
            memset(&m_sa, 0, sizeof(SECURITY_ATTRIBUTES));
            m_sa.nLength = sizeof(SECURITY_ATTRIBUTES);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cWinSecurityAttributes
    //
    //      Author: $author$
    //        Date: 6/12/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cWinSecurityAttributes()
    {
    }
#else // !defined(CWINSECURITYATTRIBUTES_MEMBERS_ONLY) 
#endif // !defined(CWINSECURITYATTRIBUTES_MEMBERS_ONLY) 

#if !defined(CWINSECURITYATTRIBUTES_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: operator
    //
    //    Author: $author$
    //      Date: 6/12/2011
    ///////////////////////////////////////////////////////////////////////
    virtual operator SECURITY_ATTRIBUTES&() const
#if defined(CWINSECURITYATTRIBUTES_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWINSECURITYATTRIBUTES_MEMBER_FUNCS_INTERFACE) 
    {
        return (SECURITY_ATTRIBUTES&)(m_sa);
    }
#endif // defined(CWINSECURITYATTRIBUTES_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CWINSECURITYATTRIBUTES_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWINSECURITYATTRIBUTES_MEMBER_FUNCS_IMPLEMENT) 

#if !defined(CWINSECURITYATTRIBUTES_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWINSECURITYATTRIBUTES_MEMBERS_ONLY) 
#endif // !defined(CWINSECURITYATTRIBUTES_MEMBERS_ONLY) 

#endif // !defined(_CWINSECURITYATTRIBUTES_HPP) || defined(CWINSECURITYATTRIBUTES_MEMBERS_ONLY) 
        

