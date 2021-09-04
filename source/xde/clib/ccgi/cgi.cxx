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
 *   File: cgi.cxx
 *
 * Author: $author$
 *   Date: 3/3/2008
 **********************************************************************
 */
#include "cgi.hxx"

#if !defined(CGI_DEBUG_LEVELS)
#define CGI_DEBUG_LEVELS 0
#endif /* !defined(CGI_DEBUG_LEVELS) */

const CHAR* cgi_env_name[e_COUNT_CGI_ENV]=
{
    CGI_ENV_NAME_GATEWAY_INTERFACE,
    CGI_ENV_NAME_SERVER_NAME,
    CGI_ENV_NAME_SERVER_PORT,
    CGI_ENV_NAME_SERVER_PROTOCOL,
    CGI_ENV_NAME_SERVER_SOFTWARE,
    CGI_ENV_NAME_AUTH_TYPE,
    CGI_ENV_NAME_CONTENT_FILE,
    CGI_ENV_NAME_CONTENT_LENGTH,
    CGI_ENV_NAME_CONTENT_TYPE,
    CGI_ENV_NAME_OUTPUT_FILE,
    CGI_ENV_NAME_PATH_INFO,
    CGI_ENV_NAME_PATH_TRANSLATED,
    CGI_ENV_NAME_QUERY_STRING,
    CGI_ENV_NAME_REMOTE_ADDR,
    CGI_ENV_NAME_REMOTE_USER,
    CGI_ENV_NAME_REQUEST_LINE,
    CGI_ENV_NAME_REQUEST_METHOD,
    CGI_ENV_NAME_REMOTE_HOST,
    CGI_ENV_NAME_REMOTE_IDENT,
    CGI_ENV_NAME_HTTP_ACCEPT,
    CGI_ENV_NAME_HTTP_USER_AGENT,
    CGI_ENV_NAME_SCRIPT_NAME
};

const CHAR* cgi_run_mode_name[e_COUNT_CGI_RUN_MODE] = 
{
    CGI_RUN_MODE_NAME_COMMAND,
    CGI_RUN_MODE_NAME_CGI
};

/**
 **********************************************************************
 * Function: main
 *
 *   Author: $author$
 *     Date: 3/3/2008
 **********************************************************************
 */
int main(int argc, char** argv, char** env)
{
    DF(main)
    int err = 0;
    int unequal;
    int args,argn;
    const char* arg;
    char argChar;
    cDebugLevelsMainArg* debugArg;
    cMainInterface* theMain;

    SET_DEBUG_LEVELS(CGI_DEBUG_LEVELS);

    if ((debugArg = cDebugLevelsMainArg::m_instance))
    for (args=0,argn=1; argn<argc; argn++)
    {
        if ('-' == (arg = argv[argn])[0])
        {
            if ('-' == arg[1])
            {
                if ((unequal = debugArg->CompareName(arg+1, 1)))
                    continue;
                arg = 0;
            }
            else 
            {
                if ((unequal = debugArg->CompareShortName(arg+1, 1)))
                    continue;
                if ((argChar = arg[2]))
                    arg = arg+2;
                else arg = 0;
            }
            debugArg->MainArg
            (args, argn, arg, argc, 
             (const char**)argv, (const char**)env);
        }
    }

    DBF("() in...\n");

    if ((theMain = theMain->GetMain()))
        err = theMain->Main(argc, argv, env);
    else DBW("() GetMain() returned 0\n");

    DBF("() ...out\n");
    return err;
}
