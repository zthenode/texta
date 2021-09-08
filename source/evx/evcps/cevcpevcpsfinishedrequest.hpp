///////////////////////////////////////////////////////////////////////
//   File: cevcpevcpsfinishedrequest.hpp
//
// Author: $author$
//   Date: 12/6/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPEVCPSFINISHEDREQUEST_HPP
#define _CEVCPEVCPSFINISHEDREQUEST_HPP

#include "cevcpevcpsrequest.hpp"
#include "cevcprequestcontent.hpp"
#include "cevcpshandshakeplaintext.hpp"
#include "cevcpscertificatelist.hpp"
#include "cevcpscertificateverify.hpp"
#include "cevcpsrsaclientkeyexchange.hpp"
#include "cevcpschangecipherspec.hpp"
#include "cevcpsgenericblockcipher.hpp"
#include "cevcpsrsaserverkeyexchange.hpp"
#include "cevcpsloginresponse.hpp"
#include "cevcpsloginrequest.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpEvcpsFinishedRequest
//
// Author: $author$
//   Date: 12/6/2007
///////////////////////////////////////////////////////////////////////
class CEvcpEvcpsFinishedRequest
: public CEvcpRequestContent
{
public:
    typedef CEvcpRequestContent CExtends;
    typedef CEvcpEvcpsFinishedRequest CDerives;

    CEvcpsHandshakePlaintext m_certificatePlaintext;
    CEvcpsHandshakePlaintext m_clientKeyExchangePlaintext;
    CEvcpsCertificateVerify& m_certificateVerify;
    CEvcpsHandshakePlaintext m_certificateVerifyPlaintext;
    CEvcpsChangeCipherSpec m_changeCipherSpec;
    CEvcpsPlaintext m_changeCipherSpecPlaintext;
    CEvcpsPlaintext m_finishedCiphertext;
    CEvcpsList m_plaintextList;
    CEvcpEvcpsRequest m_request;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpEvcpsFinishedRequest
    //
    //       Author: $author$
    //         Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpEvcpsFinishedRequest
    (EvcpHeader& header,
     CEvcpsCertificateList& certificateList,
     CEvcpsRSAClientKeyExchange& clientKeyExchange,
     CEvcpsCertificateVerify& certificateVerify,
     CEvcpsGenericBlockCipher& finishedCipher) 
    : CExtends(header),

      m_certificatePlaintext
      (certificateList, EVCPS_HANDSHAKE_TYPE_CERTIFICATE),

      m_clientKeyExchangePlaintext
      (clientKeyExchange, EVCPS_HANDSHAKE_TYPE_CLIENT_KEY_EXCHANGE),

      m_certificateVerify(certificateVerify),

      m_certificateVerifyPlaintext
      (m_certificateVerify, EVCPS_HANDSHAKE_TYPE_CERTIFICATE_VERIFY),

      m_changeCipherSpecPlaintext
      (m_changeCipherSpec, EVCPS_CONTENT_TYPE_CHANGE_CIPHER_SPEC),

      m_finishedCiphertext
      (finishedCipher, EVCPS_CONTENT_TYPE_HANDSHAKE),

      m_plaintextList
      (&m_certificatePlaintext,
       &m_clientKeyExchangePlaintext,
       &m_certificateVerifyPlaintext,
       &m_changeCipherSpecPlaintext,
       &m_finishedCiphertext, 0),

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
    // Function: SignCertificateVerify
    //
    //   Author: $author$
    //     Date: 12/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SignCertificateVerify
    (EvRSAPrivateKey& signer,
     EvMD5& md5, EvSHA1& sha1,
     EvBYTEReader& random) 
    {
        LONG length = m_certificateVerify.Sign
        (signer, md5, sha1, random);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: VerifyCertificateVerify
    //
    //   Author: $author$
    //     Date: 12/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG VerifyCertificateVerify
    (EvRSAPublicKey& signer,
     EvMD5& md5, EvSHA1& sha1) 
    {
        LONG length = m_certificateVerify.Verify
        (signer, md5, sha1);
        return length;
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
#endif // _CEVCPEVCPSFINISHREQUEST_HPP
