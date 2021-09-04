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
 *   File: cdtlex.l
 *
 * Author: $author$
 *   Date: 8/25/2003
 *
 *    $Id$
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

%{
#include "cdtparse.h"
#include "cdtlexer.hxx"
%}

%option yylineno
%x COMMENT COMMENT2 COMMENTEOL

%%

<INITIAL>{
"/*"                  { OnPushState(yytext, COMMENT); }
"/%"                  { OnPushState(yytext, COMMENT2); }
"///"                 { OnPushState(yytext, COMMENTEOL); }

"do"                  { OnReserved(yytext); return XX_DO; }
"while"               { OnReserved(yytext); return XX_WHILE; }
"until"               { OnReserved(yytext); return XX_UNTIL; }
"for"                 { OnReserved(yytext); return XX_FOR; }
"each"                { OnReserved(yytext); return XX_EACH; }
"of"                  { OnReserved(yytext); return XX_OF; }
"switch"              { OnReserved(yytext); return XX_SWITCH; }
"case"                { OnReserved(yytext); return XX_CASE; }
"when"                { OnReserved(yytext); return XX_WHEN; }
"default"             { OnReserved(yytext); return XX_DEFAULT; }
"if"                  { OnReserved(yytext); return XX_IF; }
"else"                { OnReserved(yytext); return XX_ELSE; }
"with"                { OnReserved(yytext); return XX_WITH; }
"try"                 { OnReserved(yytext); return XX_TRY; }
"catch"               { OnReserved(yytext); return XX_CATCH; }
"throw"               { OnReserved(yytext); return XX_THROW; }
"break"               { OnReserved(yytext); return XX_BREAK; }
"continue"            { OnReserved(yytext); return XX_CONTINUE; }
"return"              { OnReserved(yytext); return XX_RETURN; }
"positionof"          { OnReserved(yytext); return XX_POSITIONOF; }
"sizeof"              { OnReserved(yytext); return XX_SIZEOF; }
"textof"              { OnReserved(yytext); return XX_TEXTOF; }
"typeof"              { OnReserved(yytext); return XX_TYPEOF; }
"prefixof"            { OnReserved(yytext); return XX_PREFIXOF; }
"nameof"              { OnReserved(yytext); return XX_NAMEOF; }
"namespaceof"         { OnReserved(yytext); return XX_NAMESPACEOF; }
"positionis"          { OnReserved(yytext); return XX_POSITIONIS; }
"sizeis"              { OnReserved(yytext); return XX_SIZEIS; }
"textis"              { OnReserved(yytext); return XX_TEXTIS; }
"typeis"              { OnReserved(yytext); return XX_TYPEIS; }
"prefixis"            { OnReserved(yytext); return XX_PREFIXIS; }
"nameis"              { OnReserved(yytext); return XX_NAMEIS; }
"namespaceis"         { OnReserved(yytext); return XX_NAMESPACEIS; }
"using"               { OnReserved(yytext); return XX_USING; }
"namespace"           { OnReserved(yytext); return XX_NAMESPACE; }
"template"            { OnReserved(yytext); return XX_TEMPLATE; }
"variable"            { OnReserved(yytext); return XX_VARIABLE; }
"virtual"             { OnReserved(yytext); return XX_VIRTUAL; }
"public"              { OnReserved(yytext); return XX_PUBLIC; }
"private"             { OnReserved(yytext); return XX_PRIVATE; }
"protected"           { OnReserved(yytext); return XX_PROTECTED; }
"class"               { OnReserved(yytext); return XX_CLASS; }
"struct"              { OnReserved(yytext); return XX_STRUCT; }
"union"               { OnReserved(yytext); return XX_UNION; }
"void"                { OnReserved(yytext); return XX_VOID; }
"bool"                { OnReserved(yytext); return XX_BOOL; }
"char"                { OnReserved(yytext); return XX_CHAR; }
"float"               { OnReserved(yytext); return XX_FLOAT; }
"double"              { OnReserved(yytext); return XX_DOUBLE; }
"string"              { OnReserved(yytext); return XX_STRING; }
"int"                 { OnReserved(yytext); return XX_INT; }
"short"               { OnReserved(yytext); return XX_SHORT; }
"long"                { OnReserved(yytext); return XX_LONG; }
"signed"              { OnReserved(yytext); return XX_SIGNED; }
"unsigned"            { OnReserved(yytext); return XX_UNSIGNED; }
"include"             { OnReserved(yytext,XX_INCLUDE); return XX_INCLUDE; }
"extern"              { OnReserved(yytext); return XX_EXTERN; }
"native"              { OnReserved(yytext); return XX_NATIVE; }
"foreign"             { OnReserved(yytext); return XX_FOREIGN; }

"not"                 { OnReserved(yytext); return XX_LNOT_OP;}
"and"                 { OnReserved(yytext); return XX_LAND_OP;}
"or"                  { OnReserved(yytext); return XX_LOR_OP;}

"not="                { OnReserved(yytext); return XX_LCOM_OP;}
"and="                { OnReserved(yytext); return XX_LAND_ASSIGN;}
"or="                 { OnReserved(yytext); return XX_LOR_ASSIGN;}

"::&"                 { OnText(yytext); return XX_COLONCOLON_AND;}
"::*"                 { OnText(yytext); return XX_COLONCOLON_STAR;}
"::"                  { OnText(yytext); return XX_COLONCOLON;}
".."                  { OnText(yytext); return XX_DOTDOT;}
"..."                 { OnText(yytext); return XX_ELIPSIS;}

"\\\\>>"              { OnText(yytext); return XX_BSLASHBSLASH_SHR;}
"\\\\<<"              { OnText(yytext); return XX_BSLASHBSLASH_SHL;}
"\\\\"                { OnText(yytext); return XX_BSLASHBSLASH;}
".\\?"                { OnText(yytext); return XX_DOTBSLASHQUESTION;}
"\\?"                 { OnText(yytext); return XX_BSLASHQUESTION;}
"@?"                  { OnText(yytext); return XX_ATQUESTION;}
".?"                  { OnText(yytext); return XX_DOTQUESTION;}
"%<"                  { OnPunctuation(yytext,XX_PERCENT_LESS); return XX_PERCENT_LESS;}
">%"                  { OnPunctuation(yytext,XX_GREATER_PERCENT); return XX_GREATER_PERCENT;}
"%>"                  { OnPunctuation(yytext,XX_PERCENT_GREATER); return XX_PERCENT_GREATER;}
"<%"                  { OnPunctuation(yytext,XX_LESS_PERCENT); return XX_LESS_PERCENT;}

">>="                 { OnText(yytext); return XX_SHR_ASSIGN;}
"<<="                 { OnText(yytext); return XX_SHL_ASSIGN;}
"&&="                 { OnText(yytext); return XX_LAND_ASSIGN;}
"||="                 { OnText(yytext); return XX_LOR_ASSIGN;}

"+="                  { OnText(yytext); return XX_ADD_ASSIGN;}
"-="                  { OnText(yytext); return XX_SUB_ASSIGN;}
"*="                  { OnText(yytext); return XX_MUL_ASSIGN;}
"/="                  { OnText(yytext); return XX_DIV_ASSIGN;}
"%="                  { OnText(yytext); return XX_MOD_ASSIGN;}
"&="                  { OnText(yytext); return XX_AND_ASSIGN;}
"|="                  { OnText(yytext); return XX_OR_ASSIGN;}
"^="                  { OnText(yytext); return XX_XOR_ASSIGN;}
":="                  { OnText(yytext); return XX_ASSIGN;}

">>>"                 { OnText(yytext); return XX_RIGHT_OP;}
"<<<"                 { OnText(yytext); return XX_LEFT_OP;}
"++"                  { OnText(yytext); return XX_INC_OP;}
"--"                  { OnText(yytext); return XX_DEC_OP;}
"~~"                  { OnText(yytext); return XX_COM_OP;}
"!!"                  { OnText(yytext); return XX_LCOM_OP;}

"<="                  { OnText(yytext); return XX_LE_OP;}
">="                  { OnText(yytext); return XX_GE_OP;}
"<>"                  { OnText(yytext); return XX_NE_OP;}
"!="                  { OnText(yytext); return XX_NE_OP;}
"=="                  { OnText(yytext); return XX_EQ_OP;}
">>"                  { OnText(yytext); return XX_SHR_OP;}
"<<"                  { OnText(yytext); return XX_SHL_OP;}
"&&"                  { OnText(yytext); return XX_LAND_OP;}
"||"                  { OnText(yytext); return XX_LOR_OP;}
"**"                  { OnText(yytext); return XX_POW_OP;}
"//"                  { OnText(yytext); return XX_ROO_OP;}
"%%"                  { OnText(yytext); return XX_LOG_OP;}

0|({N}{D}*){U}?{S}?   { if (OnLiteral(yytext,0,0,XX_DEC_LITERAL)) return -1; else return XX_DEC_LITERAL; }
0[Xx]{H}+{U}?{S}?     { if (OnLiteral(yytext,2,0,XX_HEX_LITERAL)) return -1; else return XX_HEX_LITERAL; }
0[Yy]{B}+{U}?{S}?     { if (OnLiteral(yytext,2,0,XX_BIN_LITERAL)) return -1; else return XX_BIN_LITERAL; }
0{O}+{U}?{S}?         { if (OnLiteral(yytext,1,0,XX_OCT_LITERAL)) return -1; else return XX_OCT_LITERAL; }

0|({N}{D}*){F}{S}?    { if (OnLiteral(yytext,0,0,XX_FLOAT_LITERAL)) return -1; return XX_FLOAT_LITERAL; }
{D}+"."{D}+{E}?{S}?   { if (OnLiteral(yytext,0,0,XX_FLOAT_LITERAL)) return -1; return XX_FLOAT_LITERAL; }
{D}+{E}{S}?           { if (OnLiteral(yytext,0,0,XX_FLOAT_LITERAL)) return -1; return XX_FLOAT_LITERAL; }

{L}({L}|{D})*         { if (OnIdentifier(yytext,0,0,XX_IDENTIFIER)) return -1; return XX_IDENTIFIER; }

"*/"(\n|[^\/]|\/[^*])*"/*" { if (OnLiteral(yytext,0,2,XX_TEMPLATE_LITERAL)) return -1; return XX_TEMPLATE_LITERAL; }
"%/"(\n|[^\/]|\/[^%])*"/%" { if (OnLiteral(yytext,0,2,XX_TEMPLATE_LITERAL)) return -1; return XX_TEMPLATE_LITERAL; }

\"(\\.|[^\\"])*\"     { if (OnStringLiteral(yytext,0,1,XX_TEXT_LITERAL)) return -1; return XX_TEXT_LITERAL; }
\'(\\.|[^\\'])*\'     { if (OnStringLiteral(yytext,0,1,XX_TEXT_LITERAL)) return -1; return XX_TEXT_LITERAL; }
\\\\\'(\\.|[^\\'])*\' { if (OnStringLiteral(yytext,2,1,XX_URI_LITERAL)) return -1; return XX_URI_LITERAL; }
\\\\\"(\\.|[^\\"])*\" { if (OnStringLiteral(yytext,2,1,XX_URI_LITERAL)) return -1; return XX_URI_LITERAL; }
\\\\\`(\\.|[^\\`])*\` { if (OnStringLiteral(yytext,2,1,XX_ELEMENT_LITERAL)) return -1; return XX_ELEMENT_LITERAL; }

[ \t\r\n]             { OnText(yytext); }
.                     { OnText(yytext); return yytext[0];}
}

<COMMENT>{
"*/"                  { OnPopState(yytext, COMMENT);}
\n                    { OnComment(yytext, COMMENT); }
.                     { OnComment(yytext, COMMENT); }
}

<COMMENT2>{
"%/"                  { OnPopState(yytext, COMMENT2);}
\n                    { OnComment(yytext, COMMENT2); }
.                     { OnComment(yytext, COMMENT2); }
}

<COMMENTEOL>{
\n                    { OnPopState(yytext, COMMENTEOL);}
.                     { OnComment(yytext, COMMENTEOL); }
}

%%
