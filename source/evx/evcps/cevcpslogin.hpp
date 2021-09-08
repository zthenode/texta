///////////////////////////////////////////////////////////////////////
//   File: cevcpslogin.hpp
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSLOGIN_HPP
#define _CEVCPSLOGIN_HPP

#include "cevcpsversion.hpp"
#include "cevcpsrandom.hpp"
#include "cevcpssessionid.hpp"
#include "cevcpsciphersuites.hpp"
#include "cevcpscompressionmethods.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsLogin
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsLogin
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsLogin CDerives;

    CEvcpsVersion m_version;
    CEvcpsRandom m_random;
    CEvcpsSessionId m_sessionId;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsLogin
    //
    //       Author: $author$
    //         Date: 11/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsLogin() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GenerateRandom
    //
    //   Author: $author$
    //     Date: 11/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG GenerateRandom
    (CEvUTCTime& utcTime,
     EvBYTEReader& reader) 
    {
        LONG length = m_random.Generate(utcTime, reader);
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

        if (0 > (count1 = m_version.Read(reader)))
            return length;

        if (0 > (count2 = m_random.Read(reader)))
            return length;

        count1 += count2;

        if (0 > (count2 = m_sessionId.Read(reader)))
            return length;

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

        if (0 > (count1 = m_version.Write(writer)))
            return length;

        if (0 > (count2 = m_random.Write(writer)))
            return length;

        count1 += count2;

        if (0 > (count2 = m_sessionId.Write(writer)))
            return length;

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
        USHORT size = m_version.Sizeof()+
            m_random.Sizeof()+
            m_sessionId.Sizeof();
        return size;
    }
};
#endif // _CEVCPSLOGIN_HPP
