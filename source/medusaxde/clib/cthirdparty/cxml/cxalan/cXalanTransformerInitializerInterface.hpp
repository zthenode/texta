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
//   File: cXalanTransformerInitializerInterface.hpp
//
// Author: $author$
//   Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CXALANTRANSFORMERINITIALIZERINTERFACE_HPP) || defined(CXALANTRANSFORMERINITIALIZERINTERFACE_MEMBERS_ONLY)
#if !defined(_CXALANTRANSFORMERINITIALIZERINTERFACE_HPP) && !defined(CXALANTRANSFORMERINITIALIZERINTERFACE_MEMBERS_ONLY)
#define _CXALANTRANSFORMERINITIALIZERINTERFACE_HPP
#endif // !defined(_CXALANTRANSFORMERINITIALIZERINTERFACE_HPP) && !defined(CXALANTRANSFORMERINITIALIZERINTERFACE_MEMBERS_ONLY) 

#if !defined(CXALANTRANSFORMERINITIALIZERINTERFACE_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"
#include "cImplementBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INSTANCE_CLASS cXalanTransformerInitializer;
///////////////////////////////////////////////////////////////////////
// Typedef: cXalanTransformerInitializerInterfaceImplements
//
//  Author: $author$
//    Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cXalanTransformerInitializerInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cXalanTransformerInitializerInterface
//
// Author: $author$
//   Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cXalanTransformerInitializerInterface
: virtual public cXalanTransformerInitializerInterfaceImplements
{
public:
    typedef cXalanTransformerInitializerInterfaceImplements cImplements;
#else // !defined(CXALANTRANSFORMERINITIALIZERINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CXALANTRANSFORMERINITIALIZERINTERFACE_MEMBERS_ONLY) 

#if !defined(CXALANTRANSFORMERINITIALIZERINTERFACE_MEMBERS_ONLY)
// include cXalanTransformerInitializer member functions interface
//
#define CXALANTRANSFORMERINITIALIZER_MEMBERS_ONLY
#define CXALANTRANSFORMERINITIALIZER_MEMBER_FUNCS_INTERFACE
#include "cXalanTransformerInitializer.hpp"
#undef CXALANTRANSFORMERINITIALIZER_MEMBER_FUNCS_INTERFACE
#undef CXALANTRANSFORMERINITIALIZER_MEMBERS_ONLY
};

#if !defined(CXALANTRANSFORMERINITIALIZERIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cXalanTransformerInitializerImplementImplements
//
//  Author: $author$
//    Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
typedef cImplementBase
cXalanTransformerInitializerImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cXalanTransformerInitializerImplement
//
// Author: $author$
//   Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cXalanTransformerInitializerImplement
: virtual public cXalanTransformerInitializerInterface,
  virtual public cXalanTransformerInitializerImplementImplements
{
public:
    //typedef cXalanTransformerInitializerInterface cImplements;
    typedef cXalanTransformerInitializerImplementImplements cImplements;
#else // !defined(CXALANTRANSFORMERINITIALIZERIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CXALANTRANSFORMERINITIALIZERIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CXALANTRANSFORMERINITIALIZERIMPLEMENT_MEMBERS_ONLY)
// include cXalanTransformerInitializer member functions implement
//
#define CXALANTRANSFORMERINITIALIZER_MEMBERS_ONLY
#define CXALANTRANSFORMERINITIALIZER_MEMBER_FUNCS_IMPLEMENT
#include "cXalanTransformerInitializer.hpp"
#undef CXALANTRANSFORMERINITIALIZER_MEMBER_FUNCS_IMPLEMENT
#undef CXALANTRANSFORMERINITIALIZER_MEMBERS_ONLY
};
#else // !defined(CXALANTRANSFORMERINITIALIZERIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CXALANTRANSFORMERINITIALIZERIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CXALANTRANSFORMERINITIALIZERINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CXALANTRANSFORMERINITIALIZERINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CXALANTRANSFORMERINITIALIZERINTERFACE_HPP) || defined(CXALANTRANSFORMERINITIALIZERINTERFACE_MEMBERS_ONLY) 
