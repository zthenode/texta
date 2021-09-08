///////////////////////////////////////////////////////////////////////
//   File: cevcpshandshakeplaintextlist.hpp
//
// Author: $author$
//   Date: 12/14/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSHANDSHAKEPLAINTEXTLIST_HPP
#define _CEVCPSHANDSHAKEPLAINTEXTLIST_HPP

#include <stdarg.h>
#include "cevcpshandshakeplaintext.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsHandshakePlaintextList
//
// Author: $author$
//   Date: 12/14/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsHandshakePlaintextList
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsHandshakePlaintextList CDerives;

    typedef CEvcpsHandshakePlaintext CPlaintext;
    typedef CEvcpsHandshakePlaintexts CPlaintexts;
    typedef CEvcpsHandshakePlaintextsIterator CPlaintextsIterator;

    CEvcpsHandshakePlaintexts m_values;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsHandshakePlaintextList
    //
    //       Author: $author$
    //         Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsHandshakePlaintextList() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsHandshakePlaintextList
    //
    //       Author: $author$
    //         Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsHandshakePlaintextList(CEvcpsHandshakePlaintext* value,...) 
    {
        va_list va;
        va_start(va, value);
        VAppend(value,va);
        va_end(va);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpsHandshakePlaintextList
    //
    //      Author: $author$
    //        Date: 12/14/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpsHandshakePlaintextList()
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
    (CEvcpsHandshakePlaintext* value, va_list va) 
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
    (CEvcpsHandshakePlaintext* value, va_list va) 
    {
        do m_values.push_back(value);
        while (0 != (value = va_arg(va, CEvcpsHandshakePlaintext*)));
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Append
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void Append
    (CEvcpsHandshakePlaintext* value) 
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
        const_CEvcpsHandshakePlaintextsIterator i;
        for (i = m_values.begin(); i != m_values.end(); i++)
        {
            CEvcpsHandshakePlaintext* value;
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
        const_CEvcpsHandshakePlaintextsIterator i;
        for (i = m_values.begin(); i != m_values.end(); i++)
        {
            CEvcpsHandshakePlaintext* value;
            if ((value = *i))
                size += value->Sizeof();
        }
        return size;
    }
};

#endif // _CEVCPSHANDSHAKEPLAINTEXTLIST_HPP
