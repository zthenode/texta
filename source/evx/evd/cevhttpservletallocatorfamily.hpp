///////////////////////////////////////////////////////////////////////
//   File: cevhttpservletallocatorfamily.hpp
//
// Author: $author$
//   Date: 4/27/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVHTTPSERVLETALLOCATORFAMILY_HPP
#define _CEVHTTPSERVLETALLOCATORFAMILY_HPP

#include "cevcpservletallocator.hpp"
#include "evcpservletallocatorlist.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvHttpServletAllocatorItem
//
// Author: $author$
//   Date: 4/27/2007
///////////////////////////////////////////////////////////////////////
class CEvHttpServletAllocatorItem
: virtual public EvcpServletAllocatorItem,
  public CEvListItem<CEvHttpServletAllocatorItem>
{
public:
    typedef EvcpServletAllocatorItem CImplements;
    typedef CEvListItem<CEvHttpServletAllocatorItem> CExtends;
    typedef CEvHttpServletAllocatorItem CDerives;

    EvcpServletAllocator& m_allocator;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvHttpServletAllocatorItem
    //
    //       Author: $author$
    //         Date: 4/27/2007
    ///////////////////////////////////////////////////////////////////////
    CEvHttpServletAllocatorItem(EvcpServletAllocator& allocator)
    : m_allocator(allocator)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetAllocator
    //
    //   Author: $author$
    //     Date: 4/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServletAllocator& GetAllocator() const 
    {
        return m_allocator;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetNextItem
    //
    //   Author: $author$
    //     Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServletAllocatorItem* GetNextItem() const 
    {
        EvcpServletAllocatorItem* item = CExtends::GetNextItem();
        return item;
    }
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvHttpServletAllocatorList
//
// Author: $author$
//   Date: 4/27/2007
///////////////////////////////////////////////////////////////////////
class CEvHttpServletAllocatorList
: virtual public EvcpServletAllocatorList,
  public CEvStaticList
  <CEvHttpServletAllocatorItem, 
   CEvHttpServletAllocatorList>
{
public:
    typedef EvcpServletAllocatorList CImplements;
    typedef CEvStaticList
    <CEvHttpServletAllocatorItem, 
     CEvHttpServletAllocatorList> CExtends;
    typedef CEvHttpServletAllocatorList CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: GetInstance
    //
    //   Author: $author$
    //     Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    static CEvHttpServletAllocatorList& GetInstance();

    ///////////////////////////////////////////////////////////////////////
    // Function: GetFirstAllocator
    //
    //   Author: $author$
    //     Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServletAllocator* GetFirstAllocator
    (EvcpServletAllocatorItem*& item) const
    {
        EvcpServletAllocator* allocator = 0;
        if ((item = GetFirstItem()))
            allocator = &item->GetAllocator();
        return allocator;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetNextAllocator
    //
    //   Author: $author$
    //     Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServletAllocator* GetNextAllocator
    (EvcpServletAllocatorItem*& item) const
    {
        EvcpServletAllocator* allocator = 0;
        if (item)
        if ((item = item->GetNextItem()))
            allocator = &item->GetAllocator();
        return allocator;
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvHttpServletAllocatorFamily
//
//   Author: $author$
//     Date: 4/27/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorFamilyT
<CEvHttpServletAllocatorList, 
 CEvHttpServletAllocatorItem>
CEvHttpServletAllocatorFamily;

#endif // _CEVHTTPSERVLETALLOCATORFAMILY_HPP
