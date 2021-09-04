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
 *   File: cxmlelementnodeinterface.hxx
 *
 * Author: $author$
 *   Date: 11/15/2008
 **********************************************************************
 */
#ifndef _CXMLELEMENTNODEINTERFACE_HXX
#define _CXMLELEMENTNODEINTERFACE_HXX

#include "cxmlbeginelementnodeinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLElementNodeInterfaceT"
/**
 **********************************************************************
 *  Class: cXMLElementNodeInterfaceT
 *
 * Author: $author$
 *   Date: 11/15/2008
 **********************************************************************
 */
template
<class TXMLElementNode=cXMLElementNode,
 class TXMLElementNodeInterface=cXMLElementNodeInterface,
 class TXMLBeginElementNodeInterface=cXMLBeginElementNodeInterface,
 class TImplements=TXMLBeginElementNodeInterface>
 
class c_INTERFACE_CLASS cXMLElementNodeInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLElementNodeInterfaceT cDerives;

    /**
     **********************************************************************
     * Function: ElementNode
     *
     *   Author: $author$
     *     Date: 12/1/2008
     **********************************************************************
     */
    virtual TXMLElementNode* ElementNode() const = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLElementNodeInterface
 *
 * Author: $author$
 *   Date: 11/15/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLElementNodeInterface
: virtual public cXMLElementNodeInterfaceT<>
{
public:
    typedef cXMLElementNodeInterfaceT<> cImplements;
    typedef cXMLElementNodeInterface cDerives;
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 11/15/2008
     **********************************************************************
     */
    static cXMLElementNodeInterface* CreateInstance
    (cXMLDocumentNodeInterface& documentNode,
     const cXMLChar* nameChars, TLENGTH nameLength=-1,
     const cXMLChar* namespacePrefixChars=0, TLENGTH namespacePrefixLength=-1);
};

#undef CDB_CLASS
#define CDB_CLASS "cXMLElementNodeImplementT"
/**
 **********************************************************************
 *  Class: cXMLElementNodeImplementT
 *
 * Author: $author$
 *   Date: 11/15/2008
 **********************************************************************
 */
template
<class TXMLElementNode=cXMLElementNode,
 class TXMLBeginElementNodeImplement=cXMLBeginElementNodeImplement,
 class TXMLElementNodeInterface=cXMLElementNodeInterface,
 class TImplements=TXMLElementNodeInterface>
 
class cXMLElementNodeImplementT
: virtual public TXMLBeginElementNodeImplement,
  virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLElementNodeImplementT cDerives;

    /**
     **********************************************************************
     * Function: ElementNode
     *
     *   Author: $author$
     *     Date: 12/1/2008
     **********************************************************************
     */
    virtual TXMLElementNode* ElementNode() const 
    {
        TXMLElementNode* elementNode = 0;
        return elementNode;
    }
    /**
     **********************************************************************
     * Function: ElementNodeInterface
     *
     *   Author: $author$
     *     Date: 12/6/2008
     **********************************************************************
     */
    virtual TXMLElementNodeInterface* ElementNodeInterface() const 
    {
        TXMLElementNodeInterface* xmlNode = (TXMLElementNodeInterface*)(this);
        return xmlNode;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLElementNodeImplement
 *
 * Author: $author$
 *   Date: 12/1/2008
 **********************************************************************
 */
class cXMLElementNodeImplement
: virtual public cXMLElementNodeImplementT<>
{
public:
    typedef cXMLElementNodeImplementT<> cImplements;
    typedef cXMLElementNodeImplement cDerives;
};

#endif /* _CXMLELEMENTNODEINTERFACE_HXX */
