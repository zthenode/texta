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
///   File: variable_tree.hpp
///
/// Author: $author$
///   Date: 5/21/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_VARIABLE_TREE_HPP
#define _TEXTA_T_VARIABLE_TREE_HPP

#include "texta/t/variable_branch.hpp"
#include "texta/t/variable_list.hpp"
#include "texta/t/variable.hpp"

namespace texta {
namespace t {

class _EXPORT_CLASS variable_tree;
typedef avl::treet
<variable_leaf, variable_branch, variable_tree,
 avl::tree_implements, binary::treet
 <variable_leaf, variable_branch, variable_tree,
  binary::tree_implements, treet
  <variable_leaf, variable_branch, variable_tree,
   tree_implements, tree_extends> > > variable_tree_extends;
///////////////////////////////////////////////////////////////////////
///  Class: variable_tree
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS variable_tree: public variable_tree_extends {
public:
    typedef variable_tree_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    variable_tree() {
    }
    virtual ~variable_tree() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool push_value(const string& name, variable_value& to) {
        variable* v = 0;
        TEXTA_LOG_MESSAGE_DEBUG("get_variable(name = \"" << name << "\")...");
        if ((v = get_variable(name))) {
            TEXTA_LOG_MESSAGE_DEBUG("v->push_value(to = \"" << to << "\")...");
            if ((v->push_value(to))) {
                TEXTA_LOG_MESSAGE_DEBUG("...v->push_value(to = \"" << to << "\")");
                return true;
            }
        }
        return false;
    }
    virtual bool push_value(const string& name, const string& to) {
        variable* v = 0;
        TEXTA_LOG_MESSAGE_DEBUG("get_variable(name = \"" << name << "\")...");
        if ((v = get_variable(name))) {
            TEXTA_LOG_MESSAGE_DEBUG("v->push_value(to = \"" << to << "\")...");
            if ((v->push_value(to))) {
                TEXTA_LOG_MESSAGE_DEBUG("...v->push_value(to = \"" << to << "\")");
                return true;
            }
        }
        return false;
    }
    virtual bool pop_value(const string& name) {
        variable* v = 0;
        TEXTA_LOG_MESSAGE_DEBUG("get_variable(name = \"" << name << "\")...");
        if ((v = get_variable(name))) {
            TEXTA_LOG_MESSAGE_DEBUG("v->pop_value()...");
            if ((v->pop_value())) {
                TEXTA_LOG_MESSAGE_DEBUG("...v->pop_value()");
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_value(const string& name, const string& to) {
        variable* v = 0;
        TEXTA_LOG_MESSAGE_DEBUG("get_variable(name = \"" << name << "\")...");
        if ((v = get_variable(name))) {
            TEXTA_LOG_MESSAGE_DEBUG("v->set_value(to = \"" << to << "\")...");
            variable_value& value = v->set_value(to);
            TEXTA_LOG_MESSAGE_DEBUG("...\"" << value << "\" = v->set_value(to = \"" << to << "\")");
            return true;
        }
        return false;
    }
    virtual bool value(string& from, const string& name) {
        variable* v = 0;
        TEXTA_LOG_MESSAGE_DEBUG("get_variable(name = \"" << name << "\")...");
        if ((v = get_variable(name))) {
            TEXTA_LOG_MESSAGE_DEBUG("from.assign(v->value() = \"" << v->value() << "\")...");
            from.assign(v->value());
            TEXTA_LOG_MESSAGE_DEBUG("...\"" << from << "\" = from.assign(v->value() = \"" << v->value() << "\")");
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual variable* get_variable(const string& name) {
        variable* v = 0;
        TEXTA_LOG_MESSAGE_DEBUG("find_variable(name = \"" << name << "\")...");
        if (!(v = find_variable(name))) {
            TEXTA_LOG_MESSAGE_DEBUG("new variable(name = \"" << name << "\")...");
            if ((v = new variable(name))) {
                TEXTA_LOG_MESSAGE_DEBUG("..." << pointer_to_string(v) << " = new variable(name = \"" << name << "\")");
                this->insert(v->branch());
                list_.queue(v->item());
            } else {
                TEXTA_LOG_ERROR("...unexpected 0 = new variable(name = " << name << ")");
            }
        } else {
            TEXTA_LOG_MESSAGE_DEBUG("..." << pointer_to_string(v) << "->chars() = " << chars_to_string(v->chars()) << " = find_variable(name = \"" << name << "\")");
        }
        return v;
    }
    virtual variable* find_variable(const string& name) const {
        variable named(name);
        variable* v = 0;
        variable_branch* b = 0;
        if ((b = this->find(named))) {
            v = &b->variable();
        }
        return v;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual variable_list& list() const {
        return (variable_list&)list_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    variable_list list_;
};

} // namespace t
} // namespace texta

#endif // _TEXTA_T_VARIABLE_TREE_HPP
