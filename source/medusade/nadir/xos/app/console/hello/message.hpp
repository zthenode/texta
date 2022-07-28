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
///   File: message.hpp
///
/// Author: $author$
///   Date: 12/12/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_APP_CONSOLE_HELLO_MESSAGE_HPP
#define _XOS_NADIR_XOS_APP_CONSOLE_HELLO_MESSAGE_HPP

#include "xos/app/console/hello/base.hpp"

#include <list>

namespace xos {
namespace app {
namespace console {
namespace hello {

///////////////////////////////////////////////////////////////////////
///  Class: message
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS message: public string_t {
public:
    typedef string_t Extends;
    typedef message Derives;
    typedef std::list<string_t> list_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    message(): cr_((char_t)'\r'), lf_((char_t)'\n'), on_read_(0) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_write
    (const char_t* chars, size_t length, int argc, const char_t** argv) {
        if ((chars) && (length)) {
            if ((on_write_start())) {
                if ((on_write_line(chars, length))) {
                    for (int arg = 0; arg < argc; ++arg) {
                        if ((chars = argv[arg]) && (length = chars_t::count(chars))) {
                            if (!(on_write_header(chars, length))) {
                                return false;
                            }
                        }
                    }
                    if ((on_write_finish())) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_write_start() {
        this->clear();
        line_.clear();
        header_.clear();
        body_.clear();
        headers_.clear();
        on_read_ = 0;
        return true;
    }
    virtual bool on_write_finish() {
        const char_t* chars;
        size_t length;
        if ((chars = line_.has_chars(length))) {
            XOS_LOG_MESSAGE_DEBUG("...write line \"" << chars << "\"");
            this->assign(chars, length);
            this->append(&cr_, 1);
            this->append(&lf_, 1);
            if (0 < (headers_.size())) {
                list_t::const_iterator end = headers_.end();
                for (list_t::const_iterator i = headers_.begin(); i != end; ++i) {
                    const string_t& header = *i;
                    if ((chars = header.has_chars(length))) {
                        XOS_LOG_MESSAGE_DEBUG("...write header \"" << chars << "\"");
                        this->append(chars, length);
                        this->append(&cr_, 1);
                        this->append(&lf_, 1);
                    }
                }
            }
            this->append(&cr_, 1);
            this->append(&lf_, 1);
            if ((chars = body_.has_chars(length))) {
                XOS_LOG_MESSAGE_DEBUG("...write body \"" << chars << "\"");
                this->append(chars, length);
            }
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_write_line(const char_t* chars, size_t length) {
        if ((chars) && (length)) {
            line_.assign(chars, length);
            return true;
        }
        return false;
    }
    virtual bool on_write_header(const char_t* chars, size_t length) {
        if ((chars) && (length)) {
            header_.assign(chars, length);
            headers_.push_back(header_);
            return true;
        }
        return false;
    }
    virtual bool on_write_body(const char_t* chars, size_t length) {
        if ((chars) && (length)) {
            body_.assign(chars, length);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_read(const char_t* chars, size_t length) {
        if ((on_read_start())) {
            if ((on_read_finish(chars, length))) {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_read_start() {
        this->clear();
        line_.clear();
        header_.clear();
        body_.clear();
        headers_.clear();
        on_read_ = &Derives::on_read_line;
        return true;
    }
    virtual bool on_read_finish(const char_t* chars, size_t length) {
        if ((on_read_) && (chars) && (length)) {
            while (0 < (length)) {
                XOS_LOG_MESSAGE_TRACE("...on_read_finish \"" << string_t(chars,length) << "\"");
                if ((this->*on_read_)(chars, length)) {
                    on_read_ = 0;
                    return true;
                }
            }
            return false;
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_read_line(const char_t*& chars, size_t& length) {
        if ((chars)) {
            for (bool more = true; more && length; --length, ++chars) {
                this->append(chars, 1);
                if (cr_ != (*chars)) {
                    if (lf_ != (*chars)) {
                        line_.append(chars, 1);
                    } else {
                        XOS_LOG_MESSAGE_DEBUG("...read line \"" << line_ << "\"");
                        XOS_LOG_MESSAGE_DEBUG("...from \"" << *this << "\"");
                        return true;
                    }
                } else {
                    XOS_LOG_MESSAGE_TRACE("...cr in line");
                    on_read_ = &Derives::on_read_line_cr;
                    more = false;
                }
            }
        }
        return false;
    }
    virtual bool on_read_line_cr(const char_t*& chars, size_t& length) {
        if ((chars)) {
            for (bool more = true; more && length; --length, ++chars) {
                this->append(chars, 1);
                if (cr_ != (*chars)) {
                    if (lf_ != (*chars)) {
                        XOS_LOG_MESSAGE_DEBUG("...invalid char after cr in line");
                        return true;
                    } else {
                        XOS_LOG_MESSAGE_DEBUG("...read line \"" << line_ << "\"");
                        on_read_ = &Derives::on_read_header;
                        more = false;
                    }
                } else {
                    XOS_LOG_MESSAGE_DEBUG("...invalid cr after cr in line");
                    return true;
                }
            }
        }
        return false;
    }
    virtual bool on_read_header(const char_t*& chars, size_t& length) {
        if ((chars)) {
            for (bool more = true; more && length; --length, ++chars) {
                this->append(chars, 1);
                if (cr_ != (*chars)) {
                    if (lf_ != (*chars)) {
                        header_.append(chars, 1);
                    } else {
                        XOS_LOG_MESSAGE_DEBUG("...skipping lf in header");
                    }
                } else {
                    XOS_LOG_MESSAGE_TRACE("...cr in header");
                    on_read_ = &Derives::on_read_header_cr;
                    more = false;
                }
            }
        }
        return false;
    }
    virtual bool on_read_header_cr(const char_t*& chars, size_t& length) {
        if ((chars)) {
            for (bool more = true; more && length; --length, ++chars) {
                if (cr_ != (*chars)) {
                    if (lf_ != (*chars)) {
                        XOS_LOG_MESSAGE_DEBUG("...invalid char after cr in header");
                        return true;
                    } else {
                        if (0 < (header_.length())) {
                            XOS_LOG_MESSAGE_DEBUG("...read header \"" << header_ << "\"");
                            headers_.push_back(header_);
                            header_.clear();
                            on_read_ = &Derives::on_read_header;
                            more = false;
                        } else {
                            XOS_LOG_MESSAGE_DEBUG("...read end header");
                            XOS_LOG_MESSAGE_DEBUG("...from \"" << *this << "\"");
                            return true;
                        }
                    }
                } else {
                    XOS_LOG_MESSAGE_DEBUG("...invalid cr after cr in header");
                    return true;
                }
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string_t& line() const {
        return (string_t&)line_;
    }
    virtual string_t& body() const {
        return (string_t&)body_;
    }
    virtual list_t& headers() const {
        return (list_t&)headers_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef bool (Derives::*on_read_t)(const char_t*& chars, size_t& length);
protected:
    const char_t cr_, lf_;
    on_read_t on_read_;
    string_t line_, header_, body_;
    list_t headers_;
};

} // namespace hello
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_NADIR_XOS_APP_CONSOLE_HELLO_MESSAGE_HPP 
