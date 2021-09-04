/**
 **********************************************************************
 * Copyright (c) $year$ $author$
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
 *   File: function_defs.h
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _FUNCTION_DEFS_H
#define _FUNCTION_DEFS_H

/* lalr.c
 */
void set_state_table();
void set_accessing_symbol();
void set_shift_table();
void set_reduction_table();
void set_maxrhs();
void initialize_LA();
void set_goto_map();
void initialize_F();
void build_relations();
void compute_FOLLOWS();
void compute_lookaheads();
void fatal();
void digraph();
void add_lookback_edge();
void traverse();

/* lr0.c
 */
void set_first_derives();
void initialize_states();
void closure();
void save_reductions();
void new_itemsets();
void save_shifts();
void finalize_closure();
void no_space();
void fatal();

/* main.c
 */
void exit();
void no_space();
void open_error();
void reader();
void lr0();
void lalr();
void make_parser();
void verbose();
void output();

#if 0
s:\xde\c\src\capp\byacc\closure.c(39) : warning C4013: 'reflexive_transitive_closure' undefined; assuming extern returning int error.c

s:\xde\c\src\capp\byacc\error.c(10) : warning C4013: 'done' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\error.c(43) : warning C4033: 'print_pos' must return a value lalr.c

s:\xde\c\src\capp\byacc\mkpar.c(31) : warning C4013: 'find_final_state' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\mkpar.c(32) : warning C4013: 'remove_conflicts' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\mkpar.c(33) : warning C4013: 'unused_rules' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\mkpar.c(34) : warning C4013: 'total_conflicts' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\mkpar.c(35) : warning C4013: 'defreds' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\mkpar.c(176) : warning C4013: 'no_space' undefined; assuming extern returning int output.c

s:\xde\c\src\capp\byacc\output.c(21) : warning C4013: 'free_itemsets' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(22) : warning C4013: 'free_shifts' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(23) : warning C4013: 'free_reductions' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(24) : warning C4013: 'output_stored_text' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(25) : warning C4013: 'output_defines' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(26) : warning C4013: 'output_rule_data' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(27) : warning C4013: 'output_yydefred' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(28) : warning C4013: 'output_actions' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(29) : warning C4013: 'free_parser' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(30) : warning C4013: 'output_debug' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(31) : warning C4013: 'output_stype' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(32) : warning C4013: 'write_section' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(36) : warning C4013: 'output_semantic_actions' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(38) : warning C4013: 'output_trailing_text' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(126) : warning C4013: 'token_actions' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(132) : warning C4013: 'goto_actions' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(137) : warning C4013: 'sort_actions' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(138) : warning C4013: 'pack_table' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(139) : warning C4013: 'output_base' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(140) : warning C4013: 'output_table' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(141) : warning C4013: 'output_check' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(235) : warning C4013: 'default_goto' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(238) : warning C4013: 'save_column' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(321) : warning C4033: 'save_column' must return a value
s:\xde\c\src\capp\byacc\output.c(397) : warning C4013: 'matching_vector' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(400) : warning C4013: 'pack_vector' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(513) : warning C4013: 'fatal' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(518) : warning C4013: 'no_space' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(766) : warning C4013: 'open_error' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\output.c(795) : warning C4033: 'output_stored_text' must return a value
s:\xde\c\src\capp\byacc\output.c(1043) : warning C4033: 'output_trailing_text' must return a value
s:\xde\c\src\capp\byacc\output.c(1052) : warning C4033: 'output_trailing_text' must return a value
s:\xde\c\src\capp\byacc\output.c(1105) : warning C4033: 'output_semantic_actions' must return a value reader.c

