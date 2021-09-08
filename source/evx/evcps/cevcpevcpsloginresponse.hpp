///////////////////////////////////////////////////////////////////////
//   File: cevcploginresponse.hpp
//
// Author: $author$
//   Date: 11/22/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPEVCPSLOGINRESPONSE_HPP
#define _CEVCPEVCPSLOGINRESPONSE_HPP

#include "cevcpevcpsresponsecontent.hpp"
#include "cevcpevcpsresponse.hpp"
#include "cevcpshandshakeplaintextlist.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpEvcpsLoginResponse
//
// Author: $author$
//   Date: 11/22/2007
///////////////////////////////////////////////////////////////////////
class CEvcpEvcpsLoginResponse
: public CEvcpEvcpsResponseContent
  <CEvcpsHandshakePlaintextList>
{
public:
    typedef CEvcpEvcpsResponseContent
    <CEvcpsHandshakePlaintextList> CExtends;
    typedef CEvcpEvcpsLoginResponse CDerives;

    CEvcpsHandshakePlaintext m_loginPlaintext;
    CEvcpsHandshakePlaintext m_signeePlaintext;
    CEvcpsHandshakePlaintext m_signerPlaintext;
    CEvcpsHandshakePlaintextList m_plaintextList;
    CEvcpEvcpsResponse m_response;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpEvcpsLoginResponse
    //
    //       Author: $author$
    //         Date: 11/22/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpEvcpsLoginResponse
    (EvcpHeader& header,
     CEvcpsLoginResponse& loginResponse,
     CEvcpsRSAServerKeyExchange& signeeKeyExchange,
     CEvcpsRSAServerKeyExchange& signerKeyExchange)
    : CExtends(header),
    
      m_loginPlaintext
      (loginResponse, EVCPS_HANDSHAKE_TYPE_LOGIN_RESPONSE),

      m_signeePlaintext
      (signeeKeyExchange, EVCPS_HANDSHAKE_TYPE_SERVER_KEY_EXCHANGE),

      m_signerPlaintext
      (signerKeyExchange, EVCPS_HANDSHAKE_TYPE_SERVER_KEY_EXCHANGE),

      m_plaintextList
      (&m_loginPlaintext, 
       &m_signeePlaintext, 
       &m_signerPlaintext, 0),

      m_response(header, m_plaintextList)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFields
    //
    //   Author: $author$
    //     Date: 11/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFields
    (const char* evcAction, 
     const char* evcPath, 
     const char* encoding,
     const char* statusDescription, 
     UINT statusCode) 
    {
        EvError error = m_response.SetFields
        (evcAction, evcPath, encoding, statusDescription, statusCode);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: RemoveFields
    //
    //   Author: $author$
    //     Date: 9/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError RemoveFields() 
    {
        EvError error = m_response.RemoveFields();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader,
     EvcpHeader& respHeader,
     CEvcpsMessage& message,
     EvcpsMessageReadEvents& events) 
    {
        LONG length = CExtends::Read
        (reader, respHeader, message, events, 
         m_contentDecoder, m_plaintextList);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadHandshakePlaintext
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadHandshakePlaintext
    (CEvcpsMessage& message,
     CEvcpsHandshakePlaintext& plaintext,
     EvcpsMessageReadEvents& events) 
    {
        EvError error = EV_ERROR_FAILED;
        BYTE handshakeType;

        if (plaintext.m_handshake.m_type 
            == (handshakeType = message.m_handshake.m_type))
            error = events.OnReadHandshake(message);

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 11/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = m_response.Read(reader);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 11/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = m_response.Write(writer);
        return length;
    }
};
#endif // _CEVCPEVCPSLOGINRESPONSE_HPP
