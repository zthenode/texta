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
//   File: cCgiEnvInterface.hpp
//
// Author: $author$
//   Date: 6/5/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCGIENVINTERFACE_HPP) || defined(CCGIENVINTERFACE_MEMBERS_ONLY)
#if !defined(_CCGIENVINTERFACE_HPP) && !defined(CCGIENVINTERFACE_MEMBERS_ONLY)
#define _CCGIENVINTERFACE_HPP
#endif // !defined(_CCGIENVINTERFACE_HPP) && !defined(CCGIENVINTERFACE_MEMBERS_ONLY) 

#if !defined(CCGIENVINTERFACE_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"
#include "cString.hpp"
#include "cCgiEnv.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiEnvInterfaceImplements
//
//  Author: $author$
//    Date: 6/5/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cCgiEnvInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiEnvInterface
//
// Author: $author$
//   Date: 6/5/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cCgiEnvInterface
: virtual public cCgiEnvInterfaceImplements
{
public:
    typedef cCgiEnvInterfaceImplements cImplements;
#else // !defined(CCGIENVINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CCGIENVINTERFACE_MEMBERS_ONLY) 

#if !defined(CCGIENVINTERFACE_MEMBERS_ONLY)
// include cCgiEnv member functions interface
//
#define CCGIENV_MEMBERS_ONLY
#define CCGIENV_MEMBER_FUNCS_INTERFACE
#include "cCgiEnv.hpp"
#undef CCGIENV_MEMBER_FUNCS_INTERFACE
#undef CCGIENV_MEMBERS_ONLY
};

#if !defined(CCGIENVIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cCgiEnvImplement
//
// Author: $author$
//   Date: 6/5/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cCgiEnvImplement
: virtual public cCgiEnvInterface
{
public:
    typedef cCgiEnvInterface cImplements;
#else // !defined(CCGIENVIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CCGIENVIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CCGIENVIMPLEMENT_MEMBERS_ONLY)
// include cCgiEnv member functions implement
//
#define CCGIENV_MEMBERS_ONLY
#define CCGIENV_MEMBER_FUNCS_IMPLEMENT
#include "cCgiEnv.hpp"
#undef CCGIENV_MEMBER_FUNCS_IMPLEMENT
#undef CCGIENV_MEMBERS_ONLY
};
#else // !defined(CCGIENVIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CCGIENVIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCGIENVINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CCGIENVINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CCGIENVINTERFACE_HPP) || defined(CCGIENVINTERFACE_MEMBERS_ONLY) 
        

