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
///   File: string.hpp
///
/// Author: $author$
///   Date: 8/23/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_STRING_HPP
#define _XOS_NADIR_XOS_BASE_STRING_HPP

#include "xos/base/types.hpp"
#include "xos/base/base.hpp"
#include <string>

namespace xos {
namespace base {

typedef implement_base string_implements;
///////////////////////////////////////////////////////////////////////
///  Class: string_implementt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, 
 typename TEnd = TChar, TEnd VEnd = 0,
 class TImplements = string_implements>

class _EXPORT_CLASS string_implementt: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TChar Char;
    typedef Char char_t;
    enum { EndChar = VEnd, end_char = VEnd };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef std::basic_string<char> string_extends;
typedef std::basic_string<tchar_t> tstring_extends;
typedef std::basic_string<wchar_t> wstring_extends;
///////////////////////////////////////////////////////////////////////
///  Class: stringt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TEnd = TChar, TEnd VEnd = 0,
 class TExtends = std::basic_string<TChar>, class TImplements = string_implements>

class _EXPORT_CLASS stringt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TChar Char;
    typedef Char char_t;

    using TExtends::append;
    using TExtends::assign;
    using TExtends::compare;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    stringt(const wchar_t* chars, size_t length) {
        this->append(chars, length);
    }
    stringt(const wchar_t* chars) {
        this->append(chars);
    }
    stringt(const char* chars, size_t length) {
        this->append(chars, length);
    }
    stringt(const char* chars) {
        this->append(chars);
    }
    stringt(ssize_t value) {
        this->append_ssize(value);
    }
    stringt(size_t value) {
        this->append_size(value);
    }
    stringt(const wstring_extends& copy) {
        this->append(copy.c_str());
    }
    stringt(const string_extends& copy) {
        this->append(copy.c_str());
    }
    stringt(const stringt& copy): Extends(copy) {
    }
    stringt() {
    }
    virtual ~stringt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual stringt& assign() {
        this->clear();
        return *this;
    }

