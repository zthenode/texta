///////////////////////////////////////////////////////////////////////
//   File: cevpcchar2pcharbuffer.hpp
//
// Author: $author$
//   Date: 7/19/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVPCCHAR2PCHARBUFFER_HPP
#define _CEVPCCHAR2PCHARBUFFER_HPP

#include <vector>
#include "cevpcharbuffer.hpp"
#include "cevpccharbuffer.hpp"
#include "cevcharbuffer.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvPCHARVector
//
//   Author: $author$
//     Date: 7/19/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::vector<PCHAR>
CEvPCHARVector;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvPCCHARVector
//
//   Author: $author$
//     Date: 7/19/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::vector<PCCHAR>
CEvPCCHARVector;

///////////////////////////////////////////////////////////////////////
//  Class: CEvPCCHAR2PCHARBuffer
//
// Author: $author$
//   Date: 7/19/2007
///////////////////////////////////////////////////////////////////////
class CEvPCCHAR2PCHARBuffer
: public CEvPCHARBuffer
{
public:
    typedef CEvPCHARBuffer CExtends;
    typedef CEvPCCHAR2PCHARBuffer CDerives;

    CEvPCHARVector m_charsVector;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvPCCHAR2PCHARBuffer
    //
    //       Author: $author$
    //         Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvPCCHAR2PCHARBuffer() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvPCCHAR2PCHARBuffer
    //
    //      Author: $author$
    //        Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvPCCHAR2PCHARBuffer()
    {
        ClearVector();
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Append
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Append
    (const PCCHAR* buffer, LONG length=-1) 
    {
        LONG oldLength = Length();
        LONG count,i;

        if (0 < length)
        {
            for (i = 0; i < length; i++)
                if (0 > (count = Append(buffer[i])))
                    return count;
        }
        else
        {
            for (i = 0; buffer[i]; i++)
                if (0 > (count = Append(buffer[i])))
                    return count;
        }
        length = Length();
        return length-oldLength;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: VAppend
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG VAppend(va_list va) 
    {
        LONG length = 0;
        LONG count;
        PCCHAR of;

        while (0 != (of = va_arg(va, PCCHAR)))
        {
            if (0 > (count = Append(of)))
                return count;
            length += count;
        }
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Append
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Append(PCCHAR buffer) 
    {
        LONG length = 0;
        LONG count;
        PCHAR chars;

        if (0 <= (count = strlen(buffer)))
        if ((chars = new CHAR[count+1]))
        {
            memcpy(chars, buffer, count);
            chars[count] = 0;
            if (0 > (count = CExtends::Append(&chars, 1)))
            {
                delete chars;
                return count;
            }
            m_charsVector.push_back(chars);
            length += count;
        }
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Clear
    //
    //   Author: $author$
    //     Date: 7/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Clear() 
    {
        LONG length = CExtends::Clear();
        ClearVector();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ClearVector
    //
    //   Author: $author$
    //     Date: 7/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void ClearVector() 
    {
        CEvPCHARVector::iterator i;
        PCHAR chars;

        for (i = m_charsVector.begin(); 
             i != m_charsVector.end(); i++)
        {
            if ((chars = *i))
                delete chars;
        }
    }
};
#endif // _CEVPCCHAR2PCHARBUFFER_HPP
