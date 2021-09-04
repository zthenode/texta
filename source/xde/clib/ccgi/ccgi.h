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
 *   File: ccgi.h
 *
 * Author: $author$
 *   Date: 3/3/2008
 **********************************************************************
 */
#ifndef _CCGI_H
#define _CCGI_H

#include "chttp.h"

/**
 **********************************************************************
 *   Enum: eCGIEnv
 *
 * Author: $author$
 *   Date: 3/3/2008
 **********************************************************************
 */
typedef int
eCGIEnv;
enum
{
    e_FIRST_CGI_ENV = 0,

    e_CGI_ENV_GATEWAY_INTERFACE = e_FIRST_CGI_ENV,
	e_CGI_ENV_SERVER_NAME,
	e_CGI_ENV_SERVER_PORT,
	e_CGI_ENV_SERVER_PROTOCOL,
	e_CGI_ENV_SERVER_SOFTWARE,
	e_CGI_ENV_AUTH_TYPE,
	e_CGI_ENV_CONTENT_FILE,
	e_CGI_ENV_CONTENT_LENGTH,
	e_CGI_ENV_CONTENT_TYPE,
	e_CGI_ENV_OUTPUT_FILE,
	e_CGI_ENV_PATH_INFO,
	e_CGI_ENV_PATH_TRANSLATED,
	e_CGI_ENV_QUERY_STRING,
	e_CGI_ENV_REMOTE_ADDR,
	e_CGI_ENV_REMOTE_USER,
	e_CGI_ENV_REQUEST_LINE,
	e_CGI_ENV_REQUEST_METHOD,
	e_CGI_ENV_REMOTE_HOST,
	e_CGI_ENV_REMOTE_IDENT,
	e_CGI_ENV_HTTP_ACCEPT,
	e_CGI_ENV_HTTP_USER_AGENT,
	e_CGI_ENV_SCRIPT_NAME,

    e_NEXT_CGI_ENV,
    e_LAST_CGI_ENV = e_NEXT_CGI_ENV-1,
    e_COUNT_CGI_ENV = e_LAST_CGI_ENV-e_FIRST_CGI_ENV+1
};

#define CGI_ENV_NAME_GATEWAY_INTERFACE "GATEWAY_INTERFACE"
#define CGI_ENV_NAME_SERVER_NAME "SERVER_NAME"
#define CGI_ENV_NAME_SERVER_PORT "SERVER_PORT"
#define CGI_ENV_NAME_SERVER_PROTOCOL "SERVER_PROTOCOL"
#define CGI_ENV_NAME_SERVER_SOFTWARE "SERVER_SOFTWARE"
#define CGI_ENV_NAME_AUTH_TYPE "AUTH_TYPE"
#define CGI_ENV_NAME_CONTENT_FILE "CONTENT_FILE"
#define CGI_ENV_NAME_CONTENT_LENGTH "CONTENT_LENGTH"
#define CGI_ENV_NAME_CONTENT_TYPE "CONTENT_TYPE"
#define CGI_ENV_NAME_OUTPUT_FILE "OUTPUT_FILE"
#define CGI_ENV_NAME_PATH_INFO "PATH_INFO"
#define CGI_ENV_NAME_PATH_TRANSLATED "PATH_TRANSLATED"
#define CGI_ENV_NAME_QUERY_STRING "QUERY_STRING"
#define CGI_ENV_NAME_REMOTE_ADDR "REMOTE_ADDR"
#define CGI_ENV_NAME_REMOTE_USER "REMOTE_USER"
#define CGI_ENV_NAME_REQUEST_LINE "REQUEST_LINE"
#define CGI_ENV_NAME_REQUEST_METHOD "REQUEST_METHOD"
#define CGI_ENV_NAME_REMOTE_HOST "REMOTE_HOST"
#define CGI_ENV_NAME_REMOTE_IDENT "REMOTE_IDENT"
#define CGI_ENV_NAME_HTTP_ACCEPT "HTTP_ACCEPT"
#define CGI_ENV_NAME_HTTP_USER_AGENT "HTTP_USER_AGENT"
#define CGI_ENV_NAME_SCRIPT_NAME "SCRIPT_NAME"

/**
 **********************************************************************
 *   Enum: eCGIRunMode
 *
 * Author: $author$
 *   Date: 3/4/2008
 **********************************************************************
 */
typedef int
eCGIRunMode;
enum
{
    e_CGI_RUN_MODE_NONE = 0,
    e_FIRST_CGI_RUN_MODE = 1,

    e_CGI_RUN_MODE_COMMAND = e_FIRST_CGI_RUN_MODE,
    e_CGI_RUN_MODE_CGI,

    e_NEXT_CGI_RUN_MODE,
    e_LAST_CGI_RUN_MODE = e_NEXT_CGI_RUN_MODE-1,
    e_COUNT_CGI_RUN_MODE = e_LAST_CGI_RUN_MODE-e_FIRST_CGI_RUN_MODE+1
};

#define CGI_RUN_MODE_NAME_COMMAND "COMMAND"
#define CGI_RUN_MODE_NAME_CGI "CGI"

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

extern const CHAR* cgi_env_name[e_COUNT_CGI_ENV];
extern const CHAR* cgi_run_mode_name[e_COUNT_CGI_RUN_MODE];

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CCGI_H */
