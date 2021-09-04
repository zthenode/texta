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
 *   File: cxmlentitynodeinterface.hxx
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
#ifndef _CXMLENTITYNODEINTERFACE_HXX
#define _CXMLENTITYNODEINTERFACE_HXX

#include "cxmlnodeinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLEntityNodeInterfaceT"
/**
 **********************************************************************
 *  Class: cXMLEntityNodeInterfaceT
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
template
<class TXMLNodeInterface=cXMLNodeInterface,
 class TImplements=TXMLNodeInterface>
 
class c_INTERFACE_CLASS cXMLEntityNodeInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLEntityNodeInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: PublicId
     *
     *   Author: $author$
     *     Date: 12/16/2008
     **********************************************************************
     */
    virtual const cXMLString* PublicId() const = 0;
    /**
     **********************************************************************
     * Function: SystemId
     *
     *   Author: $author$
     *     Date: 12/16/2008
     **********************************************************************
     */
    virtual const cXMLString* SystemId() const = 0;
    /**
     **********************************************************************
     * Function: NotationName
     *
     *   Author: $author$
     *     Date: 12/16/2008
     **********************************************************************
     */
    virtual const cXMLString* NotationName() const = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLEntityNodeInterface
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLEntityNodeInterface
: public cXMLEntityNodeInterfaceT<>
{
public:
    typedef cXMLEntityNodeInterfaceT<> cExtends;
    typedef cXMLEntityNodeInterface cDerives;
};

#undef CDB_CLASS
#define CDB_CLASS "cXMLEntityNodeImplementT"
/**
 **********************************************************************
 *  Class: cXMLEntityNodeImplementT
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
template
<class TXMLNodeImplement=cXMLNodeImplement,
 class TXMLEntityNodeInterface=cXMLEntityNodeInterface,
 class TImplements=TXMLEntityNodeInterface>
 
class cXMLEntityNodeImplementT
: virtual public TXMLNodeImplement,
  virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLEntityNodeImplementT cDerives;
    /**
     **********************************************************************
     * Function: PublicId
     *
     *   Author: $author$
     *     Date: 12/16/2008
     **********************************************************************
     */
    virtual const cXMLString* PublicId() const 
    {
        const cXMLString* xmlString = 0;
        return xmlString;
    }
    /**
     **********************************************************************
     * Function: SystemId
     *
     *   Author: $author$
     *     Date: 12/16/2008
     **********************************************************************
     */
    virtual const cXMLString* SystemId() const 
    {
        const cXMLString* xmlString = 0;
        return xmlString;
    }
    /**
     **********************************************************************
     * Function: NotationName
     *
     *   Author: $author$
     *     Date: 12/16/2008
     **********************************************************************
     */
    virtual const cXMLString* NotationName() const 
    {
        const cXMLString* xmlString = 0;
        return xmlString;
    }
    /**
     **********************************************************************
     * Function: EntityNodeInterface
     *
     *   Author: $author$
     *     Date: 12/16/2008
     **********************************************************************
     */
    virtual TXMLEntityNodeInterface* EntityNodeInterface() const 
    {
        TXMLEntityNodeInterface* entityNode 
        = (TXMLEntityNodeInterface*)(this);
        return entityNode;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLEntityNodeImplement
 *
 * Author: $author$
 *   Date: 12/16/2008
 **********************************************************************
 */
class cXMLEntityNodeImplement
: public cXMLEntityNodeImplementT<>
{
public:
    typedef cXMLEntityNodeImplementT<> cExtends;
    typedef cXMLEntityNodeImplement cDerives;
};
#endif /* _CXMLENTITYNODEINTERFACE_HXX */
