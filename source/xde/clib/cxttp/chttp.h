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
 *   File: chttp.h
 *
 * Author: $author$
 *   Date: 3/3/2008
 **********************************************************************
 */
#ifndef _CHTTP_H
#define _CHTTP_H

#include "cxttp.h"

#define HTTP_NEWLINE \
    XTTP_NEWLINE

#define HTTP_FIELD_SEPARATOR \
    XTTP_FIELD_SEPARATOR

#define HTTP_CONTENT_TYPE_NAME \
    XTTP_CONTENT_TYPE_NAME

#define HTTP_CONTENT_LENGTH_NAME \
    XTTP_CONTENT_LENGTH_NAME

#define HTTP_CONTENT_TYPE_APPLICATION_X_WWW_FORM_URLENCODED_NAME \
    XTTP_CONTENT_TYPE_APPLICATION_NAME \
    XTTP_CONTENT_TYPE_NAME_SEPARATOR \
    XTTP_CONTENT_TYPE_X_NAME \
    XTTP_NAME_SEPARATOR \
    XTTP_CONTENT_TYPE_WWW_NAME \
    XTTP_NAME_SEPARATOR \
    XTTP_CONTENT_TYPE_FORM_NAME \
    XTTP_NAME_SEPARATOR \
    XTTP_CONTENT_TYPE_URLENCODED_NAME

#define HTTP_CONTENT_TYPE_URLENCODED_FORM_DATA_NAME \
    HTTP_CONTENT_TYPE_APPLICATION_X_WWW_FORM_URLENCODED_NAME

#define HTTP_CONTENT_TYPE_MULTIPART_FORM_DATA_NAME \
    XTTP_CONTENT_TYPE_MULTIPART_NAME \
    XTTP_CONTENT_TYPE_NAME_SEPARATOR \
    XTTP_CONTENT_TYPE_FORM_NAME \
    XTTP_NAME_SEPARATOR \
    XTTP_CONTENT_TYPE_DATA_NAME

#define HTTP_CONTENT_TYPE_TEXT_PLAIN_NAME \
    XTTP_CONTENT_TYPE_TEXT_PLAIN_NAME

#define HTTP_CONTENT_TYPE_TEXT_HTML_NAME \
    XTTP_CONTENT_TYPE_TEXT_HTML_NAME

#define HTTP_CONTENT_TYPE_TEXT_XML_NAME \
    XTTP_CONTENT_TYPE_TEXT_XML_NAME

/**
 **********************************************************************
 *   Enum:  eHTTPContentType
 *
 * Author: $author$
 *   Date: 3/24/2008
 **********************************************************************
 */
typedef int 
eHTTPContentType;
enum
{
    e_HTTP_CONTENT_TYPE_NONE = 0,
    e_FIRST_HTTP_CONTENT_TYPE = 1,

    e_HTTP_CONTENT_TYPE_TEXT = e_FIRST_HTTP_CONTENT_TYPE,
    e_HTTP_CONTENT_TYPE_HTML,
    e_HTTP_CONTENT_TYPE_XML,
    e_HTTP_CONTENT_TYPE_URLENCODED_FORM_DATA,
    e_HTTP_CONTENT_TYPE_MULTIPART_FORM_DATA,

    e_NEXT_HTTP_CONTENT_TYPE,
    e_LAST_HTTP_CONTENT_TYPE = e_NEXT_HTTP_CONTENT_TYPE-1,
    e_COUNT_HTTP_CONTENT_TYPE = e_LAST_HTTP_CONTENT_TYPE-e_FIRST_HTTP_CONTENT_TYPE+1
};

/**
 **********************************************************************
 *   Enum: eHTTPRequestMethod
 *
 * Author: $author$
 *   Date: 3/3/2008
 **********************************************************************
 */
typedef int
eHTTPRequestMethod;
enum
{
    e_HTTP_REQUEST_METHOD_NONE = 0,
    e_FIRST_HTTP_REQUEST_METHOD = 1,

    e_HTTP_REQUEST_METHOD_GET = e_FIRST_HTTP_REQUEST_METHOD,
    e_HTTP_REQUEST_METHOD_POST,
    e_HTTP_REQUEST_METHOD_PUT,
    e_HTTP_REQUEST_METHOD_DELETE,
    e_HTTP_REQUEST_METHOD_TRACE,
    e_HTTP_REQUEST_METHOD_HEAD,
    e_HTTP_REQUEST_METHOD_OPTIONS,

    e_NEXT_HTTP_REQUEST_METHOD,
    e_LAST_HTTP_REQUEST_METHOD = e_NEXT_HTTP_REQUEST_METHOD-1,
    e_COUNT_HTTP_REQUEST_METHOD = e_LAST_HTTP_REQUEST_METHOD-e_FIRST_HTTP_REQUEST_METHOD+1,
};

#define HTTP_REQUEST_METHOD_NAME_GET "GET"
#define HTTP_REQUEST_METHOD_NAME_POST "POST"
#define HTTP_REQUEST_METHOD_NAME_PUT "PUT"
#define HTTP_REQUEST_METHOD_NAME_DELETE "DELETE"
#define HTTP_REQUEST_METHOD_NAME_TRACE "TRACE"
#define HTTP_REQUEST_METHOD_NAME_HEAD "HEAD"
#define HTTP_REQUEST_METHOD_NAME_OPTIONS "OPTIONS"

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

extern const CHAR* http_content_type[e_COUNT_HTTP_CONTENT_TYPE];
extern const CHAR* http_request_method[e_COUNT_HTTP_REQUEST_METHOD];

extern const CHAR http_newline[];
extern const CHAR http_field_separator[];

extern const CHAR http_content_type_name[];
extern const CHAR http_content_length_name[];

extern const CHAR http_content_type_urlencoded_form_data_name[];
extern const CHAR http_content_type_multipart_form_data_name[];

extern const CHAR http_content_type_text_name[];
extern const CHAR http_content_type_html_name[];
extern const CHAR http_content_type_xml_name[];

extern const CHAR http_content_type_none_name[];

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CHTTP_H */
