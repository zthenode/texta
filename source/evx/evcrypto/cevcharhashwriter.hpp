///////////////////////////////////////////////////////////////////////
//   File: cevcharhashwriter.hpp
//
// Author: $author$
//   Date: 11/26/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCHARHASHWRITER_HPP
#define _CEVCHARHASHWRITER_HPP

#include "evhash.hpp"
#include "cevcharwriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCharHashWriter
//
// Author: $author$
//   Date: 11/26/2007
///////////////////////////////////////////////////////////////////////
class CEvCharHashWriter
: public CEvCharWriter
{
public:
    typedef CEvCharWriter CExtends;
    typedef CEvCharHashWriter CDerives;

    EvHash& m_hash;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCharHashWriter
    //
    //       Author: $author$
    //         Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCharHashWriter
    (EvHash& hash)
    : m_hash(hash) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 11/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_hash.Hash
        ((const BYTE*)(chars), length);
        return count;
    }
};
#endif // _CEVCHARHASHWRITER_HPP
