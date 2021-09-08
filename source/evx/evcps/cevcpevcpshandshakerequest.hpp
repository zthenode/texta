///////////////////////////////////////////////////////////////////////
//   File: cevcpevcpshandshakerequest.hpp
//
// Author: $author$
//   Date: 11/28/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPEVCPSHANDSHAKEREQUEST_HPP
#define _CEVCPEVCPSHANDSHAKEREQUEST_HPP

#include "cevcpevcpsrequest.hpp"
#include "cevcprequestcontent.hpp"
#include "cevcpshandshakeplaintext.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpEvcpsHandshakeRequest
//
// Author: $author$
//   Date: 11/28/2007
///////////////////////////////////////////////////////////////////////
class CEvcpEvcpsHandshakeRequest
: public CEvcpRequestContent
{
public:
    typedef CEvcpRequestContent CExtends;
    typedef CEvcpEvcpsHandshakeRequest CDerives;

    CEvcpsHandshakePlaintext m_plaintext;
    CEvcpEvcpsRequest m_request;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpEvcpsHandshakeRequest
    //
    //       Author: $author$
    //         Date: 11/28/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpEvcpsHandshakeRequest
    (EvcpHeader& header,
     CEvcpsBase& handshake,
     BYTE handshakeType=EVCPS_HANDSHAKE_TYPE_NONE) 
    : CExtends(header),
      m_plaintext(handshake, handshakeType),
      m_request(header, m_plaintext)
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
     const char* connection,
     const char* encoding) 
    {
        EvError error = m_request.SetFields
        (evcAction, evcPath, connection, encoding);
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
        EvError error = m_request.RemoveFields();
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
     EvcpHeader& reqHeader) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count;
        if (0 <= (count = ReadContent(reader, reqHeader)))
            length = count;
        return length;
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
        LONG length = m_request.Read(reader);
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
        LONG length = m_request.Write(writer);
        return length;
    }
};
#endif // _CEVCPEVCPSHANDSHAKEREQUEST_HPP
