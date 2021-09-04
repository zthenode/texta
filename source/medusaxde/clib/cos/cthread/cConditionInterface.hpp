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
//   File: cConditionInterface.hpp
//
// Author: $author$
//   Date: 5/30/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCONDITIONINTERFACE_HPP) || defined(CCONDITIONINTERFACE_MEMBERS_ONLY)
#if !defined(_CCONDITIONINTERFACE_HPP) && !defined(CCONDITIONINTERFACE_MEMBERS_ONLY)
#define _CCONDITIONINTERFACE_HPP
#endif // !defined(_CCONDITIONINTERFACE_HPP) && !defined(CCONDITIONINTERFACE_MEMBERS_ONLY) 

#if !defined(CCONDITIONINTERFACE_MEMBERS_ONLY)
#include "cWaitInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cConditionInterfaceImplements
//
//  Author: $author$
//    Date: 5/30/2011
///////////////////////////////////////////////////////////////////////
typedef cWaitInterface
cConditionInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cConditionInterface
//
// Author: $author$
//   Date: 5/30/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cConditionInterface
: virtual public cConditionInterfaceImplements
{
public:
    typedef cConditionInterfaceImplements cImplements;
#else // !defined(CCONDITIONINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CCONDITIONINTERFACE_MEMBERS_ONLY) 

#if !defined(CCONDITIONINTERFACE_MEMBERS_ONLY)
// include cConditionBase member functions interface
//
#define CCONDITIONBASE_MEMBERS_ONLY
#define CCONDITIONBASE_MEMBER_FUNCS_INTERFACE
#include "cConditionBase.hpp"
#undef CCONDITIONBASE_MEMBER_FUNCS_INTERFACE
#undef CCONDITIONBASE_MEMBERS_ONLY
};

#if !defined(CCONDITIONIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cConditionImplementImplement
//
//  Author: $author$
//    Date: 5/30/2011
///////////////////////////////////////////////////////////////////////
typedef cWaitImplement
cConditionImplementImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cConditionImplement
//
// Author: $author$
//   Date: 5/30/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cConditionImplement
: virtual public cConditionInterface,
  virtual public cConditionImplementImplement
{
public:
    typedef cConditionInterface cImplements;
#else // !defined(CCONDITIONIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CCONDITIONIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CCONDITIONIMPLEMENT_MEMBERS_ONLY)
// include cConditionBase member functions implement
//
#define CCONDITIONBASE_MEMBERS_ONLY
#define CCONDITIONBASE_MEMBER_FUNCS_IMPLEMENT
#include "cConditionBase.hpp"
#undef CCONDITIONBASE_MEMBER_FUNCS_IMPLEMENT
#undef CCONDITIONBASE_MEMBERS_ONLY
};

#else // !defined(CCONDITIONIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CCONDITIONIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCONDITIONINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CCONDITIONINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CCONDITIONINTERFACE_HPP) || defined(CCONDITIONINTERFACE_MEMBERS_ONLY) 
        

