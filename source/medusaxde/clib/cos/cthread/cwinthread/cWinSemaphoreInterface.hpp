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
//   File: cWinSemaphoreInterface.hpp
//
// Author: $author$
//   Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWINSEMAPHOREINTERFACE_HPP) || defined(CWINSEMAPHOREINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINSEMAPHOREINTERFACE_HPP) && !defined(CWINSEMAPHOREINTERFACE_MEMBERS_ONLY)
#define _CWINSEMAPHOREINTERFACE_HPP
#endif // !defined(_CWINSEMAPHOREINTERFACE_HPP) && !defined(CWINSEMAPHOREINTERFACE_MEMBERS_ONLY) 

#if !defined(CWINSEMAPHOREINTERFACE_MEMBERS_ONLY)
#include "cSemaphoreInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWinSemaphoreInterfaceImplements
//
//  Author: $author$
//    Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
typedef cSemaphoreInterface
cWinSemaphoreInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWinSemaphoreInterface
//
// Author: $author$
//   Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cWinSemaphoreInterface
: virtual public cWinSemaphoreInterfaceImplements
{
public:
    typedef cWinSemaphoreInterfaceImplements cImplements;
#else // !defined(CWINSEMAPHOREINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWINSEMAPHOREINTERFACE_MEMBERS_ONLY) 

#if !defined(CWINSEMAPHOREINTERFACE_MEMBERS_ONLY)
// include cWinSemaphore member functions interface
//
#define CWINSEMAPHORE_MEMBERS_ONLY
#define CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE
#include "cWinSemaphore.hpp"
#undef CWINSEMAPHORE_MEMBER_FUNCS_INTERFACE
#undef CWINSEMAPHORE_MEMBERS_ONLY
};

#if !defined(CWINSEMAPHOREIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cWinSemaphoreImplementImplements
//
//  Author: $author$
//    Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
typedef cSemaphoreImplement
cWinSemaphoreImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWinSemaphoreImplement
//
// Author: $author$
//   Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cWinSemaphoreImplement
: virtual public cWinSemaphoreInterface,
  virtual public cWinSemaphoreImplementImplements
{
public:
    typedef cWinSemaphoreImplementImplements cImplements;
#else // !defined(CWINSEMAPHOREIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWINSEMAPHOREIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CWINSEMAPHOREIMPLEMENT_MEMBERS_ONLY)
// include cWinSemaphore interface member definitions
//
#define CWINSEMAPHOREINTERFACE_MEMBERS_ONLY
#include "cWinSemaphoreInterface.hpp"
#undef CWINSEMAPHOREINTERFACE_MEMBERS_ONLY

// include cWinSemaphore member functions implement
//
#define CWINSEMAPHORE_MEMBERS_ONLY
#define CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT
#include "cWinSemaphore.hpp"
#undef CWINSEMAPHORE_MEMBER_FUNCS_IMPLEMENT
#undef CWINSEMAPHORE_MEMBERS_ONLY
};
#else // !defined(CWINSEMAPHOREIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWINSEMAPHOREIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWINSEMAPHOREINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWINSEMAPHOREINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CWINSEMAPHOREINTERFACE_HPP) || defined(CWINSEMAPHOREINTERFACE_MEMBERS_ONLY) 
        

