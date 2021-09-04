/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$.
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

B                      [0-1]
O                      [0-7]
D                      [0-9]
N                      [1-9]
H                      [0-9a-fA-F]
L                      [a-zA-Z_]
E                      [Ee][+-]?{D}+
F                      (f|F)
U                      (u|U)
S                      (l|L)

SP                      [ \t]
WS                      [ \t\r\n]

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
"/*"                     { XXPush(OnBeginComment, yytext, COMMENT); }
"//"                     { XXPush(OnBeginCommentLN, yytext, COMMENTLN); }

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
"goto"                { XX(OnReserved, yytext, 0); }
"continue"            { XX(OnReserved, yytext, 0); }
"return"              { XX(OnReserved, yytext, 0); }

"new"             { XX(OnReserved, yytext, 0); }
"delete"          { XX(OnReserved, yytext, 0); }
"sizeof"          { XX(OnReserved, yytext, 0); }
"this"            { XX(OnReserved, yytext, 0); }

"auto"            { XX(OnReserved, yytext, 0); }
"const"           { XX(OnReserved, yytext, 0); }
"register"        { XX(OnReserved, yytext, 0); }
"volatile"        { XX(OnReserved, yytext, 0); }
"extern"          { XX(OnReserved, yytext, 0); }
"static"          { XX(OnReserved, yytext, 0); }
"inline"          { XX(OnReserved, yytext, 0); }
"virtual"         { XX(OnReserved, yytext, 0); }
"explicit"        { XX(OnReserved, yytext, 0); }

"public"              { XX(OnReserved, yytext, 0); }
"private"             { XX(OnReserved, yytext, 0); }
"protected"           { XX(OnReserved, yytext, 0); }
"friend"              { XX(OnReserved, yytext, 0); }
"mutable"             { XX(OnReserved, yytext, 0); }

"using"               { XX(OnReserved, yytext, 0); }
"namespace"           { XX(OnReserved, yytext, 0); }
"template"            { XX(OnReserved, yytext, 0); }
"typedef"             { XX(OnReserved, yytext, 0); }
"typename"            { XX(OnReserved, yytext, 0); }
"typeid"              { XX(OnReserved, yytext, 0); }

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

"false"               { XX(OnReserved, yytext, 0); }
"true"                { XX(OnReserved, yytext, 0); }

"not"             { XX(OnReservedX, yytext, 0); }
"and"             { XX(OnReservedX, yytext, 0); }
"xor"             { XX(OnReservedX, yytext, 0); }
"or"              { XX(OnReservedX, yytext, 0); }

"binary"              { XX(OnReservedX, yytext, 0); }
"one"                 { XX(OnReservedX, yytext, 0); }
"zero"                { XX(OnReservedX, yytext, 0); }
"real"                { XX(OnReservedX, yytext, 0); }
"integer"             { XX(OnReservedX, yytext, 0); }
"cardinal"            { XX(OnReservedX, yytext, 0); }

"abstract"            { XX(OnReservedX, yytext, 0); }
"array"               { XX(OnReservedX, yytext, 0); }
"as"                  { XX(OnReservedX, yytext, 0); }
"base"                { XX(OnReservedX, yytext, 0); }
"byte"                { XX(OnReservedX, yytext, 0); }
"checked"             { XX(OnReservedX, yytext, 0); }
"decimal"             { XX(OnReservedX, yytext, 0); }
"delegate"            { XX(OnReservedX, yytext, 0); }
"each"               { XX(OnReservedX, yytext, 0); }
"event"              { XX(OnReservedX, yytext, 0); }
"finally"            { XX(OnReservedX, yytext, 0); }
"fixed"              { XX(OnReservedX, yytext, 0); }
"foreach"            { XX(OnReservedX, yytext, 0); }
"implicit"           { XX(OnReservedX, yytext, 0); }
"in"                 { XX(OnReservedX, yytext, 0); }
"inout"              { XX(OnReservedX, yytext, 0); }
"interface"          { XX(OnReservedX, yytext, 0); }
"internal"           { XX(OnReservedX, yytext, 0); }
"is"                 { XX(OnReservedX, yytext, 0); }
"lock"               { XX(OnReservedX, yytext, 0); }
"object"             { XX(OnReservedX, yytext, 0); }
"out"                { XX(OnReservedX, yytext, 0); }
"overload"           { XX(OnReservedX, yytext, 0); }
"override"           { XX(OnReservedX, yytext, 0); }
"params"             { XX(OnReservedX, yytext, 0); }
"partial"            { XX(OnReservedX, yytext, 0); }
"readonly"           { XX(OnReservedX, yytext, 0); }
"ref"                { XX(OnReservedX, yytext, 0); }
"sbyte"              { XX(OnReservedX, yytext, 0); }
"sealed"             { XX(OnReservedX, yytext, 0); }
"stackalloc"         { XX(OnReservedX, yytext, 0); }
"string"             { XX(OnReservedX, yytext, 0); }
"typeof"             { XX(OnReservedX, yytext, 0); }
"uint"               { XX(OnReservedX, yytext, 0); }
"ulong"              { XX(OnReservedX, yytext, 0); }
"unchecked"          { XX(OnReservedX, yytext, 0); }
"unsafe"             { XX(OnReservedX, yytext, 0); }
"ushort"             { XX(OnReservedX, yytext, 0); }
"using"              { XX(OnReservedX, yytext, 0); }

