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
 *   File: cxmlnamednode.hxx
 *
 * Author: $author$
 *   Date: 11/21/2008
 **********************************************************************
 */
#ifndef _CXMLNAMEDNODE_HXX
#define _CXMLNAMEDNODE_HXX

#include "cxmlnamednodeinterface.hxx"
#include "cxmlnode.hxx"
#include "cxmlnodename.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLNamedNodeT"
/**
 **********************************************************************
 *  Class: cXMLNamedNodeT
 *
 * Author: $author$
 *   Date: 11/21/2008
 **********************************************************************
 */
template
<class TXMLNode=cXMLNode,
 class TXMLNodeName=cXMLNodeName,
 class TXMLNamedNodeInterface=cXMLNamedNodeInterface,
 class TXMLNamedNodeImplement=cXMLNamedNodeImplement,
 class TImplements=TXMLNamedNodeImplement,
 class TExtends=TXMLNode>
 
class cXMLNamedNodeT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cXMLNamedNodeT cDerives;

    TXMLNodeName m_nodeName;

    /**
     **********************************************************************
     * Constructor: cXMLNamedNodeT
     *
     *      Author: $author$
     *        Date: 11/21/2008
     **********************************************************************
     */
    cXMLNamedNodeT
    (eXMLNodeType nodeType=e_XML_NODE_TYPE_VALUE_NONE,
     const cXMLChar* nodeNameXMLChars=0, TLENGTH nodeNameLength=-1,
     const cXMLChar* nodeNamespacePrefixXMLChars=0, TLENGTH nodeNamespacePrefixLength=-1) 
    : cExtends(nodeType)
    {
        eError error;
        TLENGTH length;

        if (nodeNameXMLChars)
        if (0 > (length = SetNodeNameChars
            (nodeNameXMLChars,  nodeNameLength)))
            throw (error = -length);

        if (nodeNamespacePrefixXMLChars)
        if (0 > (length = CTHIS SetNamespacePrefixChars
            (nodeNamespacePrefixXMLChars,  nodeNamespacePrefixLength)))
            throw (error = -length);
    }
    /**
     **********************************************************************
     * Constructor: cXMLNamedNodeT
     *
     *      Author: $author$
     *        Date: 11/21/2008
     **********************************************************************
     */
    cXMLNamedNodeT
    (eXMLNodeType nodeType,
     const char* nodeNameChars, TLENGTH nodeNameLength=-1,
     const char* nodeNamespacePrefixChars=0, TLENGTH nodeNamespacePrefixLength=-1) 
    : cExtends(nodeType)
    {
        eError error;
        TLENGTH length;

        if (nodeNameChars)
        if (0 > (length = SetNodeNameCharsc
            (nodeNameChars,  nodeNameLength)))
            throw (error = -length);

        if (nodeNamespacePrefixChars)
        if (0 > (length = SetNamespacePrefixCharsc
            (nodeNamespacePrefixChars,  nodeNamespacePrefixLength)))
            throw (error = -length);
    }

    /**
     **********************************************************************
     * Function: SetNodeNameCharsc
     *
     *   Author: $author$
     *     Date: 12/16/2008
     **********************************************************************
     */
    virtual TLENGTH SetNodeNameCharsc
    (const char* chars,
     TLENGTH length=-1) 
    {
        TLENGTH count = m_nodeName.Assignc(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: SetNamespacePrefixCharsc
     *
     *   Author: $author$
     *     Date: 12/16/2008
     **********************************************************************
     */
    virtual TLENGTH SetNamespacePrefixCharsc
    (const char* chars,
     TLENGTH length=-1) 
    {
        TLENGTH count = 0;
        return count;
    }

    /**
     **********************************************************************
     * Function: SetNodeNameChars
     *
     *   Author: $author$
     *     Date: 11/21/2008
     **********************************************************************
     */
    virtual TLENGTH SetNodeNameChars
    (const cXMLChar* xmlChars,
     TLENGTH length=-1) 
    {
        TLENGTH count = m_nodeName.Assign(xmlChars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: QualifiedName
     *
     *   Author: $author$
     *     Date: 11/21/2008
     **********************************************************************
     */
    virtual const cXMLString* QualifiedName() const 
    {
        const cXMLString* xmlString = m_nodeName.QualifiedName();
        return xmlString;
    }
    /**
     **********************************************************************
     * Function: UnqualifiedName
     *
     *   Author: $author$
     *     Date: 11/27/2008
     **********************************************************************
     */
    virtual const cXMLString* UnqualifiedName() const 
    {
        const cXMLString* xmlString = m_nodeName.UnqualifiedName();
        return xmlString;
    }
    /**
     **********************************************************************
     * Function: NamespacePrefix
     *
     *   Author: $author$
     *     Date: 11/27/2008
     **********************************************************************
     */
    virtual const cXMLString* NamespacePrefix() const 
    {
        const cXMLString* xmlString = m_nodeName.NamespacePrefix();
        return xmlString;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLNamedNode
 *
 * Author: $author$
 *   Date: 11/21/2008
 **********************************************************************
 */
class cXMLNamedNode
: public cXMLNamedNodeT<>
{
public:
    typedef cXMLNamedNodeT<> cExtends;
    typedef cXMLNamedNode cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLNamedNode
     *
     *      Author: $author$
     *        Date: 11/21/2008
     **********************************************************************
     */
    cXMLNamedNode
    (eXMLNodeType nodeType=e_XML_NODE_TYPE_VALUE_NONE,
     const cXMLChar* nodeNameXMLChars=0, TLENGTH nodeNameLength=-1,
     const cXMLChar* nodeNamespacePrefixXMLChars=0, TLENGTH nodeNamespacePrefixLength=-1) 
    : cExtends
      (nodeType, nodeNameXMLChars, nodeNameLength,
       nodeNamespacePrefixXMLChars, nodeNamespacePrefixLength)
    {
    }
    /**
     **********************************************************************
     * Constructor: cXMLNamedNode
     *
     *      Author: $author$
     *        Date: 12/16/2008
     **********************************************************************
     */
    cXMLNamedNode
    (eXMLNodeType nodeType,
     const char* nodeNameChars, TLENGTH nodeNameLength=-1,
     const char* nodeNamespacePrefixChars=0, TLENGTH nodeNamespacePrefixLength=-1) 
    : cExtends
      (nodeType, nodeNameChars, nodeNameLength,
       nodeNamespacePrefixChars, nodeNamespacePrefixLength)
    {
    }
};

#endif /* _CXMLNAMEDNODE_HXX */
