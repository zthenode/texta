///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   Date: 8/10/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_NETWORK_LOCAL_ENDPOINT_HPP
#define _XOS_NADIR_XOS_NETWORK_LOCAL_ENDPOINT_HPP

#include "xos/network/endpoint.hpp"
#include "xos/network/local/address.hpp"
#include "xos/base/attached.hpp"

namespace xos {
namespace network {
namespace local {

typedef network::endpoint endpoint_implements;
typedef base::attachedt
<endpoint_attached_t, endpoint_unattached_t, endpoint_unattached,
 endpoint_implements, address> endpoint_extends;
///////////////////////////////////////////////////////////////////////
///  Class: endpointt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = endpoint_implements, class TExtends = endpoint_extends>
class _EXPORT_CLASS endpointt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    endpointt(const char* path): socket_address_len_(0) {
        memset(&socket_address_, 0, sizeof(socket_address_));
        if (!(this->attach(path))) {
            endpoint_exception_t e = failed_to_attach_endpoint;
            XOS_LOG_ERROR("throwing failed_to_attach_endpoint...");
            throw (e);
        }
    }
    endpointt(): socket_address_len_(0) {
        memset(&socket_address_, 0, sizeof(socket_address_));
    }
    virtual ~endpointt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual struct sockaddr* attach(const char* path) {
        memset(&socket_address_, 0, socket_address_len_ = (sizeof(socket_address_)));
        socket_address_.sun_family = this->get_family();
        strncpy(socket_address_.sun_path, path, sizeof(socket_address_.sun_path)-1);;
        return Extends::attach((sockaddr*)(&socket_address_));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual socklen_t socket_address_len() const {
        return (socklen_t)(sizeof(socket_address_));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    socklen_t socket_address_len_;
    struct sockaddr_un socket_address_;
};
typedef endpointt<> endpoint;

} // namespace local 
} // namespace network 
} // namespace xos 

#endif // _XOS_NADIR_XOS_NETWORK_LOCAL_ENDPOINT_HPP 
