/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: ccxxlexer.hxx
 *
 * Author: $author$
 *   Date: 8/25/2003
 **********************************************************************
 */
#ifndef _CCXXLEXER_HXX
#define _CCXXLEXER_HXX

#undef yyIsLexer
#undef yyLexer
#undef cYYIsLexer
#define yyIsLexer cCXXIsLexer
#define yyLexer cCXXLexer
#define cYYIsLexer cCXXLexerExtends
#include "cyylexer.hxx"

/**
 **********************************************************************
 *  Class: cCXXLexerDelegate
 *
 * Author: $author$
 *   Date: 5/2/2008
 **********************************************************************
 */
class cCXXLexerDelegate
{
public:
    typedef cCXXLexerDelegate cDerives;
    /**
     **********************************************************************
     * Function: OnBeginComment
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnBeginComment
    (const char* text, int token=-1) 
    {
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
        m_delegate->OnBeginComment(text, token);
    }
    /**
     **********************************************************************
     * Function: OnEndComment
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnEndComment
    (const char* text, int token=-1) 
    {
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
        m_delegate->OnEndComment(text, token);
    }
    /**
     **********************************************************************
     * Function: OnBeginCommentEOL
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnBeginCommentEOL
    (const char* text, int token=-1) 
    {
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
        m_delegate->OnBeginCommentEOL(text, token);
    }
    /**
     **********************************************************************
     * Function: OnEndCommentEOL
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnEndCommentEOL
    (const char* text, int token=-1) 
    {
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
        m_delegate->OnEndCommentEOL(text, token);
    }
    /**
     **********************************************************************
     * Function: OnComment
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnComment
    (const char* text, int token=-1) 
    {
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
        m_delegate->OnComment(text, token);
    }
    /**
     **********************************************************************
     * Function: OnCommentLT
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnCommentLT
    (const char* text, int token=-1) 
    {
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
        m_delegate->OnCommentLT(text, token);
    }
    /**
     **********************************************************************
     * Function: OnCommentGT
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnCommentGT
    (const char* text, int token=-1) 
    {
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
        m_delegate->OnCommentGT(text, token);
    }

    /**
     **********************************************************************
     * Function: OnIncluded
     *
     *   Author: $author$
     *     Date: 5/12/2008
     **********************************************************************
     */
    virtual eError OnIncluded
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnIncluded(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnProcessor
     *
     *   Author: $author$
     *     Date: 5/2/2008
     **********************************************************************
     */
    virtual void OnProcessor
    (const char* text,
     int token=-1) 
    {
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
        m_delegate->OnProcessor(text, token);
    }
    /**
     **********************************************************************
     * Function: OnReserved
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnReserved
    (const char* text, int token=-1) 
    {
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
        m_delegate->OnReserved(text, token);
    }
    /**
     **********************************************************************
     * Function: OnStringLiteral
     *
     *   Author: $author$
     *     Date: 5/2/2008
     **********************************************************************
     */
    virtual void OnStringLiteral
    (const char* text,
     int token=-1) 
    {
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
        m_delegate->OnStringLiteral(text, token);
    }
    /**
     **********************************************************************
     * Function: OnCharLiteral
     *
     *   Author: $author$
     *     Date: 5/2/2008
     **********************************************************************
     */
    virtual void OnCharLiteral
    (const char* text,
     int token=-1) 
    {
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
        m_delegate->OnCharLiteral(text, token);
    }
    /**
     **********************************************************************
     * Function: OnLT
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnLT
    (const char* text, int token=-1) 
    {
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
        m_delegate->OnLT(text, token);
    }
    /**
     **********************************************************************
     * Function: OnGT
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnGT
    (const char* text, int token=-1) 
    {
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
        m_delegate->OnGT(text, token);
    }
    /**
     **********************************************************************
     * Function: OnText
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnText
    (const char* text, int token=-1) 
    {
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
        m_delegate->OnText(text, token);
    }

    /**
     **********************************************************************
     * Function: OnSwitch
     *
     *   Author: $author$
     *     Date: 5/12/2008
     **********************************************************************
     */
    virtual eError OnSwitch
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnSwitch(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnPush
     *
     *   Author: $author$
     *     Date: 5/12/2008
     **********************************************************************
     */
    virtual eError OnPush
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnPush(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnPop
     *
     *   Author: $author$
     *     Date: 5/12/2008
     **********************************************************************
     */
    virtual eError OnPop
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnPop(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: GetDelegate
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual cCXXLexerDelegate* GetDelegate() 
    {
        cCXXLexerDelegate* delegate = 0;
        return delegate;
    }
};

/**
 **********************************************************************
 *  Class: cCXXLexer
 *
 * Author: $author$
 *   Date: 8/25/2003
 **********************************************************************
 */
class cCXXLexer
: virtual public cCXXLexerDelegate,
  public cCXXLexerExtends
{
public:
    typedef cCXXLexerExtends cExtends;
    typedef cCXXLexerDelegate cDelegate;

    cDelegate& m_delegate;

    cCXXLexer
    (cDelegate& delegate,
     cCharStreamInterface& out, 
     cCharStreamInterface& in, 
     cSource &source)
    : cExtends(out, in, source),
      m_delegate(delegate)
    {
    }

    /**
     **********************************************************************
     * Function: yylex
     *
     *   Author: $author$
     *     Date: 8/25/2003
     *
     * This function is generated by flex.
     **********************************************************************
     */
	virtual int yylex();

    /**
     **********************************************************************
     * Function: OnBeginComment
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnBeginComment
    (const char* text, int token=-1) 
    {
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
        m_delegate->OnBeginComment(text, token);
        OnPushState(text, token);
    }
    /**
     **********************************************************************
     * Function: OnEndComment
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnEndComment
    (const char* text, int token=-1) 
    {
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
        m_delegate->OnEndComment(text, token);
        OnPopState(text, token);
    }
    /**
     **********************************************************************
     * Function: OnBeginCommentEOL
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnBeginCommentEOL
    (const char* text, int token=-1) 
    {
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
        m_delegate->OnBeginCommentEOL(text, token);
        OnPushState(text, token);
    }
    /**
     **********************************************************************
     * Function: OnEndCommentEOL
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnEndCommentEOL
    (const char* text, int token=-1) 
    {
        cCXXLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
        m_delegate->OnEndCommentEOL(text, token);
        OnPopState(text, token);
    }

    /**
     **********************************************************************
     * Function: OnSwitch
     *
     *   Author: $author$
     *     Date: 5/12/2008
     **********************************************************************
     */
    virtual eError OnSwitch
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        OnSwitchState(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnPush
     *
     *   Author: $author$
     *     Date: 5/12/2008
     **********************************************************************
     */
    virtual eError OnPush
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        OnPushState(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnPop
     *
     *   Author: $author$
     *     Date: 5/12/2008
     **********************************************************************
     */
    virtual eError OnPop
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        OnPopState(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: GetDelegate
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual cCXXLexerDelegate* GetDelegate() 
    {
        return &m_delegate;
    }
};

#endif /* _CCXXLEXER_HXX */
