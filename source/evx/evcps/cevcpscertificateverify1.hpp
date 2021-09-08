///////////////////////////////////////////////////////////////////////
//   File: cevcpscertificateverify.hpp
//
// Author: $author$
//   Date: 12/10/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSCERTIFICATEVERIFY_HPP
#define _CEVCPSCERTIFICATEVERIFY_HPP

#include "cevcpsbase.hpp"
#include "cevcpsrsasignature.hpp"
#include "cevcpshandshakelist.hpp"
#include "cevcpcharhexencoder.hpp"
#include "evdebug.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsCertificateVerify
//
// Author: $author$
//   Date: 12/10/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsCertificateVerify
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsCertificateVerify CDerives;

    CEvcpsHandshakeList& m_handshakeList;
    CEvcpsRSASignature m_signature;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsCertificateVerify
    //
    //       Author: $author$
    //         Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsCertificateVerify
    (CEvcpsHandshakeList& handshakeList)
    : m_handshakeList(handshakeList)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Sign
    //
    //   Author: $author$
    //     Date: 12/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Sign
    (EvRSAPrivateKey& signer,
     EvMD5& md5, EvSHA1& sha1,
     EvBYTEReader& random) 
    {
        LONG length;

        const char* chars;
        CEvString string;
        CEvStringWriter writer(string);
        CEvcpCharHexEncoder encoder(writer);
        
        if (0 < (length = m_handshakeList.Write(encoder)))
        if ((chars = string.HasChars(length)))
        DBT("() handshake list: %s\n", chars);

        if (0 <= (string.Clear()))
        if (0 <= (length = md5.Initialize()))
        if (0 < (length = m_handshakeList.Write(writer)))
        if ((chars = string.HasChars(length)))
        if (0 < (length = md5.Hash((const BYTE*)(chars), length)))
        if (0 <= (length = md5.Finalize
            (&m_signature.m_md5Hash, EvMD5::EV_HASH_SIZE)))
        if (0 <= (string.Clear()))
        if (0 < (length = encoder.Write
            ((char*)(&m_signature.m_md5Hash), 
             EvMD5::EV_HASH_SIZE)))
        if ((chars = string.HasChars(length)))
        DBT("() MD5 hash: %s\n", chars);

        length = m_signature.Sign
        (m_handshakeList, signer, md5, sha1, random);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Verify
    //
    //   Author: $author$
    //     Date: 12/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Verify
    (EvRSAPublicKey& signer,
     EvMD5& md5, EvSHA1& sha1) 
    {
        LONG length;

        const char* chars;
        CEvString string;
        CEvStringWriter writer(string);
        CEvcpCharHexEncoder encoder(writer);
        
        if (0 < (length = m_handshakeList.Write(encoder)))
        if ((chars = string.HasChars(length)))
        DBT("() handshake list: %s\n", chars);

        if (0 <= (string.Clear()))
        if (0 <= (length = md5.Initialize()))
        if (0 < (length = m_handshakeList.Write(writer)))
        if ((chars = string.HasChars(length)))
        if (0 < (length = md5.Hash((const BYTE*)(chars), length)))
        if (0 <= (length = md5.Finalize
            (&m_signature.m_md5Hash, EvMD5::EV_HASH_SIZE)))
        if (0 <= (string.Clear()))
        if (0 < (length = encoder.Write
            ((char*)(&m_signature.m_md5Hash), 
             EvMD5::EV_HASH_SIZE)))
        if ((chars = string.HasChars(length)))
        DBT("() MD5 hash: %s\n", chars);

        length = m_signature.Verify
        (m_handshakeList, signer, md5, sha1);
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = m_signature.Read(reader);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = m_signature.Write(writer);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = m_signature.Sizeof();
        return size;
    }
};

#endif // _CEVCPSCERTIFICATEVERIFY_HPP
