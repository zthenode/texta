///////////////////////////////////////////////////////////////////////
//   File: evcsmain.hpp
//
// Author: $author$
//   Date: 11/9/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCSMAIN_HPP
#define _EVCSMAIN_HPP

#include "evcpversion.h"
#include "cevmain.hpp"
#include "cevcpevcpsfinishedrequest.hpp"
#include "cevcpsgenericblockcipher.hpp"
#include "cevcpskeyblock.hpp"
#include "cevcpssecurityparameters.hpp"
#include "cevcpsclientfinished.hpp"
#include "cevcpsmastersecret.hpp"
#include "cevcpsrsaclientkeyexchange.hpp"
#include "cevcpevcpscertificaterequest.hpp"
#include "cevcpscertificatelist.hpp"
#include "cevcpevcpsloginresponse.hpp"
#include "cevcpevcpsloginrequest.hpp"
#include "cevcpheader.hpp"
#include "cevcpsloginresponse.hpp"
#include "cevcpsloginrequest.hpp"
#include "cevpseudorandombytereader.hpp"
#include "cevcpspkcs1encryptionblock.hpp"
#include "cevcpsserverrsaparams.hpp"
#include "cevcpsrsasignature.hpp"
#include "cevrsaprivatekey.hpp"
#include "cevrsapublickey.hpp"
#include "cevcipher.hpp"
#include "cevmd5.hpp"
#include "cevsha1.hpp"
#include "cevcryptodll.hpp"

