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
 *   File: cxmlparentbeginelementnode.hxx
 *
 * Author: $author$
 *   Date: 12/10/2008
 **********************************************************************
 */
#ifndef _CXMLPARENTBEGINELEMENTNODE_HXX
#define _CXMLPARENTBEGINELEMENTNODE_HXX

#include "cxmlelementnodeinterface.hxx"
#include "cxmlbeginelementnode.hxx"
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
 TImplements, cXMLBeginElementNode>

: virtual public TImplements,
  public cXMLBeginElementNode
{
public:
    typedef TImplements cImplements;
    typedef cXMLBeginElementNode cExtends;
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
    (const cXMLChar* nodeNameXMLChars=0, TLENGTH nodeNameLength=-1,
     const cXMLChar* nodeNamespacePrefixXMLChars=0, TLENGTH nodeNamespacePrefixLength=-1,
     eXMLNodeType nodeType=e_XML_NODE_TYPE_VALUE_BEGIN_ELEMENT) 
    : cExtends
      (nodeNameXMLChars, nodeNameLength,
       nodeNamespacePrefixXMLChars, nodeNamespacePrefixLength,
       nodeType) 
    {
    }
#include "cxmlparentnode_members.hxx"
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLParentBeginElementNode
 *
 * Author: $author$
 *   Date: 12/10/2008
 **********************************************************************
 */
class cXMLParentBeginElementNode
: public cXMLParentNodeT
  <cXMLNode, cXMLNodeList, cXMLNodeListInterface, 
   cXMLNodeInterface, cXMLNodeImplement,
   cXMLElementNodeImplement, cXMLBeginElementNode>
{
public:
    typedef cXMLParentNodeT
    <cXMLNode, cXMLNodeList, cXMLNodeListInterface, 
     cXMLNodeInterface, cXMLNodeImplement,
     cXMLElementNodeImplement, cXMLBeginElementNode> cExtends;
    typedef cXMLParentBeginElementNode cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLParentBeginElementNode
     *
     *      Author: $author$
     *        Date: 12/10/2008
     **********************************************************************
     */
    cXMLParentBeginElementNode
    (const cXMLChar* nodeNameXMLChars=0, TLENGTH nodeNameLength=-1,
     const cXMLChar* nodeNamespacePrefixXMLChars=0, TLENGTH nodeNamespacePrefixLength=-1,
     eXMLNodeType nodeType=e_XML_NODE_TYPE_VALUE_BEGIN_ELEMENT) 
    : cExtends
      (nodeNameXMLChars, nodeNameLength,
       nodeNamespacePrefixXMLChars, nodeNamespacePrefixLength, 
       nodeType) 
    {
    }
};
#endif /* _CXMLPARENTBEGINELEMENTNODE_HXX */
