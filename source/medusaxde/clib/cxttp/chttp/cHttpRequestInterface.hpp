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
//   File: cHttpRequestInterface.hpp
//
// Author: $author$
//   Date: 10/29/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPREQUESTINTERFACE_HPP) || defined(CHTTPREQUESTINTERFACE_MEMBERS_ONLY)
#if !defined(_CHTTPREQUESTINTERFACE_HPP) && !defined(CHTTPREQUESTINTERFACE_MEMBERS_ONLY)
#define _CHTTPREQUESTINTERFACE_HPP
#endif // !defined(_CHTTPREQUESTINTERFACE_HPP) && !defined(CHTTPREQUESTINTERFACE_MEMBERS_ONLY) 

#if !defined(CHTTPREQUESTINTERFACE_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"
#include "cHttpRequestMethod.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpRequestInterfaceImplements
//
//  Author: $author$
//    Date: 10/29/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cHttpRequestInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpRequestInterface
//
// Author: $author$
//   Date: 10/29/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cHttpRequestInterface
: virtual public cHttpRequestInterfaceImplements
{
public:
    typedef cHttpRequestInterfaceImplements cImplements;
#else // !defined(CHTTPREQUESTINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CHTTPREQUESTINTERFACE_MEMBERS_ONLY) 

#if !defined(CHTTPREQUESTINTERFACE_MEMBERS_ONLY)
// include cHttpRequest member functions interface
//
#define CHTTPREQUEST_MEMBERS_ONLY
#define CHTTPREQUEST_MEMBER_FUNCS_INTERFACE
#include "cHttpRequest.hpp"
#undef CHTTPREQUEST_MEMBER_FUNCS_INTERFACE
#undef CHTTPREQUEST_MEMBERS_ONLY
};

#if !defined(CHTTPREQUESTIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cHttpRequestImplement
//
// Author: $author$
//   Date: 10/29/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cHttpRequestImplement
: virtual public cHttpRequestInterface
{
public:
    typedef cHttpRequestInterface cImplements;
#else // !defined(CHTTPREQUESTIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CHTTPREQUESTIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CHTTPREQUESTIMPLEMENT_MEMBERS_ONLY)
// include cHttpRequest member functions implement
//
#define CHTTPREQUEST_MEMBERS_ONLY
#define CHTTPREQUEST_MEMBER_FUNCS_IMPLEMENT
#include "cHttpRequest.hpp"
#undef CHTTPREQUEST_MEMBER_FUNCS_IMPLEMENT
#undef CHTTPREQUEST_MEMBERS_ONLY
};
#else // !defined(CHTTPREQUESTIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CHTTPREQUESTIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPREQUESTINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CHTTPREQUESTINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CHTTPREQUESTINTERFACE_HPP) || defined(CHTTPREQUESTINTERFACE_MEMBERS_ONLY) 
        

