///////////////////////////////////////////////////////////////////////
//   File: evhttprequest.h
//
// Author: $author$
//   Date: 8/14/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVHTTPREQUEST_H
#define _EVHTTPREQUEST_H

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 8/14/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    EVHTTP_REQUEST_METHOD_GET,
    EVHTTP_REQUEST_METHOD_HEAD,
    EVHTTP_REQUEST_METHOD_POST,
    EVHTTP_REQUEST_METHOD_PUT,
    EVHTTP_REQUEST_METHOD_DELETE,
    EVHTTP_REQUEST_METHOD_TRACE,
    EVHTTP_REQUEST_METHOD_OPTIONS,

    EVHTTP_REQUEST_METHODS
};

#define EVHTTP_REQUEST_METHOD_NAME_GET "GET"
#define EVHTTP_REQUEST_METHOD_NAME_HEAD "HEAD"
#define EVHTTP_REQUEST_METHOD_NAME_POST "POST"
#define EVHTTP_REQUEST_METHOD_NAME_PUT "PUT"
#define EVHTTP_REQUEST_METHOD_NAME_DELETE "DELETE"
#define EVHTTP_REQUEST_METHOD_NAME_TRACE "TRACE"
#define EVHTTP_REQUEST_METHOD_NAME_OPTIONS "OPTIONS"

#if defined(__cplusplus)
extern "C" {
#endif

extern int g_evhttp_request_method_value[EVHTTP_REQUEST_METHODS];
extern char* g_evhttp_request_method_name[EVHTTP_REQUEST_METHODS];

#if defined(__cplusplus)
}
#endif

#endif // _EVHTTPREQUEST_H
