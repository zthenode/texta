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
///   File: address.hpp
///
/// Author: $author$
///   Date: 6/28/2022
///////////////////////////////////////////////////////////////////////
#ifndef TALAS_NETWORK_ETHERNET_ACTUAL_ADDRESS_HPP
#define TALAS_NETWORK_ETHERNET_ACTUAL_ADDRESS_HPP

#include "xos/base/base.hpp"

/// address size
/// 
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_SIZE 6

/// OUI group/indiviual bit
/// 
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_GROUP 0x01
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_GROUP 0
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_GROUP 0

#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_INDIVIDUAL 0x00
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_GROUP      0x01

#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_INDIVIDUAL 0
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_GROUP      1

/// OUI local/global bit
/// 
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_LOCAL 0x02
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_LOCAL 1
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_LOCAL 0

#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_GLOBAL 0x00
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_LOCAL  0x02

#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_GLOBAL 0
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_LOCAL  1

/// OUI multicast/unicast bit
/// 
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_MULTICAST NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_GROUP
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_MULTICAST NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_GROUP
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_MULTICAST NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_GROUP

#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_UNICAST   NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_INDIVIDUAL
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_MULTICAST NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_GROUP

#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_UNICAST   NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_INDIVIDUAL
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_MULTICAST NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_GROUP

namespace talas {
namespace network {
namespace ethernet {
namespace actual {

#include "xos/platform/platform_packed_begin.h"
///////////////////////////////////////////////////////////////////////
/// struct address
///////////////////////////////////////////////////////////////////////
struct PLATFORM_PACKED address {
    typedef address derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    union PLATFORM_PACKED {
        uint8_t m_b[NETWORK_ETHERNET_ACTUAL_ADDRESS_SIZE];

        struct PLATFORM_PACKED {
            struct PLATFORM_PACKED {
                uint8_t m_b[NETWORK_ETHERNET_ACTUAL_ADDRESS_SIZE/2];
            } m_oui;

            struct PLATFORM_PACKED {
                uint8_t m_b[NETWORK_ETHERNET_ACTUAL_ADDRESS_SIZE/2];
            } m_nic;
        };
    }; /// union

    ///////////////////////////////////////////////////////////////////////
    /// struct oui
    ///////////////////////////////////////////////////////////////////////
    struct oui {
        ///////////////////////////////////////////////////////////////////////
        /// struct grouped
        ///////////////////////////////////////////////////////////////////////
        struct grouped {
            typedef int which;
            enum {
                individual = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_INDIVIDUAL,
                group = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_GROUP
            };
            enum {
                index = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_GROUP,
                mask = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_GROUP,
                shift = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_GROUP
            };
        }; /// struct grouped

        ///////////////////////////////////////////////////////////////////////
        /// struct located
        ///////////////////////////////////////////////////////////////////////
        struct located {
            typedef int which;
            enum {
                local = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_LOCAL,
                global = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_GLOBAL 
            };
            enum {
                index = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_LOCAL,
                mask = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_LOCAL,
                shift = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_LOCAL
            };
        }; /// struct located

        ///////////////////////////////////////////////////////////////////////
        /// struct casted
        ///////////////////////////////////////////////////////////////////////
        struct casted {
            typedef int which;
            enum {
                unicast = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_UNICAST,
                multicast = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_MULTICAST
            };
            enum {
                index = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_MULTICAST,
                mask = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_MULTICAST,
                shift = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_MULTICAST
            };
        }; /// struct casted
    }; /// struct oui

    ///////////////////////////////////////////////////////////////////////
    /// operator != , operator == , size
    ///////////////////////////////////////////////////////////////////////
    inline bool operator != (const derives& to) const {
        return (0 != (::memcmp(this, &to, sizeof(derives))));
    }
    inline bool operator == (const derives& to) const {
        return (0 == (::memcmp(this, &to, sizeof(derives))));
    }
    inline size_t size() const {
        return sizeof(derives);
    }
}; /// struct address
#include "xos/platform/platform_packed_end.h"

} /// namespace actual 
} /// namespace ethernet 
} /// namespace network 
} /// namespace talas 

#endif /// ndef TALAS_NETWORK_ETHERNET_ACTUAL_ADDRESS_HPP 