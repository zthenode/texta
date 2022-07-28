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
///   Date: 2/16/2016
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_PROTOCOL_READER_HPP
#define _MEDUSA_INET_XTTP_PROTOCOL_READER_HPP

#include "medusa/inet/xttp/protocol/identifier.hpp"
#include "medusa/inet/xttp/protocol/name.hpp"
#include "medusa/inet/xttp/protocol/version.hpp"
#include "medusa/io/reader.hpp"

namespace medusa {
namespace inet {
namespace xttp {
namespace protocol {

typedef implement_base reader_implements;
typedef base reader_extends;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<typename TIdentifier = identifier,
 class TImplements = reader_implements, class TExtends = reader_extends>

class _EXPORT_CLASS readert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef readert Derives;

    typedef io::reader reader_t;
    typedef TIdentifier identifier_t;
    typedef typename TIdentifier::name_t name_t;
    typedef typename TIdentifier::version_t version_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    readert(identifier_t& identifier)
    : name_version_separator_
      ((char_t)(MEDUSA_INET_XTTP_PROTOCOL_IDENTIFIER_NAME_VERSION_SEPARATOR)),
      major_minor_separator_
      ((char_t)(MEDUSA_INET_XTTP_PROTOCOL_VERSION_MAJOR_MINOR_SEPARATOR)),
      sp_((char_t)MEDUSA_INET_XTTP_SP),
      cr_((char_t)MEDUSA_INET_XTTP_CR),
      lf_((char_t)MEDUSA_INET_XTTP_LF),
      digit_min_((char_t)'0'),
      digit_max_((char_t)'9'),
      on_read_(0),
      identifier_(identifier),
      name_(identifier_.name()),
      version_(identifier_.version()),
      major_(version_.major()),
      minor_(version_.minor()) {
    }
    virtual ~readert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool read(reader_t& r) {
        bool success = true;
        identifier_.clear();
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
            on_read_ = &Derives::on_read_major;
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
                if ((c == name_version_separator_)) {
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
    virtual bool on_read_major_token() {
        if (0 < (token_.length())) {
            MEDUSA_LOG_MESSAGE_DEBUG("...read major = \"" << token_ << "\"");
            major_.assign(token_.chars());
            on_read_ = &Derives::on_read_minor;
            return true;
        }
        return false;
    }
    virtual bool on_read_major(reader_t& r) {
        ssize_t count = 0;
        char_t c = 0;
        token_.clear();
        for (bool more = true; more; ) {
            if (0 < (count = r.read(&c, sizeof(c)))) {
                if ((c == major_minor_separator_)) {
                    more = false;
                    if (on_read_major_token()) {
                        return true;
                    }
                } else {
                    if (valid_version_char(c)) {
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
    virtual bool on_read_minor_token() {
        if (0 < (token_.length())) {
            MEDUSA_LOG_MESSAGE_DEBUG("...read minor = \"" << token_ << "\"");
            minor_.assign(token_.chars());
            version_.combine();
            identifier_.combine();
            on_read_ = &Derives::on_read_done;
            return true;
        }
        return false;
    }
    virtual bool on_read_minor(reader_t& r) {
        ssize_t count = 0;
        char_t c = 0;
        token_.clear();
        for (bool more = true; more; ) {
            if (0 < (count = r.read(&c, sizeof(c)))) {
                if (valid_version_char(c)) {
                    token_.append(&c, 1);
                } else {
                    more = false;
                }
            } else {
                more = false;
                if (on_read_minor_token()) {
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
        if ((c != sp_) && (c != cr_) && (c != lf_)) {
            return true;
        }
        return false;
    }
    virtual bool valid_version_char(const char_t& c) const {
        if ((c >= digit_min_) && (c <= digit_max_)) {
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
    const char_t
       name_version_separator_, major_minor_separator_,
       sp_, cr_, lf_, digit_min_, digit_max_;
    on_read_t on_read_;
    identifier_t& identifier_;
    name_t& name_;
    version_t& version_;
    string_t &major_, &minor_;
    string_t token_;
};
typedef readert<> reader;

} // namespace protocol 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_PROTOCOL_READER_HPP 
