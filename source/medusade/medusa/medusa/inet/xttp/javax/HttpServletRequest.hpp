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
///   File: HttpServletRequest.hpp
///
/// Author: $author$
///   Date: 2/24/2016
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_JAVAX_HTTPSERVLETREQUEST_HPP
#define _MEDUSA_INET_XTTP_JAVAX_HTTPSERVLETREQUEST_HPP

#include "xos/jdk/javax/servlet/http/HttpServletRequest.hpp"
#include "medusa/inet/xttp/request/message.hpp"

namespace medusa {
namespace inet {
namespace xttp {
namespace javax {

typedef xos::javax::servlet::http::HttpServletRequest HttpServletRequest_implements;
typedef base HttpServletRequest_extends;
///////////////////////////////////////////////////////////////////////
///  Class: HttpServletRequest
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS HttpServletRequest
: virtual public HttpServletRequest_implements, public HttpServletRequest_extends {
public:
    typedef HttpServletRequest_implements Implements;
    typedef HttpServletRequest_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    HttpServletRequest() {
    }
    virtual ~HttpServletRequest() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace javax 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_JAVAX_HTTPSERVLETREQUEST_HPP 