    // wchar_t
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual stringt& assign(const wchar_t* chars) {
        this->clear();
        this->append(chars);
        return *this;
    }
    virtual stringt& assign(const wchar_t* chars, size_t length) {
        this->clear();
        this->append(chars);
        return *this;
    }
    virtual stringt& append(const wchar_t* chars) {
        if ((chars)) {
            for (wchar_t c = *chars; c != 0; c = *(++chars)) {
                TChar tc = ((TChar)c);
                Extends::append(&tc, 1);
            }
        }
        return *this;
    }
    virtual stringt& append(const wchar_t* chars, size_t length) {
        if ((chars) && (length)) {
            for (; length > 0; --length, ++chars) {
                TChar tc = ((TChar)(*chars));
                Extends::append(&tc, 1);
            }
        }
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual stringt& assignl(const wchar_t* chars, ...) {
        this->clear();
        if ((chars)) {
            va_list va;
            va_start(va, chars);
            this->appendv(chars, va);
            va_end(va);
        }
        return *this;
    }
    virtual stringt& assignv(const wchar_t* chars, va_list va) {
        this->clear();
        if ((chars)) {
            this->appendv(chars, va);
        }
        return *this;
    }
    virtual stringt& appendl(const wchar_t* chars, ...) {
        if ((chars)) {
            va_list va;
            va_start(va, chars);
            this->appendv(chars, va);
            va_end(va);
        }
        return *this;
    }
    virtual stringt& appendv(const wchar_t* chars, va_list va) {
        if ((chars)) {
            do {
                this->append(chars);
            } while ((chars = va_arg(va, const wchar_t*)));
        }
        return *this;
    }

    // char
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual stringt& assign(const char* chars) {
        this->clear();
        this->append(chars);
        return *this;
    }
    virtual stringt& assign(const char* chars, size_t length) {
        this->clear();
        this->append(chars, length);
        return *this;
    }
    virtual stringt& append(const char* chars) {
        if ((chars)) {
            for (char c = *chars++; c != 0; c = *chars++) {
                TChar tc = ((TChar)c);
                Extends::append(&tc, 1);
            }
        }
        return *this;
    }
    virtual stringt& append(const char* chars, size_t length) {
        if ((chars) && (length)) {
            for (; length > 0; --length, ++chars) {
                TChar tc = ((TChar)(*chars));
                Extends::append(&tc, 1);
            }
        }
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual stringt& assignl(const char* chars, ...) {
        this->clear();
        if ((chars)) {
            va_list va;
            va_start(va, chars);
            this->appendv(chars, va);
            va_end(va);
        }
        return *this;
    }
    virtual stringt& assignv(const char* chars, va_list va) {
        this->clear();
        if ((chars)) {
            this->appendv(chars, va);
        }
        return *this;
    }
    virtual stringt& appendl(const char* chars, ...) {
        if ((chars)) {
            va_list va;
            va_start(va, chars);
            this->appendv(chars, va);
            va_end(va);
        }
        return *this;
    }
    virtual stringt& appendv(const char* chars, va_list va) {
        if ((chars)) {
            do {
                this->append(chars);
            } while ((chars = va_arg(va, const char*)));
        }
        return *this;
    }

    // signed
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual stringt& assign_signed(signed value) {
        this->clear(); return append_signed(value);
    }
    virtual stringt& assign_short(short value) {
        this->clear(); return append_short(value);
    }
    virtual stringt& append_signed(signed value) {
#define XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T signed
#include "xos/base/string_append_int.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T
        return *this;
    }
    virtual stringt& append_short(short value) {
#define XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T short
#include "xos/base/string_append_int.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T
        return *this;
    }

    // unsigned
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual stringt& assign_unsigned(unsigned value) {
        this->clear(); return append_unsigned(value);
    }
    virtual stringt& assign_ushort(ushort value) {
        this->clear(); return append_ushort(value);
    }
    virtual stringt& append_ushort(ushort value) {
#define XOS_NADIR_XOS_BASE_STRING_APPEND_UINT_T ushort
#include "xos/base/string_append_uint.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_APPEND_UINT_T
        return *this;
    }
    virtual stringt& append_unsigned(unsigned value) {
#define XOS_NADIR_XOS_BASE_STRING_APPEND_UINT_T unsigned
#include "xos/base/string_append_uint.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_APPEND_UINT_T
        return *this;
    }

    // int
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual stringt& assign_int(int value) {
        this->clear(); return append_int(value);
    }
    virtual stringt& assign_int8(int8_t value) {
        this->clear(); return append_int8(value);
    }
    virtual stringt& assign_int16(int16_t value) {
        this->clear(); return append_int16(value);
    }
    virtual stringt& assign_int32(int32_t value) {
        this->clear(); return append_int32(value);
    }
    virtual stringt& assign_int64(int64_t value) {
        this->clear(); return append_int64(value);
    }
    virtual stringt& assign_ssize(ssize_t value) {
        this->clear(); return append_ssize(value);
    }
    ///////////////////////////////////////////////////////////////////////
    virtual stringt& append_int(int value) {
#define XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T int
#include "xos/base/string_append_int.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T
        return *this;
    }
    virtual stringt& append_int8(int8_t value) {
#define XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T int8_t
#include "xos/base/string_append_int.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T
        return *this;
    }
    virtual stringt& append_int16(int16_t value) {
#define XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T int16_t
#include "xos/base/string_append_int.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T
        return *this;
    }
    virtual stringt& append_int32(int32_t value) {
#define XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T int32_t
#include "xos/base/string_append_int.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T
        return *this;
    }
    virtual stringt& append_int64(int64_t value) {
#define XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T int64_t
#include "xos/base/string_append_int.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T
        return *this;
    }
    virtual stringt& append_ssize(ssize_t value) {
#define XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T ssize_t
#include "xos/base/string_append_int.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T
        return *this;
    }

    // uint
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual stringt& assign_uint(uint value) {
        this->clear(); return append_uint(value);
    }
    virtual stringt& assign_uint8(uint8_t value) {
        this->clear(); return append_uint8(value);
    }
    virtual stringt& assign_uint16(uint16_t value) {
        this->clear(); return append_uint16(value);
    }
    virtual stringt& assign_uint32(uint32_t value) {
        this->clear(); return append_uint32(value);
    }
    virtual stringt& assign_uint64(uint64_t value) {
        this->clear(); return append_uint64(value);
    }
    virtual stringt& assign_size(size_t value) {
        this->clear(); return append_size(value);
    }
    ///////////////////////////////////////////////////////////////////////
    virtual stringt& append_uint(unsigned int value) {
#define XOS_NADIR_XOS_BASE_STRING_APPEND_UINT_T unsigned int
#include "xos/base/string_append_uint.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_APPEND_UINT_T
        return *this;
    }
    virtual stringt& append_uint8(uint8_t value) {
#define XOS_NADIR_XOS_BASE_STRING_APPEND_UINT_T uint8_t
#include "xos/base/string_append_uint.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_APPEND_UINT_T
        return *this;
    }
    virtual stringt& append_uint16(uint16_t value) {
#define XOS_NADIR_XOS_BASE_STRING_APPEND_UINT_T uint16_t
#include "xos/base/string_append_uint.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_APPEND_UINT_T
        return *this;
    }
    virtual stringt& append_uint32(uint32_t value) {
#define XOS_NADIR_XOS_BASE_STRING_APPEND_UINT_T uint32_t
#include "xos/base/string_append_uint.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_APPEND_UINT_T
        return *this;
    }
    virtual stringt& append_uint64(uint64_t value) {
#define XOS_NADIR_XOS_BASE_STRING_APPEND_UINT_T uint64_t
#include "xos/base/string_append_uint.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_APPEND_UINT_T
        return *this;
    }
    virtual stringt& append_size(size_t value) {
#define XOS_NADIR_XOS_BASE_STRING_APPEND_UINT_T size_t
#include "xos/base/string_append_uint.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_APPEND_UINT_T
        return *this;
    }

    // 0x
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual stringt& assignx(const void* in, size_t length, bool upper_case = false) {
        this->clear();
        this->appendx(in, length, upper_case);
        return *this;
    }
    virtual stringt& assign0x(const void* in, size_t length, bool upper_case = false) {
        this->clear();
        this->append0x(in, length, upper_case);
        return *this;
    }
    virtual stringt& appendx(const void* in, size_t length, bool upper_case = false) {
        const byte_t* bytes = (const byte_t*)(in);
        if ((bytes) && (length)) {
            TChar x[2];
            byte_t b;
            for (; 0 < length; --length) {
                b = (*bytes++);
                x[0] = dtox(b >> 4, upper_case);
                x[1] = dtox(b & 15, upper_case);
                append(x, 2);
            }
        }
        return *this;
    }
    virtual stringt& append0x(const void* in, size_t length, bool upper_case = false) {
        const byte_t* bytes = (const byte_t*)(in);
        if ((bytes) && (length)) {
            byte_t b = (*bytes);
            TChar x[5];

            x[0] = ((TChar)',');
            x[1] = ((TChar)'0');
            x[2] = ((TChar)((upper_case)?('X'):('x')));
            x[3] = dtox(b >> 4, upper_case);
            x[4] = dtox(b & 15, upper_case);
            append(x+1, 4);

            for (++bytes, --length; length > 0; --length, ++bytes) {
                b = (*bytes);
                x[3] = dtox(b >> 4, upper_case);
                x[4] = dtox(b & 15, upper_case);
                append(x, 5);
            }
        }
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual TChar dtox(byte_t d, bool upper_case = false) const {
        char a = (upper_case)?('A'):('a');
        TChar x = (TChar)(0);
        if ((0 <= d) && (9 >= d))
            x = (TChar)(('0') +  d);
        else
        if ((10 <= d) && (15 >= d))
            x = (TChar)((a) + (d - 10));
        return x;
    }

    ///////////////////////////////////////////////////////////////////////
    /// find
    ///////////////////////////////////////////////////////////////////////
    virtual const TChar* find_case(const char* whatFind, size_t findLength) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) to_lower(c)
#define XOS_NADIR_XOS_BASE_STRING_COMPARE compare_case
#include "xos/base/string_find.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual const TChar* find_case(const char* whatFind) const {
        return this->find_case(whatFind, chars_t::size(whatFind));
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const TChar* find(const char* whatFind, size_t findLength) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) (c)
#define XOS_NADIR_XOS_BASE_STRING_COMPARE compare
#include "xos/base/string_find.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual const TChar* find(const char* whatFind) const {
        return this->find(whatFind, chars_t::size(whatFind));
    }

