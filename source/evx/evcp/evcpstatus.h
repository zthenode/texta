///////////////////////////////////////////////////////////////////////
//   File: evcpstatus.h
//
// Author: $author$
//   Date: 5/1/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCPSTATUS_H
#define _EVCPSTATUS_H

///////////////////////////////////////////////////////////////////////
//  Typedef: EvcpStatus
//
//   Author: $author$
//     Date: 5/29/2007
///////////////////////////////////////////////////////////////////////
typedef int EvcpStatus;

///////////////////////////////////////////////////////////////////////
//   Enum: 
//
// Author: $author$
//   Date: 5/1/2007
///////////////////////////////////////////////////////////////////////
enum
{
    FIRST_EVCP_STATUS = 0,

    EVCP_STATUS_OK = FIRST_EVCP_STATUS,
    EVCP_STATUS_BAD_REQUEST,
    EVCP_STATUS_INTERNAL_SERVER_ERROR,

    NEXT_EVCP_STATUS,
    LAST_EVCP_STATUS = NEXT_EVCP_STATUS-1,

    EVCP_STATUS_CODES = NEXT_EVCP_STATUS
};

///////////////////////////////////////////////////////////////////////
//   Enum: 
//
// Author: $author$
//   Date: 5/1/2007
///////////////////////////////////////////////////////////////////////
enum
{
    EVCP_STATUS_CODE_OK = 200,
    EVCP_STATUS_CODE_BAD_REQUEST = 400,
    EVCP_STATUS_CODE_INTERNAL_SERVER_ERROR = 500
};

#define EVCP_STATUS_DESC_OK "OK"
#define EVCP_STATUS_DESC_BAD_REQUEST "Bad Request"
#define EVCP_STATUS_DESC_INTERNAL_SERVER_ERROR "Internal Server Error"

#if defined(__cplusplus)
extern "C" {
#endif

extern unsigned g_evcpStatusCode[EVCP_STATUS_CODES];
extern const char* g_evcpStatusDesc[EVCP_STATUS_CODES];

#if defined(__cplusplus)
}
#endif

#endif // _EVCPSTATUS_H
