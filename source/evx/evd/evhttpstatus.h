///////////////////////////////////////////////////////////////////////
//   File: evhttpstatus.h
//
// Author: $author$
//   Date: 5/1/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVHTTPSTATUS_H
#define _EVHTTPSTATUS_H

///////////////////////////////////////////////////////////////////////
//   Enum: 
//
// Author: $author$
//   Date: 5/1/2007
///////////////////////////////////////////////////////////////////////
enum
{
    FIRST_EVHTTP_STATUS = 0,

    EVHTTP_STATUS_OK = FIRST_EVHTTP_STATUS,
    EVHTTP_STATUS_BAD_REQUEST,
    EVHTTP_STATUS_INTERNAL_SERVER_ERROR,

    NEXT_EVHTTP_STATUS,
    LAST_EVHTTP_STATUS = NEXT_EVHTTP_STATUS-1,

    EVHTTP_STATUS_CODES = NEXT_EVHTTP_STATUS
};

///////////////////////////////////////////////////////////////////////
//   Enum: 
//
// Author: $author$
//   Date: 5/1/2007
///////////////////////////////////////////////////////////////////////
enum
{
    EVHTTP_STATUS_CODE_OK = 200,
    EVHTTP_STATUS_CODE_BAD_REQUEST = 400,
    EVHTTP_STATUS_CODE_INTERNAL_SERVER_ERROR = 500
};

#define EVHTTP_STATUS_DESC_OK "OK"
#define EVHTTP_STATUS_DESC_BAD_REQUEST "Bad Request"
#define EVHTTP_STATUS_DESC_INTERNAL_SERVER_ERROR "Internal Server Error"

#if defined(__cplusplus)
extern "C" {
#endif

extern unsigned g_evhttpStatusCode[EVHTTP_STATUS_CODES];
extern const char* g_evhttpStatusDesc[EVHTTP_STATUS_CODES];

#if defined(__cplusplus)
}
#endif

#endif // _EVHTTPSTATUS_H
