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
///   Date: 2/15/2016
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_REQUEST_READER_HPP
#define _MEDUSA_INET_XTTP_REQUEST_READER_HPP

#include "medusa/inet/xttp/request/message.hpp"
#include "medusa/inet/xttp/request/line.hpp"
#include "medusa/inet/xttp/request/method.hpp"
#include "medusa/inet/xttp/request/parameters.hpp"
#include "medusa/inet/xttp/message/header/reader.hpp"
#include "medusa/inet/xttp/message/header/fields.hpp"
#include "medusa/inet/xttp/message/header/field.hpp"
#include "medusa/inet/xttp/protocol/reader.hpp"
#include "medusa/io/reader.hpp"

namespace medusa {
namespace inet {
namespace xttp {
namespace request {

typedef implement_base reader_implements;
typedef base reader_extends;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<typename TMessage = message,
 class TImplements = reader_implements, class TExtends = reader_extends>

class _EXPORT_CLASS readert: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef readert Derives;

    typedef io::reader reader_t;
    typedef TMessage message_t;
    typedef typename TMessage::line_t line_t;
    typedef typename line_t::method_t method_t;
    typedef typename line_t::parameters_t parameters_t;
    typedef typename line_t::protocol_t protocol_t;
    typedef typename TMessage::headers_t headers_t;
    typedef typename headers_t::field_t header_t;
    typedef typename headers_t::field_list_t header_list_t;
    typedef typename headers_t::field_list_iterator_t header_iterator_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    readert(message_t& message)
    : sp_((char_t)MEDUSA_INET_XTTP_SP),
      cr_((char_t)MEDUSA_INET_XTTP_CR),
      lf_((char_t)MEDUSA_INET_XTTP_LF),
      on_read_(0),
      message_(message),
      line_(message_.line()),
      method_(line_.method()),
      parameters_(line_.parameters()),
      protocol_(line_.protocol()),
      protocol_reader_(protocol_),
      headers_(message_.headers()),
      header_reader_(header_),
      token_reader_(token_) {
    }
    virtual ~readert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool read(reader_t& r) {
        bool success = true;
        message_.clear();
        on_read_ = &Derives::on_read_method;
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
    virtual bool on_read_method_token(bool method_only = false) {
        if (0 < (token_.length())) {
            MEDUSA_LOG_MESSAGE_DEBUG("...read method = \"" << token_ << "\"");
            method_.assign(token_.chars());
            if ((method_only)) {
                line_.combine();
                on_read_ = &Derives::on_read_done_lf;
            } else {
                on_read_ = &Derives::on_read_parameters;
            }
            return true;
        }
        return false;
    }
    virtual bool on_read_method(reader_t& r) {
        ssize_t count = 0;
        char_t c = 0;
        token_.clear();
        for (bool more = true; more; ) {
            if (0 < (count = r.read(&c, sizeof(c)))) {
                if ((c == sp_)) {
                    more = false;
                    if (on_read_method_token()) {
                        return true;
                    }
                } else {
                    if ((c == cr_) || (c == lf_)) {
                        more = false;
                        if ((c == cr_)) {
                            if (on_read_method_token(true)) {
                                return true;
                            }
                        }
                    } else {
                        token_.append(&c, 1);
                    }
                }
            } else {
                more = false;
            }
        }
        return false;
    }
    virtual bool on_read_parameters_token() {
        if (0 < (token_.length())) {
            MEDUSA_LOG_MESSAGE_DEBUG("...read parameters = \"" << token_ << "\"");
            parameters_.assign(token_.chars());
            on_read_ = &Derives::on_read_protocol;
            return true;
        }
        return false;
    }
    virtual bool on_read_parameters(reader_t& r) {
        ssize_t count = 0;
        char_t c = 0;
        token_.clear();
        for (bool more = true; more; ) {
            if (0 < (count = r.read(&c, sizeof(c)))) {
                if ((c == sp_)) {
                    more = false;
                    if ((on_read_parameters_token())) {
                        return true;
                    }
                } else {
                    if ((c == cr_)) {
                        more = false;
                        if ((on_read_protocol_token())) {
                            return true;
                        }
                    } else {
                        token_.append(&c, 1);
                    }
                }
            } else {
                more = false;
            }
        }
        return false;
    }
    virtual bool on_read_protocol_token() {
        if (0 < (token_.length())) {
            MEDUSA_LOG_MESSAGE_DEBUG("...read protocol = \"" << token_ << "\"");
            protocol_.assign(token_.chars());
            token_reader_.reset();
            if ((protocol_reader_.read(token_reader_))) {
                MEDUSA_LOG_MESSAGE_DEBUG("...protocol name = \"" << protocol_.name() << "\" version major = \"" << protocol_.version().major() << "\" version minor = \"" << protocol_.version().minor() << "\"");
                on_read_ = &Derives::on_read_protocol_lf;
                return true;
            }
        }
        return false;
    }
    virtual bool on_read_protocol(reader_t& r) {
        ssize_t count = 0;
        char_t c = 0;
        token_.clear();
        for (bool more = true; more; ) {
            if (0 < (count = r.read(&c, sizeof(c)))) {
                if ((c == cr_)) {
                    more = false;
                    if ((on_read_protocol_token())) {
                        return true;
                    }
                } else {
                    if ((c == lf_)) {
                        break;
                    } else {
                        token_.append(&c, 1);
                    }
                }
            } else {
                more = false;
            }
        }
        return false;
    }
    virtual bool on_read_protocol_lf(reader_t& r) {
        ssize_t count = 0;
        char_t c = 0;
        for (bool more = true; more; ) {
            if (0 < (count = r.read(&c, sizeof(c)))) {
                if ((c == lf_)) {
                    line_.combine();
                    MEDUSA_LOG_MESSAGE_DEBUG("...read line = \"" << line_ << "\"");
                    on_read_ = &Derives::on_read_header;
                    return true;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        return false;
    }
    virtual bool on_read_header_token() {
        if (0 < (token_.length())) {
            MEDUSA_LOG_MESSAGE_DEBUG("...read header = \"" << token_ << "\"");
            token_reader_.reset();
            if ((header_reader_.read(token_reader_))) {
                MEDUSA_LOG_MESSAGE_DEBUG("...read header = \"" << header_ << "\"");
                headers_.append(&header_, 1);
                on_read_ = &Derives::on_read_header_lf;
                return true;
            }
        } else {
            header_list_t& headers = headers_.list();
            MEDUSA_LOG_MESSAGE_DEBUG("...read headers");
            for (header_iterator_t i = headers.begin(); i != headers.end(); ++i) {
                MEDUSA_LOG_MESSAGE_DEBUG("...header = \"" << (*i) << "\"");
            }
            on_read_ = &Derives::on_read_done_lf;
            return true;
        }
        return false;
    }
    virtual bool on_read_header(reader_t& r) {
        ssize_t count = 0;
        char_t c = 0;
        token_.clear();
        for (bool more = true; more; ) {
            if (0 < (count = r.read(&c, sizeof(c)))) {
                if ((c == cr_)) {
                    more = false;
                    if (on_read_header_token()) {
                        return true;
                    }
                } else {
                    if ((c == lf_)) {
                        break;
                    } else {
                        token_.append(&c, 1);
                    }
                }
            } else {
                more = false;
            }
        }
        return false;
    }
    virtual bool on_read_header_lf(reader_t& r) {
        ssize_t count = 0;
        char_t c = 0;
        for (bool more = true; more; ) {
            if (0 < (count = r.read(&c, sizeof(c)))) {
                if ((c == lf_)) {
                    on_read_ = &Derives::on_read_header;
                    return true;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        return false;
    }
    virtual bool on_read_done_lf(reader_t& r) {
        ssize_t count = 0;
        char_t c = 0;
        for (bool more = true; more; ) {
            if (0 < (count = r.read(&c, sizeof(c)))) {
                if ((c == lf_)) {
                    on_read_ = &Derives::on_read_done;
                    return true;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        return false;
    }
    virtual bool on_read_done(reader_t& r) {
        return true;
    }
    virtual bool on_read_fail(reader_t& r) {
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef bool (Derives::*on_read_t)(reader_t& r);

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t sp_, cr_, lf_;
    on_read_t on_read_;
    message_t& message_;
    line_t& line_;
    method_t& method_;
    parameters_t& parameters_;
    protocol_t& protocol_;
    protocol::readert<protocol_t> protocol_reader_;
    headers_t& headers_;
    header_t header_;
    xttp::message::header::readert<header_t> header_reader_;
    string_t token_;
    io::string::reader token_reader_;
};
typedef readert<> reader;

} // namespace request 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_REQUEST_READER_HPP 
