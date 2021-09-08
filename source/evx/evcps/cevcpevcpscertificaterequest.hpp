///////////////////////////////////////////////////////////////////////
//   File: cevcpevcpscertificaterequest.hpp
//
// Author: $author$
//   Date: 11/29/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPEVCPSCERTIFICATEREQUEST_HPP
#define _CEVCPEVCPSCERTIFICATEREQUEST_HPP

#include "cevcpshandshakeplaintext.hpp"
#include "cevcpevcpsrequest.hpp"
#include "cevcpscertificatelist.hpp"
#include "cevcpsrsaclientkeyexchange.hpp"
#include "cevcpschangecipherspec.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpEvcpsCertificateRequest
//
// Author: $author$
//   Date: 11/29/2007
///////////////////////////////////////////////////////////////////////
class CEvcpEvcpsCertificateRequest
: public CEvBase
{
public:
    typedef CEvBase CExtends;
    typedef CEvcpEvcpsCertificateRequest CDerives;

    CEvcpsHandshakePlaintext m_certificatePlaintext;
    CEvcpsHandshakePlaintext m_clientKeyExchangePlaintext;
    CEvcpsChangeCipherSpec m_changeCipherSpec;
    CEvcpsPlaintext m_changeCipherSpecPlaintext;
    CEvcpsList m_plaintextList;
    CEvcpEvcpsRequest m_request;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpEvcpsCertificateRequest
    //
    //       Author: $author$
    //         Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpEvcpsCertificateRequest
    (EvcpHeader& header,
     CEvcpsCertificateList& certificateList,
     CEvcpsRSAClientKeyExchange& clientKeyExchange) 
    : m_certificatePlaintext
      (certificateList, EVCPS_HANDSHAKE_TYPE_CERTIFICATE),

      m_clientKeyExchangePlaintext
      (clientKeyExchange, EVCPS_HANDSHAKE_TYPE_CLIENT_KEY_EXCHANGE),

      m_changeCipherSpecPlaintext
      (m_changeCipherSpec, EVCPS_CONTENT_TYPE_CHANGE_CIPHER_SPEC),

      m_plaintextList
      (&m_certificatePlaintext,
       &m_clientKeyExchangePlaintext,
       &m_changeCipherSpecPlaintext, 0),

      m_request(header, m_plaintextList)
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
#endif // _CEVCPEVCPSCERTIFICATEREQUEST_HPP
