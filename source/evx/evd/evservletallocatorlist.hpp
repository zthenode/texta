///////////////////////////////////////////////////////////////////////
//   File: evservletallocatorlist.hpp
//
// Author: $author$
//   Date: 7/25/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVSERVLETALLOCATORLIST_HPP
#define _EVSERVLETALLOCATORLIST_HPP

#include "evservletallocator.hpp"
#include "evbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvServletAllocatorItem
//
// Author: $author$
//   Date: 7/25/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvServletAllocatorItem
: virtual public EvBase
{
public:
    typedef EvBase CImplements;
    typedef EvServletAllocatorItem CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetAllocator
    //
    //   Author: $author$
    //     Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvServletAllocator& GetAllocator() const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetNextItem
    //
    //   Author: $author$
    //     Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvServletAllocatorItem* GetNextItem() const = 0;
};

///////////////////////////////////////////////////////////////////////
//  Class: EvServletAllocatorList
//
// Author: $author$
//   Date: 7/25/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvServletAllocatorList
: virtual public EvBase
{
public:
    typedef EvBase CImplements;
    typedef EvServletAllocatorList CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFirstAllocator
    //
    //   Author: $author$
    //     Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvServletAllocator* GetFirstAllocator
    (EvServletAllocatorItem& item) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetNextAllocator
    //
    //   Author: $author$
    //     Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvServletAllocator* GetNextAllocator
    (EvServletAllocatorItem& item) const = 0;
};
#endif // _EVSERVLETALLOCATORLIST_HPP
