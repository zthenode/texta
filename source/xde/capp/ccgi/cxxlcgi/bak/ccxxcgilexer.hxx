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
 *   File: ccxxcgilexer.hxx
 *
 * Author: $author$
 *   Date: 5/3/2008
 **********************************************************************
 */
#ifndef _CCXXCGILEXER_HXX
#define _CCXXCGILEXER_HXX

#undef yyIsLexer
#undef yyLexer
#undef cYYIsLexer
#define yyIsLexer cCXXCGIIsLexer
#define yyLexer cCXXCGILexer
#define cYYIsLexer cCXXCGILexerExtends
#include "cyylexer.hxx"

/**
 **********************************************************************
 *  Class: cCXXCGILexerDelegate
 *
 * Author: $author$
 *   Date: 5/3/2008
 **********************************************************************
 */
class cCXXCGILexerDelegate
{
public:
    typedef cCXXCGILexerDelegate cDerives;
    /**
     **********************************************************************
     * Function: OnCXXCGIBeginBody
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIBeginBody
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIBeginBody(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIEndBody
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIEndBody
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIEndBody(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIBeginComment
     *
     *   Author: $author$
     *     Date: 5/3/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIBeginComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIBeginComment(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIEndComment
     *
     *   Author: $author$
     *     Date: 5/3/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIEndComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIEndComment(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIComment
     *
     *   Author: $author$
     *     Date: 5/3/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIComment(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIText
     *
     *   Author: $author$
     *     Date: 5/3/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIText(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnCXXCGIBeginBefore
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIBeginBefore
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIBeginBefore(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIBeforeComment
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIBeforeComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIBeforeComment(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIBeforeCommentEOL
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIBeforeCommentEOL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIBeforeCommentEOL(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIBeforeProcessor
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIBeforeProcessor
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIBeforeProcessor(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIBeforeKeyword
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIBeforeKeyword
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIBeforeKeyword(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIBeforeString
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIBeforeString
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIBeforeString(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIBeforeChar
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIBeforeChar
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIBeforeChar(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIEndBefore
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIEndBefore
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIEndBefore(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIAfterText
     *
     *   Author: $author$
     *     Date: 5/3/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIAfterText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIAfterText(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIEndAfter
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIEndAfter
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIEndAfter(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: GetCXXCGIDelegate
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual cCXXCGILexerDelegate* GetCXXCGIDelegate() 
    {
        cCXXCGILexerDelegate* delegate = 0;
        return delegate;
    }
};

/**
 **********************************************************************
 *  Class: cCXXCGILexer
 *
 * Author: $author$
 *   Date: 5/3/2008
 **********************************************************************
 */
class cCXXCGILexer
: virtual public cCXXCGILexerDelegate,
  public cCXXCGILexerExtends
{
public:
    typedef cCXXCGILexerExtends cExtends;
    typedef cCXXCGILexer cDerives;
    typedef cCXXCGILexerDelegate cDelegate;

    cDelegate& m_delegate;

    /**
     **********************************************************************
     * Constructor: cCXXCGILexer
     *
     *      Author: $author$
     *        Date: 5/3/2008
     **********************************************************************
     */
    cCXXCGILexer
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
     * Function: OnCXXCGIBeginBefore
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIBeginBefore
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIBeginBefore(text, token);
        OnPushState(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIEndBefore
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIEndBefore
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIEndBefore(text, token);
        OnSwitchState(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIEndAfter
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIEndAfter
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIEndAfter(text, token);
        OnPopState(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnCXXCGIBeginBody
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIBeginBody
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIBeginBody(text, token);
        OnSwitchState(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIEndBody
     *
     *   Author: $author$
     *     Date: 5/4/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIEndBody
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIEndBody(text, token);
        OnSwitchState(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnCXXCGIBeginComment
     *
     *   Author: $author$
     *     Date: 5/3/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIBeginComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIBeginComment(text, token);
        OnPushState(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCXXCGIEndComment
     *
     *   Author: $author$
     *     Date: 5/3/2008
     **********************************************************************
     */
    virtual eError OnCXXCGIEndComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cCXXCGILexerDelegate* delegate = 0;
        if ((delegate = GetCXXCGIDelegate()))
            error = delegate->OnCXXCGIEndComment(text, token);
        OnPopState(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: GetCXXCGIDelegate
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual cCXXCGILexerDelegate* GetCXXCGIDelegate() 
    {
        return &m_delegate;
    }

    /**
     **********************************************************************
     * Function: yylex
     *
     *   Author: $author$
     *     Date: 5/3/2008
     *
     * This function is generated by flex.
     **********************************************************************
     */
	virtual int yylex();
};

#endif /* _CCXXCGILEXER_HXX */
