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
//   File: cHttpFormFields.hpp
//
// Author: $author$
//   Date: 7/22/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CHTTPFORMFIELDS_HPP) || defined(CHTTPFORMFIELDS_MEMBERS_ONLY)
#if !defined(_CHTTPFORMFIELDS_HPP) && !defined(CHTTPFORMFIELDS_MEMBERS_ONLY)
#define _CHTTPFORMFIELDS_HPP
#endif // !defined(_CHTTPFORMFIELDS_HPP) && !defined(CHTTPFORMFIELDS_MEMBERS_ONLY) 

#if !defined(CHTTPFORMFIELDS_MEMBERS_ONLY)
#include "cHttpFormFieldsInterface.hpp"
#include "cHttpFormFieldList.hpp"
#include "cHttpFormFieldItem.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cHttpFormFieldsIterator
//
// Author: $author$
//   Date: 7/26/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cHttpFormFieldsIterator
{
public:
    cHttpFormFieldList::iterator i;
};

///////////////////////////////////////////////////////////////////////
// Typedef: cHttpFormFieldsExtend
//
//  Author: $author$
//    Date: 7/22/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cHttpFormFieldsExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cHttpFormFields
//
// Author: $author$
//   Date: 7/22/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cHttpFormFields
: virtual public cHttpFormFieldsImplement,
  public cHttpFormFieldsExtend
{
public:
    typedef cHttpFormFieldsImplement cImplements;
    typedef cHttpFormFieldsExtend cExtends;

    cHttpFormFieldList m_formFields;
    cHttpFormFieldsIterator m_iterator;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cHttpFormFields
    //
    //       Author: $author$
    //         Date: 7/22/2011
    ///////////////////////////////////////////////////////////////////////
    cHttpFormFields()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cHttpFormFields
    //
    //      Author: $author$
    //        Date: 7/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cHttpFormFields()
    {
    }
#else // !defined(CHTTPFORMFIELDS_MEMBERS_ONLY) 
#endif // !defined(CHTTPFORMFIELDS_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Init
    //
    //    Author: $author$
    //      Date: 11/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual eError Init()
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        m_formFields.ClearItems();
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finish
    //
    //    Author: $author$
    //      Date: 11/25/2012
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finish()
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        m_formFields.ClearItems();
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Add
    //
    //    Author: $author$
    //      Date: 7/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Add
    (const cString& name,
     const cString& value,
     bool isFromQueryString=false)
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
     ;
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
    {
        eError error = e_ERROR_FAILED;
        return error;
    }
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: FindFirst
    //
    //    Author: $author$
    //      Date: 8/9/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindFirst
    (cHttpFormFieldsIterator*& atField,
     const cString& named,
     bool isFromQueryString=false) const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        if ((atField = (cHttpFormFieldsIterator*)(&m_iterator)))
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        if ((atField = &Iterator()))
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
            formField = FindFirst(*atField, named, isFromQueryString);
        return formField;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: FindFirst
    //
    //    Author: $author$
    //      Date: 8/9/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindFirst
    (cHttpFormFieldsIterator& atField,
     const cString& named,
     bool isFromQueryString=false) const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldList::iterator i,j;
        for (i = m_formFields.begin(), j = m_formFields.end(); i != j; i++)
        {
            cHttpFormFieldInterface& f = i->m_field;
            if ((f.GetName() == named))
            {
                if ((isFromQueryString))
                if (!(f.GetIsFromQueryString()))
                    continue;
                formField = &f;
                atField.i = i;
                break;
            }
        }
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: FindNext
    //
    //    Author: $author$
    //      Date: 8/9/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindNext
    (cHttpFormFieldsIterator& atField,
     const cString& named,
     bool isFromQueryString=false) const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldList::iterator i,j;
        for (i = atField.i, j = m_formFields.end(); (++i) != j; )
        {
            cHttpFormFieldInterface& f = i->m_field;
            if ((f.GetName() == named))
            {
                if ((isFromQueryString))
                if (!(f.GetIsFromQueryString()))
                    continue;
                formField = &f;
                atField.i = i;
                break;
            }
        }
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: FindFirst
    //
    //    Author: $author$
    //      Date: 7/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindFirst
    (const cString& named,
     bool isFromQueryString=false) const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldList::iterator i,j;
        for (i = m_formFields.begin(), j = m_formFields.end(); i != j; i++)
        {
            cHttpFormFieldInterface& f = i->m_field;
            if ((f.GetName() == named))
            {
                if ((isFromQueryString))
                if (!(f.GetIsFromQueryString()))
                    continue;
                formField = &f;
                break;
            }
        }
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        cHttpFormFieldsIterator* atField = 0;
        formField = FindFirst(atField, named, isFromQueryString);
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: FindNext
    //
    //    Author: $author$
    //      Date: 7/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindNext
    (const cHttpFormFieldInterface& fromFormField,
     const cString& named,
     bool isFromQueryString=false) const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldItem& fieldItem = fromFormField.Item();
        cHttpFormFieldList::iterator i,j;
        for (i = m_formFields.at(&fieldItem), j = m_formFields.end(); (++i) != j;)
        {
            cHttpFormFieldInterface& f = i->m_field;
            if ((f.GetName() == named))
            {
                if ((isFromQueryString))
                if (!(f.GetIsFromQueryString()))
                    continue;
                formField = &f;
                break;
            }
        }
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: FindLast
    //
    //    Author: $author$
    //      Date: 8/9/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindLast
    (cHttpFormFieldsIterator*& atField,
     const cString& named,
     bool isFromQueryString=false) const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        if ((atField = (cHttpFormFieldsIterator*)(&m_iterator)))
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        if ((atField = &Iterator()))
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
            formField = FindFirst(*atField, named, isFromQueryString);
        return formField;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: FindLast
    //
    //    Author: $author$
    //      Date: 8/9/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindLast
    (cHttpFormFieldsIterator& atField,
     const cString& named,
     bool isFromQueryString=false) const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldList::iterator i,j;
        for (i = m_formFields.end(), j = m_formFields.begin(); i != j;)
        {
            cHttpFormFieldInterface& f = (--i)->m_field;
            if ((f.GetName() == named))
            {
                if ((isFromQueryString))
                if (!(f.GetIsFromQueryString()))
                    continue;
                formField = &f;
                atField.i = i;
                break;
            }
        }
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: FindPrev
    //
    //    Author: $author$
    //      Date: 8/9/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindPrev
    (cHttpFormFieldsIterator& atField,
     const cString& named,
     bool isFromQueryString=false) const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldList::iterator i,j;
        for (i = atField.i, j = m_formFields.begin(); i != j;)
        {
            cHttpFormFieldInterface& f = (--i)->m_field;
            if ((f.GetName() == named))
            {
                if ((isFromQueryString))
                if (!(f.GetIsFromQueryString()))
                    continue;
                formField = &f;
                atField.i = i;
                break;
            }
        }
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: FindLast
    //
    //    Author: $author$
    //      Date: 7/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindLast
    (const cString& named,
     bool isFromQueryString=false) const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldList::iterator i,j;
        for (i = m_formFields.end(), j = m_formFields.begin(); i != j;)
        {
            cHttpFormFieldInterface& f = (--i)->m_field;
            if ((f.GetName() == named))
            {
                if ((isFromQueryString))
                if (!(f.GetIsFromQueryString()))
                    continue;
                formField = &f;
                break;
            }
        }
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        cHttpFormFieldsIterator* atField = 0;
        formField = FindLast(atField, named, isFromQueryString);
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: FindPrev
    //
    //    Author: $author$
    //      Date: 7/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindPrev
    (const cHttpFormFieldInterface& fromFormField,
     const cString& named,
     bool isFromQueryString=false) const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldItem& fieldItem = fromFormField.Item();
        cHttpFormFieldList::iterator i,j;
        for (i = m_formFields.at(&fieldItem), j = m_formFields.begin(); i != j;)
        {
            cHttpFormFieldInterface& f = (--i)->m_field;
            if ((f.GetName() == named))
            {
                if ((isFromQueryString))
                if (!(f.GetIsFromQueryString()))
                    continue;
                formField = &f;
                break;
            }
        }
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetFirst
    //
    //    Author: $author$
    //      Date: 8/9/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetFirst
    (cHttpFormFieldsIterator*& atField,
     bool isFromQueryString=false) const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        if ((atField = (cHttpFormFieldsIterator*)(&m_iterator)))
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        if ((atField = &Iterator()))
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
            formField = GetFirst(*atField, isFromQueryString);
        return formField;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetFirst
    //
    //    Author: $author$
    //      Date: 7/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetFirst
    (cHttpFormFieldsIterator& atField,
     bool isFromQueryString=false) const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldList::iterator begin = m_formFields.begin();
        cHttpFormFieldList::iterator end = m_formFields.end();
        cHttpFormFieldList::iterator i;
        for (i = begin; i != end; i++)
        {
            cHttpFormFieldInterface& f = i->m_field;
            if ((isFromQueryString))
            if (!(f.GetIsFromQueryString()))
                continue;
            formField = &f;
            atField.i = i;
            break;
        }
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetNext
    //
    //    Author: $author$
    //      Date: 7/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetNext
    (cHttpFormFieldsIterator& atField,
     bool isFromQueryString=false) const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldList::iterator end = m_formFields.end();
        cHttpFormFieldList::iterator i;
        for (i = atField.i; (++i) != end;)
        {
            cHttpFormFieldInterface& f = i->m_field;
            if ((isFromQueryString))
            if (!(f.GetIsFromQueryString()))
                continue;
            formField = &f;
            atField.i = i;
            break;
        }
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetLast
    //
    //    Author: $author$
    //      Date: 8/9/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetLast
    (cHttpFormFieldsIterator*& atField,
     bool isFromQueryString=false) const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        if ((atField = (cHttpFormFieldsIterator*)(&m_iterator)))
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        if ((atField = &Iterator()))
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
            formField = GetLast(*atField, isFromQueryString);
        return formField;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetLast
    //
    //    Author: $author$
    //      Date: 7/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetLast
    (cHttpFormFieldsIterator& atField,
     bool isFromQueryString=false) const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldList::iterator begin = m_formFields.begin();
        cHttpFormFieldList::iterator end = m_formFields.end();
        cHttpFormFieldList::iterator i;
        for (i = end; i != begin;)
        {
            cHttpFormFieldInterface& f = (--i)->m_field;
            if ((isFromQueryString))
            if (!(f.GetIsFromQueryString()))
                continue;
            formField = &f;
            atField.i = i;
            break;
        }
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetPrev
    //
    //    Author: $author$
    //      Date: 7/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetPrev
    (cHttpFormFieldsIterator& atField,
     bool isFromQueryString=false) const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldList::iterator begin = m_formFields.begin();
        cHttpFormFieldList::iterator i;
        for (i = atField.i; i != begin;)
        {
            cHttpFormFieldInterface& f = (--i)->m_field;
            if ((isFromQueryString))
            if (!(f.GetIsFromQueryString()))
                continue;
            formField = &f;
            atField.i = i;
            break;
        }
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 

#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Iterator
    //
    //    Author: $author$
    //      Date: 7/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldsIterator& Iterator() const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        return (cHttpFormFieldsIterator&)(m_iterator);
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetFirst
    //
    //    Author: $author$
    //      Date: 7/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetFirst
    (bool isFromQueryString=false) const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldList::iterator i,j;
        for (i = m_formFields.begin(), j = m_formFields.end(); i != j; i++)
        {
            cHttpFormFieldInterface& f = i->m_field;
            {
                if ((isFromQueryString))
                if (!(f.GetIsFromQueryString()))
                    continue;
                formField = &f;
                break;
            }
        }
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetNext
    //
    //    Author: $author$
    //      Date: 7/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetNext
    (const cHttpFormFieldInterface& fromFormField,
     bool isFromQueryString=false) const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldItem& fieldItem = fromFormField.Item();
        cHttpFormFieldList::iterator i,j;
        for (i = m_formFields.at(&fieldItem), j = m_formFields.end(); ++i != j;)
        {
            cHttpFormFieldInterface& f = i->m_field;
            {
                if ((isFromQueryString))
                if (!(f.GetIsFromQueryString()))
                    continue;
                formField = &f;
                break;
            }
        }
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetLast
    //
    //    Author: $author$
    //      Date: 7/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetLast
    (bool isFromQueryString=false) const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldList::iterator i,j;
        for (i = m_formFields.end(), j = m_formFields.begin(); i != j;)
        {
            cHttpFormFieldInterface& f = (--i)->m_field;
            {
                if ((isFromQueryString))
                if (!(f.GetIsFromQueryString()))
                    continue;
                formField = &f;
                break;
            }
        }
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetPrev
    //
    //    Author: $author$
    //      Date: 7/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetPrev
    (const cHttpFormFieldInterface& fromFormField,
     bool isFromQueryString=false) const
#if defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldItem& fieldItem = fromFormField.Item();
        cHttpFormFieldList::iterator i,j;
        for (i = m_formFields.at(&fieldItem), j = m_formFields.begin(); i != j;)
        {
            cHttpFormFieldInterface& f = (--i)->m_field;
            {
                if ((isFromQueryString))
                if (!(f.GetIsFromQueryString()))
                    continue;
                formField = &f;
                break;
            }
        }
#else // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CHTTPFORMFIELDS_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CHTTPFORMFIELDS_MEMBER_FUNCS_INTERFACE) 

#if !defined(CHTTPFORMFIELDS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CHTTPFORMFIELDS_MEMBERS_ONLY) 
#endif // !defined(CHTTPFORMFIELDS_MEMBERS_ONLY) 

#endif // !defined(_CHTTPFORMFIELDS_HPP) || defined(CHTTPFORMFIELDS_MEMBERS_ONLY) 
