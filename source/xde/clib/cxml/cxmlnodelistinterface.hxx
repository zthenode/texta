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
 *   File: cxmlnodelistinterface.hxx
 *
 * Author: $author$
 *   Date: 11/5/2008
 **********************************************************************
 */
#ifndef _CXMLNODELISTINTERFACE_HXX
#define _CXMLNODELISTINTERFACE_HXX

#include "cxmlnodeinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLNodeListInterfaceT"
/**
 **********************************************************************
 *  Class: cXMLNodeListInterfaceT
 *
 * Author: $author$
 *   Date: 11/5/2008
 **********************************************************************
 */
template
<class TXMLNodeListInterface=cXMLNodeListInterface,
 class TXMLNodeInterface=cXMLNodeInterface,
 class TImplements=cInterface>
 
class c_INTERFACE_CLASS cXMLNodeListInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLNodeListInterfaceT cDerives;

    /**
     **********************************************************************
     * Function: Length
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TLENGTH Length() const = 0;

    /**
     **********************************************************************
     * Function: FirstItem
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* FirstItem() const = 0;
    /**
     **********************************************************************
     * Function: LastItem
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* LastItem() const = 0;
    /**
     **********************************************************************
     * Function: Item
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* Item
    (TLENGTH index=-1) const = 0;

    /**
     **********************************************************************
     * Function: AppendItem
     *
     *   Author: $author$
     *     Date: 11/13/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* AppendItem
    (TXMLNodeInterface& xmlNode) = 0;
    /**
     **********************************************************************
     * Function: RemoveItem
     *
     *   Author: $author$
     *     Date: 11/13/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* RemoveItem
    (TXMLNodeInterface& xmlNode) = 0;

    /**
     **********************************************************************
     * Function: PushItem
     *
     *   Author: $author$
     *     Date: 12/5/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* PushItem
    (TXMLNodeInterface& xmlNode) = 0;
    /**
     **********************************************************************
     * Function: PopItem
     *
     *   Author: $author$
     *     Date: 12/5/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* PopItem() = 0;
    /**
     **********************************************************************
     * Function: PullItem
     *
     *   Author: $author$
     *     Date: 12/5/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* PullItem() = 0;

    /**
     **********************************************************************
     * Function: AppendItems
     *
     *   Author: $author$
     *     Date: 11/30/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* AppendItems
    (TXMLNodeInterface& firstNode, TXMLNodeInterface& lastNode) = 0;
    /**
     **********************************************************************
     * Function: RemoveItems
     *
     *   Author: $author$
     *     Date: 11/30/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* RemoveItems
    (TXMLNodeInterface& firstNode, TXMLNodeInterface& lastNode) = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLNodeListInterface
 *
 * Author: $author$
 *   Date: 11/11/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLNodeListInterface
: virtual public cXMLNodeListInterfaceT<>
{
public:
    typedef cXMLNodeListInterfaceT<> cImplements;
    typedef cXMLNodeListInterface cDerives;
};

#undef CDB_CLASS
#define CDB_CLASS "cXMLNodeListImplementT"
/**
 **********************************************************************
 *  Class: cXMLNodeListImplementT
 *
 * Author: $author$
 *   Date: 11/6/2008
 **********************************************************************
 */
template
<class TXMLNodeListInterface=cXMLNodeListInterface,
 class TXMLNodeInterface=cXMLNodeInterface>
 
class cXMLNodeListImplementT
: virtual public TXMLNodeListInterface
{
public:
    typedef TXMLNodeListInterface cImplements;
    typedef cXMLNodeListImplementT cDerives;

    /**
     **********************************************************************
     * Function: Length
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TLENGTH Length() const 
    {
        TLENGTH length = 0;
        return length;
    }

    /**
     **********************************************************************
     * Function: FirstItem
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* FirstItem() const 
    {
        TXMLNodeInterface* xmlNode = 0;
        return xmlNode;
    }
    /**
     **********************************************************************
     * Function: LastItem
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* LastItem() const 
    {
        TXMLNodeInterface* xmlNode = 0;
        return xmlNode;
    }
    /**
     **********************************************************************
     * Function: Item
     *
     *   Author: $author$
     *     Date: 11/6/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* Item
    (TLENGTH index=-1) const 
    {
        TXMLNodeInterface* xmlNode = 0;
        return xmlNode;
    }

    /**
     **********************************************************************
     * Function: AppendItem
     *
     *   Author: $author$
     *     Date: 11/13/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* AppendItem
    (TXMLNodeInterface& xmlNode) 
    {
        TXMLNodeInterface* memberXmlNodeInterface = 0;
        return memberXmlNodeInterface;
    }
    /**
     **********************************************************************
     * Function: RemoveItem
     *
     *   Author: $author$
     *     Date: 11/13/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* RemoveItem
    (TXMLNodeInterface& xmlNode) 
    {
        TXMLNodeInterface* memberXmlNodeInterface = 0;
        return memberXmlNodeInterface;
    }

    /**
     **********************************************************************
     * Function: PushItem
     *
     *   Author: $author$
     *     Date: 12/5/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* PushItem
    (TXMLNodeInterface& xmlNode) 
    {
        TXMLNodeInterface* memberXmlNodeInterface = 0;
        return memberXmlNodeInterface;
    }
    /**
     **********************************************************************
     * Function: PopItem
     *
     *   Author: $author$
     *     Date: 12/5/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* PopItem() 
    {
        TXMLNodeInterface* memberXmlNodeInterface = 0;
        return memberXmlNodeInterface;
    }
    /**
     **********************************************************************
     * Function: PullItem
     *
     *   Author: $author$
     *     Date: 12/5/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* PullItem() 
    {
        TXMLNodeInterface* memberXmlNodeInterface = 0;
        return memberXmlNodeInterface;
    }

    /**
     **********************************************************************
     * Function: AppendItems
     *
     *   Author: $author$
     *     Date: 11/30/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* AppendItems
    (TXMLNodeInterface& firstNode, TXMLNodeInterface& lastNode) 
    {
        TXMLNodeInterface* memberXmlNodeInterface = 0;
        return memberXmlNodeInterface;
    }
    /**
     **********************************************************************
     * Function: RemoveItems
     *
     *   Author: $author$
     *     Date: 11/30/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* RemoveItems
    (TXMLNodeInterface& firstNode, TXMLNodeInterface& lastNode) 
    {
        TXMLNodeInterface* memberXmlNodeInterface = 0;
        return memberXmlNodeInterface;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLNodeListImplement
 *
 * Author: $author$
 *   Date: 11/11/2008
 **********************************************************************
 */
class cXMLNodeListImplement
: virtual public cXMLNodeListImplementT<>
{
public:
    typedef cXMLNodeListImplementT<> cImplements;
    typedef cXMLNodeListImplement cDerives;
};
#endif /* _CXMLNODELISTINTERFACE_HXX */
