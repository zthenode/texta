///////////////////////////////////////////////////////////////////////
//   File: cevcpevcpsclient.hpp
//
// Author: $author$
//   Date: 12/19/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPEVCPSCLIENT_HPP
#define _CEVCPEVCPSCLIENT_HPP

#include "cevcpsmessagereadevents.hpp"
#include "cevcpevcpsconnector.hpp"

#include "cevcpevcpsapplicationdataresponse.hpp"
#include "cevcpevcpsapplicationdatarequest.hpp"
#include "cevcpevcpsfinishedresponse.hpp"
#include "cevcpevcpsfinishedrequest.hpp"
#include "cevcpevcpscertificaterequest.hpp"
#include "cevcpevcpsloginresponse.hpp"
#include "cevcpevcpsloginrequest.hpp"

#include "cevcpsclientcontext.hpp"

#include "cevcpresponse.hpp"
#include "cevcprequest.hpp"

#include "cevpseudorandombytereader.hpp"

#include "evdebug.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpEvcpsClient
//
// Author: $author$
//   Date: 12/19/2007
///////////////////////////////////////////////////////////////////////
class CEvcpEvcpsClient
: virtual public EvcpsMessageReadEvents,
  public CEvcpsMessageReadEventsT
  <CEvcpEvcpsConnector>
{
public:
    typedef EvcpsMessageReadEvents CImplements;
    typedef CEvcpsMessageReadEventsT
    <CEvcpEvcpsConnector> CExtends;
    typedef CEvcpEvcpsClient CDerives;

    typedef EvError 
    (CDerives::*MOnReadServerKeyExchange)
    (CEvcpsRSAServerKeyExchange& serverKeyExchange);

    const char m_lf;
    EvCharReader& m_reader;
    EvCharWriter& m_writer;
    EvCharWriter& m_stdOut;
    CEvcpCharHexEncoder m_hexOut;

    CEvcpRequest& m_request;
    CEvcpResponse& m_response;

    EvcpHeader& m_reqHeader;
    EvcpHeader& m_respHeader;

    EvcpHeaderHeading& m_reqHeading;
    EvcpHeaderHeading& m_respHeading;

    CEvUTCTime m_utcTime;
    CEvPseudoRandomBYTEReader m_randomReader;

    MOnReadServerKeyExchange m_onReadServerKeyExchange;

    CEvcpsClientContext m_evcpsContext;

    CEvcpsRSACertificate m_loginCertificate;
    CEvcpsRSACertificate m_caCertificate;

    CEvcpEvcpsLoginRequest m_evcpLoginRequest;
    CEvcpEvcpsLoginResponse m_evcpLoginResponse;
    CEvcpEvcpsFinishedRequest m_evcpLoginFinishedRequest;
    CEvcpEvcpsFinishedResponse m_evcpLoginFinishedResponse;
    CEvcpEvcpsApplicationDataRequest m_evcpApplicationDataRequest;
    CEvcpEvcpsApplicationDataResponse m_evcpApplicationDataResponse;

    bool m_isConnected;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpEvcpsClient
    //
    //       Author: $author$
    //         Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpEvcpsClient
    (EvCharReader& reader,
     EvCharWriter& writer,
     EvCharWriter& stdOut,
     CEvcpRequest& request,
     CEvcpResponse& response) 
    : m_lf('\n'),

      m_reader(reader),
      m_writer(writer),
      m_stdOut(stdOut),
      m_hexOut(m_stdOut),

      m_request(request),
      m_response(response),

      m_reqHeader(m_request.GetHeader()),
      m_respHeader(m_response.GetHeader()),

      m_reqHeading(m_reqHeader.GetHeading()),
      m_respHeading(m_respHeader.GetHeading()),

      m_onReadServerKeyExchange(0),

      m_evcpLoginRequest
      (m_reqHeader, m_evcpsContext.m_loginRequest),

      m_evcpLoginResponse
      (m_respHeader, 
       m_evcpsContext.m_loginResponse, 
       m_evcpsContext.m_signeeKeyExchange, 
       m_evcpsContext.m_signerKeyExchange),

      m_evcpLoginFinishedRequest
      (m_reqHeader, 
       m_evcpsContext.m_certificateList, 
       m_evcpsContext.m_clientKeyExchange, 
       m_evcpsContext.m_clientCertificateVerify, 
       m_evcpsContext.m_genericBlockCipher),

      m_evcpLoginFinishedResponse
      (m_respHeader, 
       m_evcpsContext.m_genericBlockCipher),

      m_evcpApplicationDataRequest
      (m_respHeader, 
       m_evcpsContext.m_genericBlockCipher),

      m_evcpApplicationDataResponse
      (m_respHeader, 
       m_evcpsContext.m_genericBlockCipher),

      m_isConnected(false)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpEvcpsClient
    //
    //      Author: $author$
    //        Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpEvcpsClient()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize
    (const BYTE* certRSAPublicM=0, SHORT certRSAPublicMBytes=0,
     const BYTE* certRSAPublicE=0, SHORT certRSAPublicEBytes=0,

     const BYTE* certRSAPrivateP=0, const BYTE* certRSAPrivateQ=0, 
     const BYTE* certRSAPrivateDmp1=0, const BYTE* certRSAPrivateDmq1=0, 
     const BYTE* certRSAPrivateIqmp=0, SHORT certRSAPrivatePBytes=0,
     
     const BYTE* caRSAPrivateP=0, const BYTE* caRSAPrivateQ=0, 
     const BYTE* caRSAPrivateDmp1=0, const BYTE* caRSAPrivateDmq1=0, 
     const BYTE* caRSAPrivateIqmp=0, SHORT caRSAPrivatePBytes=0,
     
     const BYTE* caRSAPublicM=0, SHORT caRSAPublicMBytes=0,
     const BYTE* caRSAPublicE=0, SHORT caRSAPublicEBytes=0) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        LONG length;

        if (!(error2 = m_evcpsContext.Initialize()))
        {
            if (!(error2 = m_evcpsContext.m_signerRSAPublic->Create(0,0)))
            if (!(error2 = m_evcpsContext.m_signerRSAPrivate->Create(0)))

            if (!(error2 = m_evcpsContext.m_rsaPublic->Create(0,0)))
            if (!(error2 = m_evcpsContext.m_rsaPrivate->Create(0)))
            {
                if ((certRSAPublicM && certRSAPublicMBytes)
                     && (certRSAPublicE && certRSAPublicEBytes)

                    && (certRSAPrivateP && certRSAPrivateQ && certRSAPrivateDmp1 
                        && certRSAPrivateDmq1 && certRSAPrivateIqmp && certRSAPrivatePBytes)

                    && (caRSAPrivateP && caRSAPrivateQ && caRSAPrivateDmp1 
                        && caRSAPrivateDmq1 && caRSAPrivateIqmp && caRSAPrivatePBytes))
                {
                    m_randomReader.Initialize();

                    if (!(error2 = m_evcpsContext.
                        m_rsaPrivate->SetMSB
                        (certRSAPrivateP, certRSAPrivateQ, certRSAPrivateDmp1, 
                         certRSAPrivateDmq1, certRSAPrivateIqmp, certRSAPrivatePBytes)))

                    if (!(error2 = m_evcpsContext.
                        m_signerRSAPrivate->SetMSB
                        (caRSAPrivateP, caRSAPrivateQ, caRSAPrivateDmp1, 
                         caRSAPrivateDmq1, caRSAPrivateIqmp, caRSAPrivatePBytes)))

                    if (0 < (length = m_loginCertificate.Assign
                        (certRSAPublicM, certRSAPublicMBytes,
                         certRSAPublicE, certRSAPublicEBytes)))

                    if (0 < (length = m_loginCertificate.Sign
                        (*m_evcpsContext.m_signerRSAPrivate, 
                         *m_evcpsContext.m_md5, 
                         *m_evcpsContext.m_sha1, 
                         m_randomReader)))

                    if ((caRSAPublicM && caRSAPublicMBytes)
                        && (caRSAPublicE && caRSAPublicEBytes))
                    {
                        if (0 < (length = m_caCertificate.Assign
                            (caRSAPublicM, caRSAPublicMBytes,
                             caRSAPublicE, caRSAPublicEBytes)))

                        if (0 < (length = m_caCertificate.Sign
                            (*m_evcpsContext.m_signerRSAPrivate, 
                             *m_evcpsContext.m_md5, 
                             *m_evcpsContext.m_sha1, 
                             m_randomReader)))
                             return EV_ERROR_NONE;
                    }
                    else return EV_ERROR_NONE;
                }
                else return EV_ERROR_NONE;
            }

            m_evcpsContext.Finalize();
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize() 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;

        if ((error2 = m_evcpsContext.Finalize()))
            error = EV_ERROR_FAILED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Connect
    //
    //   Author: $author$
    //     Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Connect() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        const char* chars;
        const char* finishedChars;
        const BYTE* macSecretBytes;
        const BYTE* keyBytes;
        const BYTE* ivBytes;
        const BYTE* bytes;
        LONG finishedLength;
        LONG macSecretLength;
        LONG keyLength;
        LONG ivLength;
        LONG length;

        DBT("() connecting...\n");

        m_randomReader.Initialize();

        m_evcpsContext.m_certificateList.
        Append(&m_loginCertificate);

        if (0 < (length = m_evcpsContext.m_loginRequest.
            GenerateRandom(m_utcTime, m_randomReader)))

        if (!(error2 = m_evcpLoginRequest.SetFields
            (EVCP_REQUEST_ACTION_NAME_EVCPS,
             EVCP_REQUEST_ACTION_NAME_START,
             EVCP_HEADER_FIELD_VALUE_CONNECTION_KEEPALIVE,
             EVCP_HEADER_FIELD_NAME_ENCODING_HEX)))

        if (0 < (length = m_evcpLoginRequest.Write(m_stdOut)))
        if (0 < (length = m_stdOut.Write(&m_lf, sizeof(m_lf))))
        if (0 < (length = m_evcpLoginRequest.Write(m_writer)))
        if (!(error2 = m_evcpLoginRequest.RemoveFields()))
        if (!(error2 = ReadOKResponse()))

        if ((m_onReadServerKeyExchange = &CDerives::OnReadSigneeServerKeyExchange))
        if (0 < (length = m_evcpLoginResponse.Read
            (m_reader, m_respHeader, 
             m_evcpsContext, (EvcpsMessageReadEvents&)(*this))))

        if (0 < (length = m_evcpsContext.m_preMasterSecret.
            GenerateRandom(m_randomReader)))

        if (0 < (length = HexOut
            ("pre master secret: ", 
             m_evcpsContext.m_preMasterSecret)))

        if (0 < (length = m_evcpsContext.m_clientKeyExchange.Encrypt
            (m_evcpsContext.m_preMasterSecret, 
             *m_evcpsContext.m_rsaPublic, m_randomReader)))

        if (0 < (length = HexOut
            ("encrypted pre master secret: ", 
             m_evcpsContext.m_clientKeyExchange)))

        if (0 < (length = m_evcpsContext.m_masterSecret.Generate
            (*m_evcpsContext.m_md5, 
             *m_evcpsContext.m_sha1,
             m_evcpsContext.m_preMasterSecret, 
             m_evcpsContext.m_loginRequest.m_random, 
             m_evcpsContext.m_loginResponse.m_random)))

        if (0 < (length = HexOut
            ("master secret: ",
             m_evcpsContext.m_masterSecret)))

        if (0 < (length = m_evcpLoginFinishedRequest.
            SignCertificateVerify
            (*m_evcpsContext.m_rsaPrivate, 
             *m_evcpsContext.m_md5,
             *m_evcpsContext.m_sha1,
             m_randomReader)))

        if ((chars = m_evcpLoginFinishedRequest.m_certificateVerify.m_signature.
            m_pkcs1Unsigned.HasChars(length)))
        if (0 < (length = HexOut
            ("unsigned certificate verify: ", chars, length)))

        if (0 < (length = HexOut
            ("certificate verify: ",
             m_evcpLoginFinishedRequest.m_certificateVerify)))

        if (0 < (length = m_evcpsContext.m_clientFinished.Generate
            (*m_evcpsContext.m_md5, 
             *m_evcpsContext.m_sha1,
             m_evcpsContext.m_masterSecret, 
             m_evcpsContext.m_handshakeMessages)))

        if (0 <= (length = m_evcpsContext.m_clientFinishedString.Clear()))
        if (0 < (length = m_evcpsContext.m_handshakeClientFinished.
            Write(m_evcpsContext.m_clientFinishedWriter)))
        if ((finishedChars = m_evcpsContext.m_clientFinishedString.
            HasChars(finishedLength)))

        if (0 < (length = HexOut
            ("client finished: ", finishedChars, finishedLength)))

        if (!(error = m_evcpsContext.m_securityParameters.SetSecret
            (m_evcpsContext.m_masterSecret, 
             m_evcpsContext.m_loginRequest.m_random, 
             m_evcpsContext.m_loginResponse.m_random)))

        if ((m_evcpsContext.m_readCipher = m_evcpsContext.m_securityParameters.
            SelectCipher
            (m_evcpsContext.m_blockSize, 
             m_evcpsContext.m_readCiphers)))

        if ((m_evcpsContext.m_writeCipher = m_evcpsContext.m_securityParameters.
            SelectCipher
            (m_evcpsContext.m_blockSize, 
             m_evcpsContext.m_writeCiphers)))

        if ((m_evcpsContext.m_hash = m_evcpsContext.m_securityParameters.
            SelectHash
            (m_evcpsContext.m_hashSize, 
             m_evcpsContext.m_hashes)))

        if (0 < (length = m_evcpsContext.m_keyBlock.Generate
            (m_evcpsContext.m_clientMACSecret, 
             m_evcpsContext.m_serverMACSecret,
             m_evcpsContext.m_clientKey, 
             m_evcpsContext.m_serverKey,
             m_evcpsContext.m_clientIV, 
             m_evcpsContext.m_serverIV,
             *m_evcpsContext.m_md5, 
             *m_evcpsContext.m_sha1, 
             m_evcpsContext.m_securityParameters)))

        if ((m_evcpsContext.m_writeMACSecret = (macSecretBytes 
            = m_evcpsContext.m_clientMACSecret.HasChars(macSecretLength))))
        if ((keyBytes = m_evcpsContext.m_clientKey.HasChars(keyLength)))
        if ((ivBytes = m_evcpsContext.m_clientIV.HasChars(ivLength)))

        if (0 < (length = m_evcpsContext.m_writeCipher->Initialize
            (keyBytes, keyLength,
             ivBytes, ivLength)))

        if (0 < (length = HexOut
            ("client mac secret: ",
             (char*)macSecretBytes, macSecretLength)))

        if (0 < (length = HexOut
            ("client key: ", (char*)keyBytes, keyLength)))

        if (0 < (length = HexOut
            ("client iv: ", (char*)ivBytes, ivLength)))

        if ((m_evcpsContext.m_readMACSecret = (macSecretBytes 
            = m_evcpsContext.m_serverMACSecret.HasChars(macSecretLength))))
        if ((keyBytes = m_evcpsContext.m_serverKey.HasChars(keyLength)))
        if ((ivBytes = m_evcpsContext.m_serverIV.HasChars(ivLength)))

        if (0 < (length = m_evcpsContext.m_readCipher->Initialize
            (keyBytes, keyLength,
             ivBytes, ivLength)))

        if (0 < (length = HexOut
            ("server mac secret: ",
             (char*)macSecretBytes, macSecretLength)))

        if (0 < (length = HexOut
            ("server key: ", (char*)keyBytes, keyLength)))

        if (0 < (length = HexOut
            ("server iv: ", (char*)ivBytes, ivLength)))

        if (0 < (length = m_evcpsContext.m_genericBlockCipher.Encrypt
            (m_evcpsContext.m_writeSeqNumber = 0, 
             m_evcpLoginFinishedRequest.m_finishedCiphertext, 
             (const BYTE*)(finishedChars), finishedLength, 
              *m_evcpsContext.m_writeCipher, 
              m_evcpsContext.m_blockSize, 
              *m_evcpsContext.m_hash, 
              m_evcpsContext.m_writeMACSecret, 
              m_evcpsContext.m_hashSize)))

        if (!(error2 = m_evcpLoginFinishedRequest.SetFields
            (EVCP_REQUEST_ACTION_NAME_EVCPS,
             EVCP_REQUEST_ACTION_NAME_FINISH,
             EVCP_HEADER_FIELD_VALUE_CONNECTION_KEEPALIVE,
             EVCP_HEADER_FIELD_NAME_ENCODING_HEX)))

        if (0 < (length = m_evcpLoginFinishedRequest.Write(m_stdOut)))
        if (0 < (length = m_stdOut.Write(&m_lf, sizeof(m_lf))))
        if (0 < (length = m_evcpLoginFinishedRequest.Write(m_writer)))
        if (!(error2 = m_evcpLoginFinishedRequest.RemoveFields()))
        if (!(error2 = ReadOKResponse()))

        if (0 < (length = m_evcpLoginFinishedResponse.Read
            (m_reader, m_respHeader, 
             m_evcpsContext, (EvcpsMessageReadEvents&)(*this))))

        if (!(error2 = m_evcpApplicationDataRequest.SetFields
            (EVCP_REQUEST_ACTION_NAME_EVCPS,
             EVCP_REQUEST_ACTION_NAME_CONTINUE,
             EVCP_HEADER_FIELD_VALUE_CONNECTION_KEEPALIVE,
             m_isHexEncoded
             ?EVCP_HEADER_FIELD_NAME_ENCODING_HEX
             :EVCP_HEADER_FIELD_NAME_ENCODING_IDENTITY)))
        {
            DBT("() ...connected\n");
            m_isConnected = true;
            return EV_ERROR_NONE;
        }

        DBE("() ...failed to connect\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Disconnect
    //
    //   Author: $author$
    //     Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Disconnect
    (bool onlyIfConnected=false) 
    {
        EvError error = EV_ERROR_NONE;

        if (m_isConnected)
            m_isConnected = false;
        else
        if (onlyIfConnected)
            error = EV_ERROR_FAILED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Fill
    //
    //   Author: $author$
    //     Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Fill() 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count;
        EvError error;

        if (m_isConnected)
        if (!(error = ReadOKResponse()))
        if (0 < (count = m_evcpApplicationDataResponse.Read
            (m_reader, m_respHeader, 
             m_evcpsContext, (EvcpsMessageReadEvents&)(*this))))
        if (0 <= (count = m_evcpsContext.
            m_genericBlockCipher.m_value.Reset()))
        if (0 < (count = m_applicationDataString.Read
            (m_evcpsContext.m_genericBlockCipher.m_valueCharReader)))
             length = count;

        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Flush
    //
    //   Author: $author$
    //     Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Flush() 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;
        const char* chars;

        if (m_isConnected)
        if ((chars = m_applicationDataString.HasChars(count1)))
        if (0 < (count1 = m_evcpApplicationDataRequest.Write
            (m_writer, m_evcpsContext, chars, count1)))
        if (0 <= (count2 = m_applicationDataString.Clear()))
            length = count1;

        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (char* chars, ULONG size) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1;
        const char* chars1;

        if (m_isConnected)
        if ((chars1 = m_applicationDataString.HasChars(count1)))
            length = m_applicationDataReader.Read(chars, size);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (const char* chars, LONG length=-1) 
    {
        LONG count = -EV_ERROR_FAILED;

        if (m_isConnected)
            count = m_applicationDataWriter.Write(chars, length);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadLoginResponse
    //
    //   Author: $author$
    //     Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadLoginResponse
    (CEvcpsLoginResponse& loginResponse) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        LONG count;

        if (!(error2 = m_evcpsContext.m_securityParameters.
            SetCipherSuite(loginResponse.m_cipherSuite)))

        if (0 <= (count = m_evcpsContext.m_serverLoginResponseString.Clear()))
        if (0 < (count = loginResponse.Write
            (m_evcpsContext.m_serverLoginResponseWriter)))

        if (0 <= (count = m_evcpsContext.m_serverLoginResponseReader.Reset()))
        if (0 < (count = m_evcpsContext.m_serverLoginResponse.Read
            (m_evcpsContext.m_serverLoginResponseReader)))
            error = EV_ERROR_NONE;

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadServerKeyExchange
    //
    //   Author: $author$
    //     Date: 12/19/2007
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
    //     Date: 12/19/2007
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

        if (0 <= (count = m_evcpsContext.m_signeeKeyExchangeString.Clear()))
        if (0 < (count = serverKeyExchange.Write
            (m_evcpsContext.m_signeeKeyExchangeWriter)))

        if (0 <= (count = m_evcpsContext.m_signeeKeyExchangeReader.Reset()))
        if (0 < (count = m_evcpsContext.m_signeeKeyExchange.Read
            (m_evcpsContext.m_signeeKeyExchangeReader)))

        if ((modulus = m_evcpsContext.m_signeeKeyExchange.
            m_rsaParams.ModulusHasChars(modBytes)))
        if ((exponent = m_evcpsContext.m_signeeKeyExchange.
            m_rsaParams.ExponentHasChars(expBytes)))

        if (!(error2 = m_evcpsContext.m_rsaPublic->SetMSB
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
    //     Date: 12/19/2007
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

        if (0 <= (count = m_evcpsContext.m_signerKeyExchangeString.Clear()))
        if (0 < (count = serverKeyExchange.Write
            (m_evcpsContext.m_signerKeyExchangeWriter)))

        if (0 <= (count = m_evcpsContext.m_signerKeyExchangeReader.Reset()))
        if (0 < (count = m_evcpsContext.m_signerKeyExchange.Read
            (m_evcpsContext.m_signerKeyExchangeReader)))

        if ((modulus = serverKeyExchange.
            m_rsaParams.ModulusHasChars(modBytes)))
        if ((exponent = serverKeyExchange.
            m_rsaParams.ExponentHasChars(expBytes)))

        if (!(error2 = m_evcpsContext.m_signerRSAPublic->SetMSB
            (modulus, modBytes, exponent, expBytes)))

        if (0 < (count = m_evcpsContext.m_signeeKeyExchange.Verify
            (*m_evcpsContext.m_signerRSAPublic, 
             *m_evcpsContext.m_md5, 
             *m_evcpsContext.m_sha1)))
            error = EV_ERROR_NONE;

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadChangeCipherSpec
    //
    //   Author: $author$
    //     Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadChangeCipherSpec
    (CEvcpsMessage& message) 
    {
        EvError error = EV_ERROR_FAILED;
        int on;
        if (0 <= (on = m_evcpsContext.ChangeToCipherSpec()))
            error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadLoginFinished
    //
    //   Author: $author$
    //     Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadLoginFinished
    (CEvcpsLoginFinished& loginFinished) 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadApplicationData
    //
    //   Author: $author$
    //     Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadApplicationData
    (CEvcpsMessage& message) 
    {
        EvError error = EV_ERROR_FAILED;
        if (m_isConnected)
            error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadOKResponse
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ReadOKResponse() 
    {
        EvError error = EV_ERROR_FAILED;
        const char* chars;
        LONG length;
        int unequal;

        if (0 >= (length = m_respHeader.Read(m_reader)))
            DBE("() failed to read header\n");

        else if (!m_respHeading.GetIsResponse())
                DBE("() read unexpected header type\n");

        else if ((unequal = m_respHeading.
                 CompareUnsignedResponseStatus
                 (EVCP_STATUS_CODE_OK)))
        {
            if ((chars = m_respHeading.
                GetResponseStatus(length)) && (0 <= length))
                DBE("() received status \"%s\"\n", chars);
        }
        else error = EV_ERROR_NONE;

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: HexOut
    //
    //   Author: $author$
    //     Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG HexOut
    (const char* label, CEvcpsBase& what) 
    {
        LONG count = -EV_ERROR_FAILED;
        LONG length;
        if (0 < (length = m_stdOut.Write(&m_lf, 1)))
        if (0 < (length = m_stdOut.Write(label)))
        if (0 < (length = what.Write(m_hexOut)))
        if (0 < (length = m_stdOut.Write(&m_lf, 1)))
            count = length;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: HexOut
    //
    //   Author: $author$
    //     Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG HexOut
    (const char* label, const char* chars, LONG len) 
    {
        LONG count = -EV_ERROR_FAILED;
        LONG length;
        if (0 < (length = m_stdOut.Write(&m_lf, 1)))
        if (0 < (length = m_stdOut.Write(label)))
        if (0 < (length = m_hexOut.Write(chars, len)))
        if (0 < (length = m_stdOut.Write(&m_lf, 1)))
            count = length;
        return count;
    }
};
#endif // _CEVCPEVCPSCLIENT_HPP