s:\xde\c\src\capp\byacc\reader.c(45) : warning C4013: 'no_space' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(63) : warning C4033: 'get_line' must return a value
s:\xde\c\src\capp\byacc\reader.c(79) : warning C4033: 'get_line' must return a value
s:\xde\c\src\capp\byacc\reader.c(92) : warning C4033: 'get_line' must return a value
s:\xde\c\src\capp\byacc\reader.c(131) : warning C4033: 'skip_comment' must return a value
s:\xde\c\src\capp\byacc\reader.c(137) : warning C4013: 'unterminated_comment' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(266) : warning C4013: 'syntax_error' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(277) : warning C4013: 'unexpected_EOF' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(287) : warning C4033: 'copy_ident' must return a value
s:\xde\c\src\capp\byacc\reader.c(294) : warning C4033: 'copy_ident' must return a value
s:\xde\c\src\capp\byacc\reader.c(314) : warning C4013: 'unterminated_text' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(350) : warning C4013: 'unterminated_string' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(419) : warning C4033: 'copy_text' must return a value
s:\xde\c\src\capp\byacc\reader.c(440) : warning C4013: 'over_unionized' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(459) : warning C4013: 'unterminated_union' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(471) : warning C4033: 'copy_union' must return a value
s:\xde\c\src\capp\byacc\reader.c(630) : warning C4013: 'illegal_character' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(756) : warning C4013: 'used_reserved' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(790) : warning C4013: 'illegal_tag' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(853) : warning C4033: 'declare_tokens' must return a value
s:\xde\c\src\capp\byacc\reader.c(855) : warning C4013: 'tokenized_start' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(861) : warning C4013: 'retyped_warning' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(868) : warning C4013: 'reprec_warning' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(880) : warning C4013: 'revalued_warning' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(908) : warning C4033: 'declare_types' must return a value
s:\xde\c\src\capp\byacc\reader.c(928) : warning C4013: 'terminal_start' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(930) : warning C4013: 'restarted_warning' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(951) : warning C4033: 'read_declarations' must return a value
s:\xde\c\src\capp\byacc\reader.c(1050) : warning C4013: 'no_grammar' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(1080) : warning C4013: 'start_rule' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(1090) : warning C4013: 'terminal_lhs' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(1108) : warning C4013: 'default_action_warning' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(1166) : warning C4033: 'add_symbol' must return a value
s:\xde\c\src\capp\byacc\reader.c(1227) : warning C4013: 'dollar_warning' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(1241) : warning C4013: 'dollar_error' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(1248) : warning C4013: 'untyped_lhs' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(1263) : warning C4013: 'unknown_rhs' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(1265) : warning C4013: 'untyped_rhs' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(1303) : warning C4013: 'unterminated_action' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(1308) : warning C4033: 'copy_action' must return a value
s:\xde\c\src\capp\byacc\reader.c(1317) : warning C4033: 'copy_action' must return a value
s:\xde\c\src\capp\byacc\reader.c(1438) : warning C4013: 'prec_redeclared' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(1483) : warning C4033: 'free_tags' must return a value
s:\xde\c\src\capp\byacc\reader.c(1524) : warning C4013: 'undefined_goal' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(1530) : warning C4013: 'undefined_symbol_warning' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(1726) : warning C4033: 'print_grammar' must return a value
s:\xde\c\src\capp\byacc\reader.c(1758) : warning C4013: 'write_section' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(1759) : warning C4013: 'create_symbol_table' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(1762) : warning C4013: 'free_symbol_table' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\reader.c(1768) : warning C4013: 'free_symbols' undefined; assuming extern returning int skeleton.c symtab.c

s:\xde\c\src\capp\byacc\symtab.c(40) : warning C4013: 'no_space' undefined; assuming extern returning int verbose.c

s:\xde\c\src\capp\byacc\verbose.c(11) : warning C4033: 'verbose' must return a value
s:\xde\c\src\capp\byacc\verbose.c(14) : warning C4013: 'no_space' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\verbose.c(17) : warning C4013: 'print_state' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\verbose.c(21) : warning C4013: 'log_unused' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\verbose.c(23) : warning C4013: 'log_conflicts' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\verbose.c(84) : warning C4013: 'print_conflicts' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\verbose.c(86) : warning C4013: 'print_core' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\verbose.c(87) : warning C4013: 'print_nulls' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\verbose.c(88) : warning C4013: 'print_actions' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\verbose.c(233) : warning C4013: 'print_shifts' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\verbose.c(234) : warning C4013: 'print_reductions' undefined; assuming extern returning int
s:\xde\c\src\capp\byacc\verbose.c(242) : warning C4013: 'print_gotos' undefined; assuming extern returning int warshall.c Generating Code...
s:\xde\c\src\capp\byacc\verbose.c(47) : warning C4716: 'log_unused' : must return a value
s:\xde\c\src\capp\byacc\verbose.c(75) : warning C4716: 'log_conflicts' : must return a value
s:\xde\c\src\capp\byacc\verbose.c(89) : warning C4716: 'print_state' : must return a value
s:\xde\c\src\capp\byacc\verbose.c(137) : warning C4716: 'print_conflicts' : must return a value
s:\xde\c\src\capp\byacc\verbose.c(173) : warning C4716: 'print_core' : must return a value
s:\xde\c\src\capp\byacc\verbose.c(217) : warning C4716: 'print_nulls' : must return a value
s:\xde\c\src\capp\byacc\verbose.c(244) : warning C4716: 'print_actions' : must return a value
s:\xde\c\src\capp\byacc\verbose.c(269) : warning C4716: 'print_shifts' : must return a value
s:\xde\c\src\capp\byacc\verbose.c(307) : warning C4716: 'print_reductions' : must return a value
s:\xde\c\src\capp\byacc\verbose.c(328) : warning C4716: 'print_gotos' : must return a value

s:\xde\c\src\capp\byacc\reader.c(268) : warning C4715: 'keyword' : not all control paths return a value
s:\xde\c\src\capp\byacc\reader.c(1097) : warning C4716: 'start_rule' : must return a value

