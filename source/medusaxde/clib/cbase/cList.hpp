///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2011 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cList.hpp
//
// Author: $author$
//   Date: 6/5/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CLIST_HPP) || defined(CLISTT_MEMBERS_ONLY)
#if !defined(_CLIST_HPP) && !defined(CLISTT_MEMBERS_ONLY)
#define _CLIST_HPP
#endif // !defined(_CLIST_HPP) && !defined(CLISTT_MEMBERS_ONLY) 

#if !defined(CLISTT_MEMBERS_ONLY)
#include "cListItem.hpp"
#include "cImplementBase.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "cListT"
///////////////////////////////////////////////////////////////////////
//  Class: cListT
//
// Author: $author$
//   Date: 6/5/2011
///////////////////////////////////////////////////////////////////////
template
<class TDerive,
 class TItem,
 class TImplement=cImplementBase,
 class TExtend=cInstanceBase>

class c_INSTANCE_CLASS cListT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement cImplements;
    typedef TExtend cExtends;
    typedef TDerive tDerive;
    typedef TItem tItem;

    tItem* m_firstItem;
    tItem* m_lastItem;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cListT
    //
    //       Author: $author$
    //         Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    cListT
    (tItem* firstItem=0,
     tItem* lastItem=0)
    : m_firstItem(firstItem), 
      m_lastItem(lastItem)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cListT
    //
    //      Author: $author$
    //        Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cListT()
    {
    }
#else // !defined(CLISTT_MEMBERS_ONLY) 
#endif // !defined(CLISTT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: PushItem
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* PushItem
    (tItem* item)
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
        if (!item) return item;

		if ((item->m_nextItem = m_firstItem))
			m_firstItem->m_prevItem = item;
		else m_lastItem = item;

		m_firstItem = item;
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return item;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: PopItem
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* PopItem()
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
        tItem* item = 0;
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
		if ((item = m_firstItem))
		{
			TItem* nextItem;

			if ((nextItem = item->m_nextItem))
				nextItem->m_prevItem = 0;
			else m_lastItem = 0;

			m_firstItem = nextItem;
			item->m_nextItem = 0;
			item->m_prevItem = 0;
		}
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return item;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: AppendItem
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* AppendItem
    (tItem* item)
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
        item = AddItem(item);
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return item;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: AddItem
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* AddItem
    (tItem* item)
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
        if (!item) return item;

		if ((item->m_prevItem = m_lastItem))
			m_lastItem->m_nextItem = item;
		else m_firstItem = item;

		m_lastItem = item;
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return item;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: RemoveItem
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* RemoveItem()
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
        tItem* item = PullItem();
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return item;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: PullItem
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* PullItem()
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
        tItem* item = 0;
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
		if ((item = m_lastItem))
		{
			TItem* prevItem;

			if ((prevItem = item->m_prevItem))
				prevItem->m_nextItem = 0;
			else m_firstItem = 0;

			m_lastItem = prevItem;
			item->m_nextItem = 0;
			item->m_prevItem = 0;
		}
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return item;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: InsertBeforeItem
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* InsertBeforeItem
    (tItem* otherItem,
     tItem* item)
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
        if (!item || !otherItem) return item;

        if ((item->m_prevItem = otherItem->m_prevItem))
            otherItem->m_prevItem->m_nextItem = item;
        else m_firstItem = item;

        item->m_nextItem = otherItem;
        otherItem->m_prevItem = item;
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return item;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: InsertAfterItem
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* InsertAfterItem
    (tItem* otherItem,
     tItem* item)
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
        if (!item || !otherItem) return item;

        if ((item->m_nextItem = otherItem->m_nextItem))
            otherItem->m_nextItem->m_prevItem = item;
        else m_lastItem = item;

        item->m_prevItem = otherItem;
        otherItem->m_nextItem = item;
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return item;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: DeleteItem
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* DeleteItem
    (tItem* item)
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
        if (!item) return item;

		if (item->m_nextItem)
			item->m_nextItem->m_prevItem = item->m_prevItem;
		else m_lastItem = item->m_prevItem;

		if (item->m_prevItem)
			item->m_prevItem->m_nextItem = item->m_nextItem;
		else m_firstItem = item->m_nextItem;

		item->m_nextItem = 0;
		item->m_prevItem = 0;
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return item;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: PushItems
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* PushItems
    (tItem* firstItem,
     tItem* lastItem)
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
        if (!firstItem || !lastItem)
            return 0;

		firstItem->m_prevItem = 0;

		if ((lastItem->m_nextItem = m_firstItem) != 0)
			m_firstItem->m_prevItem = lastItem;
		else m_lastItem = lastItem;

		m_firstItem = firstItem;
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return firstItem;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: AppendItems
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* AppendItems
    (tItem* firstItem,
     tItem* lastItem)
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
        firstItem = AddItems(firstItem, lastItem);
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return firstItem;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: AddItems
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* AddItems
    (tItem* firstItem,
     tItem* lastItem)
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
        if (!firstItem || !lastItem)
            return 0;

		lastItem->m_nextItem = 0;

		if ((firstItem->m_prevItem = m_lastItem) != 0)
			m_lastItem->m_nextItem = firstItem;
		else m_firstItem = firstItem;

		m_lastItem = lastItem;
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return firstItem;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: InsertItemsBefore
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* InsertItemsBefore
    (tItem* otherItem,
     tItem* firstItem,
     tItem* lastItem)
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
        if (!otherItem || !firstItem || !lastItem)
            return 0;

        if ((firstItem->m_prevItem = otherItem->m_prevItem) != 0)
            otherItem->m_prevItem->m_nextItem = firstItem;
        else m_firstItem = firstItem;

        lastItem->m_nextItem = otherItem;
        otherItem->m_prevItem = lastItem;
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return firstItem;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: InsertItemsAfter
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* InsertItemsAfter
    (tItem* otherItem,
     tItem* firstItem,
     tItem* lastItem)
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
        if (!otherItem || !firstItem || !lastItem)
            return 0;

        if ((lastItem->m_nextItem = otherItem->m_nextItem) != 0)
            otherItem->m_nextItem->m_prevItem = lastItem;
        else m_lastItem = lastItem;

        firstItem->m_prevItem = otherItem;
        otherItem->m_nextItem = firstItem;
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return firstItem;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: DeleteItems
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* DeleteItems
    (tItem* firstItem,
     tItem* lastItem)
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
        if (!firstItem || !lastItem)
            return 0;
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return firstItem;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: ClearItems
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* ClearItems
    (tItem*& lastItem)
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
        tItem* firstItem = 0;
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
        firstItem = m_firstItem;
        lastItem = m_lastItem;
        m_firstItem = (m_lastItem = 0);
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        lastItem = 0;
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return firstItem;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: ClearItems
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* ClearItems()
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
        tItem* firstItem = 0;
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
        firstItem = m_firstItem;
        m_firstItem = (m_lastItem = 0);
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return firstItem;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetFirstItem
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* SetFirstItem
    (tItem* item)
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
        m_firstItem = item;
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return item;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetFirstItem
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* GetFirstItem() const
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
        tItem* item = 0;
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
        item = m_firstItem;
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return item;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetLastItem
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* SetLastItem
    (tItem* item)
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
        m_lastItem = item;
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return item;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetLastItem
    //
    //    Author: $author$
    //      Date: 6/5/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tItem* GetLastItem() const
