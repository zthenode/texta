/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: clist.hxx
 *
 * Author: $author$
 *   Date: 1/26/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CLIST_HXX
#define _CLIST_HXX

#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cListItemT
 *
 * Author: $author$
 *   Date: 2/1/2007
 **********************************************************************
 */
template
<class TDerives,
 class TExtends=cBase>

class cListItemT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;

    TDerives *m_prevItem, *m_nextItem;

    /**
     **********************************************************************
     * Constructor: cListItemT
     *
     *      Author: $author$
     *        Date: 2/1/2007
     **********************************************************************
     */
    cListItemT(TDerives *prevItem=0, TDerives *nextItem=0)
    :m_prevItem(prevItem),
     m_nextItem(nextItem) 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cListItemT
     *
     *      Author: $author$
     *        Date: 2/1/2007
     **********************************************************************
     */
    virtual ~cListItemT()
    {
    }
    /**
     **********************************************************************
     * Function: GetPrevItem
     *
     *   Author: $author$
     *     Date: 2/1/2007
     **********************************************************************
     */
    TDerives *GetPrevItem() const
    {
        return m_prevItem;
    }
    /**
     **********************************************************************
     * Function: GetNextItem
     *
     *   Author: $author$
     *     Date: 2/1/2007
     **********************************************************************
     */
    TDerives *GetNextItem() const
    {
        return m_nextItem;
    }
};

/**
 **********************************************************************
 *  Class: cListT
 *
 * Author: $author$
 *   Date: 1/26/2007
 **********************************************************************
 */
template
<class TItem, 
 class TExtends=cBase>

class cListT
: public TExtends
{
public:
    typedef TExtends cExtends;

	TItem *m_firstItem, *m_lastItem;

    /**
     **********************************************************************
     * Constructor: cListT
     *
     *      Author: $author$
     *        Date: 1/26/2007
     **********************************************************************
     */
    cListT(TItem* firstItem=0, TItem* lastItem=0)
    : m_firstItem(firstItem),
      m_lastItem(lastItem) 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cListT
     *
     *      Author: $author$
     *        Date: 1/26/2007
     **********************************************************************
     */
    virtual ~cListT()
    {
    }

#include "clist_members.hxx"
};

/**
 **********************************************************************
 *  Class: cStaticListT
 *
 * Author: $author$
 *   Date: 1/26/2007
 **********************************************************************
 */
template
<class TItem, 
 class TExtends=cBase>

class cStaticListT
: public TExtends
{
public:
    typedef TExtends cExtends;

	static TItem *m_firstItem, *m_lastItem;

    /**
     **********************************************************************
     * Constructor: cStaticListT
     *
     *      Author: $author$
     *        Date: 1/26/2007
     **********************************************************************
     */
    cStaticListT() 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cStaticListT
     *
     *      Author: $author$
     *        Date: 1/26/2007
     **********************************************************************
     */
    virtual ~cStaticListT()
    {
    }

#include "clist_members.hxx"
};

/**
 **********************************************************************
 *  Class: cDynamicListItemT
 *
 * Author: $author$
 *   Date: 7/13/2003
 **********************************************************************
 */
template 
<class TDerives,
 class TExtends=cBase>

class cDynamicListItemT
: public cListItemT<TDerives, TExtends>
{
public:
    typedef cListItemT<TDerives, TExtends> cExtends;

    bool m_is_static, m_is_persistant;

    /**
     **********************************************************************
     * Constructor: cDynamicListItemT
     *
     *      Author: $author$
     *        Date: 7/13/2003
     **********************************************************************
     */
    cDynamicListItemT
    (bool is_static=false, bool is_persistant=false, 
     TDerives *previous=0, TDerives *next=0)
    : cExtends(previous, next),
      m_is_static(is_static),
      m_is_persistant(is_persistant)
    {
    }
    /**
     **********************************************************************
     * Function: SetIsStatic
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    bool SetIsStatic(bool is_static=true)
    {
        m_is_static=is_static;
        return m_is_static;
    }
    /**
     **********************************************************************
     * Function: GetIsStatic
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    bool GetIsStatic() const
    {
        return m_is_static;
    }

    /**
     **********************************************************************
     * Function: SetIsPersistant
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    bool SetIsPersistant(bool is_persistant=true)
    {
        m_is_persistant=is_persistant;
        return m_is_persistant;
    }
    /**
     **********************************************************************
     * Function: GetIsPersistant
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    bool GetIsPersistant() const
    {
        return m_is_persistant;
    }
};

/**
 **********************************************************************
 *  Class: cDynamicListT
 *
 * Author: $author$
 *   Date: 7/13/2003
 **********************************************************************
 */
template 
<class TItem,
 class TExtends=cBase>

class cDynamicListT
: public cListT<TItem, TExtends>
{
public:
    typedef cListT<TItem, TExtends> cExtends;

    bool m_is_static;

    /**
     **********************************************************************
     * Constructor: cDynamicListT
     *
     *      Author: $author$
     *        Date: 7/13/2003
     **********************************************************************
     */
    cDynamicListT
    (bool is_static=false,
     TItem *first=0,TItem *last=0)
    : cExtends(first,last),
      m_is_static(is_static) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cDynamicListT
     *
     *     Author: $author$
     *       Date: 7/13/2003
     **********************************************************************
     */
    virtual ~cDynamicListT()
    {
        Destruct();
    }
    /**
     **********************************************************************
     * Function: Destruct
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    virtual void Destruct()
    {
        eError error;

        if ((error=Clear()))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    virtual eError Clear()
    {
        eError error;
        TItem *item,*previous;

        if (m_is_static)
            CTHIS m_firstItem = CTHIS m_lastItem = 0;

        else for (item = CTHIS m_lastItem; item; item=previous)
        {
            previous=item->m_prevItem;

            if (!item->m_is_persistant)
            {
                CTHIS DeleteItem(*item);

                if (!item->m_is_static)
                if ((error=FreeItem(*item)))
                    return e_ERROR_FREE;
            }
        }
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: FreeItem
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    virtual eError FreeItem(TItem& item)
    {
        delete &item;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: SetIsStatic
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    inline bool SetIsStatic(bool is_static=true)
    {
        m_is_static=is_static;
        return m_is_static;
    }
    /**
     **********************************************************************
     * Function: GetIsStatic
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    inline bool GetIsStatic() const
    {
        return m_is_static;
    }
};

#endif /* _CLIST_HXX */
