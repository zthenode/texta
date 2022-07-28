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
///   File: protocol.hpp
///
/// Author: $author$
///   Date: 11/24/2014
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_MEDUSA_SERVER_PROTOCOL_HPP
#define _MEDUSA_INET_MEDUSA_SERVER_PROTOCOL_HPP

#include "medusa/inet/xttp/protocol/identifier.hpp"
#include "medusa/inet/xttp/protocol/name.hpp"
#include "medusa/inet/xttp/protocol/version.hpp"
#include "medusa/base/base.hpp"

#define MEDUSA_SERVER_PROTOCOL_NAME "MEDUSAD"
#define MEDUSA_SERVER_PROTOCOL_VERSION_MAJOR '1'
#define MEDUSA_SERVER_PROTOCOL_VERSION_MINOR '0'

namespace medusa {
namespace inet {
namespace medusa {
namespace server {
namespace protocol {

typedef xttp::protocol::name name_extends;
class _EXPORT_CLASS name: public name_extends {
public:
    name(): name_extends
    (MEDUSA_SERVER_PROTOCOL_NAME) {}
};

typedef xttp::protocol::version version_extends;
class _EXPORT_CLASS version: public version_extends {
public:
    version(): version_extends
    (MEDUSA_SERVER_PROTOCOL_VERSION_MAJOR,
     MEDUSA_SERVER_PROTOCOL_VERSION_MINOR) {}
};

typedef xttp::protocol::identifier identifier_extends;
class _EXPORT_CLASS identifier: public identifier_extends {
public:
    identifier(): identifier_extends
    (protocol::name(), protocol::version()) {}
};

} // namespace protocol
} // namespace server
} // namespace medusa
} // namespace inet
} // namespace medusa

#endif // _MEDUSA_INET_MEDUSA_SERVER_PROTOCOL_HPP 
