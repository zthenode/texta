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
//   File: cEventInterface.hpp
//
// Author: $author$
//   Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CEVENTINTERFACE_HPP) || defined(CEVENTINTERFACE_MEMBERS_ONLY)
#if !defined(_CEVENTINTERFACE_HPP) && !defined(CEVENTINTERFACE_MEMBERS_ONLY)
#define _CEVENTINTERFACE_HPP
#endif // !defined(_CEVENTINTERFACE_HPP) && !defined(CEVENTINTERFACE_MEMBERS_ONLY) 

#if !defined(CEVENTINTERFACE_MEMBERS_ONLY)
#include "cWaitInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cEventInterfaceImplements
//
//  Author: $author$
//    Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
typedef cWaitInterface
cEventInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cEventInterface
//
// Author: $author$
//   Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cEventInterface
: virtual public cEventInterfaceImplements
{
public:
    typedef cEventInterfaceImplements cImplements;
#else // !defined(CEVENTINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CEVENTINTERFACE_MEMBERS_ONLY) 

#if !defined(CEVENTINTERFACE_MEMBERS_ONLY)
// include cEventBase member functions interface
//
#define CEVENTBASE_MEMBERS_ONLY
#define CEVENTBASE_MEMBER_FUNCS_INTERFACE
#include "cEventBase.hpp"
#undef CEVENTBASE_MEMBER_FUNCS_INTERFACE
#undef CEVENTBASE_MEMBERS_ONLY
};

#if !defined(CEVENTIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cEventImplementImplements
//
//  Author: $author$
//    Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
typedef cWaitImplement
cEventImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cEventImplement
//
// Author: $author$
//   Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cEventImplement
: virtual public cEventInterface,
  virtual public cEventImplementImplements
{
public:
    typedef cEventImplementImplements cImplements;
#else // !defined(CEVENTIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CEVENTIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CEVENTIMPLEMENT_MEMBERS_ONLY)
// include cEvent interface member definitions
//
#define CEVENTINTERFACE_MEMBERS_ONLY
#include "cEventInterface.hpp"
#undef CEVENTINTERFACE_MEMBERS_ONLY

// include cEventBase member functions implement
//
#define CEVENTBASE_MEMBERS_ONLY
#define CEVENTBASE_MEMBER_FUNCS_IMPLEMENT
#include "cEventBase.hpp"
#undef CEVENTBASE_MEMBER_FUNCS_IMPLEMENT
#undef CEVENTBASE_MEMBERS_ONLY
};
#else // !defined(CEVENTIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CEVENTIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CEVENTINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CEVENTINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CEVENTINTERFACE_HPP) || defined(CEVENTINTERFACE_MEMBERS_ONLY) 
        

