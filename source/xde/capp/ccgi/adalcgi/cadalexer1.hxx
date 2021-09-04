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
 *   File: cadalexer.hxx
 *
 * Author: $author$
 *   Date: 6/14/2008
 **********************************************************************
 */
#ifndef _CADALEXER_HXX
#define _CADALEXER_HXX

#undef yyIsLexer
#undef yyLexer
#undef cYYIsLexer
#define yyIsLexer cAdaIsLexer
#define yyLexer cAdaLexer
#define cYYIsLexer cAdaLexerExtends
#include "cyylexer.hxx"

/**
 **********************************************************************
 *  Class: cAdaLexerDelegate
 *
 * Author: $author$
 *   Date: 6/14/2008
 **********************************************************************
 */
class cAdaLexerDelegate
{
public:
    typedef cAdaLexerDelegate cDerives;
    typedef cAdaLexerDelegate cDelegate;
    /**
     **********************************************************************
     * Function: OnBeginComment
     *
     *   Author: $author$
     *     Date: 6/14/2008
     **********************************************************************
     */
    virtual eError OnBeginComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cAdaLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginComment(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndComment
     *
     *   Author: $author$
     *     Date: 6/14/2008
     **********************************************************************
     */
    virtual eError OnEndComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cAdaLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndComment(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnReserved
     *
     *   Author: $author$
     *     Date: 6/14/2008
     **********************************************************************
     */
    virtual eError OnReserved
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cAdaLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnReserved(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnString
     *
     *   Author: $author$
     *     Date: 6/14/2008
     **********************************************************************
     */
    virtual eError OnString
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cAdaLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnString(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnChar
     *
     *   Author: $author$
     *     Date: 6/14/2008
     **********************************************************************
     */
    virtual eError OnChar
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cAdaLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnChar(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnLT
     *
     *   Author: $author$
     *     Date: 6/14/2008
     **********************************************************************
     */
    virtual eError OnLT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cAdaLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnLT(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnGT
     *
     *   Author: $author$
     *     Date: 6/14/2008
     **********************************************************************
     */
    virtual eError OnGT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cAdaLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnGT(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnText
     *
     *   Author: $author$
     *     Date: 6/14/2008
     **********************************************************************
     */
    virtual eError OnText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cAdaLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnText(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnSwitch
     *
     *   Author: $author$
     *     Date: 6/14/2008
     **********************************************************************
     */
    virtual eError OnSwitch
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cAdaLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnSwitch(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnPush
     *
     *   Author: $author$
     *     Date: 6/14/2008
     **********************************************************************
     */
    virtual eError OnPush
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cAdaLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnPush(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnPop
     *
     *   Author: $author$
     *     Date: 6/14/2008
     **********************************************************************
     */
    virtual eError OnPop
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cAdaLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnPop(text, token);
        return error;
    }

    /**
     **********************************************************************
     * Function: GetDelegate
     *
     *   Author: $author$
     *     Date: 6/13/2008
     **********************************************************************
     */
    virtual cDelegate* GetDelegate() 
    { return 0; }
};

/**
 **********************************************************************
 *  Class: cAdaLexer
 *
 * Author: $author$
 *   Date: 5/9/2008
 **********************************************************************
 */
class cAdaLexer
: virtual public cAdaLexerDelegate,
  public cAdaLexerExtends
{
public:
    typedef cAdaLexerDelegate cImplements;
    typedef cAdaLexerExtends cExtends;
    typedef cAdaLexer cDerives;

    cDelegate& m_delegate;

    /**
     **********************************************************************
     * Constructor: cAdaLexer
     *
     *      Author: $author$
     *        Date: 5/9/2008
     **********************************************************************
     */
    cAdaLexer
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
     * Function: OnSwitch
     *
     *   Author: $author$
     *     Date: 5/9/2008
     **********************************************************************
     */
    virtual eError OnSwitch
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cAdaLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnSwitch(text, token);
        OnSwitchState(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnPush
     *
     *   Author: $author$
     *     Date: 5/9/2008
     **********************************************************************
     */
    virtual eError OnPush
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cAdaLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnPush(text, token);
        OnPushState(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnPop
     *
     *   Author: $author$
     *     Date: 5/9/2008
     **********************************************************************
     */
    virtual eError OnPop
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cAdaLexerDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnPop(text, token);
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
    virtual cDelegate* GetDelegate() 
    {
        return &m_delegate;
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
};

#endif /* _CADALEXER_HXX */
