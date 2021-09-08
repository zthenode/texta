///////////////////////////////////////////////////////////////////////
//   File: cevchar2xwriter.hpp
//
// Author: $author$
//   Date: 10/30/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCHAR2XWRITER_HPP
#define _CEVCHAR2XWRITER_HPP

#include "cevcharwriter.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvChar2XWriter
//
// Author: $author$
//   Date: 10/30/2007
///////////////////////////////////////////////////////////////////////
class CEvChar2XWriter
: public CEvCharWriter
{
public:
    typedef CEvCharWriter CExtends;
    typedef CEvChar2XWriter CDerives;

    EvCharWriter& m_writer;
    char m_A, m_LF;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvChar2XWriter
    //
    //       Author: $author$
    //         Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    CEvChar2XWriter
    (EvCharWriter& writer, char A='A', char LF='\n')
    : m_writer(writer),
      m_A(A),
      m_LF(LF)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvChar2XWriter
    //
    //      Author: $author$
    //        Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvChar2XWriter()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: WriteLine
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteLine
    (const char* chars, LONG length=-1) 
    {
        LONG count, count2;
        if (0 <= (count = Write(chars, length)))
        if (0 <= (count2 = m_writer.Write(&m_LF, 1)))
            count += count2;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (const char* chars, LONG length=-1) 
    {
        LONG count;
        char c;

        if (0 < length)
        {
            for (count=0; count<length; count++)
                Put(chars[count]);
        }
        else for (count=0; (c=chars[count]); count++)
                Put(c);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Put
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Put
    (char c) 
    {
        LONG count = -EV_ERROR_FAILED;
        char x[2];

        x[0] = Char2X(c >> 4);
        x[1] = Char2X(c & 15);
        count = m_writer.Write(x, 2);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Char2X
    //
    //   Author: $author$
    //     Date: 10/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual char Char2X
    (char c) 
    {
        char x;
        BYTE b;
        if ((b=(BYTE)(c & 15)) < 10) x = '0'+b;
        else x = m_A+(b-10);
        return x;
    }
};
#endif // _CEVCHAR2XWRITER_HPP
