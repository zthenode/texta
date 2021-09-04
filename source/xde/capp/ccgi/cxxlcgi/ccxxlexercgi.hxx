/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: ccxxlexercgi.hxx
 *
 * Author: $author$
 *   Date: 4/14/2010
 **********************************************************************
 */
#ifndef _CCXXLEXERCGI_HXX
#define _CCXXLEXERCGI_HXX

#define DEFAULT_LEXERCGI_NAME "cxxlcgi"
#define DEFAULT_TEMPLATE_FILENAME_EXTENSION "lcgi"
#define DEFAULT_DOCUMENT_FILENAME_EXTENSION "cxx"

#include "ccxxlexer.hxx"
#include "clexertcgi.hxx"

/**
 **********************************************************************
 * Typedef: cCXXLexerCGI
 *
 *  Author: $author$
 *    Date: 4/14/2010
 **********************************************************************
 */
typedef cLexerTCGIT
<cCXXLexer,
 cCXXLexerDelegate>
cCXXLexerCGI;

#endif /* _CCXXLEXERCGI_HXX */
