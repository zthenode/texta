///////////////////////////////////////////////////////////////////////
//   File: cevbuffer.hpp
//
// Author: $author$
//   Date: 5/2/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVBUFFER_HPP
#define _CEVBUFFER_HPP

#include <stdarg.h>
#include <string>
#include "evplatform.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvBuffer
//
// Author: $author$
//   Date: 5/2/2007
///////////////////////////////////////////////////////////////////////
template
<class TOf,
 class TSize=ULONG,
 class TLength=LONG>

class CEvBuffer
: public ::std::basic_string<TOf>
{
public:
    typedef ::std::basic_string<TOf> CExtends;
    typedef CEvBuffer CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvBuffer
    //
    //       Author: $author$
    //         Date: 5/2/2007
    ///////////////////////////////////////////////////////////////////////
    CEvBuffer(const TOf* buffer=0, TLength length=-1) 
    {
        if (buffer)
            Append(buffer, length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvBuffer
    //
    //      Author: $author$
    //        Date: 5/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvBuffer()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: VAssign
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength VAssign(va_list va) 
    {
        TLength length = 0;
        if (0 > (length = Clear()))
            return length;
        length = VAppend(va);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: VAppend
    //
    //   Author: $author$
    //     Date: 5/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength VAppend(va_list va) 
    {
        TLength length = 0;
        TLength count;
        TOf of;
        while (0 != (of = va_arg(va, TOf)))
        {
            if (0 > (count = Append(&of, 1)))
                return count;
            length += count;
        }
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Assign
    //
    //   Author: $author$
    //     Date: 5/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Assign
    (const TOf* buffer, TLength length=-1) 
    {
        TLength count;
        if (0 > (count = Clear()))
            return count;
        length = Append(buffer, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Append
    //
    //   Author: $author$
    //     Date: 5/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Append
    (const TOf* buffer, TLength length=-1) 
    {
        TLength oldLength = Length();
        if (0 > length)
            this->append(buffer);
        else this->append(buffer, length);
        length = Length();
        return length-oldLength;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Clear
    //
    //   Author: $author$
    //     Date: 7/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Clear() 
    {
        TLength length = Length();
        (*this).clear();
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Buffer
    //
    //   Author: $author$
    //     Date: 5/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const TOf* Buffer(TLength &length) const
    {
        const TOf* buffer = (*this).c_str();
        length = (TLength)((*this).length());
        return buffer;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Length
    //
    //   Author: $author$
    //     Date: 5/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Length() const 
    {
        return (TLength)((*this).length());
    }

#if defined(EV_NO_STD_STRING_CLEAR) 
    ///////////////////////////////////////////////////////////////////////
    // Function: clear
    //
    //   Author: $author$
    //     Date: 6/7/2007
    ///////////////////////////////////////////////////////////////////////
    void clear()
    {
        assign("");
    }
#endif // defined(EV_NO_STD_STRING_CLEAR)
};
#endif // _CEVBUFFER_HPP
