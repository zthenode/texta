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
 *   File: yylexer.hxx
 *
 * Author: $author$
 *   Date: 8/25/2003
 *
 *    $Id$
 *
 * This file defines Lexer, an abstract class which specifies the
 * external interface provided to flex C++ lexer objects, and yyIsLexer,
 * which defines a particular lexer class.
 *
 * If you want to create multiple lexer classes, you use the -P flag
 * to rename each yyIsLexer to some other xxLexer.  You then
 * include <yylexer.hpp> in your other sources once per lexer class:
 *
 *	#undef yyIsLexer
 *	#undef yyLexer
 *	#define yyIsLexer xxIsLexer
 *	#define yyLexer xxLexer
 *	#include <yylexer.hpp>
 *
 *	#undef yyIsLexer
 *	#undef yyLexer
 *	#define yyIsLexer zzIsLexer
 *	#define yyLexer zzLexer
 *	#include <yylexer.hpp>
 *	...
 *
 *  To create a dirived lexer class do the same as above and 
 *  define yyDerivedLexer as folows:
 *
 *	#undef yyIsLexer
 *	#undef yyDirivedLexer
 *	#define yyIsLexer xxIsLexer
 *  #define yyDerivedLexer yyLexer
 *	#include <yylexer.hpp>
 *
 *  class yyLexer: public yyIsLexer
 *  {
 *  ...
 *  };
 **********************************************************************
 */
#ifndef _YYLEXER_HXX
#define _YYLEXER_HXX

#include "cerror.hxx"
#include "cstream.hxx"

struct yy_buffer_state;
typedef int yy_state_type;

/**
 **********************************************************************
 *  Class: yyAnyLexer
 *
 * Author: $author$
 *   Date: 8/25/2003
 **********************************************************************
 */
class yyAnyLexer
: public cError
{
public:
    typedef cError cExtends;

    /**
     **********************************************************************
     * Destructor: ~yyAnyLexer
     *
     *     Author: $author$
     *       Date: 8/25/2003
     **********************************************************************
     */
    virtual ~yyAnyLexer()
    {
    }

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	virtual struct yy_buffer_state *yy_create_buffer( cCharStreamInterface* s, int size ) = 0;
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	virtual void yy_delete_buffer( struct yy_buffer_state* b ) = 0;
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	virtual void yy_switch_to_buffer( struct yy_buffer_state* new_buffer ) = 0;
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	virtual void yyrestart( cCharStreamInterface* s ) = 0;

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     *
	 * Switch to new input/output streams.  A nil stream pointer
	 * indicates "keep the current one".
     **********************************************************************
     */
	virtual void yy_switch_streams
    ( cCharStreamInterface* new_in = 0, cCharStreamInterface* new_out = 0 ) = 0;

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    virtual int yyprintf( const char* format,...) = 0;
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    virtual int yywrap() = 0;
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	virtual int yylex() = 0;

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     *
	 * Call yylex with new input/output sources.
     **********************************************************************
     */
	int yylex( cCharStreamInterface* new_in, cCharStreamInterface* new_out = 0 )
    {
		yy_switch_streams( new_in, new_out );
		return yylex();
    }

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	const char* yy_text() const { return yytext; }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	int yy_leng() const { return yyleng; }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	int yy_lineno() const { return yylineno; }

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	int yy_get_debug() const { return yy_flex_debug; }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	void yy_set_debug( int flag ) { yy_flex_debug = flag; }

protected:

	char* yytext;
	int yyleng;
	int yylineno;		// only maintained if you use %option yylineno
	int yy_flex_debug;	// only has effect with -d or "%option debug"
};

#endif /* #ifndef _YYLEXER_HXX */

#ifndef _YYLEXER_AGAIN
#define _YYLEXER_AGAIN

/**
 **********************************************************************
 *  Class: yyIsLexer
 *
 * Author: $author$
 *   Date: 8/25/2003
 **********************************************************************
 */
class yyIsLexer
: public yyAnyLexer
{
public:
    typedef yyAnyLexer cExtends;

    cCharStreamInterface &m_out;
    cCharStreamInterface &m_in;

    /**
     **********************************************************************
     * Constructor: yyIsLexer
     *
     *      Author: $author$
     *        Date: 8/25/2003
     **********************************************************************
     */
    yyIsLexer(cCharStreamInterface &out, cCharStreamInterface &in);
    /**
     **********************************************************************
     * Destructor: ~yyIsLexer
     *
     *     Author: $author$
     *       Date: 8/25/2003
     **********************************************************************
     */
    virtual ~yyIsLexer();

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	void yy_initialize( void );
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	void yy_finish( void );
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	void yy_reset( void );
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	void *yy_save_scan_state( cCharStreamInterface *input_file );
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	void yy_restore_scan_state( void *old_state );

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	void yy_switch_to_buffer( struct yy_buffer_state* new_buffer );
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	struct yy_buffer_state* yy_create_buffer( cCharStreamInterface* s, int size );
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	void yy_delete_buffer( struct yy_buffer_state* b );
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	void yyrestart( cCharStreamInterface* s );

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	virtual void yy_switch_streams
    ( cCharStreamInterface* new_in, cCharStreamInterface* new_out );
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    virtual int yyprintf( const char* format, ... );
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    virtual int yywrap();

protected:

	cCharStreamInterface* yyin;	// input source for default yy_lexer_input
	cCharStreamInterface* yyout;	// output sink for default yy_lexer_output

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

	int yy_start_stack_ptr;
	int yy_start_stack_depth;
	int* yy_start_stack;

	// Overridable input,output and error routines
	//
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	virtual int yy_lexer_input( char* buf, int max_size );
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	virtual void yy_lexer_output( const char* buf, int size );
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	virtual void yy_lexer_error( const char* msg );

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	void yyunput( int c, char* buf_ptr );
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	int yyinput();

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	void yy_load_buffer_state();
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	void yy_init_buffer( struct yy_buffer_state* b, cCharStreamInterface* s );
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	void yy_flush_buffer( struct yy_buffer_state* b );

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	void yy_switch_state( int new_state );
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	void yy_push_state( int new_state );
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	void yy_pop_state();
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	int yy_top_state();

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	yy_state_type yy_get_previous_state();
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	yy_state_type yy_try_NUL_trans( yy_state_type current_state );
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
	int yy_get_next_buffer();
};

#ifndef yyLexer
/**
 **********************************************************************
 *  Class: yyLexer
 *
 * Author: $author$
 *   Date: 8/25/2003
 **********************************************************************
 */
class yyLexer
: public yyIsLexer
{
public:
    typedef yyIsLexer cExtends;

    /**
     **********************************************************************
     * Constructor: yyLexer
     *
     *      Author: $author$
     *        Date: 8/25/2003
     **********************************************************************
     */
    yyLexer(cCharStreamInterface &out, cCharStreamInterface &in)
	: cExtends(out, in)
    {
    }
    /**
     **********************************************************************
     * Function: yylex
     *
     *   Author: $author$
     *     Date: 8/25/2003
     *
     * This function is generated by flex.
     **********************************************************************
     */
	virtual int yylex();
};
#endif /* #ifndef yyLexer */

#endif /* #ifndef _YYLEXER_AGAIN */
