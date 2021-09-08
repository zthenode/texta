///////////////////////////////////////////////////////////////////////
//   File: cevstringwritert.hpp
//
// Author: $author$
//   Date: 1/26/2008
///////////////////////////////////////////////////////////////////////
#ifndef _CEVSTRINGWRITERT_HPP
#define _CEVSTRINGWRITERT_HPP

#include "cevcharwriter.hpp"
#include "cevwriter.hpp"
#include "cevstring.hpp"

#undef CDB_CLASS
#define CDB_CLASS "CEvStringWriterT"
///////////////////////////////////////////////////////////////////////
//  Class: CEvStringWriterT
//
// Author: $author$
//   Date: 1/26/2008
///////////////////////////////////////////////////////////////////////
template
<class TChar=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 class TString=CEvCHARString,
 class TExtends=CEvCHARWriter>
 
class CEvStringWriterT
: public TExtends
{
public:
    typedef TExtends CExtends;
    typedef CEvStringWriterT CDerives;

    TString& m_string;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvStringWriterT
    //
    //      Author: $author$
    //        Date: 1/26/2008
    ///////////////////////////////////////////////////////////////////////
    CEvStringWriterT(TString& string) 
    : m_string(string)
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
        TLength count = m_string.Append(chars, length);
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
        TLength count = m_string.Clear();
        return count;
    }
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvCHARStringWriter
//
//  Author: $author$
//    Date: 1/26/2008
///////////////////////////////////////////////////////////////////////
typedef CEvStringWriterT
<CHAR, ULONG, LONG, 
 CEvCHARString, CEvCHARWriter>
CEvCHARStringWriter;

#endif // _CEVSTRINGWRITERT_HPP 
