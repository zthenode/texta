///////////////////////////////////////////////////////////////////////
//   File: evhttpstatus.c
//
// Author: $author$
//   Date: 5/1/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "evhttpstatus.h"

unsigned g_evhttpStatusCode[EVHTTP_STATUS_CODES] = 
{
    EVHTTP_STATUS_CODE_OK,
    EVHTTP_STATUS_CODE_BAD_REQUEST,
    EVHTTP_STATUS_CODE_INTERNAL_SERVER_ERROR
};

const char* g_evhttpStatusDesc[EVHTTP_STATUS_CODES] = 
{
    EVHTTP_STATUS_DESC_OK,
    EVHTTP_STATUS_DESC_BAD_REQUEST,
    EVHTTP_STATUS_DESC_INTERNAL_SERVER_ERROR
};
