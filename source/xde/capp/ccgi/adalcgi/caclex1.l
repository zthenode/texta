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
 *   File: caclex.l
 *
 * Author: $author$
 *   Date: 7/30/2008
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
#include "caclexer.hxx"
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

/*
 * states
 */
%x COMMENT COMMENTX
 
/*
 * rules
 */
%%

<INITIAL>{
"--"             { XXPush(OnBeginComment, yytext, COMMENT); }
"-*"             { XXPush(OnBeginCommentX, yytext, COMMENTX); }

 /*
  * Ada keywords
  */
"abort"          { XXReturn(OnToken, yytext, ABORT_TOKEN); }
"abs"            { XXReturn(OnToken, yytext, ABS_TOKEN); }
"accept"         { XXReturn(OnToken, yytext, ACCEPT_TOKEN); }
"access"         { XXReturn(OnToken, yytext, ACCESS_TOKEN); }
"all"            { XXReturn(OnToken, yytext, ALL_TOKEN); }
"and"            { XXReturn(OnToken, yytext, AND_TOKEN); }
"array"          { XXReturn(OnToken, yytext, ARRAY_TOKEN); }
"at"             { XXReturn(OnToken, yytext, AT_TOKEN); }
"begin"          { XXReturn(OnToken, yytext, BEGIN_TOKEN); }
"body"           { XXReturn(OnToken, yytext, BODY_TOKEN); }
"case"           { XXReturn(OnToken, yytext, CASE_TOKEN); }
"constant"       { XXReturn(OnToken, yytext, CONSTANT_TOKEN); }
"declare"        { XXReturn(OnToken, yytext, DECLARE_TOKEN); }
"delay"          { XXReturn(OnToken, yytext, DELAY_TOKEN); }
"delta"          { XXReturn(OnToken, yytext, DELTA_TOKEN); }
"digits"         { XXReturn(OnToken, yytext, DIGITS_TOKEN); }
"else"           { XXReturn(OnToken, yytext, ELSE_TOKEN); }
"elsif"          { XXReturn(OnToken, yytext, ELSIF_TOKEN); }
"end"            { XXReturn(OnToken, yytext, END_TOKEN); }
"entry"          { XXReturn(OnToken, yytext, ENTRY_TOKEN); }
"exception"      { XXReturn(OnToken, yytext, EXCEPTION_TOKEN); }
"exit"           { XXReturn(OnToken, yytext, EXIT_TOKEN); }
"for"            { XXReturn(OnToken, yytext, FOR_TOKEN); }
"function"       { XXReturn(OnToken, yytext, FUNCTION_TOKEN); }
"generic"        { XXReturn(OnToken, yytext, GENERIC_TOKEN); }
"goto"           { XXReturn(OnToken, yytext, GOTO_TOKEN); }
"if"             { XXReturn(OnToken, yytext, IF_TOKEN); }
"in"             { XXReturn(OnToken, yytext, IN_TOKEN); }
"is"             { XXReturn(OnToken, yytext, IS_TOKEN); }
"limited"        { XXReturn(OnToken, yytext, LIMITED_TOKEN); }
"loop"           { XXReturn(OnToken, yytext, LOOP_TOKEN); }
"mod"            { XXReturn(OnToken, yytext, MOD_TOKEN); }
"new"            { XXReturn(OnToken, yytext, NEW_TOKEN); }
"not"            { XXReturn(OnToken, yytext, NOT_TOKEN); }
"null"           { XXReturn(OnToken, yytext, NULL_TOKEN); }
"of"             { XXReturn(OnToken, yytext, OF_TOKEN); }
"or"             { XXReturn(OnToken, yytext, OR_TOKEN); }
"others"         { XXReturn(OnToken, yytext, OTHERS_TOKEN); }
"out"            { XXReturn(OnToken, yytext, OUT_TOKEN); }
"package"        { XXReturn(OnToken, yytext, PACKAGE_TOKEN); }
"pragma"         { XXReturn(OnToken, yytext, PRAGMA_TOKEN); }
"private"        { XXReturn(OnToken, yytext, PRIVATE_TOKEN); }
"procedure"      { XXReturn(OnToken, yytext, PROCEDURE_TOKEN); }
"raise"          { XXReturn(OnToken, yytext, RAISE_TOKEN); }
"range"          { XXReturn(OnToken, yytext, RANGE_TOKEN); }
"record"         { XXReturn(OnToken, yytext, RECORD_TOKEN); }
"rem"            { XXReturn(OnToken, yytext, REM_TOKEN); }
"renames"        { XXReturn(OnToken, yytext, RENAMES_TOKEN); }
"return"         { XXReturn(OnToken, yytext, RETURN_TOKEN); }
"reverse"        { XXReturn(OnToken, yytext, REVERSE_TOKEN); }
"select"         { XXReturn(OnToken, yytext, SELECT_TOKEN); }
"separate"       { XXReturn(OnToken, yytext, SEPARATE_TOKEN); }
"subtype"        { XXReturn(OnToken, yytext, SUBTYPE_TOKEN); }
"task"           { XXReturn(OnToken, yytext, TASK_TOKEN); }
"terminate"      { XXReturn(OnToken, yytext, TERMINATE_TOKEN); }
"then"           { XXReturn(OnToken, yytext, THEN_TOKEN); }
"type"           { XXReturn(OnToken, yytext, TYPE_TOKEN); }
"use"            { XXReturn(OnToken, yytext, USE_TOKEN); }
"when"           { XXReturn(OnToken, yytext, WHEN_TOKEN); }
"while"          { XXReturn(OnToken, yytext, WHILE_TOKEN); }
"with"           { XXReturn(OnToken, yytext, WITH_TOKEN); }
"xor"            { XXReturn(OnToken, yytext, XOR_TOKEN); }
 /*
  * Ada 95 keywords
  */
"abstract"       { XXReturn(OnToken, yytext, ABSTRACT_TOKEN); }
"aliased"        { XXReturn(OnToken, yytext, ALIASED_TOKEN); }
"protected"      { XXReturn(OnToken, yytext, PROTECTED_TOKEN); }
"requeue"        { XXReturn(OnToken, yytext, REQUEUE_TOKEN); }
"tagged"         { XXReturn(OnToken, yytext, TAGGED_TOKEN); }
"until"          { XXReturn(OnToken, yytext, UNTIL_TOKEN); }
 /*
  * Ada 2005 keywords
  */
"interface"      { XXReturn(OnToken, yytext, INTERFACE_TOKEN); }
"overriding"     { XXReturn(OnToken, yytext, OVERRIDING_TOKEN); }
"synchronized"   { XXReturn(OnToken, yytext, SYNCHRONIZED_TOKEN); }
 /*
  * parallel Ada keywords
  */
"parallel"       { XXReturn(OnToken, yytext, PARALLEL_TOKEN); }
"object"         { XXReturn(OnToken, yytext, OBJECT_TOKEN); }
"structure"      { XXReturn(OnToken, yytext, STRUCTURE_TOKEN); }
"union"          { XXReturn(OnToken, yytext, UNION_TOKEN); }

"=>"             { XXReturn(OnToken, yytext, ARROW_TOKEN); }
".."             { XXReturn(OnToken, yytext, DOUBLE_DOT_TOKEN); }
"**"             { XXReturn(OnToken, yytext, DOUBLE_STAR_TOKEN); }
":="             { XXReturn(OnToken, yytext, ASSIGNMENT_TOKEN); }
"/="             { XXReturn(OnToken, yytext, INEQUALITY_TOKEN); }
">="             { XXReturn(OnToken, yytext, GREATER_THAN_OR_EQUAL_TOKEN); }
"<="             { XXReturn(OnToken, yytext, LESS_THAN_OR_EQUAL_TOKEN); }
"<<"             { XXReturn(OnToken, yytext, LEFT_LABEL_BRACKET_TOKEN); }
">>"             { XXReturn(OnToken, yytext, RIGHT_LABEL_BRACKET_TOKEN); }
"<>"             { XXReturn(OnToken, yytext, BOX_TOKEN); }

"//"             { XXReturn(OnToken, yytext, DOUBLE_SLASH_TOKEN); }
":++"            { XXReturn(OnToken, yytext, INCREMENT_TOKEN); }
":--"            { XXReturn(OnToken, yytext, DECREMENT_TOKEN); }

\'(\\.|[^\\'])\'  { XXReturn(OnCharToken, yytext, CHAR_TOKEN); }
\"(\\.|[^\\"])*\" { XXReturn(OnStringToken, yytext, STRING_TOKEN); }

{L}({L}|{D})*    { XXReturn(OnIdentifierToken, yytext, IDENTIFIER_TOKEN); }

0|({N}{D}*)      { XXReturn(OnIntegerToken, yytext, INTEGER_TOKEN); }
{D}+"."{D}+{E}   { XXReturn(OnRealToken, yytext, REAL_TOKEN); }

{WS}             { }
.                { XXReturn(OnToken, yytext, yytext[0]); }
}

<COMMENT>{
\n               { XXPop(OnEndComment, yytext, COMMENT); }
}

<COMMENTX>{
"*-"             { XXPop(OnEndCommentX, yytext, COMMENTX); }
}

<*>{
\n|.             { }
}

%%
