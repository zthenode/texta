///////////////////////////////////////////////////////////////////////
//   File: cevcpslist.hpp
//
// Author: $author$
//   Date: 11/29/2007
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSLIST_HPP
#define _CEVCPSLIST_HPP

#include <stdarg.h>
#include "cevcpsbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpsList
//
// Author: $author$
//   Date: 11/29/2007
///////////////////////////////////////////////////////////////////////
class CEvcpsList
: public CEvcpsBase
{
public:
    typedef CEvcpsBase CExtends;
    typedef CEvcpsList CDerives;

    CEvcpsBases m_values;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsList
    //
    //       Author: $author$
    //         Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsList() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpsList
    //
    //       Author: $author$
    //         Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpsList(CEvcpsBase* value,...) 
    {
        va_list va;
        va_start(va, value);
        VAppend(value,va);
        va_end(va);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpsList
    //
    //      Author: $author$
    //        Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpsList()
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
    (CEvcpsBase* value, va_list va) 
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
    (CEvcpsBase* value, va_list va) 
    {
        do m_values.push_back(value);
        while (0 != (value = va_arg(va, CEvcpsBase*)));
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Append
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual void Append
    (CEvcpsBase* value) 
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
    // Function: Write
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (EvCharWriter& writer) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count1 = 0;
        LONG count2;
        const_CEvcpsBasesIterator i;
        for (i = m_values.begin(); i != m_values.end(); i++)
        {
            CEvcpsBase* value;
            if ((value = *i))
            if (0 > (count2 = value->Write(writer)))
                return length;
            else count1 += count2;
        }
        return count1;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (EvCharReader& reader) 
    {
        LONG length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Sizeof
    //
    //   Author: $author$
    //     Date: 11/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual USHORT Sizeof() const 
    {
        USHORT size = 0;
        const_CEvcpsBasesIterator i;
        for (i = m_values.begin(); i != m_values.end(); i++)
        {
            CEvcpsBase* value;
            if ((value = *i))
                size += value->Sizeof();
        }
        return size;
    }
};

#endif // _CEVCPSLIST_HPP
