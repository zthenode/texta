///////////////////////////////////////////////////////////////////////
//   File: cevcpsrsaserverkeyexchange.hpp
//
// Author: $author$
//   Date: 11/26/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSRSASERVERKEYEXCHANGE_HPP
#define _CEVCPSRSASERVERKEYEXCHANGE_HPP

#include "cevcpsserverrsaparams.hpp"
#include "cevcpsrsasignature.hpp"
#include "cevcpsbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsRSAServerKeyExchange
//
// Author: $author$
//   Date: 11/26/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsRSAServerKeyExchange
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsRSAServerKeyExchange CDerives;

    CEvcpsServerRSAParams m_rsaParams;
    CEvcpsRSASignature m_rsaSignature;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsRSAServerKeyExchange
    //
    //       Author: $author$
    //         Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsRSAServerKeyExchange
    (const BYTE* rsaModulus=0, SHORT rsaModulusBytes=0,
     const BYTE* rsaExponent=0, SHORT rsaExponentBytes=0) 
    : m_rsaParams
      (rsaModulus, rsaModulusBytes, 
       rsaExponent, rsaExponentBytes)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Sign
    //
    //   Author: $author$
    //     Date: 11/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Sign
    (EvRSAPrivateKey& signer,
     EvMD5& md5, EvSHA1& sha1,
     EvBYTEReader& random) 
    {
        LONG length = m_rsaSignature.Sign
        (m_rsaParams, signer, md5, sha1, random);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Verify
    //
    //   Author: $author$
    //     Date: 11/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Verify
    (EvRSAPublicKey& signer,
     EvMD5& md5, EvSHA1& sha1) 
    {
        LONG length = m_rsaSignature.Verify
        (m_rsaParams, signer, md5, sha1);
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Assign
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Assign
    (const BYTE* rsaModulus, SHORT rsaModulusBytes,
     const BYTE* rsaExponent, SHORT rsaExponentBytes) 
    {
        LONG length = m_rsaParams.Assign
        (rsaModulus, rsaModulusBytes,
         rsaExponent, rsaExponentBytes);
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;
        if (0 < (count1 = m_rsaParams.Read(reader)))
        if (0 < (count2 = m_rsaSignature.Read(reader)))
            length = count1 + count2;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;
        if (0 < (count1 = m_rsaParams.Write(writer)))
        if (0 < (count2 = m_rsaSignature.Write(writer)))
            length = count1 + count2;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = m_rsaParams.Sizeof() 
            + m_rsaSignature.Sizeof();
        return size;
    }
};

#endif // _CEVCPSRSASERVERKEYEXCHANGE_HPP
