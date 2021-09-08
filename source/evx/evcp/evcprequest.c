///////////////////////////////////////////////////////////////////////
//   File: evcprequest.c
//
// Author: $author$
//   Date: 5/14/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "evcprequest.h"

int g_evcpRequestActionValue[EVCP_REQUEST_ACTIONS] = 
{
    EVCP_REQUEST_ACTION_CI,
    EVCP_REQUEST_ACTION_CO,
    EVCP_REQUEST_ACTION_DO,
    EVCP_REQUEST_ACTION_STOP,
    EVCP_REQUEST_ACTION_RESTART,
    EVCP_REQUEST_ACTION_HELLO
};

const char* g_evcpRequestActionName[EVCP_REQUEST_ACTIONS] = 
{
    EVCP_REQUEST_ACTION_NAME_CI,
    EVCP_REQUEST_ACTION_NAME_CO,
    EVCP_REQUEST_ACTION_NAME_DO,
    EVCP_REQUEST_ACTION_NAME_STOP,
    EVCP_REQUEST_ACTION_NAME_RESTART,
    EVCP_REQUEST_ACTION_NAME_HELLO
};
