///////////////////////////////////////////////////////////////////////
//   File: cevcpskeyblock.hpp
//
// Author: $author$
//   Date: 12/4/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSKEYBLOCK_HPP
#define _CEVCPSKEYBLOCK_HPP

#include "cevcpspseudorandom.hpp"
#include "cevbytereadwritebuffer.hpp"
#include "cevcpssecurityparameters.hpp"
#include "cevbytestring.hpp"

#define EVCPS_KEY_BLOCK_LABEL \
    TLS_KEY_BLOCK_LABEL

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsKeyBlock
//
// Author: $author$
//   Date: 12/4/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsKeyBlock
: public CEvcpsPseudoRandom
{
public:
    typedef CEvcpsPseudoRandom CExtends;
    typedef CEvcpsKeyBlock CDerives;

    CEvBYTEReadWriteBuffer m_value;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsKeyBlock
    //
    //       Author: $author$
    //         Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsKeyBlock() 
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Generate
    //
    //   Author: $author$
    //     Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Generate
    (CEvBYTEString& clientMACSecret,
     CEvBYTEString& serverMACSecret,
     CEvBYTEString& clientKey,
     CEvBYTEString& serverKey,
     CEvBYTEString& clientIV,
     CEvBYTEString& serverIV,
     EvMD5& md5, EvSHA1& sha1,
     CEvcpsSecurityParameters& securityParameters,
     const char* label=EVCPS_KEY_BLOCK_LABEL) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;
        BYTE* valueBytes;

        if (0 < (count1 = Generate
            (md5, sha1, securityParameters, label)))

        if ((valueBytes = m_value.GetWriteBuffer(count2)))

        if (0 < (count2 = clientMACSecret.Assign
            (valueBytes, securityParameters.m_hashSize)))
        if (0 < (count2 = serverMACSecret.Assign
            (valueBytes += count2, securityParameters.m_hashSize)))

        if (0 < (count2 = clientKey.Assign
            (valueBytes += count2, securityParameters.m_keySize)))
        if (0 < (count2 = serverKey.Assign
            (valueBytes += count2, securityParameters.m_keySize)))

        if (0 < (count2 = clientIV.Assign
            (valueBytes += count2, securityParameters.m_ivSize)))
        if (0 < (count2 = serverIV.Assign
            (valueBytes += count2, securityParameters.m_ivSize)))
            length = count1;

        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Generate
    //
    //   Author: $author$
    //     Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Generate
    (EvMD5& md5, EvSHA1& sha1,
     CEvcpsSecurityParameters& securityParameters,
     const char* label=EVCPS_KEY_BLOCK_LABEL) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1;
        ULONG valueSize;
        BYTE* valueBytes;
        EvError error;

        if (!(error = m_value.AllocateBuffer
            (2*(valueSize = securityParameters.m_keyMaterialLength))))
        if ((valueBytes = m_value.GetWriteBuffer(count1))
            && (count1 >= 2*valueSize))

        if (0 <= (count1 = m_secret.Clear()))
        if (0 <= (count1 = m_seed.Clear()))

        if (0 < (count1 = m_secretWriter.Write
            ((char*)(securityParameters.m_masterSecret),
             sizeof(securityParameters.m_masterSecret))))

        if (0 < (count1 = m_seedWriter.Write(label)))

        if (0 < (count1 = m_seedWriter.Write
            ((char*)(securityParameters.m_serverRandom),
             sizeof(securityParameters.m_serverRandom))))

        if (0 < (count1 = m_seedWriter.Write
            ((char*)(securityParameters.m_clientRandom),
             sizeof(securityParameters.m_clientRandom))))

        if (0 < (count1 = GeneratePseudoRandom
            (valueBytes, valueBytes, 
             valueBytes+valueSize, valueSize, md5, sha1)))
            length = count1;

        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = 0;
        return size;
    }
};

#endif // _CEVCPSKEYBLOCK_HPP
