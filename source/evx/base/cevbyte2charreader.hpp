///////////////////////////////////////////////////////////////////////
//   File: cevbyte2charreader.hpp
//
// Author: $author$
//   Date: 12/8/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVBYTE2CHARREADER_HPP
#define _CEVBYTE2CHARREADER_HPP

#include "cevcharreader.hpp"
#include "cevbytereader.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvBYTE2CharReader
//
// Author: $author$
//   Date: 12/8/2007
///////////////////////////////////////////////////////////////////////
class CEvBYTE2CharReader
: public CEvCharReader
{
public:
    typedef CEvCharReader CExtends;
    typedef CEvBYTE2CharReader CDerives;

    EvBYTEReader& m_reader;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvBYTE2CharReader
    //
    //       Author: $author$
    //         Date: 12/8/2007
    ///////////////////////////////////////////////////////////////////////
    CEvBYTE2CharReader
    (EvBYTEReader& reader) 
    : m_reader(reader) 
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (char* chars, ULONG size) 
    {
        LONG count = m_reader.Read((BYTE*)(chars), size);
        return count;
    }
};
#endif // _CEVBYTE2CHARREADER_HPP
