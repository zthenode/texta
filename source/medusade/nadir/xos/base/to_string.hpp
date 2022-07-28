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
///   File: to_string.hpp
///
/// Author: $author$
///   Date: 5/23/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_TO_STRING_HPP
#define _XOS_BASE_TO_STRING_HPP

#include "xos/base/string.hpp"
#include "xos/base/types.hpp"

namespace xos {
namespace base {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS to_string: public string {
public:
    virtual operator const char *() const {
        return this->chars();
    }
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS signed_to_string: public to_string {
public:
    signed_to_string(signed value) {
        this->append_signed(value);
    }
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS unsigned_to_string: public to_string {
public:
    unsigned_to_string(unsigned value) {
        this->append_unsigned(value);
    }
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS bool_to_string: public to_string {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    bool_to_string(bool is_true) {
        this->append((is_true)?("true"):("false"));
    }
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS pointer_to_string: public to_string {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    pointer_to_string(const void* p) {
        this->append("0x");
        this->appendx(&p, sizeof(void*));
    }
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS chars_to_string: public to_string {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    chars_to_string(const char* chars, size_t length) {
        if ((chars)) {
            this->append("\"");
            this->append(chars, length);
            this->append("\"");
        } else {
            this->append("NULL");
        }
    }
    chars_to_string(const char* chars) {
        if ((chars)) {
            this->append("\"");
            this->append(chars);
            this->append("\"");
        } else {
            this->append("NULL");
        }
    }
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TEnd = TChar, TEnd VEnd = 0,
 class TExtends = stringt<TChar, TEnd, VEnd> >

class _EXPORT_CLASS char_to_stringt: public string {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    char_to_stringt(wchar_t c) {
        char cc = (char)c;
        if ((32 <= cc) && (127 >= cc)) {
            this->append("'");
            this->append(&cc, 1);
            this->append("'");
        } else {
            this->append("[");
            this->append_unsigned(c);
            this->append("]");
        }
    }
    char_to_stringt(char c) {
        if ((32 <= c) && (127 >= c)) {
            this->append("'");
            this->append(&c, 1);
            this->append("'");
        } else {
            this->append("[");
            this->append_unsigned(c);
            this->append("]");
        }
    }
    virtual operator const TChar *() const {
        return this->chars();
    }
};
typedef char_to_stringt<char> char_to_string;
typedef char_to_stringt<wchar_t> char_to_wstring;
typedef char_to_stringt<tchar_t> char_to_tstring;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS x_to_string: public to_string {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    x_to_string(const void* data, size_t length, bool upper_case = false) {
        if ((data)) {
            this->appendx(data, length, upper_case);
        }
    }
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS X_to_string: public to_string {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    X_to_string(const void* data, size_t length, bool upper_case = true) {
        if ((data)) {
            this->appendx(data, length, upper_case);
        }
    }
};

} // namespace base

typedef base::bool_to_string bool_to_string;
typedef base::char_to_string char_to_string;
typedef base::chars_to_string chars_to_string;
typedef base::pointer_to_string pointer_to_string;
typedef base::signed_to_string signed_to_string;
typedef base::unsigned_to_string unsigned_to_string;

} // namespace xos 

#endif // _XOS_BASE_TO_STRING_HPP 
