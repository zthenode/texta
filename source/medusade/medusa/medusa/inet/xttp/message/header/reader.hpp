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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 2/17/2016
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_MESSAGE_HEADER_READER_HPP
#define _MEDUSA_INET_XTTP_MESSAGE_HEADER_READER_HPP

#include "medusa/io/reader.hpp"
#include "medusa/inet/xttp/message/header/field.hpp"

namespace medusa {
namespace inet {
namespace xttp {
namespace message {
namespace header {

typedef implement_base reader_implements;
typedef base reader_extends;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<typename TField = field,
 class TImplements = reader_implements, class TExtends = reader_extends>

class _EXPORT_CLASS readert: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef readert Derives;

    typedef io::reader reader_t;
    typedef TField field_t;
    typedef typename TField::name_t name_t;
    typedef typename TField::value_t value_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    readert(field_t& field)
    : separator_((char_t)MEDUSA_INET_XTTP_MESSAGE_HEADER_FIELD_SEPARATOR),
      sp_((char_t)MEDUSA_INET_XTTP_SP),
      cr_((char_t)MEDUSA_INET_XTTP_CR),
      lf_((char_t)MEDUSA_INET_XTTP_LF),
      on_read_(0),
      field_(field),
      name_(field_.name()),
      value_(field_.value()) {
    }
    virtual ~readert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool read(reader_t& r) {
        bool success = true;
        field_.clear();
        on_read_ = &Derives::on_read_name;
        while ((success = on_read(r))) {
            if (!(on_read_ != &Derives::on_read_done)) {
                break;
            }
        }
        return success;
    }
    virtual bool on_read(reader_t& r) {
        if ((on_read_)) {
            return (this->*on_read_)(r);
        }
        return false;
    }
    virtual bool on_read_name_token() {
        if (0 < (token_.length())) {
            MEDUSA_LOG_MESSAGE_DEBUG("...read name = \"" << token_ << "\"");
            name_.assign(token_.chars());
            on_read_ = &Derives::on_read_value_leading_sp;
            return true;
        }
        return false;
    }
    virtual bool on_read_name(reader_t& r) {
        ssize_t count = 0;
        char_t c = 0;
        token_.clear();
        for (bool more = true; more; ) {
            if (0 < (count = r.read(&c, sizeof(c)))) {
                if ((c == separator_)) {
                    more = false;
                    if (on_read_name_token()) {
                        return true;
                    }
                } else {
                    if (valid_name_char(c)) {
                        token_.append(&c, 1);
                    } else {
                        more = false;
                    }
                }
            } else {
                more = false;
            }
        }
        return false;
    }
    virtual bool on_read_value_token() {
        if (0 < (token_.length())) {
            MEDUSA_LOG_MESSAGE_DEBUG("...read value = \"" << token_ << "\"");
            value_.assign(token_.chars());
        }
        field_.combine();
        MEDUSA_LOG_MESSAGE_DEBUG("...read field = \"" << field_ << "\"");
        on_read_ = &Derives::on_read_done;
        return true;
    }
    virtual bool on_read_value_leading_sp(reader_t& r) {
        ssize_t count = 0;
        char_t c = 0;
        token_.clear();
        for (bool more = true; more; ) {
            if (0 < (count = r.read(&c, sizeof(c)))) {
                if ((sp_ != c)) {
                    if (valid_value_char(c)) {
                        token_.append(&c, 1);
                        on_read_ = &Derives::on_read_value;
                        return true;
                    } else {
                        more = false;
                    }
                }
            } else {
                more = false;
                if (on_read_value_token()) {
                    return true;
                }
            }
        }
        return false;
    }
    virtual bool on_read_value(reader_t& r) {
        ssize_t count = 0;
        char_t c = 0;
        for (bool more = true; more; ) {
            if (0 < (count = r.read(&c, sizeof(c)))) {
                if (valid_value_char(c)) {
                    token_.append(&c, 1);
                } else {
                    more = false;
                }
            } else {
                more = false;
                if (on_read_value_token()) {
                    return true;
                }
            }
        }
        return false;
    }
    virtual bool on_read_fail(reader_t& r) {
        return false;
    }
    virtual bool on_read_done(reader_t& r) {
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool valid_name_char(const char_t& c) const {
        if ((c != cr_) && (c != lf_)) {
            return true;
        }
        return false;
    }
    virtual bool valid_value_char(const char_t& c) const {
        if ((c != cr_) && (c != lf_)) {
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef bool (Derives::*on_read_t)(reader_t& r);

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t separator_, sp_, cr_, lf_;
    on_read_t on_read_;
    field_t& field_;
    name_t& name_;
    value_t& value_;
    string_t token_;
};

} // namespace header 
} // namespace message 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_MESSAGE_HEADER_READER_HPP 
        

