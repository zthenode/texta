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
///   File: variable_leaf.hpp
///
/// Author: $author$
///   Date: 6/3/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_VARIABLE_LEAF_HPP
#define _TEXTA_T_VARIABLE_LEAF_HPP

#include "texta/t/t.hpp"

namespace texta {
namespace t {

class _EXPORT_CLASS variable;
class _EXPORT_CLASS variable_branch;

typedef implement_base variable_leaf_implements;
typedef string variable_leaf_extends;
///////////////////////////////////////////////////////////////////////
///  Class: variable_leaf
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS variable_leaf
: virtual public variable_leaf_implements, public variable_leaf_extends {
public:
    typedef variable_leaf_implements Implements;
    typedef variable_leaf_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    variable_leaf(const char* name, t::variable& variable)
    : Extends(name), variable_(variable) {
    }
    variable_leaf(const string& name, t::variable& variable)
    : Extends(name), variable_(variable) {
    }
    variable_leaf(const variable_leaf& copy)
    : Extends(copy), variable_(copy.variable()) {
    }
    virtual ~variable_leaf() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual t::variable& variable() const {
        return (t::variable&)variable_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    t::variable& variable_;
};

} // namespace t
} // namespace texta

#endif // _TEXTA_T_VARIABLE_LEAF_HPP
