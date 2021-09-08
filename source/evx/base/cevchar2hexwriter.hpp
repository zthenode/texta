///////////////////////////////////////////////////////////////////////
//   File: cevchar2hexwriter.hpp
//
// Author: $author$
//   Date: 11/30/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCHAR2HEXWRITER_HPP
#define _CEVCHAR2HEXWRITER_HPP

#include "cevcharwriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvChar2HexWriter
//
// Author: $author$
//   Date: 11/30/2007
///////////////////////////////////////////////////////////////////////
class CEvChar2HexWriter
: public CEvCharWriter
{
public:
    typedef CEvCharWriter CExtends;
    typedef CEvChar2HexWriter CDerives;

    EvCharWriter& m_writer;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvChar2HexWriter
    //
    //       Author: $author$
    //         Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    CEvChar2HexWriter
    (EvCharWriter& writer) 
    : m_writer(writer)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 11/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_writer.WriteX(chars,length);
        return count;
    }
};
#endif // _CEVCHAR2HEXWRITER_HPP
