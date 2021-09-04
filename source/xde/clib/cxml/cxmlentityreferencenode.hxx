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
 *   File: cxmlentityreferencenode.hxx
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
#ifndef _CXMLENTITYREFERENCENODE_HXX
#define _CXMLENTITYREFERENCENODE_HXX

#include "cxmlentityreferencenodeinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLEntityReferenceNodeT"
/**
 **********************************************************************
 *  Class: cXMLEntityReferenceNodeT
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
template
<class TXMLEntityNodeInterface=cXMLEntityNodeInterface,
 class TXMLEntityReferenceNodeImplement=cXMLEntityReferenceNodeImplement,
 class TXMLNode=cXMLNode,
 class TImplements=TXMLEntityReferenceNodeImplement,
 class TExtends=TXMLNode>
 
class cXMLEntityReferenceNodeT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cXMLEntityReferenceNodeT cDerives;

    const TXMLEntityNodeInterface* m_referencedEntityNode;

    /**
     **********************************************************************
     * Constructor: cXMLEntityReferenceNodeT
     *
     *      Author: $author$
     *        Date: 12/16/2008
     **********************************************************************
     */
    cXMLEntityReferenceNodeT
    (const TXMLEntityNodeInterface* referencedEntityNode=0,
     eXMLNodeType nodeType=e_XML_NODE_TYPE_ENTITY_REFERENCE) 
    : cExtends(nodeType),
      m_referencedEntityNode(referencedEntityNode)
    {
    }
    /**
     **********************************************************************
     * Function: ReferenceEntityNode
     *
     *   Author: $author$
     *     Date: 12/16/2008
     **********************************************************************
     */
    virtual const TXMLEntityNodeInterface* ReferenceEntityNode
    (const TXMLEntityNodeInterface* entityNode) 
    {
        return m_referencedEntityNode = entityNode;
    }
    /**
     **********************************************************************
     * Function: ReferencedEntityNode
     *
     *   Author: $author$
     *     Date: 12/16/2008
     **********************************************************************
     */
    virtual const TXMLEntityNodeInterface* ReferencedEntityNode() const
    {
        return m_referencedEntityNode;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLEntityReferenceNode
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
class cXMLEntityReferenceNode
: public cXMLEntityReferenceNodeT<>
{
public:
    typedef cXMLEntityReferenceNodeT<> cExtends;
    typedef cXMLEntityReferenceNode cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLEntityReferenceNode
     *
     *      Author: $author$
     *        Date: 12/16/2008
     **********************************************************************
     */
    cXMLEntityReferenceNode
    (const cXMLEntityNodeInterface* referencedEntityNode=0) 
    : cExtends(referencedEntityNode) 
    {
    }
    /**
     **********************************************************************
     * Function: EntityReferenceNode
     *
     *   Author: $author$
     *     Date: 12/17/2008
     **********************************************************************
     */
    virtual cXMLEntityReferenceNode* EntityReferenceNode() const 
    {
        cXMLEntityReferenceNode* entityReferenceNode = (cXMLEntityReferenceNode*)(this);
        return entityReferenceNode;
    }
};
#endif /* _CXMLENTITYREFERENCENODE_HXX */
