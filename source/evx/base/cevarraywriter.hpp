///////////////////////////////////////////////////////////////////////
//   File: cevarraywriter.hpp
//
// Author: $author$
//   Date: 12/4/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVARRAYWRITER_HPP
#define _CEVARRAYWRITER_HPP

#include "cevwriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvArrayWriter
//
// Author: $author$
//   Date: 12/4/2007
///////////////////////////////////////////////////////////////////////
template
<class TChar=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 class TExtends=CEvWriter
 <TChar, TSize, TLength, EvBase> >

class CEvArrayWriter
: public TExtends
{
public:
    typedef TExtends CExtends;
    typedef CEvArrayWriter CDerives;

    TChar& m_chars;
    TSize m_size;
    TSize m_tell;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvArrayWriter
    //
    //       Author: $author$
    //         Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvArrayWriter
    (TChar& chars, TSize size) 
    : m_chars(chars),
      m_size(size),
      m_tell(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReWrite
    //
    //   Author: $author$
    //     Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength ReWrite
    (const TChar* chars, TLength length) 
    {
        TLength count = 0;
        if (0 <= (count = Reset()))
            count = Write(chars, length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Reset
    //
    //   Author: $author$
    //     Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Reset() 
    {
        TLength count = (TLength)(m_tell);
        m_tell = 0;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 12/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Write
    (const TChar* chars, TLength length) 
    {
        TLength count = 0;
        TSize size;
        if (0 < length)
        if (m_tell < m_size)
        {
            if ((count = length) 
                > (TLength)(size = (m_size - m_tell)))
                count = size;

            for (size=0; size<(TSize)(count); size++)
                (&m_chars)[m_tell+size] = chars[size];

            m_tell += count;
        }
        return count;
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvCharArrayWriter
//
//   Author: $author$
//     Date: 12/4/2007
///////////////////////////////////////////////////////////////////////
typedef CEvArrayWriter
<char, ULONG, LONG, CEvCharWriter>
CEvCharArrayWriter;

#endif // _CEVARRAYWRITER_HPP
