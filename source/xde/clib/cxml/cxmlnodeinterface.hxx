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
 *   File: cxmlnodeinterface.hxx
 *
 * Author: $author$
 *   Date: 11/4/2008
 **********************************************************************
 */
#ifndef _CXMLNODEINTERFACE_HXX
#define _CXMLNODEINTERFACE_HXX

#include "cinterface.hxx"
#include "cxmlnodetype.hxx"
#include "cxmlstring.hxx"

class c_INTERFACE_CLASS cXMLNodeInterface;
class c_INTERFACE_CLASS cXMLTextNodeInterface;
class c_INTERFACE_CLASS cXMLProcessorNodeInterface;
class c_INTERFACE_CLASS cXMLCommentNodeInterface;
class c_INTERFACE_CLASS cXMLElementNodeInterface;
class c_INTERFACE_CLASS cXMLAttributeNodeInterface;
class c_INTERFACE_CLASS cXMLBeginElementNodeInterface;
class c_INTERFACE_CLASS cXMLEndElementNodeInterface;
class c_INTERFACE_CLASS cXMLEntityNodeInterface;
class c_INTERFACE_CLASS cXMLEntityReferenceNodeInterface;
class c_INTERFACE_CLASS cXMLDocumentNodeInterface;
class c_INTERFACE_CLASS cXMLDocumentInterface;

class c_INTERFACE_CLASS cXMLNodeListInterface;
class c_INTERFACE_CLASS cXMLNamedNodeMapInterface;
class c_INTERFACE_CLASS cXMLNamedNodeInterface;

class cXMLNode;
class cXMLTextNode;
class cXMLAttributeNode;
class cXMLProcessorNode;
class cXMLCommentNode;
class cXMLElementNode;
class cXMLBeginElementNode;
class cXMLEndElementNode;
class cXMLDocumentNode;
class cXMLNodeItem;
class cXMLNodeList;

#undef CDB_CLASS
#define CDB_CLASS "cXMLNodeInterfaceT"
/**
 **********************************************************************
 *  Class: cXMLNodeInterfaceT
 *
 * Author: $author$
 *   Date: 11/4/2008
 **********************************************************************
 */
template
<class TXMLNode=cXMLNode,
 class TXMLNodeInterface=cXMLNodeInterface,
 class TXMLTextNodeInterface=cXMLTextNodeInterface,
 class TXMLElementNodeInterface=cXMLElementNodeInterface,
 class TXMLBeginElementNodeInterface=cXMLBeginElementNodeInterface,
 class TXMLEndElementNodeInterface=cXMLEndElementNodeInterface,
 class TXMLEntityNodeInterface=cXMLEntityNodeInterface,
 class TXMLEntityReferenceNodeInterface=cXMLEntityReferenceNodeInterface,
 class TXMLNodeListInterface=cXMLNodeListInterface,
 class TXMLNamedNodeMapInterface=cXMLNamedNodeMapInterface,
 class TXMLDocumentInterface=cXMLDocumentInterface,
 class TImplements=cInterface>
 
