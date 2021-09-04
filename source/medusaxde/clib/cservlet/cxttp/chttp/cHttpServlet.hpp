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
//   File: cHttpServlet.hpp
//
// Author: $author$
//   Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPSERVLET_HPP) || defined(CHTTPSERVLET_MEMBERS_ONLY)
#if !defined(_CHTTPSERVLET_HPP) && !defined(CHTTPSERVLET_MEMBERS_ONLY)
#define _CHTTPSERVLET_HPP
#endif // !defined(_CHTTPSERVLET_HPP) && !defined(CHTTPSERVLET_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLET_MEMBERS_ONLY)
#include "cHttpServletInterface.hpp"
#include "cXttpServlet.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpServletExtend
//
//  Author: $author$
//    Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
typedef cXttpServlet
cHttpServletExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServlet
//
// Author: $author$
//   Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cHttpServlet
: virtual public cHttpServletImplement,
  public cHttpServletExtend
{
public:
    typedef cHttpServletImplement cImplements;
    typedef cHttpServletExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpServlet
    //
    //       Author: $author$
    //         Date: 10/15/2011
    ///////////////////////////////////////////////////////////////////////
    cHttpServlet()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cHttpServlet
    //
    //      Author: $author$
    //        Date: 10/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cHttpServlet()
    {
    }
#else // !defined(CHTTPSERVLET_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLET_MEMBERS_ONLY) 

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
#if defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: DoGet
    //
    //    Author: $author$
    //      Date: 10/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError DoGet
    (const cHttpServletRequestInterface& req,
     cHttpServletResponseInterface& resp)
#if defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT)
        error = DoRequest(req, resp, e_HTTP_REQUEST_METHOD_GET);
#else // !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: DoPost
    //
    //    Author: $author$
    //      Date: 10/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError DoPost
    (const cHttpServletRequestInterface& req,
     cHttpServletResponseInterface& resp)
#if defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT)
        error = DoRequest(req, resp, e_HTTP_REQUEST_METHOD_POST);
#else // !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: DoPut
    //
    //    Author: $author$
    //      Date: 10/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError DoPut
    (const cHttpServletRequestInterface& req,
     cHttpServletResponseInterface& resp)
#if defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: DoDelete
    //
    //    Author: $author$
    //      Date: 10/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError DoDelete
    (const cHttpServletRequestInterface& req,
     cHttpServletResponseInterface& resp)
#if defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: DoHead
    //
    //    Author: $author$
    //      Date: 10/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError DoHead
    (const cHttpServletRequestInterface& req,
     cHttpServletResponseInterface& resp)
#if defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: DoOptions
    //
    //    Author: $author$
    //      Date: 10/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError DoOptions
    (const cHttpServletRequestInterface& req,
     cHttpServletResponseInterface& resp)
#if defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: DoTrace
    //
    //    Author: $author$
    //      Date: 10/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError DoTrace
    (const cHttpServletRequestInterface& req,
     cHttpServletResponseInterface& resp)
#if defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Service
    //
    //    Author: $author$
    //      Date: 10/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Service
    (const cHttpServletRequestInterface& req,
     cHttpServletResponseInterface& resp)
#if defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPSERVLET_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CHTTPSERVLET_MEMBER_FUNCS_INTERFACE) 

#if !defined(CHTTPSERVLET_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPSERVLET_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLET_MEMBERS_ONLY) 

#endif // !defined(_CHTTPSERVLET_HPP) || defined(CHTTPSERVLET_MEMBERS_ONLY) 
        

