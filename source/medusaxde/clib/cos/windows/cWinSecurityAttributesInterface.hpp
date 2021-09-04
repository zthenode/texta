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
//   File: cWinSecurityAttributesInterface.hpp
//
// Author: $author$
//   Date: 6/12/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWINSECURITYATTRIBUTESINTERFACE_HPP) || defined(CWINSECURITYATTRIBUTESINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINSECURITYATTRIBUTESINTERFACE_HPP) && !defined(CWINSECURITYATTRIBUTESINTERFACE_MEMBERS_ONLY)
#define _CWINSECURITYATTRIBUTESINTERFACE_HPP
#endif // !defined(_CWINSECURITYATTRIBUTESINTERFACE_HPP) && !defined(CWINSECURITYATTRIBUTESINTERFACE_MEMBERS_ONLY) 

#if !defined(CWINSECURITYATTRIBUTESINTERFACE_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWinSecurityAttributesInterfaceImplements
//
//  Author: $author$
//    Date: 6/12/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cWinSecurityAttributesInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWinSecurityAttributesInterface
//
// Author: $author$
//   Date: 6/12/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cWinSecurityAttributesInterface
: virtual public cWinSecurityAttributesInterfaceImplements
{
public:
    typedef cWinSecurityAttributesInterfaceImplements cImplements;
#else // !defined(CWINSECURITYATTRIBUTESINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWINSECURITYATTRIBUTESINTERFACE_MEMBERS_ONLY) 

#if !defined(CWINSECURITYATTRIBUTESINTERFACE_MEMBERS_ONLY)
// include cWinSecurityAttributes member functions interface
//
#define CWINSECURITYATTRIBUTES_MEMBERS_ONLY
#define CWINSECURITYATTRIBUTES_MEMBER_FUNCS_INTERFACE
#include "cWinSecurityAttributes.hpp"
#undef CWINSECURITYATTRIBUTES_MEMBER_FUNCS_INTERFACE
#undef CWINSECURITYATTRIBUTES_MEMBERS_ONLY
};

#if !defined(CWINSECURITYATTRIBUTESIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cWinSecurityAttributesImplement
//
// Author: $author$
//   Date: 6/12/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cWinSecurityAttributesImplement
: virtual public cWinSecurityAttributesInterface
{
public:
    typedef cWinSecurityAttributesInterface cImplements;
#else // !defined(CWINSECURITYATTRIBUTESIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWINSECURITYATTRIBUTESIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CWINSECURITYATTRIBUTESIMPLEMENT_MEMBERS_ONLY)
// include cWinSecurityAttributes interface member definitions
//
#define CWINSECURITYATTRIBUTESINTERFACE_MEMBERS_ONLY
#include "cWinSecurityAttributesInterface.hpp"
#undef CWINSECURITYATTRIBUTESINTERFACE_MEMBERS_ONLY

// include cWinSecurityAttributes member functions implement
//
#define CWINSECURITYATTRIBUTES_MEMBERS_ONLY
#define CWINSECURITYATTRIBUTES_MEMBER_FUNCS_IMPLEMENT
#include "cWinSecurityAttributes.hpp"
#undef CWINSECURITYATTRIBUTES_MEMBER_FUNCS_IMPLEMENT
#undef CWINSECURITYATTRIBUTES_MEMBERS_ONLY
};
#else // !defined(CWINSECURITYATTRIBUTESIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWINSECURITYATTRIBUTESIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWINSECURITYATTRIBUTESINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWINSECURITYATTRIBUTESINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CWINSECURITYATTRIBUTESINTERFACE_HPP) || defined(CWINSECURITYATTRIBUTESINTERFACE_MEMBERS_ONLY) 
        

