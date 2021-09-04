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
//   File: cPThreadInterface.hpp
//
// Author: $author$
//   Date: 6/16/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CPTHREADINTERFACE_HPP) || defined(CPTHREADINTERFACE_MEMBERS_ONLY)
#if !defined(_CPTHREADINTERFACE_HPP) && !defined(CPTHREADINTERFACE_MEMBERS_ONLY)
#define _CPTHREADINTERFACE_HPP
#endif // !defined(_CPTHREADINTERFACE_HPP) && !defined(CPTHREADINTERFACE_MEMBERS_ONLY) 

#if !defined(CPTHREADINTERFACE_MEMBERS_ONLY)
#include "cThreadInterface.hpp"
#include "cplatform_pthread.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cPThreadInterfaceImplements
//
//  Author: $author$
//    Date: 6/16/2011
///////////////////////////////////////////////////////////////////////
typedef cThreadInterface
cPThreadInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cPThreadInterface
//
// Author: $author$
//   Date: 6/16/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cPThreadInterface
: virtual public cPThreadInterfaceImplements
{
public:
    typedef cPThreadInterfaceImplements cImplements;
#else // !defined(CPTHREADINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CPTHREADINTERFACE_MEMBERS_ONLY) 

#if !defined(CPTHREADINTERFACE_MEMBERS_ONLY)
// include cPThread member functions interface
//
#define CPTHREAD_MEMBERS_ONLY
#define CPTHREAD_MEMBER_FUNCS_INTERFACE
#include "cPThread.hpp"
#undef CPTHREAD_MEMBER_FUNCS_INTERFACE
#undef CPTHREAD_MEMBERS_ONLY
};

///////////////////////////////////////////////////////////////////////
// Typedef: cPThreadImplementImplements
//
//  Author: $author$
//    Date: 6/16/2011
///////////////////////////////////////////////////////////////////////
typedef cThreadImplement
cPThreadImplementImplements;

#if !defined(CPTHREADIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cPThreadImplement
//
// Author: $author$
//   Date: 6/16/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cPThreadImplement
: virtual public cPThreadInterface,
  virtual public cPThreadImplementImplements
{
public:
    typedef cPThreadImplementImplements cImplements;
#else // !defined(CPTHREADIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CPTHREADIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CPTHREADIMPLEMENT_MEMBERS_ONLY)
// include cPThread interface member definitions
//
#define CPTHREADINTERFACE_MEMBERS_ONLY
#include "cPThreadInterface.hpp"
#undef CPTHREADINTERFACE_MEMBERS_ONLY

// include cPThread member functions implement
//
#define CPTHREAD_MEMBERS_ONLY
#define CPTHREAD_MEMBER_FUNCS_IMPLEMENT
#include "cPThread.hpp"
#undef CPTHREAD_MEMBER_FUNCS_IMPLEMENT
#undef CPTHREAD_MEMBERS_ONLY
};
#else // !defined(CPTHREADIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CPTHREADIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CPTHREADINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CPTHREADINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CPTHREADINTERFACE_HPP) || defined(CPTHREADINTERFACE_MEMBERS_ONLY) 
        

