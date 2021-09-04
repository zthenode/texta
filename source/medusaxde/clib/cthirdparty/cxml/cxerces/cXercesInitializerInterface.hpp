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
//   File: cXercesInitializerInterface.hpp
//
// Author: $author$
//   Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CXERCESINITIALIZERINTERFACE_HPP) || defined(CXERCESINITIALIZERINTERFACE_MEMBERS_ONLY)
#if !defined(_CXERCESINITIALIZERINTERFACE_HPP) && !defined(CXERCESINITIALIZERINTERFACE_MEMBERS_ONLY)
#define _CXERCESINITIALIZERINTERFACE_HPP
#endif // !defined(_CXERCESINITIALIZERINTERFACE_HPP) && !defined(CXERCESINITIALIZERINTERFACE_MEMBERS_ONLY) 

#if !defined(CXERCESINITIALIZERINTERFACE_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"
#include "cImplementBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INSTANCE_CLASS cXercesInitializer;
///////////////////////////////////////////////////////////////////////
// Typedef: cXercesInitializerInterfaceImplements
//
//  Author: $author$
//    Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cXercesInitializerInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cXercesInitializerInterface
//
// Author: $author$
//   Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cXercesInitializerInterface
: virtual public cXercesInitializerInterfaceImplements
{
public:
    typedef cXercesInitializerInterfaceImplements cImplements;
#else // !defined(CXERCESINITIALIZERINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CXERCESINITIALIZERINTERFACE_MEMBERS_ONLY) 

#if !defined(CXERCESINITIALIZERINTERFACE_MEMBERS_ONLY)
// include cXercesInitializer member functions interface
//
#define CXERCESINITIALIZER_MEMBERS_ONLY
#define CXERCESINITIALIZER_MEMBER_FUNCS_INTERFACE
#include "cXercesInitializer.hpp"
#undef CXERCESINITIALIZER_MEMBER_FUNCS_INTERFACE
#undef CXERCESINITIALIZER_MEMBERS_ONLY
};

#if !defined(CXERCESINITIALIZERIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cXercesInitializerImplementImplements
//
//  Author: $author$
//    Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
typedef cImplementBase
cXercesInitializerImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cXercesInitializerImplement
//
// Author: $author$
//   Date: 7/17/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cXercesInitializerImplement
: virtual public cXercesInitializerInterface,
  virtual public cXercesInitializerImplementImplements
{
public:
    //typedef cXercesInitializerInterface cImplements;
    typedef cXercesInitializerImplementImplements cImplements;
#else // !defined(CXERCESINITIALIZERIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CXERCESINITIALIZERIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CXERCESINITIALIZERIMPLEMENT_MEMBERS_ONLY)
// include cXercesInitializer interface member definitions
//
#define CXERCESINITIALIZERINTERFACE_MEMBERS_ONLY
#include "cXercesInitializerInterface.hpp"
#undef CXERCESINITIALIZERINTERFACE_MEMBERS_ONLY

// include cXercesInitializer member functions implement
//
#define CXERCESINITIALIZER_MEMBERS_ONLY
#define CXERCESINITIALIZER_MEMBER_FUNCS_IMPLEMENT
#include "cXercesInitializer.hpp"
#undef CXERCESINITIALIZER_MEMBER_FUNCS_IMPLEMENT
#undef CXERCESINITIALIZER_MEMBERS_ONLY
};
#else // !defined(CXERCESINITIALIZERIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CXERCESINITIALIZERIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CXERCESINITIALIZERINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CXERCESINITIALIZERINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CXERCESINITIALIZERINTERFACE_HPP) || defined(CXERCESINITIALIZERINTERFACE_MEMBERS_ONLY) $6\6�67�
        

