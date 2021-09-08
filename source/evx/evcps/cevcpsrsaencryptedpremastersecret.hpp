///////////////////////////////////////////////////////////////////////
//   File: cevcpsrsaencryptedpremastersecret.hpp
//
// Author: $author$
//   Date: 11/29/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSRSAENCRYPTEDPREMASTERSECRET_HPP
#define _CEVCPSRSAENCRYPTEDPREMASTERSECRET_HPP

#include "cevcpspkcs1encryptionblock.hpp"
#include "cevcpspremastersecret.hpp"
#include "cevcpsshortopaque.hpp"
#include "cevrsaprivatekey.hpp"
#include "cevrsapublickey.hpp"
#include "cevreadwritebuffer.hpp"
#include "cevstringreader.hpp"
#include "cevstringwriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsRSAEncryptedPreMasterSecret
//
// Author: $author$
//   Date: 11/29/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsRSAEncryptedPreMasterSecret
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsRSAEncryptedPreMasterSecret CDerives;

    CEvcpsPKCS1EncryptionBlock m_pkcs1;
    CEvString m_pkcs1Plain;
    CEvStringReader m_pkcs1PlainReader;
    CEvStringWriter m_pkcs1PlainWriter;
    CEvCharReadWriteBuffer m_pkcs1Cipher;
    CEvcpsSHORTOpaque m_value;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsRSAEncryptedPreMasterSecret
    //
    //       Author: $author$
    //         Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsRSAEncryptedPreMasterSecret()
    : m_pkcs1(PKCS1_TYPE_PUBLIC_KEY_OPERATION),
      m_pkcs1PlainReader(m_pkcs1Plain),
      m_pkcs1PlainWriter(m_pkcs1Plain)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Encrypt
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Encrypt
    (CEvcpsPreMasterSecret& preMasterSecret,
     EvRSAPublicKey& rsaPublicKey,
     EvBYTEReader& random) 
    {
        ULONG modulusSize = rsaPublicKey.GetModulusBytes();
        LONG length = -EV_ERROR_FAILED;
        LONG count1;
        EvError error;
        const char* inChars;
        char* outChars;

        if (0 < (count1 = m_pkcs1.Encode
            (preMasterSecret, random, modulusSize)))

        if (0 <= (count1 = m_pkcs1Plain.Clear()))
        if (modulusSize == (count1 = m_pkcs1.Write(m_pkcs1PlainWriter)))
        if ((inChars = m_pkcs1Plain.HasChars(count1))
            && (modulusSize == count1))

        if (!(error = m_pkcs1Cipher.AllocateBuffer(modulusSize)))
        if ((outChars = m_pkcs1Cipher.GetWriteBuffer(count1))
            && (count1 >= modulusSize))

        if (modulusSize == (count1 = rsaPublicKey.Crypt
            ((BYTE*)(outChars), modulusSize,
             (const BYTE*)(inChars), modulusSize)))

        if (modulusSize <= (count1 = m_value.Assign
            ((BYTE*)(outChars), modulusSize)))
            length = count1;

        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Decrypt
    //
    //   Author: $author$
    //     Date: 12/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Decrypt
    (CEvcpsPreMasterSecret& preMasterSecret,
     EvRSAPrivateKey& rsaPrivateKey) 
    {
        ULONG modulusSize = rsaPrivateKey.GetModulusBytes();
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;
        EvError error;
        const BYTE* inChars;
        const char* chars;
        char* outChars;

        if ((inChars = m_value.HasChars(count1))
            && (count1 >= modulusSize))

        if (!(error = m_pkcs1Cipher.AllocateBuffer(modulusSize)))
        if ((outChars = m_pkcs1Cipher.GetWriteBuffer(count1))
            && (count1 >= modulusSize))

        if (modulusSize == (count1 = rsaPrivateKey.Crypt
            ((BYTE*)(outChars), modulusSize,
             (const BYTE*)(inChars), modulusSize)))

        if (modulusSize == (count1 = m_pkcs1Plain.Assign
            (outChars, modulusSize)))

        if (0 <= (count1 = m_pkcs1PlainReader.Reset()))

        if (modulusSize == (count1 = m_pkcs1.
            Read(m_pkcs1PlainReader)))

        if (0 <= (count2 = m_pkcs1.m_messageReader.Reset()))

        if (0 < (count2 = preMasterSecret.
            Read(m_pkcs1.m_messageReader)))
            length = count1;

        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = m_value.Read(reader);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = m_value.Write(writer);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = m_value.Sizeof();
        return size;
    }
};

#endif // _CEVCPSRSAENCRYPTEDPREMASTERSECRET_HPP
