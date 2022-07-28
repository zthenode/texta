///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
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
///   File: identifier.hpp
///
/// Author: $author$
///   Date: 6/28/2022
///////////////////////////////////////////////////////////////////////
#ifndef TALAS_NETWORK_UNIVERSAL_UNIQUE_ACTUAL_IDENTIFIER_HPP
#define TALAS_NETWORK_UNIVERSAL_UNIQUE_ACTUAL_IDENTIFIER_HPP

#include "talas/network/ethernet/actual/address.hpp"

/// ...TIME...
/// 
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_LOW_BM 0x00000000FFFFFFFFLL
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_LOW_BS 0

#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_MID_BM 0x0000FFFF00000000LL
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_MID_BS 32

#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_HI_BM 0x0FFF000000000000LL
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_HI_BS 48

#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_HI_VERSION_BM 0xF000
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_HI_VERSION_BS 12

/// ...VERSION...
/// 
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_VERSION_BM 0xF0
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_VERSION_BS 4

/// ...CLOCK...
/// 
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_CLOCK_SEQ_LOW_BM 0x00FF
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_CLOCK_SEQ_LOW_BS 0

#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_CLOCK_SEQ_HI_BM 0x1F00
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_CLOCK_SEQ_HI_BS 8

#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_CLOCK_SEQ_HI_RESERVED_BM 0xE0
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_CLOCK_SEQ_HI_RESERVED_BS 5

/// ...RESERVED...
/// 
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_RESERVED_VARIANT_NCS_COMPATIBILITY_BM 0x4
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_RESERVED_VARIANT_NCS_COMPATIBILITY_BV 0x0

#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_RESERVED_VARIANT_RFC4122_BM 0x6
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_RESERVED_VARIANT_RFC4122_BV 0x4

#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_RESERVED_VARIANT_MICROSOFT_COMPATIBILITY_BM 0x7
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_RESERVED_VARIANT_MICROSOFT_COMPATIBILITY_BV 0x6

#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_RESERVED_VARIANT_FUTURE_DEFINITION_BM 0x7
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_RESERVED_VARIANT_FUTURE_DEFINITION_BV 0x7

namespace talas {
namespace network {
namespace universal {
namespace unique {
namespace actual {

#include "xos/platform/platform_packed_begin.h"
///////////////////////////////////////////////////////////////////////
/// struct identifier
///////////////////////////////////////////////////////////////////////
struct PLATFORM_PACKED identifier {

    /// mac_address_t
    typedef network::ethernet::actual::address mac_address_t;

    ///////////////////////////////////////////////////////////////////////
    /// enum version_t
    ///////////////////////////////////////////////////////////////////////
    typedef int version_t;
    enum {
        VERSION_NONE            = 0x0,

        VERSION_TIME_BASED      = 0x1,
        VERSION_DCE_SECURITY    = 0x2,
        VERSION_NAME_BASED_MD5  = 0x3,
        VERSION_RANDOM          = 0x4,
        VERSION_NAME_BASED_SHA1 = 0x5,

        VERSION_NEXT,
        VERSION_FIRST = VERSION_NONE+1,
        VERSION_LAST = VERSION_NEXT-1,
        VERSION_COUNT = VERSION_LAST-VERSION_FIRST+1
    }; /// enum version_t

    ///////////////////////////////////////////////////////////////////////
    /// enum variant_t
    ///////////////////////////////////////////////////////////////////////
    typedef int variant_t;
    enum {
        RESERVED_VARIANT_FIRST,

        RESERVED_VARIANT_FUTURE_DEFINITION = RESERVED_VARIANT_FIRST,
        RESERVED_VARIANT_MICROSOFT_COMPATIBILITY,
        RESERVED_VARIANT_RFC4122,
        RESERVED_VARIANT_NCS_COMPATIBILITY,

        RESERVED_VARIANT_NEXT,
        RESERVED_VARIANT_LAST = RESERVED_VARIANT_NEXT-1,
        RESERVED_VARIANT_COUNT = RESERVED_VARIANT_LAST-RESERVED_VARIANT_FIRST+1
    }; /// enum variant_t

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    union {
        uint8_t m_b[16];
        uint16_t m_w[8];
        uint32_t m_l[4];

        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        struct PLATFORM_PACKED {
            ///////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////
            union {
                uint8_t m_b[4];
                uint16_t m_w[2];
                uint32_t m_l;
            } m_timeLow; /// union

            ///////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////
            union {
                uint8_t m_b[2];
                uint16_t m_w;
            } m_timeMid; /// union

            ///////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////
            union {
                uint8_t m_b[2];
                uint16_t m_w;

                ///////////////////////////////////////////////////////////////////////
                ///////////////////////////////////////////////////////////////////////
                struct PLATFORM_PACKED {
                    uint8_t m_version;
                    uint8_t m_hi;
                };
            } m_timeHiAndVersion; /// union

            ///////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////
            union {
                uint8_t m_b[2];
                uint16_t m_w;

                ///////////////////////////////////////////////////////////////////////
                ///////////////////////////////////////////////////////////////////////
                struct PLATFORM_PACKED {
                    uint8_t m_hiAndRes;
                    uint8_t m_low;
                }; /// struct
            } m_clockSeq; /// union

            ///////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////
            union {
                uint8_t m_b[6];
                uint16_t m_w[3];

                ///////////////////////////////////////////////////////////////////////
                ///////////////////////////////////////////////////////////////////////
                struct PLATFORM_PACKED {
                    ///////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////
                    union {
                        uint8_t m_b[2];
                        uint16_t m_w;
                    } m_nodeHi; /// union

                    ///////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////
                    union {
                        uint8_t m_b[4];
                        uint16_t m_w[2];
                        uint32_t m_l;
                    } m_nodeLow; /// union
                }; /// struct

                mac_address_t m_macAddress;
            } m_node;
        }; /// struct
    }; /// union
}; /// struct identifier
#include "xos/platform/platform_packed_end.h"

} /// namespace actual 
} /// namespace unique 
} /// namespace universal 
} /// namespace network 
} /// namespace talas 

#endif /// ndef TALAS_NETWORK_UNIVERSAL_UNIQUE_ACTUAL_IDENTIFIER_HPP 