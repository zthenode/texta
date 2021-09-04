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
 *   File: cparsercgi.hxx
 *
 * Author: $author$
 *   Date: 7/31/2008
 **********************************************************************
 */
#ifndef _CPARSERCGI_HXX
#define _CPARSERCGI_HXX

#include "cdocumenttemplatecgi.hxx"
#include "ccgistream.hxx"
#include "clexer.hxx"
#undef _CYYLEXER_AGAIN
#include "clexercgilexer.hxx"

#define DEFAULT_DOCUMENT_FILENAME_NAME \
    DEFAULT_DOCUMENT_FILENAME_EXTENSION \
    DEFAULT_FILENAMECGI_FILENAME_NAME_SUFFIX

#if !defined(DEFAULT_TEMPLATE_FILENAME_EXTENSION) 
#define DEFAULT_TEMPLATE_FILENAME_EXTENSION \
    DEFAULT_PARSERCGI_NAME
#endif /* !defined(DEFAULT_TEMPLATE_FILENAME_EXTENSION) */

#define DEFAULT_TEMPLATE_FILENAME_NAME \
    DEFAULT_TEMPLATE_FILENAME_EXTENSION \
    DEFAULT_FILENAMECGI_FILENAME_NAME_SUFFIX

#define DEFAULT_DOCUMENT_URI_NAME \
    DEFAULT_DOCUMENT_FILENAME_EXTENSION \
    DEFAULT_FILENAMECGI_URI_NAME_SUFFIX

#define DEFAULT_TEMPLATE_URI_NAME \
    DEFAULT_TEMPLATE_FILENAME_EXTENSION \
    DEFAULT_FILENAMECGI_URI_NAME_SUFFIX

#define DEFAULT_DOCUMENT_FILENAME \
    DEFAULT_PARSERCGI_NAME \
    PLATFORM_EXTENSION_SEPARATOR \
    DEFAULT_DOCUMENT_FILENAME_EXTENSION

#define DEFAULT_TEMPLATE_FILENAME \
    DEFAULT_PARSERCGI_NAME \
    PLATFORM_EXTENSION_SEPARATOR \
    DEFAULT_TEMPLATE_FILENAME_EXTENSION

#if !defined(DEFAULT_COMMENT_COLOR_CHARS) 
#define DEFAULT_COMMENT_COLOR_CHARS "teal"
#endif
#if !defined(DEFAULT_COMMENTLN_COLOR_CHARS) 
#define DEFAULT_COMMENTLN_COLOR_CHARS "teal"
#endif
#if !defined(DEFAULT_COMMENTX_COLOR_CHARS) 
#define DEFAULT_COMMENTX_COLOR_CHARS "gray"
#endif
#if !defined(DEFAULT_KEYWORD_COLOR_CHARS) 
#define DEFAULT_KEYWORD_COLOR_CHARS "blue"
#endif
#if !defined(DEFAULT_KEYWORDX_COLOR_CHARS) 
#define DEFAULT_KEYWORDX_COLOR_CHARS "purple"
#endif
#if !defined(DEFAULT_DEFINE_COLOR_CHARS) 
#define DEFAULT_DEFINE_COLOR_CHARS "maroon"
#endif
#if !defined(DEFAULT_PROCESSOR_COLOR_CHARS) 
#define DEFAULT_PROCESSOR_COLOR_CHARS "maroon"
#endif
#if !defined(DEFAULT_STRING_COLOR_CHARS) 
#define DEFAULT_STRING_COLOR_CHARS "red"
#endif
#if !defined(DEFAULT_CHAR_COLOR_CHARS) 
#define DEFAULT_CHAR_COLOR_CHARS "red"
#endif
#if !defined(DEFAULT_INVALID_COLOR_CHARS) 
#define DEFAULT_INVALID_COLOR_CHARS "red"
#endif

#define DEFAULT_BEFORE_CHARS \
    "<html><head><style type=\"text/css\">" \
    "body {color: black; }" \
    "font.comment {color: "DEFAULT_COMMENT_COLOR_CHARS"; font-style:italic; }" \
    "font.commentln {color: "DEFAULT_COMMENTLN_COLOR_CHARS"; font-style:italic; }" \
    "font.commentx {color: "DEFAULT_COMMENTX_COLOR_CHARS"; font-style:italic; }" \
    "font.keyword {color: "DEFAULT_KEYWORD_COLOR_CHARS"; font-weight: bolder; }" \
    "font.keywordx {color: "DEFAULT_KEYWORDX_COLOR_CHARS"; font-weight: bolder; }" \
    "font.define {color: "DEFAULT_DEFINE_COLOR_CHARS"; }" \
    "font.processor {color: "DEFAULT_PROCESSOR_COLOR_CHARS"; }" \
    "font.string {color: "DEFAULT_STRING_COLOR_CHARS"; }" \
    "font.char {color: "DEFAULT_CHAR_COLOR_CHARS"; }" \
    "font.invalid {color: "DEFAULT_INVALID_COLOR_CHARS"; text-decoration: underline; }" \
    "</style></head><body><pre>"
#define DEFAULT_AFTER_CHARS "</pre></body></html>"

#define DEFAULT_BEGIN_COMMENT_CHARS "<font class=\"comment\">"
#define DEFAULT_BEGIN_COMMENTLN_CHARS "<font class=\"commentln\">"
#define DEFAULT_BEGIN_COMMENTX_CHARS "<font class=\"commentx\">"
#define DEFAULT_BEGIN_PROCESSOR_CHARS "<font class=\"processor\">"
#define DEFAULT_BEGIN_KEYWORD_CHARS "<font class=\"keyword\">"
#define DEFAULT_BEGIN_KEYWORDX_CHARS "<font class=\"keywordx\">"
#define DEFAULT_BEGIN_DEFINE_CHARS "<font class=\"define\">"
#define DEFAULT_BEGIN_STRING_CHARS "<font class=\"string\">"
#define DEFAULT_BEGIN_CHAR_CHARS "<font class=\"char\">"
#define DEFAULT_BEGIN_CHARS "<font class=\"invalid\">"
#define DEFAULT_END_CHARS "</font>"

#endif /* _CPARSERCGI_HXX */
