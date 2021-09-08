///////////////////////////////////////////////////////////////////////
//   File: cevhttppathservletallocatorfamily.hpp
//
// Author: $author$
//   Date: 6/12/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVHTTPPATHSERVLETALLOCATORFAMILY_HPP
#define _CEVHTTPPATHSERVLETALLOCATORFAMILY_HPP

#include "cevcpservletallocator.hpp"
#include "evcpservletallocatorlist.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvHttpPathServletAllocatorItem
//
// Author: $author$
//   Date: 6/12/2007
///////////////////////////////////////////////////////////////////////
class CEvHttpPathServletAllocatorItem
: virtual public EvcpServletAllocatorItem,
  public CEvListItem<CEvHttpPathServletAllocatorItem>
{
public:
    typedef EvcpServletAllocatorItem CImplements;
    typedef CEvListItem<CEvHttpPathServletAllocatorItem> CExtends;
    typedef CEvHttpPathServletAllocatorItem CDerives;

    EvcpServletAllocator& m_allocator;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvHttpPathServletAllocatorItem
    //
    //       Author: $author$
    //         Date: 6/12/2007
    ///////////////////////////////////////////////////////////////////////
    CEvHttpPathServletAllocatorItem
    (EvcpServletAllocator& allocator)
    : m_allocator(allocator)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetAllocator
    //
    //   Author: $author$
    //     Date: 6/12/2007
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
//  Class: CEvHttpPathServletAllocatorList
//
// Author: $author$
//   Date: 6/12/2007
///////////////////////////////////////////////////////////////////////
class CEvHttpPathServletAllocatorList
: virtual public EvcpServletAllocatorList,
  public CEvStaticList
  <CEvHttpPathServletAllocatorItem, 
   CEvHttpPathServletAllocatorList>
{
public:
    typedef CEvStaticList
    <CEvHttpPathServletAllocatorItem, 
     CEvHttpPathServletAllocatorList> CExtends;
    typedef CEvHttpPathServletAllocatorList CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: GetInstance
    //
    //   Author: $author$
    //     Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    static CEvHttpPathServletAllocatorList& GetInstance();

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
//  Typedef: CEvHttpPathServletAllocatorFamily
//
//   Author: $author$
//     Date: 6/12/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorFamilyT
<CEvHttpPathServletAllocatorList, 
 CEvHttpPathServletAllocatorItem>
CEvHttpPathServletAllocatorFamily;

#endif // _CEVHTTPPATHSERVLETALLOCATORFAMILY_HPP
