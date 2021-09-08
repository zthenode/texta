///////////////////////////////////////////////////////////////////////
//   File: cevcpsmessagereadevents.hpp
//
// Author: $author$
//   Date: 12/14/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSMESSAGEREADEVENTS_HPP
#define _CEVCPSMESSAGEREADEVENTS_HPP

#include "evcpsmessagereadevents.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsMessageReadEventsT
//
// Author: $author$
//   Date: 12/14/2007
///////////////////////////////////////////////////////////////////////
template<class TExtends=CEvBase>

class CEvcpsMessageReadEventsT
: virtual public EvcpsMessageReadEvents,
  public TExtends
{
public:
    typedef EvcpsMessageReadEvents CImplements;
    typedef TExtends CExtends;
    typedef CEvcpsMessageReadEventsT CDerives;

    EvcpsMessageReadEvents* m_deligate;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsMessageReadEventsT
    //
    //       Author: $author$
    //         Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsMessageReadEventsT
    (EvcpsMessageReadEvents* deligate=0) 
    : m_deligate(deligate)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpsMessageReadEventsT
    //
    //      Author: $author$
    //        Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpsMessageReadEventsT()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadChangeCipherSpec
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadChangeCipherSpec
    (CEvcpsMessage& message) 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadAlert
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadAlert
    (CEvcpsMessage& message) 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadApplicationData
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadApplicationData
    (CEvcpsMessage& message) 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadHandshake
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadHandshake
    (CEvcpsMessage& message) 
    {
        EvError error = EV_ERROR_NONE;
        BYTE handshakeType;

        if (m_deligate)
            error = m_deligate->
            OnReadHandshake(message);
        else
        switch((handshakeType = message.m_handshake.m_type))
        {
        case EVCPS_HANDSHAKE_TYPE_LOGIN_REQUEST:
            error = OnReadLoginRequest
            (message.m_loginRequest);
            break;

        case EVCPS_HANDSHAKE_TYPE_LOGIN_RESPONSE:
            error = OnReadLoginResponse
            (message.m_loginResponse);
            break;

        case EVCPS_HANDSHAKE_TYPE_LOGIN_RESPONSE_DONE:
            error = OnReadLoginResponseDone
            (message.m_loginResponseDone);
            break;

        case EVCPS_HANDSHAKE_TYPE_CERTIFICATE:
            error = OnReadCertificateList
            (message.m_certificateList);
            break;

        case EVCPS_HANDSHAKE_TYPE_CLIENT_KEY_EXCHANGE:
            error = OnReadClientKeyExchange
            (message.m_clientKeyExchange);
            break;

        case EVCPS_HANDSHAKE_TYPE_CERTIFICATE_VERIFY:
            error = OnReadCertificateVerify
            (message.m_certificateVerify);
            break;

        case EVCPS_HANDSHAKE_TYPE_SERVER_KEY_EXCHANGE:
            error = OnReadServerKeyExchange
            (message.m_serverKeyExchange);
            break;

        case EVCPS_HANDSHAKE_TYPE_LOGIN_FINISHED:
            error = OnReadLoginFinished
            (message.m_loginFinished);
            break;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadLoginRequest
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadLoginRequest
    (CEvcpsLoginRequest& loginRequest) 
    {
        EvError error = EV_ERROR_NONE;
        if (m_deligate)
            error = m_deligate->
            OnReadLoginRequest(loginRequest);
        return error;
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
        EvError error = EV_ERROR_NONE;
        if (m_deligate)
            error = m_deligate->
            OnReadLoginResponse(loginResponse);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadLoginResponseDone
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadLoginResponseDone
    (CEvcpsLoginResponseDone& loginResponseDone) 
    {
        EvError error = EV_ERROR_NONE;
        if (m_deligate)
            error = m_deligate->
            OnReadLoginResponseDone(loginResponseDone);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadCertificateList
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadCertificateList
    (CEvcpsCertificateList& certificateList) 
    {
        EvError error = EV_ERROR_NONE;
        if (m_deligate)
            error = m_deligate->
            OnReadCertificateList(certificateList);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadCertificate
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadCertificate
    (CEvcpsRSACertificate& rsaCertificate) 
    {
        EvError error = EV_ERROR_NONE;
        if (m_deligate)
            error = m_deligate->
            OnReadCertificate(rsaCertificate);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadCertificateVerify
    //
    //   Author: $author$
    //     Date: 12/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadCertificateVerify
    (CEvcpsCertificateVerify& certificateVerify) 
    {
        EvError error = EV_ERROR_NONE;
        if (m_deligate)
            error = m_deligate->
            OnReadCertificateVerify(certificateVerify);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadClientKeyExchange
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadClientKeyExchange
    (CEvcpsRSAClientKeyExchange& serverKeyExchange) 
    {
        EvError error = EV_ERROR_NONE;
        if (m_deligate)
            error = m_deligate->
            OnReadClientKeyExchange(serverKeyExchange);
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
        EvError error = EV_ERROR_NONE;
        if (m_deligate)
            error = m_deligate->
            OnReadServerKeyExchange(serverKeyExchange);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadLoginFinished
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadLoginFinished
    (CEvcpsLoginFinished& loginFinished) 
    {
        EvError error = EV_ERROR_NONE;
        if (m_deligate)
            error = m_deligate->
            OnReadLoginFinished(loginFinished);
        return error;
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvcpsMessageReadEvents
//
//   Author: $author$
//     Date: 12/14/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpsMessageReadEventsT<CEvBase>
CEvcpsMessageReadEvents;

#endif // _CEVCPSMESSAGEREADEVENTS_HPP
