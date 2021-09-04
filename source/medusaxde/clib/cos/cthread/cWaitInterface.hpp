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
//   File: cWaitInterface.hpp
//
// Author: $author$
//   Date: 3/19/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWAITINTERFACE_HPP) || defined(CWAITINTERFACE_MEMBERS_ONLY)
#if !defined(_CWAITINTERFACE_HPP) && !defined(CWAITINTERFACE_MEMBERS_ONLY)
#define _CWAITINTERFACE_HPP
#endif // !defined(_CWAITINTERFACE_HPP) && !defined(CWAITINTERFACE_MEMBERS_ONLY) 

#if !defined(CWAITINTERFACE_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"
#include "cplatform_time.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWaitInterfaceImplement
//
//  Author: $author$
//    Date: 3/19/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cWaitInterfaceImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cWaitInterface
//
// Author: $author$
//   Date: 3/19/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cWaitInterface
: virtual public cWaitInterfaceImplement
{
public:
    typedef cWaitInterfaceImplement cImplements;
#else // !defined(CWAITINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWAITINTERFACE_MEMBERS_ONLY) 

#if !defined(CWAITINTERFACE_MEMBERS_ONLY)
};

#if !defined(CWAITIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cWaitImplement
//
// Author: $author$
//   Date: 3/19/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cWaitImplement
: virtual public cWaitInterface
{
public:
    typedef cWaitInterface cImplements;
#else // !defined(CWAITIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWAITIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CWAITIMPLEMENT_MEMBERS_ONLY)
};
#else // !defined(CWAITIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWAITIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWAITINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWAITINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CWAITINTERFACE_HPP) || defined(CWAITINTERFACE_MEMBERS_ONLY)

