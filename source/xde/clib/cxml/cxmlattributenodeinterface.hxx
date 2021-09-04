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
 *   File: cxmlattributenodeinterface.hxx
 *
 * Author: $author$
 *   Date: 11/21/2008
 **********************************************************************
 */
#ifndef _CXMLATTRIBUTENODEINTERFACE_HXX
#define _CXMLATTRIBUTENODEINTERFACE_HXX

#include "cxmlnamednodeinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLAttributeNodeInterfaceT"
/**
 **********************************************************************
 *  Class: cXMLAttributeNodeInterfaceT
 *
 * Author: $author$
 *   Date: 11/21/2008
 **********************************************************************
 */
template
<class TXMLDocumentNodeInterface=cXMLDocumentNodeInterface,
 class TXMLAttributeNodeInterface=cXMLAttributeNodeInterface,
 class TXMLNamedNodeInterface=cXMLNamedNodeInterface,
 class TImplements=TXMLNamedNodeInterface>
 
class c_INTERFACE_CLASS cXMLAttributeNodeInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLAttributeNodeInterfaceT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLAttributeNodeInterface
 *
 * Author: $author$
 *   Date: 11/28/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLAttributeNodeInterface
: public cXMLAttributeNodeInterfaceT<>
{
public:
    typedef cXMLAttributeNodeInterfaceT<> cExtends;
    typedef cXMLAttributeNodeInterface cDerives;

    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 11/29/2008
     **********************************************************************
     */
    static cXMLAttributeNodeInterface* CreateInstance
    (cXMLDocumentNodeInterface& documentNode,
     const cXMLChar* nodeNameXMLChars=0, TLENGTH nodeNameLength=-1,
     const cXMLChar* nodeNamespacePrefixXMLChars=0, TLENGTH nodeNamespacePrefixLength=-1,
     const cXMLChar* nodeValueXMLChars=0, TLENGTH nodeValueLength=-1);
};

#undef CDB_CLASS
#define CDB_CLASS "cXMLAttributeNodeImplementT"
/**
 **********************************************************************
 *  Class: cXMLAttributeNodeImplementT
 *
 * Author: $author$
 *   Date: 11/28/2008
 **********************************************************************
 */
template
<class TXMLAttributeNodeInterface=cXMLAttributeNodeInterface,
 class TImplements=TXMLAttributeNodeInterface>
 
class cXMLAttributeNodeImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLAttributeNodeImplementT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLAttributeNodeImplement
 *
 * Author: $author$
 *   Date: 11/28/2008
 **********************************************************************
 */
class cXMLAttributeNodeImplement
: virtual public cInterface,
  public cXMLAttributeNodeImplementT<>
{
public:
    typedef cInterface cImplements;
    typedef cXMLAttributeNodeImplementT<> cExtends;
    typedef cXMLAttributeNodeImplement cDerives;
};

#endif /* _CXMLATTRIBUTENODEINTERFACE_HXX */
