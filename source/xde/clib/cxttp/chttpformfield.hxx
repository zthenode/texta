/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: chttpformfield.hxx
 *
 * Author: $author$
 *   Date: 3/17/2008
 **********************************************************************
 */
#ifndef _CHTTPFORMFIELD_HXX
#define _CHTTPFORMFIELD_HXX

#include "chttpformfieldinterface.hxx"
#include "cnamevalueeventinterface.hxx"
#include "cinstance.hxx"
#include "creference.hxx"
#include "cstring.hxx"
#include "cvector.hxx"

/**
 **********************************************************************
 *  Class: cHTTPFormField
 *
 * Author: $author$
 *   Date: 3/17/2008
 **********************************************************************
 */
class cHTTPFormField
: virtual public cHTTPFormFieldInterface,
  public cInstance
{
public:
    typedef cCharString TString;

    typedef cHTTPFormFieldInterface cImplements;
    typedef cInstance cExtends;
    typedef cHTTPFormField cDerives;

    bool m_isFromQueryString;
    TString m_name, m_value;

    /**
     **********************************************************************
     * Constructor: cHTTPFormField
     *
     *      Author: $author$
     *        Date: 3/17/2008
     **********************************************************************
     */
    cHTTPFormField
    (const TChar* name=0,
     const TChar* value=0,
     bool isFromQueryString=false,
     bool isStaticInstance=true) 
    : cExtends(isStaticInstance),
      m_isFromQueryString(isFromQueryString)
    {
        TLength length;
        eError error;

        if (name)
        if (0 > (length = SetName(name)))
            throw(error = -length);
 
        if (value)
        if (0 > (length = SetValue(value)))
            throw(error = -length);
   }
    /**
     **********************************************************************
     * Destructor: cHTTPFormField
     *
     *     Author: $author$
     *       Date: 3/17/2008
     **********************************************************************
     */
    virtual ~cHTTPFormField()
    {
    }
    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual TLength SetName
    (const TChar* chars,
     TLength length=-1) 
    {
        TLength count = m_name.Assign(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: CompareName
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual int CompareName
    (const TChar* toChars, 
     TLength length=-1) const
    {
        int unequal = m_name.Compare(toChars, length);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual const TChar* GetName
    (TLength& length) const 
    {
        const TChar* chars = m_name.Chars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual TLength SetValue
    (const TChar* chars,
     TLength length=-1) 
    {
        TLength count = m_value.Assign(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: CompareValue
     *
     *   Author: $author$
     *     Date: 12/29/2008
     **********************************************************************
     */
    virtual int CompareValue
    (const TChar* toChars, 
     TLength length=-1) const
    {
        int unequal = m_value.Compare(toChars, length);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual const TChar* GetValue
    (TLength& length) const 
    {
        const TChar* chars = m_value.Chars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetIsFromQueryString
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual bool SetIsFromQueryString(bool is=true) 
    {
        m_isFromQueryString = is;
        return m_isFromQueryString;
    }
    /**
     **********************************************************************
     * Function: GetIsFromQueryString
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual bool GetIsFromQueryString() const 
    {
        return m_isFromQueryString;
    }
    /**
     **********************************************************************
     * Function: DeleteThis
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual eError DeleteThis()
    {
        eError error = e_ERROR_NONE;
        bool isStaticInstance;
        if ((isStaticInstance = GetIsStaticInstance()))
            return e_ERROR_STATIC_INSTANCE;
        delete this;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cHTTPFormFieldReference
 *
 * Author: $author$
 *   Date: 3/17/2008
 **********************************************************************
 */
class cHTTPFormFieldReference
: public cReferenceT<cHTTPFormFieldInterface, cReferenced>
{
public:
    typedef cReferenceT<cHTTPFormFieldInterface, cReferenced> cExtends;
};

/**
 **********************************************************************
 *  Typedef: cHTTPFormFieldVectorInterface
 *
 *  Author: $author$
 *    Date: 3/17/2008
 **********************************************************************
 */
typedef cVectorInterfaceT
<cHTTPFormFieldReference,
 TSIZE,TLENGTH,UNDEFINED_LENGTH,cInterfaceBase>
cHTTPFormFieldVectorInterface;

/**
 **********************************************************************
 * Typedef: cHTTPFormFieldVectorExtends
 *
 *  Author: $author$
 *    Date: 3/13/2008
 **********************************************************************
 */
typedef std::vector
<cHTTPFormFieldReference>
cHTTPFormFieldVectorExtends;

/**
 **********************************************************************
 *  Typedef: cHTTPFormFieldVector
 *
 *  Author: $author$
 *    Date: 3/17/2008
 **********************************************************************
 */
typedef cVectorT
<cHTTPFormFieldReference, TSIZE,TLENGTH,UNDEFINED_LENGTH,
 cHTTPFormFieldVectorInterface, cHTTPFormFieldVectorExtends>
cHTTPFormFieldVector;

/**
 **********************************************************************
 *  Typedef: cHTTPFormFieldIterator
 *
 *  Author: $author$
 *    Date: 3/25/2008
 **********************************************************************
 */
typedef cHTTPFormFieldVector::iterator
cHTTPFormFieldIterator;

/**
 **********************************************************************
 *  Class: cHTTPFormFields
 *
 * Author: $author$
 *   Date: 3/17/2008
 **********************************************************************
 */
class cHTTPFormFields
: virtual public cNameValueEventInterface,
  public cBase
{
public:
    typedef cNameValueEventInterface cImplements;
    typedef cBase cExtends;
    typedef cHTTPFormFields cDerives;

    typedef char TChar;
    typedef TSIZE TSize;
    typedef TLENGTH TLength;

    cHTTPFormFieldVector m_fields;
    bool m_isFromQueryString;

    /**
     **********************************************************************
     * Constructor: cHTTPFormFields
     *
     *      Author: $author$
     *        Date: 3/17/2008
     **********************************************************************
     */
    cHTTPFormFields
    (bool isFromQueryString=false) 
    : m_isFromQueryString(isFromQueryString)
    {
    }
    /**
     **********************************************************************
     * Destructor: cHTTPFormFields
     *
     *     Author: $author$
     *       Date: 3/17/2008
     **********************************************************************
     */
    virtual ~cHTTPFormFields()
    {
    }
    /**
     **********************************************************************
     * Function: OnNameValue
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    eError OnNameValue
    (const TChar* name,
     const TChar* value) 
    {
        eError error = e_ERROR_NONE;
        AddField(name, value, m_isFromQueryString);
        return error;
    }
    /**
     **********************************************************************
     * Function: AddField
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual cHTTPFormFieldReference AddField
    (const TChar* name,
     const TChar* value=0,
     bool isFromQueryString=false) 
    {
        cHTTPFormFieldReference fieldRef;
        cHTTPFormField* field;

        if ((field = new cHTTPFormField
            (name, value, isFromQueryString, false)))
        {
            fieldRef.Set(field);
            m_fields.Append(&fieldRef, 1);
        }
        return fieldRef;
    }
    /**
     **********************************************************************
     * Function: FindField
     *
     *   Author: $author$
     *     Date: 3/17/2008
     **********************************************************************
     */
    virtual cHTTPFormFieldReference FindField
    (const TChar* name, TLength length=-1) const
    {
        cHTTPFormFieldReference fieldRef;
        cHTTPFormFieldVector::const_iterator i;
        int unequal;

        for (i = m_fields.begin(); i != m_fields.end(); i++)
        {
            const cHTTPFormFieldReference& f = *i;
            if (f)
            if (!(unequal = f->CompareName(name, length)))
                fieldRef = f;
        }
        return fieldRef;
    }
    /**
     **********************************************************************
     * Function: begin
     *
     *   Author: $author$
     *     Date: 3/25/2008
     **********************************************************************
     */
    virtual cHTTPFormFieldIterator begin() 
    {
        return m_fields.begin();
    }
    /**
     **********************************************************************
     * Function: end
     *
     *   Author: $author$
     *     Date: 3/25/2008
     **********************************************************************
     */
    virtual cHTTPFormFieldIterator end() 
    {
        return m_fields.end();
    }
};
#endif /* _CHTTPFORMFIELD_HXX */
