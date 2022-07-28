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
///   File: block_functions.cpp
///
/// Author: $author$
///   Date: 5/23/2016
///////////////////////////////////////////////////////////////////////
#include "texta/t/functions.hpp"

namespace texta {
namespace t {

///////////////////////////////////////////////////////////////////////
///  Class: apply_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS apply_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    apply_function(const char *name, const char *description)
    : Extends(name, description) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const function_argument_list &args) const {
        function_argument *name = 0, *value = 0, *expr = 0;
        if ((name = args.first_argument())) {
            if ((value = name->next_argument())) {
                variable* v = 0;
                variable_list vars;
                do {
                    TEXTA_LOG_MESSAGE_DEBUG("new variable(*name = \"" << *name << "\")...");
                    if ((v = new variable(*name))) {
                        TEXTA_LOG_MESSAGE_DEBUG("..." << pointer_to_string(v) << " = new variable(*name = \"" << *name << "\")");
                        if ((push_variable(p, *name, *value))) {
                            vars.push(v->item());
                        } else {
                            TEXTA_LOG_MESSAGE_DEBUG("delete v = " << pointer_to_string(v) << "->chars() = " << chars_to_string(v->chars()) << "...");
                            delete v;
                            TEXTA_LOG_MESSAGE_DEBUG("...delete v = " << pointer_to_string(v) << ")");
                        }
                    }
                    if ((name = value->next_argument())) {
                        if (!(value = name->next_argument())) {
                            expr = name;
                        }
                    }
                } while ((name) && (value));
                if ((expr)) {
                    p.expand(out, *expr);
                }
                while (v = (vars.pop_variable())) {
                    p.pop_variable(*v);
                    TEXTA_LOG_MESSAGE_DEBUG("delete v = " << pointer_to_string(v) << "->chars() = " << chars_to_string(v->chars()) << "...");
                    delete v;
                    TEXTA_LOG_MESSAGE_DEBUG("...delete v = " << pointer_to_string(v) << ")");
                }
            } else {
                p.expand(out, *name);
            }
        } else {
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool push_variable
    (processor &p, const string& name, result& value) const {
        if ((p.push_variable(name, value))) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_apply_function
  ("apply", "apply([name,value,...,](do))");

///////////////////////////////////////////////////////////////////////
///  Class: with_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS with_function: public apply_function {
public:
    typedef apply_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    with_function(const char *name, const char *description)
    : Extends(name, description) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool push_variable
    (processor &p, const string& name, result& value) const {
        if ((p.push_variable_expand(name, value))) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_with_function
  ("with", "with([name,(value),...,](do))"),
  the_apply_x_function
  ("apply-x", "apply-x([name,(value),...,](do))");

} // namespace t
} // namespace texta
