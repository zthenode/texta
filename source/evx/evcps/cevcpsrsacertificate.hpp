///////////////////////////////////////////////////////////////////////
//   File: cevcpsrsacertificate.hpp
//
// Author: $author$
//   Date: 11/29/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSRSACERTIFICATE_HPP
#define _CEVCPSRSACERTIFICATE_HPP

#include "cevcpsrsacertificateinfo.hpp"
#include "cevcpsrsasignature.hpp"
#include "cevcpsbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsRSACertificate
//
// Author: $author$
//   Date: 11/29/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsRSACertificate
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsRSACertificate CDerives;

    ULONG m_length;
    CEvcpsRSACertificateInfo m_certificate;
    CEvcpsRSASignature m_signature;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsRSACertificate
    //
    //       Author: $author$
    //         Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsRSACertificate
    (const BYTE* rsaModulus=0, SHORT rsaModulusBytes=0,
     const BYTE* rsaExponent=0, SHORT rsaExponentBytes=0) 
    : m_length(0),
      m_certificate
      (rsaModulus, rsaModulusBytes, 
       rsaExponent, rsaExponentBytes)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Assign
    //
    //   Author: $author$
    //     Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Assign
    (const BYTE* rsaModulus, SHORT rsaModulusBytes,
     const BYTE* rsaExponent, SHORT rsaExponentBytes) 
    {
        LONG length = m_certificate.Assign
        (rsaModulus, rsaModulusBytes,
         rsaExponent, rsaExponentBytes);
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Sign
    //
    //   Author: $author$
    //     Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Sign
    (EvRSAPrivateKey& signer,
     EvMD5& md5, EvSHA1& sha1,
     EvBYTEReader& random) 
    {
        LONG length = m_signature.Sign
        (m_certificate, signer, md5, sha1, random);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Verify
    //
    //   Author: $author$
    //     Date: 11/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Verify
    (EvRSAPublicKey& signer,
     EvMD5& md5, EvSHA1& sha1) 
    {
        LONG length = m_signature.Verify
        (m_certificate, signer, md5, sha1);
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2, count3;

        if (0 < (count1 = reader.ReadUnsignedMSB
            (m_length, sizeof(m_length)-1)))
        if (0 < (count2 = m_certificate.Read(reader)))
        if (0 < (count3 = m_signature.Read(reader)))
            length = count1 + count2 + count3;

        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2, count3;

        m_length = m_certificate.Sizeof() + m_signature.Sizeof();

        if (0 < (count1 = writer.WriteUnsignedMSB
            (m_length, sizeof(m_length)-1)))
        if (0 < (count2 = m_certificate.Write(writer)))
        if (0 < (count3 = m_signature.Write(writer)))
            length = count1 + count2 + count3;

        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = (sizeof(m_length)-1)
            + m_certificate.Sizeof()
            + m_signature.Sizeof();
        return size;
    }
};

#endif // _CEVCPSRSACERTIFICATE_HPP
