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
///   File: variable_item.hpp
///
/// Author: $author$
///   Date: 5/21/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_VARIABLE_ITEM_HPP
#define _TEXTA_T_VARIABLE_ITEM_HPP

#include "texta/t/t.hpp"

namespace texta {
namespace t {

class _EXPORT_CLASS variable;
typedef implement_base variable_reference_implements;
typedef base variable_reference_extends;
///////////////////////////////////////////////////////////////////////
///  Class: variable_reference
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS variable_reference
: virtual public variable_reference_implements, public variable_reference_extends {
public:
    typedef variable_reference_implements Implements;
    typedef variable_reference_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    variable_reference(variable& v): v_(v) {
    }
    variable_reference(const variable_reference& copy): v_(copy.v_) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    operator variable& () const { return (variable&)v_; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    variable& v_;
};
class _EXPORT_CLASS variable_item;
typedef itemt<variable_reference, variable_item> variable_item_extends;
///////////////////////////////////////////////////////////////////////
///  Class: variable_item
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS variable_item: public variable_item_extends {
public:
    typedef variable_item_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    variable_item(variable& parameter): Extends(parameter) {
    }
    virtual ~variable_item() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace t
} // namespace texta

#endif // _TEXTA_T_VARIABLE_ITEM_HPP
