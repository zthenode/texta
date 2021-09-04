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
 *   File: cxmlcommentnode.hxx
 *
 * Author: $author$
 *   Date: 12/3/2008
 **********************************************************************
 */
#ifndef _CXMLCOMMENTNODE_HXX
#define _CXMLCOMMENTNODE_HXX

#include "cxmlcommentnodeinterface.hxx"
#include "cxmlcharacterdatanode.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLCommentNodeT"
/**
 **********************************************************************
 *  Class: cXMLCommentNodeT
 *
 * Author: $author$
 *   Date: 12/3/2008
 **********************************************************************
 */
template
<class TXMLCharacterDataNode=cXMLCharacterDataNode,
 class TXMLCommentNodeImplement=cXMLCommentNodeImplement,
 class TImplements=TXMLCommentNodeImplement,
 class TExtends=TXMLCharacterDataNode>
 
class cXMLCommentNodeT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cXMLCommentNodeT cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLCommentNodeT
     *
     *      Author: $author$
     *        Date: 12/3/2008
     **********************************************************************
     */
    cXMLCommentNodeT
    (const cXMLChar* textChars=0, TLENGTH textLength=-1) 
    : cExtends
      (e_XML_NODE_TYPE_VALUE_COMMENT,
       textChars, textLength)
    {
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLCommentNode
 *
 * Author: $author$
 *   Date: 12/3/2008
 **********************************************************************
 */
class cXMLCommentNode
: public cXMLCommentNodeT<>
{
public:
    typedef cXMLCommentNodeT<> cExtends;
    typedef cXMLCommentNode cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLCommentNode
     *
     *      Author: $author$
     *        Date: 12/3/2008
     **********************************************************************
     */
    cXMLCommentNode
    (const cXMLChar* textChars=0, TLENGTH textLength=-1) 
    : cExtends(textChars, textLength) 
    {
    }
};
#endif /* _CXMLCOMMENTNODE_HXX */
