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
///   Date: 12/20/2018
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_NADIR_IO_READER_HPP
#define _MEDUSA_NADIR_IO_READER_HPP

#include "medusa/nadir/io/sequence.hpp"
#include "medusa/base/string.hpp"
#include "nadir/io/reader.hpp"
#include "nadir/io/string.hpp"

namespace medusa {
namespace io {

typedef ::nadir::io::reader reader;
typedef ::nadir::io::byte_reader byte_reader;
typedef ::nadir::io::char_reader char_reader;
typedef ::nadir::io::wchar_reader wchar_reader;
typedef ::nadir::io::tchar_reader tchar_reader;

/*
namespace string {
typedef reader reader_implements;
typedef base reader_extends;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<typename TString,
 class TImplements = reader_implements, class TExtends = reader_extends>

class _EXPORT_CLASS readert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TString string_t;
    typedef typename TString::char_t char_t;
    typedef typename TImplements::what_t what_t;
    typedef typename TImplements::sized_t sized_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    readert(const string_t& string)
    : string_(string), tell_(0) {
    }
    virtual ~readert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read(what_t* what, size_t size) {
        size_t  length = string_.length();
        sized_t* sized = 0;
        if ((sized = ((sized_t*)what)) && (size) && (length > (tell_))) {
            const char_t* chars = 0;
            if (length < (tell_ + size)) {
                if (1 > (size = length - tell_)) {
                    return 0;
                }
            }
            if ((chars = string_.chars())) {
                ssize_t count = 0;
                if ((sizeof(sized_t) == sizeof(char_t))) {
                    for (chars += tell_; size; --size, ++chars, ++sized, ++count) {
                        *sized = *(((const sized_t*)chars));
                    }
                }
                tell_ += count;
                return count;
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t reset() {
        ssize_t told = tell_;
        tell_ = 0;
        return told;
    }
    virtual ssize_t seek(size_t to) {
        size_t length = string_.length();
        if (length < (to)) {
            to = length;
        }
        tell_ = to;
        return tell_;
    }
    virtual ssize_t tell() const {
        return tell_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const string_t& string_;
    size_t tell_;
};
} /// namespace string
*/

namespace string {
typedef ::nadir::io::string::readert<string_t> reader;
} /// namespace string

namespace bstring {
typedef ::nadir::io::string::readert<bstring_t> reader;
} /// namespace bstring

} /// namespace io
} /// namespace medusa

#endif /// ndef _MEDUSA_NADIR_IO_READER_HPP
