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
//   File: cXsltParamsInterface.hpp
//
// Author: $author$
//   Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CXSLTPARAMSINTERFACE_HPP) || defined(CXSLTPARAMSINTERFACE_MEMBERS_ONLY)
#if !defined(_CXSLTPARAMSINTERFACE_HPP) && !defined(CXSLTPARAMSINTERFACE_MEMBERS_ONLY)
#define _CXSLTPARAMSINTERFACE_HPP
#endif // !defined(_CXSLTPARAMSINTERFACE_HPP) && !defined(CXSLTPARAMSINTERFACE_MEMBERS_ONLY) 

#if !defined(CXSLTPARAMSINTERFACE_MEMBERS_ONLY)
#include "cXsltParamInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INSTANCE_CLASS cXsltParamsIterator;
///////////////////////////////////////////////////////////////////////
// Typedef: cXsltParamsInterfaceImplements
//
//  Author: $author$
//    Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cXsltParamsInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cXsltParamsInterface
//
// Author: $author$
//   Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cXsltParamsInterface
: virtual public cXsltParamsInterfaceImplements
{
public:
    typedef cXsltParamsInterfaceImplements cImplements;
#else // !defined(CXSLTPARAMSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CXSLTPARAMSINTERFACE_MEMBERS_ONLY) 

#if !defined(CXSLTPARAMSINTERFACE_MEMBERS_ONLY)
// include cXsltParams member functions interface
//
#define CXSLTPARAMS_MEMBERS_ONLY
#define CXSLTPARAMS_MEMBER_FUNCS_INTERFACE
#include "cXsltParams.hpp"
#undef CXSLTPARAMS_MEMBER_FUNCS_INTERFACE
#undef CXSLTPARAMS_MEMBERS_ONLY
};

///////////////////////////////////////////////////////////////////////
// Typedef: cXsltParamsImplementImplements
//
//  Author: $author$
//    Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
typedef cImplementBase
cXsltParamsImplementImplements;

#if !defined(CXSLTPARAMSIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
//  Class: cXsltParamsImplement
//
// Author: $author$
//   Date: 7/25/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cXsltParamsImplement
: virtual public cXsltParamsInterface,
  virtual public cXsltParamsImplementImplements
{
public:
    //typedef cXsltParamsInterface cImplements;
    typedef cXsltParamsImplementImplements cImplements;
#else // !defined(CXSLTPARAMSIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CXSLTPARAMSIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CXSLTPARAMSIMPLEMENT_MEMBERS_ONLY)
// include cXsltParams member functions implement
//
#define CXSLTPARAMS_MEMBERS_ONLY
#define CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT
#include "cXsltParams.hpp"
#undef CXSLTPARAMS_MEMBER_FUNCS_IMPLEMENT
#undef CXSLTPARAMS_MEMBERS_ONLY
};
#else // !defined(CXSLTPARAMSIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CXSLTPARAMSIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CXSLTPARAMSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CXSLTPARAMSINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CXSLTPARAMSINTERFACE_HPP) || defined(CXSLTPARAMSINTERFACE_MEMBERS_ONLY) 
        

