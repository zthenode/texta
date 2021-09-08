///////////////////////////////////////////////////////////////////////
//   File: cevcpsuint64.hpp
//
// Author: $author$
//   Date: 12/5/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSUINT64_HPP
#define _CEVCPSUINT64_HPP

#include "cevcpsbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsUint64
//
// Author: $author$
//   Date: 12/5/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsUint64
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsUint64 CDerives;

    UINT64 m_value;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsUint64
    //
    //       Author: $author$
    //         Date: 12/5/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsUint64(UINT64 value=0) 
    : m_value(value)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/5/2007
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
    //     Date: 12/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        UINT64 value = m_value;
        BYTE valueByte[sizeof(value)];
        BYTE byte;

        for (byte=sizeof(value); byte; value >>= 8)
            valueByte[--byte] = (BYTE)(value & 255);

        length = writer.Write
        ((char*)(valueByte), sizeof(valueByte));

        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 12/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = sizeof(m_value);
        return size;
    }
};

#endif // _CEVCPSUINT64_HPP
