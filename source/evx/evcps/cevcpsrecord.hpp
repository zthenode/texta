///////////////////////////////////////////////////////////////////////
//   File: cevcpsrecord.hpp
//
// Author: $author$
//   Date: 12/5/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSRECORD_HPP
#define _CEVCPSRECORD_HPP

#include "cevcpsbase.hpp"
#include "cevcpsversion.hpp"

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 11/23/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    EVCPS_CONTENT_TYPE_CHANGE_CIPHER_SPEC = TLS_CONTENT_TYPE_CHANGE_CIPHER_SPEC,
    EVCPS_CONTENT_TYPE_ALERT              = TLS_CONTENT_TYPE_ALERT,
    EVCPS_CONTENT_TYPE_HANDSHAKE          = TLS_CONTENT_TYPE_HANDSHAKE,
    EVCPS_CONTENT_TYPE_APPLICATION_DATA   = TLS_CONTENT_TYPE_APPLICATION_DATA  
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsRecord
//
// Author: $author$
//   Date: 12/5/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsRecord
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsRecord CDerives;

    BYTE m_contentType;
    CEvcpsVersion m_version;
    UINT16 m_length;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsRecord
    //
    //       Author: $author$
    //         Date: 12/5/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsRecord
    (BYTE contentType=0,
     UINT16 length=0)
    : m_contentType(contentType),
      m_length(length) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsRecord
    //
    //       Author: $author$
    //         Date: 12/5/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsRecord
    (const CEvcpsRecord& record)
    : m_contentType(record.m_contentType),
      m_version(record.m_version),
      m_length(record.m_length) 
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2, count3;
        ULONG ulength;

        if (0 < (count1 = reader.Read
            ((char*)(&m_contentType), sizeof(m_contentType))))

        if (0 < (count2 = m_version.Read(reader)))

        if (0 < (count3 = reader.ReadUnsignedMSB
            (ulength, sizeof(m_length))))
        {
            m_length = (USHORT)(ulength);
            length = count1+count2+count3;
        }

        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 12/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;

        if (0 > (count1 = writer.Write
            ((char*)&m_contentType, sizeof(m_contentType))))
            return length;

        if (0 > (count2 = m_version.Write(writer)))
            return length;

        count1 += count2;

        if (0 > (count2 = writer.WriteUnsignedMSB
            (m_length, sizeof(m_length))))
            return length;

        length = count1 + count2;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 12/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = sizeof(m_contentType)
            + m_version.Sizeof()
            + sizeof(m_length) 
            + m_length;
        return size;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetContentType
    //
    //   Author: $author$
    //     Date: 12/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual BYTE SetContentType
    (BYTE contentType) 
    {
        return m_contentType = contentType;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetContentType
    //
    //   Author: $author$
    //     Date: 12/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual BYTE GetContentType() const 
    {
        return m_contentType;
    }
};

#endif // _CEVCPSRECORD_HPP
