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
///   File: version.hpp
///
/// Author: $author$
///   Date: 11/23/2014
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_PROTOCOL_VERSION_HPP
#define _MEDUSA_INET_XTTP_PROTOCOL_VERSION_HPP

#include "medusa/base/string.hpp"
#include "medusa/io/logger.hpp"

#define MEDUSA_INET_XTTP_PROTOCOL_VERSION_MAJOR_MINOR_SEPARATOR '.'
#define MEDUSA_INET_XTTP_PROTOCOL_VERSION_MAJOR '1'
#define MEDUSA_INET_XTTP_PROTOCOL_VERSION_MINOR '0'

namespace medusa {
namespace inet {
namespace xttp {
namespace protocol {

typedef string_implements version_implements;
typedef string_t version_extends;
///////////////////////////////////////////////////////////////////////
///  Class: versiont
///////////////////////////////////////////////////////////////////////
template
<class TImplements = version_implements, class TExtends = version_extends>

class _EXPORT_CLASS versiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    versiont
    (const char_t* major, const char_t* minor)
    : major_minor_separator_
      ((char_t)(MEDUSA_INET_XTTP_PROTOCOL_VERSION_MAJOR_MINOR_SEPARATOR)),
      major_(major), minor_(minor) {
        combine();
    }
    versiont(const versiont& copy)
    : Extends(copy),
      major_minor_separator_
      ((char_t)(MEDUSA_INET_XTTP_PROTOCOL_VERSION_MAJOR_MINOR_SEPARATOR)),
      major_(copy.major_), minor_(copy.minor_) {
    }
    versiont
    (char_t major = MEDUSA_INET_XTTP_PROTOCOL_VERSION_MAJOR,
     char_t minor = MEDUSA_INET_XTTP_PROTOCOL_VERSION_MINOR)
    : major_minor_separator_
      ((char_t)(MEDUSA_INET_XTTP_PROTOCOL_VERSION_MAJOR_MINOR_SEPARATOR)),
      major_(&major, 1), minor_(&minor, 1) {
        combine();
    }
    virtual ~versiont() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual versiont& combine() {
        MEDUSA_LOG_DEBUG("major = \"" << major_ << "\"");
        this->assign(major_);
        this->append(&major_minor_separator_, 1);
        MEDUSA_LOG_DEBUG("minor = \"" << minor_ << "\"");
        this->append(minor_);
        MEDUSA_LOG_DEBUG("this = \"" << *this << "\"");
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string_t& set_major(const string_t& to) {
        major_.assign(to);
        combine();
        return major_;
    }
    virtual string_t& set_major(const char_t* to, size_t length) {
        major_.assign(to, length);
        combine();
        return major_;
    }
    virtual string_t& set_major(const char_t* to) {
        major_.assign(to);
        combine();
        return major_;
    }
    virtual string_t& set_major(char_t to) {
        major_.assign(&to, 1);
        combine();
        return major_;
    }
    virtual string_t& major() const {
        return (string_t&)major_;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual string_t& set_minor(const string_t& to) {
        minor_.assign(to);
        combine();
        return major_;
    }
    virtual string_t& set_minor(const char_t* to, size_t length) {
        minor_.assign(to, length);
        combine();
        return minor_;
    }
    virtual string_t& set_minor(const char_t* to) {
        minor_.assign(to);
        combine();
        return minor_;
    }
    virtual string_t& set_minor(char_t to) {
        minor_.assign(&to, 1);
        combine();
        return minor_;
    }
    virtual string_t& minor() const {
        return (string_t&)minor_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t major_minor_separator_;
    string_t major_, minor_;
};
typedef versiont<> version;

} // namespace protocol 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_PROTOCOL_VERSION_HPP 
