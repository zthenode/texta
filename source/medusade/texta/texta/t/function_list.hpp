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
///   File: function_list.hpp
///
/// Author: $author$
///   Date: 3/21/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_FUNCTION_LIST_HPP
#define _TEXTA_T_FUNCTION_LIST_HPP

#include "texta/t/function_item.hpp"

namespace texta {
namespace t {

class _EXPORT_CLASS function_list;
typedef listt<function_list, function_item> function_list_extends;
///////////////////////////////////////////////////////////////////////
///  Class: function_list
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS function_list: public function_list_extends {
public:
    typedef function_list_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    function_list() {
    }
    virtual ~function_list() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static function_list& the_list() {
        static function_list the_list;
        return the_list;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace t 
} // namespace texta 

#endif // _TEXTA_T_FUNCTION_LIST_HPP 
        

