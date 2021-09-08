///////////////////////////////////////////////////////////////////////
//   File: evli.hpp
//
// Author: $author$
//   Date: 12/11/2007
///////////////////////////////////////////////////////////////////////

#ifndef _EVLI_HPP
#define _EVLI_HPP

#include "cevcpclientmain.hpp"

#include "cevcpevcpsfinishedresponse.hpp"
#include "cevcpevcpsfinishedrequest.hpp"
#include "cevcpevcpscertificaterequest.hpp"
#include "cevcpevcpsloginresponse.hpp"
#include "cevcpevcpsloginrequest.hpp"

#include "cevcpssecurityparameters.hpp"
#include "cevcpsmessagereadevents.hpp"

#include "cevcpskeyblock.hpp"
#include "cevcpssecurityparameters.hpp"
#include "cevcpsclientfinished.hpp"
#include "cevcpsmastersecret.hpp"
#include "cevcpsrsaclientkeyexchange.hpp"
#include "cevcpevcpscertificaterequest.hpp"
#include "cevcpscertificatelist.hpp"

#include "cevcpsloginresponsedone.hpp"
#include "cevcpsloginresponse.hpp"
#include "cevcpsloginrequest.hpp"
#include "cevpseudorandombytereader.hpp"
#include "cevcpspkcs1encryptionblock.hpp"
#include "cevcpsserverrsaparams.hpp"
#include "cevcpsrsasignature.hpp"
#include "cevrsaprivatekey.hpp"
#include "cevrsapublickey.hpp"

#include "cevrsaprivatekey.hpp"
#include "cevrsapublickey.hpp"
#include "cevcipher.hpp"
#include "cevmd5.hpp"
#include "cevsha1.hpp"
#include "cevcryptodll.hpp"

