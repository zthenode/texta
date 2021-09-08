///////////////////////////////////////////////////////////////////////
//   File: cevchar2bytewriter.hpp
//
// Author: $author$
//   Date: 12/20/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCHAR2BYTEWRITER_HPP
#define _CEVCHAR2BYTEWRITER_HPP

#include "cevcharwriter.hpp"
#include "evbytewriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvChar2BYTEWriter
//
// Author: $author$
//   Date: 12/20/2007
///////////////////////////////////////////////////////////////////////
class CEvChar2BYTEWriter
: public CEvCharWriter
{
public:
    typedef CEvCharWriter CExtends;
    typedef CEvChar2BYTEWriter CDerives;

    EvBYTEWriter& m_writer;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvChar2BYTEWriter
    //
    //       Author: $author$
    //         Date: 12/20/2007
    ///////////////////////////////////////////////////////////////////////
    CEvChar2BYTEWriter
    (EvBYTEWriter& writer) 
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
    (const char* chars, LONG length=-1) 
    {
        LONG count = m_writer.Write
        ((const BYTE*)(chars), length);
        return count;
    }
};
#endif // _CEVCHAR2BYTEWRITER_HPP
