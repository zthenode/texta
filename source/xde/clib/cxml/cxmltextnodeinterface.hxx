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
 *   File: cxmltextnodeinterface.hxx
 *
 * Author: $author$
 *   Date: 11/14/2008
 **********************************************************************
 */
#ifndef _CXMLTEXTNODEINTERFACE_HXX
#define _CXMLTEXTNODEINTERFACE_HXX

#include "cxmlcharacterdatanodeinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLTextNodeInterfaceT"
/**
 **********************************************************************
 *  Class: cXMLTextNodeInterfaceT
 *
 * Author: $author$
 *   Date: 11/14/2008
 **********************************************************************
 */
template
<class TXMLTextNodeInterface=cXMLTextNodeInterface,
 class TXMLDocumentNodeInterface=cXMLDocumentNodeInterface,
 class TXMLCharacterDataNodeInterface=cXMLCharacterDataNodeInterface,
 class TImplements=TXMLCharacterDataNodeInterface>
 
class c_INTERFACE_CLASS cXMLTextNodeInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLTextNodeInterfaceT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLTextNodeInterface
 *
 * Author: $author$
 *   Date: 11/14/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLTextNodeInterface
: virtual public cXMLTextNodeInterfaceT<>
{
public:
    typedef cXMLTextNodeInterfaceT<> cImplements;
    typedef cXMLTextNodeInterface cDerives;
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 11/14/2008
     **********************************************************************
     */
    static cXMLTextNodeInterface* CreateInstance
    (cXMLDocumentNodeInterface& documentNode,
     const cXMLChar* textChars, TLENGTH textLength=-1);
};

#undef CDB_CLASS
#define CDB_CLASS "cXMLTextNodeImplementT"
/**
 **********************************************************************
 *  Class: cXMLTextNodeImplementT
 *
 * Author: $author$
 *   Date: 12/3/2008
 **********************************************************************
 */
template
<class TXMLCharacterDataNodeImplement=cXMLCharacterDataNodeImplement,
 class TXMLTextNodeInterface=cXMLTextNodeInterface,
 class TImplements=TXMLTextNodeInterface>
 
class cXMLTextNodeImplementT
: virtual public TXMLCharacterDataNodeImplement,
  virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLTextNodeImplementT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLTextNodeImplement
 *
 * Author: $author$
 *   Date: 12/3/2008
 **********************************************************************
 */
class cXMLTextNodeImplement
: public cXMLTextNodeImplementT<>
{
public:
    typedef cXMLTextNodeImplementT<> cExtends;
    typedef cXMLTextNodeImplement cDerives;
};

#endif /* _CXMLTEXTNODEINTERFACE_HXX */
