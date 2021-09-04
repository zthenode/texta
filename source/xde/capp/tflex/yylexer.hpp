// $Header$

// yylexer.hpp -- define interfaces for lexical analyzer classes generated
// by flex

// Copyright (c) 1993 The Regents of the University of California.
// All rights reserved.
//
// This code is derived from software contributed to Berkeley by
// Kent Williams and Tom Epperly with modifications made by $author$.
//
// Redistribution and use in source and binary forms are permitted provided
// that: (1) source distributions retain this entire copyright notice and
// comment, and (2) distributions including binaries display the following
// acknowledgement:  ``This product includes software developed by the
// University of California, Berkeley and its contributors'' in the
// documentation or other materials provided with the distribution and in
// all advertising materials mentioning features or use of this software.
// Neither the name of the University nor the names of its contributors may
// be used to endorse or promote products derived from this software without
// specific prior written permission.
// THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
// WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

// This file defines Lexer, an abstract class which specifies the
// external interface provided to flex C++ lexer objects, and yyBaseLexer,
// which defines a particular lexer class.
//
// If you want to create multiple lexer classes, you use the -P flag
// to rename each yyBaseLexer to some other xxLexer.  You then
// include <yylexer.hpp> in your other sources once per lexer class:
//
//	#undef yyBaseLexer
//	#undef yyLexer
//	#define yyBaseLexer xxBaseLexer
//	#define yyLexer xxLexer
//	#include <yylexer.hpp>
//
//	#undef yyBaseLexer
//	#undef yyLexer
//	#define yyBaseLexer zzBaseLexer
//	#define yyLexer zzLexer
//	#include <yylexer.hpp>
//	...
//
//  To create a dirived lexer class do the same as above and 
//  define yyDerivedLexer as folows:
//
//	#undef yyBaseLexer
//	#undef yyDirivedLexer
//	#define yyBaseLexer xxBaseLexer
//  #define yyDerivedLexer yyLexer
//	#include <yylexer.hpp>
//
//  class yyLexer: public yyBaseLexer {
//  ...
//  };


#ifndef __YYLEXER_HPP
// Never included before - need to define base class.
#define __YYLEXER_HPP
#include <iostream.h>

extern "C++" {

struct yy_buffer_state;
typedef int yy_state_type;

class Lexer {
public:
	virtual ~Lexer() { }

	const char* yy_text() const { return yytext; }
	int yy_leng() const { return yyleng; }

	virtual void yy_switch_to_buffer( struct yy_buffer_state* new_buffer ) = 0;
	virtual struct yy_buffer_state *yy_create_buffer( istream* s, int size ) = 0;
	virtual void yy_delete_buffer( struct yy_buffer_state* b ) = 0;
	virtual void yyrestart( istream* s ) = 0;

	virtual int yylex() = 0;

	// Call yylex with new input/output sources.
	int yylex( istream* new_in, ostream* new_out = 0 )
		{
		yy_switch_streams( new_in, new_out );
		return yylex();
		}

	// Switch to new input/output streams.  A nil stream pointer
	// indicates "keep the current one".
	virtual void yy_switch_streams( istream* new_in = 0, ostream* new_out = 0 ) = 0;

	int yy_lineno() const { return yylineno; }
	int yy_get_debug() const { return yy_flex_debug; }
	void yy_set_debug( int flag ) { yy_flex_debug = flag; }

protected:
	char* yytext;
	int yyleng;
	int yylineno;		// only maintained if you use %option yylineno
	int yy_flex_debug;	// only has effect with -d or "%option debug"
};

}
#endif

#if defined(yyBaseLexer) || ! defined(yyBaseLexerOnce)
// Either this is the first time through (yyBaseLexerOnce not defined),
// or this is a repeated include to define a different flavor of
// yyBaseLexer, as discussed in the flex man page.
#define yyBaseLexerOnce

class yyBaseLexer : public Lexer {
public:
	// arg_yyin and arg_yyout default to the cin and cout, but we
	// only make that assignment when initializing in yylex().
	yyBaseLexer( istream* arg_yyin = 0, ostream* arg_yyout = 0 );

	virtual ~yyBaseLexer();

	void yy_initialize( void );
	void yy_finish( void );
	void yy_reset( void );
	void *yy_save_scan_state( istream *input_file );
	void yy_restore_scan_state( void *old_state );

	void yy_switch_to_buffer( struct yy_buffer_state* new_buffer );
	struct yy_buffer_state* yy_create_buffer( istream* s, int size );
	void yy_delete_buffer( struct yy_buffer_state* b );
	void yyrestart( istream* s );

	virtual void switch_streams( istream* new_in, ostream* new_out );

protected:
	// Overridable input,output and error routines
	//
	virtual int yy_lexer_input( char* buf, int max_size );
	virtual void yy_lexer_output( const char* buf, int size );
	virtual void yy_lexer_error( const char* msg );

	void yyunput( int c, char* buf_ptr );
	int yyinput();

	void yy_load_buffer_state();
	void yy_init_buffer( struct yy_buffer_state* b, istream* s );
	void yy_flush_buffer( struct yy_buffer_state* b );

	int yy_start_stack_ptr;
	int yy_start_stack_depth;
	int* yy_start_stack;

	void yy_push_state( int new_state );
	void yy_pop_state();
	int yy_top_state();

	yy_state_type yy_get_previous_state();
	yy_state_type yy_try_NUL_trans( yy_state_type current_state );
	int yy_get_next_buffer();

	istream* yyin;	// input source for default yy_lexer_input
	ostream* yyout;	// output sink for default yy_lexer_output

	struct yy_buffer_state* yy_current_buffer;

	// yy_hold_char holds the character lost when yytext is formed.
	char yy_hold_char;

	// Number of characters read into yy_ch_buf.
	int yy_n_chars;

	// Points to current character in buffer.
	char* yy_c_buf_p;

	int yy_init;		// whether we need to initialize
	int yy_start;		// start state number

	// Flag which is used to allow yywrap()'s to do buffer switches
	// instead of setting up a fresh yyin.  A bit of a hack ...
	int yy_did_buffer_switch_on_eof;

	// The following are not always needed, but may be depending
	// on use of certain flex features (like REJECT or yymore()).

	yy_state_type yy_last_accepting_state;
	char* yy_last_accepting_cpos;

	yy_state_type* yy_state_buf;
	yy_state_type* yy_state_ptr;

	char* yy_full_match;
	int* yy_full_state;
	int yy_full_lp;

	int yy_lp;
	int yy_looking_for_trail_begin;

	int yy_more_flag;
	int yy_more_len;
};

#endif

#if (defined(yyLexer) || !defined(yyLexerOnce)) && !defined(yyDerivedLexer)
#define yyLexerOnce

class yyLexer : public yyBaseLexer {
public:
	yyLexer( istream* arg_yyin = 0, ostream* arg_yyout = 0 )
	:yyBaseLexer(arg_yyin,arg_yyout){}

	virtual int yylex();
};

#endif

