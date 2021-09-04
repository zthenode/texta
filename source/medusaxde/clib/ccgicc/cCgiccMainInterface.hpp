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
//   File: cCgiccMainInterface.hpp
//
// Author: $author$
//   Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCGICCMAININTERFACE_HPP) || defined(CCGICCMAININTERFACE_MEMBERS_ONLY)
#if !defined(_CCGICCMAININTERFACE_HPP) && !defined(CCGICCMAININTERFACE_MEMBERS_ONLY)
#define _CCGICCMAININTERFACE_HPP
#endif // !defined(_CCGICCMAININTERFACE_HPP) && !defined(CCGICCMAININTERFACE_MEMBERS_ONLY) 

#if !defined(CCGICCMAININTERFACE_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"
#include "cImplementBase.hpp"
#include "cString.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiccMainInterfaceImplements
//
//  Author: $author$
//    Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cCgiccMainInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiccMainInterface
//
// Author: $author$
//   Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cCgiccMainInterface
: virtual public cCgiccMainInterfaceImplements
{
public:
    typedef cCgiccMainInterfaceImplements cImplements;
#else // !defined(CCGICCMAININTERFACE_MEMBERS_ONLY) 
#endif // !defined(CCGICCMAININTERFACE_MEMBERS_ONLY) 

#if !defined(CCGICCMAININTERFACE_MEMBERS_ONLY)
// include cCgiccMain member functions interface
//
#define CCGICCMAIN_MEMBERS_ONLY
#define CCGICCMAIN_MEMBER_FUNCS_INTERFACE
#include "cCgiccMain.hpp"
#undef CCGICCMAIN_MEMBER_FUNCS_INTERFACE
#undef CCGICCMAIN_MEMBERS_ONLY
};

#if !defined(CCGICCMAINIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cCgiccMainImplementImplements
//
//  Author: $author$
//    Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
typedef cImplementBase
cCgiccMainImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiccMainImplement
//
// Author: $author$
//   Date: 6/25/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cCgiccMainImplement
: virtual public cCgiccMainInterface,
  virtual public cCgiccMainImplementImplements
{
public:
    //typedef cCgiccMainInterface cImplements;
    typedef cCgiccMainImplementImplements cImplements;
#else // !defined(CCGICCMAINIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CCGICCMAINIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CCGICCMAINIMPLEMENT_MEMBERS_ONLY)
// include cCgiccMain interface member definitions
//
#define CCGICCMAININTERFACE_MEMBERS_ONLY
#include "cCgiccMainInterface.hpp"
#undef CCGICCMAININTERFACE_MEMBERS_ONLY

// include cCgiccMain member functions implement
//
#define CCGICCMAIN_MEMBERS_ONLY
#define CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT
#include "cCgiccMain.hpp"
#undef CCGICCMAIN_MEMBER_FUNCS_IMPLEMENT
#undef CCGICCMAIN_MEMBERS_ONLY
};
#else // !defined(CCGICCMAINIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CCGICCMAINIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCGICCMAININTERFACE_MEMBERS_ONLY) 
#endif // !defined(CCGICCMAININTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CCGICCMAININTERFACE_HPP) || defined(CCGICCMAININTERFACE_MEMBERS_ONLY) 
        

