///////////////////////////////////////////////////////////////////////
//   File: cevcpsciphersuites.hpp
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSCIPHERSUITES_HPP
#define _CEVCPSCIPHERSUITES_HPP

#include "cevcpsciphersuite.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsCipherSuites
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsCipherSuites
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsCipherSuites CDerives;

    enum 
    { VALUE_LENGTH_MIN = 1, 
      VALUE_LENGTH_MAX = 62 };

    WORD m_length;
    CEvcpsCipherSuite m_value[VALUE_LENGTH_MAX];

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsCipherSuites
    //
    //       Author: $author$
    //         Date: 11/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsCipherSuites()
    : m_length(VALUE_LENGTH_MIN)
    {
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
        ULONG ulength;
        WORD i;
        if (0 < (count1 = reader.
            ReadUnsignedMSB(ulength, sizeof(m_length))))
        for (m_length=(WORD)ulength, 
             i=0; i<m_length; i++)
        {
            if (0 < (count2 = m_value[i].Read(reader)))
                count1 += count2;
            length = count1;
        }
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
        WORD i;
        if (0 < (count1 = writer.
            WriteUnsignedMSB(m_length, sizeof(m_length))))
        for (i=0; i<m_length; i++)
        {
            if (0 < (count2 = m_value[i].Write(writer)))
                count1 += count2;
            length = count1;
        }
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
        USHORT size = sizeof(m_length);
        if (0 < m_length)
            size += m_length * (m_value[0].Sizeof());
        return size;
    }
};
#endif // _CEVCPSCIPHERSUITES_HPP