class c_INTERFACE_CLASS cXMLNodeInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLNodeInterfaceT cDerives;

    /**
     **********************************************************************
     * Function: SetNodeType
     *
     *   Author: $author$
     *     Date: 11/4/2008
     **********************************************************************
     */
    virtual eXMLNodeType SetNodeType
    (eXMLNodeType nodeType) = 0;
    /**
     **********************************************************************
     * Function: NodeType
     *
     *   Author: $author$
     *     Date: 11/4/2008
     **********************************************************************
     */
    virtual eXMLNodeType NodeType() const = 0;
    /**
     **********************************************************************
     * Function: NodeTypeNameChars
     *
     *   Author: $author$
     *     Date: 12/2/2008
     **********************************************************************
     */
    virtual const cXMLChar* NodeTypeNameChars
    (TLENGTH& length) const = 0;
    /**
     **********************************************************************
     * Function: NodeTypeName
     *
     *   Author: $author$
     *     Date: 12/2/2008
     **********************************************************************
     */
    virtual const cXMLString* NodeTypeName() const = 0;

    /**
     **********************************************************************
     * Function: SetNodeNameChars
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual TLENGTH SetNodeNameChars
    (const cXMLChar* xmlChars,
     TLENGTH length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetNodeNameChars
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const cXMLChar* GetNodeNameChars
    (TLENGTH& length) const = 0;
    /**
     **********************************************************************
     * Function: NodeNameChars
     *
     *   Author: $author$
     *     Date: 11/27/2008
     **********************************************************************
     */
    virtual const cXMLChar* NodeNameChars
    (TLENGTH& length) const = 0;
    /**
     **********************************************************************
     * Function: NodeName
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const cXMLString* NodeName() const = 0;

    /**
     **********************************************************************
     * Function: SetNodeValueChars
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual TLENGTH SetNodeValueChars
    (const cXMLChar* xmlChars,
     TLENGTH length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetNodeValueChars
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const cXMLChar* GetNodeValueChars
    (TLENGTH& length) const = 0;
    /**
     **********************************************************************
     * Function: NodeValueChars
     *
     *   Author: $author$
     *     Date: 11/29/2008
     **********************************************************************
     */
    virtual const cXMLChar* NodeValueChars
    (TLENGTH& length) const = 0;
    /**
     **********************************************************************
     * Function: NodeValue
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const cXMLString* NodeValue() const = 0;

    /**
     **********************************************************************
     * Function: LocalName
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const cXMLString* LocalName() const = 0;

    /**
     **********************************************************************
     * Function: Prefix
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const cXMLString* Prefix() const = 0;

    /**
     **********************************************************************
     * Function: QualifiedName
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const cXMLString* QualifiedName() const = 0;
    /**
     **********************************************************************
     * Function: UnqualifiedName
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const cXMLString* UnqualifiedName() const = 0;

    /**
     **********************************************************************
     * Function: SetNamespacePrefixChars
     *
     *   Author: $author$
     *     Date: 11/28/2008
     **********************************************************************
     */
    virtual TLENGTH SetNamespacePrefixChars
    (const cXMLChar* xmlChars,
     TLENGTH length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetNamespacePrefixChars
     *
     *   Author: $author$
     *     Date: 11/28/2008
     **********************************************************************
     */
    virtual const cXMLChar* GetNamespacePrefixChars
    (TLENGTH& length) const = 0;
    /**
     **********************************************************************
     * Function: NamespacePrefixChars
     *
     *   Author: $author$
     *     Date: 11/28/2008
     **********************************************************************
     */
    virtual const cXMLChar* NamespacePrefixChars
    (TLENGTH& length) const = 0;
    /**
     **********************************************************************
     * Function: NamespacePrefix
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const cXMLString* NamespacePrefix() const = 0;

    /**
     **********************************************************************
     * Function: NamespaceURI
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const cXMLString* NamespaceURI() const = 0;

    /**
     **********************************************************************
     * Function: OwnerDocument
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLDocumentInterface* OwnerDocument() const = 0;

    /**
     **********************************************************************
     * Function: SetParentNode
     *
     *   Author: $author$
     *     Date: 12/11/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* 
    SetParentNode(TXMLNodeInterface* xmlNode) = 0;
    /**
     **********************************************************************
     * Function: ParentNode
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeInterface* ParentNode() const = 0;

    /**
     **********************************************************************
     * Function: FirstChild
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeInterface* FirstChild() const = 0;
    /**
     **********************************************************************
     * Function: LastChild
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeInterface* LastChild() const = 0;
    /**
     **********************************************************************
     * Function: ChildNodes
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeListInterface* ChildNodes() const = 0;
    /**
     **********************************************************************
     * Function: HasChildNodes
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual bool HasChildNodes() const = 0;

    /**
     **********************************************************************
     * Function: NextSibling
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeInterface* NextSibling() const = 0;
    /**
     **********************************************************************
     * Function: PreviousSibling
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeInterface* PreviousSibling() const = 0;
    /**
     **********************************************************************
     * Function: SiblingNodes
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeListInterface* SiblingNodes() const = 0;
    /**
     **********************************************************************
     * Function: HasSiblingNodes
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual bool HasSiblingNodes() const = 0;

    /**
     **********************************************************************
     * Function: FirstAttribute
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeInterface* FirstAttribute() const = 0;
    /**
     **********************************************************************
     * Function: LastAttribute
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeInterface* LastAttribute() const = 0;
    /**
     **********************************************************************
     * Function: Attributes
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLNamedNodeMapInterface* Attributes() const = 0;
    /**
     **********************************************************************
     * Function: HasAttributes
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual bool HasAttributes() const = 0;

    /**
     **********************************************************************
     * Function: CloneNode
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* CloneNode
    (bool isDeep=false) = 0;

    /**
     **********************************************************************
     * Function: AppendChild
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* AppendChild
    (TXMLNodeInterface& xmlNode) = 0;
    /**
     **********************************************************************
     * Function: RemoveChild
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* RemoveChild
    (TXMLNodeInterface& xmlNode) = 0;
    /**
     **********************************************************************
     * Function: ReplaceChild
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* ReplaceChild
    (TXMLNodeInterface& newXmlNode,
     TXMLNodeInterface& oldXmlNode) = 0;

    /**
     **********************************************************************
     * Function: PushChild
     *
     *   Author: $author$
     *     Date: 12/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* PushChild
    (TXMLNodeInterface& xmlNode=0) = 0;
    /**
     **********************************************************************
     * Function: PopChild
     *
     *   Author: $author$
     *     Date: 12/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* PopChild() = 0;
    /**
     **********************************************************************
     * Function: PullChild
     *
     *   Author: $author$
     *     Date: 12/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* PullChild() = 0;

    /**
     **********************************************************************
     * Function: AppendChildren
     *
     *   Author: $author$
     *     Date: 12/1/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* AppendChildren
    (TXMLNodeInterface& firstNode, 
     TXMLNodeInterface& lastNode) = 0;
    /**
     **********************************************************************
     * Function: RemoveChildren
     *
     *   Author: $author$
     *     Date: 12/1/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* RemoveChildren
    (TXMLNodeInterface& firstNode, 
     TXMLNodeInterface& lastNode) = 0;

    /**
     **********************************************************************
     * Function: InsertBefore
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* InsertBefore
    (TXMLNodeInterface* newXmlNode,
     TXMLNodeInterface* oldXmlNode) = 0;
    /**
     **********************************************************************
     * Function: InsertAfter
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* InsertAfter
    (TXMLNodeInterface* newXmlNode,
     TXMLNodeInterface* oldXmlNode) = 0;

    /**
     **********************************************************************
     * Function: Normalize
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual void Normalize() = 0;

    /**
     **********************************************************************
     * Function: NodeInterface
     *
     *   Author: $author$
     *     Date: 11/30/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* NodeInterface() const = 0;
    /**
     **********************************************************************
     * Function: Node
     *
     *   Author: $author$
     *     Date: 11/13/2008
     **********************************************************************
     */
    virtual TXMLNode* Node() const = 0;
    /**
     **********************************************************************
     * Function: TextNodeInterface
     *
     *   Author: $author$
     *     Date: 12/14/2008
     **********************************************************************
     */
    virtual TXMLTextNodeInterface* TextNodeInterface() const = 0;
    /**
     **********************************************************************
     * Function: ElementNodeInterface
     *
     *   Author: $author$
     *     Date: 12/6/2008
     **********************************************************************
     */
    virtual TXMLElementNodeInterface* ElementNodeInterface() const = 0;
    /**
     **********************************************************************
     * Function: BeginElementNodeInterface
     *
     *   Author: $author$
     *     Date: 12/6/2008
     **********************************************************************
     */
    virtual TXMLBeginElementNodeInterface* BeginElementNodeInterface() const = 0;
    /**
     **********************************************************************
     * Function: EndElementNodeInterface
     *
     *   Author: $author$
     *     Date: 12/6/2008
     **********************************************************************
     */
    virtual TXMLEndElementNodeInterface* EndElementNodeInterface() const = 0;
    /**
     **********************************************************************
     * Function: EntityNodeInterface
     *
     *   Author: $author$
     *     Date: 12/16/2008
     **********************************************************************
     */
    virtual TXMLEntityNodeInterface* EntityNodeInterface() const = 0;
    /**
     **********************************************************************
     * Function: EntityReferenceNodeInterface
     *
     *   Author: $author$
     *     Date: 1/2/2009
     **********************************************************************
     */
    virtual TXMLEntityReferenceNodeInterface* 
    EntityReferenceNodeInterface() const = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLNodeInterface
 *
 * Author: $author$
 *   Date: 11/5/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLNodeInterface
: virtual public cXMLNodeInterfaceT<>
{
public:
    typedef cXMLNodeInterfaceT<> cImplements;
};

#undef CDB_CLASS
#define CDB_CLASS "cXMLNodeImplementT"
/**
 **********************************************************************
 *  Class: cXMLNodeImplementT
 *
 * Author: $author$
 *   Date: 11/4/2008
 **********************************************************************
 */
template
<class TXMLNode=cXMLNode,
 class TXMLNodeInterface=cXMLNodeInterface,
 class TXMLTextNodeInterface=cXMLTextNodeInterface,
 class TXMLElementNodeInterface=cXMLElementNodeInterface,
 class TXMLBeginElementNodeInterface=cXMLBeginElementNodeInterface,
 class TXMLEndElementNodeInterface=cXMLEndElementNodeInterface,
 class TXMLEntityNodeInterface=cXMLEntityNodeInterface,
 class TXMLEntityReferenceNodeInterface=cXMLEntityReferenceNodeInterface,
 class TXMLNodeListInterface=cXMLNodeListInterface,
 class TXMLNamedNodeMapInterface=cXMLNamedNodeMapInterface,
 class TXMLDocumentInterface=cXMLDocumentInterface>
 
class cXMLNodeImplementT
: virtual public TXMLNodeInterface
{
public:
    typedef TXMLNodeInterface cImplements;
    typedef cXMLNodeImplementT cDerives;

    /**
     **********************************************************************
     * Function: SetNodeType
     *
     *   Author: $author$
     *     Date: 11/4/2008
     **********************************************************************
     */
    virtual eXMLNodeType SetNodeType
    (eXMLNodeType nodeType) 
    {
        nodeType = e_XML_NODE_TYPE_VALUE_NONE;
        return nodeType;
    }
    /**
     **********************************************************************
     * Function: NodeType
     *
     *   Author: $author$
     *     Date: 11/4/2008
     **********************************************************************
     */
    virtual eXMLNodeType NodeType() const 
    {
        eXMLNodeType nodeType = e_XML_NODE_TYPE_VALUE_NONE;
        return nodeType;
    }
    /**
     **********************************************************************
     * Function: NodeTypeNameChars
     *
     *   Author: $author$
     *     Date: 12/2/2008
     **********************************************************************
     */
    virtual const cXMLChar* NodeTypeNameChars
    (TLENGTH& length) const 
    {
        const cXMLChar* xmlChars = 0;
        const cXMLString* nodeTypeName;
        if ((nodeTypeName = NodeTypeName()))
            xmlChars = nodeTypeName->Chars(length);
        return xmlChars;
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
        const cXMLString* xmlString = 0;
        return xmlString;
    }

    /**
     **********************************************************************
     * Function: SetNodeNameChars
     *
     *   Author: $author$
     *     Date: 11/4/2008
     **********************************************************************
     */
    virtual TLENGTH SetNodeNameChars
    (const cXMLChar* xmlChars,
     TLENGTH length=-1) 
    {
        TLENGTH count = 0;
        return count;
    }
    /**
     **********************************************************************
     * Function: GetNodeNameChars
     *
     *   Author: $author$
     *     Date: 11/4/2008
     **********************************************************************
     */
    virtual const cXMLChar* GetNodeNameChars
    (TLENGTH& length) const 
    {
        const cXMLChar* xmlChars = NodeNameChars(length);
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: NodeNameChars
     *
     *   Author: $author$
     *     Date: 11/27/2008
     **********************************************************************
     */
    virtual const cXMLChar* NodeNameChars
    (TLENGTH& length) const 
    {
        const cXMLChar* xmlChars = 0;
        const cXMLString* nodeName;
        if ((nodeName = NodeName()))
            xmlChars = nodeName->Chars(length);
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: NodeName
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const cXMLString* NodeName() const 
    {
        const cXMLString* xmlString = QualifiedName();
        return xmlString;
    }

    /**
     **********************************************************************
     * Function: SetNodeValueChars
     *
     *   Author: $author$
     *     Date: 11/4/2008
     **********************************************************************
     */
    virtual TLENGTH SetNodeValueChars
    (const cXMLChar* xmlChars,
     TLENGTH length=-1) 
    {
        TLENGTH count = 0;
        return count;
    }
    /**
     **********************************************************************
     * Function: GetNodeValueChars
     *
     *   Author: $author$
     *     Date: 11/4/2008
     **********************************************************************
     */
    virtual const cXMLChar* GetNodeValueChars
    (TLENGTH& length) const 
    {
        const cXMLChar* xmlChars = NodeValueChars(length);
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: NodeValueChars
     *
     *   Author: $author$
     *     Date: 11/29/2008
     **********************************************************************
     */
    virtual const cXMLChar* NodeValueChars
    (TLENGTH& length) const 
    {
        const cXMLChar* xmlChars = 0;
        const cXMLString* nodeValue;
        if ((nodeValue = NodeValue()))
            xmlChars = nodeValue->Chars(length);
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: NodeValue
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const cXMLString* NodeValue() const 
    {
        const cXMLString* xmlString = 0;
        return xmlString;
    }

    /**
     **********************************************************************
     * Function: LocalName
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const cXMLString* LocalName() const 
    {
        const cXMLString* xmlString = UnqualifiedName();
        return xmlString;
    }

    /**
     **********************************************************************
     * Function: Prefix
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const cXMLString* Prefix() const 
    {
        const cXMLString* xmlString = NamespacePrefix();
        return xmlString;
    }

    /**
     **********************************************************************
     * Function: QualifiedName
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const cXMLString* QualifiedName() const 
    {
        const cXMLString* xmlString = 0;
        return xmlString;
    }
    /**
     **********************************************************************
     * Function: UnqualifiedName
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const cXMLString* UnqualifiedName() const 
    {
        const cXMLString* xmlString = 0;
        return xmlString;
    }

    /**
     **********************************************************************
     * Function: SetNamespacePrefixChars
     *
     *   Author: $author$
     *     Date: 11/28/2008
     **********************************************************************
     */
    virtual TLENGTH SetNamespacePrefixChars
    (const cXMLChar* xmlChars,
     TLENGTH length=-1) 
    {
        TLENGTH count = 0;
        return count;
    }
    /**
     **********************************************************************
     * Function: GetNamespacePrefixChars
     *
     *   Author: $author$
     *     Date: 11/28/2008
     **********************************************************************
     */
    virtual const cXMLChar* GetNamespacePrefixChars
    (TLENGTH& length) const 
    {
        const cXMLChar* xmlChars = NamespacePrefixChars(length);
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: NamespacePrefixChars
     *
     *   Author: $author$
     *     Date: 11/28/2008
     **********************************************************************
     */
    virtual const cXMLChar* NamespacePrefixChars
    (TLENGTH& length) const 
    {
        const cXMLChar* xmlChars = 0;
        const cXMLString* namespacePrefix;
        if ((namespacePrefix = NamespacePrefix()))
            xmlChars = namespacePrefix->Chars(length);
        return xmlChars;
    }
    /**
     **********************************************************************
     * Function: NamespacePrefix
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const cXMLString* NamespacePrefix() const 
    {
        const cXMLString* xmlString = 0;
        return xmlString;
    }

    /**
     **********************************************************************
     * Function: NamespaceURI
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const cXMLString* NamespaceURI() const 
    {
        const cXMLString* xmlString = 0;
        return xmlString;
    }

    /**
     **********************************************************************
     * Function: OwnerDocument
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLDocumentInterface* OwnerDocument() const 
    {
        const TXMLDocumentInterface* xmlDocument = 0;
        return xmlDocument;
    }

    /**
     **********************************************************************
     * Function: SetParentNode
     *
     *   Author: $author$
     *     Date: 12/11/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* 
    SetParentNode(TXMLNodeInterface* xmlNode) 
    {
        TXMLNodeInterface* parentXmlNode = 0;
        return parentXmlNode;
    }
    /**
     **********************************************************************
     * Function: ParentNode
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeInterface* ParentNode() const 
    {
        const TXMLNodeInterface* xmlNode = 0;
        return xmlNode;
    }

    /**
     **********************************************************************
     * Function: FirstChild
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeInterface* FirstChild() const 
    {
        const TXMLNodeInterface* xmlNode = 0;
        return xmlNode;
    }
    /**
     **********************************************************************
     * Function: LastChild
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeInterface* LastChild() const 
    {
        const TXMLNodeInterface* xmlNode = 0;
        return xmlNode;
    }
    /**
     **********************************************************************
     * Function: ChildNodes
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeListInterface* ChildNodes() const 
    {
        const TXMLNodeListInterface* xmlNodeList = 0;
        return xmlNodeList;
    }
    /**
     **********************************************************************
     * Function: HasChildNodes
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual bool HasChildNodes() const 
    {
        bool hasChildNodes = false;
        return hasChildNodes;
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
        return xmlNode;
    }
    /**
     **********************************************************************
     * Function: SiblingNodes
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeListInterface* SiblingNodes() const 
    {
        const TXMLNodeListInterface* xmlNodeList = 0;
        return xmlNodeList;
    }
    /**
     **********************************************************************
     * Function: HasSiblingNodes
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual bool HasSiblingNodes() const 
    {
        bool hasSiblingNodes = false;
        return hasSiblingNodes;
    }

    /**
     **********************************************************************
     * Function: FirstAttribute
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeInterface* FirstAttribute() const 
    {
        const TXMLNodeInterface* xmlNode = 0;
        return xmlNode;
    }
    /**
     **********************************************************************
     * Function: LastAttribute
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLNodeInterface* LastAttribute() const 
    {
        const TXMLNodeInterface* xmlNode = 0;
        return xmlNode;
    }
    /**
     **********************************************************************
     * Function: Attributes
     *
     *   Author: $author$
     *     Date: 11/5/2008
     **********************************************************************
     */
    virtual const TXMLNamedNodeMapInterface* Attributes() const 
    {
        const TXMLNamedNodeMapInterface* xmlNodeMap = 0;
        return xmlNodeMap;
    }
    /**
     **********************************************************************
     * Function: HasAttributes
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual bool HasAttributes() const 
    {
        bool hasAttributes = false;
        return hasAttributes;
    }

    /**
     **********************************************************************
     * Function: CloneNode
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* CloneNode
    (bool isDeep=false) 
    {
        TXMLNodeInterface* xmlNode = 0;
        return xmlNode;
    }

    /**
     **********************************************************************
     * Function: AppendChild
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* AppendChild
    (TXMLNodeInterface& xmlNode) 
    {
        TXMLNodeInterface* childXmlNode = 0;
        return childXmlNode;
    }
    /**
     **********************************************************************
     * Function: RemoveChild
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* RemoveChild
    (TXMLNodeInterface& xmlNode) 
    {
        TXMLNodeInterface* childXmlNode = 0;
        return childXmlNode;
    }
    /**
     **********************************************************************
     * Function: ReplaceChild
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* ReplaceChild
    (TXMLNodeInterface& newXmlNode,
     TXMLNodeInterface& oldXmlNode) 
    {
        TXMLNodeInterface* childXmlNode = 0;
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
        TXMLNodeInterface* childXmlNode = 0;
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
        TXMLNodeInterface* childXmlNode = 0;
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
        TXMLNodeInterface* childXmlNode = 0;
        return childXmlNode;
    }

    /**
     **********************************************************************
     * Function: AppendChildren
     *
     *   Author: $author$
     *     Date: 12/1/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* AppendChildren
    (TXMLNodeInterface& firstNode, 
     TXMLNodeInterface& lastNode) 
    {
        TXMLNodeInterface* childXmlNode = 0;
        return childXmlNode;
    }
    /**
     **********************************************************************
     * Function: RemoveChildren
     *
     *   Author: $author$
     *     Date: 12/1/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* RemoveChildren
    (TXMLNodeInterface& firstNode, 
     TXMLNodeInterface& lastNode) 
    {
        TXMLNodeInterface* childXmlNode = 0;
        return childXmlNode;
    }

    /**
     **********************************************************************
     * Function: InsertBefore
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* InsertBefore
    (TXMLNodeInterface* newXmlNode,
     TXMLNodeInterface* oldXmlNode) 
    {
        TXMLNodeInterface* childXmlNode = 0;
        return childXmlNode;
    }
    /**
     **********************************************************************
     * Function: InsertAfter
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* InsertAfter
    (TXMLNodeInterface* newXmlNode,
     TXMLNodeInterface* oldXmlNode) 
    {
        TXMLNodeInterface* childXmlNode = 0;
        return childXmlNode;
    }

    /**
     **********************************************************************
     * Function: Normalize
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual void Normalize() 
    {
    }

    /**
     **********************************************************************
     * Function: NodeInterface
     *
     *   Author: $author$
     *     Date: 11/30/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* NodeInterface() const 
    {
        TXMLNodeInterface* xmlNode = (TXMLNodeInterface*)(this);
        return xmlNode;
    }
    /**
     **********************************************************************
     * Function: Node
     *
     *   Author: $author$
     *     Date: 11/13/2008
     **********************************************************************
     */
    virtual TXMLNode* Node() const 
    {
        TXMLNode* xmlNode = 0;
        return xmlNode;
    }
    /**
     **********************************************************************
     * Function: TextNodeInterface
     *
     *   Author: $author$
     *     Date: 12/14/2008
     **********************************************************************
     */
    virtual TXMLTextNodeInterface* TextNodeInterface() const 
    {
        TXMLTextNodeInterface* xmlNode = 0;
        return xmlNode;
    }
    /**
     **********************************************************************
     * Function: ElementNodeInterface
     *
     *   Author: $author$
     *     Date: 12/6/2008
     **********************************************************************
     */
    virtual TXMLElementNodeInterface* ElementNodeInterface() const 
    {
        TXMLElementNodeInterface* xmlNode = 0;
        return xmlNode;
    }
    /**
     **********************************************************************
     * Function: BeginElementNodeInterface
     *
     *   Author: $author$
     *     Date: 12/6/2008
     **********************************************************************
     */
    virtual TXMLBeginElementNodeInterface* BeginElementNodeInterface() const 
    {
        TXMLBeginElementNodeInterface* xmlNode = 0;
        return xmlNode;
    }
    /**
     **********************************************************************
     * Function: EndElementNodeInterface
     *
     *   Author: $author$
     *     Date: 12/6/2008
     **********************************************************************
     */
    virtual TXMLEndElementNodeInterface* EndElementNodeInterface() const 
    {
        TXMLEndElementNodeInterface* xmlNode = 0;
        return xmlNode;
    }
    /**
     **********************************************************************
     * Function: EntityNodeInterface
     *
     *   Author: $author$
     *     Date: 12/16/2008
     **********************************************************************
     */
    virtual TXMLEntityNodeInterface* EntityNodeInterface() const 
    {
        TXMLEntityNodeInterface* entityNode = 0;
        return entityNode;
    }
    /**
     **********************************************************************
     * Function: EntityReferenceNodeInterface
     *
     *   Author: $author$
     *     Date: 1/2/2009
     **********************************************************************
     */
    virtual TXMLEntityReferenceNodeInterface* 
    EntityReferenceNodeInterface() const 
    {
        TXMLEntityReferenceNodeInterface* entityReferenceNode = 0;
        return entityReferenceNode;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cXMLNodeImplement
 *
 *  Author: $author$
 *    Date: 11/4/2008
 **********************************************************************
 */
typedef cXMLNodeImplementT<>
cXMLNodeImplement;

#endif /* _CXMLNODEINTERFACE_HXX */
