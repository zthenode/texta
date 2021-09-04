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
 *   Date: 11/16/2008
 **********************************************************************
 */
#ifndef _CXMLBEGINELEMENTNODEINTERFACE_HXX
#define _CXMLBEGINELEMENTNODEINTERFACE_HXX

#include "cxmlelementnodeinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLBeginElementNodeInterfaceT"
/**
 **********************************************************************
 *  Class: cXMLBeginElementNodeInterfaceT
 *
 * Author: $author$
 *   Date: 11/16/2008
 **********************************************************************
 */
template
<class TXMLDocumentNodeInterface=cXMLDocumentNodeInterface,
 class TXMLBeginElementNodeInterface=cXMLBeginElementNodeInterface,
 class TXMLElementNodeInterface=cXMLElementNodeInterface,
 class TImplements=TXMLElementNodeInterface>
 
class c_INTERFACE_CLASS cXMLBeginElementNodeInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLBeginElementNodeInterfaceT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLBeginElementNodeInterface
 *
 * Author: $author$
 *   Date: 11/18/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLBeginElementNodeInterface
: virtual public cXMLBeginElementNodeInterfaceT<>
{
public:
    typedef cXMLBeginElementNodeInterfaceT<> cImplements;
    typedef cXMLBeginElementNodeInterface cDerives;
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 11/16/2008
     **********************************************************************
     */
    static cXMLBeginElementNodeInterface* CreateInstance
    (cXMLDocumentNodeInterface& documentNode,
     const cXMLChar* nameChars, TLENGTH nameLength=-1,
     const cXMLChar* prefixChars=0, TLENGTH prefixLength=-1,
     const cXMLChar* suffixChars=0, TLENGTH suffixLength=-1);
}; 
#endif /* _CXMLBEGINELEMENTNODEINTERFACE_HXX */
