///////////////////////////////////////////////////////////////////////
//   File: cevdeligatereader.hpp
//
// Author: $author$
//   Date: 12/19/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVDELIGATEREADER_HPP
#define _CEVDELIGATEREADER_HPP

#include "cevreader.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvDeligateReader
//
// Author: $author$
//   Date: 12/19/2007
///////////////////////////////////////////////////////////////////////
template
<class TChar=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 class TImplements=EvReader
 <TChar,TSize,TLength>,
 class TExtends=CEvReader
 <TChar,TSize,TLength,TImplements,CEvBase> >

class CEvDeligateReader
: public TExtends
{
public:
    typedef TExtends CExtends;
    typedef CEvDeligateReader CDerives;

    TImplements*& m_deligate;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDeligateReader
    //
    //       Author: $author$
    //         Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvDeligateReader(TImplements*& deligate)
    : m_deligate(deligate) 
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Read
    (TChar* chars, TSize size) 
    {
        TLength length = -EV_ERROR_FAILED;
        if (m_deligate)
            length = m_deligate->Read(chars, size);
        return length;
    }
};
#endif // _CEVDELIGATEREADER_HPP
