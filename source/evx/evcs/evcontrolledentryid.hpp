///////////////////////////////////////////////////////////////////////
//   File: evcontrolledentryid.hpp
//
// Author: $author$
//   Date: 3/11/2008
///////////////////////////////////////////////////////////////////////
#ifndef _EVCONTROLLEDENTRYID_HPP
#define _EVCONTROLLEDENTRYID_HPP

#include "evuuid.hpp"
#include "evbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvControlledEntryID
//
// Author: $author$
//   Date: 3/11/2008
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvControlledEntryID
: virtual public EvUUID
{
public:
    typedef EvUUID CImplements;
    typedef EvControlledEntryID CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: Compare
    //
    //   Author: $author$
    //     Date: 3/12/2008
    ///////////////////////////////////////////////////////////////////////
    virtual int Compare
    (const EvControlledEntryID& to) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteInstance
    //
    //   Author: $author$
    //     Date: 3/11/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteInstance() = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: CreateInstance
    //
    //   Author: $author$
    //     Date: 3/11/2008
    ///////////////////////////////////////////////////////////////////////
    static EvControlledEntryID* 
    CreateInstance(EvError& error);
    ///////////////////////////////////////////////////////////////////////
    // Function: DestroyInstance
    //
    //   Author: $author$
    //     Date: 3/11/2008
    ///////////////////////////////////////////////////////////////////////
    static EvError DestroyInstance
    (EvControlledEntryID& instance);
};
#endif // _EVCONTROLLEDENTRYID_HPP 
