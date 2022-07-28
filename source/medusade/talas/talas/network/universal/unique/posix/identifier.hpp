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
///   Date: 6/29/2022
///////////////////////////////////////////////////////////////////////
#ifndef TALAS_NETWORK_UNIVERSAL_UNIQUE_POSIX_IDENTIFIER_HPP
#define TALAS_NETWORK_UNIVERSAL_UNIQUE_POSIX_IDENTIFIER_HPP

#include "talas/network/universal/unique/identifier.hpp"
#include "talas/network/ethernet/os/address.hpp"
#include "talas/crypto/hash/implemented/implemented.hpp"
#include "talas/crypto/random/implemented/implemented.hpp"

namespace talas {
namespace network {
namespace universal {
namespace unique {
namespace posix {

///////////////////////////////////////////////////////////////////////
/// class identifiert
///////////////////////////////////////////////////////////////////////
template <class TExtends = unique::identifier, class TImplements = typename TExtends::implements>

class exported identifiert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef identifiert derives;

    typedef typename extends::actual_t actual_t;

    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    identifiert(const identifiert& copy): extends(copy) {
    }
    identifiert() {
    }
    virtual ~identifiert() {
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...generate...
    ///////////////////////////////////////////////////////////////////////
    virtual actual_t* generate_time_based(int ethernet_index) {
        network::ethernet::address& ethernet =  m_ethernet;
        crypto::random::generator& random = m_random;
        crypto::hash::md5& md5 = m_md5;
        actual_t& actual = this->actual();

        /// get current UUID time (64 bits)
        ///
        uint64_t uuidTime = time();

        /// Encode the time into the UUID struct (host order).
        ///
        actual.m_timeLow.m_l = (uint32_t)(uuidTime & NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_LOW_BM);
        actual.m_timeMid.m_w = (uint16_t)((uuidTime & NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_MID_BM) >> NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_MID_BS);
        actual.m_timeHiAndVersion.m_w = (uint16_t)((uuidTime & NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_HI_BM) >> NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_HI_BS);
        actual.m_timeHiAndVersion.m_w |= (uint16_t)(actual::identifier::VERSION_TIME_BASED << NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_HI_VERSION_BS);

        /// Convert time part to MSB (network order)
        ///
        this->time_to_msb(actual);

        ssize_t count = 0;
        size_t size = 0;

        /// get clock seqence from a crypto-quality
        /// random number generator.
        ///
        uint16_t uuidClockSeq = 0;
        size  = sizeof(uuidClockSeq);
        if (size != (count = random.generate(&uuidClockSeq, size))) {
            return 0;
        }

        /// Encode the sequence into the UUID struct (network order).
        ///
        actual.m_clockSeq.m_low = (uuidClockSeq & NETWORK_UNIQUE_ACTUAL_IDENTIFIER_CLOCK_SEQ_LOW_BM);
        actual.m_clockSeq.m_hiAndRes = ((uuidClockSeq & NETWORK_UNIQUE_ACTUAL_IDENTIFIER_CLOCK_SEQ_HI_BM) >> NETWORK_UNIQUE_ACTUAL_IDENTIFIER_CLOCK_SEQ_HI_BS);
        actual.m_clockSeq.m_hiAndRes |= (NETWORK_UNIQUE_ACTUAL_IDENTIFIER_RESERVED_VARIANT_RFC4122_BV << NETWORK_UNIQUE_ACTUAL_IDENTIFIER_CLOCK_SEQ_HI_RESERVED_BS);

        /// get node ID from the MAC address.
        ///
        const network::ethernet::actual::address* macAddress = 0;
        if ((macAddress = ethernet.set_to_adapter(ethernet_index))) {
            /// copy MAC address to node ID (network order).
            ///
            memcpy(actual.m_node.m_b, macAddress->m_b, sizeof(actual.m_node.m_b));
        } else {
            return 0;
        }

        /// Generate an MD5 hash of the MAC address to
        /// hide it's identity.
        ///
        uint8_t hash[16];
        if ((sizeof(hash)) == (count = md5(hash, sizeof(hash), actual.m_b, sizeof(actual.m_b)))) {
            memcpy(actual.m_node.m_b, hash, sizeof(actual.m_node.m_b));
        } else {
            return 0;
        }

        /// Set MAC address multicast bit per RFC4122
        ///
        actual.m_node.m_macAddress.m_oui.m_b[0] &= ~NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_MULTICAST;
        actual.m_node.m_macAddress.m_oui.m_b[0] |= NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_MULTICAST;
        this->set_string(actual);
        return &actual;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    /// ...time...
    ///////////////////////////////////////////////////////////////////////
    virtual uint64_t time() const {
        uint64_t now = 0;
        struct timeval tv;

        /// get current time
        ///
        gettimeofday(&tv, (struct timezone*)0);

        /// Offset between UUID formatted times and Unix formatted times.
        /// UUID UTC base time is October 15, 1582.
        /// Unix base time is January 1, 1970.
        ///
        now = (tv.tv_sec * 10000000) + (tv.tv_usec * 10) + 0x01B21DD213814000LL;
        return now;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    network::ethernet::os::address m_ethernet;
    crypto::random::implemented::generator m_random;
    crypto::hash::implemented::md5 m_md5;
    crypto::hash::implemented::sha1 m_sha1;
}; /// class identifiert
typedef identifiert<> identifier;

} /// namespace posix 
} /// namespace unique 
} /// namespace universal 
} /// namespace network 
} /// namespace talas 

#endif /// ndef TALAS_NETWORK_UNIVERSAL_UNIQUE_POSIX_IDENTIFIER_HPP 