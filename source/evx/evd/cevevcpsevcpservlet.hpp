///////////////////////////////////////////////////////////////////////
//   File: cevevcpsevcpservlet.hpp
//
// Author: $author$
//   Date: 12/6/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVEVCPSEVCPSERVLET_HPP
#define _CEVEVCPSEVCPSERVLET_HPP

#include "cevcpservlet.hpp"
#include "cevcpservlets.hpp"

#include "cevservletresponse.hpp"
#include "cevservletrequest.hpp"

#include "cevcpevcpsapplicationdataresponse.hpp"
#include "cevcpevcpsapplicationdatarequest.hpp"
#include "cevcpevcpsfinishedresponse.hpp"
#include "cevcpevcpsfinishedrequest.hpp"
#include "cevcpevcpsloginresponse.hpp"
#include "cevcpevcpsloginrequest.hpp"
#include "cevcpsservercontext.hpp"
#include "cevcpscontext.hpp"

#include "cevcpcharhexdecoder.hpp"
#include "cevcpcharhexencoder.hpp"

#include "cevcharreadwritebuffer.hpp"
#include "cevpseudorandombytereader.hpp"
#include "cevstringwriter.hpp"
#include "cevstringreader.hpp"
#include "cevcharfile.hpp"

#define DEFAULT_CEVEVCPSEVCPSERVLET_NAME "EVCPS"

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcpsEvcpServlet
//
// Author: $author$
//   Date: 12/6/2007
///////////////////////////////////////////////////////////////////////
class CEvEvcpsEvcpServlet
: public CEvcpServlet
{
public:
    typedef CEvcpServlet CExtends;
    typedef CEvEvcpsEvcpServlet CDerives;

    typedef EvError 
    (CDerives::*MServiceEvcpsRequest)
    (EvcpServletRequest& request,
     EvcpServletResponse& response,
     EvCharWriter& contentWriter,
     EvCharReader& contentReader,
     ULONG contentLength,
     const char* transferEncoding);

    typedef EvError 
    (CDerives::*MProcessEvcpsContent)();

    const char m_lf;
    CEvCharFile m_stdOut;
    CEvcpCharHexEncoder m_hexOut;

    CEvUTCTime m_utcTime;
    CEvPseudoRandomBYTEReader m_pseudoRandomReader;

    CEvCharReadWriteBuffer m_requestContent;

    CEvcpsServerContext m_evcpsContext;

    CEvcpsRecord m_evcpsRecord;
    CEvString m_evcpsContent;
    CEvStringReader m_evcpsContentReader;
    CEvStringWriter m_evcpsContentWriter;

    MServiceEvcpsRequest m_serviceEvcpsRequest;
    MProcessEvcpsContent m_processEvcpsContent;

    const BYTE* m_rsaModulus; 
    SHORT m_rsaModulusBytes;

    const BYTE* m_rsaExponent;
    SHORT m_rsaExponentBytes;

    const BYTE* m_rsaP;
    const BYTE* m_rsaQ; 
    const BYTE* m_rsaDmp1;
    const BYTE* m_rsaDmq1;
    const BYTE* m_rsaIqmp;
    SHORT m_rsaPBytes;

    CEvString m_reqApplicationData;
    CEvStringReader m_reqApplicationDataReader;

    CEvString m_respApplicationData;
    CEvStringWriter m_respApplicationDataWriter;

    CEvcpHeader m_evcpHeader;
    EvcpHeaderHeading& m_evcpHeading;

    CEvcpEvcpsApplicationDataResponse 
    m_evcpEvcpsApplicationDataResponse;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvcpsEvcpServlet
    //
    //       Author: $author$
    //         Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvcpsEvcpServlet
    (const char* name=DEFAULT_CEVEVCPSEVCPSERVLET_NAME,
     LONG length=-1) 
    : CExtends(name, length),

      m_lf('\n'),
      m_stdOut(stdout),
      m_hexOut(m_stdOut),

      m_evcpsContentReader(m_evcpsContent),
      m_evcpsContentWriter(m_evcpsContent),

      m_serviceEvcpsRequest(0),
      m_processEvcpsContent(0),

      m_rsaModulus(0),
      m_rsaModulusBytes(0),
      m_rsaExponent(0),
      m_rsaExponentBytes(0),

      m_rsaP(0),
      m_rsaQ(0),
      m_rsaDmp1(0),
      m_rsaDmq1(0),
      m_rsaIqmp(0),
      m_rsaPBytes(0),

      m_reqApplicationDataReader(m_reqApplicationData),
      m_respApplicationDataWriter(m_respApplicationData),

      m_evcpHeading(m_evcpHeader.GetHeading()),

      m_evcpEvcpsApplicationDataResponse
      (m_evcpHeader, m_evcpsContext.m_genericBlockCipher)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvEvcpsEvcpServlet
    //
    //      Author: $author$
    //        Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvEvcpsEvcpServlet()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionInitialize
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionInitialize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");

        m_serviceEvcpsRequest = &CDerives::ServiceEvcpsLoginRequest;
        m_processEvcpsContent = &CDerives::ProcessEvcpsLoginRequest;

        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ConnectionFinalize
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ConnectionFinalize
    (EvcpServletConnection& connection) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");

        m_serviceEvcpsRequest = 0;
        m_processEvcpsContent = 0;

        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Initialize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        LONG length;

        DBF("() in...\n");

        m_pseudoRandomReader.Initialize();

        if ((error2 = m_evcpsContext.Initialize()))
            DBE("() failed to initialize EVCPS context\n");
        else
        if (0 > (length = GetRSAPublicKey
            (m_rsaModulus, m_rsaModulusBytes,
             m_rsaExponent, m_rsaExponentBytes)))
            DBE("() failed to get RSA public key\n");
        else
        if (0 > (length = GetRSAPrivateKey
            (m_rsaP, m_rsaQ, m_rsaDmp1, 
             m_rsaDmq1, m_rsaIqmp, m_rsaPBytes)))
            DBE("() failed to get RSA private key\n");
        else
        if (0 > (length = m_evcpsContext.CreateRSAPublicKey
            (m_rsaModulus, m_rsaModulusBytes,
             m_rsaExponent, m_rsaExponentBytes)))
            DBE("() failed to create RSA public key\n");
        else
        if (0 > (length = m_evcpsContext.CreateRSAPrivateKey
            (m_rsaP, m_rsaQ, m_rsaDmp1, 
             m_rsaDmq1, m_rsaIqmp, m_rsaPBytes)))
            DBE("() failed to create RSA private key\n");
        else
        if (0 > (length = m_evcpsContext.CreateRSAPublicKey
            (m_evcpsContext.m_signerRSAPublic,
             m_rsaModulus, m_rsaModulusBytes,
             m_rsaExponent, m_rsaExponentBytes)))
            DBE("() failed to create signer RSA public key\n");
        else
        if (0 > (length = m_evcpsContext.CreateRSAPrivateKey
            (m_evcpsContext.m_signerRSAPrivate,
             m_rsaP, m_rsaQ, m_rsaDmp1, 
             m_rsaDmq1, m_rsaIqmp, m_rsaPBytes)))
            DBE("() failed to create signer RSA private key\n");
        else
        if (0 > (length = m_evcpsContext.m_signeeKeyExchange.
            Assign
            (m_rsaModulus, m_rsaModulusBytes,
             m_rsaExponent, m_rsaExponentBytes)))
            DBE("() failed to assign signee key exchange\n");
        else
        if (0 > (length = m_evcpsContext.m_signerKeyExchange.
            Assign
            (m_rsaModulus, m_rsaModulusBytes,
             m_rsaExponent, m_rsaExponentBytes)))
            DBE("() failed to assign signer key exchange\n");
        else
        if (0 > (length = m_evcpsContext.
            SignKeyExchange
            (m_evcpsContext.m_signeeKeyExchange,
             m_pseudoRandomReader)))
            DBE("() failed to sign signee key exchange\n");
        else
        if (0 > (length = m_evcpsContext.
            SignKeyExchange
            (m_evcpsContext.m_signerKeyExchange,
             m_pseudoRandomReader)))
            DBE("() failed to sign signer key exchange\n");
        else
        error = EV_ERROR_NONE;
        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize(EvServletServer& server) 
    {
        EvError error = EV_ERROR_NONE;
        DBF("() in...\n");
        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpHeader& reqHeader = request.GetHeader();
        EvCharReader& reader = request.GetReader();
        EvcpHeader& respHeader = response.GetHeader();
        EvCharWriter& writer = response.GetWriter();
        ULONG contentLength;
        LONG count;
        int unequal;
        EvError error2;
        char* chars;

        DBF("() in...\n");

        if (0 < (contentLength = reqHeader.GetFieldUnsigned
            (count, EVCP_HEADER_FIELD_NAME_CONTENT_LENGTH)))

        if (!(error2 = m_requestContent.AllocateBuffer(contentLength)))
        if (0 <= (count = m_requestContent.Reset()))
        if ((chars = m_requestContent.GetWriteBuffer(count))
            && (count >= contentLength))
        if (0 < (count = reader.Read(chars, contentLength)))

        if ((unequal = reqHeader.CompareField
            (EVCP_HEADER_FIELD_NAME_TRANSFER_ENCODING,
             EVCP_HEADER_FIELD_NAME_ENCODING_HEX)))
            error = Service
            (request, response, writer,
             m_requestContent, contentLength,
             EVCP_HEADER_FIELD_NAME_ENCODING_IDENTITY);
        else
        {
            CEvcpCharHexDecoder hexDecoder(m_requestContent);
            CEvcpCharHexEncoder hexEncoder(writer);

            error = Service
            (request, response, hexEncoder,
             hexDecoder, contentLength,
             EVCP_HEADER_FIELD_NAME_ENCODING_HEX);
        }

        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Service
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Service
    (EvcpServletRequest& request,
     EvcpServletResponse& response,
     EvCharWriter& contentWriter,
     EvCharReader& contentReader,
     ULONG contentLength,
     const char* transferEncoding) 
    {
        EvError error = EV_ERROR_NONE;
        EvcpStatus status = EVCP_STATUS_INTERNAL_SERVER_ERROR;
        EvError error2;

        DBF("() in...\n");

        SetKeepAlive(request, response);

        if (m_serviceEvcpsRequest)
        if (!(error2 = (this->*m_serviceEvcpsRequest)
            (request, response, contentWriter, 
             contentReader, contentLength,
             transferEncoding)))
            status = EVCP_STATUS_OK;

        if (EVCP_STATUS_OK != status)
            error = RespondStatus(response, status);

        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceEvcpsLoginRequest
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceEvcpsLoginRequest
    (EvcpServletRequest& request,
     EvcpServletResponse& response,
     EvCharWriter& contentWriter,
     EvCharReader& contentReader,
     ULONG contentLength,
     const char* transferEncoding) 
    {
        EvError error = EV_ERROR_FAILED;
        EvCharWriter& writer = response.GetWriter();
        EvcpHeader& respHeader = response.GetHeader();
        CEvcpEvcpsLoginResponse evcpEvcpsLoginResponse
        (respHeader, 
         m_evcpsContext.m_loginResponse, 
         m_evcpsContext.m_signeeKeyExchange, 
         m_evcpsContext.m_signerKeyExchange);
        EvError error2;
        LONG length;

        DBF("() in...\n");

        if (!(error2 = ProcessEvcpsContent(contentReader)))
        if (!(error2 = evcpEvcpsLoginResponse.SetFields
            (EVCP_REQUEST_ACTION_NAME_EVCPS,
             EVCP_REQUEST_ACTION_NAME_START,
             EVCP_HEADER_FIELD_NAME_ENCODING_HEX,
             EVCP_STATUS_DESC_OK, EVCP_STATUS_CODE_OK)))
        if (0 < (length = evcpEvcpsLoginResponse.Write(m_stdOut)))
        if (0 < (length = m_stdOut.Write(&m_lf, sizeof(m_lf))))
        if (0 < (length = evcpEvcpsLoginResponse.Write(writer)))
        {
            m_serviceEvcpsRequest = &CDerives::ServiceEvcpsLoginFinishedRequest;
            m_processEvcpsContent = &CDerives::ProcessEvcpsCertificate;
            error = EV_ERROR_NONE;
        }

        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceEvcpsLoginFinishedRequest
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceEvcpsLoginFinishedRequest
    (EvcpServletRequest& request,
     EvcpServletResponse& response,
     EvCharWriter& contentWriter,
     EvCharReader& contentReader,
     ULONG contentLength,
     const char* transferEncoding) 
    {
        EvError error = EV_ERROR_NONE;
        EvCharWriter& writer = response.GetWriter();
        EvcpHeader& respHeader = response.GetHeader();
        CEvcpEvcpsFinishedResponse evcpEvcpsFinishedResponse
        (respHeader, m_evcpsContext.m_genericBlockCipher);
        LONG length;
        const char* chars;

        DBF("() in...\n");

        if (!(error = ProcessEvcpsContent(contentReader)))

        if (0 <= (length = m_evcpsContext.m_serverFinishedString.Clear()))
        if (0 < (length = m_evcpsContext.m_handshakeServerFinished.
            Write(m_evcpsContext.m_serverFinishedWriter)))
        if ((chars = m_evcpsContext.m_serverFinishedString.
            HasChars(length)))

        if (0 < (length = m_stdOut.Write(&m_lf, 1)))
        if (0 < (length = m_stdOut.Write("server finished: ")))
        if (0 < (length = m_hexOut.Write(chars, length)))
        if (0 < (length = m_stdOut.Write(&m_lf, 1)))

        if (0 < (length = m_evcpsContext.m_genericBlockCipher.Encrypt
            (m_evcpsContext.m_writeSeqNumber, 
             evcpEvcpsFinishedResponse.m_finishedCiphertext, 
             (const BYTE*)(chars), length, 
              *m_evcpsContext.m_writeCipher, 
              m_evcpsContext.m_securityParameters.m_blockSize, 
              *m_evcpsContext.m_hash, m_evcpsContext.m_writeMACSecret, 
              m_evcpsContext.m_securityParameters.m_hashSize)))

        if (!(error = evcpEvcpsFinishedResponse.SetFields
            (EVCP_REQUEST_ACTION_NAME_EVCPS,
             EVCP_REQUEST_ACTION_NAME_START,
             EVCP_HEADER_FIELD_NAME_ENCODING_HEX,
             EVCP_STATUS_DESC_OK, EVCP_STATUS_CODE_OK)))
        if (0 < (evcpEvcpsFinishedResponse.Write(m_stdOut)))
        if (0 < (m_stdOut.Write(&m_lf, sizeof(m_lf))))
        if (0 < (evcpEvcpsFinishedResponse.Write(writer)))
        if (!(error = evcpEvcpsFinishedResponse.RemoveFields()))
        {
            m_serviceEvcpsRequest = &CDerives::ServiceEvcpsApplicationDataRequest;
            m_processEvcpsContent = &CDerives::ProcessEvcpsApplicationData;
        }

        DBF("() ...out\n");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ServiceEvcpsApplicationDataRequest
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ServiceEvcpsApplicationDataRequest
    (EvcpServletRequest& request,
     EvcpServletResponse& response,
     EvCharWriter& contentWriter,
     EvCharReader& contentReader,
     ULONG contentLength,
     const char* transferEncoding) 
    {
        EvError error = EV_ERROR_NONE;
        EvServlet* rootServlet;

        DBF("() in...\n");

        if (!(error = ProcessEvcpsContent(contentReader)))
        if ((rootServlet = GetRootServlet()))
        {
            EvServletConnection& 
            connection = request.GetConnection();

            CEvServletRequest rootRequest
            (connection, m_reqApplicationDataReader);

            CEvServletResponse rootResponse
            (connection, m_respApplicationDataWriter);

            EvCharWriter& writer = response.GetWriter();
            EvcpHeader& respHeader = response.GetHeader();
            EvcpHeaderHeading& respHeading = respHeader.GetHeading();
            const char* protocol = respHeading.GetProtocol();
            const char* protocolMajor = respHeading.GetProtocolVersionMajor();
            const char* protocolMinor = respHeading.GetProtocolVersionMinor();

            const char* chars;
            LONG length;

            m_evcpHeading.SetProtocol(protocol);
            m_evcpHeading.SetProtocolVersionMajor(protocolMajor);
            m_evcpHeading.SetProtocolVersionMinor(protocolMinor);

            if (!(error = rootServlet->Service
                (rootRequest, rootResponse)))

            if (!(error = m_evcpEvcpsApplicationDataResponse.SetFields
                (EVCP_REQUEST_ACTION_NAME_EVCPS,
                 EVCP_REQUEST_ACTION_NAME_CONTINUE,
                 transferEncoding,
                 EVCP_STATUS_DESC_OK, EVCP_STATUS_CODE_OK)))

            if ((chars = m_respApplicationData.HasChars(length)))

            if (0 < (length = m_evcpEvcpsApplicationDataResponse.
                Encrypt(m_evcpsContext, chars, length)))

            if (0 < (length = m_evcpEvcpsApplicationDataResponse.
                Write(m_stdOut)))

            if (0 < (length = m_evcpEvcpsApplicationDataResponse.
                Write(writer)))
                error = EV_ERROR_NONE;
        }

        DBF("() ...out\n");
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ProcessEvcpsContent
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ProcessEvcpsContent
    (EvCharReader& contentReader) 
    {
        EvError error = EV_ERROR_NONE;
        LONG count, count2;
        EvError error2;

        do
        {
            if (0 >= (count = m_evcpsContext.Read
                (contentReader, m_evcpsRecord, m_evcpsContent)))
                break;

            if (0 <= (count2 = m_evcpsContentReader.Reset()))

            if (0 <= (count2 = m_evcpsContext.ReadContent
                (m_evcpsContentReader, m_evcpsRecord)))

            if (m_processEvcpsContent)
            if (!(error2 = (this->*m_processEvcpsContent)()))
                continue;

            error = EV_ERROR_FAILED;
            break;
        }
        while (0 < count);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ProcessEvcpsLoginRequest
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ProcessEvcpsLoginRequest() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        LONG length;
        int type;

        m_processEvcpsContent = &CDerives::UnexpectedEvcpsContent;

        if (EVCPS_CONTENT_TYPE_HANDSHAKE !=
            (type = m_evcpsRecord.m_contentType))
            return UnexpectedEvcpsContent();

        if (EVCPS_HANDSHAKE_TYPE_LOGIN_REQUEST !=
            (type = m_evcpsContext.m_handshake.m_type))
            return UnexpectedEvcpsHandshake();

        if (0 <= (length = m_evcpsContext.m_clientLoginRequestString.Clear()))
        if (0 < (length = m_evcpsContext.m_loginRequest.Write
            (m_evcpsContext.m_clientLoginRequestWriter)))
        if (0 <= (length = m_evcpsContext.m_clientLoginRequestReader.Reset()))
        if (0 < (length = m_evcpsContext.m_clientLoginRequest.Read
            (m_evcpsContext.m_clientLoginRequestReader)))

        if (0 < (length = m_evcpsContext.m_loginResponse.
            GenerateRandom(m_utcTime, m_pseudoRandomReader)))

        if (!(error2 = m_evcpsContext.m_securityParameters.
            SetCipherSuite(m_evcpsContext.m_loginResponse.m_cipherSuite)))
            error = EV_ERROR_NONE;

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ProcessEvcpsCertificate
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ProcessEvcpsCertificate() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        LONG length;
        int type;

        m_processEvcpsContent = &CDerives::UnexpectedEvcpsContent;

        if (EVCPS_CONTENT_TYPE_HANDSHAKE !=
            (type = m_evcpsRecord.m_contentType))
            return UnexpectedEvcpsContent();

        if (EVCPS_HANDSHAKE_TYPE_CERTIFICATE !=
            (type = m_evcpsContext.m_handshake.m_type))
            return UnexpectedEvcpsHandshake();

        if (0 <= (length = m_evcpsContext.m_loginCertificateListString.Clear()))
        if (0 < (length = m_evcpsContext.m_certificateList.Write
            (m_evcpsContext.m_loginCertificateListWriter)))
        if (0 <= (length = m_evcpsContext.m_loginCertificateListReader.Reset()))
        if (0 < (length = m_evcpsContext.m_loginCertificateList.Read
            (m_evcpsContext.m_loginCertificateListReader)))

        if (!(error2 = VerifyCertificates
            (m_evcpsContext.m_certificateList)))
        {
            m_processEvcpsContent = &CDerives::ProcessEvcpsClientKeyExchange;
            error = EV_ERROR_NONE;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ProcessEvcpsClientKeyExchange
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ProcessEvcpsClientKeyExchange() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        const BYTE* keyBytes;
        const BYTE* ivBytes;
        const char* chars;
        LONG macSecretLength;
        LONG keyLength;
        LONG ivLength;
        LONG length;
        ULONG blockSize;
        ULONG hashSize;
        int type;

        m_processEvcpsContent = &CDerives::UnexpectedEvcpsContent;

        if (EVCPS_CONTENT_TYPE_HANDSHAKE !=
            (type = m_evcpsRecord.m_contentType))
            return UnexpectedEvcpsContent();

        if (EVCPS_HANDSHAKE_TYPE_CLIENT_KEY_EXCHANGE !=
            (type = m_evcpsContext.m_handshake.m_type))
            return UnexpectedEvcpsHandshake();
        
        if (0 <= (length = m_evcpsContext.m_loginClientKeyExchangeString.Clear()))
        if (0 < (length = m_evcpsContext.m_clientKeyExchange.Write
            (m_evcpsContext.m_loginClientKeyExchangeWriter)))
        if (0 <= (length = m_evcpsContext.m_loginClientKeyExchangeReader.Reset()))
        if (0 < (length = m_evcpsContext.m_loginClientKeyExchange.Read
            (m_evcpsContext.m_loginClientKeyExchangeReader)))

        if (0 < (length = m_evcpsContext.m_clientKeyExchange.
            Decrypt
            (m_evcpsContext.m_preMasterSecret, 
             *m_evcpsContext.m_rsaPrivate)))

        if (0 < (length = m_evcpsContext.m_masterSecret.Generate
            (*m_evcpsContext.m_md5, 
             *m_evcpsContext.m_sha1,
             m_evcpsContext.m_preMasterSecret, 
             m_evcpsContext.m_loginRequest.m_random, 
             m_evcpsContext.m_loginResponse.m_random)))

        if (0 < (length = m_stdOut.Write(&m_lf, 1)))
        if (0 < (length = m_stdOut.Write("master secret: ")))
        if (0 < (length = m_evcpsContext.m_masterSecret.Write(m_hexOut)))
        if (0 < (length = m_stdOut.Write(&m_lf, 1)))

        if (0 < (length = m_evcpsContext.m_serverFinished.Generate
            (*m_evcpsContext.m_md5, 
             *m_evcpsContext.m_sha1,
             m_evcpsContext.m_masterSecret, 
             m_evcpsContext.m_handshakeMessages)))

        if (0 <= (length = m_evcpsContext.m_serverFinishedString.Clear()))
        if (0 < (length = m_evcpsContext.m_serverFinished.
            Write(m_evcpsContext.m_serverFinishedWriter)))
        if ((chars = m_evcpsContext.m_serverFinishedString.
            HasChars(length)))

        if (!(error = m_evcpsContext.m_securityParameters.SetSecret
            (m_evcpsContext.m_masterSecret, 
             m_evcpsContext.m_loginRequest.m_random, 
             m_evcpsContext.m_loginResponse.m_random)))

        if ((m_evcpsContext.m_readCipher = m_evcpsContext.m_securityParameters.
            SelectCipher(blockSize, m_evcpsContext.m_readCiphers)))

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

        if ((m_evcpsContext.m_readMACSecret = m_evcpsContext.m_clientMACSecret.HasChars(macSecretLength)))
        if ((keyBytes = m_evcpsContext.m_clientKey.HasChars(keyLength)))
        if ((ivBytes = m_evcpsContext.m_clientIV.HasChars(ivLength)))

        if (0 < (length = m_evcpsContext.m_readCipher->Initialize
            (keyBytes, keyLength,
             ivBytes, ivLength)))

        if (0 < (length = m_stdOut.Write(&m_lf, 1)))
        if (0 < (length = m_stdOut.Write("client key: ")))
        if (0 < (length = m_hexOut.Write((char*)keyBytes, keyLength)))
        if (0 < (length = m_stdOut.Write(&m_lf, 1)))

        if (0 < (length = m_stdOut.Write(&m_lf, 1)))
        if (0 < (length = m_stdOut.Write("client iv: ")))
        if (0 < (length = m_hexOut.Write((char*)ivBytes, ivLength)))
        if (0 < (length = m_stdOut.Write(&m_lf, 1)))

        if ((m_evcpsContext.m_writeMACSecret = m_evcpsContext.m_serverMACSecret.HasChars(macSecretLength)))
        if ((keyBytes = m_evcpsContext.m_serverKey.HasChars(keyLength)))
        if ((ivBytes = m_evcpsContext.m_serverIV.HasChars(ivLength)))

        if (0 < (length = m_stdOut.Write(&m_lf, 1)))
        if (0 < (length = m_stdOut.Write("server key: ")))
        if (0 < (length = m_hexOut.Write((char*)keyBytes, keyLength)))
        if (0 < (length = m_stdOut.Write(&m_lf, 1)))

        if (0 < (length = m_stdOut.Write(&m_lf, 1)))
        if (0 < (length = m_stdOut.Write("server iv: ")))
        if (0 < (length = m_hexOut.Write((char*)ivBytes, ivLength)))
        if (0 < (length = m_stdOut.Write(&m_lf, 1)))

        if (0 < (length = m_evcpsContext.m_writeCipher->Initialize
            (keyBytes, keyLength,
             ivBytes, ivLength)))
        {
            m_processEvcpsContent = &CDerives::ProcessEvcpsCertificateVerify;
            error = EV_ERROR_NONE;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ProcessEvcpsCertificateVerify
    //
    //   Author: $author$
    //     Date: 12/27/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ProcessEvcpsCertificateVerify() 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        const char* chars;
        LONG length;
        int type;

        m_processEvcpsContent = &CDerives::UnexpectedEvcpsContent;

        if (EVCPS_CONTENT_TYPE_HANDSHAKE !=
            (type = m_evcpsRecord.m_contentType))
            return UnexpectedEvcpsContent();

        if (EVCPS_HANDSHAKE_TYPE_CERTIFICATE_VERIFY !=
            (type = m_evcpsContext.m_handshake.m_type))
            return UnexpectedEvcpsHandshake();

        if (0 < (length = HexOut
            ("certificate verify: ", 
             m_evcpsContext.m_certificateVerify)))

        if (0 <= (length = m_evcpsContext.m_loginCertificateVerifyString.Clear()))
        if (0 < (length = m_evcpsContext.m_certificateVerify.Write
            (m_evcpsContext.m_loginCertificateVerifyWriter)))
        if (0 <= (length = m_evcpsContext.m_loginCertificateVerifyReader.Reset()))
        if (0 < (length = m_evcpsContext.m_loginCertificateVerify.Read
            (m_evcpsContext.m_loginCertificateVerifyReader)))

        if (!(error2 = VerifyCertificateVerify
            (m_evcpsContext.m_loginCertificateVerify)))
        {
            m_processEvcpsContent = &CDerives::ProcessEvcpsChangeCipherSpec;
            error = EV_ERROR_NONE;
        }

        if ((chars = m_evcpsContext.m_loginCertificateVerify.m_signature.
            m_pkcs1Signed.GetReadBuffer(length)))
        HexOut
        ("unsigned certificate verify: ", chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ProcessEvcpsChangeCipherSpec
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ProcessEvcpsChangeCipherSpec() 
    {
        EvError error = EV_ERROR_FAILED;
        int type;
        int on;

        m_processEvcpsContent = &CDerives::UnexpectedEvcpsContent;

        if (EVCPS_CONTENT_TYPE_CHANGE_CIPHER_SPEC !=
            (type = m_evcpsRecord.m_contentType))
            return UnexpectedEvcpsContent();

        if (0 <= (on = m_evcpsContext.ChangeToCipherSpec()))
        {
            m_processEvcpsContent = &CDerives::ProcessEvcpsClientFinished;
            error = EV_ERROR_NONE;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ProcessEvcpsClientFinished
    //
    //   Author: $author$
    //     Date: 12/18/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ProcessEvcpsClientFinished() 
    {
        EvError error = EV_ERROR_FAILED;
        LONG length;
        int type;

        m_processEvcpsContent = &CDerives::UnexpectedEvcpsContent;

        if (0 < (length = m_stdOut.Write(&m_lf, 1)))
        if (0 < (length = m_stdOut.Write("client finished: ")))
        if (0 < (length = m_evcpsContext.m_genericBlockCipher.Write(m_hexOut)))
        if (0 < (length = m_stdOut.Write(&m_lf, 1)))

        if (EVCPS_CONTENT_TYPE_HANDSHAKE !=
            (type = m_evcpsRecord.m_contentType))
            return UnexpectedEvcpsContent();

        if (EVCPS_HANDSHAKE_TYPE_LOGIN_FINISHED !=
            (type = m_evcpsContext.m_handshake.m_type))
            return UnexpectedEvcpsHandshake();
        
        m_processEvcpsContent = &CDerives::ProcessEvcpsApplicationData;
        error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ProcessEvcpsApplicationData
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    EvError ProcessEvcpsApplicationData() 
    {
        EvError error = EV_ERROR_FAILED;
        LONG count;
        int type;

        m_processEvcpsContent = &CDerives::UnexpectedEvcpsContent;

        if (EVCPS_CONTENT_TYPE_APPLICATION_DATA !=
            (type = m_evcpsRecord.m_contentType))
            return UnexpectedEvcpsContent();

        if (0 < (count = m_reqApplicationData.Read
            (m_evcpsContext.m_genericBlockCipher.m_valueCharReader)))
        if (0 <= (count = m_reqApplicationDataReader.Reset()))

        if (0 <= (count = m_respApplicationData.Clear()))
        if (0 <= (count = m_respApplicationDataWriter.Reset()))
        {
            m_processEvcpsContent = &CDerives::ProcessEvcpsApplicationData;
            error = EV_ERROR_NONE;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: UnexpectedEvcpsContent
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    EvError UnexpectedEvcpsContent() 
    {
        EvError error = EV_ERROR_FAILED;
        int type = m_evcpsRecord.m_contentType;
        DBE("() unexpected content of type %d\n", type);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: UnexpectedEvcpsHandshake
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    EvError UnexpectedEvcpsHandshake() 
    {
        EvError error = EV_ERROR_FAILED;
        int type = m_evcpsContext.m_handshake.m_type;
        DBE("() unexpected handshake of type %d\n", type);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: VerifyCertificates
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    EvError VerifyCertificates
    (CEvcpsCertificateList& certificateList) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        ULONG certificates;

        if (0 < (certificates = certificateList.m_certificates))
        do
        {
            if ((error = VerifyCertificate
                (certificateList.m_certificate[--certificates])))
                break;
        }
        while (0 < certificates);

        if (!error)
            error = SetSignerRSAPublic
            (certificateList.m_certificate[0].m_certificate.m_signer);

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: VerifyCertificate
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    EvError VerifyCertificate
    (CEvcpsRSACertificate& certificate) 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetSignerRSAPublic
    //
    //   Author: $author$
    //     Date: 12/27/2007
    ///////////////////////////////////////////////////////////////////////
    EvError SetSignerRSAPublic
    (CEvcpsServerRSAParams& rsaParams) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        const BYTE* rsaModulus;
        const BYTE* rsaExponent;
        LONG rsaModulusSize;
        LONG rsaExponentSize;

        if ((rsaModulus = rsaParams.ModulusHasChars(rsaModulusSize)))
        if ((rsaExponent = rsaParams.ExponentHasChars(rsaExponentSize)))

        if (!(error2 = m_evcpsContext.m_signerRSAPublic->SetMSB
            (rsaModulus, rsaModulusSize,
             rsaExponent, rsaExponentSize)))
             error = EV_ERROR_NONE;

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: VerifyCertificateVerify
    //
    //   Author: $author$
    //     Date: 12/27/2007
    ///////////////////////////////////////////////////////////////////////
    EvError VerifyCertificateVerify
    (CEvcpsCertificateVerify& certificateVerify) 
    {
        EvError error = EV_ERROR_FAILED;
        LONG length;

        if (0 < (length = certificateVerify.Verify
            (*m_evcpsContext.m_signerRSAPublic, 
             *m_evcpsContext.m_md5, 
             *m_evcpsContext.m_sha1)))
             error = EV_ERROR_NONE;

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetRSAPublicKey
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG GetRSAPublicKey
    (const BYTE*& rsaModulus, SHORT& rsaModulusBytes,
     const BYTE*& rsaExponent, SHORT& rsaExponentBytes);
    ///////////////////////////////////////////////////////////////////////
    // Function: GetRSAPrivateKey
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG GetRSAPrivateKey
    (const BYTE*& rsaP,const BYTE*& rsaQ, 
     const BYTE*& rsaDmp1, const BYTE*& rsaDmq1,
     const BYTE*& rsaIqmp, SHORT& rsaPBytes);

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

#endif // _CEVEVCPSEVCPSERVLET_HPP
