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
///   File: writer.hpp
///
/// Author: $author$
///   Date: 12/20/2018
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_NADIR_IO_WRITER_HPP
#define _MEDUSA_NADIR_IO_WRITER_HPP

#include "medusa/nadir/io/sequence.hpp"
#include "medusa/base/string.hpp"
#include "nadir/io/writer.hpp"
#include "nadir/io/string.hpp"

namespace medusa {
namespace io {

typedef ::nadir::io::writer writer;
typedef ::nadir::io::byte_writer byte_writer;
typedef ::nadir::io::char_writer char_writer;
typedef ::nadir::io::wchar_writer wchar_writer;
typedef ::nadir::io::tchar_writer tchar_writer;

/*
namespace string {
typedef writer writer_implements;
typedef base writer_extends;
///////////////////////////////////////////////////////////////////////
///  Class: writert
///////////////////////////////////////////////////////////////////////
template
<typename TString,
 class TImplements = writer_implements, class TExtends = writer_extends>

class _EXPORT_CLASS writert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TString string_t;
    typedef typename string_t::char_t char_t;
    typedef typename Implements::what_t what_t;
    typedef typename Implements::sized_t sized_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    writert(string_t& string)
    : string_(string) {
    }
    virtual ~writert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t write(const what_t* what, ssize_t size = -1) {
        const sized_t* sized = 0;
        if ((0 != (size)) && (sized = ((const sized_t*)what))) {
            if (0 > (size)) {
                size_t length = string_.length();
                string_.append(sized);
                return string_.length() - length;
            } else {
                string_.append(sized, size);
                return size;
            }
        }
        return 0;
    }
    virtual ssize_t writefv(const what_t* format, va_list va) {
        ssize_t count = 0;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string_t& string_;
};
} /// namespace string
*/

namespace string {
typedef ::nadir::io::string::writert<string_t> writer;
} /// namespace string

namespace bstring {
typedef ::nadir::io::string::writert<bstring_t> writer;
} /// namespace bstring

} /// namespace io
} /// namespace medusa

#endif /// ndef _MEDUSA_NADIR_IO_WRITER_HPP
