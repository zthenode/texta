///////////////////////////////////////////////////////////////////////
//   File: cevdeligatewriter.hpp
//
// Author: $author$
//   Date: 12/19/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDELIGATEWRITER_HPP
#define _CEVDELIGATEWRITER_HPP

#include "cevwriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvDeligateWriter
//
// Author: $author$
//   Date: 12/19/2007
///////////////////////////////////////////////////////////////////////
template
<class TChar=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 class TImplements=EvWriter
 <TChar, TSize, TLength>,
 class TExtends=CEvWriter
 <TChar, TSize, TLength, TImplements, CEvBase> >

class CEvDeligateWriter
: public TExtends
{
public:
    typedef TExtends CExtends;
    typedef CEvDeligateWriter CDerives;

    TImplements*& m_deligate;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDeligateWriter
    //
    //       Author: $author$
    //         Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvDeligateWriter(TImplements*& deligate)
    : m_deligate(deligate)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Write
    (const TChar* chars, TLength length=-1) 
    {
        TLength count = -EV_ERROR_FAILED;
        if (m_deligate)
            count = m_deligate->Write(chars, length);
        return count;
    }
};
#endif // _CEVDELIGATEWRITER_HPP
