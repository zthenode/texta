///////////////////////////////////////////////////////////////////////
//   File: cevstringwriter.hpp
//
// Author: $author$
//   Date: 4/20/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSTRINGWRITER_HPP
#define _CEVSTRINGWRITER_HPP

#include <string.h>
#include "cevcharwriter.hpp"
#include "cevstring.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvStringWriter
//
// Author: $author$
//   Date: 4/20/2007
///////////////////////////////////////////////////////////////////////
class CEvStringWriter
: public CEvCharWriter
{
public:
    typedef CEvCharWriter CExtends;
    typedef CEvStringWriter CDerives;

    CEvString& m_string;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvStringWriter
    //
    //       Author: $author$
    //         Date: 4/20/2007
    ///////////////////////////////////////////////////////////////////////
    CEvStringWriter
    (CEvString& string)
    : m_string(string)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 4/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (const char* chars, LONG length=-1) 
    {
        LONG count = m_string.Append(chars, length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Reset
    //
    //   Author: $author$
    //     Date: 4/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Reset() 
    {
        LONG count = m_string.Clear();
        return count;
    }
};
#endif // _CEVSTRINGWRITER_HPP
