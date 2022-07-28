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
///   File: function_argument_list.hpp
///
/// Author: $author$
///   Date: 5/22/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_FUNCTION_ARGUMENT_LIST_HPP
#define _TEXTA_T_FUNCTION_ARGUMENT_LIST_HPP

#include "texta/t/function_argument.hpp"
#include "texta/t/function_argument_item.hpp"
#include "texta/io/logger.hpp"

namespace texta {
namespace t {

class _EXPORT_CLASS function_argument_list;
typedef listt
<function_argument_list, function_argument_item> function_argument_list_extends;
///////////////////////////////////////////////////////////////////////
///  Class: function_argument_list
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS function_argument_list: public function_argument_list_extends {
public:
    typedef function_argument_list_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    function_argument_list() {
    }
    virtual ~function_argument_list() {
        clear();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual function_argument* first_argument() const {
        function_argument* arg = 0;
        function_argument_item* item = 0;
        if ((item = this->first())) {
            //arg = &item->what();
            arg = &((function_argument&)(item->what()));
        }
        return arg;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void clear() {
        function_argument_item* i = 0;
        while (i = this->pop()) {
            //function_argument* a = &i->what();
            function_argument* a = &((function_argument&)(i->what()));
            TEXTA_LOG_MESSAGE_DEBUG("delete a = " << pointer_to_string(a) << "->chars() = " << chars_to_string(a->chars()) << "...");
            delete a;
            TEXTA_LOG_MESSAGE_DEBUG("...delete a = " << pointer_to_string(a) << "");
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace t
} // namespace texta

#endif // _TEXTA_T_FUNCTION_ARGUMENT_LIST_HPP
