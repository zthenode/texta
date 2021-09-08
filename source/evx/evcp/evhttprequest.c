///////////////////////////////////////////////////////////////////////
//   File: evhttprequest.c
//
// Author: $author$
//   Date: 8/14/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////
#include "evhttprequest.h"

int g_evhttp_request_method_value[EVHTTP_REQUEST_METHODS] = 
{
    EVHTTP_REQUEST_METHOD_GET,
    EVHTTP_REQUEST_METHOD_HEAD,
    EVHTTP_REQUEST_METHOD_POST,
    EVHTTP_REQUEST_METHOD_PUT,
    EVHTTP_REQUEST_METHOD_DELETE,
    EVHTTP_REQUEST_METHOD_TRACE,
    EVHTTP_REQUEST_METHOD_OPTIONS
};

const char* g_evhttp_request_method_name[EVHTTP_REQUEST_METHODS] = 
{
    EVHTTP_REQUEST_METHOD_NAME_GET,
    EVHTTP_REQUEST_METHOD_NAME_HEAD,
    EVHTTP_REQUEST_METHOD_NAME_POST,
    EVHTTP_REQUEST_METHOD_NAME_PUT,
    EVHTTP_REQUEST_METHOD_NAME_DELETE,
    EVHTTP_REQUEST_METHOD_NAME_TRACE,
    EVHTTP_REQUEST_METHOD_NAME_OPTIONS
};
