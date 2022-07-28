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
///   File: part.hpp
///
/// Author: $author$
///   Date: 10/27/2018
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_URL_PART_HPP
#define _MEDUSA_INET_HTTP_URL_PART_HPP

#include "medusa/base/string.hpp"
#include "medusa/io/writer.hpp"

namespace medusa {
namespace inet {
namespace http {
namespace url {

typedef io::string::writer part_writer;
typedef string_t::Implements part_implements;
typedef string_t part_extends;
///////////////////////////////////////////////////////////////////////
///  Class: part
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS part: virtual public part_implements, public part_extends {
public:
    typedef part_implements Implements;
    typedef part_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    part(const char_t* copy, size_t length): Extends(copy, length), writer_(*this) {}
    part(const char_t* copy): Extends(copy), writer_(*this) {}
    part(const string_t& copy): Extends(copy), writer_(*this) {}
    part(const part& copy): Extends(copy), writer_(*this) {}
    part(): writer_(*this) {}
    virtual ~part() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t clear_parts() { return 0; }
    virtual ssize_t combine_parts() { return 0; }
    virtual ssize_t separate_parts() { return 0; }
    virtual part_writer& writer() const { return ((part_writer&)writer_); }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    part_writer writer_;
}; /// class _EXPORT_CLASS part

} /// namespace url
} /// namespace http
} /// namespace inet
} /// namespace medusa

#endif ///ndef _MEDUSA_INET_HTTP_URL_PART_HPP
