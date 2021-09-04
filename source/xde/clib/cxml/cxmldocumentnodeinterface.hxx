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
 *   File: cxmldocumentnodeinterface.hxx
 *
 * Author: $author$
 *   Date: 11/18/2008
 **********************************************************************
 */
#ifndef _CXMLDOCUMENTNODEINTERFACE_HXX
#define _CXMLDOCUMENTNODEINTERFACE_HXX

#include "cxmlnodeinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLDocumentNodeInterfaceT"
/**
 **********************************************************************
 *  Class: cXMLDocumentNodeInterfaceT
 *
 * Author: $author$
 *   Date: 11/18/2008
 **********************************************************************
 */
template
<class TXMLNodeInterface=cXMLNodeInterface,
 class TImplements=TXMLNodeInterface>
 
class c_INTERFACE_CLASS cXMLDocumentNodeInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLDocumentNodeInterfaceT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLDocumentNodeInterface
 *
 * Author: $author$
 *   Date: 11/18/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLDocumentNodeInterface
: virtual public cXMLDocumentNodeInterfaceT<>
{
public:
    typedef cXMLDocumentNodeInterfaceT<> cImplements;
    typedef cXMLDocumentNodeInterface cDerives;
};

#undef CDB_CLASS
#define CDB_CLASS "cXMLDocumentNodeImplementT"
/**
 **********************************************************************
 *  Class: cXMLDocumentNodeImplementT
 *
 * Author: $author$
 *   Date: 11/18/2008
 **********************************************************************
 */
template
<class TXMLDocumentNodeInterface=cXMLDocumentNodeInterface,
 class TImplements=TXMLDocumentNodeInterface>
 
class cXMLDocumentNodeImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLDocumentNodeImplementT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cXMLDocumentNodeImplement
 *
 *  Author: $author$
 *    Date: 11/18/2008
 **********************************************************************
 */
typedef cXMLDocumentNodeImplementT<>
cXMLDocumentNodeImplement;

#endif /* _CXMLDOCUMENTNODEINTERFACE_HXX */
