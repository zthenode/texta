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
 *   File: cnamevaluewriter.hxx
 *
 * Author: $author$
 *   Date: 3/18/2008
 **********************************************************************
 */
#ifndef _CNAMEVALUEWRITER_HXX
#define _CNAMEVALUEWRITER_HXX

#include "cnamevalueeventinterface.hxx"
#include "creaderinterface.hxx"
#include "cwriter.hxx"
#include "cstring.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cNameValueWriterT"
/**
 **********************************************************************
 *  Class: cNameValueWriterT
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
 class TImplements=cNameValueEventInterface,
 class TExtends=cCharWriter>
 
class cNameValueWriterT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cNameValueWriterT cDerives;

    typedef TLength (cDerives::*mPut)(TWhat what);
    typedef eError (cDerives::*mFinal)();

    TImplements* m_eventDelegate;

    mPut m_put;
    mPut m_oldPut;
    mFinal m_final;

    TString m_name;
    TString m_value;

    /**
     **********************************************************************
     * Constructor: cNameValueWriterT
     *
     *      Author: $author$
     *        Date: 3/18/2008
     **********************************************************************
     */
    cNameValueWriterT
    (TImplements* eventDelegate=0) 
    : m_eventDelegate(eventDelegate),
      m_put(&cDerives::PutError),
      m_oldPut(&cDerives::PutError),
      m_final(&cDerives::Final) 
    {
    }
    /**
     **********************************************************************
     * Destructor: cNameValueWriterT
     *
     *     Author: $author$
     *       Date: 3/18/2008
     **********************************************************************
     */
    virtual ~cNameValueWriterT()
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
        case '=':
            m_value.Clear();
            m_put = &cDerives::PutValue;
            m_final = &cDerives::FinalValue;
            break;
        case '\n':
            if ((error = FinalValue()))
                length = -error;
            m_name.Clear();
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
        case '\n':
            if ((error = FinalValue()))
                length = -error;
            m_name.Clear();
            m_put = &cDerives::PutName;
            m_final = &cDerives::Final;
            break;
        default:
            if (0 >= (length = m_value.Append(&what, 1)))
                m_put = &cDerives::PutError;
        }
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
    virtual TImplements* SetEventDelegate
    (TImplements* delegate) 
    {
        TImplements* oldDelegate = m_eventDelegate;
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
    virtual TImplements* GetEventDelegate() const 
    {
        return m_eventDelegate;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cNameValueWriter
 *
 * Author: $author$
 *   Date: 3/20/2008
 **********************************************************************
 */
class cNameValueWriter
: public cNameValueWriterT
  <char,TSIZE,TLENGTH,
   cCharString,cCharReaderInterface,
   cNameValueEventInterface,cCharWriter>
{
public:
    typedef cNameValueWriterT
    <char,TSIZE,TLENGTH,
     cCharString,cCharReaderInterface,
     cNameValueEventInterface,cCharWriter> cExtends;
    /**
     **********************************************************************
     * Constructor: cNameValueWriter
     *
     *      Author: $author$
     *        Date: 3/20/2008
     **********************************************************************
     */
    cNameValueWriter
    (cNameValueEventInterface* eventDeligate=0)
    : cExtends(eventDeligate)
    {
    }
};
#endif /* _CNAMEVALUEWRITER_HXX */
