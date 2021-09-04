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
 *   File: ccxxlex.l
 *
 * Author: $author$
 *   Date: 5/1/2008
 **********************************************************************
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

SP                    [ \t]
WS                    [ \t\r\n]

%{
#include "ccxxlex.h"
#include "ccxxlexer.hxx"
#define XXSwitch(on, text, token) on(text, token); OnSwitch(text, token)
#define XXPush(on, text, token) on(text, token); OnPush(text, token)
#define XXPop(on, text, token) on(text, token); OnPop(text, token)
#define XX(on, text, token) on(text, token)
%}

%option yylineno
%x COMMENT COMMENTEOL INCLUDE

%%

<INITIAL>{
"/*"                 { OnBeginComment(yytext, COMMENT); }
"//"                 { OnBeginCommentEOL(yytext, COMMENTEOL); }

"do"                  { OnReserved(yytext); }
"while"               { OnReserved(yytext); }
"for"                 { OnReserved(yytext); }
"switch"              { OnReserved(yytext); }
"case"                { OnReserved(yytext); }
"default"             { OnReserved(yytext); }
"if"                  { OnReserved(yytext); }
"else"                { OnReserved(yytext); }
"try"                 { OnReserved(yytext); }
"catch"               { OnReserved(yytext); }
"throw"               { OnReserved(yytext); }
"break"               { OnReserved(yytext); }
"continue"            { OnReserved(yytext); }
"return"              { OnReserved(yytext); }

"sizeof"              { OnReserved(yytext); }

"const"               { OnReserved(yytext); }
"volatile"            { OnReserved(yytext); }
"extern"              { OnReserved(yytext); }
"static"              { OnReserved(yytext); }
"inline"              { OnReserved(yytext); }
"virtual"             { OnReserved(yytext); }
"explicit"            { OnReserved(yytext); }

"public"              { OnReserved(yytext); }
"private"             { OnReserved(yytext); }
"protected"           { OnReserved(yytext); }
"friend"              { OnReserved(yytext); }

"using"               { OnReserved(yytext); }
"namespace"           { OnReserved(yytext); }
"template"            { OnReserved(yytext); }
"typedef"             { OnReserved(yytext); }
"typename"            { OnReserved(yytext); }

"class"               { OnReserved(yytext); }
"struct"              { OnReserved(yytext); }
"union"               { OnReserved(yytext); }
"enum"                { OnReserved(yytext); }
"void"                { OnReserved(yytext); }
"bool"                { OnReserved(yytext); }
"char"                { OnReserved(yytext); }
"float"               { OnReserved(yytext); }
"double"              { OnReserved(yytext); }
"int"                 { OnReserved(yytext); }
"short"               { OnReserved(yytext); }
"long"                { OnReserved(yytext); }
"signed"              { OnReserved(yytext); }
"unsigned"            { OnReserved(yytext); }

\"(\\.|[^\\"])*\"     { OnStringLiteral(yytext); }
\'(\\.|[^\\'])*\'     { OnCharLiteral(yytext); }

"#include"            { XXPush(OnProcessor, yytext, INCLUDE); }
"#"{L}({L}|{D})*      { OnProcessor(yytext); }
{L}({L}|{D})*         { OnText(yytext); }
}

<INCLUDE>{
\"(\\.|[^\\"])*\"     { OnIncluded(yytext); }
\<(\\.|[^\\>])*\>     { OnIncluded(yytext); }
\n                    { XXPop(OnText, yytext, INCLUDE);}
}

<COMMENT>{
"*/"                  { OnEndComment(yytext, COMMENT);}
\n|.                  { OnComment(yytext, COMMENT); }
}

<COMMENTEOL>{
\n                    { OnEndCommentEOL(yytext, COMMENTEOL);}
.                     { OnComment(yytext, COMMENTEOL); }
}

<*>{
"<"                  { OnLT(yytext);}
">"                  { OnGT(yytext);}
\n|.                 { OnText(yytext);}
}

%%
