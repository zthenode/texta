///////////////////////////////////////////////////////////////////////
//   File: cevcharputer.hpp
//
// Author: $author$
//   Date: 5/21/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCHARPUTER_HPP
#define _CEVCHARPUTER_HPP

#include "cevcharwriter.hpp"
#include "evcharreader.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCharPuter
//
// Author: $author$
//   Date: 5/21/2007
///////////////////////////////////////////////////////////////////////
class CEvCharPuter
: public CEvCharWriter
{
public:
    typedef CEvCharWriter CExtends;
    typedef CEvCharPuter CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 5/20/2008
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharReader& reader, LONG length=-1) 
    {
        LONG count = -EV_ERROR_FAILED;
        LONG put = 1;
        char c;

        if (0 < length)
        {
            for (count = 0; count < length; count++)
            {
                if (0 < (put = reader.Read(&c, 1)))
                if (0 < (put = Putc(c)))
                    continue;
                return -EV_ERROR_FAILED;
            }
        }
        else
        {
            for (count = 0; (0 < put); count++)
            {
                if (0 >= (put = reader.Read(&c, 1)))
                    break;
                if (0 >= (put = Putc(c)))
                    return -EV_ERROR_FAILED;
            }
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 5/21/2007
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
    //     Date: 5/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Putc(char c) 
    {
        LONG count = -EV_ERROR_FAILED;
        return count;
    }
};
#endif // _CEVCHARPUTER_HPP
