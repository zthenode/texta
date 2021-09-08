///////////////////////////////////////////////////////////////////////
//   File: cevcpsclientcontext.hpp
//
// Author: $author$
//   Date: 12/18/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSCLIENTCONTEXT_HPP
#define _CEVCPSCLIENTCONTEXT_HPP

#include "cevcpscontext.hpp"
#include "cevcpsclientfinished.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsClientContext
//
// Author: $author$
//   Date: 12/18/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsClientContext
: public CEvcpsContext
{
public:
    typedef CEvcpsContext CExtends;
    typedef CEvcpsClientContext CDerives;

    CEvcpsLoginResponse m_serverLoginResponse;
    CEvString m_serverLoginResponseString;
    CEvStringWriter m_serverLoginResponseWriter;
    CEvStringReader m_serverLoginResponseReader;

    CEvcpsRSAServerKeyExchange m_signeeKeyExchange;
    CEvString m_signeeKeyExchangeString;
    CEvStringWriter m_signeeKeyExchangeWriter;
    CEvStringReader m_signeeKeyExchangeReader;

    CEvcpsRSAServerKeyExchange m_signerKeyExchange;
    CEvString m_signerKeyExchangeString;
    CEvStringWriter m_signerKeyExchangeWriter;
    CEvStringReader m_signerKeyExchangeReader;

    CEvcpsHandshake m_handshakeLoginRequest;
    CEvcpsHandshake m_handshakeLoginResponse;
    CEvcpsHandshake m_handshakeSigneeKeyExchange;
    CEvcpsHandshake m_handshakeSignerKeyExchange;
    CEvcpsHandshake m_handshakeCertificateList;
    CEvcpsHandshake m_handshakeClientKeyExchange;

    CEvcpsHandshakeList m_clientCertificateVerifyList;
    CEvcpsCertificateVerify m_clientCertificateVerify;
    CEvcpsHandshake m_handshakeCertificateVerify;

    CEvcpsList m_handshakeMessages;

    CEvcpsClientFinished m_clientFinished;
    CEvcpsHandshake m_handshakeClientFinished;
    CEvString m_clientFinishedString;
    CEvStringWriter m_clientFinishedWriter;
    CEvStringReader m_clientFinishedReader;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsClientContext
    //
    //       Author: $author$
    //         Date: 12/18/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsClientContext() 
    : m_serverLoginResponseWriter(m_serverLoginResponseString),
      m_serverLoginResponseReader(m_serverLoginResponseString),

      m_signeeKeyExchangeWriter(m_signeeKeyExchangeString),
      m_signeeKeyExchangeReader(m_signeeKeyExchangeString),

      m_signerKeyExchangeWriter(m_signerKeyExchangeString),
      m_signerKeyExchangeReader(m_signerKeyExchangeString),

      m_handshakeLoginRequest
      (m_loginRequest, EVCPS_HANDSHAKE_TYPE_LOGIN_REQUEST),

      m_handshakeLoginResponse
      (m_serverLoginResponse, EVCPS_HANDSHAKE_TYPE_LOGIN_RESPONSE),

      m_handshakeSigneeKeyExchange
      (m_signeeKeyExchange, 
       EVCPS_HANDSHAKE_TYPE_SERVER_KEY_EXCHANGE),

      m_handshakeSignerKeyExchange
      (m_signerKeyExchange, 
       EVCPS_HANDSHAKE_TYPE_SERVER_KEY_EXCHANGE),

      m_handshakeCertificateList
      (m_certificateList, EVCPS_HANDSHAKE_TYPE_CERTIFICATE),

      m_handshakeClientKeyExchange
      (m_clientKeyExchange, EVCPS_HANDSHAKE_TYPE_CLIENT_KEY_EXCHANGE),

      m_clientCertificateVerifyList
      (&m_handshakeLoginRequest, 
       &m_handshakeLoginResponse,
       &m_handshakeSigneeKeyExchange,
       &m_handshakeSignerKeyExchange,
       &m_handshakeCertificateList,
       &m_handshakeClientKeyExchange, 0),

      m_clientCertificateVerify(m_clientCertificateVerifyList),

      m_handshakeCertificateVerify
      (m_clientCertificateVerify, 
       EVCPS_HANDSHAKE_TYPE_CERTIFICATE_VERIFY),

      m_handshakeMessages
      (&m_handshakeLoginRequest, 
       &m_handshakeLoginResponse,
       &m_handshakeSigneeKeyExchange,
       &m_handshakeSignerKeyExchange,
       &m_handshakeCertificateList,
       &m_handshakeClientKeyExchange, 
       &m_handshakeCertificateVerify, 0),

      m_handshakeClientFinished
      (m_clientFinished, EVCPS_HANDSHAKE_TYPE_LOGIN_FINISHED),
      m_clientFinishedWriter(m_clientFinishedString),
      m_clientFinishedReader(m_clientFinishedString)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpsClientContext
    //
    //      Author: $author$
    //        Date: 12/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpsClientContext()
    {
    }
};
#endif // _CEVCPSCLIENTCONTEXT_HPP
