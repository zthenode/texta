///////////////////////////////////////////////////////////////////////
//   File: evcpservletallocatorlist.hpp
//
// Author: $author$
//   Date: 7/25/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCPSERVLETALLOCATORLIST_HPP
#define _EVCPSERVLETALLOCATORLIST_HPP

#include "evcpservletallocator.hpp"
#include "evbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvcpServletAllocatorItem
//
// Author: $author$
//   Date: 7/25/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvcpServletAllocatorItem
: virtual public EvBase
{
public:
    typedef EvBase CImplements;
    typedef EvcpServletAllocatorItem CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetAllocator
    //
    //   Author: $author$
    //     Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServletAllocator& GetAllocator() const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetNextItem
    //
    //   Author: $author$
    //     Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServletAllocatorItem* GetNextItem() const = 0;
};

///////////////////////////////////////////////////////////////////////
//  Class: EvcpServletAllocatorList
//
// Author: $author$
//   Date: 7/25/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvcpServletAllocatorList
: virtual public EvBase
{
public:
    typedef EvBase CImplements;
    typedef EvcpServletAllocatorList CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFirstAllocator
    //
    //   Author: $author$
    //     Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServletAllocator* GetFirstAllocator
    (EvcpServletAllocatorItem*& item) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetNextAllocator
    //
    //   Author: $author$
    //     Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServletAllocator* GetNextAllocator
    (EvcpServletAllocatorItem*& item) const = 0;
};
#endif // _EVCPSERVLETALLOCATORLIST_HPP
