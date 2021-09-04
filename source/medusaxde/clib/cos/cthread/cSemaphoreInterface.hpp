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
//   File: cSemaphoreInterface.hpp
//
// Author: $author$
//   Date: 5/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CSEMAPHOREINTERFACE_HPP) || defined(CSEMAPHOREINTERFACE_MEMBERS_ONLY)
#if !defined(_CSEMAPHOREINTERFACE_HPP) && !defined(CSEMAPHOREINTERFACE_MEMBERS_ONLY)
#define _CSEMAPHOREINTERFACE_HPP
#endif // !defined(_CSEMAPHOREINTERFACE_HPP) && !defined(CSEMAPHOREINTERFACE_MEMBERS_ONLY) 

#if !defined(CSEMAPHOREINTERFACE_MEMBERS_ONLY)
#include "cWaitInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cSemaphoreInterfaceImplements
//
//  Author: $author$
//    Date: 5/25/2011
///////////////////////////////////////////////////////////////////////
typedef cWaitInterface
cSemaphoreInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cSemaphoreInterface
//
// Author: $author$
//   Date: 5/25/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cSemaphoreInterface
: virtual public cSemaphoreInterfaceImplements
{
public:
    typedef cSemaphoreInterfaceImplements cImplements;
#else // !defined(CSEMAPHOREINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CSEMAPHOREINTERFACE_MEMBERS_ONLY) 

#if !defined(CSEMAPHOREINTERFACE_MEMBERS_ONLY)
// include cSemaphoreBase member functions interface
//
#define CSEMAPHOREBASE_MEMBERS_ONLY
#define CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE
#include "cSemaphoreBase.hpp"
#undef CSEMAPHOREBASE_MEMBER_FUNCS_INTERFACE
#undef CSEMAPHOREBASE_MEMBERS_ONLY
};

#if !defined(CSEMAPHOREIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cSemaphoreImplementImplement
//
//  Author: $author$
//    Date: 5/25/2011
///////////////////////////////////////////////////////////////////////
typedef cWaitImplement
cSemaphoreImplementImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cSemaphoreImplement
//
// Author: $author$
//   Date: 5/25/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cSemaphoreImplement
: virtual public cSemaphoreInterface,
  virtual public cSemaphoreImplementImplement
{
public:
    typedef cSemaphoreInterface cImplements;
#else // !defined(CSEMAPHOREIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CSEMAPHOREIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CSEMAPHOREIMPLEMENT_MEMBERS_ONLY)
// include cSemaphoreBase member functions implement
//
#define CSEMAPHOREBASE_MEMBERS_ONLY
#define CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT
#include "cSemaphoreBase.hpp"
#undef CSEMAPHOREBASE_MEMBER_FUNCS_IMPLEMENT
#undef CSEMAPHOREBASE_MEMBERS_ONLY
};
#else // !defined(CSEMAPHOREIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CSEMAPHOREIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CSEMAPHOREINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CSEMAPHOREINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CSEMAPHOREINTERFACE_HPP) || defined(CSEMAPHOREINTERFACE_MEMBERS_ONLY) 

