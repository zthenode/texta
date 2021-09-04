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
//   File: cHttpContent.hpp
//
// Author: $author$
//   Date: 11/1/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPCONTENT_HPP) || defined(CHTTPCONTENT_MEMBERS_ONLY)
#if !defined(_CHTTPCONTENT_HPP) && !defined(CHTTPCONTENT_MEMBERS_ONLY)
#define _CHTTPCONTENT_HPP
#endif // !defined(_CHTTPCONTENT_HPP) && !defined(CHTTPCONTENT_MEMBERS_ONLY) 

#if !defined(CHTTPCONTENT_MEMBERS_ONLY)
#include "cHttpContentInterface.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpContentExtend
//
//  Author: $author$
//    Date: 11/1/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cHttpContentExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpContent
//
// Author: $author$
//   Date: 11/1/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cHttpContent
: virtual public cHttpContentImplement,
  public cHttpContentExtend
{
public:
    typedef cHttpContentImplement cImplements;
    typedef cHttpContentExtend cExtends;

    cHttpContentInterface* m_delegated;
    cString m_contentType;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpContent
    //
    //       Author: $author$
    //         Date: 11/1/2011
    ///////////////////////////////////////////////////////////////////////
    cHttpContent
    (cHttpContentInterface* delegated=0)
    : m_delegated(delegated)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cHttpContent
    //
    //      Author: $author$
    //        Date: 11/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cHttpContent()
    {
    }
#else // !defined(CHTTPCONTENT_MEMBERS_ONLY) 
#endif // !defined(CHTTPCONTENT_MEMBERS_ONLY) 

#if !defined(CHTTPCONTENT_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetContentType
    //
    //    Author: $author$
    //      Date: 11/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const cString& SetContentType
    (const cString& toContentType)
#if defined(CHTTPCONTENT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPCONTENT_MEMBER_FUNCS_INTERFACE) 
    {
        return m_contentType;
    }
#endif // defined(CHTTPCONTENT_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CHTTPCONTENT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPCONTENT_MEMBER_FUNCS_IMPLEMENT) 
#if !defined(CHTTPCONTENT_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentType
    //
    //    Author: $author$
    //      Date: 11/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const cString& GetContentType()
#if defined(CHTTPCONTENT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPCONTENT_MEMBER_FUNCS_INTERFACE) 
    {
        return m_contentType;
    }
#endif // defined(CHTTPCONTENT_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CHTTPCONTENT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPCONTENT_MEMBER_FUNCS_IMPLEMENT) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Delegate
    //
    //    Author: $author$
    //      Date: 11/1/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpContentInterface* Delegate
    (cHttpContentInterface* delegatedTo)
#if defined(CHTTPCONTENT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPCONTENT_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpContentInterface* delegated = 0;
#if !defined(CHTTPCONTENT_MEMBER_FUNCS_IMPLEMENT)
        delegated = m_delegated;
        m_delegated = delegatedTo;
#else // !defined(CHTTPCONTENT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPCONTENT_MEMBER_FUNCS_IMPLEMENT) 
        return delegated;
    }
#endif // defined(CHTTPCONTENT_MEMBER_FUNCS_INTERFACE) 

#if !defined(CHTTPCONTENT_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPCONTENT_MEMBERS_ONLY) 
#endif // !defined(CHTTPCONTENT_MEMBERS_ONLY) 

#endif // !defined(_CHTTPCONTENT_HPP) || defined(CHTTPCONTENT_MEMBERS_ONLY) 
        

