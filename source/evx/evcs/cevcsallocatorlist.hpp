///////////////////////////////////////////////////////////////////////
//   File: evcsallocatorlist.hpp
//
// Author: $author$
//   Date: 5/28/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCSALLOCATORLIST_HPP
#define _CEVCSALLOCATORLIST_HPP

#include "evcsallocator.hpp"
#include "cevlist.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsAllocatorItem
//
// Author: $author$
//   Date: 5/28/2007
///////////////////////////////////////////////////////////////////////
class CEvcsAllocatorItem
: public CEvListItem<CEvcsAllocatorItem>
{
public:
    typedef CEvListItem<CEvcsAllocatorItem> CExtends;
    typedef CEvcsAllocatorItem CDerives;

    EvcsAllocator& m_allocator;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsAllocatorItem
    //
    //       Author: $author$
    //         Date: 5/28/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsAllocatorItem(EvcsAllocator& allocator);
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsAllocatorItem
    //
    //      Author: $author$
    //        Date: 5/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsAllocatorItem();
    ///////////////////////////////////////////////////////////////////////
    // Function: GetAllocator
    //
    //   Author: $author$
    //     Date: 5/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsAllocator& GetAllocator() const 
    {
        return m_allocator;
    }
};
///////////////////////////////////////////////////////////////////////
//  Class: CEvcsAllocatorList
//
// Author: $author$
//   Date: 5/28/2007
///////////////////////////////////////////////////////////////////////
class CEvcsAllocatorList
: public CEvStaticList<CEvcsAllocatorItem, CEvcsAllocatorList>
{
public:
    typedef CEvStaticList<CEvcsAllocatorItem, CEvcsAllocatorList> CExtends;
    typedef CEvcsAllocatorList CDerives;

    static CEvcsAllocatorList m_list;
    
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFirstItem
    //
    //   Author: $author$
    //     Date: 5/28/2007
    ///////////////////////////////////////////////////////////////////////
    static CEvcsAllocatorItem* xGetFirstItem()
    {
        return m_list.GetFirstItem();
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetLastItem
    //
    //   Author: $author$
    //     Date: 5/28/2007
    ///////////////////////////////////////////////////////////////////////
    static CEvcsAllocatorItem* xGetLastItem()
    {
        return m_list.GetLastItem();
    }
};
#endif // _CEVCSALLOCATORLIST_HPP
