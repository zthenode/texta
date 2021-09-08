///////////////////////////////////////////////////////////////////////
//   File: evmacaddress.hpp
//
// Author: $author$
//   Date: 1/24/2008
///////////////////////////////////////////////////////////////////////
#ifndef _EVMACADDRESS_HPP
#define _EVMACADDRESS_HPP

#include "evplatform.h"

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
// Struct: SEvMACAddress
//
// Author: $author$
//   Date: 1/24/2008
///////////////////////////////////////////////////////////////////////
#if defined(WIN32)
#pragma pack(push,1)
#define PACKED
#else // defined(WIN32) 
#define PACKED __attribute__ ((packed))
#endif // defined(WIN32) 
struct PACKED SEvMACAddress
{
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
#if defined(WIN32)
#pragma pack(pop)
#else // defined(WIN32) 
#undef PACKED
#endif // defined(WIN32) 
;

#endif // _EVMACADDRESS_HPP 
