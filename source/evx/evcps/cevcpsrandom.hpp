///////////////////////////////////////////////////////////////////////
//   File: cevcpsrandom.hpp
//
// Author: $author$
//   Date: 11/8/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSRANDOM_HPP
#define _CEVCPSRANDOM_HPP

#include "cevcpsbase.hpp"
#include "evbytestream.hpp"
#include "evcharstream.hpp"
#include "cevutctime.hpp"

#define EVCPS_UTCTIME_BYTES 4
#define EVCPS_RANDOM_BYTES 28

#define EVCPS_RANDOM_SIZE \
    (EVCPS_UTCTIME_BYTES + EVCPS_RANDOM_BYTES)

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsRandom
//
// Author: $author$
//   Date: 11/8/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsRandom
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsRandom CDerives;

    BYTE m_utcTime[EVCPS_UTCTIME_BYTES];
    BYTE m_randomBytes[EVCPS_RANDOM_BYTES];

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsRandom
    //
    //       Author: $author$
    //         Date: 11/8/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsRandom() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Generate
    //
    //   Author: $author$
    //     Date: 11/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Generate
    (CEvUTCTime& utcTime,
     EvBYTEReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count;
        ULONG lsbTime;
        unsigned bytes;

        for (lsbTime = utcTime.GetCurrent(), 
             bytes = sizeof(m_utcTime);
             bytes > 0; lsbTime >>= 8)
             m_utcTime[--bytes] = (BYTE)(lsbTime);

        if (sizeof(m_randomBytes) == (count = reader.Read
            (m_randomBytes, sizeof(m_randomBytes))))
            length = sizeof(m_utcTime)+sizeof(m_randomBytes);

        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;
        if (0 < (count1 = reader.Read((char*)m_utcTime, sizeof(m_utcTime))))
        if (0 < (count2 = reader.Read((char*)m_randomBytes, sizeof(m_randomBytes))))
            length = count1 + count2;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 11/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write(EvCharWriter& writer)
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;
        if (0 < (count1 = writer.Write((char*)m_utcTime, sizeof(m_utcTime))))
        if (0 < (count2 = writer.Write((char*)m_randomBytes, sizeof(m_randomBytes))))
            length = count1 + count2;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 11/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = sizeof(m_utcTime)
            + sizeof(m_randomBytes);
        return size;
    }
};
#endif // _CEVCPSRANDOM_HPP
