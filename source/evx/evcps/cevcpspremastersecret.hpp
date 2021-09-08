///////////////////////////////////////////////////////////////////////
//   File: cevcpspremastersecret.hpp
//
// Author: $author$
//   Date: 11/29/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSPREMASTERSECRET_HPP
#define _CEVCPSPREMASTERSECRET_HPP

#include "cevcpsversion.hpp"
#include "evbytereader.hpp"

#define EVCPS_PRE_MASTER_SECRET_RANDOM_SIZE \
    TLS_PRE_MASTER_SECRET_RANDOM_SIZE

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsPreMasterSecret
//
// Author: $author$
//   Date: 11/29/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsPreMasterSecret
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsPreMasterSecret CDerives;

    CEvcpsVersion m_clientVersion;
    BYTE m_random[EVCPS_PRE_MASTER_SECRET_RANDOM_SIZE];

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsPreMasterSecret
    //
    //       Author: $author$
    //         Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsPreMasterSecret
    (BYTE major=EVCPS_VERSION_MAJOR, 
     BYTE minor=EVCPS_VERSION_MINOR)
    : m_clientVersion(major, minor)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GenerateRandom
    //
    //   Author: $author$
    //     Date: 11/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG GenerateRandom
    (EvBYTEReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count;

        if (sizeof(m_random) == (count = reader.Read
            (m_random, sizeof(m_random))))
            length = sizeof(m_random);

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
        LONG count1, count2;
        if (0 < (count1 = m_clientVersion.Read(reader)))
        if (0 < (count2 = reader.Read
            ((char*)(m_random), sizeof(m_random))))
            length = count1 + count2;
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
        LONG count1, count2;
        if (0 < (count1 = m_clientVersion.Write(writer)))
        if (0 < (count2 = writer.Write
            ((char*)(m_random), sizeof(m_random))))
            length = count1 + count2;
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
        USHORT size = sizeof(m_random)
            + m_clientVersion.Sizeof();
        return size;
    }
};

#endif // _CEVCPSPREMASTERSECRET_HPP
