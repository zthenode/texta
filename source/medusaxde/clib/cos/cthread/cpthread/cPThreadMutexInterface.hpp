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
//   File: cPThreadMutexInterface.hpp
//
// Author: $author$
//   Date: 5/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CPTHREADMUTEXINTERFACE_HPP) || defined(CPTHREADMUTEXINTERFACE_MEMBERS_ONLY)
#if !defined(_CPTHREADMUTEXINTERFACE_HPP) && !defined(CPTHREADMUTEXINTERFACE_MEMBERS_ONLY)
#define _CPTHREADMUTEXINTERFACE_HPP
#endif // !defined(_CPTHREADMUTEXINTERFACE_HPP) && !defined(CPTHREADMUTEXINTERFACE_MEMBERS_ONLY) 

#if !defined(CPTHREADMUTEXINTERFACE_MEMBERS_ONLY)
#include "cMutexInterface.hpp"
#include "cplatform_pthread.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cPThreadMutexInterfaceImplements
//
//  Author: $author$
//    Date: 5/25/2011
///////////////////////////////////////////////////////////////////////
typedef cMutexInterface
cPThreadMutexInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cPThreadMutexInterface
//
// Author: $author$
//   Date: 5/25/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cPThreadMutexInterface
: virtual public cPThreadMutexInterfaceImplements
{
public:
    typedef cPThreadMutexInterfaceImplements cImplements;
#else // !defined(CPTHREADMUTEXINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CPTHREADMUTEXINTERFACE_MEMBERS_ONLY) 

#if !defined(CPTHREADMUTEXINTERFACE_MEMBERS_ONLY)
// include cPThreadMutex member functions interface
//
#define CPTHREADMUTEX_MEMBERS_ONLY
#define CPTHREADMUTEX_MEMBER_FUNCS_INTERFACE
#include "cPThreadMutex.hpp"
#undef CPTHREADMUTEX_MEMBER_FUNCS_INTERFACE
#undef CPTHREADMUTEX_MEMBERS_ONLY
};

#if !defined(CPTHREADMUTEXIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cPThreadMutexImplement
//
// Author: $author$
//   Date: 5/25/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cPThreadMutexImplement
: virtual public cPThreadMutexInterface,
  virtual public cMutexImplement
{
public:
    typedef cPThreadMutexInterface cImplements;
#else // !defined(CPTHREADMUTEXIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CPTHREADMUTEXIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CPTHREADMUTEXIMPLEMENT_MEMBERS_ONLY)
// include cPThreadMutex interface member definitions
//
#define CPTHREADMUTEXINTERFACE_MEMBERS_ONLY
#include "cPThreadMutexInterface.hpp"
#undef CPTHREADMUTEXINTERFACE_MEMBERS_ONLY

// include cPThreadMutex member functions implement
//
#define CPTHREADMUTEX_MEMBERS_ONLY
#define CPTHREADMUTEX_MEMBER_FUNCS_IMPLEMENT
#include "cPThreadMutex.hpp"
#undef CPTHREADMUTEX_MEMBER_FUNCS_IMPLEMENT
#undef CPTHREADMUTEX_MEMBERS_ONLY
};
#else // !defined(CPTHREADMUTEXIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CPTHREADMUTEXIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CPTHREADMUTEXINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CPTHREADMUTEXINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CPTHREADMUTEXINTERFACE_HPP) || defined(CPTHREADMUTEXINTERFACE_MEMBERS_ONLY) 

