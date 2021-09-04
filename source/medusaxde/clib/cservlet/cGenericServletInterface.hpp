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
//   File: cGenericServletInterface.hpp
//
// Author: $author$
//   Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CGENERICSERVLETINTERFACE_HPP) || defined(CGENERICSERVLETINTERFACE_MEMBERS_ONLY)
#if !defined(_CGENERICSERVLETINTERFACE_HPP) && !defined(CGENERICSERVLETINTERFACE_MEMBERS_ONLY)
#define _CGENERICSERVLETINTERFACE_HPP
#endif // !defined(_CGENERICSERVLETINTERFACE_HPP) && !defined(CGENERICSERVLETINTERFACE_MEMBERS_ONLY) 

#if !defined(CGENERICSERVLETINTERFACE_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cGenericServletInterfaceImplements
//
//  Author: $author$
//    Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cGenericServletInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cGenericServletInterface
//
// Author: $author$
//   Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cGenericServletInterface
: virtual public cGenericServletInterfaceImplements
{
public:
    typedef cGenericServletInterfaceImplements cImplements;
#else // !defined(CGENERICSERVLETINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CGENERICSERVLETINTERFACE_MEMBERS_ONLY) 

#if !defined(CGENERICSERVLETINTERFACE_MEMBERS_ONLY)
// include cGenericServlet member functions interface
//
#define CGENERICSERVLET_MEMBERS_ONLY
#define CGENERICSERVLET_MEMBER_FUNCS_INTERFACE
#include "cGenericServlet.hpp"
#undef CGENERICSERVLET_MEMBER_FUNCS_INTERFACE
#undef CGENERICSERVLET_MEMBERS_ONLY
};

#if !defined(CGENERICSERVLETIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cGenericServletImplement
//
// Author: $author$
//   Date: 10/15/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cGenericServletImplement
: virtual public cGenericServletInterface
{
public:
    typedef cGenericServletInterface cImplements;
#else // !defined(CGENERICSERVLETIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CGENERICSERVLETIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CGENERICSERVLETIMPLEMENT_MEMBERS_ONLY)
// include cGenericServlet member functions implement
//
#define CGENERICSERVLET_MEMBERS_ONLY
#define CGENERICSERVLET_MEMBER_FUNCS_IMPLEMENT
#include "cGenericServlet.hpp"
#undef CGENERICSERVLET_MEMBER_FUNCS_IMPLEMENT
#undef CGENERICSERVLET_MEMBERS_ONLY
};
#else // !defined(CGENERICSERVLETIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CGENERICSERVLETIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CGENERICSERVLETINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CGENERICSERVLETINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CGENERICSERVLETINTERFACE_HPP) || defined(CGENERICSERVLETINTERFACE_MEMBERS_ONLY) 
        

