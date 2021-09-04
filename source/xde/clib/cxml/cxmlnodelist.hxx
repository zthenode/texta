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
 *   File: cxmlnodelist.hxx
 *
 * Author: $author$
 *   Date: 11/11/2008
 **********************************************************************
 */
#ifndef _CXMLNODELIST_HXX
#define _CXMLNODELIST_HXX

#include "cxmlnodelistinterface.hxx"
#include "cxmlnodeitem.hxx"
#include "cxmlnode.hxx"

/**
 **********************************************************************
 * Typedef: cXMLNodeListExtends
 *
 *  Author: $author$
 *    Date: 11/11/2008
 **********************************************************************
 */
typedef cListT
<cXMLNodeItem, cImplement>
cXMLNodeListExtends;

#undef CDB_CLASS
#define CDB_CLASS "cXMLNodeListT"
/**
 **********************************************************************
 *  Class: cXMLNodeListT
 *
 * Author: $author$
 *   Date: 11/11/2008
 **********************************************************************
 */
template
<class TXMLNode=cXMLNode,
 class TXMLNodeItem=cXMLNodeItem,
 class TXMLNodeInterface=cXMLNodeInterface,
 class TImplements=cXMLNodeListImplement,
 class TExtends=cXMLNodeListExtends>
 
class cXMLNodeListT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cXMLNodeListT cDerives;

    /**
     **********************************************************************
     * Function: AppendItem
     *
     *   Author: $author$
     *     Date: 11/13/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* AppendItem
    (TXMLNodeInterface& xmlNode) 
    {
        TXMLNodeInterface* memberXmlNodeInterface = 0;
        TXMLNode* memberXmlNode;
        if ((memberXmlNodeInterface = (TXMLNodeInterface*)
            (memberXmlNode = xmlNode.Node())))
            cExtends::AddItem(memberXmlNode->m_nodeItem);
        return memberXmlNodeInterface;
    }
    /**
     **********************************************************************
     * Function: RemoveItem
     *
     *   Author: $author$
     *     Date: 11/13/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* RemoveItem
    (TXMLNodeInterface& xmlNode) 
    {
        TXMLNodeInterface* memberXmlNodeInterface = 0;
        TXMLNode* memberXmlNode;
        if ((memberXmlNodeInterface = (TXMLNodeInterface*)
            (memberXmlNode = xmlNode.Node())))
            cExtends::DeleteItem(memberXmlNode->m_nodeItem);
        return memberXmlNodeInterface;
    }

    /**
     **********************************************************************
     * Function: PushItem
     *
     *   Author: $author$
     *     Date: 12/5/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* PushItem
    (TXMLNodeInterface& xmlNode) 
    {
        TXMLNodeInterface* memberXmlNodeInterface = 0;
        TXMLNode* memberXmlNode;
        if ((memberXmlNodeInterface = (TXMLNodeInterface*)
            (memberXmlNode = xmlNode.Node())))
            cExtends::PushItem(memberXmlNode->m_nodeItem);
        return memberXmlNodeInterface;
    }
    /**
     **********************************************************************
     * Function: PopItem
     *
     *   Author: $author$
     *     Date: 12/5/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* PopItem() 
    {
        TXMLNodeInterface* memberXmlNodeInterface = 0;
        TXMLNodeItem* xmlNodeItem;
        
        if ((xmlNodeItem = cExtends::PopItem()))
            memberXmlNodeInterface = (TXMLNodeInterface*)(&xmlNodeItem->m_xmlNode);
        return memberXmlNodeInterface;
    }
    /**
     **********************************************************************
     * Function: PullItem
     *
     *   Author: $author$
     *     Date: 12/5/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* PullItem() 
    {
        TXMLNodeInterface* memberXmlNodeInterface = 0;
        TXMLNodeItem* xmlNodeItem;
        
        if ((xmlNodeItem = cExtends::PullItem()))
            memberXmlNodeInterface = (TXMLNodeInterface*)(&xmlNodeItem->m_xmlNode);
        return memberXmlNodeInterface;
    }

    /**
     **********************************************************************
     * Function: AppendItems
     *
     *   Author: $author$
     *     Date: 11/30/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* AppendItems
    (TXMLNodeInterface& firstNode, TXMLNodeInterface& lastNode) 
    {
        TXMLNodeInterface* memberXmlNodeInterface = 0;
        TXMLNode* firstMemberXmlNode;
        TXMLNode* lastMemberXmlNode;
        if ((lastMemberXmlNode = lastNode.Node()))
        if ((memberXmlNodeInterface = (TXMLNodeInterface*)
            (firstMemberXmlNode = firstNode.Node())))
            cExtends::AddItems
            (firstMemberXmlNode->m_nodeItem, 
             lastMemberXmlNode->m_nodeItem);
        return memberXmlNodeInterface;
    }
    /**
     **********************************************************************
     * Function: RemoveItems
     *
     *   Author: $author$
     *     Date: 11/30/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* RemoveItems
    (TXMLNodeInterface& firstNode, TXMLNodeInterface& lastNode) 
    {
        TXMLNodeInterface* memberXmlNodeInterface = 0;
        TXMLNode* firstMemberXmlNode;
        TXMLNode* lastMemberXmlNode;
        if ((lastMemberXmlNode = lastNode.Node()))
        if ((memberXmlNodeInterface = (TXMLNodeInterface*)
            (firstMemberXmlNode = firstNode.Node())))
            cExtends::DeleteItems
            (firstMemberXmlNode->m_nodeItem, 
             lastMemberXmlNode->m_nodeItem);
        return memberXmlNodeInterface;
    }

    /**
     **********************************************************************
     * Function: FirstItem
     *
     *   Author: $author$
     *     Date: 12/2/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* FirstItem() const 
    {
        TXMLNodeInterface* xmlNode = 0;
        TXMLNodeItem* xmlNodeItem;
        
        if ((xmlNodeItem = cExtends::GetFirstItem()))
            xmlNode = (TXMLNodeInterface*)(&xmlNodeItem->m_xmlNode);
        return xmlNode;
    }
    /**
     **********************************************************************
     * Function: LastItem
     *
     *   Author: $author$
     *     Date: 12/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* LastItem() const 
    {
        TXMLNodeInterface* xmlNode = 0;
        TXMLNodeItem* xmlNodeItem;
        
        if ((xmlNodeItem = cExtends::GetLastItem()))
            xmlNode = (TXMLNodeInterface*)(&xmlNodeItem->m_xmlNode);
        return xmlNode;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLNodeList
 *
 * Author: $author$
 *   Date: 11/11/2008
 **********************************************************************
 */
class cXMLNodeList
: public cXMLNodeListT<>
{
public:
    typedef cXMLNodeListT<> cExtends;
    typedef cXMLNodeList cDerives;
};

#endif /* _CXMLNODELIST_HXX */
