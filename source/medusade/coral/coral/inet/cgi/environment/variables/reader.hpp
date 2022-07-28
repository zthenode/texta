///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2015 $organization$
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
///   Date: 1/26/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_INET_CGI_ENVIRONMENT_VARIABLES_READER_HPP
#define _CORAL_INET_CGI_ENVIRONMENT_VARIABLES_READER_HPP

#include "coral/inet/cgi/environment/variables/values.hpp"
#include "coral/io/reader.hpp"

namespace coral {
namespace inet {
namespace cgi {
namespace environment {
namespace variables {

typedef implement_base reader_implements;
typedef base reader_extends;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char_t,
 typename TWhat = void,
 class TString = xos::base::stringt<TChar>,
 class TReader = xos::io::readert<TWhat, TChar>,
 typename TWhich = variable::which_t,
 TWhich VFirst = variable::first, TWhich VLast = variable::last,
 class TName = variable::namet<TChar, TWhich>,
 class TValues = valuest<TChar, TWhich, VFirst, VLast>,
 class TImplements = reader_implements, class TExtends = reader_extends>

class _EXPORT_CLASS readert: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef readert Derives;

    typedef typename TValues::value_t value_t;
    typedef TName name_t;
    typedef TValues values_t;
    typedef TWhich which_t;
    enum { first = VFirst, last = VLast };
    typedef TReader reader_t;
    typedef TString string_t;
    typedef TChar char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    readert()
    : eq_((char_t)'='),
      cr_((char_t)'\r'),
      lf_((char_t)'\n'),
      on_read_(0),
      values_(0),
      value_(0) {
    }
    virtual ~readert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read(values_t& values, reader_t& reader) {
        ssize_t count = 0;
        ssize_t amount;
        char_t c;

        name_.clear();
        values_ = &values;
        value_ = 0;
        on_read_ = &Derives::on_read_name;

        for (amount = 1; amount; count += amount) {
            if (0 > (amount = reader.read(&c, 1))) {
                values_ = 0; value_ = 0;
                return amount;
            } else {
                if (0 < (amount)) {
                    if (!(on_read(c))) {
                        values_ = 0; value_ = 0;
                        return 0;
                    }
                }
            }
        }
        values_ = 0; value_ = 0;
        return count;
    }

protected:
    typedef bool (Derives::*on_read_t)(const char_t& c);
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
                    CORAL_LOG_ERROR("...invalid char '" << string_t(&c,1) << "'");
                    return false;
                }
            } else {
                on_read_ = &Derives::on_read_name_cr;
            }
        } else {
            value_t* value = 0;
            if ((value = value_of(values_, name_))) {
                name_.clear();
                value->clear();
                value_ = value;
                on_read_ = &Derives::on_read_value;
            } else {
                CORAL_LOG_ERROR("...failed on value_of(..., \"" << name_ << "\")");
                name_.clear();
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
                        value_t* value = 0;
                        if ((value = value_of(values_, name_))) {
                            name_.clear();
                            value->clear();
                            on_read_ = &Derives::on_read_name;
                        } else {
                            CORAL_LOG_ERROR("...failed on value_of(..., \"" << name_ << "\")");
                            name_.clear();
                            return false;
                        }
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
            if ((value_)) {
                value_->append(&c, 1);
            } else {
                return false;
            }
        } else {
            value_->set();
            CORAL_LOG_DEBUG("...value = \"" << value_->chars() << "\"");
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
                on_read_ = &Derives::on_read_name;
            }
        } else {
            CORAL_LOG_ERROR("...invalid char '" << string_t(&c,1) << "'");
            return false;
        }
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual value_t* value_of(values_t* values, const string_t& named) {
        const char_t* chars = 0;
        CORAL_LOG_DEBUG("value_of(..., \"" << named << "\")...");
        if ((values) && (chars = named.has_chars())) {
            return (*values)[chars];
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t eq_, cr_, lf_;
    on_read_t on_read_;
    string_t name_;
    values_t* values_;
    value_t* value_;
};
typedef readert<> reader;

} // namespace variables 
} // namespace environment 
} // namespace cgi 
} // namespace inet 
} // namespace coral 

#endif // _CORAL_INET_CGI_ENVIRONMENT_VARIABLES_READER_HPP 
