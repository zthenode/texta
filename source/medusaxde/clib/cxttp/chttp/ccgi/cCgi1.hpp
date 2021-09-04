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
//   File: cCgi.hpp
//
// Author: $author$
//   Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CCGI_HPP) || defined(CCGI_MEMBERS_ONLY)
#if !defined(_CCGI_HPP) && !defined(CCGI_MEMBERS_ONLY)
#define _CCGI_HPP
#endif // !defined(_CCGI_HPP) && !defined(CCGI_MEMBERS_ONLY) 

#if !defined(CCGI_MEMBERS_ONLY)
#include "cCgiInterface.hpp"
#include "cCgiContentStream.hpp"
#include "cCgiEnv.hpp"
#include "cInstanceBase.hpp"
#include "cHttpFormFields.hpp"
#include "cHttpFormFieldList.hpp"
#include "cHttpFormFieldItem.hpp"
#include "cHttpFormField.hpp"

#define CCGI_NAME "cCgi"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cCgiExtend
//
//  Author: $author$
//    Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
typedef cInstanceBase
cCgiExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cCgi
//
// Author: $author$
//   Date: 6/23/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cCgi
: virtual public cCgiImplement,
  public cCgiExtend
{
public:
    typedef cCgiImplement cImplements;
    typedef cCgiExtend cExtends;

    static cCgiInterface* m_theCgi;
    cCgiInterface* m_theOldCgi;

    cCgiContentStreamInterface* m_contentOutput;

    cString m_name;
    cCgiEnv m_cgiEnv;
    cHttpFormFieldList m_formFields;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgi
    //
    //       Author: $author$
    //         Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    cCgi
    (const char* name, 
     cCgiContentStreamInterface* contentOutput=0)
    : m_theOldCgi(m_theCgi),
      m_contentOutput(contentOutput),
      m_name(CCGI_NAME)
    {
        m_theCgi = this;

        if ((name))
            m_name.Assign(name);
    }
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cCgi
    //
    //       Author: $author$
    //         Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    cCgi(cCgiContentStreamInterface* contentOutput=0)
    : m_theOldCgi(m_theCgi),
      m_contentOutput(contentOutput),
      m_name(CCGI_NAME)
    {
        m_theCgi = this;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cCgi
    //
    //      Author: $author$
    //        Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cCgi()
    {
        eError error;

        if (this == m_theCgi)
            m_theCgi = m_theOldCgi;

        if ((error = Finish()))
            throw (error);
    }
#else // !defined(CCGI_MEMBERS_ONLY) 
#endif // !defined(CCGI_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Init
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Init()
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if (!(error = m_cgiEnv.Init()))
        if ((error = m_formFields.Init()))
            m_cgiEnv.Finish();
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Finish
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Finish()
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        eError error2;
        error = m_formFields.Finish();
        if ((error2 = m_cgiEnv.Finish()))
        if (!(error))
            error = error2;
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Run
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc,
     char** argv,
     char** env)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: BeforeRun
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int BeforeRun
    (int argc,
     char** argv,
     char** env)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: AfterRun
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int AfterRun
    (int argc,
     char** argv,
     char** env)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: AddFormField
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError AddFormField
    (const cString& name,
     const cString& value,
     bool isFromQueryString=false)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_FAILED;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormField* formField;
        if ((formField = new cHttpFormField
            (name, value, isFromQueryString)))
        {
            m_formFields.AddItem(&formField->m_item);
            error = e_ERROR_NONE;
        }
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetFirstFormField
    //
    //    Author: $author$
    //      Date: 6/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetFirstFormField
    (bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldList::iterator i,j;
        for (i = m_formFields.begin(), j = m_formFields.end(); i != j; i++)
        {
            cHttpFormFieldInterface& f = i->m_field;
            //if ((f.GetName() == named))
            {
                if ((isFromQueryString))
                if (!(f.GetIsFromQueryString()))
                    continue;
                formField = &f;
                break;
            }
        }
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetNextFormField
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetNextFormField
    (const cHttpFormFieldInterface& fromFormField,
     bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldItem& fieldItem = fromFormField.Implemented().m_item;
        cHttpFormFieldList::iterator i,j;
        for (i = m_formFields.at(&fieldItem), j = m_formFields.end(); ++i != j;)
        {
            cHttpFormFieldInterface& f = i->m_field;
            //if ((f.GetName() == named))
            {
                if ((isFromQueryString))
                if (!(f.GetIsFromQueryString()))
                    continue;
                formField = &f;
                break;
            }
        }
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetLastFormField
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetLastFormField
    (bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldList::iterator i,j;
        for (i = m_formFields.end(), j = m_formFields.begin(); i != j;)
        {
            cHttpFormFieldInterface& f = (--i)->m_field;
            //if ((f.GetName() == named))
            {
                if ((isFromQueryString))
                if (!(f.GetIsFromQueryString()))
                    continue;
                formField = &f;
                break;
            }
        }
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetPrevFormField
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* GetPrevFormField
    (const cHttpFormFieldInterface& fromFormField,
     bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldItem& fieldItem = fromFormField.Implemented().m_item;
        cHttpFormFieldList::iterator i,j;
        for (i = m_formFields.at(&fieldItem), j = m_formFields.begin(); i != j;)
        {
            cHttpFormFieldInterface& f = (--i)->m_field;
            //if ((f.GetName() == named))
            {
                if ((isFromQueryString))
                if (!(f.GetIsFromQueryString()))
                    continue;
                formField = &f;
                break;
            }
        }
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: FindFirstFormField
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindFirstFormField
    (const cString& named,
     bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
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
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: FindNextFormField
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindNextFormField
    (const cHttpFormFieldInterface& fromFormField,
     const cString& named,
     bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldItem& fieldItem = fromFormField.Implemented().m_item;
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
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: FindLastFormField
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindLastFormField
    (const cString& named,
     bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
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
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: FindPrevFormField
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cHttpFormFieldInterface* FindPrevFormField
    (const cHttpFormFieldInterface& fromFormField,
     const cString& named,
     bool isFromQueryString=false) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cHttpFormFieldInterface* formField = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        cHttpFormFieldItem& fieldItem = fromFormField.Implemented().m_item;
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
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return formField;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetCgiEnv
    //
    //    Author: $author$
    //      Date: 6/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* SetCgiEnv
    (eCgiEnv e, const char* toChars, ssize_t length=-1)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        chars = (m_cgiEnv.Set(e, toChars, length));
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetCgiEnv
    //
    //    Author: $author$
    //      Date: 6/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetCgiEnv
    (eCgiEnv e) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        chars = (m_cgiEnv.Get(e));
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetCgiEnvName
    //
    //    Author: $author$
    //      Date: 6/28/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetCgiEnvName
    (eCgiEnv e) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        chars = (m_cgiEnv.GetName(e));
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetFirstCgiEnv
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetFirstCgiEnv
    (eCgiEnv& e, const char*& value) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        chars = (m_cgiEnv.GetFirst(e, value));
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetNextCgiEnv
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetNextCgiEnv
    (eCgiEnv& e, const char*& value) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        chars = (m_cgiEnv.GetNext(e, value));
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetLastCgiEnv
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetLastCgiEnv
    (eCgiEnv& e, const char*& value) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        chars = (m_cgiEnv.GetLast(e, value));
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetPrevCgiEnv
    //
    //    Author: $author$
    //      Date: 6/29/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetPrevCgiEnv
    (eCgiEnv& e, const char*& value) const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        const char* chars = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        chars = (m_cgiEnv.GetPrev(e, value));
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputContent
    //
    //    Author: $author$
    //      Date: 6/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputContent
    (const cString& content)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        const char* chars;
        ssize_t length;
        if ((chars = content.Chars(length)))
            count = OutputContent(chars, length);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OutputContent
    //
    //    Author: $author$
    //      Date: 6/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutputContent
    (const char* chars, ssize_t length=-1)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_contentOutput))
            count = m_contentOutput->Write(chars, length);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetContentType
    //
    //    Author: $author$
    //      Date: 6/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SetContentType
    (const cString& contentType)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        if ((m_contentOutput))
            count = m_contentOutput->SetContentType(contentType);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetContentOutput
    //
    //    Author: $author$
    //      Date: 6/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cCgiContentStreamInterface* SetContentOutput
    (cCgiContentStreamInterface* contentOutput)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        m_contentOutput = (contentOutput);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        contentOutput = 0;
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return contentOutput;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetContentOutput
    //
    //    Author: $author$
    //      Date: 6/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cCgiContentStreamInterface* GetContentOutput() const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        cCgiContentStreamInterface* contentOutput = 0;
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
        contentOutput = (cCgiContentStreamInterface*)(m_contentOutput);
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
        return contentOutput;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetName
    //
    //    Author: $author$
    //      Date: 6/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const cString& SetName
    (const cString& toName)
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        m_name = (toName);
        return m_name;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#if !defined(CCGI_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetName
    //
    //    Author: $author$
    //      Date: 6/27/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const cString& GetName() const
#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
    {
        return m_name;
    }
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CCGI_MEMBER_FUNCS_IMPLEMENT) 

#if defined(CCGI_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetTheCgi
    //
    //    Author: $author$
    //      Date: 6/23/2011
    ///////////////////////////////////////////////////////////////////////
    static cCgiInterface* GetTheCgi();
#else // defined(CCGI_MEMBER_FUNCS_INTERFACE) 
#endif // defined(CCGI_MEMBER_FUNCS_INTERFACE) 

#if !defined(CCGI_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CCGI_MEMBERS_ONLY) 
#endif // !defined(CCGI_MEMBERS_ONLY) 

#endif // !defined(_CCGI_HPP) || defined(CCGI_MEMBERS_ONLY) 
