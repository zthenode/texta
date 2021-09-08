///////////////////////////////////////////////////////////////////////
//   File: cevcpsgenericblockcipher.hpp
//
// Author: $author$
//   Date: 12/4/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSGENERICBLOCKCIPHER_HPP
#define _CEVCPSGENERICBLOCKCIPHER_HPP

#include "cevcpsbase.hpp"
#include "cevcpsuint64.hpp"
#include "cevcpsplaintext.hpp"
#include "cevbytereadwritebuffer.hpp"
#include "cevbyte2charreader.hpp"
#include "cevchar2bytewriter.hpp"
#include "cevcipher.hpp"
#include "cevhash.hpp"
#include "cevcharhashwriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsGenericBlockCipher
//
// Author: $author$
//   Date: 12/4/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsGenericBlockCipher
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsGenericBlockCipher CDerives;

    USHORT m_size;
    CEvBYTEReadWriteBuffer m_value;
    CEvBYTE2CharReader m_valueCharReader;
    CEvChar2BYTEWriter m_valueCharWriter;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsGenericBlockCipher
    //
    //       Author: $author$
    //         Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsGenericBlockCipher() 
    : m_size(0),
      m_valueCharReader(m_value),
      m_valueCharWriter(m_value)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Encrypt
    //
    //   Author: $author$
    //     Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Encrypt
    (UINT64 seqNumber,
     CEvcpsPlaintext& plaintext,
     const BYTE* bytes, ULONG size,
     EvCipher& cipher, ULONG blockSize,
     EvHash& mac, const BYTE* macSecret, ULONG hashSize) 
    {
        LONG length = Encrypt
        (seqNumber, (CEvcpsRecord&)(plaintext), bytes, size,
         cipher, blockSize, mac, macSecret, hashSize);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Encrypt
    //
    //   Author: $author$
    //     Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Encrypt
    (UINT64 seqNumber,
     CEvcpsRecord& plaintext,
     const BYTE* bytes, ULONG size,
     EvCipher& cipher, ULONG blockSize,
     EvHash& mac, const BYTE* macSecret, ULONG hashSize) 
    {
        CEvcpsUint64 seqNumberUint64(seqNumber);
        CEvcpsRecord plaintextRecord(plaintext);
        CEvCharHashWriter macWriter(mac);
        LONG length = -EV_ERROR_FAILED;
        ULONG cipherSize = (size + hashSize + 1);
        ULONG cipherBlocks = (cipherSize + (blockSize-1))/blockSize;
        ULONG cipherBlocksSize = cipherBlocks*blockSize;
        BYTE paddingLength = (BYTE)(cipherBlocksSize - cipherSize);
        ULONG bufferSize;
        LONG count1;
        EvError error;
        BYTE* outBytes;

        m_size = 0;

        if (!(error = m_value.AllocateBuffer
            (bufferSize = cipherSize+paddingLength)))

        if ((outBytes = m_value.GetWriteBuffer(count1))
            && (count1 >= bufferSize))
        {
            memcpy(outBytes, bytes, size);

            if (0 < (count1 = mac.Initialize(macSecret, hashSize)))
            if (0 < (count1 = seqNumberUint64.Write(macWriter)))
            if (0 < (count1 = plaintextRecord.Write(macWriter)))
            if (0 < (count1 = mac.Hash(outBytes, size)))
            if (0 < (count1 = mac.Finalize(outBytes+size, hashSize)))
            {
                memset
                (outBytes+(cipherSize-1), 
                 paddingLength, paddingLength+1);

                if (0 < (count1 = cipher.Encrypt
                    (outBytes, bufferSize, outBytes, bufferSize)))
                {
                    m_size = bufferSize;
                    length = count1;
                }
            }
        }
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Decrypt
    //
    //   Author: $author$
    //     Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Decrypt
    (UINT64 seqNumber,
     const CEvcpsPlaintext& plaintext,
     EvCipher& cipher, ULONG blockSize,
     EvHash& mac, const BYTE* macSecret, ULONG hashSize) 
    {
        LONG length = Decrypt
        (seqNumber, plaintext, cipher, blockSize, 
         mac, macSecret, hashSize);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Decrypt
    //
    //   Author: $author$
    //     Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Decrypt
    (UINT64 seqNumber,
     const CEvcpsRecord& plaintext,
     EvCipher& cipher, ULONG blockSize,
     EvHash& mac, const BYTE* macSecret, ULONG hashSize) 
    {
        CEvcpsUint64 seqNumberUint64(seqNumber);
        CEvCharHashWriter macWriter(mac);
        ULONG cipherSize = plaintext.m_length;
        ULONG paddedSize = (cipherSize - hashSize - 1);
        LONG length = -EV_ERROR_FAILED;
        LONG count1;
        ULONG plainSize;
        BYTE paddingLength;
        BYTE* outBytes;

        if ((outBytes = m_value.GetWriteBuffer(count1))
            && (count1 >= cipherSize))

        if (cipherSize == (count1 = cipher.Decrypt
            (outBytes, cipherSize, outBytes, cipherSize)))

        if (blockSize > (paddingLength = outBytes[cipherSize-1]))

        if (0 < (plainSize = paddedSize - paddingLength))
            length = count1;

        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader,
     const CEvcpsRecord& plaintext) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;
        EvError error;
        BYTE* bytes;

        if (!(count1 = (LONG)(plaintext.m_length)))
            return 0;

        if (!(error = m_value.
            AllocateBuffer(plaintext.m_length)))

        if ((bytes = m_value.GetWriteBuffer(count2))
            && (count2 >= count1))

        if (count1 == (count2 = reader.
            Read((char*)(bytes), count1)))
            m_size = (SHORT)(length = count1);

        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1;
        const BYTE* bytes;

        if ((bytes = m_value.GetReadBuffer(count1))
            && (count1 >= (LONG)(m_size)))

        if (0 <= (count1 = writer.Write
            ((const char*)(bytes), m_size)))
            length = count1;

        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = m_size;
        return size;
    }
};

#endif // _CEVCPSGENERICBLOCKCIPHER_HPP
