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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 2/17/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_STRING_READER_HPP
#define _XOS_NADIR_XOS_IO_STRING_READER_HPP

#include "xos/io/reader.hpp"
#include "xos/io/told.hpp"
#include "xos/base/string.hpp"

namespace xos {
namespace io {
namespace string {

typedef io::reader readert_implements;
typedef io::toldt<readert_implements> readert_extends;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<typename TString = base::string,
 class TImplements = readert_implements, class TExtends = readert_extends>

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
    readert(const readert& copy): Extends(copy), string_(copy.string_) {
    }
    readert(const string_t& string): string_(string) {
    }
    virtual ~readert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read(what_t* what, size_t size) {
        size_t  length = this->length();
        sized_t* sized = 0;
        if ((sized = ((sized_t*)what)) && (size) && (length > (this->tell_))) {
            const char_t* chars = 0;
            if (length < (this->tell_ + size)) {
                if (1 > (size = length - this->tell_)) {
                    return 0;
                }
            }
            if ((chars = string_.chars())) {
                ssize_t count = 0;
                if ((sizeof(sized_t) == sizeof(char_t))) {
                    for (chars += this->tell_; size; --size, ++chars, ++sized, ++count) {
                        *sized = *(((const sized_t*)chars));
                    }
                }
                this->tell_ += count;
                return count;
            }
        }
        return 0;
    }
    virtual size_t length() const {
        size_t length = string_.length();
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const string_t& string_;
};
typedef readert<> reader;

} // namespace string 
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_STRING_READER_HPP 