s:\xde\c\src\capp\byacc\output.c(87) : warning C4716: 'output_rule_data' : must return a value
s:\xde\c\src\capp\byacc\output.c(114) : warning C4716: 'output_yydefred' : must return a value
s:\xde\c\src\capp\byacc\output.c(142) : warning C4716: 'output_actions' : must return a value
s:\xde\c\src\capp\byacc\output.c(227) : warning C4716: 'token_actions' : must return a value
s:\xde\c\src\capp\byacc\output.c(260) : warning C4716: 'goto_actions' : must return a value
s:\xde\c\src\capp\byacc\output.c(339) : warning C4716: 'save_column' : must return a value
s:\xde\c\src\capp\byacc\output.c(373) : warning C4716: 'sort_actions' : must return a value
s:\xde\c\src\capp\byacc\output.c(419) : warning C4716: 'pack_table' : must return a value
s:\xde\c\src\capp\byacc\output.c(620) : warning C4716: 'output_base' : must return a value
s:\xde\c\src\capp\byacc\output.c(652) : warning C4716: 'output_table' : must return a value
s:\xde\c\src\capp\byacc\output.c(682) : warning C4716: 'output_check' : must return a value
s:\xde\c\src\capp\byacc\output.c(781) : warning C4716: 'output_defines' : must return a value
s:\xde\c\src\capp\byacc\output.c(808) : warning C4716: 'output_stored_text' : must return a value
s:\xde\c\src\capp\byacc\output.c(1024) : warning C4716: 'output_debug' : must return a value
s:\xde\c\src\capp\byacc\output.c(1034) : warning C4716: 'output_stype' : must return a value
s:\xde\c\src\capp\byacc\output.c(1091) : warning C4716: 'output_trailing_text' : must return a value
s:\xde\c\src\capp\byacc\output.c(1128) : warning C4716: 'output_semantic_actions' : must return a value
s:\xde\c\src\capp\byacc\output.c(1141) : warning C4716: 'free_itemsets' : must return a value
s:\xde\c\src\capp\byacc\output.c(1154) : warning C4716: 'free_shifts' : must return a value
s:\xde\c\src\capp\byacc\output.c(1168) : warning C4716: 'free_reductions' : must return a value

s:\xde\c\src\capp\byacc\mkpar.c(167) : warning C4716: 'find_final_state' : must return a value
s:\xde\c\src\capp\byacc\mkpar.c(199) : warning C4716: 'unused_rules' : must return a value
s:\xde\c\src\capp\byacc\mkpar.c(274) : warning C4716: 'remove_conflicts' : must return a value
s:\xde\c\src\capp\byacc\mkpar.c(294) : warning C4716: 'total_conflicts' : must return a value
s:\xde\c\src\capp\byacc\mkpar.c(333) : warning C4716: 'defreds' : must return a value

s:\xde\c\src\capp\byacc\lr0.c(242) : warning C4716: 'initialize_states' : must return a value
s:\xde\c\src\capp\byacc\lr0.c(277) : warning C4716: 'new_itemsets' : must return a value
s:\xde\c\src\capp\byacc\lr0.c(426) : warning C4716: 'save_shifts' : must return a value
s:\xde\c\src\capp\byacc\lr0.c(476) : warning C4716: 'save_reductions' : must return a value

s:\xde\c\src\capp\byacc\lalr.c(63) : warning C4716: 'set_state_table' : must return a value
s:\xde\c\src\capp\byacc\lalr.c(74) : warning C4716: 'set_accessing_symbol' : must return a value
s:\xde\c\src\capp\byacc\lalr.c(85) : warning C4716: 'set_shift_table' : must return a value
s:\xde\c\src\capp\byacc\lalr.c(96) : warning C4716: 'set_reduction_table' : must return a value
s:\xde\c\src\capp\byacc\lalr.c(124) : warning C4716: 'set_maxrhs' : must return a value
s:\xde\c\src\capp\byacc\lalr.c(162) : warning C4716: 'initialize_LA' : must return a value
s:\xde\c\src\capp\byacc\lalr.c(228) : warning C4716: 'set_goto_map' : must return a value
s:\xde\c\src\capp\byacc\lalr.c(336) : warning C4716: 'initialize_F' : must return a value
s:\xde\c\src\capp\byacc\lalr.c(429) : warning C4716: 'build_relations' : must return a value
s:\xde\c\src\capp\byacc\lalr.c(455) : warning C4716: 'add_lookback_edge' : must return a value
s:\xde\c\src\capp\byacc\lalr.c(520) : warning C4716: 'compute_FOLLOWS' : must return a value
s:\xde\c\src\capp\byacc\lalr.c(554) : warning C4716: 'compute_lookaheads' : must return a value
s:\xde\c\src\capp\byacc\lalr.c(580) : warning C4716: 'digraph' : must return a value
s:\xde\c\src\capp\byacc\lalr.c(638) : warning C4716: 'traverse' : must return a value
#endif ./* 0 */

#endif /* _FUNCTION_DEFS_H */
