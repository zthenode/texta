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
///   File: variable_list.hpp
///
/// Author: $author$
///   Date: 5/21/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_VARIABLE_LIST_HPP
#define _TEXTA_T_VARIABLE_LIST_HPP

#include "texta/t/variable_item.hpp"

namespace texta {
namespace t {

class _EXPORT_CLASS variable_list;
typedef listt
<variable_list, variable_item> variable_list_extends;
///////////////////////////////////////////////////////////////////////
///  Class: variable_list
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS variable_list: public variable_list_extends {
public:
    typedef variable_list_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    variable_list() {
    }
    virtual ~variable_list() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual variable* pop_variable() {
        variable* v = 0;
        variable_item* i = 0;
        if ((i = this->pop())) {
            //v = &i->what();
            v = &((variable&)(i->what()));
        }
        return v;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace t
} // namespace texta

#endif // _TEXTA_T_VARIABLE_LIST_HPP
