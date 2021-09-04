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
//   File: cHttpRequest.hpp
//
// Author: $author$
//   Date: 10/29/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPREQUEST_HPP) || defined(CHTTPREQUEST_MEMBERS_ONLY)
#if !defined(_CHTTPREQUEST_HPP) && !defined(CHTTPREQUEST_MEMBERS_ONLY)
#define _CHTTPREQUEST_HPP
#endif // !defined(_CHTTPREQUEST_HPP) && !defined(CHTTPREQUEST_MEMBERS_ONLY) 

#if !defined(CHTTPREQUEST_MEMBERS_ONLY)
#include "cHttpRequestInterface.hpp"
#include "cInstanceBase.hpp"

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
//  Class: cHttpRequest
//
// Author: $author$
//   Date: 10/29/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cHttpRequest
: virtual public cHttpRequestImplement,
  public cHttpRequestExtend
{
public:
    typedef cHttpRequestImplement cImplements;
    typedef cHttpRequestExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpRequest
    //
    //       Author: $author$
    //         Date: 10/29/2011
    ///////////////////////////////////////////////////////////////////////
    cHttpRequest()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cHttpRequest
    //
    //      Author: $author$
    //        Date: 10/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cHttpRequest()
    {
    }
#else // !defined(CHTTPREQUEST_MEMBERS_ONLY) 
#endif // !defined(CHTTPREQUEST_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetRequestMethod
    //
    //    Author: $author$
    //      Date: 10/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eHttpRequestMethod GetRequestMethod() const
#if defined(CHTTPREQUEST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPREQUEST_MEMBER_FUNCS_INTERFACE) 
    {
        eHttpRequestMethod requestMethod = e_HTTP_REQUEST_METHOD_NONE;
#if !defined(CHTTPREQUEST_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CHTTPREQUEST_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPREQUEST_MEMBER_FUNCS_IMPLEMENT) 
        return requestMethod;
    }
#endif // defined(CHTTPREQUEST_MEMBER_FUNCS_INTERFACE) 

#if !defined(CHTTPREQUEST_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPREQUEST_MEMBERS_ONLY) 
#endif // !defined(CHTTPREQUEST_MEMBERS_ONLY) 

#endif // !defined(_CHTTPREQUEST_HPP) || defined(CHTTPREQUEST_MEMBERS_ONLY) 
        

