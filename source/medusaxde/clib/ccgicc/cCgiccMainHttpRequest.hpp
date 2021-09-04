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
//   File: cCgiccMainHttpRequest.hpp
//
// Author: $author$
//   Date: 11/6/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCGICCMAINHTTPREQUEST_HPP) || defined(CCGICCMAINHTTPREQUEST_MEMBERS_ONLY)
#if !defined(_CCGICCMAINHTTPREQUEST_HPP) && !defined(CCGICCMAINHTTPREQUEST_MEMBERS_ONLY)
#define _CCGICCMAINHTTPREQUEST_HPP
#endif // !defined(_CCGICCMAINHTTPREQUEST_HPP) && !defined(CCGICCMAINHTTPREQUEST_MEMBERS_ONLY) 

#if !defined(CCGICCMAINHTTPREQUEST_MEMBERS_ONLY)
#include "cHttpRequest.hpp"
#include "cCgiccMainInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiccMainHttpRequestImplement
//
//  Author: $author$
//    Date: 11/6/2011
///////////////////////////////////////////////////////////////////////
typedef cHttpRequestImplement
cCgiccMainHttpRequestImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cCgiccMainHttpRequestExtend
//
//  Author: $author$
//    Date: 11/6/2011
///////////////////////////////////////////////////////////////////////
typedef cHttpRequest
cCgiccMainHttpRequestExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiccMainHttpRequest
//
// Author: $author$
//   Date: 11/6/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cCgiccMainHttpRequest
: virtual public cCgiccMainHttpRequestImplement,
  public cCgiccMainHttpRequestExtend
{
public:
    typedef cCgiccMainHttpRequestImplement cImplements;
    typedef cCgiccMainHttpRequestExtend cExtends;

    cCgiccMainInterface& m_cgiccMain;
    cString
     m_httpRequestMethodName_GET,
     m_httpRequestMethodName_POST,
     m_httpRequestMethodName_PUT,
     m_httpRequestMethodName_DELETE,
     m_httpRequestMethodName_TRACE,
     m_httpRequestMethodName_HEAD,
     m_httpRequestMethodName_OPTIONS;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgiccMainHttpRequest
    //
    //       Author: $author$
    //         Date: 11/6/2011
    ///////////////////////////////////////////////////////////////////////
    cCgiccMainHttpRequest
    (cCgiccMainInterface& cgiccMain)
    : m_cgiccMain(cgiccMain),
      m_httpRequestMethodName_GET(c_HTTP_REQUEST_METHOD_NAME_GET),
      m_httpRequestMethodName_POST(c_HTTP_REQUEST_METHOD_NAME_POST),
      m_httpRequestMethodName_PUT(c_HTTP_REQUEST_METHOD_NAME_PUT),
      m_httpRequestMethodName_DELETE(c_HTTP_REQUEST_METHOD_NAME_DELETE),
      m_httpRequestMethodName_TRACE(c_HTTP_REQUEST_METHOD_NAME_TRACE),
      m_httpRequestMethodName_HEAD(c_HTTP_REQUEST_METHOD_NAME_HEAD),
      m_httpRequestMethodName_OPTIONS(c_HTTP_REQUEST_METHOD_NAME_OPTIONS)
    {
    }
#else // !defined(CCGICCMAINHTTPREQUEST_MEMBERS_ONLY) 
#endif // !defined(CCGICCMAINHTTPREQUEST_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetRequestMethod
    //
    //    Author: $author$
    //      Date: 11/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eHttpRequestMethod GetRequestMethod() const
#if defined(CCGICCMAINHTTPREQUEST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGICCMAINHTTPREQUEST_MEMBER_FUNCS_INTERFACE) 
    {
        eHttpRequestMethod requestMethod = e_HTTP_REQUEST_METHOD_NONE;
#if !defined(CCGICCMAINHTTPREQUEST_MEMBER_FUNCS_IMPLEMENT)
        const cString& requestMethodName = m_cgiccMain.GetRequestMethod();
         if (!(requestMethodName!=(m_httpRequestMethodName_GET))) return e_HTTP_REQUEST_METHOD_GET;
         if (!(requestMethodName!=(m_httpRequestMethodName_POST))) return e_HTTP_REQUEST_METHOD_POST;
         if (!(requestMethodName!=(m_httpRequestMethodName_PUT))) return e_HTTP_REQUEST_METHOD_PUT;
         if (!(requestMethodName!=(m_httpRequestMethodName_DELETE))) return e_HTTP_REQUEST_METHOD_DELETE;
         if (!(requestMethodName!=(m_httpRequestMethodName_TRACE))) return e_HTTP_REQUEST_METHOD_TRACE;
         if (!(requestMethodName!=(m_httpRequestMethodName_HEAD))) return e_HTTP_REQUEST_METHOD_HEAD;
         if (!(requestMethodName!=(m_httpRequestMethodName_OPTIONS))) return e_HTTP_REQUEST_METHOD_OPTIONS;
#else // !defined(CCGICCMAINHTTPREQUEST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGICCMAINHTTPREQUEST_MEMBER_FUNCS_IMPLEMENT) 
        return requestMethod;
    }
#endif // defined(CCGICCMAINHTTPREQUEST_MEMBER_FUNCS_INTERFACE) 

#if !defined(CCGICCMAINHTTPREQUEST_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCGICCMAINHTTPREQUEST_MEMBERS_ONLY) 
#endif // !defined(CCGICCMAINHTTPREQUEST_MEMBERS_ONLY) 

#endif // !defined(_CCGICCMAINHTTPREQUEST_HPP) || defined(CCGICCMAINHTTPREQUEST_MEMBERS_ONLY) 
        

