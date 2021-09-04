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
 *   File: clexerdelegate.hxx
 *
 * Author: $author$
 *   Date: 7/8/2008
 **********************************************************************
 */
#ifndef _CLEXERDELEGATE_HXX
#define _CLEXERDELEGATE_HXX

#include "cerror.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cLexerDelegateT"
/**
 **********************************************************************
 *  Class: cLexerDelegateT
 *
 * Author: $author$
 *   Date: 7/8/2008
 **********************************************************************
 */
template
<class TDerives>
 
class cLexerDelegateT
{
public:
    typedef TDerives cDelegate;

    /**
     **********************************************************************
     * Function: OnCharToken
     *
     *   Author: $author$
     *     Date: 7/30/2008
     **********************************************************************
     */
    virtual eError OnCharToken
    (const char* text, int token=-1,
     int beginchars=1, int endchars=1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCharToken
            (text, token, beginchars, endchars);
        else
        {
            if (0 > beginchars) beginchars = 1;
            if (0 > endchars) endchars = 1;
            error = OnToken
            (text, token, beginchars, endchars);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnStringToken
     *
     *   Author: $author$
     *     Date: 7/30/2008
     **********************************************************************
     */
    virtual eError OnStringToken
    (const char* text, int token=-1,
     int beginchars=1, int endchars=1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnStringToken
            (text, token, beginchars, endchars);
        else
        {
            if (0 > beginchars) beginchars = 1;
            if (0 > endchars) endchars = 1;
            error = OnToken
            (text, token, beginchars, endchars);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnIntegerToken
     *
     *   Author: $author$
     *     Date: 7/30/2008
     **********************************************************************
     */
    virtual eError OnIntegerToken
    (const char* text, int token=-1,
     int beginchars=0, int endchars=0) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnIntegerToken
            (text, token, beginchars, endchars);
        else
        {
            error = OnToken
            (text, token, beginchars, endchars);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnRealToken
     *
     *   Author: $author$
     *     Date: 7/30/2008
     **********************************************************************
     */
    virtual eError OnRealToken
    (const char* text, int token=-1,
     int beginchars=0, int endchars=0) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnRealToken
            (text, token, beginchars, endchars);
        else
        {
            error = OnToken
            (text, token, beginchars, endchars);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnIdentifierToken
     *
     *   Author: $author$
     *     Date: 7/30/2008
     **********************************************************************
     */
    virtual eError OnIdentifierToken
    (const char* text, int token=-1,
     int beginchars=0, int endchars=0) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnIdentifierToken
            (text, token, beginchars, endchars);
        else
        {
            error = OnToken
            (text, token, beginchars, endchars);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnToken
     *
     *   Author: $author$
     *     Date: 7/30/2008
     **********************************************************************
     */
    virtual eError OnToken
    (const char* text, int token=-1,
     int beginchars=0, int endchars=0) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnToken
            (text, token, beginchars, endchars);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnBeginRuleComment
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnBeginRuleComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginRuleComment(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndRuleComment
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnEndRuleComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndRuleComment(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnRuleCommentText
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnRuleCommentText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnRuleCommentText(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginRuleT
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnBeginRuleT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginRuleT(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndRuleT
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnEndRuleT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndRuleT(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnRuleT
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnRuleT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnRuleT(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginRuleL
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnBeginRuleL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginRuleL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndRuleL
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnEndRuleL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndRuleL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAndRuleL
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnAndRuleL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnAndRuleL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnOrRuleL
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnOrRuleL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnOrRuleL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnRuleL
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnRuleL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnRuleL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnRuleLString
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnRuleLString
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnRuleLString(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnRuleLChar
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnRuleLChar
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnRuleLChar(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnRuleText
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnRuleText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnRuleText(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnBeginComment
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnBeginComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginComment(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndComment
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnEndComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndComment(text, token);
        else error = OnEnd(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginCommentX
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnBeginCommentX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginCommentX(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndCommentX
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnEndCommentX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndCommentX(text, token);
        else error = OnEnd(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginCommentLN
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnBeginCommentLN
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginCommentLN(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndCommentLN
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnEndCommentLN
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndCommentLN(text, token);
        else error = OnEnd(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnBeginIncludeL
     *
     *   Author: $author$
     *     Date: 9/4/2008
     **********************************************************************
     */
    virtual eError OnBeginIncludeL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginIncludeL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndIncludeL
     *
     *   Author: $author$
     *     Date: 9/4/2008
     **********************************************************************
     */
    virtual eError OnEndIncludeL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndIncludeL(text, token);
        else error = OnEndL(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnBeginImportL
     *
     *   Author: $author$
     *     Date: 9/4/2008
     **********************************************************************
     */
    virtual eError OnBeginImportL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginImportL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndImportL
     *
     *   Author: $author$
     *     Date: 9/4/2008
     **********************************************************************
     */
    virtual eError OnEndImportL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndImportL(text, token);
        else error = OnEndL(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnBeginDefine
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnBeginDefine
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginDefine(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndDefine
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnEndDefine
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndDefine(text, token);
        else error = OnEnd(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginDefineX
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnBeginDefineX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginDefineX(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndDefineX
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnEndDefineX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndDefineX(text, token);
        else error = OnEnd(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginDefineL
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnBeginDefineL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginDefineL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndDefineL
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnEndDefineL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndDefineL(text, token);
        else error = OnEndL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginDefineT
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnBeginDefineT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginDefineT(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndDefineT
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnEndDefineT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndDefineT(text, token);
        else error = OnEndT(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnBeginProcessor
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnBeginProcessor
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginProcessor(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndProcessor
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnEndProcessor
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndProcessor(text, token);
        else error = OnEnd(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginProcessorX
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnBeginProcessorX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginProcessorX(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndProcessorX
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnEndProcessorX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndProcessorX(text, token);
        else error = OnEnd(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnBeginCode
     *
     *   Author: $author$
     *     Date: 8/14/2008
     **********************************************************************
     */
    virtual eError OnBeginCode
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginCode(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndCode
     *
     *   Author: $author$
     *     Date: 8/14/2008
     **********************************************************************
     */
    virtual eError OnEndCode
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndCode(text, token);
        else error = OnEnd(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnBeginText
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnBeginText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginText(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginTextAfter
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnBeginTextAfter
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginTextAfter(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndText
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnEndText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndText(text, token);
        else error = OnEnd(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnEnd
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnEnd
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEnd(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndT
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnEndT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndT(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndL
     *
     *   Author: $author$
     *     Date: 9/4/2008
     **********************************************************************
     */
    virtual eError OnEndL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndBefore
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnEndBefore
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndBefore(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnComment
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnComment(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCommentX
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnCommentX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCommentX(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCommentLN
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnCommentLN
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCommentLN(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnIncludeL
     *
     *   Author: $author$
     *     Date: 9/4/2008
     **********************************************************************
     */
    virtual eError OnIncludeL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnIncludeL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnImportL
     *
     *   Author: $author$
     *     Date: 9/4/2008
     **********************************************************************
     */
    virtual eError OnImportL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnImportL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnProcessor
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnProcessor
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnProcessor(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnProcessorX
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnProcessorX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnProcessorX(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnDefine
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnDefine
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnDefine(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnDefineX
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnDefineX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnDefineX(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnDefineT
     *
     *   Author: $author$
     *     Date: 8/7/2008
     **********************************************************************
     */
    virtual eError OnDefineT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnDefineT(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnDefineL
     *
     *   Author: $author$
     *     Date: 8/7/2008
     **********************************************************************
     */
    virtual eError OnDefineL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnDefineL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnReserved
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnReserved
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnReserved(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnReservedX
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnReservedX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnReservedX(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnReservedY
     *
     *   Author: $author$
     *     Date: 10/13/2008
     **********************************************************************
     */
    virtual eError OnReservedY
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnReservedY(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnString
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnString
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnString(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnChar
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnChar
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnChar(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnLT
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnLT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnLT(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnGT
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnGT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnGT(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCode
     *
     *   Author: $author$
     *     Date: 8/14/2008
     **********************************************************************
     */
    virtual eError OnCode
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCode(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnText
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnText(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnSkip
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnSkip
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnSkip(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnSwitch
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnSwitch
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnSwitch(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnPush
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnPush
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnPush(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnPop
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual eError OnPop
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnPop(text, token);
        return error;
    }

    /*
     * CGI rules
     */

    /**
     **********************************************************************
     * Function: OnBeginCGIBeforeAny
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnBeginCGIBeforeAny
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginCGIBeforeAny(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeComment
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeComment(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeCommentLN
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeCommentLN
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeCommentLN(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeProcessor
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeProcessor
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeProcessor(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeDefine
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeDefine
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeDefine(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeDefineT
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeDefineT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeDefineT(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeDefineL
     *
     *   Author: $author$
     *     Date: 8/18/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeDefineL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeDefineL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeImportL
     *
     *   Author: $author$
     *     Date: 10/2/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeImportL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeImportL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeIncludeL
     *
     *   Author: $author$
     *     Date: 9/4/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeIncludeL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeIncludeL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeKeyword
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeKeyword
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeKeyword(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeKeywordX
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeKeywordX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeKeywordX(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeString
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeString
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeString(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeChar
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeChar
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeChar(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeAny
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeAny
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeAny(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnEndCGIAfterAny
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnEndCGIAfterAny
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndCGIAfterAny(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeAnyText
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeAnyText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeAnyText(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIAfterAnyText
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIAfterAnyText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIAfterAnyText(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnEndCGIBefore
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnEndCGIBefore
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndCGIBefore(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBeforeText
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeText(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIAfterText
     *
     *   Author: $author$
     *     Date: 8/10/2008
     **********************************************************************
     */
    virtual eError OnCGIAfterText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIAfterText(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnBeginCGIText
     *
     *   Author: $author$
     *     Date: 8/15/2008
     **********************************************************************
     */
    virtual eError OnBeginCGIText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginCGIText(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndCGIText
     *
     *   Author: $author$
     *     Date: 8/15/2008
     **********************************************************************
     */
    virtual eError OnEndCGIText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndCGIText(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIText
     *
     *   Author: $author$
     *     Date: 8/14/2008
     **********************************************************************
     */
    virtual eError OnCGIText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIText(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnBeginCGIPath
     *
     *   Author: $author$
     *     Date: 9/14/2008
     **********************************************************************
     */
    virtual eError OnBeginCGIPath
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginCGIPath(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndCGIPath
     *
     *   Author: $author$
     *     Date: 9/14/2008
     **********************************************************************
     */
    virtual eError OnEndCGIPath
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndCGIPath(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIPath
     *
     *   Author: $author$
     *     Date: 9/14/2008
     **********************************************************************
     */
    virtual eError OnCGIPath
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIPath(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnBeginCGIExtension
     *
     *   Author: $author$
     *     Date: 10/2/2008
     **********************************************************************
     */
    virtual eError OnBeginCGIExtension
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginCGIExtension(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndCGIExtension
     *
     *   Author: $author$
     *     Date: 10/2/2008
     **********************************************************************
     */
    virtual eError OnEndCGIExtension
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndCGIExtension(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIExtension
     *
     *   Author: $author$
     *     Date: 10/2/2008
     **********************************************************************
     */
    virtual eError OnCGIExtension
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIExtension(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: GetDelegate
     *
     *   Author: $author$
     *     Date: 7/8/2008
     **********************************************************************
     */
    virtual cDelegate* GetDelegate() 
    { return 0; }
};
#undef CDB_CLASS

#endif /* _CLEXERDELEGATE_HXX */