#if defined(CLISTT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 
    {
        tItem* item = 0;
#if !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT)
        item = m_lastItem;
#else // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CLISTT_MEMBER_FUNCS_IMPLEMENT) 
        return item;
    }
#endif // defined(CLISTT_MEMBER_FUNCS_INTERFACE) 

#if !defined(CLISTT_MEMBERS_ONLY)

    class c_INSTANCE_CLASS iterator
    {
    private:
        tItem* m_item;
        tItem* m_prevItem;
    public:
        iterator(tItem* item=0,tItem* prevItem=0):m_item(item), m_prevItem(prevItem){}
        iterator(const iterator& i):m_item(i.m_item), m_prevItem(i.m_prevItem){}
        iterator& operator ++ (){m_item = ((m_item)?(m_item->GetNextItem()):(0)); return *this;}
        iterator& operator -- (){m_item = ((m_item)?(m_item->GetPrevItem()):(m_prevItem)); m_prevItem=0; return *this;}
        iterator operator ++ (int){iterator thisOld(*this); m_item = ((m_item)?(m_item->GetNextItem()):(0)); return thisOld;}
        iterator operator -- (int){iterator thisOld(*this); m_item = ((m_item)?(m_item->GetPrevItem()):(m_prevItem)); m_prevItem=0; return thisOld;}
        tItem& operator * () const {return *((tItem*)(m_item));}
        tItem* operator -> () const {return ((tItem*)(m_item));}
        bool operator == (const iterator& i) const {return m_item == i.m_item;}
        bool operator != (const iterator& i) const {return m_item != i.m_item;}
    };

    iterator begin() const {return iterator(m_firstItem, 0);}
    iterator end() const {return iterator(0, m_lastItem);}
    iterator at(tItem* item) const {return iterator(item, 0);}
};
#undef CDB_CLASS


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CLISTT_MEMBERS_ONLY) 
#endif // !defined(CLISTT_MEMBERS_ONLY) 

#endif // !defined(_CLIST_HPP) || defined(CLISTT_MEMBERS_ONLY) 

