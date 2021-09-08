///////////////////////////////////////////////////////////////////////
//   File: evc.h
//
// Author: $author$
//   Date: 5/11/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVC_H
#define _EVC_H

#include "evd.h"

#define EVC_PRODUCT_LABEL EV_PRODUCT_LABEL " Client"

#define EVC_VERSION_MAJOR   3
#define EVC_VERSION_MINOR   0
#define EVC_VERSION_RELEASE 0

#define EVC_VERSION_MAJOR_STRING   EV_VERSION_STRING(EVC_VERSION_MAJOR)
#define EVC_VERSION_MINOR_STRING   EV_VERSION_STRING(EVC_VERSION_MINOR)
#define EVC_VERSION_RELEASE_STRING EV_VERSION_STRING(EVC_VERSION_RELEASE)

#define EVC_VERSION_LABEL \
EV_VERSION_LABEL EV_VERSION_LABEL_SEPARATOR  \
EVC_VERSION_MAJOR_STRING EV_VERSION_SEPARATOR \
EVC_VERSION_MINOR_STRING EV_VERSION_SEPARATOR \
EVC_VERSION_RELEASE_STRING

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif // _EVC_H
