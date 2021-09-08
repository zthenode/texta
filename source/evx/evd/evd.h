///////////////////////////////////////////////////////////////////////
//   File: evd.h
//
// Author: $author$
//   Date: 5/11/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVD_H
#define _EVD_H

#include "ev.h"

#define DEFAULT_EVD_SERVLET_DLL_FILENAME "libevdservlet." DLL_FILE_EXTENSION_CHARS
#define DEFAULT_EVD_TCP_HOST "localhost"
#define DEFAULT_EVD_TCP_PORT 8008
#define DEFAULT_EVD_TCP_THREADS 1

#define EVD_PRODUCT_LABEL EV_PRODUCT_LABEL " Server"

#define EVD_VERSION_MAJOR   3
#define EVD_VERSION_MINOR   0
#define EVD_VERSION_RELEASE 0

#define EVD_VERSION_MAJOR_STRING   EV_VERSION_STRING(EVD_VERSION_MAJOR)
#define EVD_VERSION_MINOR_STRING   EV_VERSION_STRING(EVD_VERSION_MINOR)
#define EVD_VERSION_RELEASE_STRING EV_VERSION_STRING(EVD_VERSION_RELEASE)

#define EVD_VERSION_LABEL \
EV_VERSION_LABEL EV_VERSION_LABEL_SEPARATOR  \
EVD_VERSION_MAJOR_STRING EV_VERSION_SEPARATOR \
EVD_VERSION_MINOR_STRING EV_VERSION_SEPARATOR \
EVD_VERSION_RELEASE_STRING

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 7/27/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    EVD_PROPERTY_ID_EVD_DIR,
    EVD_PROPERTY_ID_EVCS_DIR,
    EVD_PROPERTY_ID_EVCS_CI_DIR,
    EVD_PROPERTY_ID_EVCS_CO_DIR,
    EVD_PROPERTY_ID_EVCS_VC_DIR
};

#define EVD_PROPERTY_ID_NAME_EVD_DIR "evd-dir"
#define EVD_PROPERTY_ID_NAME_EVCS_DIR "evcs-dir"
#define EVD_PROPERTY_ID_NAME_EVCS_CI_DIR "evcs-ci-dir"
#define EVD_PROPERTY_ID_NAME_EVCS_CO_DIR "evcs-co-dir"
#define EVD_PROPERTY_ID_NAME_EVCS_VC_DIR "evcs-vc-dir"

#define DEFAULT_EVD_DIR "EVD"
#define DEFAULT_EVD_EVCS_DIR "EVCS"
#define DEFAULT_EVD_EVCS_CI_DIR "CI"
#define DEFAULT_EVD_EVCS_CO_DIR "CO"
#define DEFAULT_EVD_EVCS_VC_DIR "VC"

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif // _EVD_H
