/**
 **********************************************************************
 * Copyright (c) 1988-2012 $organization$
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
 *   File: cXttp.h
 *
 * Author: $author$
 *   Date: 11/21/2012
 **********************************************************************
 */
#ifndef _CXTTP_H
#define _CXTTP_H

#include "cplatform.h"

#if !defined(CXTTP_EXPORT)
#define CXTTP_EXPORT c_IMPORT
#endif /* !defined(CXTTP_EXPORT) */

#define c_XTTP_NEWLINE "\n"

#define c_XTTP_FIELD_SEPARATOR ":"

#define c_XTTP_NAME_SEPARATOR "-"
#define c_XTTP_CONTENT_NAME "Content"
#define c_XTTP_LENGTH_NAME "Length"
#define c_XTTP_TYPE_NAME "Type"

#define c_XTTP_CONTENT_TYPE_FIELD_NAME \
    c_XTTP_CONTENT_NAME \
    c_XTTP_NAME_SEPARATOR \
    c_XTTP_TYPE_NAME

#define c_XTTP_CONTENT_LENGTH_FIELD_NAME \
    c_XTTP_CONTENT_NAME \
    c_XTTP_NAME_SEPARATOR \
    c_XTTP_LENGTH_NAME

#define c_XTTP_CONTENT_TYPE_NAME_SEPARATOR "/"
#define c_XTTP_CONTENT_TYPE_APPLICATION_NAME "application"
#define c_XTTP_CONTENT_TYPE_MULTIPART_NAME "multipart"
#define c_XTTP_CONTENT_TYPE_URLENCODED_NAME "urlencoded"
#define c_XTTP_CONTENT_TYPE_WWW_NAME "www"
#define c_XTTP_CONTENT_TYPE_X_NAME "x"
#define c_XTTP_CONTENT_TYPE_FORM_NAME "form"
#define c_XTTP_CONTENT_TYPE_DATA_NAME "data"
#define c_XTTP_CONTENT_TYPE_HTML_NAME "html"
#define c_XTTP_CONTENT_TYPE_PLAIN_NAME "plain"
#define c_XTTP_CONTENT_TYPE_TEXT_NAME "text"
#define c_XTTP_CONTENT_TYPE_XML_NAME "xml"

#define c_XTTP_CONTENT_TYPE_TEXT_PLAIN_NAME \
    c_XTTP_CONTENT_TYPE_TEXT_NAME \
    c_XTTP_CONTENT_TYPE_NAME_SEPARATOR \
    c_XTTP_CONTENT_TYPE_PLAIN_NAME

#define c_XTTP_CONTENT_TYPE_TEXT_HTML_NAME \
    c_XTTP_CONTENT_TYPE_TEXT_NAME \
    c_XTTP_CONTENT_TYPE_NAME_SEPARATOR \
    c_XTTP_CONTENT_TYPE_HTML_NAME

#define c_XTTP_CONTENT_TYPE_TEXT_XML_NAME \
    c_XTTP_CONTENT_TYPE_TEXT_NAME \
    c_XTTP_CONTENT_TYPE_NAME_SEPARATOR \
    c_XTTP_CONTENT_TYPE_XML_NAME

#define c_XTTP_CONTENT_TYPE_NONE_NAME ""

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CXTTP_H */
        

