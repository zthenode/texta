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
#ifndef TALAS_NETWORK_ETHERNET_SYSTEMV_ADDRESS_HPP
#define TALAS_NETWORK_ETHERNET_SYSTEMV_ADDRESS_HPP

#include "talas/network/ethernet/address.hpp"
#include "talas/base/logger.hpp"
#include "xos/base/logged.hpp"

#if defined(SYSTEMV)
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#else /// defined(SYSTEMV)
#error only supported on SystemV operating systems
#endif /// defined(SYSTEMV)

namespace talas {
namespace network {
namespace ethernet {
namespace systemv {

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
    addresst(const string_t& adapter_named): ifn_(0) {
        if (!(this->set_to_adapter(adapter_named))) {
            throw exception(exception_failed);
        }
    }
    addresst(const addresst& copy): extends(copy), ifn_(0) {
    }
    addresst(): ifn_(0) {
    }
    virtual ~addresst() {
        free_if_nameindex();
    }

    /// set_to_adapter
    using extends::set_to_adapter;
    virtual actual_t* set_to_adapter(const string_t& named) {
        const char* chars = 0; size_t length = 0;
        if ((chars = named.chars(length)) && (0 < (length))) {
            const actual_t *actual = 0;
            static struct if_nameindex *ifn = 0;
            struct ifreq ifr;
            string_t adapter_name;

            this->clear();
            if ((actual = this->get_first(adapter_name, ifr, ifn))) {
                int unequal = 0;
                do {
                    if (!(unequal = adapter_name.compare(named))) {
                        this->set(*actual, adapter_name, ifn->if_index);
                        free_if_nameindex();
                        return &this->actual();
                    }
                } while ((actual = this->get_next(adapter_name, ifr, ifn)));
            }
            free_if_nameindex();
        } else {
            return this->set_to_first_adapter();
        }
        return 0;
    }
    virtual actual_t* set_to_adapter(int index) {
        const actual_t *actual = 0, *last_actual = 0;
        static struct if_nameindex *ifn = 0, *last_ifn = 0;
        struct ifreq ifr;
        string_t adapter_name;

        this->clear();
        if ((actual = this->get_first(adapter_name, ifr, ifn))) {
            int eindex = 0;
            do {
                if ((1 > index) || (eindex == index)) {
                    this->set(*actual, adapter_name, ifn->if_index);
                    free_if_nameindex();
                    return &this->actual();
                }
                last_actual = actual;
                last_ifn = ifn;
                ++eindex;
            } while ((actual = this->get_next(adapter_name, ifr, ifn)));

            if ((last_actual) && (last_ifn) && (0 > index)) {
                this->set(*last_actual, adapter_name, last_ifn->if_index);
                free_if_nameindex();
                return &this->actual();
            }
        }
        free_if_nameindex();
        return 0;
    }

