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
 *   File: ccxxcgilex.l
 *
 * Author: $author$
 *   Date: 5/3/2008
 **********************************************************************
 */

/*
 * defines
 */
B                     [0-1]
O                     [0-7]
D                     [0-9]
N                     [1-9]
H                     [0-9a-fA-F]
L                     [a-zA-Z_]
E                     [Ee][+-]?{D}+
F                     (f|F)
U                     (u|U)
S                     (l|L)

/*
 * includes
 */
%{
#include "ccxxcgilex.h"
#include "ccxxcgilexer.hxx"
%}

/*
 * options
 */
%option yylineno
%x FINAL BODY BEFORE AFTER COMMENTEOL

/*
 * rules
 */
%%
<INITIAL>{
"%%"                  { OnCXXCGIBeginBody(yytext, BODY); }
"%#"                  { OnCXXCGIBeginComment(yytext, COMMENTEOL); }
(\n|.)                { OnCXXCGIText(yytext); }
}

<FINAL>{
"%#"                  { OnCXXCGIBeginComment(yytext, COMMENTEOL); }
(\n|.)                { OnCXXCGIText(yytext); }
}

<BODY>{
"%"([^%]|[ \t\r\n])+  { OnCXXCGIBeginBefore(yytext+1, BEFORE); }
"%%"                  { OnCXXCGIEndBody(yytext, FINAL); }
"%#"                  { OnCXXCGIBeginComment(yytext, COMMENTEOL); }
(\n|.)                { }
}

<BEFORE>{
"%"[ \t\r\n]*"/*...*/"[ \t\r\n]*"%" { OnCXXCGIBeforeComment(yytext); OnCXXCGIEndBefore(yytext, AFTER); }
"%"[ \t\r\n]*"//..."[ \t\r\n]*"%"   { OnCXXCGIBeforeCommentEOL(yytext); OnCXXCGIEndBefore(yytext, AFTER); }
"%"[ \t\r\n]*"#..."[ \t\r\n]*"%"    { OnCXXCGIBeforeProcessor(yytext); OnCXXCGIEndBefore(yytext, AFTER); }
"%"[ \t\r\n]*"..."[ \t\r\n]*"%"     { OnCXXCGIBeforeKeyword(yytext); OnCXXCGIEndBefore(yytext, AFTER); }
"%"[ \t\r\n]*\""..."\"[ \t\r\n]*"%" { OnCXXCGIBeforeString(yytext); OnCXXCGIEndBefore(yytext, AFTER); }
"%"[ \t\r\n]*\'"..."\'[ \t\r\n]*"%" { OnCXXCGIBeforeChar(yytext); OnCXXCGIEndBefore(yytext, AFTER); }
"%"([^%]|\n)*"%"                    { OnCXXCGIEndBefore(yytext, AFTER); }
}

<AFTER>{
([^%]|\n)            { OnCXXCGIAfterText(yytext); }
"%"                  { OnCXXCGIEndAfter(yytext, AFTER); }
}

<COMMENTEOL>{
\n                    { OnCXXCGIEndComment(yytext, COMMENTEOL); }
(W|.)                 { }
}
%%
