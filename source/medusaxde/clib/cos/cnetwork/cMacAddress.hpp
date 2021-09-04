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
//   File: cMacAddress.hpp
//
// Author: $author$
//   Date: 8/20/2013
///////////////////////////////////////////////////////////////////////
#ifndef _CMACADDRESS_HPP
#define _CMACADDRESS_HPP

#include "cBases.hpp"

#define c_MAC_ADDRESS_SIZE 6

// OUI group/indiviual bit
//
#define c_MAC_ADDRESS_OUI_BM_GROUP 0x01
#define c_MAC_ADDRESS_OUI_BS_GROUP 0

#define c_MAC_ADDRESS_OUI_BV_INDIVIDUAL 0x00
#define c_MAC_ADDRESS_OUI_BV_GROUP      0x01

#define c_MAC_ADDRESS_OUI_INDIVIDUAL 0
#define c_MAC_ADDRESS_OUI_GROUP      1

// OUI local/global bit
//
#define c_MAC_ADDRESS_OUI_BM_LOCAL 0x02
#define c_MAC_ADDRESS_OUI_BS_LOCAL 1

#define c_MAC_ADDRESS_OUI_BV_GLOBAL 0x00
#define c_MAC_ADDRESS_OUI_BV_LOCAL  0x02

#define c_MAC_ADDRESS_OUI_GLOBAL 0
#define c_MAC_ADDRESS_OUI_LOCAL  1

// OUI multicast/unicast bit
//
#define c_MAC_ADDRESS_OUI_BM_MULTICAST c_MAC_ADDRESS_OUI_BM_GROUP
#define c_MAC_ADDRESS_OUI_BS_MULTICAST c_MAC_ADDRESS_OUI_BS_GROUP

#define c_MAC_ADDRESS_OUI_BV_UNICAST   c_MAC_ADDRESS_OUI_BV_INDIVIDUAL
#define c_MAC_ADDRESS_OUI_BV_MULTICAST c_MAC_ADDRESS_OUI_BV_GROUP

#define c_MAC_ADDRESS_OUI_UNICAST   c_MAC_ADDRESS_OUI_INDIVIDUAL
#define c_MAC_ADDRESS_OUI_MULTICAST c_MAC_ADDRESS_OUI_GROUP

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Struct: sMacAddress
//
// Author: $author$
//   Date: 8/20/2013
///////////////////////////////////////////////////////////////////////
#if defined(__MSC__)
// Visual C++
#pragma pack(push,1)
#define PACKED
#else // defined(__MSC__) 
// Gnu C++
#define PACKED __attribute__ ((packed))
#endif // defined(__MSC__) 
struct PACKED sMacAddress
{
    union {
        BYTE m_b[c_MAC_ADDRESS_SIZE];

        struct PACKED {
            struct PACKED {
                BYTE m_b[c_MAC_ADDRESS_SIZE/2];
            } m_oui;

            struct PACKED {
                BYTE m_b[c_MAC_ADDRESS_SIZE/2];
            } m_nic;
        };
    };
}
#if defined(__MSC__)
// Visual C++
#pragma pack(pop)
#else // defined(__MSC__) 
// Gnu C++
#undef PACKED
#endif // defined(__MSC__) 
;

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CMACADDRESS_HPP 
        

