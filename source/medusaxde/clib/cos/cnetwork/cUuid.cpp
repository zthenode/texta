///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2013 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cUuid.cpp
//
// Author: $author$
//   Date: 8/20/2013
///////////////////////////////////////////////////////////////////////
#include "cUuid.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

const char* evuuid_versionName[CUUID_VERSION_COUNT] = 
{
    CUUID_VERSION_NAME_TIME_BASED,
    CUUID_VERSION_NAME_DCE_SECURITY,
    CUUID_VERSION_NAME_NAME_BASED_MD5,
    CUUID_VERSION_NAME_RANDOM,
    CUUID_VERSION_NAME_NAME_BASED_SHA1
};
int evuuid_versionValue[CUUID_VERSION_COUNT] = 
{
    CUUID_VERSION_TIME_BASED,
    CUUID_VERSION_DCE_SECURITY,
    CUUID_VERSION_NAME_BASED_MD5,
    CUUID_VERSION_RANDOM,
    CUUID_VERSION_NAME_BASED_SHA1
};

const char* evuuid_reservedVariantName[CUUID_RESERVED_VARIANT_COUNT] = 
{
    CUUID_RESERVED_VARIANT_NAME_FUTURE_DEFINITION,
    CUUID_RESERVED_VARIANT_NAME_MICROSOFT_COMPATIBILITY,
    CUUID_RESERVED_VARIANT_NAME_RFC4122,
    CUUID_RESERVED_VARIANT_NAME_NCS_COMPATIBILITY
};
int evuuid_reservedVariantMask[CUUID_RESERVED_VARIANT_COUNT] = 
{
    CUUID_RESERVED_VARIANT_FUTURE_DEFINITION_BM,
    CUUID_RESERVED_VARIANT_MICROSOFT_COMPATIBILITY_BM,
    CUUID_RESERVED_VARIANT_RFC4122_BM,
    CUUID_RESERVED_VARIANT_NCS_COMPATIBILITY_BM
};
int evuuid_reservedVariantValue[CUUID_RESERVED_VARIANT_COUNT] = 
{
    CUUID_RESERVED_VARIANT_FUTURE_DEFINITION_BV,
    CUUID_RESERVED_VARIANT_MICROSOFT_COMPATIBILITY_BV,
    CUUID_RESERVED_VARIANT_RFC4122_BV,
    CUUID_RESERVED_VARIANT_NCS_COMPATIBILITY_BV
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 
