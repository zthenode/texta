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
 *   File: cxmlelementnode.hxx
 *
 * Author: $author$
 *   Date: 11/15/2008
 **********************************************************************
 */
#ifndef _CXMLELEMENTNODE_HXX
#define _CXMLELEMENTNODE_HXX

#include "cxmlelementnodeinterface.hxx"
#include "cxmlbeginelementnode.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLElementNodeT"
/**
 **********************************************************************
 *  Class: cXMLElementNodeT
 *
 * Author: $author$
 *   Date: 11/15/2008
 **********************************************************************
 */
template
<class TXMLNodeList=cXMLNodeList,
 class TXMLElementNode=cXMLElementNode,
 class TXMLBeginElementNode=cXMLBeginElementNode,
 class TXMLNodeInterface=cXMLNodeInterface,
 class TXMLElementNodeInterface=cXMLElementNodeInterface,
 class TXMLElementNodeImplement=cXMLElementNodeImplement,
 class TImplements=TXMLElementNodeImplement,
 class TExtends=TXMLBeginElementNode>
 
class cXMLElementNodeT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cXMLElementNodeT cDerives;

    TXMLNodeList m_childNodes;

    /**
     **********************************************************************
     * Constructor: cXMLElementNodeT
     *
     *      Author: $author$
     *        Date: 11/15/2008
     **********************************************************************
     */
    cXMLElementNodeT
    (const cXMLChar* nodeNameChars=0, TLENGTH nodeNameLength=-1,
     const cXMLChar* nodeNamespacePrefixChars=0, TLENGTH nodeNamespacePrefixLength=-1) 
    : cExtends
      (nodeNameChars, nodeNameLength,
       nodeNamespacePrefixChars, nodeNamespacePrefixLength,
       e_XML_NODE_TYPE_VALUE_ELEMENT)
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
     * Function: ElementNode
     *
     *   Author: $author$
     *     Date: 12/1/2008
     **********************************************************************
     */
    virtual TXMLElementNode* ElementNode() const 
    {
        TXMLElementNode* elementNode = (TXMLElementNode*)(this);
        return elementNode;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLElementNode
 *
 * Author: $author$
 *   Date: 12/1/2008
 **********************************************************************
 */
class cXMLElementNode
: public cXMLElementNodeT<>
{
public:
    typedef cXMLElementNodeT<> cExtends;
    typedef cXMLElementNode cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLElementNode
     *
     *      Author: $author$
     *        Date: 12/1/2008
     **********************************************************************
     */
    cXMLElementNode
    (const cXMLChar* nodeNameChars=0, TLENGTH nodeNameLength=-1,
     const cXMLChar* nodeNamespacePrefixChars=0, TLENGTH nodeNamespacePrefixLength=-1) 
    : cExtends
      (nodeNameChars, nodeNameLength,
       nodeNamespacePrefixChars, nodeNamespacePrefixLength)
    {
    }
};
#endif /* _CXMLELEMENTNODE_HXX */
