/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
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
 *   File: cnamelist.hxx
 *
 * Author: $author$
 *   Date: 3/26/2008
 **********************************************************************
 */
#ifndef _CNAMELIST_HXX
#define _CNAMELIST_HXX

#include "clist.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cNameItemT"
/**
 **********************************************************************
 *  Class: cNameItemT
 *
 * Author: $author$
 *   Date: 3/26/2008
 **********************************************************************
 */
template
<class TDerives,
 class TChar=CHAR,
 class TExtends=cBase>
 
class cNameItemT
: public cListItemT<TDerives,TExtends>
{
public:
    typedef cListItemT<TDerives,TExtends> cExtends;
    typedef cNameItemT cDerives;
    typedef TChar tChar;

    const TChar* m_name;

    /**
     **********************************************************************
     * Constructor: cNameItemT
     *
     *      Author: $author$
     *        Date: 3/26/2008
     **********************************************************************
     */
    cNameItemT(const TChar* name)
    : m_name(name) 
    {
    }
};
#undef CDB_CLASS

class cNameItem;

#undef CDB_CLASS
#define CDB_CLASS "cNameListT"
/**
 **********************************************************************
 *  Class: cNameListT
 *
 * Author: $author$
 *   Date: 3/26/2008
 **********************************************************************
 */
template
<class TChar=CHAR,
 class TItem=cNameItem,
 class TExtends=cBase>
 
class cNameListT
: public cStaticListT<TItem,TExtends>
{
public:
    typedef cStaticListT<TItem,TExtends> cExtends;
    typedef cNameListT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cNameItem
 *
 * Author: $author$
 *   Date: 3/26/2008
 **********************************************************************
 */
class cNameItem
: public cNameItemT<cNameItem,CHAR,cBase>
{
public:
    typedef cNameItemT<cNameItem,CHAR,cBase> cExtends;
    /**
     **********************************************************************
     * Constructor: cNameItem
     *
     *      Author: $author$
     *        Date: 3/26/2008
     **********************************************************************
     */
    cNameItem(const tChar* name)
    : cExtends(name)
    {
    }
};
/**
 **********************************************************************
 *  Class: cNameList
 *
 * Author: $author$
 *   Date: 3/26/2008
 **********************************************************************
 */
class cNameList
: public cNameListT<CHAR,cNameItem,cBase>
{
public:
    typedef cNameListT<CHAR,cNameItem,cBase> cExtends;
    static cNameList m_instance;
};
#endif /* _CNAMELIST_HXX */
