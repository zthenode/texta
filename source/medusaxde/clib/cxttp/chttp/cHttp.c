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
 *   File: cHttp.c
 *
 * Author: $author$
 *   Date: 11/21/2012
 **********************************************************************
 */
#define CHTTP_EXPORT c_EXPORT
#include "cHttp.h"
#undef CHTTP_EXPORT
        
const CHAR c_http_newline[] = c_HTTP_NEWLINE;
const CHAR c_http_field_separator[] = c_HTTP_FIELD_SEPARATOR;

const CHAR c_http_content_type_field_name[] = c_HTTP_CONTENT_TYPE_FIELD_NAME;
const CHAR c_http_content_length_field_name[] = c_HTTP_CONTENT_LENGTH_FIELD_NAME;

/*
 * content types
 */
const CHAR c_http_content_type_urlencoded_form_data_name[] = c_HTTP_CONTENT_TYPE_URLENCODED_FORM_DATA_NAME;
const CHAR c_http_content_type_multipart_form_data_name[] = c_HTTP_CONTENT_TYPE_MULTIPART_FORM_DATA_NAME;
const CHAR c_http_content_type_text_name[] = c_HTTP_CONTENT_TYPE_TEXT_PLAIN_NAME;
const CHAR c_http_content_type_html_name[] = c_HTTP_CONTENT_TYPE_TEXT_HTML_NAME;
const CHAR c_http_content_type_xml_name[] = c_HTTP_CONTENT_TYPE_TEXT_XML_NAME;
const CHAR c_http_content_type_none[] = c_HTTP_CONTENT_TYPE_NONE_NAME;

const CHAR* c_http_content_type_name[e_COUNT_HTTP_CONTENT_TYPE] = 
{
    c_http_content_type_text_name,
    c_http_content_type_html_name,
    c_http_content_type_xml_name,
    c_http_content_type_urlencoded_form_data_name,
    c_http_content_type_multipart_form_data_name
};

const char* c_http_content_type_get_name(eHttpContentType type)
{
    const char* name = 0;
    if ((e_FIRST_HTTP_CONTENT_TYPE <= type) && (e_LAST_HTTP_CONTENT_TYPE >= type))
        name = c_http_content_type_name[type-e_FIRST_HTTP_CONTENT_TYPE];
    return name;
}

/*
 * request methods
 */
const CHAR c_http_request_method_get_name[] = c_HTTP_REQUEST_METHOD_NAME_GET;
const CHAR c_http_request_method_post_name[] = c_HTTP_REQUEST_METHOD_NAME_POST;
const CHAR c_http_request_method_put_name[] = c_HTTP_REQUEST_METHOD_NAME_PUT;
const CHAR c_http_request_method_delete_name[] = c_HTTP_REQUEST_METHOD_NAME_DELETE;
const CHAR c_http_request_method_trace_name[] = c_HTTP_REQUEST_METHOD_NAME_TRACE;
const CHAR c_http_request_method_head_name[] = c_HTTP_REQUEST_METHOD_NAME_HEAD;
const CHAR c_http_request_method_options_name[] = c_HTTP_REQUEST_METHOD_NAME_OPTIONS;

const CHAR* c_http_request_method_name[e_COUNT_HTTP_REQUEST_METHOD]=
{
    c_http_request_method_get_name,
    c_http_request_method_post_name,
    c_http_request_method_put_name,
    c_http_request_method_delete_name,
    c_http_request_method_trace_name,
    c_http_request_method_head_name,
    c_http_request_method_options_name
};

