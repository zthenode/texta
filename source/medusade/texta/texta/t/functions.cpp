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
///   File: functions.cpp
///
/// Author: $author$
///   Date: 3/21/2016, 7/22/2022
///////////////////////////////////////////////////////////////////////
#include "texta/t/functions.hpp"

namespace texta {
namespace t {

///////////////////////////////////////////////////////////////////////
/// class parameters_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS parameters_function: public function_extend {
public:
    typedef function_extend Extends;
    typedef parameters_function Derives;

    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    parameters_function(const char* name, const char* description): Extends(name, description) {
        static function_parameter parameter[]
        = {{"named",""}, {"(before)",""}, {"(between)",""}, {"(after)",""}, 
           {"(do)",""}, {"name",""}, {"value",""},
           {0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand(output &out, processor &p, const function_argument_list &args) const {
        function_argument *named = 0, *before = 0, *between = 0, *after = 0, 
                          *expr = 0, *name = 0, *value = 0;

        if ((named = args.first_argument())) {
            if ((before = named->next_argument())) {
                if ((between = before->next_argument())) {
                    if ((after = between->next_argument())) {
                        if ((expr = after->next_argument())) {
                            if ((name = expr->next_argument())) {
                                value = name->next_argument();
                            }
                        }
                    }
                }
            }
        }
        if ((expr)) {
            if ((name)) {
                if ((value)) {
                    if ((name->length()) && (value->length())) {
                        processor::parameter *pp = 0;
                        const char *chars = 0;
                        size_t length = 0;
                        
                        if ((pp = p.first_parameter())) {
                            do {
                                if ((before) && (before->length())) {
                                    out.write(before->chars(), before->length());
                                }
                                if ((expr) && (expr->length())) {
                                    if ((chars = pp->has_chars(length))) {
                                        if ((p.push_variable(*name, chars))) {
                                            if ((chars = pp->value().chars(length))) {
                                                if ((p.push_variable(*value, chars))) {
                                                    p.expand(out, *expr);
                                                    expr->seek(0);
                                                    p.pop_variable(*value);
                                                }
                                            }
                                            p.pop_variable(*name);
                                        }
                                    }
                                }
                                if (pp = p.next_parameter(*pp)) {
                                    if ((between) && (between->length())) {
                                        out.write(between->chars(), between->length());
                                    }
                                }
                                if ((after) && (after->length())) {
                                    out.write(after->chars(), after->length());
                                }
                            } while (pp);
                        }
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
}; /// class parameters_function
parameters_function the_parameters_function
("parameters", "parameters(named,(before),(between),(after),(do),name,value)");

///////////////////////////////////////////////////////////////////////
///  Class: functions_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS functions_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    functions_function
    (const char *name, const char *description,
     const char *between_name = ":", const char *between = ";")
    : Extends(name, description),
      between_name_(between_name), between_(between) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const function_argument_list &args) const {
        function_argument *before = 0, *between = 0, *expr = 0, *name = 0, *desc = 0;
        function *f = 0;
        if ((before = args.first_argument())) {
            if ((between = before->next_argument())) {
                if ((expr = between->next_argument())) {
                    if ((name = expr->next_argument())) {
                        desc = name->next_argument();
                    }
                }
            }
        }
        if ((expr)) {
            if ((name) && (name->length())
                && (desc) && (desc->length())) {
                if ((f = p.first_function())) {
                    do {
                        if ((before) && (before->length())) {
                            out.write(before->chars(), before->length());
                        }
                        if ((p.push_variable(*name, f->name()))) {
                            if ((p.push_variable(*desc, f->description()))) {
                                p.expand(out, *expr);
                                expr->seek(0);
                                p.pop_variable(*desc);
                            }
                            p.pop_variable(*name);
                        }
                        if ((f = p.next_function(*f))) {
                            if ((between)) {
                                out.write(between->chars(), between->length());
                            }
                        }
                    } while (f);
                }
            }
        } else {
            if ((f = p.first_function())) {
                do {
                    if ((before) && (before->length())) {
                        out.write(before->chars(), before->length());
                    }
                    out.write(f->name());
                    out.write(between_name_);
                    out.write(f->description());
                    if ((f = p.next_function(*f))) {
                        if ((between)) {
                            out.write(between->chars(), between->length());
                        } else {
                            out.write(between_);
                        }
                    }
                } while (f);
            }
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string between_name_, between_;
} the_functions_function
  ("functions", "functions([(before),(between),(do),name,desc)]"),
  the_f_function
  ("f", "f([(before),(between),(do),name,desc)]");

///////////////////////////////////////////////////////////////////////
///  Class: function_parameters_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS function_parameters_function: public functions_function {
public:
    typedef functions_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    function_parameters_function(const char *name, const char *description)
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
        function_argument *func = 0, *before = 0, *between = 0, *expr = 0, *name = 0, *desc = 0;
        function *f = 0;
        const function_parameter *par = 0;
        size_t pars = 0;
        if ((func = args.first_argument())) {
            if ((before = func->next_argument())) {
                if ((between = before->next_argument())) {
                    if ((expr = between->next_argument())) {
                        if ((name = expr->next_argument())) {
                            desc = name->next_argument();
                        }
                    }
                }
            }
        }
        if ((f = p.find_function(*func))
            && (par = f->parameter(pars)) && (pars)) {
            if ((expr)) {
                if ((name) && (name->length())
                    && (desc) && (desc->length())) {
                    do {
                        if ((before) && (before->length())) {
                            out.write(before->chars(), before->length());
                        }
                        if ((p.push_variable(*name, par->name()))) {
                            if ((p.push_variable(*desc, par->description()))) {
                                p.expand(out, *expr);
                                expr->seek(0);
                                p.pop_variable(*desc);
                            }
                            p.pop_variable(*name);
                        }
                        if ((--pars)) {
                            par++;
                            if ((between)) {
                                out.write(between->chars(), between->length());
                            }
                        }
                    } while (pars);
                }
            } else {
                do {
                    if ((before) && (before->length())) {
                        out.write(before->chars(), before->length());
                    }
                    out.write(par->name());
                    out.write(between_name_);
                    out.write(par->description());
                    if ((--pars)) {
                        ++par;
                        if ((between)) {
                            out.write(between->chars(), between->length());
                        } else {
                            out.write(between_);
                        }
                    }
                } while (pars);
            }
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_function_parameters_function
  ("function-parameters", "function-parameters(function,(before),(between),(do),name,desc)"),
  the_p_function
  ("p", "p(function,(before),(between),(do),name,desc)");

} // namespace t
} // namespace texta 
