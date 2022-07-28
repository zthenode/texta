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
///   File: value_item.hpp
///
/// Author: $author$
///   Date: 5/23/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_VALUE_ITEM_HPP
#define _TEXTA_T_VALUE_ITEM_HPP

#include "texta/t/t.hpp"

namespace texta {
namespace t {

class _EXPORT_CLASS value;
typedef implement_base value_reference_implements;
typedef base value_reference_extends;
///////////////////////////////////////////////////////////////////////
///  Class: value_reference
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS value_reference
: virtual public value_reference_implements, public value_reference_extends {
public:
    typedef value_reference_implements Implements;
    typedef value_reference_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    value_reference(value& v): v_(v) {
    }
    value_reference(const value_reference& copy): v_(copy.v_) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    operator value& () const { return (value&)v_; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    value& v_;
};

class _EXPORT_CLASS value_item;
typedef itemt<value_reference, value_item> value_item_extends;
///////////////////////////////////////////////////////////////////////
///  Class: value_item
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS value_item: public value_item_extends {
public:
    typedef value_item_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    value_item(value& _value): Extends(_value) {
    }
    virtual ~value_item() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace t
} // namespace texta

#endif // _TEXTA_T_VALUE_ITEM_HPP
