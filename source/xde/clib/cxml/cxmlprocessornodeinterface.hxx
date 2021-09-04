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
 *   File: cxmlprocessornodeinterface.hxx
 *
 * Author: $author$
 *   Date: 11/15/2008
 **********************************************************************
 */
#ifndef _CXMLPROCESSORNODEINTERFACE_HXX
#define _CXMLPROCESSORNODEINTERFACE_HXX

#include "cxmlnodeinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLProcessorNodeInterfaceT"
/**
 **********************************************************************
 *  Class: cXMLProcessorNodeInterfaceT
 *
 * Author: $author$
 *   Date: 11/15/2008
 **********************************************************************
 */
template
<class TXMLDocumentNodeInterface=cXMLDocumentNodeInterface,
 class TXMLProcessorNodeInterface=cXMLProcessorNodeInterface,
 class TXMLNodeInterface=cXMLNodeInterface,
 class TImplements=TXMLNodeInterface>
 
class c_INTERFACE_CLASS cXMLProcessorNodeInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLProcessorNodeInterfaceT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLProcessorNodeInterface
 *
 * Author: $author$
 *   Date: 11/15/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLProcessorNodeInterface
: virtual public cXMLProcessorNodeInterfaceT<>
{
public:
    typedef cXMLProcessorNodeInterfaceT<> cImplements;
    typedef cXMLProcessorNodeInterface cDerives;
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 11/14/2008
     **********************************************************************
     */
    static cXMLProcessorNodeInterface* CreateInstance
    (cXMLDocumentNodeInterface& documentNode,
     const cXMLChar* textChars, TLENGTH textLength=-1);
};

#endif /* _CXMLPROCESSORNODEINTERFACE_HXX */
