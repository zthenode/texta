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
 *   File: cxmltextnode.hxx
 *
 * Author: $author$
 *   Date: 12/3/2008
 **********************************************************************
 */
#ifndef _CXMLTEXTNODE_HXX
#define _CXMLTEXTNODE_HXX

#include "cxmltextnodeinterface.hxx"
#include "cxmlcharacterdatanode.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLTextNodeT"
/**
 **********************************************************************
 *  Class: cXMLTextNodeT
 *
 * Author: $author$
 *   Date: 12/3/2008
 **********************************************************************
 */
template
<class TXMLCharacterDataNode=cXMLCharacterDataNode,
 class TXMLTextNodeInterface=cXMLTextNodeInterface,
 class TXMLTextNodeImplement=cXMLTextNodeImplement,
 class TImplements=TXMLTextNodeImplement,
 class TExtends=TXMLCharacterDataNode>
 
class cXMLTextNodeT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cXMLTextNodeT cDerives;

    /**
     **********************************************************************
     * Constructor: cXMLTextNodeT
     *
     *      Author: $author$
     *        Date: 12/3/2008
     **********************************************************************
     */
    cXMLTextNodeT
    (const cXMLChar* textChars=0, TLENGTH textLength=-1) 
    : cExtends
      (e_XML_NODE_TYPE_VALUE_TEXT,
       textChars, textLength)
    {
    }
    /**
     **********************************************************************
     * Constructor: cXMLTextNodeT
     *
     *      Author: $author$
     *        Date: 12/16/2008
     **********************************************************************
     */
    cXMLTextNodeT
    (const char* textChars, TLENGTH textLength=-1) 
    : cExtends
      (e_XML_NODE_TYPE_VALUE_TEXT,
       textChars, textLength)
    {
    }
    /**
     **********************************************************************
     * Function: TextNodeInterface
     *
     *   Author: $author$
     *     Date: 12/14/2008
     **********************************************************************
     */
    virtual TXMLTextNodeInterface* TextNodeInterface() const 
    {
        TXMLTextNodeInterface* xmlNode = (TXMLTextNodeInterface*)(this);
        return xmlNode;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLTextNode
 *
 * Author: $author$
 *   Date: 12/3/2008
 **********************************************************************
 */
class cXMLTextNode
: public cXMLTextNodeT<>
{
public:
    typedef cXMLTextNodeT<> cExtends;
    typedef cXMLTextNode cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLTextNode
     *
     *      Author: $author$
     *        Date: 12/3/2008
     **********************************************************************
     */
    cXMLTextNode
    (const cXMLChar* textChars=0, TLENGTH textLength=-1) 
    : cExtends(textChars, textLength)
    {
    }
    /**
     **********************************************************************
     * Constructor: cXMLTextNode
     *
     *      Author: $author$
     *        Date: 12/16/2008
     **********************************************************************
     */
    cXMLTextNode
    (const char* textChars, TLENGTH textLength=-1) 
    : cExtends(textChars, textLength)
    {
    }

    /**
     **********************************************************************
     * Function: TextNode
     *
     *   Author: $author$
     *     Date: 12/3/2008
     **********************************************************************
     */
    virtual cXMLTextNode* TextNode() const 
    {
        cXMLTextNode* xmlNode = (cXMLTextNode*)(this);
        return xmlNode;
    }
};
#endif /* _CXMLTEXTNODE_HXX */
