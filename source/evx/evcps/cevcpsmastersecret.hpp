///////////////////////////////////////////////////////////////////////
//   File: cevcpsmastersecret.hpp
//
// Author: $author$
//   Date: 11/30/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSMASTERSECRET_HPP
#define _CEVCPSMASTERSECRET_HPP

#include "cevcpspseudorandom.hpp"
#include "cevcpspremastersecret.hpp"
#include "cevcpsrandom.hpp"

#define EVCPS_MASTER_SECRET_LABEL \
    TLS_MASTER_SECRET_LABEL

#define EVCPS_MASTER_SECRET_SIZE \
    TLS_MASTER_SECRET_SIZE

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsMasterSecret
//
// Author: $author$
//   Date: 11/30/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsMasterSecret
: public CEvcpsPseudoRandom
{
public:
    typedef CEvcpsPseudoRandom CExtends;
    typedef CEvcpsMasterSecret CDerives;

    BYTE m_value[EVCPS_MASTER_SECRET_SIZE];

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsMasterSecret
    //
    //       Author: $author$
    //         Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsMasterSecret()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Generate
    //
    //   Author: $author$
    //     Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Generate
    (EvMD5& md5, EvSHA1& sha1,
     CEvcpsPreMasterSecret& secret,
     CEvcpsRandom& clientRandom,
     CEvcpsRandom& serverRandom,
     const char* label=EVCPS_MASTER_SECRET_LABEL) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1;
        BYTE value[EVCPS_MASTER_SECRET_SIZE];

        if (0 <= (count1 = m_secret.Clear()))
        if (0 <= (count1 = m_seed.Clear()))
        if (0 < (count1 = secret.Write(m_secretWriter)))
        if (0 < (count1 = m_seedWriter.Write(label)))
        if (0 < (count1 = clientRandom.Write(m_seedWriter)))
        if (0 < (count1 = serverRandom.Write(m_seedWriter)))
        if (0 < (count1 = GeneratePseudoRandom
            (m_value, m_value, value, sizeof(m_value), md5, sha1)))
            length = count1;

        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = reader.Read
        ((char*)(m_value), sizeof(m_value));
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = writer.Write
        ((char*)(m_value), sizeof(m_value));
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = sizeof(m_value);
        return size;
    }
};

#endif // _CEVCPSMASTERSECRET_HPP
