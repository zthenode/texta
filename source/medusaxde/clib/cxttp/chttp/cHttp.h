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
 *   File: cHttp.h
 *
 * Author: $author$
 *   Date: 11/21/2012
 **********************************************************************
 */
#ifndef _CHTTP_H
#define _CHTTP_H

#include "cXttp.h"

#if !defined(CHTTP_EXPORT)
#define CHTTP_EXPORT c_IMPORT
#endif /* !defined(CHTTP_EXPORT) */

#define c_HTTP_NEWLINE  \
    c_XTTP_NEWLINE 

#define c_HTTP_FIELD_SEPARATOR \
    c_XTTP_FIELD_SEPARATOR

#define c_HTTP_CONTENT_TYPE_FIELD_NAME \
    c_XTTP_CONTENT_TYPE_FIELD_NAME

#define c_HTTP_CONTENT_LENGTH_FIELD_NAME \
    c_XTTP_CONTENT_LENGTH_FIELD_NAME

/*
 * content types
 */
#define c_HTTP_CONTENT_TYPE_APPLICATION_X_WWW_FORM_URLENCODED_NAME \
    c_XTTP_CONTENT_TYPE_APPLICATION_NAME \
    c_XTTP_CONTENT_TYPE_NAME_SEPARATOR \
    c_XTTP_CONTENT_TYPE_X_NAME \
    c_XTTP_NAME_SEPARATOR \
    c_XTTP_CONTENT_TYPE_WWW_NAME \
    c_XTTP_NAME_SEPARATOR \
    c_XTTP_CONTENT_TYPE_FORM_NAME \
    c_XTTP_NAME_SEPARATOR \
    c_XTTP_CONTENT_TYPE_URLENCODED_NAME

#define c_HTTP_CONTENT_TYPE_URLENCODED_FORM_DATA_NAME \
    c_HTTP_CONTENT_TYPE_APPLICATION_X_WWW_FORM_URLENCODED_NAME

#define c_HTTP_CONTENT_TYPE_MULTIPART_FORM_DATA_NAME \
    c_XTTP_CONTENT_TYPE_MULTIPART_NAME \
    c_XTTP_CONTENT_TYPE_NAME_SEPARATOR \
    c_XTTP_CONTENT_TYPE_FORM_NAME \
    c_XTTP_NAME_SEPARATOR \
    c_XTTP_CONTENT_TYPE_DATA_NAME

#define c_HTTP_CONTENT_TYPE_TEXT_PLAIN_NAME \
    c_XTTP_CONTENT_TYPE_TEXT_PLAIN_NAME

#define c_HTTP_CONTENT_TYPE_TEXT_HTML_NAME \
    c_XTTP_CONTENT_TYPE_TEXT_HTML_NAME

#define c_HTTP_CONTENT_TYPE_TEXT_XML_NAME \
    c_XTTP_CONTENT_TYPE_TEXT_XML_NAME

#define c_HTTP_CONTENT_TYPE_NONE_NAME \
    c_XTTP_CONTENT_TYPE_NONE_NAME

/**
 **********************************************************************
 *    Enum: eHttpContentType
 *
 *  Author: $author$
 *    Date: 11/21/2012
 **********************************************************************
 */
typedef int eHttpContentType;
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

/*
 * request methods
 */
#define c_HTTP_REQUEST_METHOD_NAME_GET "GET"
#define c_HTTP_REQUEST_METHOD_NAME_POST "POST"
#define c_HTTP_REQUEST_METHOD_NAME_PUT "PUT"
#define c_HTTP_REQUEST_METHOD_NAME_DELETE "DELETE"
#define c_HTTP_REQUEST_METHOD_NAME_TRACE "TRACE"
#define c_HTTP_REQUEST_METHOD_NAME_HEAD "HEAD"
#define c_HTTP_REQUEST_METHOD_NAME_OPTIONS "OPTIONS"

/**
 **********************************************************************
 *    Enum: eHttpRequestMethod
 *
 *  Author: $author$
 *    Date: 11/21/2012
 **********************************************************************
 */
typedef int eHttpRequestMethod;
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

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

extern CHTTP_EXPORT const CHAR c_http_newline[];
extern CHTTP_EXPORT const CHAR c_http_field_separator[];

extern CHTTP_EXPORT const CHAR c_http_content_type_field_name[];
extern CHTTP_EXPORT const CHAR c_http_content_length_field_name[];

/*
 * content types
 */
extern CHTTP_EXPORT const CHAR c_http_content_type_urlencoded_form_data_name[];
extern CHTTP_EXPORT const CHAR c_http_content_type_multipart_form_data_name[];
extern CHTTP_EXPORT const CHAR c_http_content_type_text_name[];
extern CHTTP_EXPORT const CHAR c_http_content_type_html_name[];
extern CHTTP_EXPORT const CHAR c_http_content_type_xml_name[];
extern CHTTP_EXPORT const CHAR c_http_content_type_none_name[];
extern CHTTP_EXPORT const CHAR* c_http_content_type_name[e_COUNT_HTTP_CONTENT_TYPE];

extern CHTTP_EXPORT const char* c_http_content_type_get_name(eHttpContentType type);

/*
 * request methods
 */
extern CHTTP_EXPORT const CHAR c_http_request_method_get_name[];
extern CHTTP_EXPORT const CHAR c_http_request_method_post_name[];
extern CHTTP_EXPORT const CHAR c_http_request_method_put_name[];
extern CHTTP_EXPORT const CHAR c_http_request_method_delete_name[];
extern CHTTP_EXPORT const CHAR c_http_request_method_trace_name[];
extern CHTTP_EXPORT const CHAR c_http_request_method_head_name[];
extern CHTTP_EXPORT const CHAR c_http_request_method_options_name[];
extern CHTTP_EXPORT const CHAR* c_http_request_method_name[e_COUNT_HTTP_REQUEST_METHOD];

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CHTTP_H */
        

