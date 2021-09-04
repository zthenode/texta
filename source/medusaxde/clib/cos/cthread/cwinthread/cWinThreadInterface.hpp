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
//   File: cWinThreadInterface.hpp
//
// Author: $author$
//   Date: 6/14/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWINTHREADINTERFACE_HPP) || defined(CWINTHREADINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINTHREADINTERFACE_HPP) && !defined(CWINTHREADINTERFACE_MEMBERS_ONLY)
#define _CWINTHREADINTERFACE_HPP
#endif // !defined(_CWINTHREADINTERFACE_HPP) && !defined(CWINTHREADINTERFACE_MEMBERS_ONLY) 

#if !defined(CWINTHREADINTERFACE_MEMBERS_ONLY)
#include "cThreadInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWinThreadInterfaceImplements
//
//  Author: $author$
//    Date: 6/14/2011
///////////////////////////////////////////////////////////////////////
typedef cThreadInterface
cWinThreadInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWinThreadInterface
//
// Author: $author$
//   Date: 6/14/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cWinThreadInterface
: virtual public cWinThreadInterfaceImplements
{
public:
    typedef cWinThreadInterfaceImplements cImplements;
#else // !defined(CWINTHREADINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWINTHREADINTERFACE_MEMBERS_ONLY) 

#if !defined(CWINTHREADINTERFACE_MEMBERS_ONLY)
// include cWinThread member functions interface
//
#define CWINTHREAD_MEMBERS_ONLY
#define CWINTHREAD_MEMBER_FUNCS_INTERFACE
#include "cWinThread.hpp"
#undef CWINTHREAD_MEMBER_FUNCS_INTERFACE
#undef CWINTHREAD_MEMBERS_ONLY
};

#if !defined(CWINTHREADIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cWinThreadImplementImplements
//
//  Author: $author$
//    Date: 6/14/2011
///////////////////////////////////////////////////////////////////////
typedef cThreadImplement
cWinThreadImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWinThreadImplement
//
// Author: $author$
//   Date: 6/14/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cWinThreadImplement
: virtual public cWinThreadInterface,
  virtual public cWinThreadImplementImplements
{
public:
    typedef cWinThreadImplementImplements cImplements;
#else // !defined(CWINTHREADIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWINTHREADIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CWINTHREADIMPLEMENT_MEMBERS_ONLY)
// include cWinThread interface member definitions
//
#define CWINTHREADINTERFACE_MEMBERS_ONLY
#include "cWinThreadInterface.hpp"
#undef CWINTHREADINTERFACE_MEMBERS_ONLY

// include cWinThread member functions implement
//
#define CWINTHREAD_MEMBERS_ONLY
#define CWINTHREAD_MEMBER_FUNCS_IMPLEMENT
#include "cWinThread.hpp"
#undef CWINTHREAD_MEMBER_FUNCS_IMPLEMENT
#undef CWINTHREAD_MEMBERS_ONLY
};
#else // !defined(CWINTHREADIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWINTHREADIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWINTHREADINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWINTHREADINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CWINTHREADINTERFACE_HPP) || defined(CWINTHREADINTERFACE_MEMBERS_ONLY) 
