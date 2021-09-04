/*
 * yyparser.hxx
 *
 * $author$
 * 2/13/97
 *
 * $Id$
 *
 * This file defines Flexer, an abstract class which specifies the
 * external interface provided to flex C++ lexer objects, and yyFlexer,
 * which defines a particular lexer class.
 *
 * If you want to create multiple lexer classes, you use the -P flag
 * to rename each yyFlexer to some other xxFlexer.  You then
 * include <Flexer.h> in your other sources once per lexer class:
 *
 *	#undef yyFlexer
 *	#define yyFlexer xxFlexer
 *	#include <Flexer.h>
 *
 *	#undef yyFlexer
 *	#define yyFlexer zzFlexer
 *	#include <Flexer.h>
 *	...
 */

#ifndef YYPARSER_HXX
#define YYPARSER_HXX

class yyAnyParser
{
public:
    virtual int yyparse()=0;
protected:
private:
};

#endif

#ifndef yyParserAgain
#define yyParserAgain

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

class yyIsParser: public yyAnyParser
{
public:
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

    yyIsParser();
    virtual ~yyIsParser();
    virtual int yyinit();
    virtual void yyfinish();
    virtual int yyoutofmemory();
    virtual void yyerror(const char *msg);
    virtual int yyprintf(const char *format,...);
    virtual int yylex()=0;
protected:
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
private:
};

class yyParser: public yyIsParser
{
public:
    int yylex();
    int yyparse();
};

#endif