    ///////////////////////////////////////////////////////////////////////
    /// compare
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_case
    (const TChar* chars, const char* to_chars,
     size_t to_length, size_t length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) to_lower(c)
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) 0
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) chars
#include "xos/base/string_compare_chars.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_case
    (const TChar* chars, const char* to_chars, size_t length) const {
        return this->compare_case(chars, to_chars, length, length);
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int compare
    (const TChar* chars, const char* to_chars,
     size_t to_length, size_t length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) c
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) 0
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) chars
#include "xos/base/string_compare_chars.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare
    (const TChar* chars, const char* to_chars, size_t length) const {
        return this->compare(chars, to_chars, length, length);
    }

    ///////////////////////////////////////////////////////////////////////
    /// compare_begin
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_begin_case(const char* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) to_lower(c)
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) 0
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) chars
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_begin_case(const char* to_chars) const {
        return this->compare_begin_case(to_chars, chars_t::size(to_chars));
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_begin_case(const wchar_t* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) to_lower(c)
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) 0
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) chars
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_begin_case(const wchar_t* to_chars) const {
        return this->compare_begin_case(to_chars, wchars_t::size(to_chars));
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_begin(const char* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) c
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) 0
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) chars
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_begin(const char* to_chars) const {
        return this->compare_begin(to_chars, chars_t::size(to_chars));
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_begin(const wchar_t* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) c
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) 0
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) chars
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_begin(const wchar_t* to_chars) const {
        return this->compare_begin(to_chars, wchars_t::size(to_chars));
    }

    ///////////////////////////////////////////////////////////////////////
    /// compare_end
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_end_case(const char* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) to_lower(c)
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) 0
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) end_chars(chars, length, to_length)
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_end_case(const char* to_chars) const {
        return this->compare_end_case(to_chars, chars_t::size(to_chars));
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_end_case(const wchar_t* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) to_lower(c)
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) 0
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) end_chars(chars, length, to_length)
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_end_case(const wchar_t* to_chars) const {
        return this->compare_end_case(to_chars, wchars_t::size(to_chars));
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_end(const char* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) c
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) 0
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) end_chars(chars, length, to_length)
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_end(const char* to_chars) const {
        return this->compare_end(to_chars, chars_t::size(to_chars));
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_end(const wchar_t* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) c
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) 0
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) end_chars(chars, length, to_length)
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_end(const wchar_t* to_chars) const {
        return this->compare_end(to_chars, wchars_t::size(to_chars));
    }

    ///////////////////////////////////////////////////////////////////////
    /// compare
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_case(const char* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) to_lower(c)
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) unequal
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) chars
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_case(const char* to_chars) const {
        return this->compare_case(to_chars, chars_t::size(to_chars));
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_case(const wchar_t* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) to_lower(c)
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) unequal
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) chars
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare_case(const wchar_t* to_chars) const {
        return this->compare_case(to_chars, wchars_t::size(to_chars));
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare(const char* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) c
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) unequal
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) chars
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare(const char* to_chars) const {
        return this->compare(to_chars, chars_t::size(to_chars));
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int compare(const wchar_t* to_chars, size_t to_length) const {
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(c) c
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal) unequal
#define XOS_NADIR_XOS_BASE_STRING_COMPARE_END(chars, length, to_length) chars
#include "xos/base/string_compare.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_END
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN
#undef XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE
        return 0;
    }
    virtual int compare(const wchar_t* to_chars) const {
        return this->compare(to_chars, wchars_t::size(to_chars));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int to_signed() const {
        signed value = 0;
#define XOS_NADIR_XOS_BASE_STRING_TO_INT_T signed
#include "xos/base/string_to_int.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_TO_INT_T
        return value;
    }
    virtual int to_int() const {
        int value = 0;
#define XOS_NADIR_XOS_BASE_STRING_TO_INT_T int
#include "xos/base/string_to_int.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_TO_INT_T
        return value;
    }
    virtual int to_int8() const {
        int8_t value = 0;
#define XOS_NADIR_XOS_BASE_STRING_TO_INT_T int8_t
#include "xos/base/string_to_int.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_TO_INT_T
        return value;
    }
    virtual int to_int16() const {
        int16_t value = 0;
#define XOS_NADIR_XOS_BASE_STRING_TO_INT_T int16_t
#include "xos/base/string_to_int.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_TO_INT_T
        return value;
    }
    virtual int to_int32() const {
        int32_t value = 0;
#define XOS_NADIR_XOS_BASE_STRING_TO_INT_T int32_t
#include "xos/base/string_to_int.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_TO_INT_T
        return value;
    }
    virtual int to_int64() const {
        int64_t value = 0;
#define XOS_NADIR_XOS_BASE_STRING_TO_INT_T int64_t
#include "xos/base/string_to_int.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_TO_INT_T
        return value;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int to_unsigned() const {
        unsigned value = 0;
#define XOS_NADIR_XOS_BASE_STRING_TO_UINT_T unsigned
#include "xos/base/string_to_uint.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_TO_UINT_T
        return value;
    }
    virtual unsigned int to_uint() const {
        unsigned int value = 0;
#define XOS_NADIR_XOS_BASE_STRING_TO_UINT_T unsigned int
#include "xos/base/string_to_uint.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_TO_UINT_T
        return value;
    }
    virtual uint8_t to_uint8() const {
        uint8_t value = 0;
#define XOS_NADIR_XOS_BASE_STRING_TO_UINT_T uint8_t
#include "xos/base/string_to_uint.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_TO_UINT_T
        return value;
    }
    virtual uint16_t to_uint16() const {
        uint16_t value = 0;
#define XOS_NADIR_XOS_BASE_STRING_TO_UINT_T uint16_t
#include "xos/base/string_to_uint.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_TO_UINT_T
        return value;
    }
    virtual uint32_t to_uint32() const {
        uint32_t value = 0;
#define XOS_NADIR_XOS_BASE_STRING_TO_UINT_T uint32_t
#include "xos/base/string_to_uint.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_TO_UINT_T
        return value;
    }
    virtual uint64_t to_uint64() const {
        uint64_t value = 0;
#define XOS_NADIR_XOS_BASE_STRING_TO_UINT_T uint64_t
#include "xos/base/string_to_uint.cpp"
#undef XOS_NADIR_XOS_BASE_STRING_TO_UINT_T
        return value;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual TChar to_lower(TChar c) const {
        static const TChar A = ((TChar)'A');
        static const TChar Z = ((TChar)'Z');
        static const TChar a = ((TChar)'a');
        if ((c >= A) && (c <= Z))
            c = a + (c - A);
        return c;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const TChar* has_chars(size_t& length) const {
        if (0 < (length = this->length())) {
            return this->c_str();
        }
        return 0;
    }
    virtual const TChar* has_chars() const {
        if (0 < (this->length())) {
            return this->c_str();
        }
        return 0;
    }
    virtual const TChar* chars(size_t& length) const {
        length = this->length();
        return this->c_str();
    }
    virtual const TChar* chars() const {
        return this->c_str();
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* end_chars
    (const char* chars, size_t length, size_t to_length) const {
        if ((chars) && (length >= to_length))
            return chars + length - to_length;
        return chars;
    }
    virtual const wchar_t* end_chars
    (const wchar_t* chars, size_t length, size_t to_length) const {
        if ((chars) && (length >= to_length))
            return chars + length - to_length;
        return chars;
    }
};

typedef stringt<char> string;
typedef stringt<byte_t> bstring;
typedef stringt<wchar_t> wstring;
typedef stringt<tchar_t> tstring;

typedef string_implements bstring_implements;
typedef string_implements wstring_implements;
typedef string_implements tstring_implements;

} // namespace base
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_STRING_HPP 
