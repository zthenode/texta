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
///   Date: 6/29/2022
///////////////////////////////////////////////////////////////////////
#ifndef TALAS_NETWORK_ETHERNET_BSD_ADDRESS_HPP
#define TALAS_NETWORK_ETHERNET_BSD_ADDRESS_HPP

#include "talas/network/ethernet/address.hpp"
#include "talas/base/logger.hpp"
#include "xos/base/logged.hpp"

#if !defined(BSD)
#if defined(APPLE)
#define BSD
#endif /// defined(APPLE)
#endif /// !defined(BSD)

#if defined(BSD)
#include <sys/socket.h>
#include <net/if.h>
#include <net/if_dl.h>
#include <net/if_types.h>
#include <ifaddrs.h>
#else /// defined(BSD)
#error only supported on BSD operating systems
#endif /// defined(BSD)

namespace talas {
namespace network {
namespace ethernet {
namespace bsd {

/// class addresst
template 
<class TExtends = ethernet::address, class TImplements = typename TExtends::implements>

class exported addresst: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef addresst derives;

    typedef typename extends::actual_t actual_t;
    typedef typename extends::string_t string_t;

    /// constructor / destructor
    addresst(const string_t& adapter_named) {
        if (!(this->set_to_adapter(adapter_named))) {
            throw exception(exception_failed);
        }
    }
    addresst(const addresst& copy): extends(copy) {
    }
    addresst() {
    }
    virtual ~addresst() {
    }

    /// set_to_adapter
    using extends::set_to_adapter;
    virtual actual_t* set_to_adapter(const string_t& named) {
        const char* chars = 0;
        size_t length = 0;

        if ((chars = named.chars(length)) && (0 < (length))) {
            struct ifaddrs* ifa = 0;
            const actual_t* actual = 0;
            string_t adapter_name;

            this->clear();

            if ((actual = this->get_first(adapter_name, ifa))) {
                struct sockaddr_dl* dl = 0;
                int unequal = 0;

                do {
                    if ((dl = (struct sockaddr_dl*)(ifa->ifa_addr))) {
                        if (!(unequal = adapter_name.compare(named))) {
                            this->set(*actual, adapter_name, dl->sdl_index);
                            return &this->actual();
                        }
                    }
                } while ((actual = this->get_next(adapter_name, ifa)));
            }
        } else {
            return this->set_to_first_adapter();
        }
        return 0;
    }
    virtual actual_t* set_to_adapter(int index) {
        struct ifaddrs* ifa = 0;
        const actual_t* actual = 0;
        int eindex = 0;
        string_t adapter_name;

        this->clear();

        if ((actual = this->get_first(adapter_name, ifa))) {
            struct sockaddr_dl* dl = 0;

            do {
                if ((dl = (struct sockaddr_dl*)(ifa->ifa_addr))) {
                    if ((1 > index) || (eindex == index)) {
                        this->set(*actual, adapter_name, dl->sdl_index);
                        return &this->actual();
                    }
                    ++eindex;
                }
            } while ((actual = this->get_next(adapter_name, ifa)));

            if ((dl)) {
                if ((0 > index)) {
                    this->set(*actual, adapter_name, dl->sdl_index);
                    return &this->actual();
                }
            }
        }
        return 0;
    }

    /// ...get...
    virtual const actual_t* get_first(string_t& adapter_name) const {
        return this->get_next(adapter_name, 0);
    }
    virtual const actual_t* get_next(string_t& adapter_name, const actual_t* to) const {
        struct ifaddrs* ifa = 0;
        const actual_t* actual = 0;
        if ((actual = this->get_first(adapter_name, ifa))) {
            if ((to)) {
                do {
                    if ((*to) == (*actual)) {
                        if ((actual = this->get_next(adapter_name, ifa))) {
                            break;
                        }
                    }
                } while ((actual = this->get_next(adapter_name, ifa)));
            }
        }
        return actual;
    }

protected:
    /// ...get...
    virtual const actual_t* get_first(string_t& adapter_name, struct ifaddrs*& ifa) const {
        int err = 0;

        LOGGER_IS_LOGGED_DEBUG("::getifaddrs(&ifa)...");
        if (!(err = ::getifaddrs(&ifa)) && (ifa)) {
            LOGGER_IS_LOGGED_DEBUG("...::getifaddrs(&ifa)");
            const actual_t* actual = 0;

            do {
                if ((actual = this->get(adapter_name, ifa))) {
                    return actual;
                }
            } while ((ifa = ifa->ifa_next));
        } else {
            LOGGER_IS_LOGGED_ERROR("...failed " << err << " = on ::getifaddrs(&ifa)");
        }
        return 0;
    }
    virtual const actual_t* get_next(string_t& adapter_name, struct ifaddrs*& ifa) const {
        if ((ifa)) {
            const actual_t* actual = 0;

            while ((ifa = ifa->ifa_next)) {
                if ((actual = this->get(adapter_name, ifa))) {
                    return actual;
                }
            }
        }
        return 0;
    }
    virtual const actual_t* get(string_t& adapter_name, struct ifaddrs*& ifa) const {
        if ((ifa)) {
            struct sockaddr* sa = 0;
            struct sockaddr_dl* dl = 0;
            const actual_t* actual = 0;
            const char* chars = 0;
            size_t length = 0;

            if ((sa = (ifa->ifa_addr))) {
                sa_family_t sa_family = 0;

                if ((AF_LINK == (sa_family = sa->sa_family))) {
                    if ((dl = (struct sockaddr_dl*)(ifa->ifa_addr))) {
                        u_char sdl_type = 0;
                        
                        if ((IFT_ETHER == (sdl_type = dl->sdl_type))) {
                             if ((sizeof(actual_t) == (dl->sdl_alen))
                                 && (actual = (const actual_t*)(LLADDR(dl)))
                                 && (chars = (const char*)(dl->sdl_data))
                                 && (0 < (length = (size_t)(dl->sdl_nlen)))) {
                                adapter_name.assign(chars, length);
                                return actual;
                            }
                        } else {
                            LOGGER_IS_LOGGED_DEBUG("...(IFT_ETHER != (" << sdl_type << " = dl->sdl_type))");
                        }
                    }
                } else {
                    LOGGER_IS_LOGGED_DEBUG("...(AF_LINK != (" << sa_family << " = sa->sa_family))");
                }
            }
        }
        return 0;
    }
}; /// class addresst
typedef addresst<> address;

} /// namespace bsd 
} /// namespace ethernet 
} /// namespace network 
} /// namespace talas 

#endif /// ndef TALAS_NETWORK_ETHERNET_BSD_ADDRESS_HPP 