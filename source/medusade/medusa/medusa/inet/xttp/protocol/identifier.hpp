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
///   File: identifier.hpp
///
/// Author: $author$
///   Date: 11/23/2014
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_PROTOCOL_IDENTIFIER_HPP
#define _MEDUSA_INET_XTTP_PROTOCOL_IDENTIFIER_HPP

#include "medusa/inet/xttp/protocol/name.hpp"
#include "medusa/inet/xttp/protocol/version.hpp"
#include "medusa/inet/xttp/xttp.hpp"
#include "medusa/io/logger.hpp"

#define MEDUSA_INET_XTTP_PROTOCOL_IDENTIFIER_NAME_VERSION_SEPARATOR '/'

namespace medusa {
namespace inet {
namespace xttp {
namespace protocol {

typedef string_implements identifier_implements;
typedef string_t identifier_extends;
///////////////////////////////////////////////////////////////////////
///  Class: identifiert
///////////////////////////////////////////////////////////////////////
template
<class TImplements = identifier_implements,
 class TExtends = identifier_extends>

class _EXPORT_CLASS identifiert: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef protocol::name name_t;
    typedef protocol::version version_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    identifiert
    (const name_t& name, const version_t& version)
    : name_version_separator_
      ((char_t)(MEDUSA_INET_XTTP_PROTOCOL_IDENTIFIER_NAME_VERSION_SEPARATOR)),
      name_(name), version_(version) {
        combine();
    }
    identifiert
    (const char_t* name, const version_t& version)
    : name_version_separator_
      ((char_t)(MEDUSA_INET_XTTP_PROTOCOL_IDENTIFIER_NAME_VERSION_SEPARATOR)),
      name_(name), version_(version) {
        combine();
    }
    identifiert
    (const char_t* name, const char_t* major, const char_t* minor)
    : name_version_separator_
      ((char_t)(MEDUSA_INET_XTTP_PROTOCOL_IDENTIFIER_NAME_VERSION_SEPARATOR)),
      name_(name), version_(major, minor) {
        combine();
    }
    identifiert
    (const char_t* name,
     char_t major = MEDUSA_INET_XTTP_PROTOCOL_VERSION_MAJOR,
     char_t minor = MEDUSA_INET_XTTP_PROTOCOL_VERSION_MINOR)
    : name_version_separator_
      ((char_t)(MEDUSA_INET_XTTP_PROTOCOL_IDENTIFIER_NAME_VERSION_SEPARATOR)),
      name_(name), version_(major, minor) {
        combine();
    }
    identifiert(const identifiert& copy)
    : Extends(copy),
      name_version_separator_
      ((char_t)(MEDUSA_INET_XTTP_PROTOCOL_IDENTIFIER_NAME_VERSION_SEPARATOR)),
      name_(copy.name_), version_(copy.version_) {
    }
    identifiert()
    : name_version_separator_
      ((char_t)(MEDUSA_INET_XTTP_PROTOCOL_IDENTIFIER_NAME_VERSION_SEPARATOR)) {
    }
    virtual ~identifiert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual identifiert& clear() {
        Extends::clear();
        name_.clear();
        version_.clear();
        return *this;
    }
    virtual identifiert& combine() {
        MEDUSA_LOG_DEBUG("name = \"" << name_ << "\"");
        this->assign(name_);
        this->append(&name_version_separator_, 1);
        MEDUSA_LOG_DEBUG("version = \"" << version_ << "\"");
        this->append(version_);
        MEDUSA_LOG_DEBUG("this = \"" << *this << "\"");
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual name_t& set_name(const char_t* to, size_t length) {
        name_.assign(to, length);
        combine();
        return name_;
    }
    virtual name_t& set_name(const char_t* to) {
        name_.assign(to);
        combine();
        return name_;
    }
    virtual name_t& name() const {
        return (name_t&)name_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual version_t& set_version(const version_t& to) {
        version_.set_major(to.major());
        version_.set_minor(to.minor());
        combine();
        return version_;
    }
    virtual version_t& version() const {
        return (version_t&)version_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t name_version_separator_;
    name_t name_;
    version_t version_;
};
typedef identifiert<> identifier;

} // namespace protocol 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_PROTOCOL_IDENTIFIER_HPP 
