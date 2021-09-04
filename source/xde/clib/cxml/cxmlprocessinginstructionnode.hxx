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
 *   File: cxmlprocessinginstructionnode.hxx
 *
 * Author: $author$
 *   Date: 12/4/2008
 **********************************************************************
 */
#ifndef _CXMLPROCESSINGINSTRUCTIONNODE_HXX
#define _CXMLPROCESSINGINSTRUCTIONNODE_HXX

#include "cxmlprocessinginstructionnodeinterface.hxx"
#include "cxmlnode.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLProcessingInstructionNodeT"
/**
 **********************************************************************
 *  Class: cXMLProcessingInstructionNodeT
 *
 * Author: $author$
 *   Date: 12/4/2008
 **********************************************************************
 */
template
<class TXMLNode=cXMLNode,
 class TXMLProcessingInstructionNodeImplement=cXMLProcessingInstructionNodeImplement,
 class TImplements=TXMLProcessingInstructionNodeImplement,
 class TExtends=TXMLNode>
 
class cXMLProcessingInstructionNodeT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cXMLProcessingInstructionNodeT cDerives;

    /**
     **********************************************************************
     * Constructor: cXMLProcessingInstructionNodeT
     *
     *      Author: $author$
     *        Date: 12/4/2008
     **********************************************************************
     */
    cXMLProcessingInstructionNodeT
    (const cXMLChar* textChars=0, TLENGTH textLength=-1) 
    : cExtends(e_XML_NODE_TYPE_VALUE_PROCESSING_INSTRUCTION)
    {
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLProcessingInstructionNode
 *
 * Author: $author$
 *   Date: 12/4/2008
 **********************************************************************
 */
class cXMLProcessingInstructionNode
: public cXMLProcessingInstructionNodeT<>
{
public:
    typedef cXMLProcessingInstructionNodeT<> cExtends;
    typedef cXMLProcessingInstructionNode cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLProcessingInstructionNode
     *
     *      Author: $author$
     *        Date: 12/4/2008
     **********************************************************************
     */
    cXMLProcessingInstructionNode
    (const cXMLChar* textChars=0, TLENGTH textLength=-1) 
    : cExtends(textChars, textLength) 
    {
    }
};

#endif /* _CXMLPROCESSINGINSTRUCTIONNODE_HXX */
