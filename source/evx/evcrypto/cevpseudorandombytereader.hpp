///////////////////////////////////////////////////////////////////////
//   File: cevpseudorandombytereader.hpp
//
// Author: $author$
//   Date: 11/8/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVPSEUDORANDOMBYTEREADER_HPP
#define _CEVPSEUDORANDOMBYTEREADER_HPP

#include <vector>
#include "evplatform_time.h"
#include "cevbytereader.hpp"
#include "cevutctime.hpp"
#include "evdebug.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvPseudoRandomBYTEReader
//
// Author: $author$
//   Date: 11/8/2007
///////////////////////////////////////////////////////////////////////
class CEvPseudoRandomBYTEReader
: public CEvBYTEReader
{
public:
    typedef CEvBYTEReader CExtends;
    typedef CEvPseudoRandomBYTEReader CDerives;

    CEvUTCTime m_utcTime;
    unsigned int m_rand;
    ULONG m_avail;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvPseudoRandomBYTEReader
    //
    //       Author: $author$
    //         Date: 11/8/2007
    ///////////////////////////////////////////////////////////////////////
    CEvPseudoRandomBYTEReader
    (bool initialize=false) 
    : m_rand(0),
      m_avail(0)
    {
        if (initialize)
            Initialize();
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvPseudoRandomBYTEReader
    //
    //      Author: $author$
    //        Date: 11/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvPseudoRandomBYTEReader()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Initialize
    //
    //   Author: $author$
    //     Date: 12/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void Initialize() 
    {
        //DBF("()\n");
        srand((ULONG)(m_utcTime.GetCurrent()));
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
        ULONG i, j, count, length;

        for (length=0; length<size; )
        {
            if (1 > m_avail)
            {
                m_rand = (unsigned int)rand();
                //DBT("() m_rand = 0x%X\n", m_rand);

                m_avail = sizeof(m_rand);
            }

            if ((count = size-length) > m_avail)
                count = m_avail;

            for (j=0,i=0; i<count; i++)
            {
                if ((chars[length+j] = (BYTE)(m_rand & 255)))
                {
                    //DBT("() char = 0x%X\n", chars[length+j]);
                    j++;
                }

                m_rand >>= 8;
            }

            length += j;
            m_avail -= count;
        }
        return length;
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvPseudoRandomBYTEReaders
//
//   Author: $author$
//     Date: 11/8/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::vector<CEvPseudoRandomBYTEReader*>
CEvPseudoRandomBYTEReaders;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvPseudoRandomBYTEReadersIterator
//
//   Author: $author$
//     Date: 11/8/2007
///////////////////////////////////////////////////////////////////////
typedef CEvPseudoRandomBYTEReaders::iterator
CEvPseudoRandomBYTEReadersIterator;

///////////////////////////////////////////////////////////////////////
//  Typedef: const_CEvPseudoRandomBYTEReadersIterator
//
//   Author: $author$
//     Date: 11/8/2007
///////////////////////////////////////////////////////////////////////
typedef CEvPseudoRandomBYTEReaders::const_iterator
const_CEvPseudoRandomBYTEReadersIterator;

#endif // _CEVPSEUDORANDOMBYTEREADER_HPP
