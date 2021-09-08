///////////////////////////////////////////////////////////////////////
//   File: cevcps2handshakeplaintext.hpp
//
// Author: $author$
//   Date: 11/28/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPS2HANDSHAKEPLAINTEXT_HPP
#define _CEVCPS2HANDSHAKEPLAINTEXT_HPP

#include "cevcpshandshake.hpp"
#include "cevcpsplaintext.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcps2HandshakePlaintext
//
// Author: $author$
//   Date: 11/28/2007
///////////////////////////////////////////////////////////////////////
class CEvcps2HandshakePlaintext
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcps2HandshakePlaintext CDerives;

    CEvcpsBase& m_request1;
    CEvcpsBase& m_request2;
    CEvcpsHandshake m_handshake1, m_handshake2;
    CEvcpsPlaintext m_plaintext1, m_plaintext2;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcps2HandshakePlaintext
    //
    //       Author: $author$
    //         Date: 11/28/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcps2HandshakePlaintext
    (CEvcpsBase& request1,
     CEvcpsBase& request2,
     BYTE handshakeType=EVCPS_HANDSHAKE_TYPE_NONE) 
    : m_request1(request1),
      m_request2(request2),
      m_handshake1(m_request1, handshakeType),
      m_handshake2(m_request2, handshakeType),
      m_plaintext1(m_handshake1, EVCPS_CONTENT_TYPE_HANDSHAKE), 
      m_plaintext2(m_handshake2, EVCPS_CONTENT_TYPE_HANDSHAKE) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 11/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1,count2;
        if (0 < (count1 = m_plaintext1.Read(reader)))
        if (0 < (count2 = m_plaintext2.Read(reader)))
            length = count1 + count2;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 11/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1,count2;
        if (0 < (count1 = m_plaintext1.Write(writer)))
        if (0 < (count2 = m_plaintext2.Write(writer)))
            length = count1 + count2;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 11/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = m_plaintext1.Sizeof() 
            + m_plaintext2.Sizeof();
        return size;
    }
};

#endif // _CEVCPS2HANDSHAKEPLAINTEXT_HPP
