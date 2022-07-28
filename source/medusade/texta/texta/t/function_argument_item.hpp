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
///   File: function_argument_item.hpp
///
/// Author: $author$
///   Date: 5/22/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_FUNCTION_ARGUMENT_ITEM_HPP
#define _TEXTA_T_FUNCTION_ARGUMENT_ITEM_HPP

#include "texta/t/t.hpp"

namespace texta {
namespace t {

class _EXPORT_CLASS function_argument;
typedef implement_base function_argument_reference_implements;
typedef base function_argument_reference_extends;
///////////////////////////////////////////////////////////////////////
///  Class: function_argument_reference
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS function_argument_reference
: virtual public function_argument_reference_implements,
  public function_argument_reference_extends {
public:
    typedef function_argument_reference_implements Implements;
    typedef function_argument_reference_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    function_argument_reference(function_argument& a): a_(a) {
    }
    function_argument_reference
    (const function_argument_reference& copy): a_(copy.a_) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    operator function_argument& () const { return (function_argument&)a_; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    function_argument& a_;
};
class _EXPORT_CLASS function_argument_item;
typedef itemt
<function_argument_reference, function_argument_item> function_argument_item_extends;
///////////////////////////////////////////////////////////////////////
///  Class: function_argument_item
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS function_argument_item: public function_argument_item_extends {
public:
    typedef function_argument_item_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    function_argument_item(function_argument& argument): Extends(argument) {
    }
    virtual ~function_argument_item() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace t
} // namespace texta

#endif // _TEXTA_T_FUNCTION_ARGUMENT_ITEM_HPP
