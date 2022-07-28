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
///   File: string_extend.hpp
///
/// Author: $author$
///   Date: 7/28/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_STRING_EXTEND_HPP
#define _XOS_NADIR_XOS_BASE_STRING_EXTEND_HPP

#include "xos/base/base.hpp"
#include <string>

namespace xos {
namespace base {

typedef implement_base string_extend_implements;
typedef std::basic_string<char> string_extend_extends;
typedef std::basic_string<tchar_t> tstring_extend_extends;
typedef std::basic_string<wchar_t> wstring_extend_extends;
///////////////////////////////////////////////////////////////////////
///  Class: string_extendt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TEnd = TChar, TEnd VEnd = 0,
 class TExtends = std::basic_string<TChar>, class TImplements = string_extend_implements>
class _EXPORT_CLASS string_extendt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TChar char_t;
    typedef TEnd end_t;
    static const end_t end = VEnd;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    string_extendt(const wchar_t* chars, size_t length) {
        this->append(chars, length);
    }
    string_extendt(const wchar_t* chars) {
        this->append(chars);
    }
    string_extendt(const char* chars, size_t length) {
        this->append(chars, length);
    }
    string_extendt(const char* chars) {
        this->append(chars);
    }
    ///////////////////////////////////////////////////////////////////////
    string_extendt(const wstring_extend_extends& copy) {
        this->append(copy.c_str());
    }
    string_extendt(const string_extend_extends& copy) {
        this->append(copy.c_str());
    }
    string_extendt(const string_extendt& copy): Extends(copy) {
    }
    string_extendt() {
    }
    virtual ~string_extendt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string_extendt& assign() {
        this->clear();
        return *this;
    }
    virtual string_extendt& assign(const char_t* chars) {
        this->clear();
        this->append(chars);
        return *this;
    }
    virtual string_extendt& assign(const char_t* chars, size_t length) {
        this->clear();
        this->append(chars, length);
        return *this;
    }
    virtual string_extendt& append() {
        return *this;
    }
    virtual string_extendt& append(const char_t* chars) {
        if ((chars)) {
            while ((*chars) != end) {
                this->append(chars, 1);
                ++chars;
            }
        }
        return *this;
    }
    virtual string_extendt& append(const char_t* chars, size_t length) {
        Extends::append(chars, length);
        return *this;
    }

    // wchar_t
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string_extendt& assign(const wchar_t* chars) {
        this->clear();
        this->append(chars);
        return *this;
    }
    virtual string_extendt& assign(const wchar_t* chars, size_t length) {
        this->clear();
        this->append(chars);
        return *this;
    }
    virtual string_extendt& append(const wchar_t* chars) {
        return *this;
    }
    virtual string_extendt& append(const wchar_t* chars, size_t length) {
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual string_extendt& assignl(const wchar_t* chars, ...) {
        this->clear();
        if ((chars)) {
            va_list va;
            va_start(va, chars);
            this->appendv(chars, va);
            va_end(va);
        }
        return *this;
    }
    virtual string_extendt& assignv(const wchar_t* chars, va_list va) {
        this->clear();
        if ((chars)) {
            this->appendv(chars, va);
        }
        return *this;
    }
    virtual string_extendt& appendl(const wchar_t* chars, ...) {
        if ((chars)) {
            va_list va;
            va_start(va, chars);
            this->appendv(chars, va);
            va_end(va);
        }
        return *this;
    }
    virtual string_extendt& appendv(const wchar_t* chars, va_list va) {
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
    virtual string_extendt& assign(const char* chars) {
        this->clear();
        this->append(chars);
        return *this;
    }
    virtual string_extendt& assign(const char* chars, size_t length) {
        this->clear();
        this->append(chars, length);
        return *this;
    }
    virtual string_extendt& append(const char* chars) {
        return *this;
    }
    virtual string_extendt& append(const char* chars, size_t length) {
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string_extendt& assignl(const char* chars, ...) {
        this->clear();
        if ((chars)) {
            va_list va;
            va_start(va, chars);
            this->appendv(chars, va);
            va_end(va);
        }
        return *this;
    }
    virtual string_extendt& assignv(const char* chars, va_list va) {
        this->clear();
        if ((chars)) {
            this->appendv(chars, va);
        }
        return *this;
    }
    virtual string_extendt& appendl(const char* chars, ...) {
        if ((chars)) {
            va_list va;
            va_start(va, chars);
            this->appendv(chars, va);
            va_end(va);
        }
        return *this;
    }
    virtual string_extendt& appendv(const char* chars, va_list va) {
        if ((chars)) {
            do {
                this->append(chars);
            } while ((chars = va_arg(va, const char*)));
        }
        return *this;
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

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_STRING_EXTEND_HPP 
