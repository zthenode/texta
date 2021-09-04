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
//   File: cMutexInterface.hpp
//
// Author: $author$
//   Date: 3/19/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CMUTEXINTERFACE_HPP) || defined(CMUTEXINTERFACE_MEMBERS_ONLY)
#if !defined(_CMUTEXINTERFACE_HPP) && !defined(CMUTEXINTERFACE_MEMBERS_ONLY)
#define _CMUTEXINTERFACE_HPP
#endif // !defined(_CMUTEXINTERFACE_HPP) && !defined(CMUTEXINTERFACE_MEMBERS_ONLY) 

#if !defined(CMUTEXINTERFACE_MEMBERS_ONLY)
#include "cWaitInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cMutexInterfaceImplement
//
//  Author: $author$
//    Date: 3/19/2011
///////////////////////////////////////////////////////////////////////
typedef cWaitInterface
cMutexInterfaceImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cMutexInterface
//
// Author: $author$
//   Date: 3/19/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cMutexInterface
: virtual public cMutexInterfaceImplement
{
public:
    typedef cMutexInterfaceImplement cImplements;
#else // !defined(CMUTEXINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CMUTEXINTERFACE_MEMBERS_ONLY) 

#if !defined(CMUTEXINTERFACE_MEMBERS_ONLY)
// include cMutexBase member functions interface
//
#define CMUTEXBASE_MEMBERS_ONLY
#define CMUTEXBASE_MEMBER_FUNCS_INTERFACE
#include "cMutexBase.hpp"
#undef CMUTEXBASE_MEMBER_FUNCS_INTERFACE
#undef CMUTEXBASE_MEMBERS_ONLY
};

#if !defined(CMUTEXIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cMutexImplement
//
// Author: $author$
//   Date: 3/19/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cMutexImplement
: virtual public cMutexInterface
{
public:
    typedef cMutexInterface cImplements;
#else // !defined(CMUTEXIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CMUTEXIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CMUTEXIMPLEMENT_MEMBERS_ONLY)
// include cMutexBase member functions implement
// 
#define CMUTEXBASE_MEMBERS_ONLY
#define CMUTEXBASE_MEMBER_FUNCS_IMPLEMENT
#include "cMutexBase.hpp"
#undef CMUTEXBASE_MEMBER_FUNCS_IMPLEMENT
#undef CMUTEXBASE_MEMBERS_ONLY
};
#else // !defined(CMUTEXIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CMUTEXIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CMUTEXINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CMUTEXINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CMUTEXINTERFACE_HPP) || defined(CMUTEXINTERFACE_MEMBERS_ONLY) 
