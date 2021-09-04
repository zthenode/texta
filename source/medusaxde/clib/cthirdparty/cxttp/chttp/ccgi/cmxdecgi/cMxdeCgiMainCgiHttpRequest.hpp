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
//   File: cMxdeCgiMainCgiHttpRequest.hpp
//
// Author: $author$
//   Date: 10/29/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CMXDECGIMAINCGIHTTPREQUEST_HPP) || defined(CMXDECGIMAINCGIHTTPREQUEST_MEMBERS_ONLY)
#if !defined(_CMXDECGIMAINCGIHTTPREQUEST_HPP) && !defined(CMXDECGIMAINCGIHTTPREQUEST_MEMBERS_ONLY)
#define _CMXDECGIMAINCGIHTTPREQUEST_HPP
#endif // !defined(_CMXDECGIMAINCGIHTTPREQUEST_HPP) && !defined(CMXDECGIMAINCGIHTTPREQUEST_MEMBERS_ONLY) 

#if !defined(CMXDECGIMAINCGIHTTPREQUEST_MEMBERS_ONLY)
#include "cHttpRequest.hpp"
#include "cMxdeCgiMainHttpRequest.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpRequestExtend
//
//  Author: $author$
//    Date: 10/29/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cHttpRequestExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cMxdeCgiMainCgiHttpRequest
//
// Author: $author$
//   Date: 10/29/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cMxdeCgiMainCgiHttpRequest
: public cHttpRequest
{
public:
    typedef cHttpRequest cExtends;

    cMxdeCgiMainHttpRequest& m_request;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cMxdeCgiMainCgiHttpRequest
    //
    //       Author: $author$
    //         Date: 10/29/2011
    ///////////////////////////////////////////////////////////////////////
    cMxdeCgiMainCgiHttpRequest
    (cMxdeCgiMainHttpRequest& request)
    : m_request(request)
    {
    }
#else // !defined(CMXDECGIMAINCGIHTTPREQUEST_MEMBERS_ONLY) 
#endif // !defined(CMXDECGIMAINCGIHTTPREQUEST_MEMBERS_ONLY) 

#if !defined(CMXDECGIMAINCGIHTTPREQUEST_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetRequestMethod
    //
    //    Author: $author$
    //      Date: 10/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eHttpRequestMethod GetRequestMethod() const
    {
        return ToHttpRequestMethod(m_request.GetRequestMethod());
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: ToHttpRequestMethod
    //
    //    Author: $author$
    //      Date: 10/29/2011
    ///////////////////////////////////////////////////////////////////////
    eHttpRequestMethod ToHttpRequestMethod
    (eMxdeCgiHttpRequestMethod requestMethod) const
    {
        switch(requestMethod)
        {
        case e_MXDE_CGI_HTTP_REQUEST_METHOD_GET: return e_HTTP_REQUEST_METHOD_GET;
        case e_MXDE_CGI_HTTP_REQUEST_METHOD_POST: return e_HTTP_REQUEST_METHOD_POST;
        case e_MXDE_CGI_HTTP_REQUEST_METHOD_PUT: return e_HTTP_REQUEST_METHOD_PUT;
        case e_MXDE_CGI_HTTP_REQUEST_METHOD_DELETE: return e_HTTP_REQUEST_METHOD_DELETE;
        case e_MXDE_CGI_HTTP_REQUEST_METHOD_TRACE: return e_HTTP_REQUEST_METHOD_TRACE;
        case e_MXDE_CGI_HTTP_REQUEST_METHOD_HEAD: return e_HTTP_REQUEST_METHOD_HEAD;
        case e_MXDE_CGI_HTTP_REQUEST_METHOD_OPTIONS: return e_HTTP_REQUEST_METHOD_OPTIONS;
        }
        return e_HTTP_REQUEST_METHOD_NONE;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CMXDECGIMAINCGIHTTPREQUEST_MEMBERS_ONLY) 
#endif // !defined(CMXDECGIMAINCGIHTTPREQUEST_MEMBERS_ONLY) 

#endif // !defined(_CMXDECGIMAINCGIHTTPREQUEST_HPP) || defined(CMXDECGIMAINCGIHTTPREQUEST_MEMBERS_ONLY) 
        

