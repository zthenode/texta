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
 *   File: cxmlbeginelementnode.hxx
 *
 * Author: $author$
 *   Date: 12/1/2008
 **********************************************************************
 */
#ifndef _CXMLBEGINELEMENTNODE_HXX
#define _CXMLBEGINELEMENTNODE_HXX

#include "cxmlbeginelementnodeinterface.hxx"
#include "cxmlnamednode.hxx"
#include "cxmlnodelist.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLBeginElementNodeT"
/**
 **********************************************************************
 *  Class: cXMLBeginElementNodeT
 *
 * Author: $author$
 *   Date: 12/1/2008
 **********************************************************************
 */
template
<class TXMLNodeList=cXMLNodeList,
 class TXMLNamedNode=cXMLNamedNode,
 class TXMLNodeInterface=cXMLNodeInterface,
 class TXMLBeginElementNodeImplement=cXMLBeginElementNodeImplement,
 class TImplements=TXMLBeginElementNodeImplement,
 class TExtends=TXMLNamedNode>
 
class cXMLBeginElementNodeT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cXMLBeginElementNodeT cDerives;

    TXMLNodeList m_attributeNodes;

    /**
     **********************************************************************
     * Constructor: cXMLBeginElementNodeT
     *
     *      Author: $author$
     *        Date: 12/1/2008
     **********************************************************************
     */
    cXMLBeginElementNodeT
    (const cXMLChar* nodeNameXMLChars=0, TLENGTH nodeNameLength=-1,
     const cXMLChar* nodeNamespacePrefixXMLChars=0, TLENGTH nodeNamespacePrefixLength=-1,
     eXMLNodeType nodeType=e_XML_NODE_TYPE_VALUE_BEGIN_ELEMENT) 
    : cExtends
      (nodeType, nodeNameXMLChars, nodeNameLength,
       nodeNamespacePrefixXMLChars, nodeNamespacePrefixLength)
    {
    }

    /**
     **********************************************************************
     * Function: AppendAttributes
     *
     *   Author: $author$
     *     Date: 12/1/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* AppendAttributes
    (TXMLNodeInterface& firstAttribute,
     TXMLNodeInterface& lastAttribute) 
    {
        TXMLNodeInterface* attributeNode = m_attributeNodes.
        AppendItems(firstAttribute, lastAttribute);
        return attributeNode;
    }
    /**
     **********************************************************************
     * Function: RemoveAttributes
     *
     *   Author: $author$
     *     Date: 12/1/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* RemoveAttributes
    (TXMLNodeInterface& firstAttribute,
     TXMLNodeInterface& lastAttribute) 
    {
        TXMLNodeInterface* attributeNode = m_attributeNodes.
        RemoveItems(firstAttribute, lastAttribute);
        return attributeNode;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLBeginElementNode
 *
 * Author: $author$
 *   Date: 12/1/2008
 **********************************************************************
 */
class cXMLBeginElementNode
: public cXMLBeginElementNodeT<>
{
public:
    typedef cXMLBeginElementNodeT<> cExtends;
    typedef cXMLBeginElementNode cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLBeginElementNode
     *
     *      Author: $author$
     *        Date: 12/1/2008
     **********************************************************************
     */
    cXMLBeginElementNode
    (const cXMLChar* nodeNameXMLChars=0, TLENGTH nodeNameLength=-1,
     const cXMLChar* nodeNamespacePrefixXMLChars=0, TLENGTH nodeNamespacePrefixLength=-1,
     eXMLNodeType nodeType=e_XML_NODE_TYPE_VALUE_BEGIN_ELEMENT) 
    : cExtends
      (nodeNameXMLChars, nodeNameLength,
       nodeNamespacePrefixXMLChars, nodeNamespacePrefixLength, nodeType) 
    {
    }
    /**
     **********************************************************************
     * Function: DeleteThis
     *
     *   Author: $author$
     *     Date: 12/10/2008
     **********************************************************************
     */
    virtual eError DeleteThis()
    {
        delete this;
        return e_ERROR_NONE;
    }
};

#endif /* _CXMLBEGINELEMENTNODE_HXX */
