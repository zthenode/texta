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
//   File: cHttpFormField.hpp
//
// Author: $author$
//   Date: 6/5/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPFORMFIELD_HPP) || defined(CHTTPFORMFIELDT_MEMBERS_ONLY)
#if !defined(_CHTTPFORMFIELD_HPP) && !defined(CHTTPFORMFIELDT_MEMBERS_ONLY)
#define _CHTTPFORMFIELD_HPP
#endif // !defined(_CHTTPFORMFIELD_HPP) && !defined(CHTTPFORMFIELDT_MEMBERS_ONLY) 

#if !defined(CHTTPFORMFIELDT_MEMBERS_ONLY)
#include "cHttpFormFieldInterface.hpp"
#include "cHttpFormFieldItem.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "cHttpFormFieldT"
///////////////////////////////////////////////////////////////////////
//  Class: cHttpFormFieldT
//
// Author: $author$
//   Date: 6/5/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cHttpFormFieldImplement,
 class TItem=cHttpFormFieldItem,
 class TInterface=cHttpFormFieldInterface,
 class THttpFormField=cHttpFormField,
 class TString=cString,
 class TChar=char,
 class TExtend=cInstanceBase>

class c_INSTANCE_CLASS cHttpFormFieldT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement cImplements;
    typedef TExtend cExtends;
    
