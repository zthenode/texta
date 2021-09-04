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
 *   File: ccxxcgi.hxx
 *
 * Author: $author$
 *   Date: 9/3/2008
 **********************************************************************
 */
#ifndef _CCXXCGI_HXX
#define _CCXXCGI_HXX

#define DEFAULT_LEXERCGI_NAME "cxxcgi"
#define DEFAULT_DOCUMENT_FILENAME_EXTENSION "cxx"

#include "ccxxlexer.hxx"
#include "clexertcgi.hxx"

/**
 **********************************************************************
 *  Typedef: cCXXCGI
 *
 *  Author: $author$
 *    Date: 9/3/2008
 **********************************************************************
 */
typedef cLexerTCGIT
<cCXXLexer,
 cCXXLexerDelegate>
cCXXCGI;

#endif /* _CCXXCGI_HXX */
