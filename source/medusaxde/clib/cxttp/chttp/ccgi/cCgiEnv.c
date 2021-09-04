/**
 **********************************************************************
 * Copyright (c) 1988-2011 $organization$
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
 *   File: cCgiEnv.c
 *
 * Author: $author$
 *   Date: 6/5/2011
 **********************************************************************
 */
#define CCGIENV_EXPORT c_EXPORT
#include "cCgiEnv.h"
        
CCGIENV_EXPORT const char* c_cgi_env_name[e_COUNT_CGI_ENV] =
{
    c_CGI_ENV_NAME_GATEWAY_INTERFACE,
    c_CGI_ENV_NAME_SERVER_NAME,
    c_CGI_ENV_NAME_SERVER_PORT,
    c_CGI_ENV_NAME_SERVER_PROTOCOL,
    c_CGI_ENV_NAME_SERVER_SOFTWARE,
    c_CGI_ENV_NAME_AUTH_TYPE,
    c_CGI_ENV_NAME_CONTENT_FILE,
    c_CGI_ENV_NAME_CONTENT_LENGTH,
    c_CGI_ENV_NAME_CONTENT_TYPE,
    c_CGI_ENV_NAME_OUTPUT_FILE,
    c_CGI_ENV_NAME_PATH_INFO,
    c_CGI_ENV_NAME_PATH_TRANSLATED,
    c_CGI_ENV_NAME_QUERY_STRING,
    c_CGI_ENV_NAME_REMOTE_ADDR,
    c_CGI_ENV_NAME_REMOTE_USER,
    c_CGI_ENV_NAME_REQUEST_LINE,
    c_CGI_ENV_NAME_REQUEST_METHOD,
    c_CGI_ENV_NAME_REMOTE_HOST,
    c_CGI_ENV_NAME_REMOTE_IDENT,
    c_CGI_ENV_NAME_HTTP_ACCEPT,
    c_CGI_ENV_NAME_HTTP_USER_AGENT,
    c_CGI_ENV_NAME_SCRIPT_NAME
};

CCGIENV_EXPORT const char* c_cgi_env_get_name(eCgiEnv env)
{
    if ((e_FIRST_CGI_ENV <= env) && (e_LAST_CGI_ENV >= env))
        return c_cgi_env_name[env-e_FIRST_CGI_ENV];
    return 0;
}

#undef CCGIENV_EXPORT
