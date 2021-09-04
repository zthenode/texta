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
//   File: cThreadInterface.hpp
//
// Author: $author$
//   Date: 6/14/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CTHREADINTERFACE_HPP) || defined(CTHREADINTERFACE_MEMBERS_ONLY)
#if !defined(_CTHREADINTERFACE_HPP) && !defined(CTHREADINTERFACE_MEMBERS_ONLY)
#define _CTHREADINTERFACE_HPP
#endif // !defined(_CTHREADINTERFACE_HPP) && !defined(CTHREADINTERFACE_MEMBERS_ONLY) 

#if !defined(CTHREADINTERFACE_MEMBERS_ONLY)
#include "cWaitInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cThreadInterfaceImplements
//
//  Author: $author$
//    Date: 6/14/2011
///////////////////////////////////////////////////////////////////////
typedef cWaitInterface
cThreadInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cThreadInterface
//
// Author: $author$
//   Date: 6/14/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cThreadInterface
: virtual public cThreadInterfaceImplements
{
public:
    typedef cThreadInterfaceImplements cImplements;
#else // !defined(CTHREADINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CTHREADINTERFACE_MEMBERS_ONLY) 

#if !defined(CTHREADINTERFACE_MEMBERS_ONLY)
// include cThreadBase member functions interface
//
#define CTHREADBASE_MEMBERS_ONLY
#define CTHREADBASE_MEMBER_FUNCS_INTERFACE
#include "cThreadBase.hpp"
#undef CTHREADBASE_MEMBER_FUNCS_INTERFACE
#undef CTHREADBASE_MEMBERS_ONLY
};

///////////////////////////////////////////////////////////////////////
// Typedef: cThreadImplementImplements
//
//  Author: $author$
//    Date: 6/14/2011
///////////////////////////////////////////////////////////////////////
typedef cWaitImplement
cThreadImplementImplements;

#if !defined(CTHREADIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cThreadImplement
//
// Author: $author$
//   Date: 6/14/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cThreadImplement
: virtual public cThreadInterface,
  virtual public cThreadImplementImplements
{
public:
    typedef cThreadImplementImplements cImplements;
#else // !defined(CTHREADIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CTHREADIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CTHREADIMPLEMENT_MEMBERS_ONLY)
// include cThreadBase interface member definitions
//
#define CTHREADINTERFACE_MEMBERS_ONLY
#include "cThreadInterface.hpp"
#undef CTHREADINTERFACE_MEMBERS_ONLY

// include cThreadBase member functions implement
//
#define CTHREADBASE_MEMBERS_ONLY
#define CTHREADBASE_MEMBER_FUNCS_IMPLEMENT
#include "cThreadBase.hpp"
#undef CTHREADBASE_MEMBER_FUNCS_IMPLEMENT
#undef CTHREADBASE_MEMBERS_ONLY
};
#else // !defined(CTHREADIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CTHREADIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CTHREADINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CTHREADINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CTHREADINTERFACE_HPP) || defined(CTHREADINTERFACE_MEMBERS_ONLY) 
        

