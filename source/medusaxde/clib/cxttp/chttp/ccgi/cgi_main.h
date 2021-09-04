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
 *   File: cgi_main.h
 *
 * Author: $author$
 *   Date: 9/15/2011
 **********************************************************************
 */
#ifndef _CGI_MAIN_H
#define _CGI_MAIN_H

#include "cplatform.h"

#if !defined(CGI_MAIN_EXPORT) 
#define CGI_MAIN_EXPORT PLATFORM_IMPORT
#else /* !defined(CGI_MAIN_EXPORT) */
#endif /* !defined(CGI_MAIN_EXPORT) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

/**
 **********************************************************************
 * Function: cgi_main
 *
 *   Author: $author$
 *     Date: 9/15/2011
 **********************************************************************
 */
CGI_MAIN_EXPORT int cgi_main
(int argc, char** argv, char** env);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CGI_MAIN_H */
        

