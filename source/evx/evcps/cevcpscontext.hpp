///////////////////////////////////////////////////////////////////////
//   File: cevcpscontext.hpp
//
// Author: $author$
//   Date: 12/16/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSCONTEXT_HPP
#define _CEVCPSCONTEXT_HPP

#include "cevcpsmessage.hpp"
#include "cevcpskeyblock.hpp"
#include "cevcpssecurityparameters.hpp"
#include "cevrsaprivatekey.hpp"
#include "cevrsapublickey.hpp"
#include "cevcipher.hpp"
#include "cevmd5.hpp"
#include "cevsha1.hpp"
#include "cevcryptodll.hpp"

#include "cevstringwriter.hpp"
#include "cevstringreader.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsContext
//
// Author: $author$
//   Date: 12/16/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsContext
: public CEvcpsMessage
{
public:
    typedef CEvcpsMessage CExtends;
    typedef CEvcpsContext CDerives;

    typedef EvCipher* Ciphers[EVCPS_BULK_CIPHER_ALGORITHMS];
    typedef EvHash* Hashes[EVCPS_MAC_ALGORITHMS];

    typedef LONG (CDerives::*MReadContent)
    (EvCharReader& reader,
     const CEvcpsRecord& record);

    EvRSAPublicKey* m_signerRSAPublic;
    EvRSAPrivateKey* m_signerRSAPrivate;
    EvRSAPublicKey* m_rsaPublic;
    EvRSAPrivateKey* m_rsaPrivate;
    EvDES3* m_readDes3;
    EvDES3* m_writeDes3;
    EvAES* m_readAes;
    EvAES* m_writeAes;
    EvMD5* m_md5;
    EvSHA1* m_sha1;

    CEvCipher m_nullCipher;
    CEvHash m_nullHash;

    CEvCryptoDll m_crypto;

    Ciphers m_readCiphers;
    Ciphers m_writeCiphers;
    Hashes m_hashes;

    EvCipher* m_readCipher;
    EvCipher* m_writeCipher;
    EvHash* m_hash;

    const BYTE* m_readMACSecret;
    const BYTE* m_writeMACSecret;

    ULONG m_blockSize;
    ULONG m_hashSize;

    UINT64 m_readSeqNumber;
    UINT64 m_writeSeqNumber;

    MReadContent m_readContent;

    CEvcpsGenericBlockCipher m_genericBlockCipher;

    CEvcpsPreMasterSecret m_preMasterSecret;
    CEvcpsMasterSecret m_masterSecret;

    CEvcpsSecurityParameters m_securityParameters;

    CEvcpsKeyBlock m_keyBlock;

    CEvBYTEString m_clientMACSecret;
    CEvBYTEString m_serverMACSecret;

    CEvBYTEString m_clientKey;
    CEvBYTEString m_serverKey;

    CEvBYTEString m_clientIV;
    CEvBYTEString m_serverIV;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsContext
    //
    //       Author: $author$
    //         Date: 12/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsContext() 
    : m_signerRSAPublic(0),
      m_signerRSAPrivate(0),
      m_rsaPublic(0),
      m_rsaPrivate(0),
      m_readDes3(0),
      m_writeDes3(0),
      m_readAes(0),
      m_writeAes(0),
      m_md5(0),
      m_sha1(0),

      m_readCipher(0),
      m_writeCipher(0),
      m_hash(0),

      m_readMACSecret(0),
      m_writeMACSecret(0),

      m_blockSize(0),
      m_hashSize(0),

      m_readSeqNumber(0),
      m_writeSeqNumber(0),

      m_readContent(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpsContext
    //
    //      Author: $author$
    //        Date: 12/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpsContext()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if ((m_signerRSAPrivate = m_crypto.AcquireRSAPrivateKey(error2)))
        if ((m_signerRSAPublic = m_crypto.AcquireRSAPublicKey(error2)))
        if ((m_rsaPrivate = m_crypto.AcquireRSAPrivateKey(error2)))
        if ((m_rsaPublic = m_crypto.AcquireRSAPublicKey(error2)))
        if ((m_readDes3 = m_crypto.AcquireDES3(error2)))
        if ((m_writeDes3 = m_crypto.AcquireDES3(error2)))
        if ((m_readAes = m_crypto.AcquireAES(error2)))
        if ((m_writeAes = m_crypto.AcquireAES(error2)))
        if ((m_md5 = m_crypto.AcquireMD5(error2)))
        if ((m_sha1 = m_crypto.AcquireSHA1(error2)))
        {
            InitializeCiphers();
            error = EV_ERROR_NONE;
        }

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize() 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;

        if ((error2 = m_crypto.ReleaseAllRSAPrivateKeys()))
            error = EV_ERROR_FAILED;
        if ((error2 = m_crypto.ReleaseAllRSAPublicKeys()))
            error = EV_ERROR_FAILED;
        if ((error2 = m_crypto.ReleaseAllDES3s()))
            error = EV_ERROR_FAILED;
        if ((error2 = m_crypto.ReleaseAllAESs()))
            error = EV_ERROR_FAILED;
        if ((error2 = m_crypto.ReleaseAllMD5s()))
            error = EV_ERROR_FAILED;
        if ((error2 = m_crypto.ReleaseAllSHA1s()))
            error = EV_ERROR_FAILED;

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: InitializeCiphers
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void InitializeCiphers() 
    {
        m_readCiphers[EVCPS_BULK_CIPHER_ALGORITHM_NULL] = &m_nullCipher;
        m_readCiphers[EVCPS_BULK_CIPHER_ALGORITHM_DES3] = m_readDes3;
        m_readCiphers[EVCPS_BULK_CIPHER_ALGORITHM_AES256] = m_readAes;

        m_writeCiphers[EVCPS_BULK_CIPHER_ALGORITHM_NULL] = &m_nullCipher;
        m_writeCiphers[EVCPS_BULK_CIPHER_ALGORITHM_DES3] = m_writeDes3;
        m_writeCiphers[EVCPS_BULK_CIPHER_ALGORITHM_AES256] = m_writeAes;

        m_hashes[EVCPS_MAC_ALGORITHM_NULL] = &m_nullHash;
        m_hashes[EVCPS_MAC_ALGORITHM_MD5] = m_md5;
        m_hashes[EVCPS_MAC_ALGORITHM_SHA1] = m_sha1;

        m_readCipher = 0;
        m_writeCipher = 0;
        m_hash = 0;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SignKeyExchange
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SignKeyExchange
    (CEvcpsRSAServerKeyExchange& serverKeyExchange,
     EvBYTEReader& randomReader) 
    {
        LONG length = CExtends::SignKeyExchange
        (serverKeyExchange, randomReader,
         *m_rsaPrivate, *m_md5, *m_sha1);
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CreateRSAPublicKey
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG CreateRSAPublicKey
    (const BYTE* rsaModulus, SHORT rsaModulusBytes,
     const BYTE* rsaExponent, SHORT rsaExponentBytes) 
    {
        LONG length = CreateRSAPublicKey
        (m_rsaPublic, rsaModulus, rsaModulusBytes,
         rsaExponent, rsaExponentBytes);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CreateRSAPrivateKey
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG CreateRSAPrivateKey
    (const BYTE* rsaP,const BYTE* rsaQ, 
     const BYTE* rsaDmp1, const BYTE* rsaDmq1,
     const BYTE* rsaIqmp, SHORT rsaPBytes) 
    { 
        LONG length = CreateRSAPrivateKey
        (m_rsaPrivate, rsaP, rsaQ, rsaDmp1, 
         rsaDmq1, rsaIqmp, rsaPBytes);
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CreateRSAPublicKey
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG CreateRSAPublicKey
    (EvRSAPublicKey*& rsaPublic,
     const BYTE* rsaModulus, SHORT rsaModulusBytes,
     const BYTE* rsaExponent, SHORT rsaExponentBytes) 
    {
        LONG length = -EV_ERROR_FAILED;
        EvError error;

        if (rsaPublic)
        if (!(error = rsaPublic->CreateMSB
            (rsaModulus, rsaModulusBytes,
             rsaExponent, rsaExponentBytes)))
             length = rsaModulusBytes;

        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CreateRSAPrivateKey
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG CreateRSAPrivateKey
    (EvRSAPrivateKey*& rsaPrivate,
     const BYTE* rsaP,const BYTE* rsaQ, 
     const BYTE* rsaDmp1, const BYTE* rsaDmq1,
     const BYTE* rsaIqmp, SHORT rsaPBytes) 
    { 
        LONG length = -EV_ERROR_FAILED;
        EvError error;

        if (rsaPrivate)
        if (!(error = rsaPrivate->CreateMSB
            (rsaP, rsaQ, rsaDmp1, rsaDmq1, rsaIqmp, rsaPBytes)))
             length = rsaPBytes + rsaPBytes;

        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ChangeToCipherSpec
    //
    //   Author: $author$
    //     Date: 12/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int ChangeToCipherSpec(bool on=true) 
    {
        int isOn = -EV_ERROR_FAILED;

        if (!on)
        {
            m_readContent = &CDerives::ReadPlainContent;
            return on;
        }

        if (m_readCipher 
            && m_writeCipher 
            && m_hash
            && m_readMACSecret
            && m_writeMACSecret)
        {
            m_readContent = &CDerives::ReadCipherContent;
            isOn = on;
        }
        return isOn;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadContent
    //
    //   Author: $author$
    //     Date: 12/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadContent
    (EvCharReader& reader,
     const CEvcpsRecord& record) 
    {
        LONG length = -EV_ERROR_FAILED;
        if (m_readContent)
            length = (this->*m_readContent)(reader, record);
        else length = CExtends::ReadContent(reader, record);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadPlainContent
    //
    //   Author: $author$
    //     Date: 12/7/2007
    ///////////////////////////////////////////////////////////////////////
    LONG ReadPlainContent
    (EvCharReader& reader,
     const CEvcpsRecord& record) 
    {
        LONG length = CExtends::ReadContent(reader, record);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadCipherContent
    //
    //   Author: $author$
    //     Date: 12/7/2007
    ///////////////////////////////////////////////////////////////////////
    LONG ReadCipherContent
    (EvCharReader& reader,
     const CEvcpsRecord& record) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count, count2;

        if (0 < (count = m_genericBlockCipher.
            Read(reader, record)))

        if (0 < (count = m_genericBlockCipher.
            Decrypt
            (m_readSeqNumber, record, 
             *m_readCipher, m_securityParameters.m_blockSize, 
             *m_hash, m_readMACSecret, m_securityParameters.m_hashSize)))

        if (0 <= (count2 = m_genericBlockCipher.m_value.Reset()))
        if (0 <= (count2 = ReadPlainContent
            (m_genericBlockCipher.m_valueCharReader, record)))
             length = count;

        return length;
    }
};
#endif // _CEVCPSCONTEXT_HPP
