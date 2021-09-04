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
 *   File: clexertoken.hxx
 *
 * Author: $author$
 *   Date: 5/2/2008
 **********************************************************************
 */
#ifndef _CLEXERTOKEN_HXX
#define _CLEXERTOKEN_HXX

#include "clist.hxx"
#include "cstring.hxx"

    /**
     **********************************************************************
     *  Class: cLexerToken
     *
     * Author: $author$
     *   Date: 8/25/2003
     **********************************************************************
     */
    class cLexerToken
    : public cDynamicListItemT<cLexerToken>
    {
    public:
        typedef cDynamicListItemT<cLexerToken> cExtends;

        cCharString m_buffer;

        /**
         **********************************************************************
         * Constructor: cLexerToken
         *
         *      Author: $author$
         *        Date: 8/25/2003
         **********************************************************************
         */
        cLexerToken(const char *token=0,int len=-1) 
        {
            if (token)
                Set(token,len);
        }
        /**
         **********************************************************************
         * Function: Set
         *
         *   Author: $author$
         *     Date: 8/25/2003
         **********************************************************************
         */
        int Set(const char *token,int len=-1)
        {
            return m_buffer.Assign(token,len);
        }
        /**
         **********************************************************************
         * Function: SetUpper
         *
         *   Author: $author$
         *     Date: 8/1/2008
         **********************************************************************
         */
        int SetUpper(const char *token,int len=-1)
        {
            return m_buffer.AssignUpper(token,len);
        }
        /**
         **********************************************************************
         * Function: SetLower
         *
         *   Author: $author$
         *     Date: 8/1/2008
         **********************************************************************
         */
        int SetLower(const char *token,int len=-1)
        {
            return m_buffer.AssignLower(token,len);
        }
        /**
         **********************************************************************
         * Function: SetEscaped
         *
         *   Author: $author$
         *     Date: 8/25/2003
         **********************************************************************
         */
        int SetEscaped(const char *token,int len=-1)
        {
            return m_buffer.Assign/*Escaped*/(token,len);
        }
        /**
         **********************************************************************
         * Function: Add
         *
         *   Author: $author$
         *     Date: 8/25/2003
         **********************************************************************
         */
        int Add(const char *token,int len=-1)
        {
            return m_buffer.Write(token,len);
        }
        /**
         **********************************************************************
         * Function: AddUpper
         *
         *   Author: $author$
         *     Date: 8/1/2008
         **********************************************************************
         */
        int AddUpper(const char *token,int len=-1)
        {
            return m_buffer.AppendUpper(token,len);
        }
        /**
         **********************************************************************
         * Function: AddLower
         *
         *   Author: $author$
         *     Date: 8/1/2008
         **********************************************************************
         */
        int AddLower(const char *token,int len=-1)
        {
            return m_buffer.AppendLower(token,len);
        }
        /**
         **********************************************************************
         * Function: AddEscaped
         *
         *   Author: $author$
         *     Date: 8/25/2003
         **********************************************************************
         */
        int AddEscaped(const char *token,int len=-1)
        {
            return m_buffer.Write/*Escaped*/(token,len);
        }
        /**
         **********************************************************************
         * Function: GetBuffer
         *
         *   Author: $author$
         *     Date: 8/25/2003
         **********************************************************************
         */
        inline const char *Get()
        {
            TLENGTH length;
            return m_buffer.Chars(length);
        }
        /**
         **********************************************************************
         * Function: GetStream
         *
         *   Author: $author$
         *     Date: 8/25/2003
         **********************************************************************
         */
        inline cCharStreamInterface& GetStream()
        {
            return m_buffer;
        }
    };

    /**
     **********************************************************************
     *  Class: cEscapedLexerToken
     *
     * Author: $author$
     *   Date: 8/25/2003
     **********************************************************************
     */
    class cEscapedLexerToken
    : public cLexerToken
    {
    public:
        typedef cLexerToken cExtends;
        /**
         **********************************************************************
         * Constructor: cEscapedLexerToken
         *
         *      Author: $author$
         *        Date: 8/25/2003
         **********************************************************************
         */
        cEscapedLexerToken(const char *token,int len=-1) 
        {
            if (token) SetEscaped(token,len);
        }
    };
    /**
     **********************************************************************
     *  Class: cUpperLexerToken
     *
     * Author: $author$
     *   Date: 8/1/2008
     **********************************************************************
     */
    class cUpperLexerToken
    : public cLexerToken
    {
    public:
        typedef cLexerToken cExtends;
        typedef cUpperLexerToken cDerives;
        /**
         **********************************************************************
         * Constructor: cUpperLexerToken
         *
         *      Author: $author$
         *        Date: 8/1/2008
         **********************************************************************
         */
        cUpperLexerToken
        (const char *token,
         int len=-1) 
        {
            if(token) SetUpper(token,len);
        }
    };
    /**
     **********************************************************************
     *  Class: cLowerLexerToken
     *
     * Author: $author$
     *   Date: 8/1/2008
     **********************************************************************
     */
    class cLowerLexerToken
    : public cLexerToken
    {
    public:
        typedef cLexerToken cExtends;
        typedef cLowerLexerToken cDerives;
        /**
         **********************************************************************
         * Constructor: cLowerLexerToken
         *
         *      Author: $author$
         *        Date: 8/1/2008
         **********************************************************************
         */
        cLowerLexerToken
        (const char *token,
         int len=-1) 
        {
            if(token) SetLower(token,len);
        }
    };

    /**
     **********************************************************************
     *  Class: cLexerTokens
     *
     * Author: $author$
     *   Date: 8/25/2003
     **********************************************************************
     */
    class cLexerTokens
    : public cDynamicListT<cLexerToken>
    {
    public:
        typedef cDynamicListT<cLexerToken> cExtends;
    };

#endif /* _CLEXERTOKEN_HXX */
