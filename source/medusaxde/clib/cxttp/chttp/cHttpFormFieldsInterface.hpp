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
//   File: cHttpFormFieldsInterface.hpp
//
// Author: $author$
//   Date: 7/22/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPFORMFIELDSINTERFACE_HPP) || defined(CHTTPFORMFIELDSINTERFACE_MEMBERS_ONLY)
#if !defined(_CHTTPFORMFIELDSINTERFACE_HPP) && !defined(CHTTPFORMFIELDSINTERFACE_MEMBERS_ONLY)
#define _CHTTPFORMFIELDSINTERFACE_HPP
#endif // !defined(_CHTTPFORMFIELDSINTERFACE_HPP) && !defined(CHTTPFORMFIELDSINTERFACE_MEMBERS_ONLY) 

#if !defined(CHTTPFORMFIELDSINTERFACE_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"
#include "cImplementBase.hpp"
#include "cHttpFormFieldInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INSTANCE_CLASS cHttpFormFieldsIterator;

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpFormFieldsInterfaceImplements
//
//  Author: $author$
//    Date: 7/22/2011
///////////////////////////////////////////////////////////////////////
typedef cInterfaceBase
cHttpFormFieldsInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpFormFieldsInterface
//
// Author: $author$
//   Date: 7/22/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cHttpFormFieldsInterface
: virtual public cHttpFormFieldsInterfaceImplements
{
public:
    typedef cHttpFormFieldsInterfaceImplements cImplements;
#else // !defined(CHTTPFORMFIELDSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CHTTPFORMFIELDSINTERFACE_MEMBERS_ONLY) 

#if !defined(CHTTPFORMFIELDSINTERFACE_MEMBERS_ONLY)
// include cHttpFormFields member functions interface
//
#define CHTTPFORMFIELDS_MEMBERS_ONLY
#define CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE
#include "cHttpFormFields.hpp"
#undef CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE
#undef CHTTPFORMFIELDS_MEMBERS_ONLY
};

#if !defined(CHTTPFORMFIELDSIMPLEMENT_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cHttpFormFieldsImplementImplements
//
//  Author: $author$
//    Date: 7/22/2011
///////////////////////////////////////////////////////////////////////
typedef cImplementBase
cHttpFormFieldsImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpFormFieldsImplement
//
// Author: $author$
//   Date: 7/22/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cHttpFormFieldsImplement
: virtual public cHttpFormFieldsInterface,
  virtual public cHttpFormFieldsImplementImplements
{
public:
    //typedef cHttpFormFieldsInterface cImplements;
    typedef cHttpFormFieldsImplementImplements cImplements;
#else // !defined(CHTTPFORMFIELDSIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CHTTPFORMFIELDSIMPLEMENT_MEMBERS_ONLY) 

#if !defined(CHTTPFORMFIELDSIMPLEMENT_MEMBERS_ONLY)
// include cHttpFormFields member functions implement
//
#define CHTTPFORMFIELDS_MEMBERS_ONLY
#define CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT
#include "cHttpFormFields.hpp"
#undef CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT
#undef CHTTPFORMFIELDS_MEMBERS_ONLY
};
#else // !defined(CHTTPFORMFIELDSIMPLEMENT_MEMBERS_ONLY) 
#endif // !defined(CHTTPFORMFIELDSIMPLEMENT_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPFORMFIELDSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CHTTPFORMFIELDSINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CHTTPFORMFIELDSINTERFACE_HPP) || defined(CHTTPFORMFIELDSINTERFACE_MEMBERS_ONLY) 
