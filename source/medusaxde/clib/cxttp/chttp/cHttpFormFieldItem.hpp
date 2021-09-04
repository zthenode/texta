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
//   File: cHttpFormFieldItem.hpp
//
// Author: $author$
//   Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPFORMFIELDITEM_HPP) || defined(CHTTPFORMFIELDITEMT_MEMBERS_ONLY)
#if !defined(_CHTTPFORMFIELDITEM_HPP) && !defined(CHTTPFORMFIELDITEMT_MEMBERS_ONLY)
#define _CHTTPFORMFIELDITEM_HPP
#endif // !defined(_CHTTPFORMFIELDITEM_HPP) && !defined(CHTTPFORMFIELDITEMT_MEMBERS_ONLY) 

#if !defined(CHTTPFORMFIELDITEMT_MEMBERS_ONLY)
#include "cHttpFormFieldInterface.hpp"
#include "cListItem.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INSTANCE_CLASS cHttpFormFieldItem;

#undef CDB_CLASS
#define CDB_CLASS "cHttpFormFieldItemT"
///////////////////////////////////////////////////////////////////////
//  Class: cHttpFormFieldItemT
//
// Author: $author$
//   Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
template
<class TDerives=cHttpFormFieldItem,
 class THttpFormFieldInterface=cHttpFormFieldInterface,
 class TString=cString,
 class TChar=char,
 class TImplement=cInterfaceBase>

class c_INSTANCE_CLASS cHttpFormFieldItemT
: virtual public TImplement,
  public cListItemT<TDerives>
{
public:
    typedef TImplement cImplements;
    typedef cListItemT<TDerives> cExtends;
    typedef TDerives tDerives;
    typedef THttpFormFieldInterface tHttpFormFieldInterface;

    tHttpFormFieldInterface& m_field;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpFormFieldItemT
    //
    //       Author: $author$
    //         Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    cHttpFormFieldItemT
    (tHttpFormFieldInterface& field)
    : m_field(field)
    {
    }
#else // !defined(CHTTPFORMFIELDITEMT_MEMBERS_ONLY) 
#endif // !defined(CHTTPFORMFIELDITEMT_MEMBERS_ONLY) 

#if !defined(CHTTPFORMFIELDITEMT_MEMBERS_ONLY)
};
#undef CDB_CLASS

#if !defined(CHTTPFORMFIELDITEM_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cHttpFormFieldItemExtends
//
//  Author: $author$
//    Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
typedef cHttpFormFieldItemT<>
cHttpFormFieldItemExtends;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpFormFieldItem
//
// Author: $author$
//   Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cHttpFormFieldItem
: public cHttpFormFieldItemExtends
{
public:
    typedef cHttpFormFieldItemExtends cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpFormFieldItem
    //
    //       Author: $author$
    //         Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    cHttpFormFieldItem
    (tHttpFormFieldInterface& field)
    : cExtends(field)
    {
    }
#else // !defined(CHTTPFORMFIELDITEM_MEMBERS_ONLY) 
#endif // !defined(CHTTPFORMFIELDITEM_MEMBERS_ONLY) 

#if !defined(CHTTPFORMFIELDITEM_MEMBERS_ONLY)
};
#else // !defined(CHTTPFORMFIELDITEM_MEMBERS_ONLY) 
#endif // !defined(CHTTPFORMFIELDITEM_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPFORMFIELDITEMT_MEMBERS_ONLY) 
#endif // !defined(CHTTPFORMFIELDITEMT_MEMBERS_ONLY) 

#endif // !defined(_CHTTPFORMFIELDITEM_HPP) || defined(CHTTPFORMFIELDITEMT_MEMBERS_ONLY) 
        

