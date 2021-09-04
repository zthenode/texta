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
 *   File: cxmlbeginelementnodeinterface.hxx
 *
 * Author: $author$
 *   Date: 12/1/2008
 **********************************************************************
 */
#ifndef _CXMLBEGINELEMENTNODEINTERFACE_HXX
#define _CXMLBEGINELEMENTNODEINTERFACE_HXX

#include "cxmlnamednodeinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLBeginElementNodeInterfaceT"
/**
 **********************************************************************
 *  Class: cXMLBeginElementNodeInterfaceT
 *
 * Author: $author$
 *   Date: 12/1/2008
 **********************************************************************
 */
template
<class TXMLNodeInterface=cXMLNodeInterface,
 class TXMLNamedNodeInterface=cXMLNamedNodeInterface,
 class TImplements=TXMLNamedNodeInterface>
 
class c_INTERFACE_CLASS cXMLBeginElementNodeInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLBeginElementNodeInterfaceT cDerives;

    /**
     **********************************************************************
     * Function: AppendAttributes
     *
     *   Author: $author$
     *     Date: 12/1/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* AppendAttributes
    (TXMLNodeInterface& firstAttribute,
     TXMLNodeInterface& lastAttribute) = 0;
    /**
     **********************************************************************
     * Function: RemoveAttributes
     *
     *   Author: $author$
     *     Date: 12/1/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* RemoveAttributes
    (TXMLNodeInterface& firstAttribute,
     TXMLNodeInterface& lastAttribute) = 0;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLBeginElementNodeInterface
 *
 * Author: $author$
 *   Date: 12/1/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLBeginElementNodeInterface
: public cXMLBeginElementNodeInterfaceT<>
{
public:
    typedef cXMLBeginElementNodeInterfaceT<> cExtends;
    typedef cXMLBeginElementNodeInterface cDerives;
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 12/4/2008
     **********************************************************************
     */
    static cXMLBeginElementNodeInterface* CreateInstance
    (cXMLDocumentNodeInterface& documentNode,
     const cXMLChar* nameChars, TLENGTH nameLength=-1,
     const cXMLChar* nameSpacePrefixChars=0, TLENGTH nameSpacePrefixLength=-1);
}; 

#undef CDB_CLASS
#define CDB_CLASS "cXMLBeginElementNodeImplementT"
/**
 **********************************************************************
 *  Class: cXMLBeginElementNodeImplementT
 *
 * Author: $author$
 *   Date: 12/1/2008
 **********************************************************************
 */
template
<class TXMLNodeInterface=cXMLNodeInterface,
 class TXMLNamedNodeImplement=cXMLNamedNodeImplement,
 class TXMLBeginElementNodeInterface=cXMLBeginElementNodeInterface,
 class TImplements=TXMLBeginElementNodeInterface>
 
class cXMLBeginElementNodeImplementT
: virtual public TXMLNamedNodeImplement,
  virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLBeginElementNodeImplementT cDerives;

    /**
     **********************************************************************
     * Function: AppendAttributes
     *
     *   Author: $author$
     *     Date: 12/1/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* AppendAttributes
    (TXMLNodeInterface& firstAttribute,
     TXMLNodeInterface& lastAttribute) 
    {
        TXMLNodeInterface* attributeNode = 0;
        return attributeNode;
    }
    /**
     **********************************************************************
     * Function: RemoveAttributes
     *
     *   Author: $author$
     *     Date: 12/1/2008
     **********************************************************************
     */
    virtual TXMLNodeInterface* RemoveAttributes
    (TXMLNodeInterface& firstAttribute,
     TXMLNodeInterface& lastAttribute) 
    {
        TXMLNodeInterface* attributeNode = 0;
        return attributeNode;
    }

    /**
     **********************************************************************
     * Function: BeginElementNodeInterface
     *
     *   Author: $author$
     *     Date: 12/6/2008
     **********************************************************************
     */
    virtual TXMLBeginElementNodeInterface* BeginElementNodeInterface() const 
    {
        TXMLBeginElementNodeInterface* xmlNode = (TXMLBeginElementNodeInterface*)(this);
        return xmlNode;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLBeginElementNodeImplement
 *
 * Author: $author$
 *   Date: 12/1/2008
 **********************************************************************
 */
class cXMLBeginElementNodeImplement
: virtual public cXMLBeginElementNodeImplementT<>
{
public:
    typedef cXMLBeginElementNodeImplementT<> cImplements;
    typedef cXMLBeginElementNodeImplement cDerives;
};

#endif /* _CXMLBEGINELEMENTNODEINTERFACE_HXX */
