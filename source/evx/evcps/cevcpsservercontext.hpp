///////////////////////////////////////////////////////////////////////
//   File: cevcpsservercontext.hpp
//
// Author: $author$
//   Date: 12/17/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSSERVERCONTEXT_HPP
#define _CEVCPSSERVERCONTEXT_HPP

#include "cevcpscontext.hpp"
#include "cevcpsserverfinished.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsServerContext
//
// Author: $author$
//   Date: 12/17/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsServerContext
: public CEvcpsContext
{
public:
    typedef CEvcpsContext CExtends;
    typedef CEvcpsServerContext CDerives;

    CEvcpsLoginRequest m_clientLoginRequest;
    CEvString m_clientLoginRequestString;
    CEvStringWriter m_clientLoginRequestWriter;
    CEvStringReader m_clientLoginRequestReader;

    CEvcpsCertificateList m_loginCertificateList;
    CEvString m_loginCertificateListString;
    CEvStringWriter m_loginCertificateListWriter;
    CEvStringReader m_loginCertificateListReader;

    CEvcpsRSAClientKeyExchange m_loginClientKeyExchange;
    CEvString m_loginClientKeyExchangeString;
    CEvStringWriter m_loginClientKeyExchangeWriter;
    CEvStringReader m_loginClientKeyExchangeReader;

    CEvcpsRSAServerKeyExchange m_signeeKeyExchange;
    CEvcpsRSAServerKeyExchange m_signerKeyExchange;

    CEvcpsHandshake m_handshakeLoginRequest;
    CEvcpsHandshake m_handshakeLoginResponse;
    CEvcpsHandshake m_handshakeSigneeKeyExchange;
    CEvcpsHandshake m_handshakeSignerKeyExchange;
    CEvcpsHandshake m_handshakeCertificateList;
    CEvcpsHandshake m_handshakeClientKeyExchange;

    CEvcpsHandshakeList m_loginCertificateVerifyList;
    CEvcpsCertificateVerify m_loginCertificateVerify;
    CEvString m_loginCertificateVerifyString;
    CEvStringWriter m_loginCertificateVerifyWriter;
    CEvStringReader m_loginCertificateVerifyReader;

    CEvcpsHandshake m_handshakeCertificateVerify;

    CEvcpsList m_handshakeMessages;

    CEvcpsServerFinished m_serverFinished;
    CEvcpsHandshake m_handshakeServerFinished;
    CEvString m_serverFinishedString;
    CEvStringWriter m_serverFinishedWriter;
    CEvStringReader m_serverFinishedReader;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsServerContext
    //
    //       Author: $author$
    //         Date: 12/17/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsServerContext() 
    : m_clientLoginRequestWriter(m_clientLoginRequestString),
      m_clientLoginRequestReader(m_clientLoginRequestString),

      m_loginCertificateListWriter(m_loginCertificateListString),
      m_loginCertificateListReader(m_loginCertificateListString),

      m_loginClientKeyExchangeWriter(m_loginClientKeyExchangeString),
      m_loginClientKeyExchangeReader(m_loginClientKeyExchangeString),

      m_handshakeLoginRequest
      (m_clientLoginRequest, EVCPS_HANDSHAKE_TYPE_LOGIN_REQUEST),

      m_handshakeLoginResponse
      (m_loginResponse, EVCPS_HANDSHAKE_TYPE_LOGIN_RESPONSE),

      m_handshakeSigneeKeyExchange
      (m_signeeKeyExchange, EVCPS_HANDSHAKE_TYPE_SERVER_KEY_EXCHANGE),

      m_handshakeSignerKeyExchange
      (m_signerKeyExchange, EVCPS_HANDSHAKE_TYPE_SERVER_KEY_EXCHANGE),

      m_handshakeCertificateList
      (m_loginCertificateList, EVCPS_HANDSHAKE_TYPE_CERTIFICATE),

      m_handshakeClientKeyExchange
      (m_loginClientKeyExchange, EVCPS_HANDSHAKE_TYPE_CLIENT_KEY_EXCHANGE),

      m_loginCertificateVerifyList
      (&m_handshakeLoginRequest, 
       &m_handshakeLoginResponse,
       &m_handshakeSigneeKeyExchange,
       &m_handshakeSignerKeyExchange,
       &m_handshakeCertificateList,
       &m_handshakeClientKeyExchange, 0),

      m_loginCertificateVerify(m_loginCertificateVerifyList),
      m_loginCertificateVerifyWriter(m_loginCertificateVerifyString),
      m_loginCertificateVerifyReader(m_loginCertificateVerifyString),

      m_handshakeCertificateVerify
      (m_loginCertificateVerify, EVCPS_HANDSHAKE_TYPE_CERTIFICATE_VERIFY),

      m_handshakeMessages
      (&m_handshakeLoginRequest, 
       &m_handshakeLoginResponse,
       &m_handshakeSigneeKeyExchange,
       &m_handshakeSignerKeyExchange,
       &m_handshakeCertificateList,
       &m_handshakeClientKeyExchange,
       &m_handshakeCertificateVerify, 0),

      m_handshakeServerFinished
      (m_serverFinished, EVCPS_HANDSHAKE_TYPE_LOGIN_FINISHED),
      m_serverFinishedWriter(m_serverFinishedString),
      m_serverFinishedReader(m_serverFinishedString)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpsServerContext
    //
    //      Author: $author$
    //        Date: 12/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpsServerContext()
    {
    }
};
#endif // _CEVCPSSERVERCONTEXT_HPP
