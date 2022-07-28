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
///   File: transport.hpp
///
/// Author: $author$
///   Date: 8/11/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_NETWORK_LOCAL_STREAM_TRANSPORT_HPP
#define _XOS_NADIR_XOS_NETWORK_LOCAL_STREAM_TRANSPORT_HPP

#include "xos/network/local/transport.hpp"

#define XOS_NETWORK_LOCAL_STREAM_TRANSPORT_TYPE SOCK_STREAM

namespace xos {
namespace network {
namespace local {
namespace stream {

typedef local::transport transport_implements;
typedef base::base transport_extends;
///////////////////////////////////////////////////////////////////////
///  Class: transportt
///////////////////////////////////////////////////////////////////////
template
<typename TDomain = transport_domain_t,
 typename TType = transport_type_t,
 typename TProtocol = transport_protocol_t,
 class TImplements = transport_implements, class TExtends = transport_extends>

class _EXPORT_CLASS transportt: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TDomain domain_t;
    typedef TType type_t;
    typedef TProtocol protocol_t;
    enum { domain = XOS_NETWORK_LOCAL_TRANSPORT_DOMAIN };
    enum { type = XOS_NETWORK_LOCAL_STREAM_TRANSPORT_TYPE };
    enum { protocol = XOS_NETWORK_LOCAL_TRANSPORT_PROTOCOL };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    transportt() {
    }
    virtual ~transportt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual domain_t get_domain() const {
        return domain;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual type_t get_type() const {
        return type;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual protocol_t get_protocol() const {
        return protocol;
    }
};
typedef transportt<> transport;

} // namespace stream 
} // namespace local 
} // namespace network 
} // namespace xos 

#endif // _XOS_NADIR_XOS_NETWORK_LOCAL_STREAM_TRANSPORT_HPP 
