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
 *   File: cxmlparentnode.hxx
 *
 * Author: $author$
 *   Date: 12/6/2008
 **********************************************************************
 */
#ifndef _CXMLPARENTNODE_HXX
#define _CXMLPARENTNODE_HXX

#include "cxmlelementnodeinterface.hxx"
#include "cxmlbeginelementnode.hxx"
#include "cxmlnodelist.hxx"
#include "cxmlnode.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLParentNodeT"
/**
 **********************************************************************
 *  Class: cXMLParentNodeT
 *
 * Author: $author$
 *   Date: 12/6/2008
 **********************************************************************
 */
template
<class TXMLNode=cXMLNode,
 class TXMLNodeList=cXMLNodeList,
 class TXMLNodeListInterface=cXMLNodeListInterface,
 class TXMLNodeInterface=cXMLNodeInterface,
 class TXMLNodeImplement=cXMLNodeImplement,
 class TImplements=TXMLNodeImplement,
 class TExtends=TXMLNode>
 
class cXMLParentNodeT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cXMLParentNodeT cDerives;

    /**
     **********************************************************************
     * Constructor: cXMLParentNodeT
     *
     *      Author: $author$
     *        Date: 12/6/2008
     **********************************************************************
     */
    cXMLParentNodeT
    (eXMLNodeType nodeType=e_XML_NODE_TYPE_NONE)
    : cExtends(nodeType)
    {
    }
#include "cxmlparentnode_members.hxx"
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLParentNode
 *
 * Author: $author$
 *   Date: 12/6/2008
 **********************************************************************
 */
class cXMLParentNode
: public cXMLParentNodeT<>
{
public:
    typedef cXMLParentNodeT<> cExtends;
    typedef cXMLParentNode cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLParentNode
     *
     *      Author: $author$
     *        Date: 12/6/2008
     **********************************************************************
     */
    cXMLParentNode
    (eXMLNodeType nodeType=e_XML_NODE_TYPE_NONE)
    : cExtends(nodeType) 
    {
    }
};
#endif /* _CXMLPARENTNODE_HXX */
