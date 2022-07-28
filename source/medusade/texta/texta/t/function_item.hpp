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
///   File: function_item.hpp
///
/// Author: $author$
///   Date: 5/21/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_FUNCTION_ITEM_HPP
#define _TEXTA_T_FUNCTION_ITEM_HPP

#include "texta/t/function.hpp"

namespace texta {
namespace t {

class _EXPORT_CLASS function;
class _EXPORT_CLASS function_item;
typedef itemt<function_reference, function_item> function_item_extends;
///////////////////////////////////////////////////////////////////////
///  Class: function_item
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS function_item: public function_item_extends {
public:
    typedef function_item_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    function_item(function& _function): Extends(_function) {
    }
    virtual ~function_item() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace t
} // namespace texta

#endif // _TEXTA_T_FUNCTION_ITEM_HPP
