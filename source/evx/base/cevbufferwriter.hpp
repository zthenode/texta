///////////////////////////////////////////////////////////////////////
//   File: cevbufferwriter.hpp
//
// Author: $author$
//   Date: 1/26/2008
///////////////////////////////////////////////////////////////////////

#ifndef _CEVBUFFERWRITER_HPP
#define _CEVBUFFERWRITER_HPP

#include "cevwriter.hpp"

#undef CDB_CLASS
#define CDB_CLASS "CEvBufferWriter"
///////////////////////////////////////////////////////////////////////
//  Class: CEvBufferWriter
//
// Author: $author$
//   Date: 1/26/2008
///////////////////////////////////////////////////////////////////////
template
<class TChar=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 class TExtends=CEvCHARWriter>
 
class CEvBufferWriter
: public TExtends
{
public:
    typedef TExtends CExtends;
    typedef CEvBufferWriter CDerives;

    TChar& m_buffer;
    TSize m_size;
    TSize m_tell;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvBufferWriter
    //
    //      Author: $author$
    //        Date: 1/26/2008
    ///////////////////////////////////////////////////////////////////////
    CEvBufferWriter
    (TChar& buffer, TSize size) 
    : m_buffer(buffer),
      m_size(size),
      m_tell(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 1/26/2008
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (const TChar* chars, TLength length=-1) 
    {
        TLength count = -EV_ERROR_FAILED;

        if (!length)
            return length;

        if (0 > length)
            return count;

        if (length > (count = (TLength)(m_size-m_tell)))
            length = count;

        for (count = 0; count < length; count++)
            (&m_buffer)[m_tell++] = chars[count];
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Reset
    //
    //   Author: $author$
    //     Date: 1/26/2008
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Reset() 
    {
        TLength count = m_tell;
        m_tell = 0;
        return count;
    }
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvCHARBufferWriter
//
//  Author: $author$
//    Date: 1/26/2008
///////////////////////////////////////////////////////////////////////
typedef CEvBufferWriter
<CHAR, ULONG, LONG, CEvCHARWriter>
CEvCHARBufferWriter;

#endif // _CEVBUFFERWRITER_HPP 
