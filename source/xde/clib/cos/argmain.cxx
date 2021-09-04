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
 *   File: argmain.cxx
 *
 * Author: $author$
 *   Date: 2/15/2008
 **********************************************************************
 */

#include "cargmain.hxx"
#include "cdebug.hxx"

#if !defined(DEFAULT_MAIN_DEBUG_LEVELS) 
#if defined(DEFAULT_LOGGING_LEVELS_ERROR) 
#define DEFAULT_MAIN_DEBUG_LEVELS DEBUG_LEVELS_ERROR
#else /* defined(DEFAULT_LOGGING_LEVELS_ERROR) */
#if defined(DEFAULT_LOGGING_LEVELS_DEBUG) 
#define DEFAULT_MAIN_DEBUG_LEVELS DEBUG_LEVELS_DEBUG
#else /* defined(DEFAULT_LOGGING_LEVELS_DEBUG) */
#if defined(DEFAULT_LOGGING_LEVELS_TRACE) 
#define DEFAULT_MAIN_DEBUG_LEVELS DEBUG_LEVELS_TRACE
#else /* defined(DEFAULT_LOGGING_LEVELS_TRACE) */
#endif /* defined(DEFAULT_LOGGING_LEVELS_TRACE) */
#endif /* defined(DEFAULT_LOGGING_LEVELS_DEBUG) */
#endif /* defined(DEFAULT_LOGGING_LEVELS_ERROR) */
#endif /* !defined(DEFAULT_MAIN_DEBUG_LEVELS) */

#if !defined(DEFAULT_MAIN_DEBUG_LEVELS) 
#define DEFAULT_MAIN_DEBUG_LEVELS DEFAULT_DEBUG_LEVELS
#endif /* !defined(DEFAULT_MAIN_DEBUG_LEVELS) */

/**
 **********************************************************************
 * Function: main
 *
 *   Author: $author$
 *     Date: 2/15/2008
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

    SET_DEBUG_LEVELS(DEFAULT_MAIN_DEBUG_LEVELS);

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