#include "cevrsa_test_keys.cpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvLoginMain
//
// Author: $author$
//   Date: 12/11/2007
///////////////////////////////////////////////////////////////////////
class CEvLoginMain
: virtual public EvcpsMessageReadEvents,
  public CEvcpsMessageReadEventsT<CEvcpClientMain>
{
public:
    typedef CEvcpsMessageReadEventsT<CEvcpClientMain> CExtends;
    typedef CEvLoginMain CDerives;

    typedef EvError 
    (CDerives::*MOnReadServerKeyExchange)
    (CEvcpsRSAServerKeyExchange& serverKeyExchange);

    const char m_lf;

    EvRSAPublicKey* signerRSAPublic;
    EvRSAPublicKey* serverRSAPublic;
    EvRSAPublicKey* rsaPublic;
    EvRSAPrivateKey* rsaPrivate;
    EvDES3* m_readDes3;
    EvAES* m_readAes;
    EvDES3* des3;
    EvAES* aes;
    EvMD5* md5;
    EvSHA1* sha1;

    CEvCipher nullCipher;
    CEvHash nullHash;

    CEvCryptoDll crypto;

    CEvcpsMessage m_evcsMessage;

    CEvcpsLoginResponse m_loginResponse;
    CEvString m_loginResponseString;
    CEvStringWriter m_loginResponseWriter;
    CEvStringReader m_loginResponseReader;

    CEvcpsRSAServerKeyExchange m_signeeKeyExchange;
    CEvString m_signeeKeyExchangeString;
    CEvStringWriter m_signeeKeyExchangeWriter;
    CEvStringReader m_signeeKeyExchangeReader;

    CEvcpsRSAServerKeyExchange m_signerKeyExchange;
    CEvString m_signerKeyExchangeString;
    CEvStringWriter m_signerKeyExchangeWriter;
    CEvStringReader m_signerKeyExchangeReader;

    MOnReadServerKeyExchange m_onReadServerKeyExchange;

    CEvcpsSecurityParameters m_securityParameters;

    UINT64 seqNumber;

    CEvcpCharHexEncoder m_hexOut;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLoginMain
    //
    //       Author: $author$
    //         Date: 12/11/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLoginMain() 
    : m_lf('\n'),

      m_loginResponseWriter(m_loginResponseString),
      m_loginResponseReader(m_loginResponseString),

      m_signeeKeyExchangeWriter(m_signeeKeyExchangeString),
      m_signeeKeyExchangeReader(m_signeeKeyExchangeString),

      m_signerKeyExchangeWriter(m_signerKeyExchangeString),
      m_signerKeyExchangeReader(m_signerKeyExchangeString),

      m_onReadServerKeyExchange(0),

      seqNumber(0),

      m_hexOut(m_stdOut)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvLoginMain
    //
    //      Author: $author$
    //        Date: 12/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvLoginMain()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //    Author: $author$
    //      Date: 12/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, const char** argv, const char** env) 
    {
        int err = 0;
        EvError error;
        LONG length;

        if ((signerRSAPublic = crypto.AcquireRSAPublicKey(error)))
        if ((serverRSAPublic = crypto.AcquireRSAPublicKey(error)))
        if ((rsaPublic = crypto.AcquireRSAPublicKey(error)))
        if ((rsaPrivate = crypto.AcquireRSAPrivateKey(error)))
        if ((m_readDes3 = crypto.AcquireDES3(error)))
        if ((m_readAes = crypto.AcquireAES(error)))
        if ((des3 = crypto.AcquireDES3(error)))
        if ((aes = crypto.AcquireAES(error)))
        if ((md5 = crypto.AcquireMD5(error)))
        if ((sha1 = crypto.AcquireSHA1(error)))
        if (!(error = signerRSAPublic->Create(0,0)))
        if (!(error = serverRSAPublic->Create(0,0)))
        if (!(error = rsaPublic->CreateMSB
            (rsaPublicM, sizeof(rsaPublicM),
             rsaPublicE, sizeof(rsaPublicE))))
        if (!(error = rsaPrivate->CreateMSB
            (rsaPrivateP, rsaPrivateQ, 
             rsaPrivateDmp1, rsaPrivateDmq1,
             rsaPrivateIqmp, sizeof(rsaPrivateP))))
        if (!(error = Connect(m_tcpHost, m_tcpPort)))
        {
            Login(argc, argv, env);
            Disconnect();
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Login
    //
    //    Author: $author$
    //      Date: 12/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Login
    (int argc, const char** argv, const char** env) 
    {
        int err = 0;

        EvCipher* readCiphers[EVCPS_BULK_CIPHER_ALGORITHMS]
        = {&nullCipher, m_readDes3, m_readAes};

        EvCipher* ciphers[EVCPS_BULK_CIPHER_ALGORITHMS]
        = {&nullCipher, des3, aes};

        EvHash* hashes[EVCPS_MAC_ALGORITHMS] 
        = {&nullHash, md5, sha1};

        CEvUTCTime utcTime;
        CEvPseudoRandomBYTEReader randomReader;

        CEvcpsLoginRequest loginRequest;
        CEvcpEvcpsLoginRequest evcpLoginRequest(m_reqHeader, loginRequest);

        CEvcpsRSACertificate loginCertificate
        (rsaPublicM, sizeof(rsaPublicM),
         rsaPublicE, sizeof(rsaPublicE));

        CEvcpsCertificateList loginCertificateList
        (&loginCertificate, 0);

        CEvcpsPreMasterSecret preMasterSecret;
        CEvcpsRSAClientKeyExchange rsaClientKeyExchange;

        CEvcpEvcpsCertificateRequest evcpCertificateRequest
        (m_reqHeader, loginCertificateList, rsaClientKeyExchange);

        CEvcpsLoginResponse loginResponse;

        CEvcpsRSAServerKeyExchange signeeKeyExchange
        (rsaPublicM, sizeof(rsaPublicM),
         rsaPublicE, sizeof(rsaPublicE));

        CEvcpsRSAServerKeyExchange signerKeyExchange
        (rsaPublicM, sizeof(rsaPublicM),
         rsaPublicE, sizeof(rsaPublicE));

        CEvcpEvcpsLoginResponse evcpLoginResponse
        (m_respHeader, loginResponse, 
         signeeKeyExchange, signerKeyExchange);

        CEvcpsMasterSecret masterSecret;

        CEvcpsHandshake handshakeLoginRequest
        (loginRequest, EVCPS_HANDSHAKE_TYPE_LOGIN_REQUEST);

        CEvcpsHandshake handshakeLoginResponse
        (m_loginResponse, EVCPS_HANDSHAKE_TYPE_LOGIN_RESPONSE);

        CEvcpsHandshake handshakeSigneeKeyExchange
        (m_signeeKeyExchange, EVCPS_HANDSHAKE_TYPE_SERVER_KEY_EXCHANGE);

        CEvcpsHandshake handshakeSignerKeyExchange
        (m_signerKeyExchange, EVCPS_HANDSHAKE_TYPE_SERVER_KEY_EXCHANGE);

        CEvcpsHandshake handshakeLoginCertificateList
        (loginCertificateList, EVCPS_HANDSHAKE_TYPE_CERTIFICATE);

        CEvcpsHandshake handshakeRsaClientKeyExchange
        (rsaClientKeyExchange, EVCPS_HANDSHAKE_TYPE_CLIENT_KEY_EXCHANGE);

        CEvcpsList handshakeMessages
        (&handshakeLoginRequest, 
         &handshakeLoginResponse,
         &handshakeSigneeKeyExchange,
         &handshakeSignerKeyExchange,
         &handshakeLoginCertificateList,
         &handshakeRsaClientKeyExchange, 0);

        CEvcpsClientFinished clientFinished;
        CEvcpsHandshake handshakeClientFinished
        (clientFinished, EVCPS_HANDSHAKE_TYPE_LOGIN_FINISHED);

        CEvString clientFinishedString;
        CEvStringWriter clientFinishedWriter(clientFinishedString);
        const char* clientFinishedChars;
        LONG clientFinishedLength;

        CEvBYTEString clientMACSecret;
        CEvBYTEString serverMACSecret;

        CEvBYTEString clientKey;
        CEvBYTEString serverKey;

        CEvBYTEString clientIV;
        CEvBYTEString serverIV;

        const BYTE* clientMACSecretBytes;
        const BYTE* clientKeyBytes;
        const BYTE* clientIVBytes;
        LONG clientMACSecretLength;
        LONG clientKeyLength;
        LONG clientIVLength;

        CEvcpsKeyBlock keyBlock;

        CEvcpsGenericBlockCipher genericBlockCipher;

        CEvcpEvcpsFinishedRequest evcpFinishedRequest
        (m_reqHeader, loginCertificateList, 
         rsaClientKeyExchange, genericBlockCipher);

        CEvcpEvcpsFinishedResponse evcpFinishedResponse
        (m_reqHeader, genericBlockCipher);

        CEvcpsPlaintext cipherText
        (genericBlockCipher, EVCPS_CONTENT_TYPE_HANDSHAKE);

        CEvcpEvcpsRequest cipherTextRequest
        (m_reqHeader, cipherText);

        EvCipher* readCipher;
        EvCipher* cipher;
        ULONG blockSize;

        EvHash* hash;
        ULONG hashSize;

        EvError error;
        LONG length;

        randomReader.Initialize();

        if (0 < (length = loginCertificate.Sign
            (*rsaPrivate, *md5, *sha1, randomReader)))

        if (0 < (length = loginRequest.
            GenerateRandom(utcTime, randomReader)))
        if (!(error = evcpLoginRequest.SetFields
            (EVCP_REQUEST_ACTION_NAME_EVCPS,
             EVCP_REQUEST_ACTION_NAME_START,
             EVCP_HEADER_FIELD_VALUE_CONNECTION_KEEPALIVE,
             EVCP_HEADER_FIELD_NAME_ENCODING_HEX)))
        if (0 < (length = evcpLoginRequest.Write(m_stdOut)))
        if (0 < (length = m_stdOut.Write(&m_lf, sizeof(m_lf))))
        if (0 < (length = evcpLoginRequest.Write(*m_writer)))
        if (!(error = evcpLoginRequest.RemoveFields()))
        if (!(error = ReadOKResponse()))

        if ((m_onReadServerKeyExchange = &CDerives::OnReadSigneeServerKeyExchange))
        if (0 < (length = evcpLoginResponse.Read
            (*m_reader, m_respHeader, 
             m_evcsMessage, (EvcpsMessageReadEvents&)(*this))))

        if (0 < (length = preMasterSecret.
            GenerateRandom(randomReader)))

        if (0 < (length = rsaClientKeyExchange.Encrypt
            (preMasterSecret, *serverRSAPublic, randomReader)))

        if (0 < (length = masterSecret.Generate
            (*md5, *sha1,
             preMasterSecret, 
             loginRequest.m_random, 
             m_loginResponse.m_random)))

        if (0 < (length = m_stdOut.Write(&m_lf, 1)))
        if (0 < (length = m_stdOut.Write("master secret: ")))
        if (0 < (length = masterSecret.Write(m_hexOut)))
        if (0 < (length = m_stdOut.Write(&m_lf, 1)))

        if (0 < (length = clientFinished.Generate
            (*md5, *sha1,
             masterSecret, 
             handshakeMessages)))

        if (0 <= (length = clientFinishedString.Clear()))
        if (0 < (length = handshakeClientFinished.
            Write(clientFinishedWriter)))
        if ((clientFinishedChars = clientFinishedString.
            HasChars(clientFinishedLength)))

        if (!(error = m_securityParameters.SetSecret
            (masterSecret, 
             loginRequest.m_random, 
             m_loginResponse.m_random)))

        if ((readCipher = m_securityParameters.
            SelectCipher(blockSize, readCiphers)))

        if ((cipher = m_securityParameters.
            SelectCipher(blockSize, ciphers)))

        if ((hash = m_securityParameters.
            SelectHash(hashSize, hashes)))

        if (0 < (length = keyBlock.Generate
            (clientMACSecret, serverMACSecret,
             clientKey, serverKey,
             clientIV, serverIV,
             *md5, *sha1, m_securityParameters)))

        if ((clientMACSecretBytes = clientMACSecret.HasChars(clientMACSecretLength)))
        if ((clientKeyBytes = clientKey.HasChars(clientKeyLength)))
        if ((clientIVBytes = clientIV.HasChars(clientIVLength)))

        if (0 < (length = cipher->Initialize
            (clientKeyBytes, clientKeyLength,
             clientIVBytes, clientIVLength)))

        if (0 < (length = m_stdOut.Write(&m_lf, 1)))
        if (0 < (length = m_stdOut.Write("client key: ")))
        if (0 < (length = m_hexOut.Write((char*)clientKeyBytes, clientKeyLength)))
        if (0 < (length = m_stdOut.Write(&m_lf, 1)))

        if (0 < (length = m_stdOut.Write(&m_lf, 1)))
        if (0 < (length = m_stdOut.Write("client iv: ")))
        if (0 < (length = m_hexOut.Write((char*)clientIVBytes, clientIVLength)))
        if (0 < (length = m_stdOut.Write(&m_lf, 1)))

        if (0 < (length = m_stdOut.Write(&m_lf, 1)))
        if (0 < (length = m_stdOut.Write("client finished: ")))
        if (0 < (length = m_hexOut.Write(clientFinishedChars, clientFinishedLength)))
        if (0 < (length = m_stdOut.Write(&m_lf, 1)))

        if (0 < (length = genericBlockCipher.Encrypt
            (seqNumber, 
             evcpFinishedRequest.m_finishedCiphertext, 
             (const BYTE*)(clientFinishedChars), clientFinishedLength, 
             *cipher, blockSize, *hash, clientMACSecretBytes, hashSize)))

        if (!(error = evcpFinishedRequest.SetFields
            (EVCP_REQUEST_ACTION_NAME_EVCPS,
             EVCP_REQUEST_ACTION_NAME_FINISH,
             EVCP_HEADER_FIELD_VALUE_CONNECTION_KEEPALIVE,
             EVCP_HEADER_FIELD_NAME_ENCODING_HEX)))
        if (0 < (length = evcpFinishedRequest.Write(m_stdOut)))
        if (0 < (length = m_stdOut.Write(&m_lf, sizeof(m_lf))))
        if (0 < (length = evcpFinishedRequest.Write(*m_writer)))
        if (!(error = evcpFinishedRequest.RemoveFields()))
        if (!(error = ReadOKResponse()))

        if (0 < (length = evcpFinishedResponse.Read
            (*m_reader, m_respHeader, 
             m_evcsMessage, (EvcpsMessageReadEvents&)(*this))))
        {
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadLoginResponse
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadLoginResponse
    (CEvcpsLoginResponse& loginResponse) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        LONG count;

        if (!(error2 = m_securityParameters.
            SetCipherSuite(loginResponse.m_cipherSuite)))

        if (0 <= (count = m_loginResponseString.Clear()))
        if (0 < (count = loginResponse.Write
            (m_loginResponseWriter)))

        if (0 <= (count = m_loginResponseReader.Reset()))
        if (0 < (count = m_loginResponse.Read
            (m_loginResponseReader)))
            error = EV_ERROR_NONE;

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadServerKeyExchange
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadServerKeyExchange
    (CEvcpsRSAServerKeyExchange& serverKeyExchange) 
    {
        EvError error = EV_ERROR_FAILED;
        if (m_onReadServerKeyExchange)
            error = (this->*m_onReadServerKeyExchange)
            (serverKeyExchange);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadSigneeServerKeyExchange
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    EvError OnReadSigneeServerKeyExchange
    (CEvcpsRSAServerKeyExchange& serverKeyExchange) 
    {
        EvError error = EV_ERROR_FAILED;
        LONG count, modBytes, expBytes;
        const BYTE* modulus;
        const BYTE* exponent;
        EvError error2;

        m_onReadServerKeyExchange = 0;

        if (0 <= (count = m_signeeKeyExchangeString.Clear()))
        if (0 < (count = serverKeyExchange.Write
            (m_signeeKeyExchangeWriter)))

        if (0 <= (count = m_signeeKeyExchangeReader.Reset()))
        if (0 < (count = m_signeeKeyExchange.Read
            (m_signeeKeyExchangeReader)))

        if ((modulus = m_signeeKeyExchange.
            m_rsaParams.ModulusHasChars(modBytes)))
        if ((exponent = m_signeeKeyExchange.
            m_rsaParams.ExponentHasChars(expBytes)))

        if (!(error2 = serverRSAPublic->SetMSB
            (modulus, modBytes, exponent, expBytes)))
        {
            m_onReadServerKeyExchange 
            = &CDerives::OnReadSignerServerKeyExchange;
            error = EV_ERROR_NONE;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadSignerServerKeyExchange
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    EvError OnReadSignerServerKeyExchange
    (CEvcpsRSAServerKeyExchange& serverKeyExchange) 
    {
        EvError error = EV_ERROR_FAILED;
        LONG count, modBytes, expBytes;
        const BYTE* modulus;
        const BYTE* exponent;
        EvError error2;

        m_onReadServerKeyExchange = 0;

        if (0 <= (count = m_signerKeyExchangeString.Clear()))
        if (0 < (count = serverKeyExchange.Write
            (m_signerKeyExchangeWriter)))

        if (0 <= (count = m_signerKeyExchangeReader.Reset()))
        if (0 < (count = m_signerKeyExchange.Read
            (m_signerKeyExchangeReader)))

        if ((modulus = serverKeyExchange.
            m_rsaParams.ModulusHasChars(modBytes)))
        if ((exponent = serverKeyExchange.
            m_rsaParams.ExponentHasChars(expBytes)))

        if (!(error2 = signerRSAPublic->SetMSB
            (modulus, modBytes, exponent, expBytes)))

        if (0 < (count = m_signeeKeyExchange.Verify
            (*signerRSAPublic, *md5, *sha1)))
            error = EV_ERROR_NONE;

        return error;
    }
};
#endif // _EVLI_HPP
