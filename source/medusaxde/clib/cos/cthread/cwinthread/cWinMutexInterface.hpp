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
//   File: cWinMutexInterface.hpp
//
// Author: $author$
//   Date: 6/3/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWINMUTEXINTERFACE_HPP) || defined(CWINMUTEXINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINMUTEXINTERFACE_HPP) && !defined(CWINMUTEXINTERFACE_MEMBERS_ONLY)
#define _CWINMUTEXINTERFACE_HPP
#endif // !defined(_CWINMUTEXINTERFACE_HPP) && !defined(CWINMUTEXINTERFACE_MEMBERS_ONLY) 

#if !defined(CWINMUTEXINTERFACE_MEMBERS_ONLY)
#include "cMutexInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWinMutexInterfaceImplements
//
//  Author: $author$
//    Date: 6/3/2011
///////////////////////////////////////////////////////////////////////
typedef cMutexInterface
cWinMutexInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWinMutexInterface
//
// Author: $author$
//   Date: 6/3/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cWinMutexInterface
: virtual public cWinMutexInterfaceImplements
{
public:
    typedef cWinMutexInterfaceImplements cImplements;
#else // !defined(CWINMUTEXINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWINMUTEXINTERFACE_MEMBERS_ONLY) 

#if !defined(CWINMUTEXINTERFACE_MEMBERS_ONLY)
// include cWinMutex member functions interface
//
#define CWINMUTEX_MEMBERS_ONLY
#define CWINMUTEX_MEMBER_FUNCS_INTERFACE
#include "cWinMutex.hpp"
#undef CWINMUTEX_MEMBER_FUNCS_INTERFACE
#undef CWINMUTEX_MEMBERS_ONLY
};

#if !defined(CWINMUTEXIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cWinMutexImplementImplements
//
//  Author: $author$
//    Date: 6/3/2011
///////////////////////////////////////////////////////////////////////
typedef cMutexImplement
cWinMutexImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWinMutexImplement
//
// Author: $author$
//   Date: 6/3/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cWinMutexImplement
: virtual public cWinMutexInterface,
  virtual public cWinMutexImplementImplements
{
public:
    typedef cWinMutexInterface cImplements;
#else // !defined(CWINMUTEXIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWINMUTEXIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CWINMUTEXIMPLEMENT_MEMBERS_ONLY)
// include cWinMutex member functions implement
//
#define CWINMUTEX_MEMBERS_ONLY
#define CWINMUTEX_MEMBER_FUNCS_IMPLEMENT
#include "cWinMutex.hpp"
#undef CWINMUTEX_MEMBER_FUNCS_IMPLEMENT
#undef CWINMUTEX_MEMBERS_ONLY
};
#else // !defined(CWINMUTEXIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWINMUTEXIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWINMUTEXINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWINMUTEXINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CWINMUTEXINTERFACE_HPP) || defined(CWINMUTEXINTERFACE_MEMBERS_ONLY) 
        

