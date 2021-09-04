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
 *   File: cxmlcommentnodeinterface.hxx
 *
 * Author: $author$
 *   Date: 11/14/2008
 **********************************************************************
 */
#ifndef _CXMLCOMMENTNODEINTERFACE_HXX
#define _CXMLCOMMENTNODEINTERFACE_HXX

#include "cxmlcharacterdatanodeinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLCommentNodeInterfaceT"
/**
 **********************************************************************
 *  Class: cXMLCommentNodeInterfaceT
 *
 * Author: $author$
 *   Date: 11/14/2008
 **********************************************************************
 */
template
<class TXMLCharacterDataNodeInterface=cXMLCharacterDataNodeInterface,
 class TImplements=TXMLCharacterDataNodeInterface>
 
class c_INTERFACE_CLASS cXMLCommentNodeInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLCommentNodeInterfaceT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLCommentNodeInterface
 *
 * Author: $author$
 *   Date: 11/15/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLCommentNodeInterface
: virtual public cXMLCommentNodeInterfaceT<>
{
public:
    typedef cXMLCommentNodeInterfaceT<> cImplements;
    typedef cXMLCommentNodeInterface cDerives;
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 11/14/2008
     **********************************************************************
     */
    static cXMLCommentNodeInterface* CreateInstance
    (cXMLDocumentNodeInterface& documentNode,
     const cXMLChar* textChars, TLENGTH textLength=-1);
};

#undef CDB_CLASS
#define CDB_CLASS "cXMLCommentNodeImplementT"
/**
 **********************************************************************
 *  Class: cXMLCommentNodeImplementT
 *
 * Author: $author$
 *   Date: 12/3/2008
 **********************************************************************
 */
template
<class TXMLCommentNodeInterface=cXMLCommentNodeInterface,
 class TImplements=TXMLCommentNodeInterface>
 
class cXMLCommentNodeImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLCommentNodeImplementT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLCommentNodeImplement
 *
 * Author: $author$
 *   Date: 12/3/2008
 **********************************************************************
 */
class cXMLCommentNodeImplement
: virtual public cXMLCommentNodeImplementT<>
{
public:
    typedef cXMLCommentNodeImplementT<> cImplements;
    typedef cXMLCommentNodeImplement cDerives;
};
#endif /* _CXMLCOMMENTNODEINTERFACE_HXX */
