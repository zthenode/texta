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
//   File: cHttpFormFieldInterface.hpp
//
// Author: $author$
//   Date: 6/5/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPFORMFIELDINTERFACE_HPP) || defined(CHTTPFORMFIELDINTERFACET_MEMBERS_ONLY)
#if !defined(_CHTTPFORMFIELDINTERFACE_HPP) && !defined(CHTTPFORMFIELDINTERFACET_MEMBERS_ONLY)
#define _CHTTPFORMFIELDINTERFACE_HPP
#endif // !defined(_CHTTPFORMFIELDINTERFACE_HPP) && !defined(CHTTPFORMFIELDINTERFACET_MEMBERS_ONLY) 

#if !defined(CHTTPFORMFIELDINTERFACET_MEMBERS_ONLY)
#include "cInterfaceBase.hpp"
#include "cString.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INTERFACE_CLASS cHttpFormFieldInterface;
class c_INSTANCE_CLASS cHttpFormFieldItem;
class c_INSTANCE_CLASS cHttpFormField;

#undef CDB_CLASS
#define CDB_CLASS "cHttpFormFieldInterfaceT"
///////////////////////////////////////////////////////////////////////
//  Class: cHttpFormFieldInterfaceT
//
// Author: $author$
//   Date: 6/5/2011
///////////////////////////////////////////////////////////////////////
template
<class TInterface=cHttpFormFieldInterface,
 class TItem=cHttpFormFieldItem,
 class THttpFormField=cHttpFormField,
 class TString=cString,
 class TChar=char,
 class TImplement=cInterfaceBase>

class c_INTERFACE_CLASS cHttpFormFieldInterfaceT
: virtual public TImplement
{
public:
    typedef TImplement cImplements;
#else // !defined(CHTTPFORMFIELDINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CHTTPFORMFIELDINTERFACET_MEMBERS_ONLY) 

    typedef TInterface tHttpFormFieldInterface;
    typedef THttpFormField tHttpFormField;
    typedef TItem tHttpFormFieldItem;
    typedef TString tString;
    typedef TChar char_t;

#if !defined(CHTTPFORMFIELDINTERFACET_MEMBERS_ONLY)
// include cHttpFormFieldT member functions interface
//
#define CHTTPFORMFIELDT_MEMBERS_ONLY
#define CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE
#include "cHttpFormField.hpp"
#undef CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE
#undef CHTTPFORMFIELDT_MEMBERS_ONLY
};
#undef CDB_CLASS

#if !defined(CHTTPFORMFIELDIMPLEMENTT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cHttpFormFieldImplement;

#undef CDB_CLASS
#define CDB_CLASS "cHttpFormFieldImplementT"
///////////////////////////////////////////////////////////////////////
//  Class: cHttpFormFieldImplementT
//
// Author: $author$
//   Date: 6/5/2011
///////////////////////////////////////////////////////////////////////
template
<class TInterface=cHttpFormFieldInterface,
 class TItem=cHttpFormFieldItem,
 class THttpFormField=cHttpFormField,
 class TString=cString,
 class TChar=char>

class c_IMPLEMENT_CLASS cHttpFormFieldImplementT
: virtual public TInterface
{
public:
    typedef TInterface cImplements;
#else // !defined(CHTTPFORMFIELDIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CHTTPFORMFIELDIMPLEMENTT_MEMBERS_ONLY) 

#if !defined(CHTTPFORMFIELDIMPLEMENTT_MEMBERS_ONLY)
// include cHttpFormFieldT interface member definitions
//
#define CHTTPFORMFIELDINTERFACET_MEMBERS_ONLY
#include "cHttpFormFieldInterface.hpp"
#undef CHTTPFORMFIELDINTERFACET_MEMBERS_ONLY

// include cHttpFormFieldT member functions implement
//
#define CHTTPFORMFIELDT_MEMBERS_ONLY
#define CHTTPFORMFIELDT_MEMBER_FUNCS_IMPLEMENT
#include "cHttpFormField.hpp"
#undef CHTTPFORMFIELDT_MEMBER_FUNCS_IMPLEMENT
#undef CHTTPFORMFIELDT_MEMBERS_ONLY
};
#undef CDB_CLASS
#else // !defined(CHTTPFORMFIELDIMPLEMENTT_MEMBERS_ONLY) 
#endif // !defined(CHTTPFORMFIELDIMPLEMENTT_MEMBERS_ONLY) 

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpFormFieldInterfaceImplements
//
//  Author: $author$
//    Date: 6/7/2011
///////////////////////////////////////////////////////////////////////
typedef cHttpFormFieldInterfaceT
<cHttpFormFieldInterface,cHttpFormFieldItem,cHttpFormField,cString,char>
cHttpFormFieldInterfaceImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpFormFieldInterface
//
// Author: $author$
//   Date: 6/7/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cHttpFormFieldInterface
: virtual public cHttpFormFieldInterfaceImplements
{
public:
    typedef cHttpFormFieldInterfaceImplements cImplements;
};
///////////////////////////////////////////////////////////////////////
// Typedef: cHttpFormFieldImplementImplements
//
//  Author: $author$
//    Date: 6/7/2011
///////////////////////////////////////////////////////////////////////
typedef cHttpFormFieldImplementT
<cHttpFormFieldInterface,cHttpFormField,cHttpFormField,cString,char>
cHttpFormFieldImplementImplements;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpFormFieldImplement
//
// Author: $author$
//   Date: 6/7/2011
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cHttpFormFieldImplement
: virtual public cHttpFormFieldImplementImplements
{
public:
    typedef cHttpFormFieldImplementImplements cImplements;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPFORMFIELDINTERFACET_MEMBERS_ONLY) 
#endif // !defined(CHTTPFORMFIELDINTERFACET_MEMBERS_ONLY) 

#endif // !defined(_CHTTPFORMFIELDINTERFACE_HPP) || defined(CHTTPFORMFIELDINTERFACET_MEMBERS_ONLY) 
