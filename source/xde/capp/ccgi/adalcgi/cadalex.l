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
 *   File: cadalex.l
 *
 * Author: $author$
 *   Date: 6/13/2008
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
SP                    [ \t]
WS                    [ \t\r\n]
NOT_SP                [^ \t]
NOT_WS                [^ \t\r\n]

/*
 * includes
 */
%{
#include "cacparse.h"
#include "cadalexer.hxx"
#define XXSwitch(on, text, token) on(text, token); OnSwitch(text, token)
#define XXPush(on, text, token) on(text, token); OnPush(text, token)
#define XXPop(on, text, token) on(text, token); OnPop(text, token)
#define XXReturn(on, text, token) on(text, token); return token
#define XX(on, text, token) on(text, token)
%}

/*
 * options
 */
%option yylineno
%x COMMENT COMMENT2 COMMENTLN PPROCESS IMPORT

/*
 * rules
 */
%%

<INITIAL>{
"--"             { XXPush(OnBeginCommentLN, yytext, COMMENTLN); }
"-*"             { XXPush(OnBeginComment, yytext, COMMENT); }
"-/"             { XXPush(OnBeginComment, yytext, COMMENT2); }

 /*
  * Ada keywords
  */
"abort"          { XX(OnReserved, yytext, 0); }
"abs"            { XX(OnReserved, yytext, 0); }
"accept"         { XX(OnReserved, yytext, 0); }
"access"         { XX(OnReserved, yytext, 0); }
"all"            { XX(OnReserved, yytext, 0); }
"and"            { XX(OnReserved, yytext, 0); }
"array"          { XX(OnReserved, yytext, 0); }
"at"             { XX(OnReserved, yytext, 0); }
"begin"          { XX(OnReserved, yytext, 0); }
"body"           { XX(OnReserved, yytext, 0); }
"case"           { XX(OnReserved, yytext, 0); }
"constant"       { XX(OnReserved, yytext, 0); }
"declare"        { XX(OnReserved, yytext, 0); }
"delay"          { XX(OnReserved, yytext, 0); }
"delta"          { XX(OnReserved, yytext, 0); }
"digits"         { XX(OnReserved, yytext, 0); }
"do"             { XX(OnReserved, yytext, 0); }
"else"           { XX(OnReserved, yytext, 0); }
"elsif"          { XX(OnReserved, yytext, 0); }
"end"            { XX(OnReserved, yytext, 0); }
"entry"          { XX(OnReserved, yytext, 0); }
"exception"      { XX(OnReserved, yytext, 0); }
"exit"           { XX(OnReserved, yytext, 0); }
"for"            { XX(OnReserved, yytext, 0); }
"function"       { XX(OnReserved, yytext, 0); }
"generic"        { XX(OnReserved, yytext, 0); }
"goto"           { XX(OnReserved, yytext, 0); }
"if"             { XX(OnReserved, yytext, 0); }
"in"             { XX(OnReserved, yytext, 0); }
"is"             { XX(OnReserved, yytext, 0); }
"limited"        { XX(OnReserved, yytext, 0); }
"loop"           { XX(OnReserved, yytext, 0); }
"mod"            { XX(OnReserved, yytext, 0); }
"new"            { XX(OnReserved, yytext, 0); }
"not"            { XX(OnReserved, yytext, 0); }
"null"           { XX(OnReserved, yytext, 0); }
"of"             { XX(OnReserved, yytext, 0); }
"or"             { XX(OnReserved, yytext, 0); }
"others"         { XX(OnReserved, yytext, 0); }
"out"            { XX(OnReserved, yytext, 0); }
"package"        { XX(OnReserved, yytext, 0); }
"pragma"         { XX(OnReserved, yytext, 0); }
"private"        { XX(OnReserved, yytext, 0); }
"procedure"      { XX(OnReserved, yytext, 0); }
"raise"          { XX(OnReserved, yytext, 0); }
"range"          { XX(OnReserved, yytext, 0); }
"record"         { XX(OnReserved, yytext, 0); }
"rem"            { XX(OnReserved, yytext, 0); }
"renames"        { XX(OnReserved, yytext, 0); }
"return"         { XX(OnReserved, yytext, 0); }
"reverse"        { XX(OnReserved, yytext, 0); }
"select"         { XX(OnReserved, yytext, 0); }
"separate"       { XX(OnReserved, yytext, 0); }
"subtype"        { XX(OnReserved, yytext, 0); }
"task"           { XX(OnReserved, yytext, 0); }
"terminate"      { XX(OnReserved, yytext, 0); }
"then"           { XX(OnReserved, yytext, 0); }
"type"           { XX(OnReserved, yytext, 0); }
"use"            { XX(OnReserved, yytext, 0); }
"when"           { XX(OnReserved, yytext, 0); }
"while"          { XX(OnReserved, yytext, 0); }
"with"           { XX(OnReserved, yytext, 0); }
"xor"            { XX(OnReserved, yytext, 0); }
 /*
  * Ada 95 keywords
  */
"abstract"       { XX(OnReservedX, yytext, 0); }
"aliased"        { XX(OnReservedX, yytext, 0); }
"protected"      { XX(OnReservedX, yytext, 0); }
"requeue"        { XX(OnReservedX, yytext, 0); }
"tagged"         { XX(OnReservedX, yytext, 0); }
"until"          { XX(OnReservedX, yytext, 0); }
 /*
  * Ada 2005 keywords
  */
"interface"      { XX(OnReservedX, yytext, 0); }
"overriding"     { XX(OnReservedX, yytext, 0); }
"synchronized"   { XX(OnReservedX, yytext, 0); }
 /*
  * Ada** keywords
  */
"absolute"       { XX(OnReservedY, yytext, ABSOLUTE_); }
"at"             { XX(OnReservedY, yytext, AT_); }
"by"             { XX(OnReservedY, yytext, BY_); }
"catch"          { XX(OnReservedY, yytext, CATCH_); }
"constructor"    { XX(OnReservedY, yytext, CONSTRUCTOR_); }
"delete"         { XX(OnReservedY, yytext, DELETE_); }
"destructor"     { XX(OnReservedY, yytext, DESTRUCTOR_); }
"dispose"        { XX(OnReservedY, yytext, DISPOSE_); }
"downto"         { XX(OnReservedY, yytext, DOWNTO_); }
"elseif"         { XX(OnReservedY, yytext, ELSEIF_); }
"enumerate"      { XX(OnReservedY, yytext, ENUMERATE_); }
"extends"        { XX(OnReservedY, yytext, EXTENDS_); }
"external"       { XX(OnReservedY, yytext, EXTERNAL_); }
"implements"     { XX(OnReservedY, yytext, IMPLEMENTS_); }
"interrupt"      { XX(OnReservedY, yytext, INTERRUPT_); }
"ln"             { XX(OnReservedY, yytext, LN_); }
"log"            { XX(OnReservedY, yytext, LOG_); }
"object"         { XX(OnReservedY, yytext, OBJECT_); }
"otherwise"      { XX(OnReservedY, yytext, OTHERWISE_); }
"packed"         { XX(OnReservedY, yytext, PACKED_); }
"parallel"       { XX(OnReservedY, yytext, PARALLEL_); }
"program"        { XX(OnReservedY, yytext, PROGRAM_); }
"public"         { XX(OnReservedY, yytext, PUBLIC_); }
"remote"         { XX(OnReservedY, yytext, REMOTE_); }
"repeat"         { XX(OnReservedY, yytext, REPEAT_); }
"serial"         { XX(OnReservedY, yytext, SERIAL_); }
"signed"         { XX(OnReservedY, yytext, SIGNED_); }
"static"         { XX(OnReservedY, yytext, STATIC_); }
"structure"      { XX(OnReservedY, yytext, STRUCTURE_); }
"this"           { XX(OnReservedY, yytext, THIS__); }
"throw"          { XX(OnReservedY, yytext, THROW_); }
"to"             { XX(OnReservedY, yytext, TO_); }
"try"            { XX(OnReservedY, yytext, TRY_); }
"unsigned"       { XX(OnReservedY, yytext, UNSIGNED_); }
"union"          { XX(OnReservedY, yytext, UNION_); }
"virtual"        { XX(OnReservedY, yytext, VIRTUAL_); }
"volatile"       { XX(OnReservedY, yytext, VOLATILE_); }
"where"          { XX(OnReservedY, yytext, WHERE_); }

 /*
  * Ada** operators
  */
"<<:="           { XX(OnReservedY, yytext, 0); }
">>:="           { XX(OnReservedY, yytext, 0); }
"**:="           { XX(OnReservedY, yytext, 0); }
"//:="           { XX(OnReservedY, yytext, 0); }
"%%:="           { XX(OnReservedY, yytext, 0); }

"*:="            { XX(OnReservedY, yytext, 0); }
"/:="            { XX(OnReservedY, yytext, 0); }
"%:="            { XX(OnReservedY, yytext, 0); }
"+:="            { XX(OnReservedY, yytext, 0); }
"-:="            { XX(OnReservedY, yytext, 0); }
"&:="            { XX(OnReservedY, yytext, 0); }
"|:="            { XX(OnReservedY, yytext, 0); }
"!:="            { XX(OnReservedY, yytext, 0); }
"^:="            { XX(OnReservedY, yytext, 0); }

":<<"            { XX(OnReservedY, yytext, 0); }
":>>"            { XX(OnReservedY, yytext, 0); }
":++"            { XX(OnReservedY, yytext, 0); }
":--"            { XX(OnReservedY, yytext, 0); }
"..."            { XX(OnReservedY, yytext, 0); }
"//"             { XX(OnReservedY, yytext, 0); }
"%%"             { XX(OnReservedY, yytext, 0); }
  
 /*
  * Ada operators
  */
"<="            { XX(OnReserved, yytext, 0); }
">="            { XX(OnReserved, yytext, 0); }
"/="            { XX(OnReserved, yytext, 0); }
"<>"            { XX(OnReserved, yytext, 0); }
":="            { XX(OnReserved, yytext, 0); }

"=>"            { XX(OnReserved, yytext, 0); }
".."            { XX(OnReserved, yytext, 0); }
"**"            { XX(OnReserved, yytext, 0); }
"<<"            { XX(OnReserved, yytext, 0); }
">>"            { XX(OnReserved, yytext, 0); }

 /*
  * Ada operators
  */
"&"            { XX(OnReserved, yytext, 0); }
"|"            { XX(OnReserved, yytext, 0); }

"+"            { XX(OnReserved, yytext, 0); }
"-"            { XX(OnReserved, yytext, 0); }
"*"            { XX(OnReserved, yytext, 0); }
"/"            { XX(OnReserved, yytext, 0); }

"<"            { XX(OnReserved, yytext, 0); }
">"            { XX(OnReserved, yytext, 0); }
"="            { XX(OnReserved, yytext, 0); }

"#"({L}({L}|{D})*)* { XXPush(OnProcessor, yytext, PPROCESS); }

"<<"{L}({L}|{D})*">>" { XX(OnDefine, yytext, 0); }

\"(\\.|[^\\"])*\" { XX(OnString, yytext, 0); }
\'(\\.|[^\\'])\'  { XX(OnChar, yytext, 0); }

