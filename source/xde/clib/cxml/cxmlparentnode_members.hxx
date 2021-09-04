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
 *   File: cxmlparentnode_members.hxx
 *
 * Author: $author$
 *   Date: 12/11/2008
 **********************************************************************
 */

/*
class cXMLParentNodeT
{
public:
*/
    TXMLNodeList m_childNodes;

    /**
     **********************************************************************
     * Destructor: ~cXMLParentNodeT
     *
     *     Author: $author$
     *       Date: 12/10/2008
     **********************************************************************
     */
    virtual ~cXMLParentNodeT()
    {
    }

    /**
     **********************************************************************
     * Function: AppendChild
     *
     *   Author: $author$
     *     Date: 12/2/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* AppendChild
    (TXMLNodeInterface& xmlNode) 
    {
        TXMLNodeInterface* childXmlNode
        = m_childNodes.AppendItem(xmlNode);
        return childXmlNode;
    }
    /**
     **********************************************************************
     * Function: RemoveChild
     *
     *   Author: $author$
     *     Date: 12/2/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* RemoveChild
    (TXMLNodeInterface& xmlNode) 
    {
        TXMLNodeInterface* childXmlNode 
        = m_childNodes.RemoveItem(xmlNode);
        return childXmlNode;
    }

    /**
     **********************************************************************
     * Function: PushChild
     *
     *   Author: $author$
     *     Date: 12/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* PushChild
    (TXMLNodeInterface& xmlNode=0) 
    {
        TXMLNodeInterface* childXmlNode
        = m_childNodes.PushItem(xmlNode);
        return childXmlNode;
    }
    /**
     **********************************************************************
     * Function: PopChild
     *
     *   Author: $author$
     *     Date: 12/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* PopChild() 
    {
        TXMLNodeInterface* childXmlNode 
        = m_childNodes.PopItem();
        return childXmlNode;
    }
    /**
     **********************************************************************
     * Function: PullChild
     *
     *   Author: $author$
     *     Date: 12/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* PullChild() 
    {
        TXMLNodeInterface* childXmlNode 
        = m_childNodes.PullItem();
        return childXmlNode;
    }

    /**
     **********************************************************************
     * Function: AppendChildren
     *
     *   Author: $author$
     *     Date: 12/2/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* AppendChildren
    (TXMLNodeInterface& firstNode, 
     TXMLNodeInterface& lastNode) 
    {
        TXMLNodeInterface* childXmlNode = m_childNodes.
        AppendItems(firstNode, lastNode);
        return childXmlNode;
    }
    /**
     **********************************************************************
     * Function: RemoveChildren
     *
     *   Author: $author$
     *     Date: 12/2/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* RemoveChildren
    (TXMLNodeInterface& firstNode, 
     TXMLNodeInterface& lastNode) 
    {
        TXMLNodeInterface* childXmlNode = m_childNodes.
        RemoveItems(firstNode, lastNode);
        return childXmlNode;
    }

    /**
     **********************************************************************
     * Function: FirstChild
     *
     *   Author: $author$
     *     Date: 12/6/2008
     **********************************************************************
     */
    virtual const TXMLNodeInterface* FirstChild() const 
    {
        const TXMLNodeInterface* xmlNode = 0;
        const TXMLNodeListInterface* xmlNodeList;
        if ((xmlNodeList = ChildNodes()))
            xmlNode = xmlNodeList->FirstItem();
        return xmlNode;
    }
    /**
     **********************************************************************
     * Function: LastChild
     *
     *   Author: $author$
     *     Date: 12/6/2008
     **********************************************************************
     */
    virtual const TXMLNodeInterface* LastChild() const 
    {
        const TXMLNodeInterface* xmlNode = 0;
        const TXMLNodeListInterface* xmlNodeList;
        if ((xmlNodeList = ChildNodes()))
            xmlNode = xmlNodeList->LastItem();
        return xmlNode;
    }
    /**
     **********************************************************************
     * Function: ChildNodes
     *
     *   Author: $author$
     *     Date: 12/6/2008
     **********************************************************************
     */
    virtual const TXMLNodeListInterface* ChildNodes() const 
    {
        const TXMLNodeListInterface* xmlNodeList 
        = (const TXMLNodeListInterface*)(&m_childNodes);
        return xmlNodeList;
    }
    /**
     **********************************************************************
     * Function: HasChildNodes
     *
     *   Author: $author$
     *     Date: 12/6/2008
     **********************************************************************
     */
    virtual bool HasChildNodes() const 
    {
        bool hasChildNodes = false;
        const TXMLNodeInterface* xmlNode = 0;
        if ((xmlNode = FirstChild()))
            hasChildNodes = true;
        return hasChildNodes;
    }
/*
};
*/
