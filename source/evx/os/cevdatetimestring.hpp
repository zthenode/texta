///////////////////////////////////////////////////////////////////////
//   File: cevdatetimestring.hpp
//
// Author: $author$
//   Date: 9/10/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDATETIMESTRING_HPP
#define _CEVDATETIMESTRING_HPP

#include "cevstring.hpp"
#include "cevstringwriter.hpp"
#include "cevdatetime2charwriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvDateTimeString
//
// Author: $author$
//   Date: 9/10/2007
///////////////////////////////////////////////////////////////////////
class CEvDateTimeString
: public CEvString
{
public:
    typedef CEvString CExtends;
    typedef CEvDateTimeString CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDateTimeString
    //
    //       Author: $author$
    //         Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    CEvDateTimeString() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDateTimeString
    //
    //       Author: $author$
    //         Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    CEvDateTimeString
    (const EvDateTime& dateTime) 
    {
        EvError error;
        LONG length;
        if (0 > (length = Append(dateTime)))
            throw(error = -length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Assign
    //
    //   Author: $author$
    //     Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Assign
    (const EvDateTime& dateTime) 
    {
        LONG count = 0;
        if (0 <= (count = Clear()))
            count = Append(dateTime);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Append
    //
    //   Author: $author$
    //     Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Append
    (const EvDateTime& dateTime) 
    {
        CEvStringWriter writer(*this);
        CEvDateTime2CharWriter dtcWriter;
        LONG count = dtcWriter.Write(writer, dateTime);
        return count;
    }
};
#endif // _CEVDATETIMESTRING_HPP
