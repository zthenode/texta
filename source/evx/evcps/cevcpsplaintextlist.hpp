///////////////////////////////////////////////////////////////////////
//   File: cevcpsplaintextlist.hpp
//
// Author: $author$
//   Date: 12/15/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSPLAINTEXTLIST_HPP
#define _CEVCPSPLAINTEXTLIST_HPP

#include <stdarg.h>
#include "cevcpsplaintext.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsPlaintextList
//
// Author: $author$
//   Date: 12/14/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsPlaintextList
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsPlaintextList CDerives;

    typedef CEvcpsPlaintext CPlaintext;
    typedef CEvcpsPlaintexts CPlaintexts;
    typedef CEvcpsPlaintextsIterator CPlaintextsIterator;

    CEvcpsPlaintexts m_values;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsPlaintextList
    //
    //       Author: $author$
    //         Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsPlaintextList() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsPlaintextList
    //
    //       Author: $author$
    //         Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsPlaintextList(CEvcpsPlaintext* value,...) 
    {
        va_list va;
        va_start(va, value);
        VAppend(value,va);
        va_end(va);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpsPlaintextList
    //
    //      Author: $author$
    //        Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpsPlaintextList()
    {
        m_values.clear();
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: VAssign
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void VAssign
    (CEvcpsPlaintext* value, va_list va) 
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
    (CEvcpsPlaintext* value, va_list va) 
    {
        do m_values.push_back(value);
        while (0 != (value = va_arg(va, CEvcpsPlaintext*)));
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Append
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void Append
    (CEvcpsPlaintext* value) 
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
    //     Date: 12/14/2007
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
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1 = 0;
        LONG count2;
        const_CEvcpsPlaintextsIterator i;
        for (i = m_values.begin(); i != m_values.end(); i++)
        {
            CEvcpsPlaintext* value;
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
    //     Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = 0;
        const_CEvcpsPlaintextsIterator i;
        for (i = m_values.begin(); i != m_values.end(); i++)
        {
            CEvcpsPlaintext* value;
            if ((value = *i))
                size += value->Sizeof();
        }
        return size;
    }
};

#endif // _CEVCPSPLAINTEXTLIST_HPP
