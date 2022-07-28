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
///   File: variable.hpp
///
/// Author: $author$
///   Date: 3/21/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_VARIABLE_HPP
#define _TEXTA_T_VARIABLE_HPP

#include "texta/t/variable_branch.hpp"
#include "texta/t/variable_item.hpp"
#include "texta/t/value_list.hpp"
#include "texta/t/value.hpp"
#include "texta/io/logger.hpp"

namespace texta {
namespace t {

typedef value variable_value;
typedef value_list variable_value_list;
typedef variable_leaf_implements variable_implements;
typedef variable_leaf variable_extends;
///////////////////////////////////////////////////////////////////////
///  Class: variable
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS variable
: virtual public variable_implements, public variable_extends {
public:
    typedef variable_implements Implements;
    typedef variable_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    variable(const char* name, const char* value)
    : Extends(name, *this), branch_(*this), item_(*this) {
        values_.push(value_.item());
        set_value(value);
    }
    variable(const char* name)
    : Extends(name, *this), branch_(*this), item_(*this) {
        values_.push(value_.item());
    }
    variable(const string& name, const string& value)
    : Extends(name, *this), branch_(*this), item_(*this) {
        values_.push(value_.item());
        set_value(value);
    }
    variable(const string& name)
    : Extends(name, *this), branch_(*this), item_(*this) {
        values_.push(value_.item());
    }
    variable(const variable& copy)
    : Extends(copy), branch_(*this), item_(*this) {
        values_.push(value_.item());
    }
    virtual ~variable() {
        for (value_item* i = values_.pop(); i; i = values_.pop()) {
            //variable_value* v = &i->what();
            variable_value* v = &((variable_value&)(i->what()));
            if (&value_ != v) {
                TEXTA_LOG_MESSAGE_DEBUG("delete v = " << pointer_to_string(v) << "->chars() = " << chars_to_string(v->chars()) << "...");
                delete v;
                TEXTA_LOG_MESSAGE_DEBUG("...delete v = " << pointer_to_string(v));
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool push_value(variable_value& v) {
        values_.push(v.item());
        return true;
    }
    virtual bool push_value(const string& to) {
        variable_value* v = 0;
        if ((v = new variable_value(to))) {
            values_.push(v->item());
            return true;
        } else {
            TEXTA_LOG_ERROR("...unexpected 0 = new variable_value(to = \"" << to << "\")");
        }
        return false;
    }
    virtual bool pop_value() {
        value_item* i = 0;
        if ((i = values_.first())) {
            //variable_value* v = &i->what();
            variable_value* v = &((variable_value&)(i->what()));
            if (&value_ != v) {
                TEXTA_LOG_MESSAGE_DEBUG("values_.pop()...");
                values_.pop();
                TEXTA_LOG_MESSAGE_DEBUG("delete v = " << pointer_to_string(v) << "->chars() = " << chars_to_string(v->chars()) << "...");
                delete v;
                TEXTA_LOG_MESSAGE_DEBUG("...delete v = " << pointer_to_string(v));
                return true;
            } else {
                TEXTA_LOG_ERROR("...unexpected &value_ (" << pointer_to_string(&value_) << ") != v (" << pointer_to_string(v) << ")");
            }
        } else {
            TEXTA_LOG_ERROR("...unexpected 0 = values_.first()");
        }
        return false;
    }
    virtual variable_value& set_value(const string& to) {
        this->value().assign(to);
        return this->value();
    }
    virtual variable_value& value() const {
        value_item* i = values_.first();
        if ((i)) {
            return i->what();
        } else {
            TEXTA_LOG_ERROR("...unexpected 0 = values_.first()");
        }
        return (variable_value&)value_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual variable_branch& branch() const {
        return (variable_branch&)branch_;
    }
    virtual variable_item& item() const {
        return (variable_item&)item_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    variable_branch branch_;
    variable_item item_;
    variable_value value_;
    variable_value_list values_;
};

} // namespace t
} // namespace texta 

#endif // _TEXTA_T_VARIABLE_HPP 
