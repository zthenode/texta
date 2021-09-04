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
 *   File: http.c
 *
 * Author: $author$
 *   Date: 3/3/2008
 **********************************************************************
 */
#include "chttp.h"

const CHAR* http_content_type[e_COUNT_HTTP_CONTENT_TYPE] = 
{
    HTTP_CONTENT_TYPE_TEXT_PLAIN_NAME,
    HTTP_CONTENT_TYPE_TEXT_HTML_NAME,
    HTTP_CONTENT_TYPE_TEXT_XML_NAME,
    HTTP_CONTENT_TYPE_URLENCODED_FORM_DATA_NAME,
    HTTP_CONTENT_TYPE_MULTIPART_FORM_DATA_NAME
};

const CHAR* http_request_method[e_COUNT_HTTP_REQUEST_METHOD]=
{
    HTTP_REQUEST_METHOD_NAME_GET,
    HTTP_REQUEST_METHOD_NAME_POST,
    HTTP_REQUEST_METHOD_NAME_PUT,
    HTTP_REQUEST_METHOD_NAME_DELETE,
    HTTP_REQUEST_METHOD_NAME_TRACE,
    HTTP_REQUEST_METHOD_NAME_HEAD,
    HTTP_REQUEST_METHOD_NAME_OPTIONS
};

const CHAR http_newline[]=HTTP_NEWLINE;
const CHAR http_field_separator[]=HTTP_FIELD_SEPARATOR;

const CHAR http_content_type_name[]=HTTP_CONTENT_TYPE_NAME;
const CHAR http_content_length_name[]=HTTP_CONTENT_LENGTH_NAME;

const CHAR http_content_type_urlencoded_form_data_name[]=HTTP_CONTENT_TYPE_URLENCODED_FORM_DATA_NAME;
const CHAR http_content_type_multipart_form_data_name[]=HTTP_CONTENT_TYPE_MULTIPART_FORM_DATA_NAME;

const CHAR http_content_type_text_name[]=HTTP_CONTENT_TYPE_TEXT_PLAIN_NAME;
const CHAR http_content_type_html_name[]=HTTP_CONTENT_TYPE_TEXT_HTML_NAME;
const CHAR http_content_type_xml_name[]=HTTP_CONTENT_TYPE_TEXT_XML_NAME;

const CHAR http_content_type_none[]="";
