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
//   File: cHttpServletCgiHttpServletRequest.hpp
//
// Author: $author$
//   Date: 11/6/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPSERVLETCGIHTTPSERVLETREQUEST_HPP) || defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBERS_ONLY)
#if !defined(_CHTTPSERVLETCGIHTTPSERVLETREQUEST_HPP) && !defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBERS_ONLY)
#define _CHTTPSERVLETCGIHTTPSERVLETREQUEST_HPP
#endif // !defined(_CHTTPSERVLETCGIHTTPSERVLETREQUEST_HPP) && !defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBERS_ONLY)
#include "cHttpServletRequest.hpp"
#include "cCgiInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpServletCgiHttpServletRequestImplement
//
//  Author: $author$
//    Date: 11/6/2011
///////////////////////////////////////////////////////////////////////
typedef cHttpServletRequestImplement
cHttpServletCgiHttpServletRequestImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cHttpServletCgiHttpServletRequestExtend
//
//  Author: $author$
//    Date: 11/6/2011
///////////////////////////////////////////////////////////////////////
typedef cHttpServletRequest
cHttpServletCgiHttpServletRequestExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletCgiHttpServletRequest
//
// Author: $author$
//   Date: 11/6/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cHttpServletCgiHttpServletRequest
: virtual public cHttpServletCgiHttpServletRequestImplement,
  public cHttpServletCgiHttpServletRequestExtend
{
public:
    typedef cHttpServletCgiHttpServletRequestImplement cImplements;
    typedef cHttpServletCgiHttpServletRequestExtend cExtends;

    cCgiInterface& m_cgi;
    cString m_contentType;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpServletCgiHttpServletRequest
    //
    //       Author: $author$
    //         Date: 11/6/2011
    ///////////////////////////////////////////////////////////////////////
    cHttpServletCgiHttpServletRequest
    (cCgiInterface& cgi)
    : m_cgi(cgi)
    {
    }
#else // !defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetContentType
    //
    //    Author: $author$
    //      Date: 11/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const cString& SetContentType
    (const cString& toContentType)
#if defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBER_FUNCS_INTERFACE) 
    {
        m_contentType = toContentType;
        return m_contentType;
    }
#endif // defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBER_FUNCS_IMPLEMENT) 
#if !defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentType
    //
    //    Author: $author$
    //      Date: 11/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const cString& GetContentType() const
#if defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBER_FUNCS_INTERFACE) 
    {
        return m_contentType;
    }
#endif // defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBER_FUNCS_IMPLEMENT) 

#if !defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBERS_ONLY) 

#endif // !defined(_CHTTPSERVLETCGIHTTPSERVLETREQUEST_HPP) || defined(CHTTPSERVLETCGIHTTPSERVLETREQUEST_MEMBERS_ONLY) 
        

