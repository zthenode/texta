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
//   File: cPThreadSemaphoreInterface.hpp
//
// Author: $author$
//   Date: 5/26/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CPTHREADSEMAPHOREINTERFACE_HPP) || defined(CPTHREADSEMAPHOREINTERFACE_MEMBERS_ONLY)
#if !defined(_CPTHREADSEMAPHOREINTERFACE_HPP) && !defined(CPTHREADSEMAPHOREINTERFACE_MEMBERS_ONLY)
#define _CPTHREADSEMAPHOREINTERFACE_HPP
#endif // !defined(_CPTHREADSEMAPHOREINTERFACE_HPP) && !defined(CPTHREADSEMAPHOREINTERFACE_MEMBERS_ONLY) 

#if !defined(CPTHREADSEMAPHOREINTERFACE_MEMBERS_ONLY)
#include "cSemaphoreInterface.hpp"
#include "cplatform_semaphore.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cPThreadSemaphoreInterfaceImplements
//
//  Author: $author$
//    Date: 5/26/2011
///////////////////////////////////////////////////////////////////////
typedef cSemaphoreInterface
cPThreadSemaphoreInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cPThreadSemaphoreInterface
//
// Author: $author$
//   Date: 5/26/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cPThreadSemaphoreInterface
: virtual public cPThreadSemaphoreInterfaceImplements
{
public:
    typedef cPThreadSemaphoreInterfaceImplements cImplements;
#else // !defined(CPTHREADSEMAPHOREINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CPTHREADSEMAPHOREINTERFACE_MEMBERS_ONLY) 

#if !defined(CPTHREADSEMAPHOREINTERFACE_MEMBERS_ONLY)
// include cPThreadSemaphore member functions interface
//
#define CPTHREADSEMAPHORE_MEMBERS_ONLY
#define CPTHREADSEMAPHORE_MEMBER_FUNCS_INTERFACE
#include "cPThreadSemaphore.hpp"
#undef CPTHREADSEMAPHORE_MEMBER_FUNCS_INTERFACE
#undef CPTHREADSEMAPHORE_MEMBERS_ONLY
};

#if !defined(CPTHREADSEMAPHOREIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cPThreadSemaphoreImplementImplements
//
//  Author: $author$
//    Date: 5/26/2011
///////////////////////////////////////////////////////////////////////
typedef cSemaphoreImplement
cPThreadSemaphoreImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cPThreadSemaphoreImplement
//
// Author: $author$
//   Date: 5/26/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cPThreadSemaphoreImplement
: virtual public cPThreadSemaphoreInterface,
  virtual public cPThreadSemaphoreImplementImplements
{
public:
    typedef cPThreadSemaphoreInterface cImplements;
#else // !defined(CPTHREADSEMAPHOREIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CPTHREADSEMAPHOREIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CPTHREADSEMAPHOREIMPLEMENT_MEMBERS_ONLY)
// include cPThreadSemaphore member functions implement
//
#define CPTHREADSEMAPHORE_MEMBERS_ONLY
#define CPTHREADSEMAPHORE_MEMBER_FUNCS_IMPLEMENT
#include "cPThreadSemaphore.hpp"
#undef CPTHREADSEMAPHORE_MEMBER_FUNCS_IMPLEMENT
#undef CPTHREADSEMAPHORE_MEMBERS_ONLY
};
#else // !defined(CPTHREADSEMAPHOREIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CPTHREADSEMAPHOREIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CPTHREADSEMAPHOREINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CPTHREADSEMAPHOREINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CPTHREADSEMAPHOREINTERFACE_HPP) || defined(CPTHREADSEMAPHOREINTERFACE_MEMBERS_ONLY) 

