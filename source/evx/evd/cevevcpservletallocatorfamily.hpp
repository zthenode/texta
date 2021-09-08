///////////////////////////////////////////////////////////////////////
//   File: cevevcpservletallocatorfamily.hpp
//
// Author: $author$
//   Date: 4/26/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVEVCPSERVLETALLOCATORFAMILY_HPP
#define _CEVEVCPSERVLETALLOCATORFAMILY_HPP

#include "cevcpservletallocator.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcpServletAllocatorItem
//
// Author: $author$
//   Date: 4/26/2007
///////////////////////////////////////////////////////////////////////
class CEvEvcpServletAllocatorItem
: public CEvListItem<CEvEvcpServletAllocatorItem>
{
public:
    typedef CEvListItem<CEvEvcpServletAllocatorItem> CExtends;
    typedef CEvEvcpServletAllocatorItem CDerives;

    EvcpServletAllocator& m_allocator;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvcpServletAllocatorItem
    //
    //       Author: $author$
    //         Date: 4/26/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvcpServletAllocatorItem(EvcpServletAllocator& allocator)
    : m_allocator(allocator)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetAllocator
    //
    //   Author: $author$
    //     Date: 4/26/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServletAllocator& GetAllocator() const 
    {
        return m_allocator;
    }
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcpServletAllocatorList
//
// Author: $author$
//   Date: 4/22/2007
///////////////////////////////////////////////////////////////////////
class CEvEvcpServletAllocatorList
: public CEvStaticList
  <CEvEvcpServletAllocatorItem, CEvEvcpServletAllocatorList>
{
public:
    typedef CEvStaticList
    <CEvEvcpServletAllocatorItem, CEvEvcpServletAllocatorList> CExtends;
    typedef CEvEvcpServletAllocatorList CDerives;
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvEvcpServletAllocatorFamily
//
//   Author: $author$
//     Date: 4/26/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorFamilyT
<CEvEvcpServletAllocatorList, 
 CEvEvcpServletAllocatorItem>
CEvEvcpServletAllocatorFamily;

#endif // _CEVEVCPSERVLETALLOCATORFAMILY_HPP
