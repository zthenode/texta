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
 *   File: csyntax.hxx
 *
 * Author: $author$
 *   Date: 8/3/2008
 **********************************************************************
 */
#ifndef _CSYNTAX_HXX
#define _CSYNTAX_HXX

#include "csyntaxnodetype.hxx"
#include "cstring.hxx"
#include "clist.hxx"

/**
 **********************************************************************
 *  Class: cSyntaxNodeInterface
 *
 * Author: $author$
 *   Date: 8/3/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cSyntaxNodeInterface
: virtual public cInterfaceBase
{
public:
    typedef cInterfaceBase cImplements;
    typedef cSyntaxNodeInterface cDerives;
};

class cSyntaxNode;
/**
 **********************************************************************
 *  Class: cSyntaxNodeItem
 *
 * Author: $author$
 *   Date: 8/3/2008
 **********************************************************************
 */
class cSyntaxNodeItem
: public cListItemT<cSyntaxNodeItem>
{
public:
    typedef cListItemT<cSyntaxNodeItem> cExtends;
    typedef cSyntaxNodeItem cDerives;

    cSyntaxNode& m_node;
    bool m_canDeleteThis;

    /**
     **********************************************************************
     * Constructor: cSyntaxNodeItem
     *
     *      Author: $author$
     *        Date: 8/3/2008
     **********************************************************************
     */
    cSyntaxNodeItem
    (cSyntaxNode& node,
     bool canDeleteThis=false) 
    : m_node(node),
      m_canDeleteThis(canDeleteThis)
    {
    }
    static cSyntaxNodeItem* 
    CreateInstance(cSyntaxNode& node)
    {
        cSyntaxNodeItem* instance 
        = new cSyntaxNodeItem(node, true);
        return instance;
    }
    virtual eError DeleteInstance()
    {
        eError error = DeleteThis();
        return error;
    }
    virtual eError DeleteThis()
    {
        eError error = e_ERROR_NONE;
        if (m_canDeleteThis)
            delete this;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cSyntaxNodeList
 *
 * Author: $author$
 *   Date: 8/3/2008
 **********************************************************************
 */
class cSyntaxNodeList
: public cListT<cSyntaxNodeItem>
{
public:
    typedef cListT<cSyntaxNodeItem> cExtends;
    typedef cSyntaxNodeList cDerives;
    /**
     **********************************************************************
     * Destructor: ~cSyntaxNodeList
     *
     *     Author: $author$
     *       Date: 8/3/2008
     **********************************************************************
     */
    virtual ~cSyntaxNodeList()
    {
        eError error;
        if (error = Clear())
            throw(error);
    }
    virtual eError Swap(cSyntaxNodeList& list)
    {
        eError error = e_ERROR_NONE;
        cSyntaxNodeItem* tempItem = m_firstItem;
        m_firstItem = list.m_firstItem;
        list.m_firstItem = tempItem;
        tempItem = m_lastItem;
        m_lastItem = list.m_lastItem;
        list.m_lastItem = tempItem;
        return error;
    }
    virtual eError Clear()
    {
        eError error = e_ERROR_NONE;
        cSyntaxNodeItem* prevItem;
        cSyntaxNodeItem* item;

        for (prevItem = 0, item = m_lastItem;
             item; item = prevItem)
        {
            prevItem = item->m_prevItem;
            DeleteItem(*item);
            if ((error = item->DeleteInstance()))
                break;
        }
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cSyntaxNode
 *
 * Author: $author$
 *   Date: 8/3/2008
 **********************************************************************
 */
class cSyntaxNode
: virtual public cSyntaxNodeInterface
{
public:
    typedef cSyntaxNodeInterface cImplements;
    typedef cSyntaxNode cDerives;

    cSyntaxNodeItem m_item;
    cSyntaxNodeList m_list;

    eSyntaxNodeType m_type;
    cCharString m_text;
    const char* m_textChars;
    TLENGTH m_textLength;

    /**
     **********************************************************************
     * Constructor: cSyntaxNode
     *
     *      Author: $author$
     *        Date: 8/3/2008
     **********************************************************************
     */
    cSyntaxNode
    (eSyntaxNodeType type=e_SYNTAX_NODE_TYPE_NONE,
     const char* chars=0,
     TLENGTH length=-1) 
    : m_item(*this),
      m_type(type)
    {
        eError error;
        if (chars)
        if (0 > (length = m_text.Assign(chars,length)))
            throw(error = -length);
    }
    virtual eError Out
    (cCharStreamInterface& out)
    {
        switch(m_type)
        {
        case e_SYNTAX_NODE_TYPE_IDENTIFIER:
            if ((m_textChars = GetText(m_textLength)))
                out.WriteL("identify=",m_textChars,"\n",0);
            break;
        case e_SYNTAX_NODE_TYPE_LITERAL_STRING:
            if ((m_textChars = GetText(m_textLength)))
                out.WriteL("litarally=\"",m_textChars,"\"\n",0);
            break;
        case e_SYNTAX_NODE_TYPE_LITERAL_CHAR:
            if ((m_textChars = GetText(m_textLength)))
                out.WriteL("litarally=\'",m_textChars,"\'\n",0);
            break;
        }
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: SetText
     *
     *   Author: $author$
     *     Date: 8/3/2008
     **********************************************************************
     */
    virtual TLENGTH SetText
    (const char* chars,
     TLENGTH length=-1) 
    {
        TLENGTH count = m_text.Assign(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: GetText
     *
     *   Author: $author$
     *     Date: 8/3/2008
     **********************************************************************
     */
    virtual const char* GetText
    (TLENGTH& length) const 
    {
        const char* chars = m_text.Chars(length);
        return chars;
    }
    static cSyntaxNode* CreateInstance
    (eSyntaxNodeType type=e_SYNTAX_NODE_TYPE_NONE,
     const char* chars=0,
     TLENGTH length=-1)
    {
        cSyntaxNode* instance = new cSyntaxNode(type, chars, length);
        return instance;
    }
};
#endif /* _CSYNTAX_HXX */
