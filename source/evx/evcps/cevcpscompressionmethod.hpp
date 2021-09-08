///////////////////////////////////////////////////////////////////////
//   File: cevcpscompressionmethod.hpp
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSCOMPRESSIONMETHOD_HPP
#define _CEVCPSCOMPRESSIONMETHOD_HPP

#include "cevcpsbase.hpp"

#define EVCPS_COMPRESSION_METHOD_NULL \
    TLS_COMPRESSION_METHOD_NULL

#define DEFAULT_EVCPS_COMPRESSION_METHOD \
    EVCPS_COMPRESSION_METHOD_NULL

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsCompressionMethod
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsCompressionMethod
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsCompressionMethod CDerives;

    BYTE m_value;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsCompressionMethod
    //
    //       Author: $author$
    //         Date: 11/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsCompressionMethod
    (BYTE value=DEFAULT_EVCPS_COMPRESSION_METHOD) 
    : m_value(value)
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
        LONG count;
        if (0 < (count = reader.Read
            ((char*)&m_value, sizeof(m_value))))
            length = count;
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
        LONG count;
        if (0 < (count = writer.Write
            ((char*)&m_value, sizeof(m_value))))
            length = count;
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
        USHORT size = sizeof(m_value);
        return size;
    }
};
#endif // _CEVCPSCOMPRESSIONMETHOD_HPP
