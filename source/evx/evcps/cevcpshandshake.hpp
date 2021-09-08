///////////////////////////////////////////////////////////////////////
//   File: cevcpshandshake.hpp
//
// Author: $author$
//   Date: 11/24/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSHANDSHAKE_HPP
#define _CEVCPSHANDSHAKE_HPP

#include <vector>
#include "cevcpshandshakebase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsHandshake
//
// Author: $author$
//   Date: 11/24/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsHandshake
: public CEvcpsHandshakeBase
{
public:
    typedef CEvcpsHandshakeBase CExtends;
    typedef CEvcpsHandshake CDerives;

    CEvcpsBase& m_value;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsHandshake
    //
    //       Author: $author$
    //         Date: 11/24/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsHandshake
    (CEvcpsBase& value,
     BYTE type=EVCPS_HANDSHAKE_TYPE_NONE) 
    : CExtends(type),
      m_value(value)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 11/24/2007
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
    //     Date: 11/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1,count2;

        m_length = m_value.Sizeof();

        if (0 > (count1 = CExtends::Write(writer)))
            return length;

        if (0 > (count2 = m_value.Write(writer)))
            return length;

        length = count1+count2;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 11/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = sizeof(m_type)
            + (sizeof(m_length)-1)
            + m_value.Sizeof();
        return size;
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvcpsHandshakes
//
//   Author: $author$
//     Date: 12/14/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::vector<CEvcpsHandshake*>
CEvcpsHandshakes;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvcpsHandshakesIterator
//
//   Author: $author$
//     Date: 12/14/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpsHandshakes::iterator
CEvcpsHandshakesIterator;

///////////////////////////////////////////////////////////////////////
//  Typedef: const_CEvcpsHandshakesIterator
//
//   Author: $author$
//     Date: 12/14/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpsHandshakes::const_iterator
const_CEvcpsHandshakesIterator;

#endif // _CEVCPSHANDSHAKE_HPP
