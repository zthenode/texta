///////////////////////////////////////////////////////////////////////
//   File: cevcphexdecoder.hpp
//
// Author: $author$
//   Date: 12/6/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPHEXDECODER_HPP
#define _CEVCPHEXDECODER_HPP

#include "cevreader.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpHexDecoder
//
// Author: $author$
//   Date: 12/6/2007
///////////////////////////////////////////////////////////////////////
template
<class TChar=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 class TImplements=EvCHARReader,
 class TExtends=CEvCHARReader>

class CEvcpHexDecoder
: public TExtends
{
public:
    typedef TExtends CExtends;
    typedef CEvcpHexDecoder CDerives;

    const TChar m_0;
    const TChar m_9;
    const TChar m_a;
    const TChar m_f;
    const TChar m_A;
    const TChar m_F;

    TImplements& m_reader;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpHexDecoder
    //
    //       Author: $author$
    //         Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpHexDecoder
    (TImplements& reader) 
    : m_0('0'),
      m_9('9'),
      m_a('a'),
      m_f('f'),
      m_A('A'),
      m_F('F'),
      m_reader(reader)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Read
    (TChar* chars, TSize size) 
    {
        TLength length = -EV_ERROR_FAILED;
        TSize count;
        BYTE nibble[2];
        TChar x[2];

        for (count=0; count<size; count++)
        {
            if (2 > m_reader.Read(x, 2))
                return length;

            if ((1 > X2BYTE(nibble[0], x[0])) 
                || (1 > X2BYTE(nibble[1], x[1])))
                return length;

            chars[count] = (TChar)((nibble[0] << 4) | nibble[1]);
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: X2BYTE
    //
    //   Author: $author$
    //     Date: 12/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength X2BYTE
    (BYTE& b, TChar x) 
    {
        TLength length = -EV_ERROR_FAILED;

        if ((x >= m_0) && (x <= m_9))
            b = x - m_0;
        else if ((x >= m_a) && (x <= m_f))
                b = (x - m_a) + 10;
        else if ((x >= m_A) && (x <= m_F))
                b = (x - m_A) + 10;
        else return length;
        return 1;
    }
};

#endif // _CEVCPHEXDECODER_HPP
