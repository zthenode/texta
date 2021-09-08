///////////////////////////////////////////////////////////////////////
//   File: cevcpevcpsfinishedresponse.hpp
//
// Author: $author$
//   Date: 12/15/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPEVCPSFINISHEDRESPONSE_HPP
#define _CEVCPEVCPSFINISHEDRESPONSE_HPP

#include "cevcpevcpsresponsecontent.hpp"
#include "cevcpevcpsresponse.hpp"
#include "cevcpsplaintextlist.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpEvcpsFinishedResponse
//
// Author: $author$
//   Date: 12/15/2007
///////////////////////////////////////////////////////////////////////
class CEvcpEvcpsFinishedResponse
: public CEvcpEvcpsResponseContent
  <CEvcpsPlaintextList>
{
public:
    typedef CEvcpEvcpsResponseContent
    <CEvcpsPlaintextList> CExtends;
    typedef CEvcpEvcpsFinishedResponse CDerives;

    CEvcpsChangeCipherSpec m_changeCipherSpec;
    CEvcpsPlaintext m_changeCipherSpecPlaintext;
    CEvcpsPlaintext m_finishedCiphertext;
    CEvcpsPlaintextList m_plaintextList;
    CEvcpEvcpsResponse m_response;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpEvcpsFinishedResponse
    //
    //       Author: $author$
    //         Date: 12/15/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpEvcpsFinishedResponse
    (EvcpHeader& header,
     CEvcpsGenericBlockCipher& finishedCipher) 
    : CExtends(header),

      m_changeCipherSpecPlaintext
      (m_changeCipherSpec, EVCPS_CONTENT_TYPE_CHANGE_CIPHER_SPEC),

      m_finishedCiphertext
      (finishedCipher, EVCPS_CONTENT_TYPE_HANDSHAKE),

      m_plaintextList
      (&m_changeCipherSpecPlaintext,
       &m_finishedCiphertext, 0),

      m_response(header, m_plaintextList) 
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFields
    //
    //   Author: $author$
    //     Date: 11/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFields
    (const char* evcAction, 
     const char* evcPath, 
     const char* encoding,
     const char* statusDescription, 
     UINT statusCode) 
    {
        EvError error = m_response.SetFields
        (evcAction, evcPath, encoding, 
         statusDescription, statusCode);
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
    //     Date: 12/13/2007
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
    // Function: OnReadChangeCipherSpecPlaintext
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadChangeCipherSpecPlaintext
    (CEvcpsMessage& message,
     CEvcpsPlaintext& plaintext,
     EvcpsMessageReadEvents& events) 
    {
        EvError error = events.OnReadChangeCipherSpec(message);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnReadHandshakePlaintext
    //
    //   Author: $author$
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnReadHandshakePlaintext
    (CEvcpsMessage& message,
     CEvcpsPlaintext& plaintext,
     EvcpsMessageReadEvents& events) 
    {
        EvError error = EV_ERROR_FAILED;
        BYTE handshakeType;

        if (EVCPS_HANDSHAKE_TYPE_LOGIN_FINISHED 
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
#endif // _CEVCPEVCPSFINISHEDRESPONSE_HPP
