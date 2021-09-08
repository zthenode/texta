///////////////////////////////////////////////////////////////////////
//   File: evuuid.cpp
//
// Author: $author$
//   Date: 1/22/2008
///////////////////////////////////////////////////////////////////////

#include "evuuid.hpp"

///////////////////////////////////////////////////////////////////////
// Struct: SEvUUID
//
// Author: $author$
//   Date: 1/22/2008
///////////////////////////////////////////////////////////////////////

const char* evuuid_versionName[EVUUID_VERSION_COUNT] = 
{
    EVUUID_VERSION_NAME_TIME_BASED,
    EVUUID_VERSION_NAME_DCE_SECURITY,
    EVUUID_VERSION_NAME_NAME_BASED_MD5,
    EVUUID_VERSION_NAME_RANDOM,
    EVUUID_VERSION_NAME_NAME_BASED_SHA1
};
int evuuid_versionValue[EVUUID_VERSION_COUNT] = 
{
    EVUUID_VERSION_TIME_BASED,
    EVUUID_VERSION_DCE_SECURITY,
    EVUUID_VERSION_NAME_BASED_MD5,
    EVUUID_VERSION_RANDOM,
    EVUUID_VERSION_NAME_BASED_SHA1
};

const char* evuuid_reservedVariantName[EVUUID_RESERVED_VARIANT_COUNT] = 
{
    EVUUID_RESERVED_VARIANT_NAME_FUTURE_DEFINITION,
    EVUUID_RESERVED_VARIANT_NAME_MICROSOFT_COMPATIBILITY,
    EVUUID_RESERVED_VARIANT_NAME_RFC4122,
    EVUUID_RESERVED_VARIANT_NAME_NCS_COMPATIBILITY
};
int evuuid_reservedVariantMask[EVUUID_RESERVED_VARIANT_COUNT] = 
{
    EVUUID_RESERVED_VARIANT_FUTURE_DEFINITION_BM,
    EVUUID_RESERVED_VARIANT_MICROSOFT_COMPATIBILITY_BM,
    EVUUID_RESERVED_VARIANT_RFC4122_BM,
    EVUUID_RESERVED_VARIANT_NCS_COMPATIBILITY_BM
};
int evuuid_reservedVariantValue[EVUUID_RESERVED_VARIANT_COUNT] = 
{
    EVUUID_RESERVED_VARIANT_FUTURE_DEFINITION_BV,
    EVUUID_RESERVED_VARIANT_MICROSOFT_COMPATIBILITY_BV,
    EVUUID_RESERVED_VARIANT_RFC4122_BV,
    EVUUID_RESERVED_VARIANT_NCS_COMPATIBILITY_BV
};
