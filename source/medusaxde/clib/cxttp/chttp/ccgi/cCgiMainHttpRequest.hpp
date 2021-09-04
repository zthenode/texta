///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2012 $organization$
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
//   File: cCgiMainHttpRequest.hpp
//
// Author: $author$
//   Date: 11/23/2012
///////////////////////////////////////////////////////////////////////
#ifndef _CCGIMAINHTTPREQUEST_HPP
#define _CCGIMAINHTTPREQUEST_HPP

#include "cCgiMain.hpp"
#include "cHttpRequest.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiMainHttpRequestImplement
//
//  Author: $author$
//    Date: 11/23/2012
///////////////////////////////////////////////////////////////////////
typedef cHttpRequestImplement
cCgiMainHttpRequestImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cCgiMainHttpRequestExtend
//
//  Author: $author$
//    Date: 11/23/2012
///////////////////////////////////////////////////////////////////////
typedef cHttpRequest
cCgiMainHttpRequestExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiMainHttpRequest
//
// Author: $author$
//   Date: 11/23/2012
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cCgiMainHttpRequest
: virtual public cCgiMainHttpRequestImplement,
  public cCgiMainHttpRequestExtend
{
public:
    typedef cCgiMainHttpRequestImplement cImplements;
    typedef cCgiMainHttpRequestExtend cExtends;

    cCgiMain& m_cgiMain;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgiMainHttpRequest
    //
    //       Author: $author$
    //         Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    cCgiMainHttpRequest
    (cCgiMain& cgiMain)
    : m_cgiMain(cgiMain)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCgiMainHttpRequest
    //
    //      Author: $author$
    //        Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCgiMainHttpRequest()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetRequestMethod
    //
    //    Author: $author$
    //      Date: 11/23/2012
    ///////////////////////////////////////////////////////////////////////
    virtual eHttpRequestMethod GetRequestMethod() const
    {
        eHttpRequestMethod requestMethod = m_cgiMain.GetCgiRequestMethod();
        return requestMethod;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CCGIMAINHTTPREQUEST_HPP 
        

