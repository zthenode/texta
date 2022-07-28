///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   Date: 8/4/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_STRING_WRITER_HPP
#define _XOS_NADIR_XOS_IO_STRING_WRITER_HPP

#include "xos/io/writer.hpp"
#include "xos/base/string.hpp"
#include "xos/base/array.hpp"

namespace xos {
namespace io {
namespace string {

typedef io::writer writer_implements;
typedef base::base writer_extends;
///////////////////////////////////////////////////////////////////////
///  Class: writert
///////////////////////////////////////////////////////////////////////
template
<typename TString = base::string,
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
typedef writert<> writer;

typedef writert<base::wstring, io::wchar_writer> wchar_writer;
typedef writert<base::tstring, io::tchar_writer> tchar_writer;

typedef writert<base::string, io::char_writer> char_writer_extends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS char_writer: public char_writer_extends {
public:
    typedef char_writer_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    char_writer(string_t& string): Extends(string) {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t writefv(const char* format, va_list va) {
        ssize_t count = 0;
        size_t length = 0;
        char* chars = 0;
        va_list va0;
        va_copy(va0, va);
        if ((chars = chars_.elements())) {
            if (0 < (length = vsnprintf(chars, 0, format, va0))) {
                if (length < chars_.set_length(length+1)) {
                    if ((chars = chars_.elements())) {
                        if (0 < (length = vsnprintf(chars, length+1, format, va))) {
                            count = this->write(chars, length);
                        }
                    }
                }
            }
        }
        va_end(va0);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    xos::base::char_array chars_;
};

} // namespace string 
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_STRING_WRITER_HPP 
