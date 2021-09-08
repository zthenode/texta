///////////////////////////////////////////////////////////////////////
//   File: cevcploginresponse.hpp
//
// Author: $author$
//   Date: 11/22/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPEVCPSLOGINRESPONSE_HPP
#define _CEVCPEVCPSLOGINRESPONSE_HPP

#include "cevcpevcpsresponse.hpp"
#include "cevcpresponsecontent.hpp"
#include "cevcpsmessagereadevents.hpp"
#include "cevcpsmessage.hpp"
#include "cevcpsloginresponse.hpp"
#include "cevcpsrsaserverkeyexchange.hpp"
#include "cevcpshandshakeplaintext.hpp"
#include "cevcpshandshakeplaintextlist.hpp"
#include "cevcpslist.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpEvcpsLoginResponse
//
// Author: $author$
//   Date: 11/22/2007
///////////////////////////////////////////////////////////////////////
class CEvcpEvcpsLoginResponse
: public CEvcpResponseContent
{
public:
    typedef CEvcpResponseContent CExtends;
    typedef CEvcpEvcpsLoginResponse CDerives;

    CEvcpsHandshakePlaintext m_loginPlaintext;
    CEvcpsHandshakePlaintext m_signeePlaintext;
    CEvcpsHandshakePlaintext m_signerPlaintext;
    CEvcpsHandshakePlaintextList m_plaintextList;
    CEvcpEvcpsResponse m_response;

    CEvcpsRecord m_evcpsRecord;
    CEvString m_evcpsRecordContent;
    CEvStringReader m_evcpsRecordContentReader;

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

      m_response(header, m_plaintextList),

      m_evcpsRecordContentReader(m_evcpsRecordContent)
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
        LONG length = -EV_ERROR_FAILED;
        return length;
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
        LONG length = -EV_ERROR_FAILED;
        LONG count;

        if (0 <= (count = ReadContent(reader, respHeader)))
        if (m_contentDecoder)
        if (0 < (length = count))
        if (0 > (count = ReadPlaintext
            (*m_contentDecoder, message, events)))
            length = -EV_ERROR_FAILED;

        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadPlaintext
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadPlaintext
    (EvCharReader& reader,
     CEvcpsMessage& message,
     EvcpsMessageReadEvents& events) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count = 0;
        LONG count1,count2;
        CEvcpsHandshakePlaintextsIterator i;
        CEvcpsHandshakePlaintext* plaintext;

        for (i = m_plaintextList.m_values.begin();
             i != m_plaintextList.m_values.end(); i++)
        {
            if ((plaintext = *i))
            if (0 < (count1 = message.Read
                (reader, m_evcpsRecord, m_evcpsRecordContent)))
            if (plaintext->m_plaintext.m_contentType 
                == m_evcpsRecord.m_contentType)
            if (0 <= (count2 = m_evcpsRecordContentReader.Reset()))
            if (0 < (count2 = ReadPlaintextContent
                (m_evcpsRecordContentReader, 
                 message, *plaintext, events)))
            {
                count += count1;
                continue;
            }
            return length;
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadPlaintextContent
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadPlaintextContent
    (EvCharReader& reader,
     CEvcpsMessage& message,
     CEvcpsHandshakePlaintext& plaintext,
     EvcpsMessageReadEvents& events) 
    {
        BYTE contentType = plaintext.m_plaintext.m_contentType;
        BYTE handshakeType = plaintext.m_handshake.m_type;
        LONG length = -EV_ERROR_FAILED;
        LONG count;
        EvError error;

        if (0 < (count = message.
            ReadContent(reader, m_evcpsRecord)))
        switch(contentType)
        {
        case EVCPS_CONTENT_TYPE_HANDSHAKE:
            if (handshakeType == message.m_handshake.m_type)
            if (!(error = events.OnReadHandshake(message)))
                length = count;
            break;
        }
        return length;
    }
    /*//////////////////////////////////////////////////////////////////////
    // Function: OnReadHandshake
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadHandshake
    (CEvcpsMessage& message) 
    {
        BYTE handshakeType = message.m_handshake.m_type;
        EvError error = EV_ERROR_FAILED;
        switch(handshakeType)
        {
        case EVCPS_HANDSHAKE_TYPE_LOGIN_RESPONSE:
            error = OnReadLoginResponse
            (message.m_loginResponse);
            break;

        case EVCPS_HANDSHAKE_TYPE_SERVER_KEY_EXCHANGE:
            error = OnReadServerKeyExchange
            (message.m_serverKeyExchange);
            break;
        }
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
        return error;
    }*/
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
