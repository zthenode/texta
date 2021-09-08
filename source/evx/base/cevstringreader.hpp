///////////////////////////////////////////////////////////////////////
//   File: cevstringreader.hpp
//
// Author: $author$
//   Date: 4/19/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSTRINGREADER_HPP
#define _CEVSTRINGREADER_HPP

#include <string.h>
#include "cevcharreader.hpp"
#include "cevstring.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvStringReader
//
// Author: $author$
//   Date: 4/19/2007
///////////////////////////////////////////////////////////////////////
class CEvStringReader
: public CEvCharReader
{
public:
    typedef CEvCharReader CExtends;
    typedef CEvStringReader CDerives;

    CEvString& m_string;
    ULONG m_tell;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvStringReader
    //
    //       Author: $author$
    //         Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvStringReader
    (CEvString& string, ULONG tell=0)
    : m_string(string),
      m_tell(tell)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (char* chars, ULONG size) 
    {
        LONG count = size;
        ULONG length;
        ULONG told;
        const char* stringChars;

        if (!(stringChars = m_string.c_str()))
            return -EV_ERROR_FAILED;

        if (m_tell >= (length = (LONG)(m_string.length())))
            return 0;

        if (length < (told = m_tell+size))
            count = (told = size) - m_tell;

        memcpy(chars, stringChars+m_tell, count);
        m_tell = told;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Reset
    //
    //   Author: $author$
    //     Date: 4/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Reset() 
    {
        LONG count = m_tell;
        m_tell = 0;
        return count;
    }
};
#endif // _CEVSTRINGREADER_HPP
