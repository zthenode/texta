///////////////////////////////////////////////////////////////////////
//   File: cevlist.hpp
//
// Author: $author$
//   Date: 4/4/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVLIST_HPP
#define _CEVLIST_HPP

#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvListItem
//
// Author: $author$
//   Date: 4/4/2007
///////////////////////////////////////////////////////////////////////
template
<class TDerives,
 class TExtends=CEvBase>

class CEvListItem
: public TExtends
{
public:
    typedef TExtends CExtends;
    typedef CEvListItem CDerives;

    TDerives *m_prevItem, *m_nextItem;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvListItem
    //
    //       Author: $author$
    //         Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvListItem
    (TDerives *prevItem=0, TDerives *nextItem=0) 
    : m_prevItem(prevItem),
      m_nextItem(nextItem) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetPrevItem
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    TDerives* GetPrevItem() const 
    {
        return m_prevItem;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetNextItem
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    TDerives* GetNextItem() const 
    {
        return m_nextItem;
    }
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvList
//
// Author: $author$
//   Date: 4/4/2007
///////////////////////////////////////////////////////////////////////
template
<class TItem,
 class TDerives,
 class TExtends=CEvBase>

class CEvList
: public TExtends
{
public:
    typedef TExtends CExtends;
    typedef CEvList CDerives;

	TItem *m_firstItem, *m_lastItem;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvList
    //
    //       Author: $author$
    //         Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvList(TItem* firstItem=0, TItem* lastItem=0)
    : m_firstItem(firstItem),
      m_lastItem(lastItem) 
    {
    }
#undef CEVLIST_MEMBER
#undef CEVLIST_MEMBER_const
#define CEVLIST_MEMBER
#define CEVLIST_MEMBER_const const
#include "cevlist_members.hpp"
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvStaticList
//
// Author: $author$
//   Date: 4/4/2007
///////////////////////////////////////////////////////////////////////
template
<class TItem,
 class TDerives,
 class TExtends=CEvBase>

class CEvStaticList
: public TExtends
{
public:
    typedef TExtends CExtends;
    typedef CEvStaticList CDerives;

	static TItem *m_firstItem, *m_lastItem;

#undef CEVLIST_MEMBER
#undef CEVLIST_MEMBER_const
#define CEVLIST_MEMBER static
#define CEVLIST_MEMBER_const
#include "cevlist_members.hpp"
};
#endif // _CEVLIST_HPP
