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
#ifndef _MEDUSA_NETWORK_SOCKETS_CONNECTION_HPP
#define _MEDUSA_NETWORK_SOCKETS_CONNECTION_HPP

#include "medusa/network/connection.hpp"
#include "medusa/network/socket.hpp"
#include "medusa/io/logger.hpp"

namespace medusa {
namespace network {
namespace sockets {

typedef network::connection connectiont_implements;
typedef ::xos::network::os::socket connectiont_extends;
///////////////////////////////////////////////////////////////////////
/// Class: connectiont
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = connectiont_implements, class TExtends = connectiont_extends>
class _EXPORT_CLASS connectiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    connectiont(const network::transport& tp) {
        if (!(this->open(tp))) {
            const opener_exception e = failed_to_open;
            MEDUSA_LOG_ERROR("...failed on this->open(tp) throw (e = " << e << ")...");
            throw (e);
        }
    }
    connectiont() {
    }
    virtual ~connectiont() {
        if (!(this->closed())) {
            const opener_exception e = failed_to_close;
            MEDUSA_LOG_ERROR("...failed on this->closed() throw (e = " << e << ")...");
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef connectiont_implements connection_implements;
typedef connectiont<> connection_extends;
///////////////////////////////////////////////////////////////////////
/// Class: connection
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS connection
: virtual public connection_implements, public connection_extends {
public:
    typedef connection_implements Implements;
    typedef connection_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    connection(const network::transport& tp): Extends(tp) {
    }
    connection() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual sockets_connection_t* sockets_connection() const {
        return (sockets_connection_t*)this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace sockets 
} // namespace network 
} // namespace medusa 

#endif // _MEDUSA_NETWORK_SOCKETS_CONNECTION_HPP 
