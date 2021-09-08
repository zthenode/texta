///////////////////////////////////////////////////////////////////////
//   File: cevcpshandshakeplaintext.hpp
//
// Author: $author$
//   Date: 11/28/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSHANDSHAKEPLAINTEXT_HPP
#define _CEVCPSHANDSHAKEPLAINTEXT_HPP

#include <vector>
#include "cevcpshandshake.hpp"
#include "cevcpsplaintext.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsHandshakePlaintext
//
// Author: $author$
//   Date: 11/28/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsHandshakePlaintext
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsHandshakePlaintext CDerives;

    CEvcpsBase& m_request;
    CEvcpsHandshake m_handshake;
    CEvcpsPlaintext m_plaintext;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsHandshakePlaintext
    //
    //       Author: $author$
    //         Date: 11/28/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsHandshakePlaintext
    (CEvcpsBase& request,
     BYTE handshakeType=EVCPS_HANDSHAKE_TYPE_NONE) 
    : m_request(request),
      m_handshake(m_request, handshakeType),
      m_plaintext(m_handshake, EVCPS_CONTENT_TYPE_HANDSHAKE)
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
        LONG length = m_plaintext.Read(reader);
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
        LONG length = m_plaintext.Write(writer);
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
        USHORT size = m_plaintext.Sizeof();
        return size;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetContentType
    //
    //   Author: $author$
    //     Date: 12/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual BYTE SetContentType
    (BYTE contentType) 
    {
        return m_plaintext.SetContentType(contentType);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetContentType
    //
    //   Author: $author$
    //     Date: 12/15/2007
    ///////////////////////////////////////////////////////////////////////
    virtual BYTE GetContentType() const 
    {
        return m_plaintext.GetContentType();
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvcpsHandshakePlaintexts
//
//   Author: $author$
//     Date: 12/14/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::vector<CEvcpsHandshakePlaintext*>
CEvcpsHandshakePlaintexts;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvcpsHandshakePlaintextsIterator
//
//   Author: $author$
//     Date: 12/14/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpsHandshakePlaintexts::iterator
CEvcpsHandshakePlaintextsIterator;

///////////////////////////////////////////////////////////////////////
//  Typedef: const_CEvcpsHandshakePlaintextsIterator
//
//   Author: $author$
//     Date: 12/14/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpsHandshakePlaintexts::const_iterator
const_CEvcpsHandshakePlaintextsIterator;

#endif // _CEVCPSHANDSHAKEPLAINTEXT_HPP
