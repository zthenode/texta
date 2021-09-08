///////////////////////////////////////////////////////////////////////
//   File: cevlist_members.hpp
//
// Author: $author$
//   Date: 4/4/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    // Function: AddItem
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEVLIST_MEMBER void AddItem(TItem& item) 
    {
		item.m_nextItem = 0;

		if ((item.m_prevItem = m_lastItem))
			m_lastItem->m_nextItem = &item;
		else m_firstItem = &item;

		m_lastItem = &item;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: PushItem
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEVLIST_MEMBER void PushItem(TItem& item)  
    {
		item.m_prevItem = 0;

		if ((item.m_nextItem = m_firstItem))
			m_firstItem->m_prevItem = &item;
		else m_lastItem = &item;

		m_firstItem = &item;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: InsertBeforeItem
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEVLIST_MEMBER void InsertBeforeItem(TItem &otherItem, TItem& item)
    {
        if ((item.m_prevItem = otherItem.m_prevItem))
            otherItem.m_prevItem->m_nextItem = &item;
        else m_firstItem = &item;

        otherItem.m_prevItem = &item;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: InsertAfterItem
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEVLIST_MEMBER void InsertAfterItem(TItem &otherItem, TItem& item)
    {
        if ((item.m_nextItem = otherItem.m_nextItem))
            otherItem.m_nextItem->m_prevItem = &item;
        else m_lastItem = &item;

        otherItem.m_nextItem = &item;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteItem
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEVLIST_MEMBER void DeleteItem(TItem& item) 
    {
		if (item.m_nextItem)
			item.m_nextItem->m_prevItem = item.m_prevItem;
		else m_lastItem = item.m_prevItem;

		if (item.m_prevItem)
			item.m_prevItem->m_nextItem = item.m_nextItem;
		else m_firstItem = item.m_nextItem;

		item.m_nextItem = 0;
		item.m_prevItem = 0;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: PopItem
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEVLIST_MEMBER TItem* PopItem() 
    {
        TItem* item = 0;

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
        return item;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: PullItem
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEVLIST_MEMBER TItem* PullItem() 
    {
        TItem* item = 0;

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
        return item;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetFirstItem
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEVLIST_MEMBER TItem* GetFirstItem() CEVLIST_MEMBER_const 
    {
        return m_firstItem;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetLastItem
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEVLIST_MEMBER TItem* GetLastItem() CEVLIST_MEMBER_const 
    {
        return m_lastItem;
    }
