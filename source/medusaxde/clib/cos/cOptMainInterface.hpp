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
//   File: cOptMainInterface.hpp
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_COPTMAININTERFACE_HPP) || defined(COPTMAININTERFACE_MEMBERS_ONLY)
#if !defined(_COPTMAININTERFACE_HPP) && !defined(COPTMAININTERFACE_MEMBERS_ONLY)
#define _COPTMAININTERFACE_HPP
#endif // !defined(_COPTMAININTERFACE_HPP) && !defined(COPTMAININTERFACE_MEMBERS_ONLY) 

#if !defined(COPTMAININTERFACE_MEMBERS_ONLY)
#include "cMainInterface.hpp"
#include "cplatform_getopt.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//    Enum: eMainOptArgument
//
//  Author: $author$
//    Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
typedef int eMainOptArgument;
enum
{
    e_MAIN_OPT_ARGUMENT_NONE     = 0,
    e_MAIN_OPT_ARGUMENT_REQUIRED = 1,
    e_MAIN_OPT_ARGUMENT_OPTIONAL = 2
};
///////////////////////////////////////////////////////////////////////
// Typedef: cOptMainInterfaceImplements
//
//  Author: $author$
//    Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
typedef cMainInterface
cOptMainInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cOptMainInterface
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cOptMainInterface
: virtual public cOptMainInterfaceImplements
{
public:
    typedef cOptMainInterfaceImplements cImplements;
#else // !defined(COPTMAININTERFACE_MEMBERS_ONLY) 
#endif // !defined(COPTMAININTERFACE_MEMBERS_ONLY) 

#if !defined(COPTMAININTERFACE_MEMBERS_ONLY)
// include cOptMain member functions interface
//
#define COPTMAIN_MEMBERS_ONLY
#define COPTMAIN_MEMBER_FUNCS_INTERFACE
#include "cOptMain.hpp"
#undef COPTMAIN_MEMBER_FUNCS_INTERFACE
#undef COPTMAIN_MEMBERS_ONLY
};

#if !defined(COPTMAINIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cOptMainImplementImplements
//
//  Author: $author$
//    Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
typedef cMainImplement
cOptMainImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cOptMainImplement
//
// Author: $author$
//   Date: 6/2/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cOptMainImplement
: virtual public cOptMainInterface,
  virtual public cOptMainImplementImplements
{
public:
    typedef cOptMainInterface cImplements;
#else // !defined(COPTMAINIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(COPTMAINIMPLEMENT_MEMBERS_ONLY) 

#if !defined(COPTMAINIMPLEMENT_MEMBERS_ONLY)
// include cOptMain member functions implement
//
#define COPTMAIN_MEMBERS_ONLY
#define COPTMAIN_MEMBER_FUNCS_IMPLEMENT
#include "cOptMain.hpp"
#undef COPTMAIN_MEMBER_FUNCS_IMPLEMENT
#undef COPTMAIN_MEMBERS_ONLY
};
#else // !defined(COPTMAINIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(COPTMAINIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(COPTMAININTERFACE_MEMBERS_ONLY) 
#endif // !defined(COPTMAININTERFACE_MEMBERS_ONLY) 

#endif // !defined(_COPTMAININTERFACE_HPP) || defined(COPTMAININTERFACE_MEMBERS_ONLY) 
        

