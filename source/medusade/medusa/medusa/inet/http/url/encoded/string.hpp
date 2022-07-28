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
///   File: string.hpp
///
/// Author: $author$
///   Date: 10/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_URL_ENCODED_STRING_HPP
#define _MEDUSA_INET_HTTP_URL_ENCODED_STRING_HPP

#include "medusa/base/string.hpp"
#include "medusa/inet/http/url/encoded/reader.hpp"
#include "medusa/inet/http/url/encoded/writer.hpp"
#include "xos/io/string/reader.hpp"
#include "xos/io/string/writer.hpp"

namespace medusa {
namespace inet {
namespace http {
namespace url {
namespace encoded {

typedef reader stringt_reader;
typedef writer stringt_writer;
typedef ::xos::io::string::readert<string_t> stringt_string_reader;
typedef ::xos::io::string::writert<string_t> stringt_string_writer;
typedef ::medusa::string_t_implements stringt_implements;
typedef ::medusa::string_t stringt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: stringt
///////////////////////////////////////////////////////////////////////
template 
<class TReader = stringt_reader, class TWriter = stringt_writer,
 class TStringReader = stringt_string_reader, class TStringWriter = stringt_string_writer,
 class TImplements = stringt_implements, class TExtends = stringt_extends>

class _EXPORT_CLASS stringt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    
    typedef Extends string_t;
    typedef TReader reader_t;
    typedef TWriter writer_t;
    typedef TStringReader string_reader_t;
    typedef TStringWriter string_writer_t;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    stringt(const char_t* copy, size_t length): Extends(copy, length) {}
    stringt(const char_t* copy): Extends(copy) {}
    stringt(const string_t& copy): Extends(copy) {}
    stringt(const stringt& copy): Extends(copy) {}
    stringt() {}
    virtual ~stringt() {}

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual stringt& encode(const string_t& from) {
        string_writer_t writer(*this);
        writer_t encoder(writer);
        const char_t* chars = 0;
        size_t length = 0;
        this->clear();
        if ((chars = from.has_chars(length))) {
            encoder.write(chars, length);
        }
        return *this;
    }
    virtual stringt& encode(const char_t* chars, size_t length) {
        string_writer_t writer(*this);
        writer_t encoder(writer);
        this->clear();
        if ((chars) && (length)) {
            encoder.write(chars, length);
        }
        return *this;
    }
    virtual stringt& encode(const char_t* chars) {
        string_writer_t writer(*this);
        writer_t encoder(writer);
        this->clear();
        if ((chars)) {
            encoder.write(chars);
        }
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual stringt& decode(string_t& to) {
        string_reader_t reader(*this);
        reader_t decoder(reader);
        char_t c = 0;
        to.clear();
        while (0 < (decoder.read(&c, 1))) {
            to.append(&c, 1);
        }
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS stringt

typedef stringt<> string;

} /// namespace encoded
} /// namespace url
} /// namespace http
} /// namespace inet
} /// namespace medusa

#endif ///ndef _MEDUSA_INET_HTTP_URL_ENCODED_STRING_HPP
