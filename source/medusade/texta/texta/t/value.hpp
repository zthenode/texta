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
///   File: value.hpp
///
/// Author: $author$
///   Date: 5/23/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_VALUE_HPP
#define _TEXTA_T_VALUE_HPP

#include "texta/t/value_item.hpp"
#include "texta/t/t.hpp"

namespace texta {
namespace t {

typedef result_implements value_implements;
typedef result value_extends;
///////////////////////////////////////////////////////////////////////
///  Class: value
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS value
: virtual public value_implements, public value_extends {
public:
    typedef value_implements Implements;
    typedef value_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    value(const char* chars): Extends(chars), item_(*this) {
    }
    value(const string& copy): Extends(copy), item_(*this) {
    }
    value(const value& copy): Extends(copy), item_(*this) {
    }
    value(): item_(*this) {
    }
    virtual ~value() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual value_item& item() const {
        return (value_item&)item_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    value_item item_;
};

} // namespace t
} // namespace texta

#endif // _TEXTA_T_VALUE_HPP
