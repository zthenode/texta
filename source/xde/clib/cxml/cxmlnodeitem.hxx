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
 *   File: cxmlnodeitem.hxx
 *
 * Author: $author$
 *   Date: 11/6/2008
 **********************************************************************
 */
#ifndef _CXMLNODEITEM_HXX
#define _CXMLNODEITEM_HXX

#include "cxmlnodeinterface.hxx"
#include "clist.hxx"

/**
 **********************************************************************
 * Typedef: cXMLNodeItemExtends
 *
 *  Author: $author$
 *    Date: 11/6/2008
 **********************************************************************
 */
typedef cListItemT<cXMLNodeItem, cBase>
cXMLNodeItemExtends;

#undef CDB_CLASS
#define CDB_CLASS "cXMLNodeItemT"
/**
 **********************************************************************
 *  Class: cXMLNodeItemT
 *
 * Author: $author$
 *   Date: 11/6/2008
 **********************************************************************
 */
template
<class TXMLNodeInterface=cXMLNodeInterface,
 class TExtends=cXMLNodeItemExtends>
 
class cXMLNodeItemT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef cXMLNodeItemT cDerives;

    TXMLNodeInterface& m_xmlNode;

    /**
     **********************************************************************
     * Constructor: cXMLNodeItemT
     *
     *      Author: $author$
     *        Date: 11/6/2008
     **********************************************************************
     */
    cXMLNodeItemT
    (TXMLNodeInterface& xmlNode) 
    : m_xmlNode(xmlNode)
    {
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLNodeItem
 *
 * Author: $author$
 *   Date: 11/6/2008
 **********************************************************************
 */
class cXMLNodeItem
: public cXMLNodeItemT<>
{
public:
    typedef cXMLNodeItemT<> cExtends;
    typedef cXMLNodeItem cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLNodeItem
     *
     *      Author: $author$
     *        Date: 11/6/2008
     **********************************************************************
     */
    cXMLNodeItem
    (cXMLNodeInterface& xmlNode) 
    : cExtends(xmlNode) 
    {
    }
};
#endif /* _CXMLNODEITEM_HXX */
