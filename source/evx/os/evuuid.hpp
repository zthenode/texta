///////////////////////////////////////////////////////////////////////
//   File: evuuid.hpp
//
// Author: $author$
//   Date: 1/22/2008
///////////////////////////////////////////////////////////////////////
#ifndef _EVUUID_HPP
#define _EVUUID_HPP

#include "evplatform.h"
#include "evmacaddress.hpp"
#include "evinstance.hpp"

#define EVUUID_TIME_LOW_BM 0x00000000FFFFFFFFLL
#define EVUUID_TIME_LOW_BS 0

#define EVUUID_TIME_MID_BM 0x0000FFFF00000000LL
#define EVUUID_TIME_MID_BS 32

#define EVUUID_TIME_HI_BM 0x0FFF000000000000LL
#define EVUUID_TIME_HI_BS 48

#define EVUUID_TIME_HI_VERSION_BM 0xF000
#define EVUUID_TIME_HI_VERSION_BS 12

#define EVUUID_VERSION_BM 0xF0
#define EVUUID_VERSION_BS 4

///////////////////////////////////////////////////////////////////////
//   Enum: 
//
// Author: $author$
//   Date: 1/29/2008
///////////////////////////////////////////////////////////////////////
enum
{
    EVUUID_VERSION_NONE            = 0x0,

    EVUUID_VERSION_TIME_BASED      = 0x1,
    EVUUID_VERSION_DCE_SECURITY    = 0x2,
    EVUUID_VERSION_NAME_BASED_MD5  = 0x3,
    EVUUID_VERSION_RANDOM          = 0x4,
    EVUUID_VERSION_NAME_BASED_SHA1 = 0x5,

    EVUUID_VERSION_NEXT,
    EVUUID_VERSION_FIRST = EVUUID_VERSION_NONE+1,
    EVUUID_VERSION_LAST = EVUUID_VERSION_NEXT-1,
    EVUUID_VERSION_COUNT = EVUUID_VERSION_LAST-EVUUID_VERSION_FIRST+1
};

#define EVUUID_VERSION_NAME_NONE            "NONE"
#define EVUUID_VERSION_NAME_TIME_BASED      "TIME_BASED"
#define EVUUID_VERSION_NAME_DCE_SECURITY    "DCE_SECURITY"
#define EVUUID_VERSION_NAME_NAME_BASED_MD5  "NAME_BASED_MD5"
#define EVUUID_VERSION_NAME_RANDOM          "RANDOM"
#define EVUUID_VERSION_NAME_NAME_BASED_SHA1 "NAME_BASED_SHA1"

#define EVUUID_CLOCK_SEQ_LOW_BM 0x00FF
#define EVUUID_CLOCK_SEQ_LOW_BS 0

#define EVUUID_CLOCK_SEQ_HI_BM 0x1F00
#define EVUUID_CLOCK_SEQ_HI_BS 8

#define EVUUID_CLOCK_SEQ_HI_RESERVED_BM 0xE0
#define EVUUID_CLOCK_SEQ_HI_RESERVED_BS 5

#define EVUUID_RESERVED_VARIANT_NCS_COMPATIBILITY_BM 0x4
#define EVUUID_RESERVED_VARIANT_NCS_COMPATIBILITY_BV 0x0

#define EVUUID_RESERVED_VARIANT_RFC4122_BM 0x6
#define EVUUID_RESERVED_VARIANT_RFC4122_BV 0x4

#define EVUUID_RESERVED_VARIANT_MICROSOFT_COMPATIBILITY_BM 0x7
#define EVUUID_RESERVED_VARIANT_MICROSOFT_COMPATIBILITY_BV 0x6

#define EVUUID_RESERVED_VARIANT_FUTURE_DEFINITION_BM 0x7
#define EVUUID_RESERVED_VARIANT_FUTURE_DEFINITION_BV 0x7

///////////////////////////////////////////////////////////////////////
//   Enum: 
//
// Author: $author$
//   Date: 1/29/2008
///////////////////////////////////////////////////////////////////////
enum
{
    EVUUID_RESERVED_VARIANT_FIRST,

    EVUUID_RESERVED_VARIANT_FUTURE_DEFINITION = EVUUID_RESERVED_VARIANT_FIRST,
    EVUUID_RESERVED_VARIANT_MICROSOFT_COMPATIBILITY,
    EVUUID_RESERVED_VARIANT_RFC4122,
    EVUUID_RESERVED_VARIANT_NCS_COMPATIBILITY,

