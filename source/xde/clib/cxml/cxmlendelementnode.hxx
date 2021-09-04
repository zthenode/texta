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
 *   File: cxmlendelementnode.hxx
 *
 * Author: $author$
 *   Date: 12/4/2008
 **********************************************************************
 */
#ifndef _CXMLENDELEMENTNODE_HXX
#define _CXMLENDELEMENTNODE_HXX

#include "cxmlendelementnodeinterface.hxx"
#include "cxmlnamednode.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLEndElementNodeT"
/**
 **********************************************************************
 *  Class: cXMLEndElementNodeT
 *
 * Author: $author$
 *   Date: 12/4/2008
 **********************************************************************
 */
template
<class TXMLNamedNode=cXMLNamedNode,
 class TXMLEndElementNodeImplement=cXMLEndElementNodeImplement,
 class TImplements=TXMLEndElementNodeImplement,
 class TExtends=TXMLNamedNode>
 
class cXMLEndElementNodeT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cXMLEndElementNodeT cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLEndElementNodeT
     *
     *      Author: $author$
     *        Date: 12/4/2008
     **********************************************************************
     */
    cXMLEndElementNodeT
    (const cXMLChar* nodeNameXMLChars=0, TLENGTH nodeNameLength=-1,
     const cXMLChar* nodeNamespacePrefixXMLChars=0, TLENGTH nodeNamespacePrefixLength=-1,
     eXMLNodeType nodeType=e_XML_NODE_TYPE_VALUE_END_ELEMENT) 
    : cExtends
      (nodeType, nodeNameXMLChars, nodeNameLength,
       nodeNamespacePrefixXMLChars, nodeNamespacePrefixLength) 
    {
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLEndElementNode
 *
 * Author: $author$
 *   Date: 12/4/2008
 **********************************************************************
 */
class cXMLEndElementNode
: public cXMLEndElementNodeT<>
{
public:
    typedef cXMLEndElementNodeT<> cExtends;
    typedef cXMLEndElementNode cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLEndElementNode
     *
     *      Author: $author$
     *        Date: 12/4/2008
     **********************************************************************
     */
    cXMLEndElementNode
    (const cXMLChar* nodeNameXMLChars=0, TLENGTH nodeNameLength=-1,
     const cXMLChar* nodeNamespacePrefixXMLChars=0, TLENGTH nodeNamespacePrefixLength=-1) 
    : cExtends
      (nodeNameXMLChars, nodeNameLength,
       nodeNamespacePrefixXMLChars, nodeNamespacePrefixLength) 
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
#endif /* _CXMLENDELEMENTNODE_HXX */
