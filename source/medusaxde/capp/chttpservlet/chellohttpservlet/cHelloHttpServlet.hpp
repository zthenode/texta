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
//   File: cHelloHttpServlet.hpp
//
// Author: $author$
//   Date: 10/27/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHELLOHTTPSERVLET_HPP) || defined(CHELLOHTTPSERVLET_MEMBERS_ONLY)
#if !defined(_CHELLOHTTPSERVLET_HPP) && !defined(CHELLOHTTPSERVLET_MEMBERS_ONLY)
#define _CHELLOHTTPSERVLET_HPP
#endif // !defined(_CHELLOHTTPSERVLET_HPP) && !defined(CHELLOHTTPSERVLET_MEMBERS_ONLY) 

#if !defined(CHELLOHTTPSERVLET_MEMBERS_ONLY)
#include "cHttpServlet.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHelloHttpServletImplement
//
//  Author: $author$
//    Date: 10/27/2011
///////////////////////////////////////////////////////////////////////
typedef cHttpServletImplement
cHelloHttpServletImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cHelloHttpServletExtend
//
//  Author: $author$
//    Date: 10/27/2011
///////////////////////////////////////////////////////////////////////
typedef cHttpServlet
cHelloHttpServletExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cHelloHttpServlet
//
// Author: $author$
//   Date: 10/27/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cHelloHttpServlet
: virtual public cHelloHttpServletImplement,
  public cHelloHttpServletExtend
{
public:
    typedef cHelloHttpServletImplement cImplements;
    typedef cHelloHttpServletExtend cExtends;
#else // !defined(CHELLOHTTPSERVLET_MEMBERS_ONLY) 
#endif // !defined(CHELLOHTTPSERVLET_MEMBERS_ONLY) 

#if !defined(CHELLOHTTPSERVLET_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: DoRequest
    //
    //    Author: $author$
    //      Date: 10/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError DoRequest
    (const cHttpServletRequestInterface& req,
     cHttpServletResponseInterface& resp,
     eHttpRequestMethod requestMethod=e_HTTP_REQUEST_METHOD_NONE)
    {
        cWriterInterface& writer = resp.GetWriter();
        eError error = e_ERROR_NONE;
        resp.SetContentType("text/xml");
        writer.Write("<b>Hello</b>");
        return error;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHELLOHTTPSERVLET_MEMBERS_ONLY) 
#endif // !defined(CHELLOHTTPSERVLET_MEMBERS_ONLY) 

#endif // !defined(_CHELLOHTTPSERVLET_HPP) || defined(CHELLOHTTPSERVLET_MEMBERS_ONLY) 
        

