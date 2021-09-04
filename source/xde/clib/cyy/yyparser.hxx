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
 *   File: yyparser.hxx
 *
 * Author: $author$
 *   Date: 8/26/2003
 *
 *    $Id$
 *
 * This file defines yyAnyParser, an abstract class which specifies the
 * external interface provided to yacc C++ parser objects, and yyParser,
 * which defines a particular parser class.
 *
 * If you want to create multiple parser classes, you use the -b flag
 * to rename each yyParser to some other xxParser.  You then
 * include <yyparser.hxx> in your other sources once per parser class:
 *
 *	#undef yyParser
 *	#define yyParser xxParser
 *	#include <yyparser.hxx>
 *
 *	#undef yyParser
 *	#define yyParser zzParser
 *	#include <yyparser.hxx>
 *	...
 **********************************************************************
 */
#ifndef _YYPARSER_HXX
#define _YYPARSER_HXX

#include "cerror.hxx"
#include "cstream.hxx"

/**
 **********************************************************************
 *  Class: yyAnyParser
 *
 * Author: $author$
 *   Date: 8/26/2003
 **********************************************************************
 */
class yyAnyParser
: public cError
{
public:
    typedef cError cExtends;

    /**
     **********************************************************************
     * Function: yyparse
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual int yyparse()=0;
};

#endif /* #ifndef _YYPARSER_HXX */

#ifndef _YYPARSER_AGAIN
#define _YYPARSER_AGAIN

/**
 **********************************************************************
 *  Class: yyIsParser
 *
 * Author: $author$
 *   Date: 8/26/2003
 **********************************************************************
 */
class yyIsParser
: public yyAnyParser
{
public:
    typedef yyAnyParser cExtends;

    /**
     **********************************************************************
     * Constructor: yyIsParser
     *
     *      Author: $author$
     *        Date: 8/26/2003
     **********************************************************************
     */
    yyIsParser();
    /**
     **********************************************************************
     * Destructor: ~yyIsParser
     *
     *     Author: $author$
     *       Date: 8/26/2003
     **********************************************************************
     */
    virtual ~yyIsParser();

    /**
     **********************************************************************
     * Function: yyinit
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual int yyinit();
    /**
     **********************************************************************
     * Function: yyfinish
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual void yyfinish();
    /**
     **********************************************************************
     * Function: yyoutofmemory
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual int yyoutofmemory();
    /**
     **********************************************************************
     * Function: yyerror
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual void yyerror(const char *msg);
    /**
     **********************************************************************
     * Function: yyprintf
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual int yyprintf(const char *format,...);
    /**
     **********************************************************************
     * Function: yylex
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual int yylex()=0;

protected:

    static short yylhs[];
    static short yylen[];
    static short yydefred[];
    static short yydgoto[];
    static short yysindex[];
    static short yyrindex[];
    static short yygindex[];
    static short yytable[];
    static short yycheck[];
    static char *yyname[];
    static char *yyrule[];

    int yydebug;
    int yynerrs;
    int yyerrflag;
    int yychar;
    short *yyssp;
    YYSTYPE *yyvsp;
    YYSTYPE yyval;
    YYSTYPE yylval;
    short *yyss;
    YYSTYPE *yyvs;
};

#ifndef yyParser

/**
 **********************************************************************
 *  Class: yyParser
 *
 * Author: $author$
 *   Date: 8/26/2003
 **********************************************************************
 */
class yyParser
: public yyIsParser
{
public:
    typedef yyIsParser cExtends;

    /**
     **********************************************************************
     * Function: yylex
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    int yylex();
    /**
     **********************************************************************
     * Function: yyparse
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    int yyparse();
};

#endif /* #ifndef yyParser */

#endif /* #ifndef _YYPARSER_AGAIN */
