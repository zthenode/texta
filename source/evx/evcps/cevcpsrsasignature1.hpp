///////////////////////////////////////////////////////////////////////
//   File: cevcpsrsasignature.hpp
//
// Author: $author$
//   Date: 11/26/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSRSASIGNATURE_HPP
#define _CEVCPSRSASIGNATURE_HPP

#include "cevcpsbase.hpp"
#include "cevcpsserverrsaparams.hpp"
#include "cevcpspkcs1encryptionblock.hpp"
#include "evrsaprivatekey.hpp"
#include "evrsapublickey.hpp"
#include "evmd5.hpp"
#include "evsha1.hpp"
#include "cevcharhashwriter.hpp"
#include "cevreadwritebuffer.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsRSASignature
//
// Author: $author$
//   Date: 11/26/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsRSASignature
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsRSASignature CDerives;

    CEvcpsPKCS1EncryptionBlock m_pkcs1;
    CEvString m_pkcs1Unsigned;
    CEvStringWriter m_pkcs1UnsignedWriter;

    BYTE m_hashes[EvMD5::EV_HASH_SIZE+EvSHA1::EV_HASH_SIZE];
    BYTE& m_md5Hash;
    BYTE& m_sha1Hash;

    CEvCharReadWriteBuffer m_pkcs1Signed;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsRSASignature
    //
    //       Author: $author$
    //         Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsRSASignature() 
    : m_pkcs1(PKCS1_TYPE_PRIVATE_KEY_OPERATION),
      m_pkcs1UnsignedWriter(m_pkcs1Unsigned),
      m_md5Hash(*m_hashes),
      m_sha1Hash(*(m_hashes+EvMD5::EV_HASH_SIZE))
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Sign
    //
    //   Author: $author$
    //     Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Sign
    (CEvcpsServerRSAParams& signee, 
     EvRSAPrivateKey& signer,
     EvMD5& md5, EvSHA1& sha1,
     EvBYTEReader& random) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count;
        ULONG modulusSize;
        EvError error;
        const char* inChars;
        char* outChars;

        if (0 > (count = signer.GetModulusBytes()))
            return length;

        modulusSize = count;

        if (0 < (count = Hash
            (&m_md5Hash, sizeof(m_hashes), md5, signee)))

        if (0 < (count = Hash
            (&m_sha1Hash, sizeof(m_hashes), sha1, signee)))

        if (modulusSize == (count = m_pkcs1.Encode
            (m_hashes, random, sizeof(m_hashes), modulusSize)))

        if (0 <= (count = m_pkcs1Unsigned.Clear()))
        if (modulusSize == (count = m_pkcs1.Write(m_pkcs1UnsignedWriter)))
        if ((inChars = m_pkcs1Unsigned.HasChars(count))
            && (modulusSize == count))

        if (!(error = m_pkcs1Signed.AllocateBuffer(modulusSize)))
        if ((outChars = m_pkcs1Signed.GetWriteBuffer(count))
            && (modulusSize == count))

        if (modulusSize == (count = signer.Crypt
            ((BYTE*)(outChars), modulusSize,
             (const BYTE*)(inChars), modulusSize)))
            length = count;

        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Verify
    //
    //   Author: $author$
    //     Date: 11/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Verify
    (CEvcpsServerRSAParams& signee, 
     EvRSAPublicKey& signer,
     EvMD5& md5, EvSHA1& sha1) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count;
        ULONG modulusSize;
        const char* inChars;
        char* outChars;
        int unequal;

        if (0 > (count = signer.GetModulusBytes()))
            return length;

        modulusSize = count;

        if (0 < (count = Hash
            (&m_md5Hash, sizeof(m_hashes), md5, signee)))

        if (0 < (count = Hash
            (&m_sha1Hash, sizeof(m_hashes), sha1, signee)))

        if ((outChars = m_pkcs1Signed.GetWriteBuffer(count)))

        if (modulusSize == (count = m_pkcs1Unsigned.
            Assign(outChars, count)))
        if ((inChars = m_pkcs1Unsigned.HasChars(count)))

        if (modulusSize == (count = signer.Crypt
            ((BYTE*)(outChars), modulusSize,
             (const BYTE*)(inChars), modulusSize)))

        if (0 < (count = m_pkcs1.Read(m_pkcs1Signed)))

        if (!(unequal = m_pkcs1.CompareMessage
            ((char*)(m_hashes), sizeof(m_hashes))))
            length = count;

        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Hash
    //
    //   Author: $author$
    //     Date: 11/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Hash
    (BYTE* hashed, ULONG hashSize, 
     EvHash& hash, CEvcpsServerRSAParams& signee) 
    {
        CEvCharHashWriter hashWriter(hash);
        LONG length = -EV_ERROR_FAILED;
        LONG count;

        if (0 <= (count = hash.Initialize()))
        if (0 < (count = signee.Write(hashWriter)))
        if (0 < (count = hash.Finalize(hashed, hashSize)))
            length = count;

        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadX
    //
    //   Author: $author$
    //     Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadX
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteX
    //
    //   Author: $author$
    //     Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteX
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count;
        const char* chars;

        if ((chars = m_pkcs1Signed.
            GetReadBuffer(count)) && (0 < count))
            length = writer.WriteX(chars, count);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = 0;
        LONG count;
        if (0 < (count = m_pkcs1Signed.GetSize()))
            size = (USHORT)(count);
        return size;
    }
};

#endif // _CEVCPSRSASIGNATURE_HPP
