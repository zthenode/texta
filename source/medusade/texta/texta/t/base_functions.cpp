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
///   File: base_functions.cpp
///
/// Author: $author$
///   Date: 5/25/2016
///////////////////////////////////////////////////////////////////////
#include "texta/t/functions.hpp"

namespace texta {
namespace t {

///////////////////////////////////////////////////////////////////////
///  Class: do_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS do_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    do_function(const char *name, const char *description)
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
        for (function_argument_item* i = args.first(); i; i = i->next()) {
            function_argument& in = i->what();
            p.expand(out, in);
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_do_function
  ("do", "do((do),...)");

///////////////////////////////////////////////////////////////////////
///  Class: echo_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS echo_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    echo_function(const char *name, const char *description)
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
        for (function_argument_item* i = args.first(); i; i = i->next()) {
            function_argument& in = i->what();
            out.write(in);
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_echo_function
  ("echo", "echo(arg,...)");

///////////////////////////////////////////////////////////////////////
///  Class: exit_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS exit_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    exit_function(const char *name, const char *description)
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
        p.exit();
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_exit_function
  ("exit", "exit()");

///////////////////////////////////////////////////////////////////////
///  Class: set_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS set_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    set_function(const char *name, const char *description)
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
        function_argument *name = 0, *value = 0;
        if ((name = args.first_argument())
            && (value = name->next_argument())) {
            do {
                p.set_variable(*name, *value);
            } while
              ((name = value->next_argument())
               && (value = name->next_argument()));
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_set_function
  ("set", "set(name,value,...)");

///////////////////////////////////////////////////////////////////////
///  Class: get_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS get_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    get_function(const char *name, const char *description)
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
        function_argument *name = 0;
        if ((name = args.first_argument())) {
            variable* v = 0;
            do {
                if ((v = p.find_variable(*name))) {
                    out.write(v->value());
                }
            } while ((name = name->next_argument()));
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_get_function
  ("get", "get(name,...)");

} // namespace t
} // namespace texta
