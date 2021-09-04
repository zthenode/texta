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
//   File: cPThreadConditionInterface.hpp
//
// Author: $author$
//   Date: 5/30/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CPTHREADCONDITIONINTERFACE_HPP) || defined(CPTHREADCONDITIONINTERFACE_MEMBERS_ONLY)
#if !defined(_CPTHREADCONDITIONINTERFACE_HPP) && !defined(CPTHREADCONDITIONINTERFACE_MEMBERS_ONLY)
#define _CPTHREADCONDITIONINTERFACE_HPP
#endif // !defined(_CPTHREADCONDITIONINTERFACE_HPP) && !defined(CPTHREADCONDITIONINTERFACE_MEMBERS_ONLY) 

#if !defined(CPTHREADCONDITIONINTERFACE_MEMBERS_ONLY)
#include "cConditionInterface.hpp"
#include "cplatform_pthread.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cPThreadConditionInterfaceImplements
//
//  Author: $author$
//    Date: 5/30/2011
///////////////////////////////////////////////////////////////////////
typedef cConditionInterface
cPThreadConditionInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cPThreadConditionInterface
//
// Author: $author$
//   Date: 5/30/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cPThreadConditionInterface
: virtual public cPThreadConditionInterfaceImplements
{
public:
    typedef cPThreadConditionInterfaceImplements cImplements;
#else // !defined(CPTHREADCONDITIONINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CPTHREADCONDITIONINTERFACE_MEMBERS_ONLY) 

#if !defined(CPTHREADCONDITIONINTERFACE_MEMBERS_ONLY)
// include cPThreadCondition member functions interface
//
#define CPTHREADCONDITION_MEMBERS_ONLY
#define CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE
#include "cPThreadCondition.hpp"
#undef CPTHREADCONDITION_MEMBER_FUNCS_INTERFACE
#undef CPTHREADCONDITION_MEMBERS_ONLY
};

#if !defined(CPTHREADCONDITIONIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cPThreadConditionImplementImplement
//
//  Author: $author$
//    Date: 5/30/2011
///////////////////////////////////////////////////////////////////////
typedef cConditionImplement
cPThreadConditionImplementImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cPThreadConditionImplement
//
// Author: $author$
//   Date: 5/30/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cPThreadConditionImplement
: virtual public cPThreadConditionInterface,
  virtual public cPThreadConditionImplementImplement
{
public:
    typedef cPThreadConditionInterface cImplements;
#else // !defined(CPTHREADCONDITIONIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CPTHREADCONDITIONIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CPTHREADCONDITIONIMPLEMENT_MEMBERS_ONLY)
// include cPThreadCondition member functions implement
//
#define CPTHREADCONDITION_MEMBERS_ONLY
#define CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT
#include "cPThreadCondition.hpp"
#undef CPTHREADCONDITION_MEMBER_FUNCS_IMPLEMENT
#undef CPTHREADCONDITION_MEMBERS_ONLY
};

#else // !defined(CPTHREADCONDITIONIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CPTHREADCONDITIONIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CPTHREADCONDITIONINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CPTHREADCONDITIONINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CPTHREADCONDITIONINTERFACE_HPP) || defined(CPTHREADCONDITIONINTERFACE_MEMBERS_ONLY) 
        

