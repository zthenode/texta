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
 *   File: cacparse.y
 *
 * Author: $author$
 *   Date: 7/30/2008
 **********************************************************************
 */

/*
 * defines
 */
%token ABORT_TOKEN ABS_TOKEN ACCEPT_TOKEN ACCESS_TOKEN ALL_TOKEN AND_TOKEN
%token ARRAY_TOKEN AT_TOKEN BEGIN_TOKEN BODY_TOKEN CASE_TOKEN CONSTANT_TOKEN
%token DECLARE_TOKEN DELAY_TOKEN DELTA_TOKEN DIGITS_TOKEN ELSE_TOKEN ELSIF_TOKEN
%token END_TOKEN ENTRY_TOKEN EXCEPTION_TOKEN EXIT_TOKEN FOR_TOKEN FUNCTION_TOKEN
%token GENERIC_TOKEN GOTO_TOKEN IF_TOKEN IN_TOKEN IS_TOKEN LIMITED_TOKEN
%token LOOP_TOKEN MOD_TOKEN NEW_TOKEN NOT_TOKEN NULL_TOKEN OF_TOKEN
%token OR_TOKEN OTHERS_TOKEN OUT_TOKEN PACKAGE_TOKEN PRAGMA_TOKEN PRIVATE_TOKEN
%token PROCEDURE_TOKEN RAISE_TOKEN RANGE_TOKEN RECORD_TOKEN REM_TOKEN RENAMES_TOKEN
%token RETURN_TOKEN REVERSE_TOKEN SELECT_TOKEN SEPARATE_TOKEN SUBTYPE_TOKEN TASK_TOKEN
%token TERMINATE_TOKEN THEN_TOKEN TYPE_TOKEN USE_TOKEN WHEN_TOKEN WHILE_TOKEN
%token WITH_TOKEN XOR_TOKEN
%token ABSTRACT_TOKEN ALIASED_TOKEN PROTECTED_TOKEN REQUEUE_TOKEN TAGGED_TOKEN UNTIL_TOKEN
%token INTERFACE_TOKEN OVERRIDING_TOKEN SYNCHRONIZED_TOKEN
%token PARALLEL_TOKEN OBJECT_TOKEN STRUCTURE_TOKEN UNION_TOKEN
%token ARROW_TOKEN DOUBLE_DOT_TOKEN DOUBLE_STAR_TOKEN ASSIGNMENT_TOKEN
%token INEQUALITY_TOKEN GREATER_THAN_OR_EQUAL_TOKEN LESS_THAN_OR_EQUAL_TOKEN
%token LEFT_LABEL_BRACKET_TOKEN RIGHT_LABEL_BRACKET_TOKEN BOX_TOKEN
%token DOUBLE_SLASH_TOKEN INCREMENT_TOKEN DECREMENT_TOKEN
%token CHAR_TOKEN STRING_TOKEN INTEGER_TOKEN REAL_TOKEN IDENTIFIER_TOKEN

/*
 * includes
 */
%{
#undef NULL
#include "cacparser.hxx"
#define YY(on) if ((m_error = on())) return YYOnError(""#on""); else YYOn(""#on"")
#define YYToken(on,token) if ((m_error = on(token))) return YYOnError(""#on"",token); else YYOn(""#on"",token)
%}

/*
 * rules
 */
%%

compilation
: ..compilation_unit..
;

..compilation_unit..
: ..prag..
| ..compilation_unit.. compilation_unit ..prag..
;

compilation_unit
: context_cl library_unit
;

library_unit
: subprg_body
;

subprg_body
: subprg_spec IS_TOKEN
  .decl_part.
  BEGIN_TOKEN
  .seq_of_stmts.
  END_TOKEN .designator. ';'
;

.seq_of_stmts.
:
| seq_of_stmts
;

seq_of_stmts
: ..prag.. stmt ..stmt..
;

..stmt..
: ..prag..
| ..stmt.. stmt ..prag..
;

