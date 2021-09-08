///////////////////////////////////////////////////////////////////////
//   File: evcpstatus.c
//
// Author: $author$
//   Date: 5/1/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "evcpstatus.h"

unsigned g_evcpStatusCode[EVCP_STATUS_CODES] = 
{
    EVCP_STATUS_CODE_OK,
    EVCP_STATUS_CODE_BAD_REQUEST,
    EVCP_STATUS_CODE_INTERNAL_SERVER_ERROR
};

const char* g_evcpStatusDesc[EVCP_STATUS_CODES] = 
{
    EVCP_STATUS_DESC_OK,
    EVCP_STATUS_DESC_BAD_REQUEST,
    EVCP_STATUS_DESC_INTERNAL_SERVER_ERROR
};
