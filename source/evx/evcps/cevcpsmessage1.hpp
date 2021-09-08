///////////////////////////////////////////////////////////////////////
//   File: cevcpsmessage.hpp
//
// Author: $author$
//   Date: 12/13/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSMESSAGE_HPP
#define _CEVCPSMESSAGE_HPP

#include "cevcpsloginresponse.hpp"
#include "cevcpsloginrequest.hpp"
#include "cevcpsrsaserverkeyexchange.hpp"

#include "cevcpshandshakeplaintext.hpp"
#include "cevcpscertificatelist.hpp"
#include "cevcpsrsaclientkeyexchange.hpp"
#include "cevcpschangecipherspec.hpp"
#include "cevcpsgenericblockcipher.hpp"

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

#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsMessage
//
// Author: $author$
//   Date: 12/13/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsMessage
: public CEvBase
{
public:
    typedef CEvBase CExtends;
    typedef CEvcpsMessage CDerives;

    CEvcpsHandshakeBase m_handshake;

    CEvcpsLoginRequest m_loginRequest;
    CEvcpsLoginResponse m_loginResponse;
    CEvcpsLoginResponseDone m_loginResponseDone;
    CEvcpsLoginFinished m_loginFinished;

    CEvcpsCertificateRequest m_certificateRequest;
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

    CEvcpsHandshakeList m_certificateVerifyList;
    CEvcpsCertificateVerify m_certificateVerify;
    CEvcpsHandshake m_handshakeCertificateVerify;

    CEvcpsList m_handshakeMessages;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsMessage
    //
    //       Author: $author$
    //         Date: 12/13/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsMessage() 
    : m_handshakeLoginRequest
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

      m_certificateVerifyList
      (&m_handshakeLoginRequest, 
       &m_handshakeLoginResponse,
       &m_handshakeSigneeKeyExchange,
       &m_handshakeSignerKeyExchange,
       &m_handshakeCertificateList,
       &m_handshakeClientKeyExchange, 0),

      m_certificateVerify(m_certificateVerifyList),

      m_handshakeCertificateVerify
      (m_certificateVerify, EVCPS_HANDSHAKE_TYPE_CERTIFICATE_VERIFY),

      m_handshakeMessages
      (&m_handshakeLoginRequest, 
       &m_handshakeLoginResponse,
       &m_handshakeSigneeKeyExchange,
       &m_handshakeSignerKeyExchange,
       &m_handshakeCertificateList,
       &m_handshakeClientKeyExchange,
       &m_handshakeCertificateVerify, 0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpsMessage
    //
    //      Author: $author$
    //        Date: 12/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpsMessage()
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
     EvBYTEReader& randomReader,
     EvRSAPrivateKey& rsaPrivate,
     EvMD5& md5, EvSHA1& sha1) 
    {
        LONG length = serverKeyExchange.Sign
        (rsaPrivate, md5, sha1, randomReader);
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
            length = 0;
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
};
#endif // _CEVCPSMESSAGE_HPP
