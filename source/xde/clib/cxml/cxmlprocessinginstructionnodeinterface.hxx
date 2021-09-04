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
 *   File: cxmlprocessinginstructionnodeinterface.hxx
 *
 * Author: $author$
 *   Date: 12/4/2008
 **********************************************************************
 */
#ifndef _CXMLPROCESSINGINSTRUCTIONNODEINTERFACE_HXX
#define _CXMLPROCESSINGINSTRUCTIONNODEINTERFACE_HXX

#include "cxmlnodeinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLProcessingInstructionNodeInterfaceT"
/**
 **********************************************************************
 *  Class: cXMLProcessingInstructionNodeInterfaceT
 *
 * Author: $author$
 *   Date: 12/4/2008
 **********************************************************************
 */
template
<class TXMLNodeInterface=cXMLNodeInterface,
 class TImplements=TXMLNodeInterface>
 
class c_INTERFACE_CLASS cXMLProcessingInstructionNodeInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLProcessingInstructionNodeInterfaceT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLProcessingInstructionNodeInterface
 *
 * Author: $author$
 *   Date: 12/4/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLProcessingInstructionNodeInterface
: virtual public cXMLProcessingInstructionNodeInterfaceT<>
{
public:
    typedef cXMLProcessingInstructionNodeInterfaceT<> cImplements;
    typedef cXMLProcessingInstructionNodeInterface cDerives;
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 12/4/2008
     **********************************************************************
     */
    static cXMLProcessingInstructionNodeInterface* CreateInstance
    (cXMLDocumentNodeInterface& documentNode,
     const cXMLChar* textChars, TLENGTH textLength=-1);
};

#undef CDB_CLASS
#define CDB_CLASS "cXMLProcessingInstructionNodeImplementT"
/**
 **********************************************************************
 *  Class: cXMLProcessingInstructionNodeImplementT
 *
 * Author: $author$
 *   Date: 12/4/2008
 **********************************************************************
 */
template
<class TXMLProcessingInstructionNodeInterface=cXMLProcessingInstructionNodeInterface,
 class TImplements=TXMLProcessingInstructionNodeInterface>
 
class cXMLProcessingInstructionNodeImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cXMLProcessingInstructionNodeImplementT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLProcessingInstructionNodeImplement
 *
 * Author: $author$
 *   Date: 12/4/2008
 **********************************************************************
 */
class cXMLProcessingInstructionNodeImplement
: virtual public cInterface,
  public cXMLProcessingInstructionNodeImplementT<>
{
public:
    typedef cInterface cImplements;
    typedef cXMLProcessingInstructionNodeImplementT<> cExtends;
    typedef cXMLProcessingInstructionNodeImplement cDerives;
};
#endif /* _CXMLPROCESSINGINSTRUCTIONNODEINTERFACE_HXX */
