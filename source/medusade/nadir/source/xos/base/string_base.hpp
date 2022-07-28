///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
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
///   File: string_base.hpp
///
/// Author: $author$
///   Date: 1/15/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_BASE_STRING_BASE_HPP
#define XOS_BASE_STRING_BASE_HPP

#include "xos/base/extend.hpp"

#define XOS_BASE_STRING_BASE_DEFAULT_SIZE 128

namespace xos {
namespace base {

typedef extend string_base_extends;
typedef implement string_base_implements;
///////////////////////////////////////////////////////////////////////
/// class string_baset
///////////////////////////////////////////////////////////////////////
template 
<typename TChar = char_t, typename TSize = size_t,
 TSize VSize = XOS_BASE_STRING_BASE_DEFAULT_SIZE, typename TEnd = TChar, TEnd VEnd = 0,
 class TExtends = string_base_extends, class TImplements = string_base_implements>
class EXPORT_CLASS string_baset: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef string_baset Derives;

    typedef TChar char_t;
    typedef TEnd end_char_t;
    enum { end_char = VEnd };

    typedef TSize size_t;
    enum { default_size = VSize };
    
    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    string_baset(const char_t* chars, size_t length) {
        _construct();
        append(chars, length);
    }
    string_baset(const char_t* chars) {
        _construct();
        append(chars);
    }
    string_baset(const string_baset& copy): Extends(copy) {
        _construct();
        append(copy);
    }
    string_baset() {
        _construct();
    }
    virtual ~string_baset() {
        _destruct();
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string_baset& assign(const string_baset& copy) {
        clear();
        return append(copy);
    }
    virtual string_baset& assign(const char_t* chars) {
        clear();
        return append(chars);
    }
    virtual string_baset& assign(const char_t* chars, size_t length) {
        clear();
        return append(chars, length);
    }
    virtual string_baset& operator = (const string_baset& copy) {
        return assign(copy);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string_baset& append(const string_baset& copy) {
        const char_t* chars = 0; size_t length = 0;
        if ((chars = copy.c_str()) && (length = copy.length())) {
            append(chars, length);
        }
        return *this;
    }
    virtual string_baset& append(const char_t* chars) {
        if ((chars) && (chars[0] != (char_t)(VEnd))) {
            append(chars, _length_of(chars));
        }
        return *this;
    }
    virtual string_baset& append(const char_t* chars, size_t length) {
        if ((chars) && (0 < length)) {
            size_t newSize = (m_tell+length);

            if (m_size <= newSize) {
                if (m_fixedSize) {
                    length = m_size-m_tell;
                } else {
                    if (!(_adjust_to_size(_new_size_of(newSize)))) {
                        length = 0;
                    }
                }
            }
            if (length) {
                _copy_to(m_writeBuffer+m_tell, chars, length);
                if ((m_tell += length) > m_length) {
                    if ((m_length = m_tell) < m_size) {
                        ///
                        /// add end char at end
                        /// 
                        m_writeBuffer[m_tell] = (char_t)(VEnd);
                    }
                }
            }
        }
        return *this;
    }
    virtual string_baset& clear() {
        if ((m_writeBuffer)) {
            if (m_size > (m_length = (m_tell = 0))) {
                m_writeBuffer[m_tell] = (char_t)(VEnd);
            }
        }
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare(const string_baset& to) const {
        return compare(to.c_str(), to.length());
    }
    virtual int compare(const char_t* toChars, size_t toLength) const {
        const char_t *thisChars = 0, thisChar = 0, toChar = 0;
        size_t thisLength = 0; ssize_t lendiff = 0; 
        int unequal = 2;

        if (!(thisChars = (c_str()))) {
            return (toChars)?(-1):(1);
        }
        if (0 < (lendiff = (toLength - (thisLength = length())))) {
            toLength = thisLength;
            unequal = -1;
        } else {
            if (lendiff) {
                unequal = 1;
            }
        }
        if ((toChars) && (toLength > 0)) {
            do {
                if ((thisChar = *(thisChars++)) > (toChar = *(toChars++))) {
                    return 1;
                } else {
                    if (thisChar < toChar) {
                        return -1;
                    }
                }
            } while (--toLength > 0);
        }
        return unequal;
    }
    virtual int compare(const char_t* toChars) {
        return compare(toChars, _length_of(toChars));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual char_t* buffer() const {
        return str();
    }
    virtual const char_t* chars() const {
        return c_str();
    }
    virtual char_t* str() const {
        return m_writeBuffer;
    }
    virtual const char_t* c_str() const {
        return m_readBuffer;
    }
    virtual size_t length() const {
        return m_length;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void _construct() {
        m_freeBuffer = (m_fixedSize = false);
        m_size = default_size; m_length = (m_tell = 0);
        m_readBuffer = (m_writeBuffer = m_defaultBuffer);
    }
    virtual void _destruct() {
        if ((m_writeBuffer != m_defaultBuffer)) {
            if ((m_writeBuffer) && (m_freeBuffer)) {
                _free_buffer(m_writeBuffer);
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t adjust_size(size_t newSize) {
        if (!m_writeBuffer) {
            return 0;
        }
        if (m_size < (newSize)) {
            if (m_fixedSize) {
                return 0;
            } else {
                if (1 > (_adjust_to_size(_new_size_of(newSize)))) {
                    return 0;
                }
            }
        }
        return m_size;
    }
    virtual size_t _adjust_to_size(size_t size) {
        bool freeBuffer = false;
        char_t* buffer = 0;

        if (!m_writeBuffer) {
            return 0;
        }
        if (size <= m_size) {
            return m_size;
        }
        if (!(freeBuffer = m_freeBuffer)) {
            m_freeBuffer = true;
        }
        if (!(buffer = _alloc_buffer(size))) {
            m_freeBuffer = freeBuffer;
            return 0;
        }
        if (m_writeBuffer) {
            if (m_length > 0) {
                _copy_to(buffer, m_writeBuffer, m_length);
            }
            if ((m_writeBuffer != m_defaultBuffer) && (freeBuffer)) {
                _free_buffer(m_writeBuffer);
            }
        }
        m_writeBuffer = buffer;
        m_readBuffer = buffer;
        m_size = size;
        return m_size;
    }
    virtual size_t _new_size_of(size_t size) const {
        /// 
        /// Increase the buffer size by default buffer
        /// sized chunks. Note the desired new size is always
        /// needed size + 1. The size in chunks is calculated
        /// as (new size + (chunk size - 1)) / chunk size.
        /// since new size = needed size + 1 then we have
        /// chunks = (needed size + chunk size) / chunk size.
        /// Finally we need bytes which is chunks * chunk size
        /// which can be reduced to
        /// ((needed size / chunk size) + 1) * chunk size
        /// 
        return ((size / default_size) + 1) * default_size;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual char_t* _alloc_buffer(size_t size) const {
        char_t* chars = 0;
        if ((size)) {
            if (!(chars = new char_t[size])) {
            }
        }
        return chars;
    }
    virtual void _free_buffer(char_t* buffer) const {
        if ((buffer)) {
            delete[] buffer;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t _copy_to(char_t* to, const char_t* from, size_t size) const {
        size_t length = 0;

        if ((from) && (to)) {
            for (length = size; size; --size) {
                (*to++) = (*from++);
            }
        }
        return length;
    }
    virtual size_t _length_of(const char_t* chars) const {
        const char_t endChar((char_t)(VEnd));
        size_t length = 0;

        if ((chars)) {
            for (length = 0; ((*chars) != endChar); chars++) {
                length++;
            }
        }
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool m_freeBuffer, m_fixedSize;
    size_t m_size, m_length, m_tell;
    const char_t *m_readBuffer, *m_writeBuffer, m_defaultBuffer[default_size];
}; /// class string_baset

typedef string_baset<char_t> string_base;
typedef string_baset<wchar_t> wstring_base;
typedef string_baset<tchar_t> tstring_base;

} /// namespace base
} /// namespace xos

#endif /// ndef XOS_BASE_STRING_BASE_HPP 
