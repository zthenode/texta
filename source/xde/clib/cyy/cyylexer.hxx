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
 *   File: cyylexer.hxx
 *
 * Author: $author$
 *   Date: 5/2/2008
 **********************************************************************
 */
#ifndef _CYYLEXER_AGAIN
#define _CYYLEXER_AGAIN

#undef _YYLEXER_AGAIN
#include "yylexer.hxx"
#include "clexersource.hxx"
#include "clexertoken.hxx"
#include "ccounter.hxx"

/**
 **********************************************************************
 *  Class: cYYIsLexer
 *
 * Author: $author$
 *   Date: 5/2/2008
 **********************************************************************
 */
class cYYIsLexer
: public yyIsLexer
{
public:
    typedef yyIsLexer cExtends;
    typedef cYYIsLexer cDerives;

    typedef cEscapedLexerToken cEscapedToken;
    typedef cUpperLexerToken cUpperToken;
    typedef cLowerLexerToken cLowerToken;
    typedef cLexerToken cToken;
    typedef cLexerTokens cTokens;
    typedef cLexerSource cSource;
    typedef cLexerInclude cInclude;
    typedef cLexerIncludes cIncludes;

    cSource &m_source;
    cIncludes m_includes;
    cTokens m_tokens;
    cTokens m_free_tokens;

    cCharCounter m_charCounter;

    /**
     **********************************************************************
     * Constructor: cYYIsLexer
     *
     *      Author: $author$
     *        Date: 5/2/2008
     **********************************************************************
     */
    cYYIsLexer
    (cCharStreamInterface& out, 
     cCharStreamInterface& in, 
     cSource &source) 
    : cExtends(out, in),
      m_source(source)
    {
    }

    /**
     **********************************************************************
     * Function: OnInclude
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    virtual eError OnInclude()
    {
        int count;
        eError error;
        cToken *token;
        cInclude *include;
        cCharStreamInterface* stream;
        cCharString buffer;

        if ((token=PopToken()))
        {            
            if ((stream = m_source.OpenFile(error, token->Get())))
            {
                if (!(include=new cInclude(m_source, *stream)))
                {
                    m_source.Close(*stream);
                    return e_ERROR_NEW;
                }

                include->m_state=yy_save_scan_state(&include->m_stream);
                m_includes.PushItem(*include);
            }
            else 
            {
                TLENGTH length;
                if (0< (count = buffer.AssignL
                    ("Unable to open include file \"",token->Get(),"\"",0)))
                    SetLastError
                    (e_ERROR_OPEN, buffer.Chars(length));

                error=e_ERROR_OPEN;
            }
            return error;
        }
        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnIncludeURI
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    virtual eError OnIncludeURI()
    {
        int count;
        eError error;
        cToken *token;
        cInclude *include;
        cCharStreamInterface* stream;
        cCharString buffer;

        if ((token=PopToken()))
        {            
            if ((stream = m_source.OpenURI(error, token->Get())))
            {
                if (!(include=new cInclude(m_source, *stream)))
                {
                    m_source.Close(*stream);
                    return e_ERROR_NEW;
                }

                include->m_state=yy_save_scan_state(&include->m_stream);
                m_includes.PushItem(*include);
            }
            else 
            {
                TLENGTH length;
                if (0< (count = buffer.AssignL
                    ("Unable to open include URI \"",token->Get(),"\"",0)))
                    SetLastError
                    (e_ERROR_OPEN, buffer.Chars(length));

                error=e_ERROR_OPEN;
            }
            return error;
        }
        return e_ERROR_FAILED;
    }

    /**
     **********************************************************************
     * Function: OnEscapedTokenText
     *
     *   Author: $author$
     *     Date: 7/30/2008
     **********************************************************************
     */
    eError OnEscapedTokenText
    (const char* text, int token=-1,
     int beginchars=0, int endchars=0)
    {
        cToken *ctoken;
        TLENGTH length;

        if (0 <= (length = m_charCounter.LengthOf(text+beginchars)))
        if ((ctoken=NewEscapedToken
            (text+beginchars, length-endchars)))
        {
            m_tokens.AddItem(*ctoken);
            return e_ERROR_NONE;
        }
        return e_ERROR_NEW;
    }
    /**
     **********************************************************************
     * Function: OnUpperTokenText
     *
     *   Author: $author$
     *     Date: 7/30/2008
     **********************************************************************
     */
    eError OnUpperTokenText
    (const char* text, int token=-1,
     int beginchars=0, int endchars=0)
    {
        cToken *ctoken;
        TLENGTH length;

        if (0 <= (length = m_charCounter.LengthOf(text+beginchars)))
        if ((ctoken=NewUpperToken
            (text+beginchars, length-endchars)))
        {
            m_tokens.AddItem(*ctoken);
            return e_ERROR_NONE;
        }
        return e_ERROR_NEW;
    }
    /**
     **********************************************************************
     * Function: OnTokenText
     *
     *   Author: $author$
     *     Date: 7/30/2008
     **********************************************************************
     */
    eError OnTokenText
    (const char* text, int token=-1,
     int beginchars=0, int endchars=0)
    {
        cToken *ctoken;
        TLENGTH length;

        if (0 <= (length = m_charCounter.LengthOf(text+beginchars)))
        if ((ctoken=NewToken
            (text+beginchars, length-endchars)))
        {
            m_tokens.AddItem(*ctoken);
            return e_ERROR_NONE;
        }
        return e_ERROR_NEW;
    }

    /**
     **********************************************************************
     * Function: NewEscapedToken
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    cToken *NewEscapedToken
    (const char *token, int len=-1)
    {
        cToken *ctoken;

        if (!(ctoken=m_free_tokens.PopItem()))
            return new cEscapedToken(token, len);

        ctoken->SetEscaped(token, len);
        return ctoken;
    }
    /**
     **********************************************************************
     * Function: NewUpperToken
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    cToken *NewUpperToken
    (const char *token, int len=-1)
    {
        cToken *ctoken;

        if (!(ctoken=m_free_tokens.PopItem()))
            return new cUpperToken(token, len);

        ctoken->SetUpper(token, len);
        return ctoken;
    }
    /**
     **********************************************************************
     * Function: NewLowerToken
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    cToken *NewLowerToken
    (const char *token, int len=-1)
    {
        cToken *ctoken;

        if (!(ctoken=m_free_tokens.PopItem()))
            return new cLowerToken(token, len);

        ctoken->SetLower(token, len);
        return ctoken;
    }
    /**
     **********************************************************************
     * Function: NewToken
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    cToken *NewToken
    (const char *token, int len=-1)
    {
        cToken *ctoken;

        if (!(ctoken=m_free_tokens.PopItem()))
            return new cToken(token, len);

        ctoken->Set(token, len);
        return ctoken;
    }

    /**
     **********************************************************************
     * Function: PopToken
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    cToken *PopToken()
    {
        cToken *token;

        if ((token=m_tokens.PopItem()))
            m_free_tokens.PushItem(*token);

        return token;
    }
    /**
     **********************************************************************
     * Function: PullToken
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    cToken *PullToken()
    {
        cToken *token;

        if ((token=m_tokens.PullItem()))
            m_free_tokens.PushItem(*token);

        return token;
    }
    /**
     **********************************************************************
     * Function: TopToken
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    cToken *TopToken()
    {
        return m_tokens.GetFirstItem();
    }
    /**
     **********************************************************************
     * Function: BottomToken
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    cToken *BottomToken()
    {
        return m_tokens.GetLastItem();
    }

    /**
     **********************************************************************
     * Function: OnSwitchState
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnSwitchState
    (const char* text, int token) 
    {
        yy_switch_state(token);
    }
    /**
     **********************************************************************
     * Function: OnPushState
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnPushState
    (const char* text, int token) 
    {
        yy_push_state(token);
    }
    /**
     **********************************************************************
     * Function: OnPopState
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnPopState
    (const char* text, int token) 
    {
        yy_pop_state();
    }

    /**
     **********************************************************************
     * Function: yywrap
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    virtual int yywrap()
    {
        cInclude* include;

        if ((include = m_includes.PopItem()))
        {
            yy_restore_scan_state(include->m_state);
            delete include;
            return 0;
        }
        return 1;
    }

};
#endif /* _CYYLEXER_AGAIN */
