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
///   File: function_parameter.hpp
///
/// Author: $author$
///   Date: 3/21/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_FUNCTION_PARAMETER_HPP
#define _TEXTA_T_FUNCTION_PARAMETER_HPP

#include "texta/t/function.hpp"
#include "xos/base/list.hpp"
#include "xos/base/item.hpp"

namespace texta {
namespace t {

///////////////////////////////////////////////////////////////////////
///  Class: function_parameter
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS function_parameter {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    const char *name() const {
        return name_;
    }
    const char *description() const {
        return description_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    const char *name_, *description_;
};

typedef implement_base function_parameter_reference_implements;
typedef base function_parameter_reference_extends;
///////////////////////////////////////////////////////////////////////
///  Class: function_parameter_reference
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS function_parameter_reference
: virtual public function_parameter_reference_implements,
  public function_parameter_reference_extends {
public:
    typedef function_parameter_reference_implements Implements;
    typedef function_parameter_reference_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    function_parameter_reference(function_parameter& p): p_(p) {
    }
    function_parameter_reference
    (const function_parameter_reference& copy): p_(copy.p_) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    operator function_parameter& () const { return (function_parameter&)p_; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    function_parameter& p_;
};

class _EXPORT_CLASS function_parameter_item;
typedef itemt
<function_parameter_reference, function_parameter_item> function_parameter_item_extends;
///////////////////////////////////////////////////////////////////////
///  Class: function_parameter_item
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS function_parameter_item: public function_parameter_item_extends {
public:
    typedef function_parameter_item_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    function_parameter_item(function_parameter& parameter): Extends(parameter) {
    }
    virtual ~function_parameter_item() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

class _EXPORT_CLASS function_parameter_list;
typedef listt
<function_parameter_list, function_parameter_item> function_parameter_list_extends;
///////////////////////////////////////////////////////////////////////
///  Class: function_parameter_list
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS function_parameter_list: public function_parameter_list_extends {
public:
    typedef function_parameter_list_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    function_parameter_list() {
    }
    virtual ~function_parameter_list() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace t
} // namespace texta 

#endif // _TEXTA_T_FUNCTION_PARAMETER_HPP 
