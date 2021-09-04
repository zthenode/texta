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
 *   File: cxmlparentnamednode.hxx
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
#ifndef _CXMLPARENTNAMEDNODE_HXX
#define _CXMLPARENTNAMEDNODE_HXX

#include "cxmlnamednode.hxx"
#include "cxmlparentnode.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLParentNodeT"
/**
 **********************************************************************
 *  Class: cXMLParentNodeT
 *
 * Author: $author$
 *   Date: 12/10/2008
 **********************************************************************
 */
template
<class TXMLNode,
 class TXMLNodeList,
 class TXMLNodeListInterface,
 class TXMLNodeInterface,
 class TXMLNodeImplement,
 class TImplements>
 
class cXMLParentNodeT
<TXMLNode, TXMLNodeList, TXMLNodeListInterface, 
 TXMLNodeInterface, TXMLNodeImplement,
 TImplements, cXMLNamedNode>

: virtual public TImplements,
  public cXMLNamedNode
{
public:
    typedef TImplements cImplements;
    typedef cXMLNamedNode cExtends;
    typedef cXMLParentNodeT cDerives;

    /**
     **********************************************************************
     * Constructor: cXMLParentNodeT
     *
     *      Author: $author$
     *        Date: 12/10/2008
     **********************************************************************
     */
    cXMLParentNodeT
    (eXMLNodeType nodeType=e_XML_NODE_TYPE_NONE,
     const cXMLChar* nodeNameXMLChars=0, TLENGTH nodeNameLength=-1,
     const cXMLChar* nodeNamespacePrefixXMLChars=0, TLENGTH nodeNamespacePrefixLength=-1) 
    : cExtends
      (nodeType,
       nodeNameXMLChars, nodeNameLength,
       nodeNamespacePrefixXMLChars, nodeNamespacePrefixLength) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cXMLParentNodeT
     *
     *      Author: $author$
     *        Date: 12/16/2008
     **********************************************************************
     */
    cXMLParentNodeT
    (eXMLNodeType nodeType,
     const char* nodeNameChars, TLENGTH nodeNameLength=-1,
     const char* nodeNamespacePrefixChars=0, TLENGTH nodeNamespacePrefixLength=-1) 
    : cExtends
      (nodeType,
       nodeNameChars, nodeNameLength,
       nodeNamespacePrefixChars, nodeNamespacePrefixLength) 
    {
    }
#include "cxmlparentnode_members.hxx"
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLParentNamedNode
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
class cXMLParentNamedNode
: public cXMLParentNodeT
  <cXMLNode, cXMLNodeList, cXMLNodeListInterface, 
   cXMLNodeInterface, cXMLNodeImplement,
   cXMLNamedNodeImplement, cXMLNamedNode>
{
public:
    typedef cXMLParentNodeT
    <cXMLNode, cXMLNodeList, cXMLNodeListInterface, 
     cXMLNodeInterface, cXMLNodeImplement,
     cXMLNamedNodeImplement, cXMLNamedNode> cExtends;
    typedef cXMLParentNamedNode cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLParentNamedNode
     *
     *      Author: $author$
     *        Date: 12/16/2008
     **********************************************************************
     */
    cXMLParentNamedNode
    (eXMLNodeType nodeType=e_XML_NODE_TYPE_NONE,
     const cXMLChar* nodeNameXMLChars=0, TLENGTH nodeNameLength=-1,
     const cXMLChar* nodeNamespacePrefixXMLChars=0, TLENGTH nodeNamespacePrefixLength=-1) 
    : cExtends
      (nodeType, 
       nodeNameXMLChars, nodeNameLength,
       nodeNamespacePrefixXMLChars, nodeNamespacePrefixLength) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cXMLParentNamedNode
     *
     *      Author: $author$
     *        Date: 12/16/2008
     **********************************************************************
     */
    cXMLParentNamedNode
    (eXMLNodeType nodeType,
     const char* nodeNameChars, TLENGTH nodeNameLength=-1,
     const char* nodeNamespacePrefixChars=0, TLENGTH nodeNamespacePrefixLength=-1) 
    : cExtends
      (nodeType, 
       nodeNameChars, nodeNameLength,
       nodeNamespacePrefixChars, nodeNamespacePrefixLength) 
    {
    }
};
#endif /* _CXMLPARENTNAMEDNODE_HXX */
