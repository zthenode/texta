///////////////////////////////////////////////////////////////////////
//   File: cevbyte2charwriter.hpp
//
// Author: $author$
//   Date: 12/20/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVBYTE2CHARWRITER_HPP
#define _CEVBYTE2CHARWRITER_HPP

#include "cevbytewriter.hpp"
#include "evcharwriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvBYTE2CharWriter
//
// Author: $author$
//   Date: 12/20/2007
///////////////////////////////////////////////////////////////////////
class CEvBYTE2CharWriter
: public CEvBYTEWriter
{
public:
    typedef CEvBYTEWriter CExtends;
    typedef CEvBYTE2CharWriter CDerives;

    EvCharWriter& m_writer;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvBYTE2CharWriter
    //
    //       Author: $author$
    //         Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    CEvBYTE2CharWriter
    (EvCharWriter& writer)
    : m_writer(writer)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (const BYTE* chars, LONG length=-1) 
    {
        LONG count = m_writer.Write
        ((const char*)(chars), length);
        return count;
    }
};
#endif // _CEVBYTE2CHARWRITER_HPP
