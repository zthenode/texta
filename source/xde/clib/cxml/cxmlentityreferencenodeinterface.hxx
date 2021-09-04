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
 *   File: cxmlentityreferencenodeinterface.hxx
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
#ifndef _CXMLENTITYREFERENCENODEINTERFACE_HXX
#define _CXMLENTITYREFERENCENODEINTERFACE_HXX

#include "cxmlentitynode.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLEntityReferenceNodeInterfaceT"
/**
 **********************************************************************
 *  Class: cXMLEntityReferenceNodeInterfaceT
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
template
<class TXMLEntityNodeInterface=cXMLEntityNodeInterface,
 class TXMLNodeInterface=cXMLNodeInterface,
 class TImplements=TXMLNodeInterface>
 
class c_INTERFACE_CLASS cXMLEntityReferenceNodeInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLEntityReferenceNodeInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: ReferenceEntityNode
     *
     *   Author: $author$
     *     Date: 12/16/2008
     **********************************************************************
     */
    virtual const TXMLEntityNodeInterface* ReferenceEntityNode
    (const TXMLEntityNodeInterface* entityNode) = 0;
    /**
     **********************************************************************
     * Function: ReferencedEntityNode
     *
     *   Author: $author$
     *     Date: 12/16/2008
     **********************************************************************
     */
    virtual const TXMLEntityNodeInterface* ReferencedEntityNode() const = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLEntityReferenceNodeInterface
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLEntityReferenceNodeInterface
: virtual public cXMLEntityReferenceNodeInterfaceT<>
{
public:
    typedef cXMLEntityReferenceNodeInterfaceT<> cImplements;
    typedef cXMLEntityReferenceNodeInterface cDerives;
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 12/16/2008
     **********************************************************************
     */
    static cXMLEntityReferenceNodeInterface* CreateInstance
    (cXMLDocumentNodeInterface& documentNode,
     const cXMLChar* referencedNameXmlChars,
     TLENGTH referencedNameLength=-1);
}; 

#undef CDB_CLASS
#define CDB_CLASS "cXMLEntityReferenceNodeImplementT"
/**
 **********************************************************************
 *  Class: cXMLEntityReferenceNodeImplementT
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
template
<class TXMLNodeImplement=cXMLNodeImplement,
 class TXMLEntityNodeInterface=cXMLEntityNodeInterface,
 class TXMLEntityReferenceNodeInterface=cXMLEntityReferenceNodeInterface,
 class TImplements=TXMLEntityReferenceNodeInterface>
 
class cXMLEntityReferenceNodeImplementT
: virtual public TXMLNodeImplement,
  virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLEntityReferenceNodeImplementT cDerives;
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
        const TXMLEntityNodeInterface* referencedEntityNode = 0;
        return referencedEntityNode;
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
        const TXMLEntityNodeInterface* referencedEntityNode = 0;
        return referencedEntityNode;
    }
    /**
     **********************************************************************
     * Function: EntityReferenceNodeInterface
     *
     *   Author: $author$
     *     Date: 12/16/2008
     **********************************************************************
     */
    virtual TXMLEntityReferenceNodeInterface* EntityReferenceNodeInterface() const
    {
        TXMLEntityReferenceNodeInterface* entityReferenceNode 
        = (TXMLEntityReferenceNodeInterface*)(this);
        return entityReferenceNode;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLEntityReferenceNodeImplement
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
class cXMLEntityReferenceNodeImplement
: virtual public cXMLEntityReferenceNodeImplementT<>
{
public:
    typedef cXMLEntityReferenceNodeImplementT<> cImplements;
    typedef cXMLEntityReferenceNodeImplement cDerives;
};

#endif /* _CXMLENTITYREFERENCENODEINTERFACE_HXX */
