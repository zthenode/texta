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
//   File: cCgiInterface.hpp
//
// Author: $author$
//   Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCGIINTERFACE_HPP) || defined(CCGIINTERFACE_MEMBERS_ONLY)
#if !defined(_CCGIINTERFACE_HPP) && !defined(CCGIINTERFACE_MEMBERS_ONLY)
#define _CCGIINTERFACE_HPP
#endif // !defined(_CCGIINTERFACE_HPP) && !defined(CCGIINTERFACE_MEMBERS_ONLY) 

#if !defined(CCGIINTERFACE_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"
#include "cImplementBase.hpp"
#include "cCgiEnvInterface.hpp"
#include "cCgiContentStreamInterface.hpp"
#include "cHttpFormFieldsInterface.hpp"
#include "cHttpFormFieldInterface.hpp"
#include "cHttpRequestInterface.hpp"
#include "cHttpRequestMethod.hpp"
#include "cDebugInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiInterfaceImplements
//
//  Author: $author$
//    Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cCgiInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiInterface
//
// Author: $author$
//   Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cCgiInterface
: virtual public cCgiInterfaceImplements
{
public:
    typedef cCgiInterfaceImplements cImplements;
#else // !defined(CCGIINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CCGIINTERFACE_MEMBERS_ONLY) 

#if !defined(CCGIINTERFACE_MEMBERS_ONLY)
// include cCgi member functions interface
//
#define CCGI_MEMBERS_ONLY
#define CCGI_MEMBER_FUNCS_INTERFACE
#include "cCgi.hpp"
#undef CCGI_MEMBER_FUNCS_INTERFACE
#undef CCGI_MEMBERS_ONLY
};

#if !defined(CCGIIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cCgiImplementImplements
//
//  Author: $author$
//    Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
typedef cImplementBase
cCgiImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cCgiImplement
//
// Author: $author$
//   Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cCgiImplement
: virtual public cCgiInterface,
  virtual public cCgiImplementImplements
{
public:
    //typedef cCgiInterface cImplements;
    typedef cCgiImplementImplements cImplements;
#else // !defined(CCGIIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CCGIIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CCGIIMPLEMENT_MEMBERS_ONLY)
// include cCgi interface member definitions
//
#define CCGIINTERFACE_MEMBERS_ONLY
#include "cCgiInterface.hpp"
#undef CCGIINTERFACE_MEMBERS_ONLY

// include cCgi member functions implement
//
#define CCGI_MEMBERS_ONLY
#define CCGI_MEMBER_FUNCS_IMPLEMENT
#include "cCgi.hpp"
#undef CCGI_MEMBER_FUNCS_IMPLEMENT
#undef CCGI_MEMBERS_ONLY
};
#else // !defined(CCGIIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CCGIIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCGIINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CCGIINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CCGIINTERFACE_HPP) || defined(CCGIINTERFACE_MEMBERS_ONLY) 
        

