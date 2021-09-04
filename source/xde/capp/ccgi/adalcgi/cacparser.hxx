/**
 **********************************************************************
 * Copyright (c) 1988-2008 $author$
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
 *   File: cacparser.hxx
 *
 * Author: $author$
 *   Date: 7/31/2008
 **********************************************************************
 */
#ifndef _CACPARSER_HXX
#define _CACPARSER_HXX

#include "csyntax.hxx"
#include "caclexer.hxx"

#undef yyIsParser
#undef yyParser
#define yyIsParser cIsACParser
#define yyParser cACParser
#include "yyparser.hxx"

/**
 **********************************************************************
 *  Class: cACParser
 *
 * Author: $author$
 *   Date: 7/31/2008
 **********************************************************************
 */
class cACParser
: public cIsACParser
{
public:
    typedef cIsACParser cExtends;
    typedef cACParser cDerives;

    cCharStreamInterface& m_out;
    cACLexer m_lexer;

    cSyntaxNodeList m_exprNodeStack;
    cSyntaxNodeList m_syntaxNodeStack;
    cSyntaxNodeList m_syntaxNodeList;
    cSyntaxNodeItem* m_syntaxNodeItem;
    cSyntaxNodeItem* m_syntaxNodeItem2;
    cSyntaxNodeItem* m_syntaxNodeItem3;
    cSyntaxNode* m_syntaxNode;

    eSyntaxNodeType m_nodeType;
    const char* m_nodeText;
    const char* m_nodeText2;
    const char* m_nodeText3;
    TLENGTH m_nodeTextLength;

    /**
     **********************************************************************
     * Constructor: cACParser
     *
     *      Author: $author$
     *        Date: 7/31/2008
     **********************************************************************
     */
    cACParser
    (cACLexerDelegate& lexerDelegate,
     cCharStreamInterface& out, 
     cCharStreamInterface& in, 
     cLexerSource &source) 
    : m_out(out),
      m_lexer(lexerDelegate, out, in, source)
    {
    }

    /* Function: OnIdentifier
     */
    virtual eError OnIdentifier()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnIdentifier()...\n");
        On(e_SYNTAX_NODE_TYPE_IDENTIFIER);
        return error;
    }
    /* Function: OnLiteralInteger
     */
    virtual eError OnLiteralInteger()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnLiteralInteger()...\n");
        On(e_SYNTAX_NODE_TYPE_LITERAL_INTEGER);
        return error;
    }
    /* Function: OnLiteralReal
     */
    virtual eError OnLiteralReal()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnLiteralReal()...\n");
        On(e_SYNTAX_NODE_TYPE_LITERAL_REAL);
        return error;
    }
    /* Function: OnLiteralString
     */
    virtual eError OnLiteralString()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnLiteralString()...\n");
        On(e_SYNTAX_NODE_TYPE_LITERAL_STRING);
        return error;
    }
    /* Function: OnLiteralChar
     */
    virtual eError OnLiteralChar()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnLiteralChar()...\n");
        On(e_SYNTAX_NODE_TYPE_LITERAL_CHAR);
        return error;
    }

    /* Function: OnAssignmentOp
     */
    virtual eError OnAssignmentOp()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnAssignmentOp()...\n");
        return error;
    }
    /* Function: OnAssignmentUnop
     */
    virtual eError OnAssignmentUnop()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnAssignmentUnop()...\n");
        return error;
    }
    /* Function: OnOp
     */
    virtual eError OnOp
    (int token=0, const char* text="")
    {
        eError error = e_ERROR_NONE;
        yytracel("OnOp(", text, ")...\n", 0);
        return error;
    }

    /* Function: OnAssignmentStatement
     */
    virtual eError OnAssignmentStatement()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnAssignmentStatement()...\n");
        return error;
    }

    /* Function: OnMbrAccess
     */
    virtual eError OnMbrAccess()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnMbrAccess()...\n");
        return error;
    }
    /* Function: OnVirtualMbrSubPrg
     */
    virtual eError OnVirtualMbrSubPrg()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnVirtualMbrSubPrg()...\n");
        return error;
    }
    /* Function: OnAbstractMbrSubPrg
     */
    virtual eError OnAbstractMbrSubPrg()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnAbstractMbrSubPrg()...\n");
        return error;
    }
    /* Function: OnVirtualMbrSubPrgProto
     */
    virtual eError OnVirtualMbrSubPrgProto()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnVirtualMbrSubPrgProto()...\n");
        return error;
    }
    /* Function: OnMbrSubPrg
     */
    virtual eError OnMbrSubPrg()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnMbrSubPrg()...\n");
        return error;
    }
    /* Function: OnMbrSubPrgProto
     */
    virtual eError OnMbrSubPrgProto()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnMbrSubPrgProto()...\n");
        return error;
    }
    /* Function: OnObjAccessPrivate
     */
    virtual eError OnObjAccessPrivate()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnObjAccessPrivate()...\n");
        return error;
    }
    /* Function: OnObjAccessProtected
     */
    virtual eError OnObjAccessProtected()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnObjAccessProtected()...\n");
        return error;
    }
    /* Function: OnObjAccessPublic
     */
    virtual eError OnObjAccessPublic()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnObjAccessPublic()...\n");
        return error;
    }

    /* Function: OnProcedureProto
     */
    virtual eError OnProcedureProto()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnProcedureProto()...\n");
        return error;
    }
    /* Function: OnFunctionProto
     */
    virtual eError OnFunctionProto()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnFunctionProto()...\n");
        return error;
    }
    /* Function: OnFormalParams
     */
    virtual eError OnFormalParams()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnFormalParams()...\n");
        return error;
    }

    /* Function: OnPragmas
     */
    virtual eError OnPragmas()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnPragmas()...\n");
        return error;
    }
    /* Function: OnPragma
     */
    virtual eError OnPragma()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnPragma()...\n");
        return error;
    }
    /* Function: OnPragArgs
     */
    virtual eError OnPragArgs()
    {
        eError error = e_ERROR_NONE;
        yytrace("OnPragArgs()...\n");
        return error;
    }

    virtual eError On
    (eSyntaxNodeType type=e_SYNTAX_NODE_TYPE_NONE)
    {
        cLexerToken *token;
        const char* chars;
        if ((token = m_lexer.PopToken()))
        if ((chars = token->Get()))
        {
            m_out.WriteL
           (g_syntax_node_type_name
            [type-e_SYNTAX_NODE_TYPE_LITERAL_FIRST],
            "=",chars,"\n",0);

            if ((m_syntaxNode = cSyntaxNode::CreateInstance(type, chars)))
            {
                m_syntaxNodeList.AddItem(m_syntaxNode->m_item);
                if ((m_syntaxNodeItem = cSyntaxNodeItem::CreateInstance(*m_syntaxNode)))
                    m_syntaxNodeStack.PushItem(*m_syntaxNodeItem);
            }
        }
        return e_ERROR_NONE;
    }
    virtual eError OnExpr()
    {
        if ((m_syntaxNodeItem = m_syntaxNodeStack.PopItem()))
        {
            m_syntaxNodeItem->m_node.Out(m_out);
            switch((m_nodeType = m_syntaxNodeItem->m_node.m_type))
            {
            case e_SYNTAX_NODE_TYPE_IDENTIFIER:
                break;
            case e_SYNTAX_NODE_TYPE_LITERAL_STRING:
                break;
            }
        }
        if (m_syntaxNodeItem)
            m_syntaxNodeStack.PushItem(*m_syntaxNodeItem);
        return e_ERROR_NONE;
    }
    virtual eError OnIndexedComponent()
    {
        if ((m_syntaxNodeItem2 = m_syntaxNodeStack.PopItem()))
        if ((m_syntaxNodeItem = m_syntaxNodeStack.PopItem()))
        if ((m_nodeText = m_syntaxNodeItem->m_node.GetText(m_nodeTextLength)))
        {
            m_out.WriteL(m_nodeText,"(...","\n",0);
            while ((m_syntaxNodeItem3 = m_syntaxNodeItem2->m_node.m_list.PopItem()))
                m_syntaxNodeItem3->m_node.Out(m_out);
            m_out.WriteL("...)",m_nodeText,"\n",0);
        }
        return e_ERROR_NONE;
    }
    virtual eError OnAggrBegin()
    {
        m_out.WriteL("(...","\n",0);
        if ((m_syntaxNode = cSyntaxNode::
            CreateInstance(e_SYNTAX_NODE_TYPE_NONE)))
        {
            m_exprNodeStack.PushItem(m_syntaxNode->m_item);
            while ((m_syntaxNodeItem = m_syntaxNodeStack.PopItem()))
                m_syntaxNode->m_list.AddItem(*m_syntaxNodeItem);
        }
        return e_ERROR_NONE;
    }
    virtual eError OnAggrEnd()
    {
        m_out.WriteL("...)","\n",0);
        if ((m_syntaxNodeItem = m_exprNodeStack.PopItem()))
        {
            m_syntaxNodeItem->m_node.m_list.Swap(m_syntaxNodeStack);
            m_syntaxNodeStack.PushItem(*m_syntaxNodeItem);
        }
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: YYOn
     *
     *   Author: $author$
     *     Date: 7/31/2008
     **********************************************************************
     */
    virtual void YYOn
    (const char* on, const char* name=0) 
    {
    }
    /**
     **********************************************************************
     * Function: YYOnError
     *
     *   Author: $author$
     *     Date: 7/31/2008
     **********************************************************************
     */
    virtual eError YYOnError
    (const char* on, const char* name=0) 
    {
        return m_error;
    }
    /**
     **********************************************************************
     * Function: yyparse
     *
     *   Author: $author$
     *     Date: 7/31/2008
     *
     * This function is generated by yacc.
     **********************************************************************
     */
    virtual int yyparse();
    /**
     **********************************************************************
     * Function: yylex
     *
     *   Author: $author$
     *     Date: 7/31/2008
     **********************************************************************
     */
    int yylex()
    {
        return m_lexer.yylex();
    }
    /**
     **********************************************************************
     * Function: yyerrorl
     *
     *   Author: $author$
     *     Date: 7/31/2008
     **********************************************************************
     */
    void yyerrorl(const char *msg,...)
    {
        va_list va;

        va_start(va,msg);
        yyerror(msg);
        yyerrorv(va);
        va_end(va);
    }
    /**
     **********************************************************************
     * Function: yyerrorv
     *
     *   Author: $author$
     *     Date: 7/31/2008
     **********************************************************************
     */
    void yyerrorv(va_list va)
    {
        const char *msg;

        while ((msg=va_arg(va,const char *)))
            yyerror(msg);
    }
    /**
     **********************************************************************
     * Function: yytracel
     *
     *   Author: $author$
     *     Date: 8/15/2008
     **********************************************************************
     */
    virtual void yytracel(const char *msg, ...)
    {
        va_list va;

        va_start(va,msg);
        yytrace(msg);
        yytracev(va);
        va_end(va);
    }
    /**
     **********************************************************************
     * Function: yytracev
     *
     *   Author: $author$
     *     Date: 8/15/2008
     **********************************************************************
     */
    virtual void yytracev(va_list va)
    {
        const char *msg;

        while ((msg=va_arg(va,const char *)))
            yytrace(msg);
    }
    /**
     **********************************************************************
     * Function: yytrace
     *
     *   Author: $author$
     *     Date: 8/15/2008
     **********************************************************************
     */
    virtual void yytrace(const char *msg)
    {
        m_out.Write(msg);
    }
    /**
     **********************************************************************
     * Function: yyinfo
     *
     *   Author: $author$
     *     Date: 8/15/2008
     **********************************************************************
     */
    virtual void yyinfo(const char *msg)
    {
        m_out.Write(msg);
    }
    /**
     **********************************************************************
     * Function: yywarning
     *
     *   Author: $author$
     *     Date: 8/15/2008
     **********************************************************************
     */
    virtual void yywarning(const char *msg)
    {
        yyerror(msg);
    }
    /**
     **********************************************************************
     * Function: yyerror
     *
     *   Author: $author$
     *     Date: 7/31/2008
     **********************************************************************
     */
    virtual void yyerror(const char *msg)
    {
        const char* yytext = m_lexer.yy_text();
        const char* yylinenotext = "-1";
        cCharString yylineno;
        TLENGTH length;

        if (0 < (length = yylineno.AssignSigned(m_lexer.yy_lineno())))
        if (!(yylinenotext = yylineno.HasChars(length)))
            yylinenotext = "-1";

        m_out.WriteL
        (msg," at ",(yytext[0]?"\"":""), 
         (yytext[0]?yytext:"[EOF]"),
         (yytext[0]?"\"":"")," on line ",yylinenotext,"\n",0);
    }
};
#endif /* _CACPARSER_HXX */
