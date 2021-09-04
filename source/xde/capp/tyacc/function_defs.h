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
int set_state_table();
int set_accessing_symbol();
int set_shift_table();
int set_reduction_table();
int set_maxrhs();
int initialize_LA();
int set_goto_map();
int initialize_F();
int build_relations();
int compute_FOLLOWS();
int compute_lookaheads();
int fatal();
int digraph();
int add_lookback_edge();
int traverse();

/* lr0.c
 */
int set_first_derives();
int initialize_states();
int closure();
int save_reductions();
int new_itemsets();
int save_shifts();
int finalize_closure();
int no_space();
int fatal();

/* main.c
 */
int exit();
int no_space();
int open_error();
int reader();
int lr0();
int lalr();
int make_parser();
int verbose();
int output();

#endif /* _FUNCTION_DEFS_H */
