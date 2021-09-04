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
 *   File: chttpurlencodedformfieldwriter.hxx
 *
 * Author: $author$
 *   Date: 3/18/2008
 **********************************************************************
 */
#ifndef _CHTTPURLENCODEDFORMFIELDWRITER_HXX
#define _CHTTPURLENCODEDFORMFIELDWRITER_HXX

#include "chttpformfield.hxx"
#include "cnamevaluewriterinterface.hxx"
#include "cnamevalueeventinterface.hxx"
#include "creaderinterface.hxx"
#include "cwriter.hxx"

#define CharIsX(x) \
    (((x) >= '0' && (x) <= '9') \
    || ((x) >= 'a' && (x) <= 'f') \
    || ((x) >= 'A' && (x) <= 'F'))

#define X2Char(x) \
    (((x) >= '0' && (x) <= '9')?((x)-'0') \
    :(((x) >= 'a' && (x) <= 'f')?((x)-'a'+10) \
    :((x)-'A'+10)))

#define Char2X(x) \
    (((x) >= 0 && (x) <= 9)?((x)+'0') \
    :(((x) >= 10 && (x) <= 15)?((x)+'a'-10) \
    :'.'))

#undef CDB_CLASS
#define CDB_CLASS "cHTTPURLEncodedFormFieldWriterT"
/**
 **********************************************************************
 *  Class: cHTTPURLEncodedFormFieldWriterT
 *
 * Author: $author$
 *   Date: 3/20/2008
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TString=cString,
 class TReader=cReaderInterface,
 class TEvent=cNameValueEventInterface,
 class TImplements=cNameValueWriterInterface,
 class TExtends=cCharWriter>
 
class cHTTPURLEncodedFormFieldWriterT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cHTTPURLEncodedFormFieldWriterT cDerives;

    typedef TLength (cDerives::*mPut)(TWhat what);
    typedef eError (cDerives::*mFinal)();

    TEvent* m_eventDelegate;

    mPut m_put;
    mPut m_oldPut;
    mFinal m_final;

    bool m_isFromQueryString;
    TString m_name;
    TString m_value;
    TString* m_string;
    TWhat m_percent;
    TWhat m_space;
    TWhat m_what;

    /**
     **********************************************************************
     * Constructor: cHTTPURLEncodedFormFieldWriterT
     *
     *      Author: $author$
     *        Date: 3/18/2008
     **********************************************************************
     */
    cHTTPURLEncodedFormFieldWriterT
    (TEvent* eventDelegate=0) 
    : m_eventDelegate(eventDelegate),
      m_put(&cDerives::PutError),
      m_oldPut(&cDerives::PutError),
      m_final(&cDerives::Final),
      m_isFromQueryString(false),
      m_string(&m_name),
      m_percent('%'),
      m_space(' '),
      m_what(0)
    {
    }
    /**
     **********************************************************************
     * Destructor: cHTTPURLEncodedFormFieldWriterT
     *
     *     Author: $author$
     *       Date: 3/18/2008
     **********************************************************************
     */
    virtual ~cHTTPURLEncodedFormFieldWriterT()
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;
        m_put = &cDerives::PutName;
        m_final = &cDerives::Final;
        m_string = &m_name;
        m_name.Clear();
        m_value.Clear();
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = e_ERROR_NONE;
        if (m_final)
            error = (this->*m_final)();
        m_put = &cDerives::PutName;
        m_final = &cDerives::Final;
        m_string = &m_name;
        m_name.Clear();
        m_value.Clear();
        return error;
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
    (const TWhat* name,
     const TWhat* value) 
    {
        eError error = e_ERROR_NONE;
        if (m_eventDelegate)
            m_eventDelegate->OnNameValue(name, value);
        return error;
    }
    /**
     **********************************************************************
     * Function: Final
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    eError Final() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: FinalValue
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    eError FinalValue() 
    {
        eError error = e_ERROR_FAILED;
        const TWhat* name;
        const TWhat* value;
        TLength length;
        if ((name = m_name.HasChars(length)))
        if ((value = m_value.Chars(length)))
            error = OnNameValue(name, value);
        return error;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    virtual TLength Write
    (TReader& reader, TLength length=-1) 
    {
        TLength count = -e_ERROR_FAILED;
        TLength count2;
        TWhat what;

        if (0 <= length)
        for (count=0; count<length; count += count2)
        {
            if (0 >= (count2 = reader.Read(&what, 1)))
                return count2;
            if (0 >= (count2 = Put(what)))
                return count2;
        }
        else
        for (count=0; ; count += count2)
        {
            if (0 > (count2 = reader.Read(&what, 1)))
                return count;
            if (0 >= (count2 = Put(what)))
                return count2;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    virtual TLength Write
    (const TWhat* what, TLength length=-1) 
    {
        TLength count = -e_ERROR_FAILED;
        TLength count2;

        if (0 <= length)
        for (count=0; count<length; count += count2)
        {
            if (0 >= (count2 = Put(what[count])))
                return count2;
        }
        else
        for (count=0; what[count]!=0; count += count2)
        {
            if (0 >= (count2 = Put(what[count])))
                return count2;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    virtual TLength Put(TWhat what) 
    {
        TLength length = -e_ERROR_FAILED;
        if (m_put)
            length = (this->*m_put)(what);
        return length;
    }
    /**
     **********************************************************************
     * Function: PutError
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    TLength PutError(TWhat what) 
    {
        TLength length = -e_ERROR_FAILED;
        return length;
    }
    /**
     **********************************************************************
     * Function: PutName
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    TLength PutName(TWhat what) 
    {
        TLength length = 1;
        eError error;
        switch(what)
        {
        case '%':
            m_string = &m_value;
            m_oldPut = m_put;
            m_put = &cDerives::PutX1;
            break;
        case '&':
            if ((error = FinalValue()))
                length = -error;
            m_name.Clear();
            break;
        case '=':
            m_value.Clear();
            m_put = &cDerives::PutValue;
            m_final = &cDerives::FinalValue;
            break;
        case '+':
            if (0 >= (length = m_name.Append(&m_space, 1)))
                m_put = &cDerives::PutError;
            break;
        default:
            if (0 >= (length = m_name.Append(&what, 1)))
                m_put = &cDerives::PutError;
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: PutValue
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    TLength PutValue(TWhat what) 
    {
        TLength length = 1;
        eError error;
        switch(what)
        {
        case '%':
            m_string = &m_value;
            m_oldPut = m_put;
            m_put = &cDerives::PutX1;
            break;
        case '&':
        case '\n':
            if ((error = FinalValue()))
                length = -error;
            m_name.Clear();
            m_put = &cDerives::PutName;
            m_final = &cDerives::Final;
            break;
        case '+':
            if (0 >= (length = m_value.Append(&m_space, 1)))
                m_put = &cDerives::PutError;
            break;
        default:
            if (0 >= (length = m_value.Append(&what, 1)))
                m_put = &cDerives::PutError;
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: PutX1
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    TLength PutX1(TWhat what) 
    {
        TLength length = 1;
        if (CharIsX(what))
        {
            m_what = X2Char(what);
            m_put = &cDerives::PutX2;
        }
        else
        m_put = m_oldPut;
        return length;
    }
    /**
     **********************************************************************
     * Function: PutX2
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    TLength PutX2(TWhat what) 
    {
        TLength length = 1;
        if (CharIsX(what))
        {
            m_what <<= 4;
            m_what |= X2Char(what);
            if (0 >= (length = m_string->Append(&m_what, 1)))
                m_put = &cDerives::PutError;
            else
            m_put = m_oldPut;
        }
        else
        m_put = m_oldPut;
        return length;
    }
    /**
     **********************************************************************
     * Function: SetEventDelegate
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    virtual TEvent* SetEventDelegate
    (TEvent* delegate) 
    {
        TEvent* oldDelegate = m_eventDelegate;
        m_eventDelegate = delegate;
        return oldDelegate;
    }
    /**
     **********************************************************************
     * Function: GetEventDelegate
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    virtual TEvent* GetEventDelegate() const 
    {
        return m_eventDelegate;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cHTTPURLEncodedFormFieldWriter
 *
 * Author: $author$
 *   Date: 3/20/2008
 **********************************************************************
 */
class cHTTPURLEncodedFormFieldWriter
: virtual public cHTTPURLEncodedFormFieldWriterT
  <char,TSIZE,TLENGTH,cCharString,cCharReaderInterface,
   cNameValueEventInterface,cNameValueWriterInterface,cCharWriter>
{
public:
    typedef cHTTPURLEncodedFormFieldWriterT
    <char,TSIZE,TLENGTH,cCharString,cCharReaderInterface,
     cNameValueEventInterface,cNameValueWriterInterface,cCharWriter> cExtends;
    /**
     **********************************************************************
     * Constructor: cHTTPURLEncodedFormFieldWriter
     *
     *      Author: $author$
     *        Date: 3/20/2008
     **********************************************************************
     */
    cHTTPURLEncodedFormFieldWriter
    (cNameValueEventInterface* eventDeligate=0)
    : cExtends(eventDeligate) 
    {
    }
};
#endif /* _CHTTPURLENCODEDFORMFIELDWRITER_HXX */
