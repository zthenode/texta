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
 *   File: cadacgi.hxx
 *
 * Author: $author$
 *   Date: 7/29/2008
 **********************************************************************
 */
#ifndef _CADACGI_HXX
#define _CADACGI_HXX

#define DEFAULT_LEXERCGI_NAME "adacgi"
#define DEFAULT_DOCUMENT_FILENAME_EXTENSION "ada"
#include "cadalexer.hxx"
#if defined(WIN32) 
/* Windows
 */
#include "clexertcgi.hxx"
#else /* defined(WIN32) */
/* Unix
 */
#include "clexercgi.hxx"
#endif /* defined(WIN32) */

/**
 **********************************************************************
 *  Typedef: cAdaCGI
 *
 *  Author: $author$
 *    Date: 7/29/2008
 **********************************************************************
 */
#if defined(WIN32) 
/* Windows
 */
typedef cLexerTCGIT
#else /* defined(WIN32) */
/* Unix
 */
typedef cLexerCGIT
#endif /* defined(WIN32) */
<cAdaLexer,
 cAdaLexerDelegate>
cAdaCGI;

#endif /* _CADACGI_HXX */