{L}({L}|{D})*    { XX(OnText, yytext, 0); }
}

<IMPORT>{
\"(\\.|[^\\"])*\"         { XX(OnIncludeL, yytext, 0); }
\<(\\.|[^\\>])*\>         { XX(OnIncludeL, yytext, 0); }
({L}|[\.])({L}|{D}|[\.])* { XX(OnImportL, yytext, 0); }
";"                       { XXPop(OnText, yytext, IMPORT);}
}

<COMMENT>{
"*-"             { XXPop(OnEndComment, yytext, COMMENT); }
}

<COMMENT2>{
"/-"             { XXPop(OnEndComment, yytext, COMMENT2); }
}

<COMMENTLN>{
\n               { XXPop(OnEndCommentLN, yytext, COMMENTLN); }
}

<PPROCESS>{
"--"             { XXSwitch(OnBeginCommentLN, yytext, COMMENTLN); }
"-*"             { XXPush(OnBeginComment, yytext, COMMENT); }
"-/"             { XXPush(OnBeginComment, yytext, COMMENT2); }
\n               { XXPop(OnText, yytext, PPROCESS); }
}

<*>{
"<"              { XX(OnLT, yytext, 0); }
">"              { XX(OnGT, yytext, 0); }
\n|.             { XX(OnText, yytext, 0); }
}

%%
