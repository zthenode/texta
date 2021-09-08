///////////////////////////////////////////////////////////////////////
//   File: cevfilewriter.hpp
//
// Author: $author$
//   Date: 7/9/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILEWRITER_HPP
#define _CEVFILEWRITER_HPP

#include "cevcharwriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFILEWriter
//
// Author: $author$
//   Date: 7/9/2007
///////////////////////////////////////////////////////////////////////
class CEvFILEWriter
: public CEvCharWriter
{
public:
    typedef CEvCharWriter CExtends;
    typedef CEvFILEWriter CDerives;

    FILE* m_file;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFILEWriter
    //
    //       Author: $author$
    //         Date: 7/9/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFILEWriter(FILE* file=0) 
    : m_file(file) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 7/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (const char* chars, LONG length) 
    {
        LONG count = 0;
        
        if (!m_file)
            return 0;

        if (0 > length)
            length = strlen(chars);

        count = (LONG)fwrite(chars, 1, length, m_file);
        return count;
    }
};
#endif // _CEVFILEWRITER_HPP
