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
 *   File: clexer.hxx
 *
 * Author: $author$
 *   Date: 7/8/2008
 **********************************************************************
 */
#ifndef _CLEXER_HXX
#define _CLEXER_HXX

#include "clexersource.hxx"
#include "clexerdelegate.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cLexerT"
/**
 **********************************************************************
 *  Class: cLexerT
 *
 * Author: $author$
 *   Date: 7/8/2008
 **********************************************************************
 */
template
<class TDelegate,
 class TExtends,
 class TSource=cLexerSource,
 class TStream=cCharStreamInterface>
 
class cLexerT
: virtual public TDelegate,
  public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDelegate cDelegate;

    TDelegate& m_delegate;

    /**
     **********************************************************************
     * Constructor: cLexerT
     *
     *      Author: $author$
     *        Date: 7/8/2008
     **********************************************************************
     */
    cLexerT
    (TDelegate& delegate,
     TStream& out,
     TStream& in,
     TSource& source) 
    : cExtends(out, in, source),
      m_delegate(delegate)
    {
    }
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
        TDelegate* m_delegate;

        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCharToken
            (text, token, beginchars, endchars);

        if (0 > beginchars) beginchars = 1;
        if (0 > endchars) endchars = 1;

        CTHIS OnEscapedTokenText
        (text, token, beginchars, endchars);
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
        TDelegate* m_delegate;

        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnStringToken
            (text, token, beginchars, endchars);

        if (0 > beginchars) beginchars = 1;
        if (0 > endchars) endchars = 1;

        CTHIS OnEscapedTokenText
        (text, token, beginchars, endchars);
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
        TDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnIdentifierToken
            (text, token, beginchars, endchars);
        CTHIS OnTokenText
        (text, token, beginchars, endchars);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnSwitch
     *
     *   Author: $author$
     *     Date: 6/25/2008
     **********************************************************************
     */
    virtual eError OnSwitch
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        TDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnSwitch(text, token);
        CTHIS OnSwitchState(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnPush
     *
     *   Author: $author$
     *     Date: 6/25/2008
     **********************************************************************
     */
    virtual eError OnPush
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        TDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnPush(text, token);
        CTHIS OnPushState(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnPop
     *
     *   Author: $author$
     *     Date: 6/25/2008
     **********************************************************************
     */
    virtual eError OnPop
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        TDelegate* m_delegate;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnPop(text, token);
        CTHIS OnPopState(text, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: GetDelegate
     *
     *   Author: $author$
     *     Date: 6/25/2008
     **********************************************************************
     */
    virtual TDelegate* GetDelegate() 
    {
        return &m_delegate;
    }
};
#undef CDB_CLASS

#endif /* _CLEXER_HXX */
