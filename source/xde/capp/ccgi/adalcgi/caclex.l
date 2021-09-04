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
%x COMMENT COMMENTX COMMENTY PPROCESS
 
/*
 * rules
 */
%%

<INITIAL>{
"#"              { XXPush(OnBeginComment, yytext, PPROCESS); }
"--"             { XXPush(OnBeginComment, yytext, COMMENT); }
"-*"             { XXPush(OnBeginCommentX, yytext, COMMENTX); }
"-/"             { XXPush(OnBeginCommentX, yytext, COMMENTY); }

 /*
  * Ada keywords
  */
"abort"          { XXReturn(OnToken, yytext, ABORT_); }
"abs"            { XXReturn(OnToken, yytext, ABS_); }
"accept"         { XXReturn(OnToken, yytext, ACCEPT_); }
"access"         { XXReturn(OnToken, yytext, ACCESS_); }
"all"            { XXReturn(OnToken, yytext, ALL_); }
"and"            { XXReturn(OnToken, yytext, AND_); }
"array"          { XXReturn(OnToken, yytext, ARRAY_); }
"at"             { XXReturn(OnToken, yytext, AT_); }
"begin"          { XXReturn(OnToken, yytext, BEGIN_); }
"body"           { XXReturn(OnToken, yytext, BODY_); }
"case"           { XXReturn(OnToken, yytext, CASE_); }
"constant"       { XXReturn(OnToken, yytext, CONSTANT_); }
"declare"        { XXReturn(OnToken, yytext, DECLARE_); }
"delay"          { XXReturn(OnToken, yytext, DELAY_); }
"delta"          { XXReturn(OnToken, yytext, DELTA_); }
"digits"         { XXReturn(OnToken, yytext, DIGITS_); }
"do"             { XXReturn(OnToken, yytext, DO_); }
"else"           { XXReturn(OnToken, yytext, ELSE_); }
"elsif"          { XXReturn(OnToken, yytext, ELSIF_); }
"end"            { XXReturn(OnToken, yytext, END_); }
"entry"          { XXReturn(OnToken, yytext, ENTRY_); }
"exception"      { XXReturn(OnToken, yytext, EXCEPTION_); }
"exit"           { XXReturn(OnToken, yytext, EXIT_); }
"for"            { XXReturn(OnToken, yytext, FOR_); }
"function"       { XXReturn(OnToken, yytext, FUNCTION_); }
"generic"        { XXReturn(OnToken, yytext, GENERIC_); }
"goto"           { XXReturn(OnToken, yytext, GOTO_); }
"if"             { XXReturn(OnToken, yytext, IF_); }
"in"             { XXReturn(OnToken, yytext, IN_); }
"is"             { XXReturn(OnToken, yytext, IS_); }
"limited"        { XXReturn(OnToken, yytext, LIMITED_); }
"loop"           { XXReturn(OnToken, yytext, LOOP_); }
"mod"            { XXReturn(OnToken, yytext, MOD_); }
"new"            { XXReturn(OnToken, yytext, NEW_); }
"not"            { XXReturn(OnToken, yytext, NOT_); }
"null"           { XXReturn(OnToken, yytext, NULL_); }
"of"             { XXReturn(OnToken, yytext, OF_); }
"or"             { XXReturn(OnToken, yytext, OR_); }
"others"         { XXReturn(OnToken, yytext, OTHERS_); }
"out"            { XXReturn(OnToken, yytext, OUT_); }
"package"        { XXReturn(OnToken, yytext, PACKAGE_); }
"pragma"         { XXReturn(OnToken, yytext, PRAGMA_); }
"private"        { XXReturn(OnToken, yytext, PRIVATE_); }
"procedure"      { XXReturn(OnToken, yytext, PROCEDURE_); }
"raise"          { XXReturn(OnToken, yytext, RAISE_); }
"range"          { XXReturn(OnToken, yytext, RANGE_); }
"record"         { XXReturn(OnToken, yytext, RECORD_); }
"rem"            { XXReturn(OnToken, yytext, REM_); }
"renames"        { XXReturn(OnToken, yytext, RENAMES_); }
"return"         { XXReturn(OnToken, yytext, RETURN_); }
"reverse"        { XXReturn(OnToken, yytext, REVERSE_); }
"select"         { XXReturn(OnToken, yytext, SELECT_); }
"separate"       { XXReturn(OnToken, yytext, SEPARATE_); }
"subtype"        { XXReturn(OnToken, yytext, SUBTYPE_); }
"task"           { XXReturn(OnToken, yytext, TASK_); }
"terminate"      { XXReturn(OnToken, yytext, TERMINATE_); }
"then"           { XXReturn(OnToken, yytext, THEN_); }
"type"           { XXReturn(OnToken, yytext, TYPE_); }
"use"            { XXReturn(OnToken, yytext, USE_); }
"when"           { XXReturn(OnToken, yytext, WHEN_); }
"while"          { XXReturn(OnToken, yytext, WHILE_); }
"with"           { XXReturn(OnToken, yytext, WITH_); }
"xor"            { XXReturn(OnToken, yytext, XOR_); }
 /*
  * Ada 95 keywords
  */
"abstract"       { XXReturn(OnToken, yytext, ABSTRACT_); }
"aliased"        { XXReturn(OnToken, yytext, ALIASED_); }
"protected"      { XXReturn(OnToken, yytext, PROTECTED_); }
"requeue"        { XXReturn(OnToken, yytext, REQUEUE_); }
"tagged"         { XXReturn(OnToken, yytext, TAGGED_); }
"until"          { XXReturn(OnToken, yytext, UNTIL_); }
 /*
  * Ada 2005 keywords
  */
"interface"      { XXReturn(OnToken, yytext, INTERFACE_); }
"overriding"     { XXReturn(OnToken, yytext, OVERRIDING_); }
"synchronized"   { XXReturn(OnToken, yytext, SYNCHRONIZED_); }
 /*
  * Ada** keywords
  */
"absolute"       { XXReturn(OnToken, yytext, ABSOLUTE_); }
"by"             { XXReturn(OnToken, yytext, BY_); }
"catch"          { XXReturn(OnToken, yytext, CATCH_); }
"constructor"    { XXReturn(OnToken, yytext, CONSTRUCTOR_); }
"delete"         { XXReturn(OnToken, yytext, DELETE_); }
"destructor"     { XXReturn(OnToken, yytext, DESTRUCTOR_); }
"dispose"        { XXReturn(OnToken, yytext, DISPOSE_); }
"downto"         { XXReturn(OnToken, yytext, DOWNTO_); }
"elseif"         { XXReturn(OnToken, yytext, ELSEIF_); }
"enumerate"      { XXReturn(OnToken, yytext, ENUMERATE_); }
"extends"        { XXReturn(OnToken, yytext, EXTENDS_); }
"external"       { XXReturn(OnToken, yytext, EXTERNAL_); }
"implements"     { XXReturn(OnToken, yytext, IMPLEMENTS_); }
"interrupt"      { XXReturn(OnToken, yytext, INTERRUPT_); }
"ln"             { XXReturn(OnToken, yytext, LN_); }
"log"            { XXReturn(OnToken, yytext, LOG_); }
"object"         { XXReturn(OnToken, yytext, OBJECT_); }
"otherwise"      { XXReturn(OnToken, yytext, OTHERWISE_); }
"packed"         { XXReturn(OnToken, yytext, PACKED_); }
"parallel"       { XXReturn(OnToken, yytext, PARALLEL_); }
"program"        { XXReturn(OnToken, yytext, PROGRAM_); }
"public"         { XXReturn(OnToken, yytext, PUBLIC_); }
"remote"         { XXReturn(OnToken, yytext, REMOTE_); }
"repeat"         { XXReturn(OnToken, yytext, REPEAT_); }
"serial"         { XXReturn(OnToken, yytext, SERIAL_); }
"signed"         { XXReturn(OnToken, yytext, SIGNED_); }
"static"         { XXReturn(OnToken, yytext, STATIC_); }
"structure"      { XXReturn(OnToken, yytext, STRUCTURE_); }
"this"           { XXReturn(OnToken, yytext, THIS__); }
"throw"          { XXReturn(OnToken, yytext, THROW_); }
"to"             { XXReturn(OnToken, yytext, TO_); }
"try"            { XXReturn(OnToken, yytext, TRY_); }
"unsigned"       { XXReturn(OnToken, yytext, UNSIGNED_); }
"union"          { XXReturn(OnToken, yytext, UNION_); }
"virtual"        { XXReturn(OnToken, yytext, VIRTUAL_); }
"volatile"       { XXReturn(OnToken, yytext, VOLATILE_); }
"where"          { XXReturn(OnToken, yytext, WHERE_); }

 /*
  * Ada** operators
  */
"<<:="           { XXReturn(OnToken, yytext, LEFT_); }
">>:="           { XXReturn(OnToken, yytext, RIGHT_); }
"**:="           { XXReturn(OnToken, yytext, POWER_); }
"//:="           { XXReturn(OnToken, yytext, ROOT_); }
"%%:="           { XXReturn(OnToken, yytext, ORDER_); }
"*:="            { XXReturn(OnToken, yytext, MULTIPLY_); }
"/:="            { XXReturn(OnToken, yytext, DIVIDE_); }
"%:="            { XXReturn(OnToken, yytext, MODULO_); }
"+:="            { XXReturn(OnToken, yytext, ADD_); }
"-:="            { XXReturn(OnToken, yytext, SUBTRACT_); }
"&:="            { XXReturn(OnToken, yytext, INTERSECT_); }
"|:="            { XXReturn(OnToken, yytext, INCLUDE_); }
"~:="            { XXReturn(OnToken, yytext, EXCLUDE_); }
"^:="            { XXReturn(OnToken, yytext, POINT_); }
":<<"            { XXReturn(OnToken, yytext, LSHIFT_); }
":>>"            { XXReturn(OnToken, yytext, RSHIFT_); }
":++"            { XXReturn(OnToken, yytext, INCREMENT_); }
":--"            { XXReturn(OnToken, yytext, DECREMENT_); }
":~~"            { XXReturn(OnToken, yytext, COMPLEMENT_); }
"..."            { XXReturn(OnToken, yytext, ELIPSIS_); }
"%%"             { XXReturn(OnToken, yytext, PCENTPCENT_); }
"//"             { XXReturn(OnToken, yytext, SLASHSLASH_); }
 /*
  * Ada operators
  */
"=>"             { XXReturn(OnToken, yytext, ARROW_); }
".."             { XXReturn(OnToken, yytext, DOTDOT_); }
"**"             { XXReturn(OnToken, yytext, STARSTAR_); }
":="             { XXReturn(OnToken, yytext, ASSIGN_); }
"/="             { XXReturn(OnToken, yytext, NE_); }
">="             { XXReturn(OnToken, yytext, GE_); }
"<="             { XXReturn(OnToken, yytext, LE_); }
"<<"             { XXReturn(OnToken, yytext, LLABEL_); }
">>"             { XXReturn(OnToken, yytext, RLABEL_); }
"<>"             { XXReturn(OnToken, yytext, BOX_); }

"<<"{L}({L}|{D})*">>" { XXReturn(OnIdentifierToken, yytext, LABEL_); }

\'(\\.|[^\\'])\'  { XXReturn(OnCharToken, yytext, CHAR_); }
\"(\\.|[^\\"])*\" { XXReturn(OnStringToken, yytext, STRING_); }

{L}({L}|{D})*    { XXReturn(OnIdentifierToken, yytext, IDENTIFIER_); }

0|({N}{D}*)      { XXReturn(OnIntegerToken, yytext, INTEGER_); }
{D}+"."{D}+{E}   { XXReturn(OnRealToken, yytext, REAL_); }

{WS}             { }
.                { XXReturn(OnToken, yytext, yytext[0]); }
}

<PPROCESS>{
\n               { XXPop(OnEndComment, yytext, PPROCESS); }
}

<COMMENT>{
\n               { XXPop(OnEndComment, yytext, COMMENT); }
}

<COMMENTX>{
"*-"             { XXPop(OnEndCommentX, yytext, COMMENTX); }
}

<COMMENTY>{
"/-"             { XXPop(OnEndCommentX, yytext, COMMENTY); }
}

<*>{
\n|.             { }
}

%%
