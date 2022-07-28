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
#ifndef _MEDUSA_INET_XTTP_RESPONSE_STATUS_LINE_HPP
#define _MEDUSA_INET_XTTP_RESPONSE_STATUS_LINE_HPP

#include "medusa/inet/xttp/response/status/code.hpp"
#include "medusa/inet/xttp/response/status/reason.hpp"
#include "medusa/inet/xttp/protocol/identifier.hpp"
#include "medusa/base/base.hpp"

namespace medusa {
namespace inet {
namespace xttp {
namespace response {
namespace status {

typedef string_implements line_implements;
typedef string_t line_extends;
///////////////////////////////////////////////////////////////////////
///  Class: linet
///////////////////////////////////////////////////////////////////////
template
<class TImplements = line_implements,
 class TExtends = line_extends>

class _EXPORT_CLASS linet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef protocol::identifier protocol_t;
    typedef status::code code_t;
    typedef status::reason reason_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    linet
    (const protocol_t& protocol, const code_t& code, const reason_t& reason)
    : sp_((char_t)MEDUSA_INET_XTTP_SP),
      cr_((char_t)MEDUSA_INET_XTTP_CR),
      lf_((char_t)MEDUSA_INET_XTTP_LF),
      protocol_(protocol), code_(code), reason_(reason) {
        combine();
    }
    linet
    (const protocol_t& protocol, const code_t& code)
    : sp_((char_t)MEDUSA_INET_XTTP_SP),
      cr_((char_t)MEDUSA_INET_XTTP_CR),
      lf_((char_t)MEDUSA_INET_XTTP_LF),
      protocol_(protocol), code_(code) {
        combine();
    }
    linet(const linet& copy)
    : Extends(copy),
      sp_((char_t)MEDUSA_INET_XTTP_SP),
      cr_((char_t)MEDUSA_INET_XTTP_CR),
      lf_((char_t)MEDUSA_INET_XTTP_LF),
      protocol_(copy.protocol_), code_(copy.code_), reason_(copy.reason_) {
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
        protocol_.clear();
        code_.clear();
        reason_.clear();
        return *this;
    }
    virtual linet& combine() {
        this->assign(protocol_.chars());
        this->append(&sp_, 1);
        this->append(code_.chars());
        if (0 < (reason_.length())) {
            this->append(&sp_, 1);
            this->append(reason_.chars());
        }
        this->append(&cr_, 1);
        this->append(&lf_, 1);
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual protocol_t& set_protocol(const protocol_t& to) {
        protocol_.assign(to);
        combine();
        return (protocol_t&)protocol_;
    }
    virtual protocol_t& set_protocol(const char_t* to) {
        protocol_.assign(to);
        combine();
        return (protocol_t&)protocol_;
    }
    virtual protocol_t& protocol() const {
        return (protocol_t&)protocol_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual code_t& set_code(const code_t& to) {
        code_.assign(to);
        combine();
        return (code_t&)code_;
    }
    virtual code_t& set_code(const char_t* to) {
        code_.assign(to);
        combine();
        return (code_t&)code_;
    }
    virtual code_t& code() const {
        return (code_t&)code_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual reason_t& set_reason(const reason_t& to) {
        reason_.assign(to);
        combine();
        return (reason_t&)reason_;
    }
    virtual reason_t& set_reason(const char_t* to) {
        reason_.assign(to);
        combine();
        return (reason_t&)reason_;
    }
    virtual reason_t& reason() const {
        return (reason_t&)reason_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t sp_, cr_, lf_;
    protocol_t protocol_;
    code_t code_;
    reason_t reason_;
};
typedef linet<> line;

} // namespace status 
} // namespace response 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_RESPONSE_STATUS_LINE_HPP 
