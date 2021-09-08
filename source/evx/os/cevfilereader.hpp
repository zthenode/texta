///////////////////////////////////////////////////////////////////////
//   File: cevfilereader.hpp
//
// Author: $author$
//   Date: 7/9/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILEREADER_HPP
#define _CEVFILEREADER_HPP

#include "cevcharreader.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFILEReader
//
// Author: $author$
//   Date: 7/9/2007
///////////////////////////////////////////////////////////////////////
class CEvFILEReader
: public CEvCharReader
{
public:
    typedef CEvCharReader CExtends;
    typedef CEvFILEReader CDerives;

    FILE* m_file;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFILEReader
    //
    //       Author: $author$
    //         Date: 7/9/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFILEReader(FILE* file=0) 
    : m_file(file)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 7/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (char* chars, ULONG size) 
    {
        LONG count = 0;
        
        if (!m_file)
            return 0;

        count = (LONG)fread(chars, 1, size, m_file);
        return count;
    }
};
#endif // _CEVFILEREADER_HPP
