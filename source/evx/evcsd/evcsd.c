///////////////////////////////////////////////////////////////////////
//   File: evcsd.c
//
// Author: $author$
//   Date: 7/31/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "evcsd.h"

int g_evcsd_property_id[EVCSD_PROPERTY_IDS] = 
{
    EVCSD_PROPERTY_ID_CI_DIRECTORY,
    EVCSD_PROPERTY_ID_CO_DIRECTORY
};
const char* g_evcsd_property_name[EVCSD_PROPERTY_IDS] = 
{
    EVCSD_PROPERTY_NAME_CI_DIRECTORY,
    EVCSD_PROPERTY_NAME_CO_DIRECTORY
};
