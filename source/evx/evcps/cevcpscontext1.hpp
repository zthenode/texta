///////////////////////////////////////////////////////////////////////
//   File: cevcpscontext.hpp
//
// Author: $author$
//   Date: 12/6/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSCONTEXT_HPP
#define _CEVCPSCONTEXT_HPP

#include "cevcpevcpsfinishedrequest.hpp"
#include "cevcpevcpsloginresponse.hpp"
#include "cevcpevcpsloginrequest.hpp"

#include "cevcpscertificateverify.hpp"
#include "cevcpscertificaterequest.hpp"
#include "cevcpsloginresponsedone.hpp"
#include "cevcpsloginfinished.hpp"
#include "cevcpsrsaclientkeyexchange.hpp"

#include "cevrsaprivatekey.hpp"
#include "cevrsapublickey.hpp"
#include "cevcipher.hpp"
#include "cevmd5.hpp"
#include "cevsha1.hpp"
#include "cevcryptodll.hpp"

#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsContext
//
// Author: $author$
//   Date: 12/6/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsContext
: public CEvBase
{
public:
    typedef CEvBase CExtends;
    typedef CEvcpsContext CDerives;

    typedef EvCipher* Ciphers[EVCPS_BULK_CIPHER_ALGORITHMS];
    typedef EvHash* Hashes[EVCPS_MAC_ALGORITHMS];

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

    CEvcpsHandshakeBase m_handshake;

    CEvcpsLoginRequest m_loginRequest;
    CEvcpsLoginResponse m_loginResponse;
    CEvcpsLoginResponseDone m_loginResponseDone;
    CEvcpsLoginFinished m_loginFinished;

    CEvcpsCertificateRequest m_certificateRequest;
    CEvcpsCertificateVerify m_certificateVerify;
    CEvcpsCertificateList m_certificateList;

    CEvcpsRSAClientKeyExchange m_clientKeyExchange;
    CEvcpsRSAServerKeyExchange m_serverKeyExchange;

    CEvcpsRSAServerKeyExchange m_signeeKeyExchange;
    CEvcpsRSAServerKeyExchange m_signerKeyExchange;

    CEvcpsHandshake m_handshakeLoginRequest;
    CEvcpsHandshake m_handshakeLoginResponse;

    CEvcpsHandshake m_handshakeSigneeKeyExchange;
    CEvcpsHandshake m_handshakeSignerKeyExchange;

    CEvcpsHandshake m_handshakeCertificateList;

    CEvcpsHandshake m_handshakeClientKeyExchange;

    CEvcpsList m_handshakeMessages;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsContext
    //
    //       Author: $author$
    //         Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsContext() 
    : m_rsaPublic(0),
      m_rsaPrivate(0),
      m_readDes3(0),
      m_writeDes3(0),
      m_readAes(0),
      m_writeAes(0),
      m_md5(0),
      m_sha1(0),

      m_handshakeLoginRequest
      (m_loginRequest, EVCPS_HANDSHAKE_TYPE_LOGIN_REQUEST),

      m_handshakeLoginResponse
      (m_loginResponse, EVCPS_HANDSHAKE_TYPE_LOGIN_RESPONSE),

      m_handshakeSigneeKeyExchange
      (m_signeeKeyExchange, EVCPS_HANDSHAKE_TYPE_SERVER_KEY_EXCHANGE),

      m_handshakeSignerKeyExchange
      (m_signerKeyExchange, EVCPS_HANDSHAKE_TYPE_SERVER_KEY_EXCHANGE),

      m_handshakeCertificateList
      (m_certificateList, EVCPS_HANDSHAKE_TYPE_CERTIFICATE),

      m_handshakeClientKeyExchange
      (m_clientKeyExchange, EVCPS_HANDSHAKE_TYPE_CLIENT_KEY_EXCHANGE),

      m_handshakeMessages
      (&m_handshakeLoginRequest, 
       &m_handshakeLoginResponse,
       &m_handshakeSigneeKeyExchange,
       &m_handshakeSignerKeyExchange,
       &m_handshakeCertificateList,
       &m_handshakeClientKeyExchange, 0)
    {
        InitializeCiphers();
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpsContext
    //
    //      Author: $author$
    //        Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpsContext()
    {
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
        LONG length = serverKeyExchange.Sign
        (*m_rsaPrivate, *m_md5, *m_sha1, randomReader);
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
        LONG length = -EV_ERROR_FAILED;
        EvError error;

        if (m_rsaPublic)
        if (!(error = m_rsaPublic->CreateMSB
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
    (const BYTE* rsaP,const BYTE* rsaQ, 
     const BYTE* rsaDmp1, const BYTE* rsaDmq1,
     const BYTE* rsaIqmp, SHORT rsaPBytes) 
    { 
        LONG length = -EV_ERROR_FAILED;
        EvError error;

        if (m_rsaPrivate)
        if (!(error = m_rsaPrivate->CreateMSB
            (rsaP, rsaQ, rsaDmp1, rsaDmq1, rsaIqmp, rsaPBytes)))
             length = rsaPBytes + rsaPBytes;

        return length;
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
        int contentType = record.m_contentType;
        LONG length = -EV_ERROR_FAILED;
        LONG count1;

        switch(contentType)
        {
        case EVCPS_CONTENT_TYPE_CHANGE_CIPHER_SPEC:
            length = 0;
            break;

        case EVCPS_CONTENT_TYPE_ALERT:
            break;

        case EVCPS_CONTENT_TYPE_HANDSHAKE:
            if (0 < (count1 = ReadHandshake
                (reader, m_handshake)))
                length = count1;
            break;

        case EVCPS_CONTENT_TYPE_APPLICATION_DATA:
            break;
        }
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadHandshake
    //
    //   Author: $author$
    //     Date: 12/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadHandshake
    (EvCharReader& reader,
     CEvcpsHandshakeBase& handshake) 
    {
        LONG length  = -EV_ERROR_FAILED;
        LONG count1, count2;
        int type;

        if (0 < (count1 = handshake.Read(reader)))
        switch((type = handshake.m_type))
        {
        case EVCPS_HANDSHAKE_TYPE_LOGIN_REQUEST:
            if (0 <= (count2 = m_loginRequest.Read(reader)))
                length = count1+count2;
            break;

        case EVCPS_HANDSHAKE_TYPE_LOGIN_RESPONSE:
            if (0 <= (count2 = m_loginResponse.Read(reader)))
                length = count1+count2;
            break;

        case EVCPS_HANDSHAKE_TYPE_LOGIN_RESPONSE_DONE:
            if (0 <= (count2 = m_loginResponseDone.Read(reader)))
                length = count1+count2;
            break;

        case EVCPS_HANDSHAKE_TYPE_CERTIFICATE:
            if (0 <= (count2 = m_certificateList.Read(reader)))
                length = count1+count2;
            break;

        case EVCPS_HANDSHAKE_TYPE_CERTIFICATE_REQUEST:
            if (0 <= (count2 = m_certificateRequest.Read(reader)))
                length = count1+count2;
            break;

        case EVCPS_HANDSHAKE_TYPE_CERTIFICATE_VERIFY:
            if (0 <= (count2 = m_certificateVerify.Read(reader)))
                length = count1+count2;
            break;

        case EVCPS_HANDSHAKE_TYPE_CLIENT_KEY_EXCHANGE:
            if (0 <= (count2 = m_clientKeyExchange.Read(reader)))
                length = count1+count2;
            break;

        case EVCPS_HANDSHAKE_TYPE_SERVER_KEY_EXCHANGE:
            if (0 <= (count2 = m_serverKeyExchange.Read(reader)))
                length = count1+count2;
            break;

        case EVCPS_HANDSHAKE_TYPE_LOGIN_FINISHED:
            if (0 <= (count2 = m_loginFinished.Read(reader)))
                length = count1+count2;
            break;
        }
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader,
     CEvcpsRecord& record,
     CEvString& content) 
    {
        LONG length  = -EV_ERROR_FAILED;
        LONG count1, count2;
        
        if (0 <= (count1 = content.Clear()))
        if (0 < (count1 = record.Read(reader)))
        if (0 < (count2 = content.Read(reader, record.m_length)))
            length = count1+count2;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 12/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer,
     const CEvcpsRecord& record,
     const CEvString& content) 
    {
        LONG count = -EV_ERROR_FAILED;
        return count;
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
        EvError error = EV_ERROR_FAILED;
        error = EV_ERROR_NONE;
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
};
#endif // _CEVCPSCONTEXT_HPP
