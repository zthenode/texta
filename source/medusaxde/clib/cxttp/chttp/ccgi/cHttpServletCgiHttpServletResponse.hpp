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
//   File: cHttpServletCgiHttpServletResponse.hpp
//
// Author: $author$
//   Date: 11/6/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPSERVLETCGIHTTPSERVLETRESPONSE_HPP) || defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBERS_ONLY)
#if !defined(_CHTTPSERVLETCGIHTTPSERVLETRESPONSE_HPP) && !defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBERS_ONLY)
#define _CHTTPSERVLETCGIHTTPSERVLETRESPONSE_HPP
#endif // !defined(_CHTTPSERVLETCGIHTTPSERVLETRESPONSE_HPP) && !defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBERS_ONLY)
#include "cHttpServletResponse.hpp"
#include "cCgiInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpServletCgiHttpServletResponseImplement
//
//  Author: $author$
//    Date: 11/6/2011
///////////////////////////////////////////////////////////////////////
typedef cHttpServletResponseImplement
cHttpServletCgiHttpServletResponseImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cHttpServletCgiHttpServletResponseExtend
//
//  Author: $author$
//    Date: 11/6/2011
///////////////////////////////////////////////////////////////////////
typedef cHttpServletResponse
cHttpServletCgiHttpServletResponseExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletCgiHttpServletResponse
//
// Author: $author$
//   Date: 11/6/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cHttpServletCgiHttpServletResponse
: virtual public cHttpServletCgiHttpServletResponseImplement,
  public cHttpServletCgiHttpServletResponseExtend
{
public:
    typedef cHttpServletCgiHttpServletResponseImplement cImplements;
    typedef cHttpServletCgiHttpServletResponseExtend cExtends;

    cCgiInterface& m_cgi;
    cString m_contentType;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpServletCgiHttpServletResponse
    //
    //       Author: $author$
    //         Date: 11/6/2011
    ///////////////////////////////////////////////////////////////////////
    cHttpServletCgiHttpServletResponse
    (cCgiInterface& cgi)
    : m_cgi(cgi)
    {
    }
#else // !defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetContentType
    //
    //    Author: $author$
    //      Date: 11/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const cString& SetContentType
    (const cString& toContentType)
#if defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE) 
    {
        m_cgi.SetContentType(toContentType);
        m_contentType = toContentType;
        return m_contentType;
    }
#endif // defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT) 
#if !defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentType
    //
    //    Author: $author$
    //      Date: 11/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const cString& GetContentType()
#if defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE) 
    {
        return m_contentType;
    }
#endif // defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBER_FUNCS_IMPLEMENT) 

#if !defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBERS_ONLY) 

#endif // !defined(_CHTTPSERVLETCGIHTTPSERVLETRESPONSE_HPP) || defined(CHTTPSERVLETCGIHTTPSERVLETRESPONSE_MEMBERS_ONLY) 
        

