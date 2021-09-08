///////////////////////////////////////////////////////////////////////
//   File: cevcpssessionid.hpp
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSSESSIONID_HPP
#define _CEVCPSSESSIONID_HPP

#include "cevcpsbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsSessionId
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsSessionId
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsSessionId CDerives;

    enum 
    { VALUE_LENGTH_MIN = 0, 
      VALUE_LENGTH_MAX = 32 };

    BYTE m_length;
    BYTE m_value[VALUE_LENGTH_MAX];

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsSessionId
    //
    //       Author: $author$
    //         Date: 11/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsSessionId() 
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
        if (0 <= (count1 = reader.Read((char*)&m_length, sizeof(m_length))))
        if (0 <= (count2 = reader.Read((char*)m_value, m_length)))
            length = count1+count2;
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
        if (0 <= (count1 = writer.Write((char*)&m_length, sizeof(m_length))))
        if (0 <= (count2 = writer.Write((char*)m_value, m_length)))
            length = count1+count2;
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
        USHORT size = sizeof(m_length)+m_length;
        return size;
    }
};
#endif // _CEVCPSSESSIONID_HPP
