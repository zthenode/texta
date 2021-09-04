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
 *   File: cxtp.h
 *
 * Author: $author$
 *   Date: 3/3/2008
 **********************************************************************
 */
#ifndef _CXTTP_H
#define _CXTTP_H

#include "cplatform.h"

#define XTTP_NEWLINE "\n"

#define XTTP_FIELD_SEPARATOR ":"

#define XTTP_NAME_SEPARATOR "-"
#define XTTP_CONTENT_NAME "Content"
#define XTTP_LENGTH_NAME "Length"
#define XTTP_TYPE_NAME "Type"

#define XTTP_CONTENT_TYPE_NAME \
    XTTP_CONTENT_NAME \
    XTTP_NAME_SEPARATOR \
    XTTP_TYPE_NAME

#define XTTP_CONTENT_LENGTH_NAME \
    XTTP_CONTENT_NAME \
    XTTP_NAME_SEPARATOR \
    XTTP_LENGTH_NAME

#define XTTP_CONTENT_TYPE_NAME_SEPARATOR "/"
#define XTTP_CONTENT_TYPE_APPLICATION_NAME "application"
#define XTTP_CONTENT_TYPE_MULTIPART_NAME "multipart"
#define XTTP_CONTENT_TYPE_URLENCODED_NAME "urlencoded"
#define XTTP_CONTENT_TYPE_WWW_NAME "www"
#define XTTP_CONTENT_TYPE_X_NAME "x"
#define XTTP_CONTENT_TYPE_FORM_NAME "form"
#define XTTP_CONTENT_TYPE_DATA_NAME "data"
#define XTTP_CONTENT_TYPE_HTML_NAME "html"
#define XTTP_CONTENT_TYPE_PLAIN_NAME "plain"
#define XTTP_CONTENT_TYPE_TEXT_NAME "text"
#define XTTP_CONTENT_TYPE_XML_NAME "xml"

#define XTTP_CONTENT_TYPE_TEXT_PLAIN_NAME \
    XTTP_CONTENT_TYPE_TEXT_NAME \
    XTTP_CONTENT_TYPE_NAME_SEPARATOR \
    XTTP_CONTENT_TYPE_PLAIN_NAME

#define XTTP_CONTENT_TYPE_TEXT_HTML_NAME \
    XTTP_CONTENT_TYPE_TEXT_NAME \
    XTTP_CONTENT_TYPE_NAME_SEPARATOR \
    XTTP_CONTENT_TYPE_HTML_NAME

#define XTTP_CONTENT_TYPE_TEXT_XML_NAME \
    XTTP_CONTENT_TYPE_TEXT_NAME \
    XTTP_CONTENT_TYPE_NAME_SEPARATOR \
    XTTP_CONTENT_TYPE_XML_NAME

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CXTTP_H */
