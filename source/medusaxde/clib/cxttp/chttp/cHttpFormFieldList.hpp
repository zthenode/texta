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
//   File: cHttpFormFieldList.hpp
//
// Author: $author$
//   Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPFORMFIELDLIST_HPP) || defined(CHTTPFORMFIELDLISTT_MEMBERS_ONLY)
#if !defined(_CHTTPFORMFIELDLIST_HPP) && !defined(CHTTPFORMFIELDLISTT_MEMBERS_ONLY)
#define _CHTTPFORMFIELDLIST_HPP
#endif // !defined(_CHTTPFORMFIELDLIST_HPP) && !defined(CHTTPFORMFIELDLISTT_MEMBERS_ONLY) 

#if !defined(CHTTPFORMFIELDLISTT_MEMBERS_ONLY)
#include "cHttpFormFieldItem.hpp"
#include "cList.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INSTANCE_CLASS cHttpFormFieldList;

#undef CDB_CLASS
#define CDB_CLASS "cHttpFormFieldListT"
///////////////////////////////////////////////////////////////////////
//  Class: cHttpFormFieldListT
//
// Author: $author$
//   Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
template
<class TDerive=cHttpFormFieldList,
 class TItem=cHttpFormFieldItem,
 class THttpFormFieldInterface=cHttpFormFieldInterface,
 class TString=cString,
 class TChar=char,
 class TImplement=cInterfaceBase>

class c_INSTANCE_CLASS cHttpFormFieldListT
: virtual public TImplement,
  public cListT<TDerive,TItem>
{
public:
    typedef TImplement cImplements;
    typedef cListT<TDerive,TItem> cExtends;
    typedef TDerive tDerives;
    typedef TItem tItem;
    typedef THttpFormFieldInterface tHttpFormFieldInterface;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpFormFieldListT
    //
    //       Author: $author$
    //         Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    cHttpFormFieldListT
    (TItem* firstItem=0, TItem* lastItem=0)
    : cExtends(firstItem, lastItem)
    {
    }
#else // !defined(CHTTPFORMFIELDLISTT_MEMBERS_ONLY) 
#endif // !defined(CHTTPFORMFIELDLISTT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Init
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Init()
#if defined(CHTTPFORMFIELDLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDLISTT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CHTTPFORMFIELDLISTT_MEMBER_FUNCS_IMPLEMENT)
        cExtends::ClearItems();
#else // !defined(CHTTPFORMFIELDLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CHTTPFORMFIELDLISTT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finish
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finish()
#if defined(CHTTPFORMFIELDLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDLISTT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CHTTPFORMFIELDLISTT_MEMBER_FUNCS_IMPLEMENT)
        cExtends::ClearItems();
#else // !defined(CHTTPFORMFIELDLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CHTTPFORMFIELDLISTT_MEMBER_FUNCS_INTERFACE) 

#if !defined(CHTTPFORMFIELDLISTT_MEMBERS_ONLY)
};
#undef CDB_CLASS

#if !defined(CHTTPFORMFIELDLIST_MEMBERS_ONLY)
///////////////////////////////////////////////////////////////////////
// Typedef: cHttpFormFieldListExtend
//
//  Author: $author$
//    Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
typedef cHttpFormFieldListT<>
cHttpFormFieldListExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpFormFieldList
//
// Author: $author$
//   Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cHttpFormFieldList
: public cHttpFormFieldListExtend
{
public:
    typedef cHttpFormFieldListExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpFormFieldList
    //
    //       Author: $author$
    //         Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    cHttpFormFieldList()
    {
    }
#else // !defined(CHTTPFORMFIELDLIST_MEMBERS_ONLY) 
#endif // !defined(CHTTPFORMFIELDLIST_MEMBERS_ONLY) 

#if !defined(CHTTPFORMFIELDLIST_MEMBERS_ONLY)
};
#else // !defined(CHTTPFORMFIELDLIST_MEMBERS_ONLY) 
#endif // !defined(CHTTPFORMFIELDLIST_MEMBERS_ONLY) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPFORMFIELDLISTT_MEMBERS_ONLY) 
#endif // !defined(CHTTPFORMFIELDLISTT_MEMBERS_ONLY) 

#endif // !defined(_CHTTPFORMFIELDLIST_HPP) || defined(CHTTPFORMFIELDLISTT_MEMBERS_ONLY) 
        

