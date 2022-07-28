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
///   File: version.hpp
///
/// Author: $author$
///   Date: 11/25/2014
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_VERSION_HPP
#define _MEDUSA_INET_HTTP_VERSION_HPP

#include "medusa/inet/xttp/protocol/identifier.hpp"
#include "medusa/base/base.hpp"

#define MEDUSA_INET_HTTP_VERSION_PROTOCOL "HTTP"
#define MEDUSA_INET_HTTP_VERSION_MAJOR_NO 1
#define MEDUSA_INET_HTTP_VERSION_MAJOR MEDUSA_2STRING(MEDUSA_INET_HTTP_VERSION_MAJOR_NO)
#define MEDUSA_INET_HTTP_VERSION_MINOR_NO 1
#define MEDUSA_INET_HTTP_VERSION_MINOR MEDUSA_2STRING(MEDUSA_INET_HTTP_VERSION_MINOR_NO)

namespace medusa {
namespace inet {
namespace http {

typedef xttp::protocol::identifier_implements version_implements;
typedef xttp::protocol::identifier version_extends;
///////////////////////////////////////////////////////////////////////
///  Class: version
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS version: virtual public version_implements, public version_extends {
public:
    typedef version_implements Implements;
    typedef version_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    version(): Extends
    (MEDUSA_INET_HTTP_VERSION_PROTOCOL,
     MEDUSA_INET_HTTP_VERSION_MAJOR, MEDUSA_INET_HTTP_VERSION_MINOR) {
    }
    virtual ~version() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace http 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_HTTP_VERSION_HPP 
