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
///   File: field.hpp
///
/// Author: $author$
///   Date: 1/11/2015
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_FORM_FIELD_HPP
#define _MEDUSA_INET_HTTP_FORM_FIELD_HPP

#include "medusa/base/string.hpp"

namespace medusa {
namespace inet {
namespace http {
namespace form {

typedef implement_base field_implements;
typedef base field_extends;
///////////////////////////////////////////////////////////////////////
///  Class: fieldt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char_t, typename TEnd = int, TEnd VEnd = 0,
 class TString = xos::base::stringt<TChar, TEnd, VEnd>,
 class TImplements = field_implements, class TExtends = field_extends>

class _EXPORT_CLASS fieldt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TString string_t;
    typedef TChar char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    fieldt
    (const string_t& name, const string_t& value)
    : name_(name), value_(value) {
    }
    fieldt
    (const char_t* name, const char_t* value)
    : name_(name), value_(value) {
    }
    fieldt(const fieldt& copy)
    : name_(copy.name_), value_(copy.value_) {
    }
    fieldt() {
    }
    virtual ~fieldt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string_t& set_name(const char_t* chars, size_t length) {
        name_.assign(chars, length);
        return name_;
    }
    virtual string_t& set_name(const char_t* chars) {
        name_.assign(chars);
        return name_;
    }
    virtual string_t& name() const {
        return ((string_t&)name_);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string_t& set_value(const char_t* chars, size_t length) {
        value_.assign(chars, length);
        return value_;
    }
    virtual string_t& set_value(const char_t* chars) {
        value_.assign(chars);
        return value_;
    }
    virtual string_t& value() const {
        return ((string_t&)value_);
    }

#if defined(__MSC__)
	///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
	virtual bool operator == (const fieldt& to) {
		return !((this) != (&to));
	}
	virtual bool operator < (const fieldt& to) {
		return ((this) < (&to));
	}
#endif // defined(__MSC__)

	///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string_t name_, value_;
};
typedef fieldt<> field;

} // namespace form 
} // namespace http 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_HTTP_FORM_FIELD_HPP 
