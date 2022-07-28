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
///   File: field.hpp
///
/// Author: $author$
///   Date: 11/23/2014
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_MESSAGE_HEADER_FIELD_HPP
#define _MEDUSA_INET_XTTP_MESSAGE_HEADER_FIELD_HPP

#include "medusa/inet/xttp/xttp.hpp"

#define MEDUSA_INET_XTTP_MESSAGE_HEADER_FIELD_SEPARATOR ':'
#define MEDUSA_INET_XTTP_MESSAGE_HEADER_FIELD_SEPARATOR_CHARS ": "

namespace medusa {
namespace inet {
namespace xttp {
namespace message {
namespace header {

typedef string_t_implements field_implements;
typedef string_t field_extends;
///////////////////////////////////////////////////////////////////////
///  Class: fieldt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = field_implements, class TExtends = field_extends>

class _EXPORT_CLASS fieldt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef string_t name_t;
    typedef string_t value_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    fieldt(const name_t& name, const value_t& value)
    : cr_((char_t)MEDUSA_INET_XTTP_CR),
      lf_((char_t)MEDUSA_INET_XTTP_LF),
      separator_(MEDUSA_INET_XTTP_MESSAGE_HEADER_FIELD_SEPARATOR_CHARS),
      name_(name),
      value_(value) {
        this->combine();
    }
    fieldt(const fieldt& copy)
    : Extends(copy),
      cr_((char_t)MEDUSA_INET_XTTP_CR),
      lf_((char_t)MEDUSA_INET_XTTP_LF),
      separator_(MEDUSA_INET_XTTP_MESSAGE_HEADER_FIELD_SEPARATOR_CHARS),
      name_(copy.name_),
      value_(copy.value_) {
    }
    fieldt()
    : cr_((char_t)MEDUSA_INET_XTTP_CR),
      lf_((char_t)MEDUSA_INET_XTTP_LF),
      separator_(MEDUSA_INET_XTTP_MESSAGE_HEADER_FIELD_SEPARATOR_CHARS) {
    }
    virtual ~fieldt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual fieldt& clear() {
        Extends::clear();
        name_.clear();
        value_.clear();
        return *this;
    }
    virtual fieldt& combine() {
        this->assign(this->name_.chars());
        this->append(this->separator_.chars());
        this->append(this->value_.chars());
        this->append(&this->cr_, 1);
        this->append(&this->lf_, 1);
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string_t& set_name(const char_t* to) {
        name_.assign(to);
        combine();
        return name_;
    }
    virtual string_t& name() const {
        return (string_t&)name_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string_t& set_value(const char_t* to) {
        value_.assign(to);
        combine();
        return value_;
    }
    virtual string_t& value() const {
        return (string_t&)value_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t cr_, lf_;
    const string_t separator_;
    name_t name_;
    value_t value_;
};
typedef fieldt<> field;

} // namespace header 
} // namespace message 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_MESSAGE_HEADER_FIELD_HPP 
