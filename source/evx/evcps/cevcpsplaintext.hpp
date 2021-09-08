///////////////////////////////////////////////////////////////////////
//   File: cevcpsplaintext.hpp
//
// Author: $author$
//   Date: 11/23/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSPLAINTEXT_HPP
#define _CEVCPSPLAINTEXT_HPP

#include <vector>
#include "cevcpsrecord.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsPlaintext
//
// Author: $author$
//   Date: 11/23/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsPlaintext
: public CEvcpsRecord
{
public:
    typedef CEvcpsRecord CExtends;
    typedef CEvcpsPlaintext CDerives;

    CEvcpsBase& m_fragment;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsPlaintext
    //
    //       Author: $author$
    //         Date: 11/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsPlaintext
    (CEvcpsBase& fragment,
     BYTE contentType=0,
     UINT16 length=0)
    : CExtends(contentType, length),
      m_fragment(fragment)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 11/23/2007
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
    //     Date: 11/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1, count2;

        m_length = m_fragment.Sizeof();

        if (0 > (count1 = WriteHeader(writer)))
            return length;

        if (0 > (count2 = m_fragment.Write(writer)))
            return length;

        length = count1 + count2;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteHeader
    //
    //   Author: $author$
    //     Date: 11/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteHeader
    (EvCharWriter& writer) 
    {
        LONG length = CExtends::Write(writer);
        return length;
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvcpsPlaintexts
//
//   Author: $author$
//     Date: 12/15/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::vector<CEvcpsPlaintext*>
CEvcpsPlaintexts;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvcpsPlaintextsIterator
//
//   Author: $author$
//     Date: 12/15/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpsPlaintexts::iterator
CEvcpsPlaintextsIterator;

///////////////////////////////////////////////////////////////////////
//  Typedef: const_CEvcpsPlaintextsIterator
//
//   Author: $author$
//     Date: 12/15/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpsPlaintexts::const_iterator
const_CEvcpsPlaintextsIterator;

#endif // _CEVCPSPLAINTEXT_HPP
