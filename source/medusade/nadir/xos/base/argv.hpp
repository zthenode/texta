///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2015 $organization$
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
///   File: argv.hpp
///
/// Author: $author$
///   Date: 1/31/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_ARGV_HPP
#define _XOS_NADIR_XOS_BASE_ARGV_HPP

#include "xos/base/array.hpp"
#include "xos/base/string_base.hpp"

#define XOS_BASE_ARGV_DEFAULT_SIZE \
    XOS_ARRAY_DEFAULT_SIZE

namespace xos {
namespace base {

typedef array_implements argv_implements;
///////////////////////////////////////////////////////////////////////
///  Class: argvt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TSize = size_t,
 TSize VSize = XOS_BASE_ARGV_DEFAULT_SIZE,
 class TString = string_baset<TChar>,
 class TExtends = arrayt<TChar*, TSize, VSize>,
 class TImplements = argv_implements>

class _EXPORT_CLASS argvt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TString string_t;
    typedef TChar* chars_t;
    typedef TChar char_t;
    typedef TSize size_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    argvt(const char_t** elements, size_t length): end_(0) {
        if ((append(elements, length))) {
            append_end();
        }
    }
    argvt(): end_(0) {
    }
    virtual ~argvt() {
        clear();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t assign(const char_t** elements, size_t length) {
        size_t count = 0;
        clear();
        count = append(elements, length);
        return count;
    }
    virtual size_t append(const char_t** elements, size_t length) {
        size_t count = 0;
        if ((elements) && (length)) {
            for (size_t index = strings_.length(); count < length; ++count) {
                string_t s(elements[count]);
                chars_t chars = 0;
                if (0 < (strings_.append(&s, 1))) {
                    if ((chars = strings_[index + count].buffer())) {
                        if (0 < (Extends::append(&chars, 1))) {
                            continue;
                        }
                    }
                }
                break;
            }
        }
        return count;
    }
    virtual size_t append_end() {
        size_t count = Extends::append(&end_, 1);
        return count;
    }
    virtual size_t clear() {
        size_t count = Extends::clear();
        strings_.clear();
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef arrayt<string_t, size_t, VSize> strings_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    chars_t end_;
    strings_t strings_;
};

typedef argvt<char_t> argv_t;
typedef argvt<wchar_t> wargv_t;
typedef argvt<tchar_t> targv_t;

} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_ARGV_HPP 
        