    EVUUID_RESERVED_VARIANT_NEXT,
    EVUUID_RESERVED_VARIANT_LAST = EVUUID_RESERVED_VARIANT_NEXT-1,
    EVUUID_RESERVED_VARIANT_COUNT = EVUUID_RESERVED_VARIANT_LAST-EVUUID_RESERVED_VARIANT_FIRST+1
};

#define EVUUID_RESERVED_VARIANT_NAME_NONE                    "NONE"
#define EVUUID_RESERVED_VARIANT_NAME_FUTURE_DEFINITION       "FUTURE_DEFINITION"
#define EVUUID_RESERVED_VARIANT_NAME_MICROSOFT_COMPATIBILITY "MICROSOFT_COMPATIBILITY"
#define EVUUID_RESERVED_VARIANT_NAME_RFC4122                 "RFC4122"
#define EVUUID_RESERVED_VARIANT_NAME_NCS_COMPATIBILITY       "NCS_COMPATIBILITY"

///////////////////////////////////////////////////////////////////////
// Struct: SEvUUID
//
// Author: $author$
//   Date: 1/22/2008
//
// This stuct is defined in network (MSB) order.
///////////////////////////////////////////////////////////////////////
#if defined(WIN32)
#pragma pack(push,1)
#define PACKED
#else // defined(WIN32) 
#define PACKED __attribute__ ((packed))
#endif // defined(WIN32) 
struct PACKED SEvUUID
{
    union {
        BYTE m_b[16];
        UINT16 m_w[8];
        UINT32 m_l[4];
        struct PACKED {
            union {
                BYTE m_b[4];
                UINT16 m_w[2];
                UINT32 m_l;
            } m_timeLow;

            union {
                BYTE m_b[2];
                UINT16 m_w;
            } m_timeMid;

            union {
                BYTE m_b[2];
                UINT16 m_w;
                struct PACKED {
                    UINT8 m_version;
                    UINT8 m_hi;
                };
            } m_timeHiAndVersion;

            union {
                BYTE m_b[2];
                UINT16 m_w;
                struct PACKED {
                    UINT8 m_hiAndRes;
                    UINT8 m_low;
                };
            } m_clockSeq;

            union {
                BYTE m_b[6];
                UINT16 m_w[3];
                struct PACKED {
                    union {
                        BYTE m_b[2];
                        UINT16 m_w;
                    } m_nodeHi;

                    union {
                        BYTE m_b[4];
                        UINT16 m_w[2];
                        UINT32 m_l;
                    } m_nodeLow;
                };
                SEvMACAddress m_macAddress;
            } m_node;
        };
    };
}
#if defined(WIN32)
#pragma pack(pop)
#else // defined(WIN32) 
#undef PACKED
#endif // defined(WIN32) 
;

///////////////////////////////////////////////////////////////////////
//  Class: EvUUID
//
// Author: $author$
//   Date: 3/12/2008
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvUUID
: virtual public EvInstance
{
public:
    typedef EvInstance CImplements;
    typedef EvUUID CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: Generate
    //
    //   Author: $author$
    //     Date: 3/12/2008
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Generate() = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: Compare
    //
    //   Author: $author$
    //     Date: 3/12/2008
    ///////////////////////////////////////////////////////////////////////
    virtual int Compare(const EvUUID& to) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetUUID
    //
    //   Author: $author$
    //     Date: 3/12/2008
    ///////////////////////////////////////////////////////////////////////
    virtual const SEvUUID& GetUUID() const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: CreateInstance
    //
    //   Author: $author$
    //     Date: 3/12/2008
    ///////////////////////////////////////////////////////////////////////
    static EvUUID* CreateInstance(EvError& error);
    ///////////////////////////////////////////////////////////////////////
    // Function: DestroyInstance
    //
    //   Author: $author$
    //     Date: 3/12/2008
    ///////////////////////////////////////////////////////////////////////
    static EvError DestroyInstance(EvUUID& instance);
};

extern const char* evuuid_versionName[EVUUID_VERSION_COUNT];
extern int evuuid_versionValue[EVUUID_VERSION_COUNT];

extern const char* evuuid_reservedVariantName[EVUUID_RESERVED_VARIANT_COUNT];
extern int evuuid_reservedVariantMask[EVUUID_RESERVED_VARIANT_COUNT];
extern int evuuid_reservedVariantValue[EVUUID_RESERVED_VARIANT_COUNT];

#endif // _EVUUID_HPP
