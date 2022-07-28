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
///   File: line.hpp
///
/// Author: $author$
///   Date: 11/23/2014
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_REQUEST_LINE_HPP
#define _MEDUSA_INET_XTTP_REQUEST_LINE_HPP

#include "medusa/inet/xttp/request/method.hpp"
#include "medusa/inet/xttp/request/parameters.hpp"
#include "medusa/inet/xttp/protocol/identifier.hpp"
#include "medusa/base/base.hpp"

namespace medusa {
namespace inet {
namespace xttp {
namespace request {

typedef method line_method;
typedef parameters line_parameters;
typedef protocol::identifier line_protocol;

typedef string_implements line_implements;
typedef string_t line_extends;
///////////////////////////////////////////////////////////////////////
///  Class: linet
///////////////////////////////////////////////////////////////////////
template
<typename TMethod = line_method,
 typename TParameters = line_parameters, typename TProtocol = line_protocol,
 class TImplements = line_implements, class TExtends = line_extends>

class _EXPORT_CLASS linet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TMethod method_t;
    typedef TParameters parameters_t;
    typedef TProtocol protocol_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    linet
    (const method_t& method,
     const parameters_t& parameters, const protocol_t& protocol)
    : sp_((char_t)MEDUSA_INET_XTTP_SP),
      cr_((char_t)MEDUSA_INET_XTTP_CR),
      lf_((char_t)MEDUSA_INET_XTTP_LF),
      method_(method), parameters_(parameters), protocol_(protocol) {
        combine();
    }
    linet
    (const method_t& method, const protocol_t& protocol)
    : sp_((char_t)MEDUSA_INET_XTTP_SP),
      cr_((char_t)MEDUSA_INET_XTTP_CR),
      lf_((char_t)MEDUSA_INET_XTTP_LF),
      method_(method), protocol_(protocol) {
        combine();
    }
    linet
    (const char_t* method,
     const char_t* parameters, const protocol_t& protocol)
    : sp_((char_t)MEDUSA_INET_XTTP_SP),
      cr_((char_t)MEDUSA_INET_XTTP_CR),
      lf_((char_t)MEDUSA_INET_XTTP_LF),
      method_(method), parameters_(parameters), protocol_(protocol) {
        combine();
    }
    linet
    (const char_t* method, const protocol_t& protocol)
    : sp_((char_t)MEDUSA_INET_XTTP_SP),
      cr_((char_t)MEDUSA_INET_XTTP_CR),
      lf_((char_t)MEDUSA_INET_XTTP_LF),
      method_(method), protocol_(protocol) {
        combine();
    }
    linet(const linet& copy)
    : Extends(copy),
      sp_((char_t)MEDUSA_INET_XTTP_SP),
      cr_((char_t)MEDUSA_INET_XTTP_CR),
      lf_((char_t)MEDUSA_INET_XTTP_LF),
      method_(copy.method_),
      parameters_(copy.parameters_), protocol_(copy.protocol_) {
    }
    linet()
    : sp_((char_t)MEDUSA_INET_XTTP_SP),
      cr_((char_t)MEDUSA_INET_XTTP_CR),
      lf_((char_t)MEDUSA_INET_XTTP_LF) {
    }
    virtual ~linet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual linet& clear() {
        Extends::clear();
        method_.clear();
        parameters_.clear();
        protocol_.clear();
        return *this;
    }
    virtual linet& combine() {
        this->assign(method_.chars());
        this->append(&sp_, 1);
        if (0 < (parameters_.length())) {
            this->append(parameters_.chars());
            this->append(&sp_, 1);
        }
        this->append(protocol_.chars());
        this->append(&cr_, 1);
        this->append(&lf_, 1);
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual method_t& set_method(method_t& to) {
        method_.assign(to);
        combine();
        return ((method_t&)method_);
    }
    virtual method_t& method() const {
        return ((method_t&)method_);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual parameters_t& set_parameters(parameters_t& to) {
        parameters_.assign(to);
        combine();
        return ((parameters_t&)parameters_);
    }
    virtual parameters_t& parameters() const {
        return ((parameters_t&)parameters_);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual protocol_t& set_protocol(protocol_t& to) {
        protocol_.assign(to);
        combine();
        return ((protocol_t&)protocol_);
    }
    virtual protocol_t& protocol() const {
        return ((protocol_t&)protocol_);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t sp_, cr_, lf_;
    method_t method_;
    parameters_t parameters_;
    protocol_t protocol_;
};
typedef linet<> line;

} // namespace request 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_REQUEST_LINE_HPP 
