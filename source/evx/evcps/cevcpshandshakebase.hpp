///////////////////////////////////////////////////////////////////////
//   File: cevcpshandshakebase.hpp
//
// Author: $author$
//   Date: 12/7/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSHANDSHAKEBASE_HPP
#define _CEVCPSHANDSHAKEBASE_HPP

#include "cevcpsbase.hpp"

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 11/28/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    EVCPS_HANDSHAKE_TYPE_NONE = TLS_HANDSHAKE_TYPE_NONE,

    EVCPS_HANDSHAKE_TYPE_LOGIN_REQUEST = TLS_HANDSHAKE_TYPE_CLIENT_HELLO,
    EVCPS_HANDSHAKE_TYPE_LOGIN_RESPONSE = TLS_HANDSHAKE_TYPE_SERVER_HELLO,
    EVCPS_HANDSHAKE_TYPE_LOGIN_RESPONSE_DONE = TLS_HANDSHAKE_TYPE_SERVER_HELLO_DONE,

    EVCPS_HANDSHAKE_TYPE_CERTIFICATE = TLS_HANDSHAKE_TYPE_CERTIFICATE,
    EVCPS_HANDSHAKE_TYPE_CERTIFICATE_REQUEST = TLS_HANDSHAKE_TYPE_CERTIFICATE_REQUEST,
    EVCPS_HANDSHAKE_TYPE_CERTIFICATE_VERIFY = TLS_HANDSHAKE_TYPE_CERTIFICATE_VERIFY,

    EVCPS_HANDSHAKE_TYPE_CLIENT_KEY_EXCHANGE = TLS_HANDSHAKE_TYPE_CLIENT_KEY_EXCHANGE,
    EVCPS_HANDSHAKE_TYPE_SERVER_KEY_EXCHANGE = TLS_HANDSHAKE_TYPE_SERVER_KEY_EXCHANGE,

    EVCPS_HANDSHAKE_TYPE_LOGIN_FINISHED = TLS_HANDSHAKE_TYPE_FINISHED
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsHandshakeBase
//
// Author: $author$
//   Date: 12/7/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsHandshakeBase
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsHandshakeBase CDerives;

    BYTE m_type;
    UINT32 m_length;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsHandshakeBase
    //
    //       Author: $author$
    //         Date: 12/7/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsHandshakeBase
    (BYTE type=EVCPS_HANDSHAKE_TYPE_NONE) 
    : m_type(type),
      m_length(0) 
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
        LONG count1,count2;
        ULONG ulength;

        if (0 > (count1 = reader.Read
            ((char*)(&m_type), sizeof(m_type))))
            return length;

        if (0 > (count2 = reader.ReadUnsignedMSB
            (ulength, sizeof(m_length)-1)))
            return length;

        m_length = ulength;
        length = count1+count2;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 12/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1,count2;

        if (0 > (count1 = writer.Write
            ((char*)(&m_type), sizeof(m_type))))
            return length;

        if (0 > (count2 = writer.WriteUnsignedMSB
            ((m_length), sizeof(m_length)-1)))
            return length;

        length = count1+count2;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 12/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = sizeof(m_type)
            + (sizeof(m_length)-1)
            + m_length;
        return size;
    }
};

#endif // _CEVCPSHANDSHAKEBASE_HPP
