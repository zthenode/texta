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
 *   File: cxmlendelementnodeinterface.hxx
 *
 * Author: $author$
 *   Date: 11/16/2008
 **********************************************************************
 */
#ifndef _CXMLENDELEMENTNODEINTERFACE_HXX
#define _CXMLENDELEMENTNODEINTERFACE_HXX

#include "cxmlnamednodeinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLEndElementNodeInterfaceT"
/**
 **********************************************************************
 *  Class: cXMLEndElementNodeInterfaceT
 *
 * Author: $author$
 *   Date: 11/16/2008
 **********************************************************************
 */
template
<class TXMLNamedNodeInterface=cXMLNamedNodeInterface,
 class TImplements=TXMLNamedNodeInterface>
 
class c_INTERFACE_CLASS cXMLEndElementNodeInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLEndElementNodeInterfaceT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLEndElementNodeInterface
 *
 * Author: $author$
 *   Date: 11/18/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLEndElementNodeInterface
: virtual public cXMLEndElementNodeInterfaceT<>
{
public:
    typedef cXMLEndElementNodeInterfaceT<> cImplements;
    typedef cXMLEndElementNodeInterface cDerives;
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 11/16/2008
     **********************************************************************
     */
    static cXMLEndElementNodeInterface* CreateInstance
    (cXMLDocumentNodeInterface& documentNode,
     const cXMLChar* nameChars, TLENGTH nameLength=-1,
     const cXMLChar* nameSpacePrefixChars=0, TLENGTH nameSpacePrefixLength=-1);
};

#undef CDB_CLASS
#define CDB_CLASS "cXMLEndElementNodeImplementT"
/**
 **********************************************************************
 *  Class: cXMLEndElementNodeImplementT
 *
 * Author: $author$
 *   Date: 12/4/2008
 **********************************************************************
 */
template
<class TXMLEndElementNodeInterface=cXMLEndElementNodeInterface,
 class TXMLNamedNodeImplement=cXMLNamedNodeImplement,
 class TImplements=TXMLEndElementNodeInterface>
 
class cXMLEndElementNodeImplementT
: virtual public TXMLNamedNodeImplement,
  virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLEndElementNodeImplementT cDerives;
    /**
     **********************************************************************
     * Function: EndElementNodeInterface
     *
     *   Author: $author$
     *     Date: 12/6/2008
     **********************************************************************
     */
    virtual TXMLEndElementNodeInterface* EndElementNodeInterface() const 
    {
        TXMLEndElementNodeInterface* xmlNode = (TXMLEndElementNodeInterface*)(this);
        return xmlNode;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLEndElementNodeImplement
 *
 * Author: $author$
 *   Date: 12/4/2008
 **********************************************************************
 */
class cXMLEndElementNodeImplement
: public cXMLEndElementNodeImplementT<>
{
public:
    typedef cXMLEndElementNodeImplementT<> cExtends;
    typedef cXMLEndElementNodeImplement cDerives;
};

#endif /* _CXMLENDELEMENTNODEINTERFACE_HXX */
