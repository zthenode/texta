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
 *   File: cxmlentitynode.hxx
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
#ifndef _CXMLENTITYNODE_HXX
#define _CXMLENTITYNODE_HXX

#include "cxmlentitynodeinterface.hxx"
#include "cxmlparentnamednode.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLEntityNodeT"
/**
 **********************************************************************
 *  Class: cXMLEntityNodeT
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
template
<class TXMLEntityNodeImplement=cXMLEntityNodeImplement,
 class TXMLParentNamedNode=cXMLParentNamedNode,
 class TImplements=TXMLEntityNodeImplement,
 class TExtends=TXMLParentNamedNode>
 
class cXMLEntityNodeT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cXMLEntityNodeT cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLEntityNodeT
     *
     *      Author: $author$
     *        Date: 12/16/2008
     **********************************************************************
     */
    cXMLEntityNodeT
    (const cXMLChar* nodeNameXMLChars=0, TLENGTH nodeNameLength=-1,
     eXMLNodeType nodeType=e_XML_NODE_TYPE_VALUE_ENTITY) 
    : cExtends
      (nodeType,
       nodeNameXMLChars, nodeNameLength) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cXMLEntityNodeT
     *
     *      Author: $author$
     *        Date: 12/16/2008
     **********************************************************************
     */
    cXMLEntityNodeT
    (const char* nodeNameChars, TLENGTH nodeNameLength=-1,
     eXMLNodeType nodeType=e_XML_NODE_TYPE_VALUE_ENTITY) 
    : cExtends
      (nodeType,
       nodeNameChars, nodeNameLength) 
    {
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLEntityNode
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
class cXMLEntityNode
: public cXMLEntityNodeT<>
{
public:
    typedef cXMLEntityNodeT<> cExtends;
    typedef cXMLEntityNode cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLEntityNode
     *
     *      Author: $author$
     *        Date: 12/16/2008
     **********************************************************************
     */
    cXMLEntityNode
    (const cXMLChar* nodeNameXMLChars=0, TLENGTH nodeNameLength=-1,
     eXMLNodeType nodeType=e_XML_NODE_TYPE_VALUE_ENTITY) 
    : cExtends(nodeNameXMLChars, nodeNameLength, nodeType) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cXMLEntityNode
     *
     *      Author: $author$
     *        Date: 12/16/2008
     **********************************************************************
     */
    cXMLEntityNode
    (const char* nodeNameChars, TLENGTH nodeNameLength=-1,
     eXMLNodeType nodeType=e_XML_NODE_TYPE_VALUE_ENTITY) 
    : cExtends(nodeNameChars, nodeNameLength, nodeType) 
    {
    }
    /**
     **********************************************************************
     * Function: EntityNode
     *
     *   Author: $author$
     *     Date: 12/17/2008
     **********************************************************************
     */
    virtual cXMLEntityNode* EntityNode() const 
    {
        cXMLEntityNode* entityNode = (cXMLEntityNode*)(this);
        return entityNode;
    }
};

#endif /* _CXMLENTITYNODE_HXX */
