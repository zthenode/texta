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
#include "ccxxlexer.hxx"
#define XXSwitch(on, text, token) on(text, token); OnSwitch(text, token)
#define XXPush(on, text, token) on(text, token); OnPush(text, token)
#define XXPop(on, text, token) on(text, token); OnPop(text, token)
#define XX(on, text, token) on(text, token)
%}

%option yylineno
%x COMMENT COMMENTLN INCLUDE

%%

<INITIAL>{
"/*"                 { XXPush(OnBeginComment, yytext, COMMENT); }
"//"                 { XXPush(OnBeginCommentLN, yytext, COMMENTLN); }

"do"                  { XX(OnReserved, yytext, 0); }
"while"               { XX(OnReserved, yytext, 0); }
"for"                 { XX(OnReserved, yytext, 0); }
"switch"              { XX(OnReserved, yytext, 0); }
"case"                { XX(OnReserved, yytext, 0); }
"default"             { XX(OnReserved, yytext, 0); }
"if"                  { XX(OnReserved, yytext, 0); }
"else"                { XX(OnReserved, yytext, 0); }
"try"                 { XX(OnReserved, yytext, 0); }
"catch"               { XX(OnReserved, yytext, 0); }
"throw"               { XX(OnReserved, yytext, 0); }
"break"               { XX(OnReserved, yytext, 0); }
"continue"            { XX(OnReserved, yytext, 0); }
"return"              { XX(OnReserved, yytext, 0); }

"sizeof"              { XX(OnReserved, yytext, 0); }

"const"               { XX(OnReserved, yytext, 0); }
"volatile"            { XX(OnReserved, yytext, 0); }
"extern"              { XX(OnReserved, yytext, 0); }
"static"              { XX(OnReserved, yytext, 0); }
"inline"              { XX(OnReserved, yytext, 0); }
"virtual"             { XX(OnReserved, yytext, 0); }
"explicit"            { XX(OnReserved, yytext, 0); }

"public"              { XX(OnReserved, yytext, 0); }
"private"             { XX(OnReserved, yytext, 0); }
"protected"           { XX(OnReserved, yytext, 0); }
"friend"              { XX(OnReserved, yytext, 0); }

"using"               { XX(OnReserved, yytext, 0); }
"namespace"           { XX(OnReserved, yytext, 0); }
"template"            { XX(OnReserved, yytext, 0); }
"typedef"             { XX(OnReserved, yytext, 0); }
"typename"            { XX(OnReserved, yytext, 0); }

"class"               { XX(OnReserved, yytext, 0); }
"struct"              { XX(OnReserved, yytext, 0); }
"union"               { XX(OnReserved, yytext, 0); }
"enum"                { XX(OnReserved, yytext, 0); }
"void"                { XX(OnReserved, yytext, 0); }
"bool"                { XX(OnReserved, yytext, 0); }
"char"                { XX(OnReserved, yytext, 0); }
"float"               { XX(OnReserved, yytext, 0); }
"double"              { XX(OnReserved, yytext, 0); }
"int"                 { XX(OnReserved, yytext, 0); }
"short"               { XX(OnReserved, yytext, 0); }
"long"                { XX(OnReserved, yytext, 0); }
"signed"              { XX(OnReserved, yytext, 0); }
"unsigned"            { XX(OnReserved, yytext, 0); }

\"(\\.|[^\\"])*\"     { XX(OnString, yytext, 0); }
\'(\\.|[^\\'])*\'     { XX(OnChar, yytext, 0); }

"#include"            { XXPush(OnProcessor, yytext, INCLUDE); }
"#import"             { XXPush(OnProcessor, yytext, INCLUDE); }
"#"{L}({L}|{D})*      { XX(OnProcessor, yytext, 0); }
"@"{L}({L}|{D})*      { XX(OnProcessor, yytext, 0); }
{L}({L}|{D})*         { XX(OnText, yytext, 0); }
}

<INCLUDE>{
\"(\\.|[^\\"])*\"     { XX(OnIncludeL, yytext, 0); }
\<(\\.|[^\\>])*\>     { XX(OnIncludeL, yytext, 0); }
\n                    { XXPop(OnText, yytext, INCLUDE);}
}

<COMMENT>{
"*/"                  { XXPop(OnEndComment, yytext, COMMENT);}
}

<COMMENTLN>{
\n                    { XXPop(OnEndCommentLN, yytext, COMMENTLN);}
}

<*>{
"<"                  { XX(OnLT, yytext, 0);}
">"                  { XX(OnGT, yytext, 0);}
\n|.                 { XX(OnText, yytext, 0);}
}

%%