    /// get...
    virtual const actual_t* get_first(string_t& adapter_name) const {
        const actual_t* actual = 0;
        actual = this->get_next(adapter_name, 0);
        return actual;
    }
    virtual const actual_t* get_next(string_t& adapter_name, const actual_t* to) const {
        const actual_t* actual = 0;
        static struct if_nameindex* ifn = 0;
        struct ifreq ifr;
        if ((actual = this->get_first(adapter_name, ifr, ifn))) {
            if ((to)) {
                do {
                    if ((*to) == (*actual)) {
                        actual = this->get_next(adapter_name, ifr, ifn);
                        break;
                    }
                } while ((actual = this->get_next(adapter_name, ifr, ifn)));
            }
        }
        return actual;
    }
    
protected:
    /// get...
    virtual const actual_t* get_first(string_t& adapter_name, struct ifreq& ifr, struct if_nameindex*& ifn) const {
        free_if_nameindex();
        if ((ifn = get_if_nameindex()) && (*((char*)ifn))) {
            const actual_t* actual = 0;

            do {
                if ((actual = this->get(adapter_name, ifr, ifn))) {
                    return actual;
                }
            } while (*((char*)(++ifn)));
        }
        return 0;
    }
    virtual const actual_t* get_next(string_t& adapter_name, struct ifreq& ifr, struct if_nameindex*& ifn) const {
        if ((ifn) && (*((char*)ifn))) {
            const actual_t* actual = 0;

            for (++ifn; *((char*)ifn); ++ifn) {
                if ((actual = this->get(adapter_name, ifr, ifn))) {
                    return actual;
                }
            }
        }
        return 0;
    }
    virtual const actual_t* get(string_t& adapter_name, struct ifreq& ifr, struct if_nameindex*& ifn) const {
        if ((ifn) && (*((char*)ifn))) {
            const char *chars = 0;

            if ((chars = ifn->if_name) && (chars[0])) {

                ::memset(&ifr, 0, sizeof(ifr));
                ::strncpy(ifr.ifr_name, chars, IF_NAMESIZE);

                if (0 == (ifr.ifr_name[IF_NAMESIZE-1])) {
                    string_t name(ifr.ifr_name);
                    int sock = -1;

                    LOGGER_IS_LOGGED_DEBUG("::socket(PF_INET, SOCK_STREAM, 0)...");
                    if (0 <= (sock = ::socket(PF_INET, SOCK_STREAM, 0))) {
                        LOGGER_IS_LOGGED_DEBUG("...::socket(PF_INET, SOCK_STREAM, 0)");
                        int err = -1, err2 = -1;

                        LOGGER_IS_LOGGED_DEBUG("::ioctl(sock, SIOCGIFHWADDR, &ifr = { ifr_name[" << IF_NAMESIZE << "]:\"" << ifr.ifr_name << "\" })...");
                        err = ::ioctl(sock, SIOCGIFHWADDR, &ifr);

                        LOGGER_IS_LOGGED_DEBUG("::close(sock)...");
                        if (!(err2 = ::close(sock))) {
                            LOGGER_IS_LOGGED_DEBUG("...::close(sock)");
                        } else {
                            LOGGER_IS_LOGGED_ERROR("...failed " << err << " = on ::close(sock)");
                        }
                        if (!(err)) {
                            LOGGER_IS_LOGGED_DEBUG("...::ioctl(sock, SIOCGIFHWADDR, &ifr = { ifr_name[" << IF_NAMESIZE << "]:\"" << ifr.ifr_name << "\" })");
                            sa_family_t family = 0;

                            family = ifr.ifr_ifru.ifru_hwaddr.sa_family;
                            if ((AF_LOCAL == (family))) {
                                const actual_t* actual = 0;

                                actual = (const actual_t*)(ifr.ifr_ifru.ifru_hwaddr.sa_data);
                                if ((actual)) {
                                    adapter_name.assign(name);
                                    return actual;
                                } else {
                                    LOGGER_IS_LOGGED_DEBUG("...0 = (const actual_t*)(ifr.ifr_ifru.ifru_hwaddr.sa_data)");
                                }
                            } else {
                                LOGGER_IS_LOGGED_DEBUG("...AF_LOCAL != (" << family << " = ifr.ifr_ifru.ifru_hwaddr.sa_family)");
                            }
                        } else {
                            LOGGER_IS_LOGGED_ERROR("...failed " << err << " = on ::ioctl(sock, SIOCGIFHWADDR, &ifr = { ifr_name[" << IF_NAMESIZE << "]:\"" << ifr.ifr_name << "\" })");
                        }
                    } else {
                        LOGGER_IS_LOGGED_ERROR("...failed " << sock << " = ::socket(PF_INET, SOCK_STREAM, 0)");
                    }
                } else {
                    LOGGER_IS_LOGGED_ERROR("...feiled (0 != (ifr.ifr_name[IF_NAMESIZE-1]))");
                }
            }
        }
        return 0;
    }

    /// ...if_nameindex
    virtual void free_if_nameindex() const {
        struct if_nameindex*& ifn = if_nameindex();
        if ((ifn)) {
            LOGGER_IS_LOGGED_DEBUG("::if_freenameindex(ifn)...");
            ::if_freenameindex(ifn);
            LOGGER_IS_LOGGED_DEBUG("...::if_freenameindex(ifn)");
            ifn = 0;
        }
    }
    virtual struct if_nameindex* get_if_nameindex() const {
        struct if_nameindex*& ifn = if_nameindex();
        LOGGER_IS_LOGGED_DEBUG("::if_nameindex()...");
        if ((ifn = ::if_nameindex())) {
            LOGGER_IS_LOGGED_DEBUG("...::if_nameindex()");
        } else {
            LOGGER_IS_LOGGED_ERROR("...0 = ::if_nameindex()");
        }
        return ifn;
    }
    virtual struct if_nameindex*& if_nameindex() const {
        return (struct if_nameindex*&)ifn_;
    }

protected:
    struct if_nameindex* ifn_;
}; /// class addresst
typedef addresst<> address;

} /// namespace systemv 
} /// namespace ethernet 
} /// namespace network 
} /// namespace talas 

#endif /// ndef TALAS_NETWORK_ETHERNET_SYSTEMV_ADDRESS_HPP 