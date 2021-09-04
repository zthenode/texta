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
 *   File: clexercgilex.l
 *
 * Author: $author$
 *   Date: 8/10/2008
 **********************************************************************
 */

/*
 * defines
 */
STRING \"[^"\n]*\"
CHAR \'[^'\n]*\'
WS [ \t\r\n]*

/*
 * includes
 */
%{
#include "cdebug.hxx"
#include "clexercgilexer.hxx"
#define XX(on, text, token) on(text, token)
#define XXEndof(on, text, token) on(text, token); yyterminate()
#define XXPush(on, text, token) on(text, token); OnPush(text, token)
#define XXPop(on, text, token) on(text, token); OnPop(text, token)
#define XXSwitch(on, text, token) on(text, token); OnSwitch(text, token)
%}

/*
 * options
 */
%option yylineno
%x CGIFINAL CGIBODY CGIPATH CGIEXT CGITEXT CGIBEFORE CGIBEFOREESC CGIAFTER CGIBETWEEN CGICOMMENTEOL

/*
 * rules
 */
%%

<INITIAL>{
"%%"                  { XXSwitch(OnEndCGIBefore, yytext, CGIBODY); }
"%#"                  { XXPush(OnSkip, yytext, CGICOMMENTEOL); }
\\[%\\]               { XX(OnCGIBeforeText, yytext+1, -1); }
(\n|.)                { XX(OnCGIBeforeText, yytext, -1); }
}

<CGIFINAL>{
"%#"                  { XXPush(OnSkip, yytext, CGICOMMENTEOL); }
\\[%\\]               { XX(OnCGIAfterText, yytext+1, -1); }
(\n|.)                { XX(OnCGIAfterText, yytext, -1); }
}

<CGIBODY>{
"%"([^%#{?\\]|[ \t\r\n])+ { XXPush(OnBeginCGIBeforeAny, yytext+1, CGIBEFORE); }
"%%"                     { XXSwitch(OnSkip, yytext, CGIFINAL); }
"%#"                     { XXPush(OnSkip, yytext, CGICOMMENTEOL); }
"%{"                     { XXPush(OnBeginCGIText, yytext, CGITEXT); }
"%?/"                    { XXPush(OnBeginCGIPath, yytext, CGIPATH); }
"%?."                    { XXPush(OnBeginCGIExtension, yytext, CGIEXT); }
(\n|.)                   { }
}

<CGIPATH>{
"/?%"                   { XXPop(OnEndCGIPath, yytext, CGIPATH); }
.                       { XX(OnCGIPath, yytext, -1); }
[\t\r\n]                { }
}

<CGIEXT>{
".?%"                   { XXPop(OnEndCGIExtension, yytext, CGIEXT); }
.                       { XX(OnCGIExtension, yytext, -1); }
[\t\r\n]                { }
}

<CGITEXT>{
"%}"                    { XXPop(OnEndCGIText, yytext, CGITEXT); }
(\n|.)                  { XX(OnCGIText, yytext, -1); }
}

<CGIBEFORE>{
"%"{WS}"/*...*/"{WS}"%" { XXSwitch(OnCGIBeforeComment, yytext, CGIAFTER); }
"%"{WS}"//..."{WS}"%"   { XXSwitch(OnCGIBeforeCommentLN, yytext, CGIAFTER); }
"%"{WS}"#..."{WS}"%"    { XXSwitch(OnCGIBeforeProcessor, yytext, CGIAFTER); }
"%"{WS}"=..."{WS}"%"    { XXSwitch(OnCGIBeforeDefine, yytext, CGIAFTER); }
"%"{WS}"..."{WS}"%"     { XXSwitch(OnCGIBeforeKeyword, yytext, CGIAFTER); }
"%"{WS}"(...)"{WS}"%"   { XXSwitch(OnCGIBeforeKeywordX, yytext, CGIAFTER); }
"%"{WS}"[...]"{WS}"%"   { XXSwitch(OnCGIBeforeKeywordY, yytext, CGIAFTER); }
"%"{WS}\""..."\"{WS}"%" { XXSwitch(OnCGIBeforeString, yytext, CGIAFTER); }
"%"{WS}\'"..."\'{WS}"%" { XXSwitch(OnCGIBeforeChar, yytext, CGIAFTER); }

"%"{WS}"...:"{WS}"%"        { XXSwitch(OnCGIBeforeDefineT, yytext, CGIBETWEEN); }
"%"{WS}":..."{WS}"%"        { XXSwitch(OnCGIBeforeDefineL, yytext, CGIBETWEEN); }
"%"{WS}"import..."{WS}"%"   { XXSwitch(OnCGIBeforeImportL, yytext, CGIBETWEEN); }
"%"{WS}"#include..."{WS}"%" { XXSwitch(OnCGIBeforeIncludeL, yytext, CGIBETWEEN); }

"%"([^%]|\n)*"%"        { XXSwitch(OnSkip, yytext, CGIAFTER); }
\\[%\\]                 { XX(OnCGIBeforeAny, yytext+1, 0); }
\n|.                    { XX(OnCGIBeforeAny, yytext, 0); }
}

<CGIAFTER>{
([^%]|\n)            { XX(OnCGIAfterAnyText, yytext, -1); }
"%"                  { XXPop(OnEndCGIAfterAny, yytext, CGIAFTER); }
}

<CGIBETWEEN>{
([^%]|\n)            { XX(OnCGIBetweenAnyText, yytext, -1); }
"%"                  { XXSwitch(OnEndCGIBetweenAny, yytext, CGIAFTER); }
}

<CGICOMMENTEOL>{
\n                    { XXPop(OnSkip, yytext, CGICOMMENTEOL); }
.                     { }
}

%%
