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
//   File: cHttpServletRequestInterface.hpp
//
// Author: $author$
//   Date: 10/26/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPSERVLETREQUESTINTERFACE_HPP) || defined(CHTTPSERVLETREQUESTINTERFACE_MEMBERS_ONLY)
#if !defined(_CHTTPSERVLETREQUESTINTERFACE_HPP) && !defined(CHTTPSERVLETREQUESTINTERFACE_MEMBERS_ONLY)
#define _CHTTPSERVLETREQUESTINTERFACE_HPP
#endif // !defined(_CHTTPSERVLETREQUESTINTERFACE_HPP) && !defined(CHTTPSERVLETREQUESTINTERFACE_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETREQUESTINTERFACE_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpServletRequestInterfaceImplements
//
//  Author: $author$
//    Date: 10/26/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cHttpServletRequestInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletRequestInterface
//
// Author: $author$
//   Date: 10/26/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cHttpServletRequestInterface
: virtual public cHttpServletRequestInterfaceImplements
{
public:
    typedef cHttpServletRequestInterfaceImplements cImplements;
#else // !defined(CHTTPSERVLETREQUESTINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETREQUESTINTERFACE_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETREQUESTINTERFACE_MEMBERS_ONLY)
// include cHttpServletRequest member functions interface
//
#define CHTTPSERVLETREQUEST_MEMBERS_ONLY
#define CHTTPSERVLETREQUEST_MEMBER_FUNCS_INTERFACE
#include "cHttpServletRequest.hpp"
#undef CHTTPSERVLETREQUEST_MEMBER_FUNCS_INTERFACE
#undef CHTTPSERVLETREQUEST_MEMBERS_ONLY
};

#if !defined(CHTTPSERVLETREQUESTIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cHttpServletRequestImplement
//
// Author: $author$
//   Date: 10/26/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cHttpServletRequestImplement
: virtual public cHttpServletRequestInterface
{
public:
    typedef cHttpServletRequestInterface cImplements;
#else // !defined(CHTTPSERVLETREQUESTIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETREQUESTIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CHTTPSERVLETREQUESTIMPLEMENT_MEMBERS_ONLY)
// include cHttpServletRequest member functions implement
//
#define CHTTPSERVLETREQUEST_MEMBERS_ONLY
#define CHTTPSERVLETREQUEST_MEMBER_FUNCS_IMPLEMENT
#include "cHttpServletRequest.hpp"
#undef CHTTPSERVLETREQUEST_MEMBER_FUNCS_IMPLEMENT
#undef CHTTPSERVLETREQUEST_MEMBERS_ONLY
};
#else // !defined(CHTTPSERVLETREQUESTIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETREQUESTIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPSERVLETREQUESTINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CHTTPSERVLETREQUESTINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CHTTPSERVLETREQUESTINTERFACE_HPP) || defined(CHTTPSERVLETREQUESTINTERFACE_MEMBERS_ONLY) 
        

