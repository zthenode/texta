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
///   File: value.hpp
///
/// Author: $author$
///   Date: 12/31/2014
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_INET_CGI_ENVIRONMENT_VARIABLE_VALUE_HPP
#define _CORAL_INET_CGI_ENVIRONMENT_VARIABLE_VALUE_HPP

#include "coral/inet/cgi/environment/variable/name.hpp"
#include "coral/inet/cgi/environment/variable/which.hpp"

namespace coral {
namespace inet {
namespace cgi {
namespace environment {
namespace variable {

typedef implement_base value_implements;
///////////////////////////////////////////////////////////////////////
///  Class: valuet
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char_t,
 typename TWhich = which_t,
 typename TChars = xos::base::typest<TChar>,
 typename TString = xos::base::stringt<TChar>,
 typename TName = namet<TChar, TWhich>,
 class TExtends = xos::base::wrappedt<const TChar*>,
 class TImplements = value_implements>

class _EXPORT_CLASS valuet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TName name_t;
    typedef TWhich which_t;
    typedef TChar char_t;
    typedef TChars chars_t;
    typedef TString string_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    valuet(which_t which) {
        this->get(which);
    }
    valuet(const valuet& copy): Extends(copy) {
    }
    valuet() {
    }
    virtual ~valuet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual valuet& get(which_t which) {
        const char_t* of;
        this->wrapped_ = 0;
        if ((of = name_t::of(which))) {
            if ((this->wrapped_ = getenv(of))) {
                chars_.assign(this->wrapped_);
                this->wrapped_ = chars_.chars();
            }
        }
        return *this;
    }
    virtual valuet& set() {
        this->wrapped_ = chars_.chars();
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual valuet& append(const char_t* chars, size_t length) {
        chars_.append(chars, length);
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual valuet& clear() {
        chars_.clear();
        this->wrapped_ = 0;
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* has_chars(size_t& length) const {
        const char_t* chars;
        if ((chars = this->wrapped_) && (chars[0])) {
            length = chars_.length();
            return chars;
        }
        return 0;
    }
    virtual const char_t* has_chars() const {
        const char_t* chars;
        if ((chars = this->wrapped_) && (chars[0])) {
            return chars;
        }
        return 0;
    }
    virtual const char_t* chars(size_t& length) const {
        const char_t* chars;
        if ((chars = this->wrapped_)) {
            length = chars_.length();
            return chars;
        }
        return 0;
    }
    virtual const char_t* chars() const {
        const char_t* chars;
        if ((chars = this->wrapped_)) {
            return chars;
        }
        return 0;
    }
    virtual ssize_t length() const {
        if ((this->wrapped_)) {
            return chars_.length();
        }
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual valuet& operator = (which_t which) {
        this->get(which);
        return *this;
    }
    virtual valuet& operator = (const string_t& chars) {
        chars_ = chars;
        this->wrapped_ = chars_.chars();
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string_t chars_;
};
typedef valuet<> value;

} // namespace variable 
} // namespace environment 
} // namespace cgi 
} // namespace inet 
} // namespace coral 

#endif // _CORAL_INET_CGI_ENVIRONMENT_VARIABLE_VALUE_HPP 
        

