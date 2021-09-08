///////////////////////////////////////////////////////////////////////
//   File: cevcpshandshakelist.hpp
//
// Author: $author$
//   Date: 12/27/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSHANDSHAKELIST_HPP
#define _CEVCPSHANDSHAKELIST_HPP

#include <stdarg.h>
#include "cevcpsbase.hpp"
#include "cevcpshandshakebases.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsHandshakeList
//
// Author: $author$
//   Date: 12/27/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsHandshakeList
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsHandshakeList CDerives;

    CEvcpsHandshakeBases m_values;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsHandshakeList
    //
    //       Author: $author$
    //         Date: 12/27/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsHandshakeList() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsHandshakeList
    //
    //       Author: $author$
    //         Date: 12/27/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsHandshakeList(CEvcpsHandshakeBase* value,...) 
    {
        va_list va;
        va_start(va, value);
        VAppend(value,va);
        va_end(va);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: VAssign
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void VAssign
    (CEvcpsHandshakeBase* value, va_list va) 
    {
        Clear();
        VAppend(value, va);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: VAppend
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void VAppend
    (CEvcpsHandshakeBase* value, va_list va) 
    {
        do m_values.push_back(value);
        while (0 != (value = va_arg(va, CEvcpsHandshakeBase*)));
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Append
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void Append
    (CEvcpsHandshakeBase* value) 
    {
        m_values.push_back(value);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Clear
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void Clear() 
    {
        m_values.clear();
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 12/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1 = 0;
        LONG count2;
        const_CEvcpsHandshakeBasesIterator i;
        for (i = m_values.begin(); i != m_values.end(); i++)
        {
            CEvcpsHandshakeBase* value;
            if ((value = *i))
            if (0 > (count2 = value->Write(writer)))
                return length;
            else count1 += count2;
        }
        return count1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 12/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = 0;
        const_CEvcpsHandshakeBasesIterator i;
        for (i = m_values.begin(); i != m_values.end(); i++)
        {
            CEvcpsHandshakeBase* value;
            if ((value = *i))
                size += value->Sizeof();
        }
        return size;
    }
};

#endif // _CEVCPSHANDSHAKELIST_HPP
