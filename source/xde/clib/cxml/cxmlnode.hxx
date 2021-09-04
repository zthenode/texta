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
 *   File: cxmlnode.hxx
 *
 * Author: $author$
 *   Date: 11/4/2008
 **********************************************************************
 */
#ifndef _CXMLNODE_HXX
#define _CXMLNODE_HXX

#include "cxmlnodeinterface.hxx"
#include "cxmlnodeitem.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLNodeT"
/**
 **********************************************************************
 *  Class: cXMLNodeT
 *
 * Author: $author$
 *   Date: 11/4/2008
 **********************************************************************
 */
template
<class TXMLNode=cXMLNode,
 class TXMLNodeInterface=cXMLNodeInterface,
 class TXMLNodeListInterface=cXMLNodeListInterface,
 class TXMLNamedNodeMapInterface=cXMLNamedNodeMapInterface,
 class TXMLDocumentInterface=cXMLDocumentInterface,
 class TXMLNodeItem=cXMLNodeItem,
 class TImplements=cXMLNodeImplement,
 class TExtends=cInterfaceInstance>
 
class cXMLNodeT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cXMLNodeT cDerives;

    TXMLNodeItem m_nodeItem;
    eXMLNodeType m_nodeType;
    TXMLNodeInterface* m_parentNode;

    /**
     **********************************************************************
     * Constructor: cXMLNodeT
     *
     *      Author: $author$
     *        Date: 11/4/2008
     **********************************************************************
     */
    cXMLNodeT
    (eXMLNodeType nodeType=e_XML_NODE_TYPE_VALUE_NONE) 
    : m_nodeItem((TXMLNodeInterface&)(*this)),
      m_nodeType(nodeType),
      m_parentNode(0)
    {
    }

    /**
     **********************************************************************
     * Function: SetParentNode
     *
     *   Author: $author$
     *     Date: 12/7/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* SetParentNode
    (TXMLNodeInterface* parentNode) 
    {
        TXMLNodeInterface* xmlNode = 0;
        xmlNode = (m_parentNode = parentNode);
        return xmlNode;
    }
    /**
     **********************************************************************
     * Function: ParentNode
     *
     *   Author: $author$
     *     Date: 12/7/2008
     **********************************************************************
     */
    virtual const TXMLNodeInterface* ParentNode() const 
    {
        const TXMLNodeInterface* xmlNode = m_parentNode;
        return xmlNode;
    }

    /**
     **********************************************************************
     * Function: NextSibling
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeInterface* NextSibling() const 
    {
        const TXMLNodeInterface* xmlNode = 0;
        TXMLNodeItem* xmlNodeItem;
        if ((xmlNodeItem = m_nodeItem.GetNextItem()))
            xmlNode = &xmlNodeItem->m_xmlNode;
        return xmlNode;
    }
    /**
     **********************************************************************
     * Function: PreviousSibling
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeInterface* PreviousSibling() const 
    {
        const TXMLNodeInterface* xmlNode = 0;
        TXMLNodeItem* xmlNodeItem;
        if ((xmlNodeItem = m_nodeItem.GetPrevItem()))
            xmlNode = &xmlNodeItem->m_xmlNode;
        return xmlNode;
    }

    /**
     **********************************************************************
     * Function: NodeTypeName
     *
     *   Author: $author$
     *     Date: 12/2/2008
     **********************************************************************
     */
    virtual const cXMLString* NodeTypeName() const 
    {
        const cXMLString* xmlString = cXMLNodeType::NodeTypeName(m_nodeType);
        return xmlString;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cXMLNodeExtends
 *
 *  Author: $author$
 *    Date: 11/4/2008
 **********************************************************************
 */
typedef cXMLNodeT<>
cXMLNodeExtends;

/**
 **********************************************************************
 *  Class: cXMLNode
 *
 * Author: $author$
 *   Date: 11/6/2008
 **********************************************************************
 */
class cXMLNode
: public cXMLNodeExtends
{
public:
    typedef cXMLNodeExtends cExtends;
    typedef cXMLNode cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLNode
     *
     *      Author: $author$
     *        Date: 11/6/2008
     **********************************************************************
     */
    cXMLNode
    (eXMLNodeType nodeType=e_XML_NODE_TYPE_VALUE_NONE) 
    : cExtends(nodeType) 
    {
    }

    /**
     **********************************************************************
     * Function: Node
     *
     *   Author: $author$
     *     Date: 11/29/2008
     **********************************************************************
     */
    virtual cXMLNode* Node() const 
    {
        cXMLNode* xmlNode = (cXMLNode*)(this);
        return xmlNode;
    }
};
#endif /* _CXMLNODE_HXX */
