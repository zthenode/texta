///////////////////////////////////////////////////////////////////////
//   File: cevcphexencoder.hpp
//
// Author: $author$
//   Date: 12/11/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPHEXENCODER_HPP
#define _CEVCPHEXENCODER_HPP

#include "cevwriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpHexEncoder
//
// Author: $author$
//   Date: 12/11/2007
///////////////////////////////////////////////////////////////////////
template
<class TChar=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 class TImplements=EvCHARWriter,
 class TExtends=CEvCHARWriter>

class CEvcpHexEncoder
: public TExtends
{
public:
    typedef TExtends CExtends;
    typedef CEvcpHexEncoder CDerives;

    const TChar m_0;
    const TChar m_A;
    TImplements& m_writer;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpHexEncoder
    //
    //       Author: $author$
    //         Date: 12/11/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpHexEncoder
    (TImplements& writer)
    : m_0('0'),
      m_A('A'),
      m_writer(writer)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Write
    (const TChar* chars, TLength length) 
    {
        TLength count = -EV_ERROR_FAILED;
        TLength i, count1, count2;
        TChar x[2];

        if (0 <= length)
        {
            for (count1=0, i=0; i<length; i++, count1+=count2)
            {
                Char2X(x, chars[i]);
                if (0 > (count2 = m_writer.Write(x, 2)))
                    return count;
            }
            count = count1;
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Char2X
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void Char2X
    (TChar x[2], TChar c) 
    {
        BYTE b = (BYTE)(c);
        x[0] = BYTE2X(b >> 4);
        x[1] = BYTE2X(b & 15);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: BYTE2X
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TChar BYTE2X(BYTE b) 
    {
        TChar x;
        if ((b &= 15) < 10)
            x = m_0+b;
        else x = m_A+(b-10);
        return x;
    }
};
#endif // _CEVCPHEXENCODER_HPP