stmt
: ..label.. sim_stmt
| ..label.. compound_stmt 
;

..label..
:
| ..label.. label
;

label
: LEFT_LABEL_BRACKET_TOKEN sim_n RIGHT_LABEL_BRACKET_TOKEN
;

sim_stmt
: name ';'
;

code_stmt
:
;

compound_stmt
: block_stmt
;

block_stmt
: BEGIN_TOKEN
  .seq_of_stmts.
  END_TOKEN .sim_n. ';'
;

.decl_part.
: decl_part
;

decl_part
: ..basic_decl_item..
;

..basic_decl_item..
: ..prag..
| ..basic_decl_item.. basic_decl_item ..prag..
;

basic_decl_item
: basic_d
;

basic_d
: object_d
;

object_d
: idents ':' subty_ind ._ASN_expr. ';'
;

subty_ind
: ty_mk .constrt.
;

.constrt.
:
| constrt
;

constrt
: rng_c
;

rng_c
: RANGE_TOKEN rng
;

rng
: name
;

name
: CHAR
| sim_n
| op_symbol
| idxed_cmpon
;

idxed_cmpon
: prefix aggr { OnIndexedComponent(); }
;

prefix
: name
;

aggr
: aggr_begin
  cmpon_asc  ..cmpon_asc.. 
  aggr_end
;

aggr_begin
: '(' { OnAggrBegin(); }
;

aggr_end
: ')' { OnAggrEnd(); }
;

..cmpon_asc..
:
| ..cmpon_asc.. ',' cmpon_asc
;

cmpon_asc
: expr
;

subprg_spec
: PROCEDURE_TOKEN  IDENTIFIER .fml_part.
| FUNCTION_TOKEN  designator .fml_part. RETURN_TOKEN ty_mk
;

.fml_part.
:
| fml_part
;

fml_part
: '(' prm_spec ..prm_spec.. ')'
;

..prm_spec..
:
| ..prm_spec.. ';' prm_spec
;

prm_spec
: idents ':' mode ty_mk ._ASN_expr.
;

idents
: IDENTIFIER ..ident..
;

..ident..
:
| ..ident.. ',' IDENTIFIER
;

mode
: .IN.
| IN_TOKEN OUT_TOKEN
| OUT_TOKEN
;

.IN.
:
| IN_TOKEN
;

ty_mk
: expanded_n
;

._ASN_expr.
:
| ASSIGNMENT_TOKEN expr
;

.designator.
:
| designator
;

designator
: IDENTIFIER
| op_symbol
;

op_symbol
: STRING
;

context_cl
: ..with_cl..use_cl..
;

..with_cl..use_cl..
:
| ..with_cl..use_cl.. with_cl ..use_cl..
;

with_cl
: WITH_TOKEN sim_n ..sim_n.. ';'
;

..use_cl..
: ..prag..
| ..use_cl.. use_cl ..prag..
;

use_cl
: USE_TOKEN expanded_n ..expanded_n.. ';'
;

..prag..
:
| ..prag.. prag
;

prag
: PRAGMA_TOKEN IDENTIFIER .arg_ascs. ';'
;

.arg_ascs.
:
| '(' arg_ascs ')'
;

arg_ascs
: arg_asc
| arg_ascs ',' arg_asc 
;

arg_asc
: expr
| IDENTIFIER ARROW_TOKEN expr
;

expr
: name { OnExpr(); }
;

..expanded_n..
:
| ..expanded_n.. ',' expanded_n
;

.expanded_n.
:
| expanded_n
;

expanded_n
: IDENTIFIER
| expanded_n '.' IDENTIFIER
;

..sim_n.. 
:
| ..sim_n.. ',' sim_n
;

.sim_n.
: 
| sim_n
;

sim_n
: IDENTIFIER
;

IDENTIFIER
: IDENTIFIER_TOKEN { YY(OnIdentifier); }
;

STRING
: STRING_TOKEN { YY(OnString); }
;

CHAR
: CHAR_TOKEN { YY(OnChar); }
;

%%
