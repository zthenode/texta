///////////////////////////////////////////////////////////////////////
//   File: cevcpservletallocator.hpp
//
// Author: $author$
//   Date: 4/22/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCPSERVLETALLOCATOR_HPP
#define _CEVCPSERVLETALLOCATOR_HPP

#include "evcpservletallocator.hpp"
#include "cevservletallocator.hpp"
#include "cevlist.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpServletAllocatorItem
//
// Author: $author$
//   Date: 4/22/2007
///////////////////////////////////////////////////////////////////////
class CEvcpServletAllocatorItem
: public CEvListItem<CEvcpServletAllocatorItem>
{
public:
    typedef CEvListItem<CEvcpServletAllocatorItem> CExtends;
    typedef CEvcpServletAllocatorItem CDerives;

    EvcpServletAllocator& m_allocator;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpServletAllocatorItem
    //
    //       Author: $author$
    //         Date: 4/22/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpServletAllocatorItem(EvcpServletAllocator& allocator)
    : m_allocator(allocator)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetAllocator
    //
    //   Author: $author$
    //     Date: 4/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcpServletAllocator& GetAllocator() const 
    {
        return m_allocator;
    }
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpServletAllocatorList
//
// Author: $author$
//   Date: 4/22/2007
///////////////////////////////////////////////////////////////////////
class CEvcpServletAllocatorList
: public CEvStaticList
  <CEvcpServletAllocatorItem, CEvcpServletAllocatorList>
{
public:
    typedef CEvStaticList
    <CEvcpServletAllocatorItem, CEvcpServletAllocatorList> CExtends;
    typedef CEvcpServletAllocatorList CDerives;
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpServletAllocatorFamilyT
//
// Author: $author$
//   Date: 4/22/2007
///////////////////////////////////////////////////////////////////////
template
<class TList,
 class TItem=CEvcpServletAllocatorItem,
 class TImplements=EvcpServletAllocator,
 class TExtends=CEvServletAllocator>

class CEvcpServletAllocatorFamilyT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;

    TItem m_item;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcpServletAllocatorFamilyT
    //
    //       Author: $author$
    //         Date: 4/22/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcpServletAllocatorFamilyT() 
    : m_item(*this)
    {
        TList::AddItem(m_item);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcpServletAllocatorFamilyT
    //
    //      Author: $author$
    //        Date: 4/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcpServletAllocatorFamilyT()
    {
        TList::DeleteItem(m_item);
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvcpServletAllocatorFamily
//
//   Author: $author$
//     Date: 4/25/2007
///////////////////////////////////////////////////////////////////////
typedef CEvcpServletAllocatorFamilyT
<CEvcpServletAllocatorList, 
 CEvcpServletAllocatorItem>
CEvcpServletAllocatorFamily;

///////////////////////////////////////////////////////////////////////
//  Class: CEvcpServletAllocatorT
//
// Author: $author$
//   Date: 4/25/2007
///////////////////////////////////////////////////////////////////////
template
<class TServlet,
 class TServletImplements=EvcpServlet,
 class TAllocatorFamily=CEvcpServletAllocatorFamily>

class CEvcpServletAllocatorT
: public TAllocatorFamily
{
public:
    typedef TAllocatorFamily CExtends;
    typedef CEvcpServletAllocatorT CDerives;

    static CDerives m_allocator;

    ///////////////////////////////////////////////////////////////////////
    // Function: AcquireServlet
    //
    //   Author: $author$
    //     Date: 4/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual TServletImplements* 
    AcquireServlet(EvError& error) 
    {
        TServletImplements* servlet = 0;

        if ((servlet = new TServlet()))
        if ((error = AddServlet(*servlet)))
        {
            delete servlet;
            servlet = 0;
        }
        return servlet;
    }
};

#endif // _CEVCPSERVLETALLOCATOR_HPP
