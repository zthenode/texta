///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2014 $organization$
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
///   File: endpoint.hpp
///
/// Author: $author$
///   Date: 11/27/2014, 2/17/2021
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_NETWORK_ENDPOINT_HPP
#define _XOS_NADIR_XOS_NETWORK_ENDPOINT_HPP

#include "xos/network/address.hpp"
#include "xos/base/attacher.hpp"
#include "xos/base/string.hpp"
#include "xos/io/logger.hpp"

#define XOS_NETWORK_ENDPOINT_ADDRHOST_SIZE NI_MAXHOST

namespace xos {
namespace network {

enum {
    first_addrindex = 0,
    last_addrindex = -1
};
typedef int addrindex_t;

typedef u_short sockport_t;

typedef int endpoint_exception_t;
enum {
    failed_to_attach_endpoint,
    failed_to_detach_endpoint
};

enum { endpoint_unattached = 0 };
typedef int endpoint_unattached_t;
typedef struct sockaddr* endpoint_attached_t;

typedef base::attachert
<endpoint_attached_t, endpoint_unattached_t,
 endpoint_unattached, address> endpoint_implements;
///////////////////////////////////////////////////////////////////////
///  Class: endpointt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = endpoint_implements>
class _EXPORT_CLASS endpointt: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual struct sockaddr* attach_first(const xos::base::string& host, sockport_t port) {
        const char* chars = host.has_chars();
        if ((chars)) { return this->attach_first(chars, port); }
        return this->attach(port);
    }
    virtual struct sockaddr* attach_last(const xos::base::string& host, sockport_t port) {
        const char* chars = host.has_chars();
        if ((chars)) { return this->attach_last(chars, port); }
        return this->attach(port);
    }
    virtual struct sockaddr* attach(const xos::base::string& host, sockport_t port) {
        const char* chars = host.has_chars();
        if ((chars)) { return this->attach(chars, port); }
        return this->attach(port);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual struct sockaddr* attach(const char_t* host, sockport_t port) {
        return this->attach(host, first_addrindex, port);
    }
    virtual struct sockaddr* attach_first(const char_t* host, sockport_t port) {
        return this->attach(host, first_addrindex, port);
    }
    virtual struct sockaddr* attach_last(const char_t* host, sockport_t port) {
        return this->attach(host, last_addrindex, port);
    }
    virtual struct sockaddr* attach
    (const char_t* host, addrindex_t index, sockport_t port) {
        struct addrinfo* addrs = 0;
        struct sockaddr* saddr = 0;
        int err = 0;

        XOS_LOG_DEBUG("getaddrinfo(\"" << host << "\",...)...");
        if (!(err = getaddrinfo(host, 0, 0, &addrs))) {
            const address_family_t family = this->get_family();
            struct addrinfo* addr = 0;
            addrindex_t addr_i = 0;
            bool do_getnameinfo = false;

            XOS_LOG_DEBUG("...getaddrinfo(\"" << host << "\",...) family = " << family);
            for (addr_i = 0, addr = addrs; addr; addr = addr->ai_next) {
                const address_family_t addrfamily = addr->ai_family;

                if (family == (addrfamily)) {
                    if ((addr_i == index) || ((last_addrindex == index) && !(addr->ai_next))) {
                        XOS_LOG_DEBUG("...found family " << family << " address[" << addr_i << "]");
                        saddr = this->attach(addr->ai_addr, addr->ai_addrlen, port);
                    } else {
                        ++addr_i;
                    }
                }
                if ((do_getnameinfo)) {
                    char addrhost[XOS_NETWORK_ENDPOINT_ADDRHOST_SIZE];
    
                    XOS_LOG_DEBUG("getnameinfo(...)... family = " << addrfamily);
                    if (!(err = getnameinfo
                        (addr->ai_addr, addr->ai_addrlen, addrhost, sizeof(addrhost)-1, 0, 0, 0))) {
    
                        addrhost[sizeof(addrhost)-1] = 0;
                        XOS_LOG_DEBUG("...getnameinfo(..., addrhost = \"" << addrhost << "\",...)");
                        /*if (family == (addrfamily)) {
                            if ((addr_i == index) || ((last_addrindex == index) && !(addr->ai_next))) {
                                XOS_LOG_DEBUG("...found family " << family << " address[" << addr_i << "]");
                                saddr = this->attach(addr->ai_addr, addr->ai_addrlen, port);
                                break;
                            } else {
                                ++addr_i;
                            }
                        }*/
                    } else {
                        XOS_LOG_ERROR("...failed " << this->get_last_error() << " on getnameinfo(...)");
                    }
                }
                if ((saddr)) {
                    break;
                }
            }
            freeaddrinfo(addrs);
        } else {
            XOS_LOG_ERROR("...failed " << this->get_last_error() << " on getaddrinfo(\"" << host << "\",...)");
        }
        return saddr;
    }
    virtual struct sockaddr* attach
    (const struct sockaddr* socket_address, socklen_t socket_address_len, sockport_t port) {
        return 0;
    }
    virtual struct sockaddr* attach(const char_t* path) {
        return 0;
    }
    virtual struct sockaddr* attach(sockport_t port) {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual struct sockaddr* socket_address(socklen_t& len) const {
        len = socket_address_len();
        return this->attached_to();
    }
    virtual struct sockaddr* socket_address() const {
        return this->attached_to();
    }
    virtual socklen_t socket_address_len() const {
        return 0;
    }
    virtual operator struct sockaddr* () const {
        return this->socket_address();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_last_error() const {
        return errno;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef endpointt<> endpoint;

} // namespace network 
} // namespace xos 

#endif // _XOS_NADIR_XOS_NETWORK_ENDPOINT_HPP 
