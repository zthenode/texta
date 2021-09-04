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
//   File: cWinCrtThreadInterface.hpp
//
// Author: $author$
//   Date: 6/21/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWINCRTTHREADINTERFACE_HPP) || defined(CWINCRTTHREADINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINCRTTHREADINTERFACE_HPP) && !defined(CWINCRTTHREADINTERFACE_MEMBERS_ONLY)
#define _CWINCRTTHREADINTERFACE_HPP
#endif // !defined(_CWINCRTTHREADINTERFACE_HPP) && !defined(CWINCRTTHREADINTERFACE_MEMBERS_ONLY) 

#if !defined(CWINCRTTHREADINTERFACE_MEMBERS_ONLY)
#include "cWinThreadInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWinCrtThreadInterfaceImplements
//
//  Author: $author$
//    Date: 6/21/2011
///////////////////////////////////////////////////////////////////////
typedef cWinThreadInterface
cWinCrtThreadInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWinCrtThreadInterface
//
// Author: $author$
//   Date: 6/21/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cWinCrtThreadInterface
: virtual public cWinCrtThreadInterfaceImplements
{
public:
    typedef cWinCrtThreadInterfaceImplements cImplements;
#else // !defined(CWINCRTTHREADINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWINCRTTHREADINTERFACE_MEMBERS_ONLY) 

#if !defined(CWINCRTTHREADINTERFACE_MEMBERS_ONLY)
// include cWinCrtThread member functions interface
//
#define CWINCRTTHREAD_MEMBERS_ONLY
#define CWINCRTTHREAD_MEMBER_FUNCS_INTERFACE
#include "cWinCrtThread.hpp"
#undef CWINCRTTHREAD_MEMBER_FUNCS_INTERFACE
#undef CWINCRTTHREAD_MEMBERS_ONLY
};

#if !defined(CWINCRTTHREADIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cWinCrtThreadImplementImplements
//
//  Author: $author$
//    Date: 6/21/2011
///////////////////////////////////////////////////////////////////////
typedef cWinThreadImplement
cWinCrtThreadImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWinCrtThreadImplement
//
// Author: $author$
//   Date: 6/21/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cWinCrtThreadImplement
: virtual public cWinCrtThreadInterface,
  virtual public cWinCrtThreadImplementImplements
{
public:
    typedef cWinCrtThreadImplementImplements cImplements;
#else // !defined(CWINCRTTHREADIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWINCRTTHREADIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CWINCRTTHREADIMPLEMENT_MEMBERS_ONLY)
// include cWinCrtThread interface member definitions
//
#define CWINCRTTHREADINTERFACE_MEMBERS_ONLY
#include "cWinCrtThreadInterface.hpp"
#undef CWINCRTTHREADINTERFACE_MEMBERS_ONLY

// include cWinCrtThread member functions implement
//
#define CWINCRTTHREAD_MEMBERS_ONLY
#define CWINCRTTHREAD_MEMBER_FUNCS_IMPLEMENT
#include "cWinCrtThread.hpp"
#undef CWINCRTTHREAD_MEMBER_FUNCS_IMPLEMENT
#undef CWINCRTTHREAD_MEMBERS_ONLY
};
#else // !defined(CWINCRTTHREADIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWINCRTTHREADIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWINCRTTHREADINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWINCRTTHREADINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CWINCRTTHREADINTERFACE_HPP) || defined(CWINCRTTHREADINTERFACE_MEMBERS_ONLY) 
