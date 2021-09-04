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
 *   File: cxmlattributenode.hxx
 *
 * Author: $author$
 *   Date: 11/28/2008
 **********************************************************************
 */
#ifndef _CXMLATTRIBUTENODE_HXX
#define _CXMLATTRIBUTENODE_HXX

#include "cxmlattributenodeinterface.hxx"
#include "cxmlnamednode.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLAttributeNodeT"
/**
 **********************************************************************
 *  Class: cXMLAttributeNodeT
 *
 * Author: $author$
 *   Date: 11/28/2008
 **********************************************************************
 */
template
<class TXMLNamedNode=cXMLNamedNode,
 class TXMLAttributeNodeImplement=cXMLAttributeNodeImplement,
 class TImplements=TXMLAttributeNodeImplement,
 class TExtends=TXMLNamedNode>
 
class cXMLAttributeNodeT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cXMLAttributeNodeT cDerives;

    cXMLString m_nodeValue;

    /**
     **********************************************************************
     * Constructor: cXMLAttributeNodeT
     *
     *      Author: $author$
     *        Date: 11/28/2008
     **********************************************************************
     */
    cXMLAttributeNodeT
    (const cXMLChar* nodeNameXMLChars=0, TLENGTH nodeNameLength=-1,
     const cXMLChar* nodeNamespacePrefixXMLChars=0, TLENGTH nodeNamespacePrefixLength=-1,
     const cXMLChar* nodeValueXMLChars=0, TLENGTH nodeValueLength=-1) 
    : cExtends
      (e_XML_NODE_TYPE_VALUE_ATTRIBUTE,
       nodeNameXMLChars, nodeNameLength,
       nodeNamespacePrefixXMLChars, nodeNamespacePrefixLength)
    {
        TLENGTH length;
        eError error;

        if (nodeValueXMLChars)
        if (0 > (length = SetNodeValueChars
            (nodeValueXMLChars, nodeValueLength)))
            throw (error = -length);
    }

    /**
     **********************************************************************
     * Function: SetNodeValueChars
     *
     *   Author: $author$
     *     Date: 11/29/2008
     **********************************************************************
     */
    virtual TLENGTH SetNodeValueChars
    (const cXMLChar* xmlChars,
     TLENGTH length=-1) 
    {
        TLENGTH count = m_nodeValue.Assign(xmlChars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: NodeValue
     *
     *   Author: $author$
     *     Date: 11/29/2008
     **********************************************************************
     */
    virtual const cXMLString* NodeValue() const 
    {
        const cXMLString* xmlString = &m_nodeValue;
        return xmlString;
    }

    /**
     **********************************************************************
     * Function: DeleteThis
     *
     *   Author: $author$
     *     Date: 11/30/2008
     **********************************************************************
     */
    virtual eError DeleteThis()
    {
        delete this;
        return e_ERROR_NONE;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLAttributeNode
 *
 * Author: $author$
 *   Date: 11/29/2008
 **********************************************************************
 */
class cXMLAttributeNode
: public cXMLAttributeNodeT<>
{
public:
    typedef cXMLAttributeNodeT<> cExtends;
    typedef cXMLAttributeNode cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLAttributeNode
     *
     *      Author: $author$
     *        Date: 11/29/2008
     **********************************************************************
     */
    cXMLAttributeNode
    (const cXMLChar* nodeNameXMLChars=0, TLENGTH nodeNameLength=-1,
     const cXMLChar* nodeNamespacePrefixXMLChars=0, TLENGTH nodeNamespacePrefixLength=-1,
     const cXMLChar* nodeValueXMLChars=0, TLENGTH nodeValueLength=-1) 
    : cExtends
      (nodeNameXMLChars, nodeNameLength,
       nodeNamespacePrefixXMLChars, nodeNamespacePrefixLength,
       nodeValueXMLChars, nodeValueLength)
    {
    }
};
#endif /* _CXMLATTRIBUTENODE_HXX */
