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
//   File: cXsltParamInterface.hpp
//
// Author: $author$
//   Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CXSLTPARAMINTERFACE_HPP) || defined(CXSLTPARAMINTERFACE_MEMBERS_ONLY)
#if !defined(_CXSLTPARAMINTERFACE_HPP) && !defined(CXSLTPARAMINTERFACE_MEMBERS_ONLY)
#define _CXSLTPARAMINTERFACE_HPP
#endif // !defined(_CXSLTPARAMINTERFACE_HPP) && !defined(CXSLTPARAMINTERFACE_MEMBERS_ONLY) 

#if !defined(CXSLTPARAMINTERFACE_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"
#include "cImplementBase.hpp"
#include "cString.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INSTANCE_CLASS cXsltParam;
///////////////////////////////////////////////////////////////////////
// Typedef: cXsltParamInterfaceImplements
//
//  Author: $author$
//    Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cXsltParamInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cXsltParamInterface
//
// Author: $author$
//   Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cXsltParamInterface
: virtual public cXsltParamInterfaceImplements
{
public:
    typedef cXsltParamInterfaceImplements cImplements;
#else // !defined(CXSLTPARAMINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CXSLTPARAMINTERFACE_MEMBERS_ONLY) 

#if !defined(CXSLTPARAMINTERFACE_MEMBERS_ONLY)
// include cXsltParam member functions interface
//
#define CXSLTPARAM_MEMBERS_ONLY
#define CXSLTPARAM_MEMBER_FUNCS_INTERFACE
#include "cXsltParam.hpp"
#undef CXSLTPARAM_MEMBER_FUNCS_INTERFACE
#undef CXSLTPARAM_MEMBERS_ONLY
};

///////////////////////////////////////////////////////////////////////
// Typedef: cXsltParamImplementImplements
//
//  Author: $author$
//    Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
typedef cImplementBase
cXsltParamImplementImplements;

#if !defined(CXSLTPARAMIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cXsltParamImplement
//
// Author: $author$
//   Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cXsltParamImplement
: virtual public cXsltParamInterface,
  virtual public cXsltParamImplementImplements
{
public:
    //typedef cXsltParamInterface cImplements;
    typedef cXsltParamImplementImplements cImplements;
#else // !defined(CXSLTPARAMIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CXSLTPARAMIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CXSLTPARAMIMPLEMENT_MEMBERS_ONLY)
// include cXsltParam member functions implement
//
#define CXSLTPARAM_MEMBERS_ONLY
#define CXSLTPARAM_MEMBER_FUNCS_IMPLEMENT
#include "cXsltParam.hpp"
#undef CXSLTPARAM_MEMBER_FUNCS_IMPLEMENT
#undef CXSLTPARAM_MEMBERS_ONLY
};
#else // !defined(CXSLTPARAMIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CXSLTPARAMIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CXSLTPARAMINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CXSLTPARAMINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CXSLTPARAMINTERFACE_HPP) || defined(CXSLTPARAMINTERFACE_MEMBERS_ONLY) 
        

