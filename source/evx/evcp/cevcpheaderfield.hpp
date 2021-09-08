///////////////////////////////////////////////////////////////////////
//   File: cevcpheaderfield.hpp
//
// Author: $author$
//   Date: 4/19/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPHEADERFIELD_HPP
#define _CEVCPHEADERFIELD_HPP

#include "evcpheaderfield.hpp"
#include "evcpheaderfieldevents.hpp"
#include "cevcpheaderline.hpp"
#include "cevcpheaderfieldwriter.hpp"
#include "cevstringreader.hpp"
#include "cevstringwriter.hpp"
#include "cevstring.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpHeaderField
//
// Author: $author$
//   Date: 4/18/2007
///////////////////////////////////////////////////////////////////////
class CEvcpHeaderField
: virtual public EvcpHeaderField,
  virtual public EvcpHeaderFieldEvents,
  public CEvcpHeaderLine
{
public:
    typedef EvcpHeaderFieldEvents CImplements;
    typedef CEvcpHeaderLine CExtends;
    typedef CEvcpHeaderField CDerives;

    static const char m_separator;

    CEvStringReader m_stringReader;
    CEvStringWriter m_stringWriter;
    CEvcpHeaderFieldWriter m_fieldWriter;

    CEvString m_fieldName;
    CEvString m_fieldValue;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpHeaderField
    //
    //       Author: $author$
    //         Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpHeaderField
    (const char* name=0, 
     const char* value=0, bool hasCR=false) 
    : CExtends(hasCR),
      m_stringReader(*this),
      m_stringWriter(*this),
      m_fieldWriter(*this)
    {
        EvError error;
        LONG length;

        if (name)
        if (0 > (length = SetFieldName(name)))
            throw(error = -length);

        if (value)
        if (0 > (length = SetFieldValue(value)))
            throw(error = -length);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader, LONG length=-1) 
    {
        LONG count = -EV_ERROR_FAILED;
        EvError error;

        if (0 < (count = ReadLine(reader, length)))
        if (0 > (length = m_stringReader.Reset()))
            return -EV_ERROR_FAILED;

        else if ((error = m_fieldWriter.Initialize()))
                return -EV_ERROR_FAILED;

        else if (0 > (length = m_fieldWriter.WriteReader(m_stringReader)))
                return -EV_ERROR_FAILED;

        else if ((error = m_fieldWriter.Finalize()))
                return -EV_ERROR_FAILED;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 5/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer, LONG length=-1)
    {
        LONG count = 0;
        LONG written;

        if (0 > (written = m_fieldName.Write(writer, length)))
            return written;

        count += written;

        if (0 > (written = writer.Write
            (&m_separator, sizeof(m_separator))))
            return written;

        count += written;

        if (0 > (written = m_fieldValue.WriteLine(writer, length)))
            return written;

        count += written;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareFieldName
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareFieldName
    (const char* chars, LONG length=-1) const
    {
        int unequal = m_fieldName.Compare(chars, length);
        return unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetFieldName
    //
    //   Author: $author$
    //     Date: 4/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetFieldName
    (const char* chars, LONG length=-1) 
    {
        m_fieldName.Assign(chars, length);
        length = m_fieldName.Length();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFieldName
    //
    //   Author: $author$
    //     Date: 4/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetFieldName
    (LONG& length) const 
    {
        return m_fieldName.Chars(length);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareFieldValue
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareFieldValue
    (const char* chars, LONG length=-1) const
    {
        int unequal = m_fieldValue.Compare(chars, length);
        return unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetUnsignedFieldValue
    //
    //   Author: $author$
    //     Date: 5/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetUnsignedFieldValue
    (ULONG value) 
    {
        LONG length = m_fieldValue.AssignUnsigned(value);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetSignedFieldValue
    //
    //   Author: $author$
    //     Date: 5/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetSignedFieldValue
    (LONG value) 
    {
        LONG length = m_fieldValue.AssignSigned(value);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetFieldValue
    //
    //   Author: $author$
    //     Date: 4/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetFieldValue
    (const char* chars, LONG length=-1) 
    {
        m_fieldValue.Assign(chars, length);
        length = m_fieldValue.Length();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFieldValue
    //
    //   Author: $author$
    //     Date: 4/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetFieldValue
    (LONG& length) const 
    {
        return m_fieldValue.Chars(length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetSignedFieldValue
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG GetSignedFieldValue(LONG& digits) const 
    {
        LONG value = m_fieldValue.Signed(digits);
        return value;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetUnsignedFieldValue
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ULONG GetUnsignedFieldValue(LONG& digits) const 
    {
        ULONG value = m_fieldValue.Unsigned(digits);
        return value;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnFieldName
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFieldName(const char* chars) 
    {
        EvError error = EV_ERROR_NONE;
        SetFieldName(chars);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFieldValue
    //
    //   Author: $author$
    //     Date: 4/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFieldValue(const char* chars) 
    {
        EvError error = EV_ERROR_NONE;
        SetFieldValue(chars);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFieldCR
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFieldCR
    (const char* chars) 
    {
        EvError error = EV_ERROR_NONE;
        SetHasCR();
        return error;
    }
};

#endif // _CEVCPHEADERFIELD_HPP
