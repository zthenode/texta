///////////////////////////////////////////////////////////////////////
//   File: cevrandombytereader.hpp
//
// Author: $author$
//   Date: 1/25/2008
///////////////////////////////////////////////////////////////////////
#ifndef _CEVRANDOMBYTEREADER_HPP
#define _CEVRANDOMBYTEREADER_HPP

#include "cevbytereader.hpp"
#include "cevpseudorandombytereader.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvRandomBYTEReader
//
// Author: $author$
//   Date: 1/25/2008
///////////////////////////////////////////////////////////////////////
class CEvRandomBYTEReader
: public CEvBYTEReader
{
public:
    typedef CEvBYTEReader CExtends;
    typedef CEvRandomBYTEReader CDerives;

    bool m_initialized;
    CEvPseudoRandomBYTEReader m_pseudoReader;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvRandomBYTEReader
    //
    //      Author: $author$
    //        Date: 1/25/2008
    ///////////////////////////////////////////////////////////////////////
    CEvRandomBYTEReader() 
    : m_initialized(false)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: CEvRandomBYTEReader
    //
    //     Author: $author$
    //       Date: 1/25/2008
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvRandomBYTEReader()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 1/25/2008
    ///////////////////////////////////////////////////////////////////////
    virtual void Initialize() 
    {
        m_pseudoReader.Initialize();
        m_initialized = true;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 11/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (BYTE* chars, ULONG size) 
    {
        LONG length;

        if (!m_initialized)
            Initialize();

        length = m_pseudoReader.Read(chars, size);
        return length;
    }
};
#endif // _CEVRANDOMBYTEREADER_HPP
