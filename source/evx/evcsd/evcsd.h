///////////////////////////////////////////////////////////////////////
//   File: evcsd.h
//
// Author: $author$
//   Date: 7/31/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVCSD_H
#define _EVCSD_H

///////////////////////////////////////////////////////////////////////
//   Enum:  
//
// Author: $author$
//   Date: 7/31/2007
///////////////////////////////////////////////////////////////////////
enum 
{
    EVCSD_PROPERTY_ID_CI_DIRECTORY,
    EVCSD_PROPERTY_ID_CO_DIRECTORY,

    EVCSD_PROPERTY_IDS,
};

#define EVCSD_PROPERTY_NAME_CI_DIRECTORY "ci-directory"
#define EVCSD_PROPERTY_NAME_CO_DIRECTORY "co-directory"

#if defined(__cplusplus)
extern "C" {
#endif

extern int g_evcsd_property_id[EVCSD_PROPERTY_IDS];
extern char* g_evcsd_property_name[EVCSD_PROPERTY_IDS];

#if defined(__cplusplus)
}
#endif

#endif // _EVCSD_H
