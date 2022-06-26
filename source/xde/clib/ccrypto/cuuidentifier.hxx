///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: cuuidentifier.hxx
///
/// Author: $author$
///   Date: 10/7/2021
///////////////////////////////////////////////////////////////////////
#ifndef _CUUIDENTIFIER_HXX
#define _CUUIDENTIFIER_HXX

#include "ccryptobase.hxx"
#if defined(WINDOWS)
#endif /// defined(WINDOWS)

#define EV_MAC_ADDRESS_SIZE 6

// OUI group/indiviual bit
//
#define EV_MAC_ADDRESS_OUI_BM_GROUP 0x01
#define EV_MAC_ADDRESS_OUI_BS_GROUP 0

#define EV_MAC_ADDRESS_OUI_BV_INDIVIDUAL 0x00
#define EV_MAC_ADDRESS_OUI_BV_GROUP      0x01

#define EV_MAC_ADDRESS_OUI_INDIVIDUAL 0
#define EV_MAC_ADDRESS_OUI_GROUP      1

// OUI local/global bit
//
#define EV_MAC_ADDRESS_OUI_BM_LOCAL 0x02
#define EV_MAC_ADDRESS_OUI_BS_LOCAL 1

#define EV_MAC_ADDRESS_OUI_BV_GLOBAL 0x00
#define EV_MAC_ADDRESS_OUI_BV_LOCAL  0x02

#define EV_MAC_ADDRESS_OUI_GLOBAL 0
#define EV_MAC_ADDRESS_OUI_LOCAL  1

// OUI multicast/unicast bit
//
#define EV_MAC_ADDRESS_OUI_BM_MULTICAST EV_MAC_ADDRESS_OUI_BM_GROUP
#define EV_MAC_ADDRESS_OUI_BS_MULTICAST EV_MAC_ADDRESS_OUI_BS_GROUP

#define EV_MAC_ADDRESS_OUI_BV_UNICAST   EV_MAC_ADDRESS_OUI_BV_INDIVIDUAL
#define EV_MAC_ADDRESS_OUI_BV_MULTICAST EV_MAC_ADDRESS_OUI_BV_GROUP

#define EV_MAC_ADDRESS_OUI_UNICAST   EV_MAC_ADDRESS_OUI_INDIVIDUAL
#define EV_MAC_ADDRESS_OUI_MULTICAST EV_MAC_ADDRESS_OUI_GROUP

///////////////////////////////////////////////////////////////////////
/// struct SEvMACAddress
///////////////////////////////////////////////////////////////////////
#if defined(WINDOWS)
#pragma pack(push,1)
#define PACKED
#else /// defined(WINDOWS) 
#define PACKED __attribute__ ((packed))
#endif /// defined(WINDOWS) 
struct PACKED SEvMACAddress {
    union {
        BYTE m_b[EV_MAC_ADDRESS_SIZE];

        struct PACKED {
            struct PACKED {
                BYTE m_b[EV_MAC_ADDRESS_SIZE/2];
            } m_oui;

            struct PACKED {
                BYTE m_b[EV_MAC_ADDRESS_SIZE/2];
            } m_nic;
        };
    };
}
#if defined(WINDOWS)
#pragma pack(pop)
#else /// defined(WINDOWS) 
#undef PACKED
#endif /// defined(WINDOWS) 
;

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

enum {
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

enum {
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
/// struct SEvUUID
///////////////////////////////////////////////////////////////////////
#if defined(WINDOWS)
#pragma pack(push,1)
#define PACKED
#else /// defined(WINDOWS) 
#define PACKED __attribute__ ((packed))
#endif /// defined(WINDOWS) 
struct PACKED SEvUUID {
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
#if defined(WINDOWS)
#pragma pack(pop)
#else /// defined(WINDOWS) 
#undef PACKED
#endif /// defined(WINDOWS) 
;

typedef cCryptoBase cUUIdentifierExtends;
///////////////////////////////////////////////////////////////////////
/// class cUUIdentifier
///////////////////////////////////////////////////////////////////////
class PLATFORM_EXPORT cUUIdentifier: public cUUIdentifierExtends {
public:
    typedef cUUIdentifierExtends Extends;
    typedef cUUIdentifier Derives; 
    
    SEvUUID m_uuid;

#if defined(WINDOWS)
#endif /// defined(WINDOWS)
    ///////////////////////////////////////////////////////////////////////
    /// constructors / destructor
    ///////////////////////////////////////////////////////////////////////
    cUUIdentifier(const cUUIdentifier& copy): Extends(copy) {
    }
    cUUIdentifier() {
    }
    virtual ~cUUIdentifier() {
    }

    virtual BOOL Generate(cString& id) {
#if defined(WINDOWS)
        RPC_STATUS status = -1;

        if (RPC_S_OK == (status = UuidCreate((UUID*)(m_uuid.m_b)))) {
            RPC_WSTR uuidTString;
            cTString uuidString;

            if (RPC_S_OK == (status = UuidToString((UUID*)(m_uuid.m_b), &uuidTString))) {
                const TCHAR* chars = 0;
                LONG length = 0;
                BOOL success = FALSE;

                uuidString.Assign((const TCHAR*)(uuidTString));
                if ((success = (0 != (chars = uuidString.HasChars(length))))) {
                    id.Clear();
                    do {
                        char c = toupper(((char)(*(chars++))));
                        id.Append(&c, 1);
                    } while(0 < (--length));
                } else {
                }
                RpcStringFree(&uuidTString);
                return success;
            } else {
            }
        } else {
        }
#endif /// defined(WINDOWS)
        return FALSE;
    }
}; /// class cUUIdentifier

#endif /// _CUUIDENTIFIER_HXX
