///////////////////////////////////////////////////////////////////////
//   File: cevcpspkcs1encryptionblock.hpp
//
// Author: $author$
//   Date: 11/24/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSPKCS1ENCRYPTIONBLOCK_HPP
#define _CEVCPSPKCS1ENCRYPTIONBLOCK_HPP

#include "cevcpsbase.hpp"
#include "cevbytereader.hpp"
#include "cevstring.hpp"
#include "cevstringwriter.hpp"
#include "cevstringreader.hpp"

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 11/25/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    PKCS1_TYPE_00_PADDED = 0,
    PKCS1_TYPE_FF_PADDED = 1,
    PKCS1_TYPE_XX_PADDED = 2,

    PKCS1_TYPE_PUBLIC_KEY_OPERATION = PKCS1_TYPE_XX_PADDED,
    PKCS1_TYPE_PRIVATE_KEY_OPERATION = PKCS1_TYPE_FF_PADDED,

    PKCS1_TYPE_MIN = PKCS1_TYPE_00_PADDED,
    PKCS1_TYPE_MAX = PKCS1_TYPE_XX_PADDED
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsPKCS1EncryptionBlock
//
// Author: $author$
//   Date: 11/24/2007
//
// 00 + (00 | FF | XX) + P + 00 + M
///////////////////////////////////////////////////////////////////////
class CEvcpsPKCS1EncryptionBlock
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsPKCS1EncryptionBlock CDerives;

    const BYTE m_00;
    const BYTE m_FF;

    BYTE m_type;

    CEvString m_padding;
    CEvString m_message;

    CEvStringWriter m_paddingWriter;
    CEvStringWriter m_messageWriter;
    CEvStringReader m_messageReader;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsPKCS1EncryptionBlock
    //
    //       Author: $author$
    //         Date: 11/24/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsPKCS1EncryptionBlock
    (BYTE type=PKCS1_TYPE_PRIVATE_KEY_OPERATION) 
    : m_00(0x00),
      m_FF(0xFF),
      m_type(type),
      m_paddingWriter(m_padding),
      m_messageWriter(m_message),
      m_messageReader(m_message)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Encode
    //
    //   Author: $author$
    //     Date: 11/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Encode
    (CEvcpsBase& message, 
     EvBYTEReader& random, 
     ULONG blockSize) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;
        USHORT size;

        if (blockSize < ((size = message.Sizeof())+3U))
            return length;

        if (0 > (count1 = Padd(random, blockSize-size-3)))
            return length;

        count1 += 3;

        if (0 > (count2 = m_message.Clear()))
            return length;

        if (0 > (count2 = message.Write(m_messageWriter)))
            return length;

        length = count1 + count2;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Encode
    //
    //   Author: $author$
    //     Date: 11/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Encode
    (const BYTE* message, 
     EvBYTEReader& random, 
     ULONG messageSize,
     ULONG blockSize) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;

        if (blockSize < (messageSize + 3))
            return length;

        if (0 > (count1 = Padd
            (random, blockSize-messageSize-3)))
            return length;

        if (0 > (count2 = m_message.Assign
            ((const char*)(message), messageSize)))
            return length;

        length = count1+count2+3;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CompareMessage
    //
    //   Author: $author$
    //     Date: 11/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareMessage
    (const char* chars,
     LONG length=-1) const
    {
        int unequal = m_message.Compare(chars,length);
        return unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMessage
    //
    //   Author: $author$
    //     Date: 11/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetMessage
    (LONG& length) const
    {
        const char* chars = m_message.HasChars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Padd
    //
    //   Author: $author$
    //     Date: 11/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Padd
    (EvBYTEReader& random, ULONG size) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count = 0;
        LONG count1;

        switch(m_type)
        {
        case PKCS1_TYPE_00_PADDED:
            return length = Padd(m_00, size);

        case PKCS1_TYPE_FF_PADDED:
            return length = Padd(m_FF, size);
        }

        if (0 > (count1 = m_padding.Clear()))
            return length;

        for (ULONG i=0; i<size; i++)
        {
            BYTE padded;

            if (0 > (count1 = random.
                Read(&padded, sizeof(padded))))
                return length;

            if (0 > (count1 = m_padding.
                Append((char*)&padded, sizeof(padded))))
                return length;

            count += count1;
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Padd
    //
    //   Author: $author$
    //     Date: 11/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Padd
    (BYTE padding, ULONG size) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count;

        if (0 > (count = m_padding.Clear()))
            return length;

        for (ULONG i=0; i<size; i++)
        {
            if (0 > (count = m_padding.
                Append((char*)&padding, sizeof(padding))))
                return length;
        }
        return size;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 11/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;
        BYTE byte;

        if (0 > (count1 = m_padding.Clear()))
            return length;

        if (0 > (count1 = m_message.Clear()))
            return length;

        if (0 > (count1 = reader.
            Read((char*)&byte, sizeof(byte))))
            return length;

        if (m_00 != byte)
            return length;

        if (0 > (count2 = reader.
            Read((char*)&byte, sizeof(byte))))
            return length;

        count1 += count2;

        if ((PKCS1_TYPE_MIN > byte)
            || (PKCS1_TYPE_MAX < byte))
            return length;

        count2 = -1;

        switch(m_type = byte)
        {
        case PKCS1_TYPE_00_PADDED:
            count2 = Read00(reader);
            break;
        case PKCS1_TYPE_FF_PADDED:
            count2 = ReadFF(reader);
            break;
        case PKCS1_TYPE_XX_PADDED:
            count2 = ReadXX(reader);
            break;
        }

        if (0 > count2)
            return length;

        count1 += count2;

        if (0 > (count2 = m_message.Read(reader)))
            return length;

        length = count1+count2;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read00
    //
    //   Author: $author$
    //     Date: 11/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read00
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1 = 0;
        LONG count2;
        BYTE byte;

        do
        {
            if (0 > (count2 = reader.
                Read((char*)&byte, sizeof(byte))))
                return length;

            count1 += count2;

            if (m_00 != byte)
            if (0 > (count2 = m_message.
                Append((char*)&byte, sizeof(byte))))
                return length;
            else return count1;

            if (0 > (count2 = m_padding.
                Append((char*)&byte, sizeof(byte))))
                return length;
        }
        while(0 < count2);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadFF
    //
    //   Author: $author$
    //     Date: 11/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadFF
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1 = 0;
        LONG count2;
        BYTE byte;

        do
        {
            if (0 > (count2 = reader.
                Read((char*)&byte, sizeof(byte))))
                return length;

            count1 += count2;

            if (m_00 == byte)
                return count1;
            else if (m_FF != byte)
                    return length;

            if (0 > (count2 = m_padding.
                Append((char*)&byte, sizeof(byte))))
                return length;
        }
        while(0 < count2);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadXX
    //
    //   Author: $author$
    //     Date: 11/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadXX
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1 = 0;
        LONG count2;
        BYTE byte;

        do
        {
            if (0 > (count2 = reader.
                Read((char*)&byte, sizeof(byte))))
                return length;

            count1 += count2;

            if (m_00 == byte)
                return count1;

            if (0 > (count2 = m_padding.
                Append((char*)&byte, sizeof(byte))))
                return length;
        }
        while(0 < count2);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 11/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;
        const char* chars;

        if (0 > (count1 = writer.
            Write((char*)&m_00, sizeof(m_00))))
            return length;

        if (0 > (count2 = writer.
            Write((char*)&m_type, sizeof(m_type))))
            return length;

        count1 += count2;

        if ((chars = m_padding.HasChars(count2)))
        if (0 > (count2 = writer.
            Write(chars, count2)))
            return length;
        else count1 += count2;

        if (0 > (count2 = writer.
            Write((char*)&m_00, sizeof(m_00))))
            return length;

        count1 += count2;

        if ((chars = m_message.HasChars(count2)))
        if (0 > (count2 = writer.
            Write(chars, count2)))
            return length;

        length = count1+count2;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 11/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = 0;
        return size;
    }
};

#endif // _CEVCPSPKCS1ENCRYPTIONBLOCK_HPP
