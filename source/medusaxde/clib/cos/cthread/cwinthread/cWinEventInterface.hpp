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
//   File: cWinEventInterface.hpp
//
// Author: $author$
//   Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWINEVENTINTERFACE_HPP) || defined(CWINEVENTINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINEVENTINTERFACE_HPP) && !defined(CWINEVENTINTERFACE_MEMBERS_ONLY)
#define _CWINEVENTINTERFACE_HPP
#endif // !defined(_CWINEVENTINTERFACE_HPP) && !defined(CWINEVENTINTERFACE_MEMBERS_ONLY) 

#if !defined(CWINEVENTINTERFACE_MEMBERS_ONLY)
#include "cEventInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWinEventInterfaceImplements
//
//  Author: $author$
//    Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
typedef cEventInterface
cWinEventInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cWinEventInterface
//
// Author: $author$
//   Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cWinEventInterface
: virtual public cWinEventInterfaceImplements
{
public:
    typedef cWinEventInterfaceImplements cImplements;
#else // !defined(CWINEVENTINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWINEVENTINTERFACE_MEMBERS_ONLY) 

#if !defined(CWINEVENTINTERFACE_MEMBERS_ONLY)
// include cWinEvent member functions interface
//
#define CWINEVENT_MEMBERS_ONLY
#define CWINEVENT_MEMBER_FUNCS_INTERFACE
#include "cWinEvent.hpp"
#undef CWINEVENT_MEMBER_FUNCS_INTERFACE
#undef CWINEVENT_MEMBERS_ONLY
};

///////////////////////////////////////////////////////////////////////
// Typedef: cWinEventImplementImplements
//
//  Author: $author$
//    Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
typedef cEventImplement
cWinEventImplementImplements;

#if !defined(CWINEVENTIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cWinEventImplement
//
// Author: $author$
//   Date: 6/13/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cWinEventImplement
: virtual public cWinEventInterface,
  virtual public cWinEventImplementImplements
{
public:
    typedef cWinEventImplementImplements cImplements;
#else // !defined(CWINEVENTIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWINEVENTIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CWINEVENTIMPLEMENT_MEMBERS_ONLY)
// include cWinEvent interface member definitions
//
#define CWINEVENTINTERFACE_MEMBERS_ONLY
#include "cWinEventInterface.hpp"
#undef CWINEVENTINTERFACE_MEMBERS_ONLY

// include cWinEvent member functions implement
//
#define CWINEVENT_MEMBERS_ONLY
#define CWINEVENT_MEMBER_FUNCS_IMPLEMENT
#include "cWinEvent.hpp"
#undef CWINEVENT_MEMBER_FUNCS_IMPLEMENT
#undef CWINEVENT_MEMBERS_ONLY
};
#else // !defined(CWINEVENTIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CWINEVENTIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWINEVENTINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWINEVENTINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CWINEVENTINTERFACE_HPP) || defined(CWINEVENTINTERFACE_MEMBERS_ONLY) 
        