#include "cevrsa_test_keys.cpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsMain
//
// Author: $author$
//   Date: 11/9/2007
///////////////////////////////////////////////////////////////////////
class CEvcsMain
: public CEvMain
{
public:
    typedef CEvMain CExtends;
    typedef CEvcsMain CDerives;

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

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsMain
    //
    //       Author: $author$
    //         Date: 11/9/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsMain() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsMain
    //
    //      Author: $author$
    //        Date: 11/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsMain()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //    Author: $author$
    //      Date: 11/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, const char** argv, const char** env) 
    {
        int err = 0;
        EvError error;

        if ((rsaPrivate = crypto.AcquireRSAPrivateKey(error)))
        if ((rsaPublic = crypto.AcquireRSAPublicKey(error)))
        if ((m_readDes3 = crypto.AcquireDES3(error)))
        if ((m_readAes = crypto.AcquireAES(error)))
        if ((des3 = crypto.AcquireDES3(error)))
        if ((aes = crypto.AcquireAES(error)))
        if ((md5 = crypto.AcquireMD5(error)))
        if ((sha1 = crypto.AcquireSHA1(error)))
        if (!(error = rsaPublic->CreateMSB
            (rsaPublicM, sizeof(rsaPublicM),
             rsaPublicE, sizeof(rsaPublicE))))
        if (!(error = rsaPrivate->CreateMSB
            (rsaPrivateP, rsaPrivateQ, 
             rsaPrivateDmp1, rsaPrivateDmq1,
             rsaPrivateIqmp, sizeof(rsaPrivateP))))
        Login(argc, argv, env);

        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Login
    //
    //    Author: $author$
    //      Date: 11/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Login
    (int argc, const char** argv, const char** env) 
    {
        const char lf = '\n';

        EvCipher* ciphers[EVCPS_BULK_CIPHER_ALGORITHMS]
        = {&nullCipher, des3, aes};

        EvHash* hashes[EVCPS_MAC_ALGORITHMS] 
        = {&nullHash, md5, sha1};

        const BYTE message[] = {'H', 'e', 'l', 'l', 'o', 0};
        const BYTE* messageBytes = message;
        LONG messageLength = sizeof(message);

        UINT64 seqNumber = 0;

        int err = 0;
        EvError error;
        LONG length;

        CEvUTCTime utcTime;
        CEvPseudoRandomBYTEReader randomReader;

        CEvcpHeader evcpHeader
        (EVC_PROTOCOL_NAME,
         EVC_PROTOCOL_VERSION_MAJOR,
         EVC_PROTOCOL_VERSION_MINOR);

        CEvcpsLoginRequest loginRequest;
        CEvcpEvcpsLoginRequest evcpLoginRequest(evcpHeader, loginRequest);

        CEvcpsRSACertificate loginCertificate
        (rsaPublicM, sizeof(rsaPublicM),
         rsaPublicE, sizeof(rsaPublicE));

        CEvcpsCertificateList loginCertificateList
        (&loginCertificate, 0);

        CEvcpsPreMasterSecret preMasterSecret;
        CEvcpsRSAClientKeyExchange rsaClientKeyExchange;

        CEvcpEvcpsCertificateRequest evcpCertificateRequest
        (evcpHeader, loginCertificateList, rsaClientKeyExchange);

        CEvcpsLoginResponse loginResponse;

        CEvcpsRSAServerKeyExchange signeeKeyExchange
        (rsaPublicM, sizeof(rsaPublicM),
         rsaPublicE, sizeof(rsaPublicE));

        CEvcpsRSAServerKeyExchange signerKeyExchange
        (rsaPublicM, sizeof(rsaPublicM),
         rsaPublicE, sizeof(rsaPublicE));

        CEvcpEvcpsLoginResponse evcpLoginResponse
        (evcpHeader, loginResponse, 
         signeeKeyExchange, signerKeyExchange);

        CEvcpsMasterSecret masterSecret;

        CEvcpsHandshake handshakeLoginRequest
        (loginRequest, EVCPS_HANDSHAKE_TYPE_LOGIN_REQUEST);

        CEvcpsHandshake handshakeLoginResponse
        (loginResponse, EVCPS_HANDSHAKE_TYPE_LOGIN_RESPONSE);

        CEvcpsHandshake handshakeSigneeKeyExchange
        (signeeKeyExchange, EVCPS_HANDSHAKE_TYPE_SERVER_KEY_EXCHANGE);

        CEvcpsHandshake handshakeSignerKeyExchange
        (signerKeyExchange, EVCPS_HANDSHAKE_TYPE_SERVER_KEY_EXCHANGE);

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
        CEvString clientFinishedString;
        CEvStringWriter clientFinishedWriter(clientFinishedString);

        CEvcpsSecurityParameters securityParameters;

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
        (evcpHeader, loginCertificateList, 
         rsaClientKeyExchange, genericBlockCipher);

        CEvcpsPlaintext cipherText
        (genericBlockCipher, EVCPS_CONTENT_TYPE_HANDSHAKE);

        CEvcpEvcpsRequest cipherTextRequest
        (evcpHeader, cipherText);

        EvCipher* cipher;
        ULONG blockSize;

        EvHash* hash;
        ULONG hashSize;

        randomReader.Initialize();

        if (0 < (length = loginRequest.
            GenerateRandom(utcTime, randomReader)))
        if (!(error = evcpLoginRequest.SetFields
            (EVCP_REQUEST_ACTION_NAME_EVCPS,
             EVCP_REQUEST_ACTION_NAME_START,
             EVCP_HEADER_FIELD_VALUE_CONNECTION_KEEPALIVE,
             EVCP_HEADER_FIELD_NAME_ENCODING_HEX)))
        if (0 < (evcpLoginRequest.Write(m_stdOut)))
        if (0 < (m_stdOut.Write(&lf, sizeof(lf))))
        if (!(error = evcpLoginRequest.RemoveFields()))

        if (0 < (length = signeeKeyExchange.Sign
            (*rsaPrivate, *md5, *sha1, randomReader)))
        if (0 < (length = signerKeyExchange.Sign
            (*rsaPrivate, *md5, *sha1, randomReader)))
        if (0 < (length = loginResponse.m_random.
            Generate(utcTime, randomReader)))
        if (!(error = evcpLoginResponse.SetFields
            (EVCP_REQUEST_ACTION_NAME_EVCPS,
             EVCP_REQUEST_ACTION_NAME_START,
             EVCP_HEADER_FIELD_NAME_ENCODING_HEX,
             EVCP_STATUS_DESC_OK, EVCP_STATUS_CODE_OK)))
        if (0 < (evcpLoginResponse.Write(m_stdOut)))
        if (0 < (m_stdOut.Write(&lf, sizeof(lf))))
        if (!(error = evcpLoginResponse.RemoveFields()))

        if (0 < (length = loginCertificate.Sign
            (*rsaPrivate, *md5, *sha1, randomReader)))
        if (0 < (length = preMasterSecret.GenerateRandom(randomReader)))
        if (0 < (length = rsaClientKeyExchange.Encrypt
            (preMasterSecret, *rsaPublic, randomReader)))

        if (0 < (length = masterSecret.Generate
            (*md5, *sha1,
             preMasterSecret, 
             loginRequest.m_random, 
             loginResponse.m_random)))

        if (0 < (length = clientFinished.Generate
            (*md5, *sha1,
             masterSecret, 
             handshakeMessages)))

        if (0 <= (length = clientFinishedString.Clear()))
        if (0 < (length = clientFinished.Write(clientFinishedWriter)))
        if ((messageBytes = (const BYTE*)clientFinishedString.HasChars(messageLength)))

        if (!(error = securityParameters.Generate
            (loginResponse.m_cipherSuite, masterSecret, 
             loginRequest.m_random, loginResponse.m_random)))

        if ((cipher = securityParameters.
            SelectCipher(blockSize, ciphers)))

        if ((hash = securityParameters.
            SelectHash(hashSize, hashes)))

        if (0 < (length = keyBlock.Generate
            (clientMACSecret, serverMACSecret,
             clientKey, serverKey,
             clientIV, serverIV,
             *md5, *sha1, securityParameters)))

        if ((clientMACSecretBytes = clientMACSecret.HasChars(clientMACSecretLength)))
        if ((clientKeyBytes = clientKey.HasChars(clientKeyLength)))
        if ((clientIVBytes = clientIV.HasChars(clientIVLength)))

        if (0 < (length = cipher->Initialize
            (clientKeyBytes, clientKeyLength,
             clientIVBytes, clientIVLength)))

        if (0 < (length = genericBlockCipher.Encrypt
            (seqNumber, evcpFinishedRequest.m_finishedCiphertext, messageBytes, messageLength, 
             *cipher, blockSize, *hash, clientMACSecretBytes, hashSize)))

        if (!(error = evcpFinishedRequest.SetFields
            (EVCP_REQUEST_ACTION_NAME_EVCPS,
             EVCP_REQUEST_ACTION_NAME_FINISH,
             EVCP_HEADER_FIELD_VALUE_CONNECTION_KEEPALIVE,
             EVCP_HEADER_FIELD_NAME_ENCODING_HEX)))
        if (0 < (evcpFinishedRequest.Write(m_stdOut)))
        if (0 < (m_stdOut.Write(&lf, sizeof(lf))))

        if (0 < (length = cipher->Initialize
            (clientKeyBytes, clientKeyLength,
             clientIVBytes, clientIVLength)))

        if (0 < (length = genericBlockCipher.Decrypt
            (seqNumber, evcpFinishedRequest.m_finishedCiphertext, *cipher, blockSize, 
             *hash, clientMACSecretBytes, hashSize)))

        if (0 < (evcpFinishedRequest.Write(m_stdOut)))
        if (0 < (m_stdOut.Write(&lf, sizeof(lf))))
            evcpFinishedRequest.RemoveFields();

        return err;
    }
};

#endif // _EVCSMAIN_HPP
