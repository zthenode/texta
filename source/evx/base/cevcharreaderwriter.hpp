///////////////////////////////////////////////////////////////////////
//   File: cevcharreaderwriter.hpp
//
// Author: $author$
//   Date: 4/19/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCHARREADERWRITER_HPP
#define _CEVCHARREADERWRITER_HPP

#include "cevreaderwriter.hpp"
#include "evcharreader.hpp"
#include "cevcharwriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvCharReaderWriterExtends
//
//   Author: $author$
//     Date: 4/19/2007
///////////////////////////////////////////////////////////////////////
typedef CEvReaderWriter
<char, ULONG, LONG, 
 EvCharReader, EvCharWriter, CEvCharWriter>
CEvCharReaderWriterExtends;

///////////////////////////////////////////////////////////////////////
//  Class: CEvCharReaderWriter
//
// Author: $author$
//   Date: 7/11/2007
///////////////////////////////////////////////////////////////////////
class CEvCharReaderWriter
: public CEvCharReaderWriterExtends
{
public:
    typedef CEvCharReaderWriterExtends CExtends;
    typedef CEvCharReaderWriter CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (const char* chars, LONG length=-1) 
    {
        LONG count = -EV_ERROR_FAILED;
        LONG put;
        char c;

        if (0 < length)
        {
            for (count = 0; count < length; count++)
                if (0 >= (put = Putc(chars[count])))
                    return -EV_ERROR_FAILED;
        }
        else
        {
            for (count = 0; (c = chars[count]); count++)
                if (0 >= (put = Putc(c)))
                    return -EV_ERROR_FAILED;
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Putc
    //
    //   Author: $author$
    //     Date: 7/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Putc(char c) 
    {
        LONG count = -EV_ERROR_FAILED;
        return count;
    }
};

#endif // _CEVCHARREADERWRITER_HPP
