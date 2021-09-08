///////////////////////////////////////////////////////////////////////
//   File: evfiletime.hpp
//
// Author: $author$
//   Date: 6/13/2007
///////////////////////////////////////////////////////////////////////

#ifndef _EVFILETIME_HPP
#define _EVFILETIME_HPP

#include <vector>
#include "ev.hpp"
#include "evdatetime.hpp"
#include "evinstance.hpp"
#include "evbase.hpp"

#define EV_TIME_TYPE_NAME_NONE "None"
#define EV_TIME_TYPE_NAME_MODIFIED "Modified"
#define EV_TIME_TYPE_NAME_CREATED "Created"
#define EV_TIME_TYPE_NAME_ACCESSED "Accessed"
#define EV_TIME_TYPE_NAME_CHANGED "Changed"

///////////////////////////////////////////////////////////////////////
//  Class: EvFileTime
//
// Author: $author$
//   Date: 6/13/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvFileTime
: virtual public EvDateTime,
  virtual public EvInstance
{
public:
    typedef EvDateTime CDateTimeImplements;
    typedef EvInstance CImplements;
    typedef EvFileTime CDerives;

    typedef int EvType;

    ///////////////////////////////////////////////////////////////////////
    //   Enum:  
    //
    // Author: $author$
    //   Date: 6/13/2007
    ///////////////////////////////////////////////////////////////////////
    enum 
    {
        EV_TIME_NONE = 0,

        EV_TIME_MODIFIED = 1,
        EV_TIME_CREATED = 2,
        EV_TIME_ACCESSED = 4,
        EV_TIME_CHANGED = 8,

        EV_NEXT_TIME,
        EV_ANY_TIME = ((EV_NEXT_TIME-1) << 1) - 1
    };

    ///////////////////////////////////////////////////////////////////////
    //   Enum:  
    //
    // Author: $author$
    //   Date: 6/21/2007
    ///////////////////////////////////////////////////////////////////////
    enum 
    {
        EV_FIRST_TIME_TYPE,

        EV_TIME_TYPE_MODIFIED = EV_FIRST_TIME_TYPE,
        EV_TIME_TYPE_CREATED,
        EV_TIME_TYPE_ACCESSED,
        EV_TIME_TYPE_CHANGED,

        EV_NEXT_TIME_TYPE,
        EV_LAST_TIME_TYPE = EV_NEXT_TIME_TYPE-1,

        EV_TIME_TYPES = EV_NEXT_TIME_TYPE
    };

    static const char* m_typeName[EV_TIME_TYPES];

    ///////////////////////////////////////////////////////////////////////
    // Function: GetTypeName
    //
    //   Author: $author$
    //     Date: 6/21/2007
    ///////////////////////////////////////////////////////////////////////
    static const char* 
    GetTypeName(EvType type) 
    {
        const char* chars = EV_TIME_TYPE_NAME_NONE;
        UINT order;

        if ((EV_FIRST_TIME_TYPE <= (order = Ev::Order(type))) 
            && (EV_LAST_TIME_TYPE >= order))
            chars = m_typeName[order];
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetType
    //
    //   Author: $author$
    //     Date: 6/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetType(EvType type) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetType
    //
    //   Author: $author$
    //     Date: 6/13/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvType GetType() const = 0;

    ///////////////////////////////////////////////////////////////////////
    // Function: CreateInstance
    //
    //   Author: $author$
    //     Date: 5/14/2008
    ///////////////////////////////////////////////////////////////////////
    static EvFileTime* CreateInstance
    (EvError& error);
    ///////////////////////////////////////////////////////////////////////
    // Function: DestroyInstance
    //
    //   Author: $author$
    //     Date: 5/14/2008
    ///////////////////////////////////////////////////////////////////////
    static EvError DestroyInstance
    (EvFileTime& instance);
};

#endif // _EVFILETIME_HPP
