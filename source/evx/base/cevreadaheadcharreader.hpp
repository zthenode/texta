///////////////////////////////////////////////////////////////////////
//   File: cevreadaheadcharreader.hpp
//
// Author: $author$
//   Date: 10/14/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVREADAHEADCHARREADER_HPP
#define _CEVREADAHEADCHARREADER_HPP

#include <stdio.h>
#include "cevcharreader.hpp"
#include "cevstringreader.hpp"
#include "cevstringwriter.hpp"
#include "cevstring.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvReadAheadCharReader
//
// Author: $author$
//   Date: 10/14/2007
///////////////////////////////////////////////////////////////////////
class CEvReadAheadCharReader
: public CEvCharReader
{
public:
    typedef CEvCharReader CExtends;
    typedef CEvReadAheadCharReader CDerives;

    typedef LONG (CDerives::*MRead)
    (char* chars, ULONG size);

    EvCharReader& m_reader;
    MRead m_read;
    CEvString m_buffer;
    CEvStringReader m_bufferReader;
    CEvStringWriter m_bufferWriter;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvReadAheadCharReader
    //
    //       Author: $author$
    //         Date: 10/14/2007
    ///////////////////////////////////////////////////////////////////////
    CEvReadAheadCharReader
    (EvCharReader& reader) 
    : m_reader(reader),
      m_read(&CDerives::ReadReader),
      m_bufferReader(m_buffer),
      m_bufferWriter(m_buffer)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadAhead
    //
    //   Author: $author$
    //     Date: 10/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadAhead
    (char* chars,
     ULONG size) 
    {
        LONG length = -EV_ERROR_FAILED;
        const char* bufferChars;
        LONG bufferLength;

        if (0 <= (bufferLength = m_buffer.Clear()))
        if (0 < (length = m_buffer.Read(m_reader, size)))
        {
            m_read = &CDerives::ReadBuffer;

            if ((bufferChars = m_buffer.HasChars(bufferLength)))
                memcpy(chars, bufferChars, bufferLength);
        }
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 10/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (char* chars,
     ULONG size) 
    {
        LONG length;
        if (m_read)
            length = (this->*m_read)(chars, size);
        else length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadReader
    //
    //   Author: $author$
    //     Date: 10/14/2007
    ///////////////////////////////////////////////////////////////////////
    LONG ReadReader
    (char* chars,
     ULONG size) 
    {
        LONG length = m_reader.Read(chars, size);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadBuffer
    //
    //   Author: $author$
    //     Date: 10/14/2007
    ///////////////////////////////////////////////////////////////////////
    LONG ReadBuffer
    (char* chars,
     ULONG size) 
    {
        LONG lsize = (LONG)(size);
        LONG length, count;
        
        if (lsize >= (length = m_bufferReader.Read(chars, size)))
        {
            m_read = &CDerives::ReadReader;
            if ((lsize > length) && (0 <= length))
            if (0 < (count = m_reader.Read(chars+length, lsize-length)))
                length += count;
        }
        return length;
    }
};
#endif // _CEVREADAHEADCHARREADER_HPP
