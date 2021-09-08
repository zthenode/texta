///////////////////////////////////////////////////////////////////////
//   File: cevcpheader.hpp
//
// Author: $author$
//   Date: 4/20/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPHEADER_HPP
#define _CEVCPHEADER_HPP

#include "evcpheader.hpp"
#include "cevcpheaderheading.hpp"
#include "cevcpheaderfields.hpp"
#include "cevcpheaderfield.hpp"
#include "evcharreader.hpp"
#include "evcharwriter.hpp"
#include "cevstring.hpp"
#include "evdebug.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpHeader
//
// Author: $author$
//   Date: 4/18/2007
///////////////////////////////////////////////////////////////////////
class CEvcpHeader
: virtual public EvcpHeader,
  public CEvBase
{
public:
    typedef EvcpHeader CImplements;
    typedef CEvBase CExtends;
    typedef CEvcpHeader CDerives;

    static const char m_cr;
    static const char m_lf;

    CEvcpHeaderHeading m_heading;
    CEvcpHeaderFields m_fields;

    CEvString m_fieldValue;
    mutable const_CEvcpHeaderFieldsIterator m_fieldsIterator;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpHeader
    //
    //       Author: $author$
    //         Date: 4/18/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpHeader
    (const char* protocol=0,
     const char* protocolVersionMajor=0,
     const char* protocolVersionMinor=0) 
    {
        if (protocol)
            m_heading.SetProtocol(protocol);

        if (protocolVersionMajor)
            m_heading.SetProtocolVersionMajor(protocolVersionMajor);

        if (protocolVersionMinor)
            m_heading.SetProtocolVersionMinor(protocolVersionMinor);
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpHeader
    //
    //       Author: $author$
    //         Date: 4/18/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpHeader(const CEvcpHeader& header) 
    : m_heading(header.GetHeading())
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpHeader
    //
    //       Author: $author$
    //         Date: 4/18/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpHeader(const EvcpHeader& header) 
    : m_heading(header.GetHeading())
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpHeader
    //
    //      Author: $author$
    //        Date: 4/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpHeader()
    {
        EvError error;
        if ((error = ClearFields()))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 4/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader, LONG length=-1) 
    {
        LONG count = 0;
        LONG read;
        EvError error;
        CEvcpHeaderField* field;
        int fieldLength;

        DBT("() in...\n");

        if ((error = ClearAll()))
            return -error;

        if (0 >= (read = m_heading.Read(reader, length)))
            return -EV_ERROR_READ;

        if (0 >= m_heading.length())
            return read;

        do
        {
            count += read;

            if (0 < length) 
                length -= read;

            if ((field = NewField()))
            {
                if (0 < (read = field->Read(reader, length)))
                {
                    if (!(error = m_fields.AddField(*field)))
                    {
                        fieldLength = (int)(field->length());
                        continue;
                    }
                }
                else if (0 > read)
                        count = -EV_ERROR_READ;

                DeleteField(*field);
            }
            break;
        }
        while (0 < fieldLength);

        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 4/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer, LONG length=-1) 
    {
        LONG count = -EV_ERROR_FAILED;
        if (m_heading.GetIsResponse())
            count = WriteResponse(writer, length);
        else count = WriteRequest(writer, length);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: WriteRequest
    //
    //   Author: $author$
    //     Date: 4/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteRequest
    (EvCharWriter& writer, LONG length=-1) 
    {
        LONG count = 0;
        LONG written;

        if (0 > (written = m_heading.
            WriteRequest(writer, length)))
            return -EV_ERROR_FAILED;

        count += written;

        if (0 < length) 
            length -= written;

        if (0 > (written = WriteRest(writer, length)))
            return written;

        count += written;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteResponse
    //
    //   Author: $author$
    //     Date: 4/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteResponse
    (EvCharWriter& writer, LONG length=-1) 
    {
        LONG count = 0;
        LONG written;

        if (0 > (written = m_heading.
            WriteResponse(writer, length)))
            return -EV_ERROR_FAILED;

        count += written;

        if (0 < length) 
            length -= written;

        if (0 > (written = WriteRest(writer, length)))
            return written;

        count += written;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteRest
    //
    //   Author: $author$
    //     Date: 5/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteRest
    (EvCharWriter& writer, LONG length=-1) 
    {
        LONG count = 0;
        LONG written;

        if (0 > (written = WriteFields(writer, length)))
            return written;

        count += written;

        if (0 < length) 
            length -= written;

        if (0 != length)
        if (0 > (written = writer.Write(&m_lf, 1)))
            return -EV_ERROR_WRITE;

        count += written;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareField
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareField
    (const char* name, 
     const char* value, LONG length=-1) const 
    {
        int unequal = 1;
        EvcpHeaderField* field;

        if ((field = FindField(name)))
            unequal = field->CompareFieldValue(value, length);
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ClearAll
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ClearAll() 
    {
        EvError error = ClearFields();
        EvError error2;
        if ((error2 = m_heading.ClearAll()) && !error)
            error = error2;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFieldUnsigned
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpHeaderField* SetFieldUnsigned
    (const char* name, ULONG value, bool hasCR=false)
    {
        EvcpHeaderField* field = 0;
        const char* chars;
        LONG length;

        if (0 < (length = m_fieldValue.AssignUnsigned(value)))
        if ((chars = m_fieldValue.Chars(length)) && (0 < length))
            field = SetField(name, chars, hasCR);
        return field;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFieldUnsigned
    //
    //   Author: $author$
    //     Date: 7/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ULONG GetFieldUnsigned
    (LONG& digits, const char* name, LONG nameLength=-1) const 
    {
        ULONG value = 0;
        EvcpHeaderField* field;

        digits = 0;
        if ((field = FindField(name, nameLength)))
            value = field->GetUnsignedFieldValue(digits);
        return value;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFieldSigned
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpHeaderField* SetFieldSigned
    (const char* name, LONG value, bool hasCR=false)
    {
        EvcpHeaderField* field = 0;
        const char* chars;
        LONG length;

        if (0 < (length = m_fieldValue.AssignSigned(value)))
        if ((chars = m_fieldValue.Chars(length)) && (0 < length))
            field = SetField(name, chars, hasCR);
        return field;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFieldSigned
    //
    //   Author: $author$
    //     Date: 7/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG GetFieldSigned
    (LONG& digits, const char* name, LONG nameLength=-1) const 
    {
        LONG value = 0;
        EvcpHeaderField* field;

        digits = 0;
        if ((field = FindField(name, nameLength)))
            value = field->GetSignedFieldValue(digits);
        return value;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetField
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpHeaderField* SetField
    (const char* name, const char* value, bool hasCR=false)
    {
        EvcpHeaderField* field;
        LONG length;
        int has;

        if ((field = FindField(name)))
        {
            if ((0 > (length = field->SetFieldValue(value)))
                || (0 > (has = field->SetHasCR(hasCR))))
                field = 0;
        }
        else field = AddField(name, value);
        return field;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetField
    //
    //   Author: $author$
    //     Date: 7/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetField
    (LONG& length, const char* name, LONG nameLength=-1) const 
    {
        const char* chars = 0;
        EvcpHeaderField* field;

        length = 0;
        if ((field = FindField(name, nameLength)))
            chars = field->GetFieldValue(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AddField
    //
    //   Author: $author$
    //     Date: 5/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpHeaderField* AddField
    (const char* name, const char* value, bool hasCR=false)
    {
        CEvcpHeaderField* field;

        if ((field = NewField(name, value, hasCR)))
            m_fields.push_back(field);
        return field;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ClearFields
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ClearFields() 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        CEvcpHeaderFieldsIterator i;
        CEvcpHeaderField *field;

        for (i = m_fields.begin(); i != m_fields.end(); i++)
        {
            if ((field = *i))
            if ((error2 = DeleteField(*field)))
            if (!error)
                error = error2;
        }
        m_fields.clear();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveField
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RemoveField
    (const char* name, int length=-1)
    {
        CEvcpHeaderFieldsIterator iterator;
        EvError error = RemoveField(iterator, name, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveField
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RemoveField
    (CEvcpHeaderFieldsIterator& iterator,
     const char* name, int length=-1)
    {
        CEvcpHeaderField* field;
        EvError error;
        int unequal;

        for (iterator = m_fields.begin(); 
             iterator != m_fields.end(); iterator++)
        {
            if ((field = *iterator))
            if (!(unequal = field->CompareFieldName(name, length)))
            {
                m_fields.erase(iterator);
                error = DeleteField(*field);
                return error;
            }
        }
        return EV_ERROR_FAILED;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: WriteFields
    //
    //   Author: $author$
    //     Date: 5/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteFields
    (EvCharWriter& writer, LONG length=-1)
    {
        LONG count = 0;
        LONG written;
        CEvcpHeaderFieldsIterator i;
        CEvcpHeaderField *field;

        for (i = m_fields.begin(); i != m_fields.end(); i++)
        {
            if ((field = *i))
            if (0 > (written = field->Write(writer, length)))
                return written;
            else count += written;
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: FindField
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpHeaderField* FindField
    (const char* name, int length=-1) const 
    {
        EvcpHeaderField* field = 0;
        const_CEvcpHeaderFieldsIterator iterator;
        field = FindField(iterator, name, length);
        return field;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FindField
    //
    //   Author: $author$
    //     Date: 4/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpHeaderField* FindField
    (const_CEvcpHeaderFieldsIterator& iterator,
     const char* name, int length=-1) const 
    {
        EvcpHeaderField* field;
        int unequal;

        for (iterator = m_fields.begin(); 
             iterator != m_fields.end(); iterator++)
        {
            if ((field = *iterator))
            if (!(unequal = field->CompareFieldName(name, length)))
                return field;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetFirstField
    //
    //   Author: $author$
    //     Date: 5/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpHeaderField* GetFirstField
    (const_CEvcpHeaderFieldsIterator& iterator) const 
    {
        EvcpHeaderField* field = 0;

        if ((iterator = m_fields.begin()) != m_fields.end())
            field = *iterator;
        return field;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetNextField
    //
    //   Author: $author$
    //     Date: 5/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpHeaderField* GetNextField
    (const_CEvcpHeaderFieldsIterator& iterator) const 
    {
        EvcpHeaderField* field = 0;

        if ((++iterator != m_fields.end()))
            field = *iterator;
        return field;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: NewField
    //
    //   Author: $author$
    //     Date: 4/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual CEvcpHeaderField* NewField
    (const char* name=0, const char* value=0, bool hasCR=false) 
    {
        CEvcpHeaderField* field 
            = new CEvcpHeaderField
              (name, value, hasCR);
        return field;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteField
    //
    //   Author: $author$
    //     Date: 4/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteField(CEvcpHeaderField& field) 
    {
        EvError error = EV_ERROR_NONE;
        delete &field;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Heading
    //
    //   Author: $author$
    //     Date: 4/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpHeaderHeading& GetHeading() const 
    {
        return (EvcpHeaderHeading&)(m_heading);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetFieldsIterator
    //
    //   Author: $author$
    //     Date: 5/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const_CEvcpHeaderFieldsIterator& GetFieldsIterator() const 
    {
        return m_fieldsIterator;
    }
};

#endif // _CEVCPHEADER_HPP
