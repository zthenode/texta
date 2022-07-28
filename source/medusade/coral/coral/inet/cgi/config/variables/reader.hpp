///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   Date: 11/5/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_INET_CGI_CONFIG_VARIABLES_READER_HPP
#define _CORAL_INET_CGI_CONFIG_VARIABLES_READER_HPP

#include "coral/base/string.hpp"
#include "coral/io/reader.hpp"
#include "coral/io/logger.hpp"

namespace coral {
namespace inet {
namespace cgi {
namespace config {
namespace variables {

typedef coral::string_t::char_t char_t;
typedef coral::string_t string_t;
typedef implement_base reader_eventst_implements;
///////////////////////////////////////////////////////////////////////
///  Class: reader_eventst
///////////////////////////////////////////////////////////////////////
template <class TImplements = reader_eventst_implements>

class _EXPORT_CLASS reader_eventst: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_config_variable(const string_t& name, const string_t& value) {
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS reader_eventst

typedef reader_eventst<> reader_events;

typedef io::reader readert_reader;
typedef reader_events readert_events;
typedef base readert_extends;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template 
<class TReader = readert_reader,
 class TImplements = readert_events, class TExtends = readert_extends>

class _EXPORT_CLASS readert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef readert Derives;

    typedef Implements events_t;
    typedef TReader reader_t;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    readert(events_t& events)
    : events_(events),
      eq_((char_t)'='), 
      cr_((char_t)'\r'), 
      lf_((char_t)'\n'), 
      on_read_(0) {
    }
    readert(const readert& copy)
    : events_(*this),
      eq_((char_t)'='), 
      cr_((char_t)'\r'), 
      lf_((char_t)'\n'), 
      on_read_(0) {
    }
    readert()
    : events_(*this),
      eq_((char_t)'='), 
      cr_((char_t)'\r'), 
      lf_((char_t)'\n'), 
      on_read_(0) {
    }
    virtual ~readert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read(reader_t& reader) {
        ssize_t count = 0, amount = 0;
        char_t c = 0;
        
        name_.clear();
        value_.clear();
        on_read_ = &Derives::on_read_name;

        for (amount = 1; amount; count += amount) {
            if (0 > (amount = reader.read(&c, 1))) {
                return amount;
            } else {
                if (0 < (amount)) {
                    if (!(on_read(c))) {
                        return 0;
                    }
                    count += amount;
                }
            }
        }
        return count;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t on_read(const char_t& c) {
        if ((on_read_)) {
            return (this->*on_read_)(c);
        }
        return true;
    }
    virtual bool on_read_name(const char_t& c) {
        if ((c != eq_)) {
            if ((c != cr_)) {
                if ((c != lf_)) {
                    name_.append(&c, 1);
                } else {
                    if (0 < (name_.length())) {
                        CORAL_LOG_DEBUG("on_config_variable(name_ = \"" << name_.chars() << "\", value_ = \"" << value_.chars() << "\")...");
                        if ((on_config_variable(name_, value_))) {
                            name_.clear();
                            on_read_ = &Derives::on_read_name;
                        } else {
                            CORAL_LOG_ERROR("...failed on on_config_variable(name_, value_)");
                            return false;
                        }
                    } else {
                        CORAL_LOG_ERROR("...failed on (0 < (name_.length()))");
                        return false;
                    }
                }
            } else {
                on_read_ = &Derives::on_read_name_cr;
            }
        } else {
            if (0 < (name_.length())) {
                on_read_ = &Derives::on_read_value;
            } else {
                CORAL_LOG_ERROR("...failed on (0 < (name_.length()))");
                return false;
            }
        }
        return true;
    }
    virtual bool on_read_name_cr(const char_t& c) {
        if ((c != eq_)) {
            if ((c != cr_)) {
                if ((c != lf_)) {
                    CORAL_LOG_ERROR("...invalid char '" << string_t(&c,1) << "'");
                    return false;
                } else {
                    if (0 < (name_.length())) {
                        CORAL_LOG_DEBUG("on_config_variable(name_ = \"" << name_.chars() << "\", value_ = \"" << value_.chars() << "\")...");
                        if ((on_config_variable(name_, value_))) {
                            name_.clear();
                            on_read_ = &Derives::on_read_name;
                        } else {
                            CORAL_LOG_ERROR("...failed on on_config_variable(name_, value_)");
                            return false;
                        }
                    } else {
                        CORAL_LOG_ERROR("...failed on (0 < (name_.length()))");
                        return false;
                    }
                }
            } else {
                CORAL_LOG_ERROR("...invalid char '" << string_t(&c,1) << "'");
                return false;
            }
        } else {
            CORAL_LOG_ERROR("...invalid char '" << string_t(&c,1) << "'");
            return false;
        }
        return true;
    }
    virtual bool on_read_value(const char_t& c) {
        if ((c != cr_)) {
            if ((c != lf_)) {
                value_.append(&c, 1);
            } else {
                CORAL_LOG_DEBUG("on_config_variable(name_ = \"" << name_.chars() << "\", value_ = \"" << value_.chars() << "\")...");
                if ((on_config_variable(name_, value_))) {
                    name_.clear();
                    value_.clear();
                    on_read_ = &Derives::on_read_name;
                } else {
                    CORAL_LOG_ERROR("...failed on on_config_variable(name_, value_)");
                    return false;
                }
            }
        } else {
            CORAL_LOG_DEBUG("...value = \"" << value_.chars() << "\"");
            on_read_ = &Derives::on_read_value_cr;
        }
        return true;
    }
    virtual bool on_read_value_cr(const char_t& c) {
        if ((c != cr_)) {
            if ((c != lf_)) {
                CORAL_LOG_ERROR("...invalid char '" << string_t(&c,1) << "'");
                return false;
            } else {
                CORAL_LOG_DEBUG("on_config_variable(name_ = \"" << name_.chars() << "\", value_ = \"" << value_.chars() << "\")...");
                if ((on_config_variable(name_, value_))) {
                    name_.clear();
                    value_.clear();
                    on_read_ = &Derives::on_read_name;
                } else {
                    CORAL_LOG_ERROR("...failed on on_config_variable(name_, value_)");
                    return false;
                }
            }
        } else {
            CORAL_LOG_ERROR("...invalid char '" << string_t(&c,1) << "'");
            return false;
        }
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_config_variable(const string_t& name, const string_t& value) {
        if ((&events_ != this)) {
            return events_.on_config_variable(name, value);
        }
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    events_t& events_;
    const char_t eq_, cr_, lf_;
    bool (Derives::*on_read_)(const char_t& c);
    string_t name_, value_;
}; /// class _EXPORT_CLASS reader

typedef readert<> reader;

} /// namespace variables
} /// namespace config
} /// namespace cgi
} /// namespace inet
} /// namespace coral

#endif ///ndef _CORAL_INET_CGI_CONFIG_VARIABLES_READER_HPP