"assert"             { XX(OnReservedY, yytext, 0); }
"atomic"             { XX(OnReservedY, yytext, 0); }
"nonatomic"          { XX(OnReservedY, yytext, 0); }
"based"              { XX(OnReservedY, yytext, 0); }
"derive"             { XX(OnReservedY, yytext, 0); }
"derived"            { XX(OnReservedY, yytext, 0); }
"derives"            { XX(OnReservedY, yytext, 0); }
"dynamic"            { XX(OnReservedY, yytext, 0); }
"boolean"            { XX(OnReservedY, yytext, 0); }
"extended"           { XX(OnReservedY, yytext, 0); }
"extends"            { XX(OnReservedY, yytext, 0); }
"extend"             { XX(OnReservedY, yytext, 0); }
"final"              { XX(OnReservedY, yytext, 0); }
"id"                 { XX(OnReservedY, yytext, 0); }
"implementation"     { XX(OnReservedY, yytext, 0); }
"implemented"        { XX(OnReservedY, yytext, 0); }
"implements"         { XX(OnReservedY, yytext, 0); }
"implement"          { XX(OnReservedY, yytext, 0); }
"import"             { XX(OnReservedY, yytext, 0); }
"instanceof"         { XX(OnReservedY, yytext, 0); }
"native"             { XX(OnReservedY, yytext, 0); }
"nil"                { XX(OnReservedY, yytext, 0); }
"package"            { XX(OnReservedY, yytext, 0); }
"property"           { XX(OnReservedX, yytext, 0); }
"protocol"           { XX(OnReservedX, yytext, 0); }
"domain"             { XX(OnReservedX, yytext, 0); }
"network"            { XX(OnReservedX, yytext, 0); }
"release"            { XX(OnReservedY, yytext, 0); }
"retain"             { XX(OnReservedY, yytext, 0); }
"restrict"           { XX(OnReservedY, yytext, 0); }
"selector"           { XX(OnReservedY, yytext, 0); }
"strictfp"           { XX(OnReservedY, yytext, 0); }
"self"               { XX(OnReservedY, yytext, 0); }
"super"              { XX(OnReservedY, yytext, 0); }
"synchronized"       { XX(OnReservedY, yytext, 0); }
"throws"             { XX(OnReservedY, yytext, 0); }
"transient"          { XX(OnReservedY, yytext, 0); }

\"(\\.|[^\\"])*\"     { XX(OnString, yytext, 0); }
\'(\\.|[^\\'])*\'     { XX(OnChar, yytext, 0); }

"#include"            { XXPush(OnProcessor, yytext, INCLUDE); }
"#import"             { XXPush(OnProcessor, yytext, INCLUDE); }
"#"{L}({L}|{D})*      { XX(OnProcessor, yytext, 0); }
"@"{L}({L}|{D})*      { XX(OnProcessor, yytext, 0); }
"defined"             { XX(OnProcessor, yytext, 0); }
{L}({L}|{D})*         { XX(OnText, yytext, 0); }
}

<INCLUDE>{
\"(\\.|[^\\"])*\"     { XX(OnIncludeL, yytext, 0); }
\<(\\.|[^\\>])*\>     { XX(OnIncludeL, yytext, 0); }
\n                    { XXPop(OnText, yytext, INCLUDE);}
}

<COMMENT>{
"*/"                   { XXPop(OnEndComment, yytext, COMMENT);}
}

<COMMENTLN>{
\n                      { XXPop(OnEndCommentLN, yytext, COMMENTLN);}
}

<*>{
"<"                     { XX(OnLT, yytext, 0);}
">"                     { XX(OnGT, yytext, 0);}
\n|.                    { XX(OnText, yytext, 0);}
}

%%