// include cHttpFormFieldT interface member definitions
//
#define CHTTPFORMFIELDINTERFACET_MEMBERS_ONLY
#include "cHttpFormFieldInterface.hpp"
#undef CHTTPFORMFIELDINTERFACET_MEMBERS_ONLY

    tHttpFormFieldItem m_item;
    tString m_name;
    tString m_value;
    bool m_isFromQueryString;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpFormFieldT
    //
    //       Author: $author$
    //         Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    cHttpFormFieldT
    (const tString& name,
     const tString& value,
     bool isFromQueryString=false)
    : m_item(*this),
      m_name(name),
      m_value(value),
      m_isFromQueryString(isFromQueryString)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpFormFieldT
    //
    //       Author: $author$
    //         Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    cHttpFormFieldT
    (const char_t* nameChars=0,
     const char_t* valueChars=0,
     bool isFromQueryString=false)
    : m_item(*this),
      m_isFromQueryString(isFromQueryString)
    {
        if ((nameChars))
            SetName(nameChars);

        if ((valueChars))
            SetValue(valueChars);
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cHttpFormFieldT
    //
    //      Author: $author$
    //        Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cHttpFormFieldT()
    {
    }
#else // !defined(CHTTPFORMFIELDT_MEMBERS_ONLY) 
#endif // !defined(CHTTPFORMFIELDT_MEMBERS_ONLY) 

#if !defined(CHTTPFORMFIELDT_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetName
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tString& SetName
    (const tString& toName)
#if defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
    {
        m_name = toName;
        return m_name;
    }
#endif // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetName
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tString& SetName
    (const char_t* chars, ssize_t length=-1)
#if defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
    {
        m_name.Assign(chars, length);
        return m_name;
    }
#endif // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetName
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const tString& GetName() const
#if defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
    {
        return m_name;
    }
#endif // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetValue
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tString& SetValue
    (const tString& toValue)
#if defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
    {
        m_value = toValue;
        return m_value;
    }
#endif // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetValue
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tString& SetValue
    (const char_t* chars, ssize_t length=-1)
#if defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
    {
        m_value.Assign(chars, length);
        return m_name;
    }
#endif // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetValue
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const tString& GetValue() const
#if defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
    {
        return m_value;
    }
#endif // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CHTTPFORMFIELDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDT_MEMBER_FUNCS_IMPLEMENT) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetNameChars
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* GetNameChars
    (ssize_t& length, bool negativeIsNullTerminated=false) const
#if defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
    {
        const char_t* chars = 0;
#if !defined(CHTTPFORMFIELDT_MEMBER_FUNCS_IMPLEMENT)
        if ((chars = m_name.Chars(length)))
        if ((negativeIsNullTerminated))
            length = -length;
#else // !defined(CHTTPFORMFIELDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDT_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetValueChars
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* GetValueChars
    (ssize_t& length, bool negativeIsNullTerminated=false) const
#if defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
    {
        const char_t* chars = 0;
#if !defined(CHTTPFORMFIELDT_MEMBER_FUNCS_IMPLEMENT)
        if ((chars = m_value.Chars(length)))
        if ((negativeIsNullTerminated))
            length = -length;
#else // !defined(CHTTPFORMFIELDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDT_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetIsFromQueryString
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsFromQueryString
    (bool isTrue=true)
#if defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CHTTPFORMFIELDT_MEMBER_FUNCS_IMPLEMENT)
        m_isFromQueryString = (isTrue);
#else // !defined(CHTTPFORMFIELDT_MEMBER_FUNCS_IMPLEMENT) 
        isTrue = false;
#endif // !defined(CHTTPFORMFIELDT_MEMBER_FUNCS_IMPLEMENT) 
        return isTrue;
    }
#endif // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetIsFromQueryString
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsFromQueryString() const
#if defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
    {
        bool isTrue = false;
#if !defined(CHTTPFORMFIELDT_MEMBER_FUNCS_IMPLEMENT)
        isTrue = (m_isFromQueryString);
#else // !defined(CHTTPFORMFIELDT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDT_MEMBER_FUNCS_IMPLEMENT) 
        return isTrue;
    }
#endif // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 

#if defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Item
    //
    //    Author: $author$
    //      Date: 7/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tHttpFormFieldItem& Item() const
    = 0;
#else // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
#endif // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
/*
#if defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Implemented
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tHttpFormField& Implemented() const
    = 0;
#else // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
#endif // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
*/
#if defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: NewInstance
    //
    //    Author: $author$
    //      Date: 7/22/2011
    ///////////////////////////////////////////////////////////////////////
    static tHttpFormFieldInterface* NewInstance
    (eError& error, 
     const cString& name,
     const cString& value,
     bool isFromQueryString=false);
#else // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
#endif // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 

#if defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: DeleteInstance
    //
    //    Author: $author$
    //      Date: 7/22/2011
    ///////////////////////////////////////////////////////////////////////
    static eError DeleteInstance
    (tHttpFormFieldInterface* formField);
#else // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 
#endif // defined(CHTTPFORMFIELDT_MEMBER_FUNCS_INTERFACE) 

#if !defined(CHTTPFORMFIELDT_MEMBERS_ONLY)
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpFormFieldExtend
//
//  Author: $author$
//    Date: 6/7/2011
///////////////////////////////////////////////////////////////////////
typedef cHttpFormFieldT
<cHttpFormFieldImplement,cHttpFormFieldItem,
 cHttpFormFieldInterface,cHttpFormField,cString,char>
cHttpFormFieldExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpFormField
//
// Author: $author$
//   Date: 6/7/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cHttpFormField
: public cHttpFormFieldExtend
{
public:
    typedef cHttpFormFieldExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpFormField
    //
    //       Author: $author$
    //         Date: 6/7/2011
    ///////////////////////////////////////////////////////////////////////
    cHttpFormField
    (const tString& name,
     const tString& value,
     bool isFromQueryString=false)
    : cExtends(name,value,isFromQueryString)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpFormField
    //
    //       Author: $author$
    //         Date: 6/7/2011
    ///////////////////////////////////////////////////////////////////////
    cHttpFormField
    (const char_t* nameChars=0,
     const char_t* valueChars=0,
     bool isFromQueryString=false)
    : cExtends(nameChars,valueChars,isFromQueryString)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Item
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tHttpFormFieldItem& Item() const
    {
        tHttpFormFieldItem& item = (tHttpFormFieldItem&)(m_item);
        return item;
    }
    /*
    ///////////////////////////////////////////////////////////////////////
    //  Function: Implemented
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tHttpFormField& Implemented() const
    {
        tHttpFormField& formField = (tHttpFormField&)(*this);
        return formField;
    }
    */
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPFORMFIELDT_MEMBERS_ONLY) 
#endif // !defined(CHTTPFORMFIELDT_MEMBERS_ONLY) 

#endif // !defined(_CHTTPFORMFIELD_HPP) || defined(CHTTPFORMFIELDT_MEMBERS_ONLY) 
