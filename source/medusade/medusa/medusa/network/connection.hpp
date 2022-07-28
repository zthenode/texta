///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   File: connection.hpp
///
/// Author: $author$
///   Date: 1/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_NETWORK_CONNECTION_HPP
#define _MEDUSA_NETWORK_CONNECTION_HPP

#include "medusa/network/location.hpp"
#include "xos/network/socket.hpp"

namespace medusa {
namespace network {

namespace sockets {

class _EXPORT_CLASS connection;

} // namespace sockets

typedef sockets::connection sockets_connection_t;
typedef ::xos::network::socket connection_implements;
///////////////////////////////////////////////////////////////////////
/// Class: connectiont
///////////////////////////////////////////////////////////////////////
template <class TImplements = connection_implements>
class _EXPORT_CLASS connectiont: virtual public TImplements {
public:
    typedef TImplements Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::send;
    virtual ssize_t send(const void* buf, size_t len) {
        return this->send(buf, len, 0);
    }
    using Implements::recv;
    virtual ssize_t recv(void* buf, size_t len) {
        return this->recv(buf, len, 0);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool connect(const network::location& lc) {
        network::location::sockets_address_t* sa = 0;
        if ((sa = lc.sockets_address())) {
            return Implements::connect(*sa);
        }
        return false;
    }
    virtual bool disconnect() {
        bool success = false;
        if ((this->shutdown())) {
            success = true;
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual sockets_connection_t* sockets_connection() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef connectiont<> connection;

} // namespace network 
} // namespace medusa 

#endif // _MEDUSA_NETWORK_CONNECTION_HPP 
