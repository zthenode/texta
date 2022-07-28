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
///   File: conditional_functions.cpp
///
/// Author: $author$
///   Date: 3/22/2016
///////////////////////////////////////////////////////////////////////
#include "texta/t/functions.hpp"

namespace texta {
namespace t {

///////////////////////////////////////////////////////////////////////
///  Class: if_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS if_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    if_function(const char *name, const char *description)
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
        function_argument *cond = 0, *expr = 0;
        if ((cond = args.first_argument())
            && (expr = cond->next_argument())) {
            if ((meets(*cond))) {
                if (!(p.expand(out, *expr))) {
                    return false;
                }
            } else {
                while ((expr = expr->next_argument())) {
                    if (!(p.expand(out, *expr))) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    virtual bool meets(const function_argument& cond) const {
        if (0 < (cond.length())) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_if_function
  ("if", "if(cond,(do),(else),...)");

///////////////////////////////////////////////////////////////////////
///  Class: else_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS else_function: public if_function {
public:
    typedef if_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    else_function(const char *name, const char *description)
    : Extends(name, description) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool meets(const function_argument& cond) const {
        if (1 > (cond.length())) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_else_function
  ("else", "else(cond,(do),(else)...)");

///////////////////////////////////////////////////////////////////////
///  Class: if_then_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS if_then_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    if_then_function(const char *name, const char *description)
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
        function_argument *a = 0;
        if ((a = args.first_argument())) {
            out.write(*a);
            if ((meets(*a))) {
                while ((a = a->next_argument())) {
                    p.expand(out, *a);
                }
            }
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool meets(const function_argument& cond) const {
        if (0 < (cond.length())) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_if_then_function
  ("if-then", "if-then(did,(do),...)");

///////////////////////////////////////////////////////////////////////
///  Class: else_then_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS else_then_function: public if_then_function {
public:
    typedef if_then_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    else_then_function(const char *name, const char *description)
    : Extends(name, description) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool meets(const function_argument& cond) const {
        if (1 > (cond.length())) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_else_then_function
  ("else-then", "else-then(did,(else),...)");

///////////////////////////////////////////////////////////////////////
///  Class: then_if_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS then_if_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    then_if_function(const char *name, const char *description)
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
        function_argument *todo = 0, *expr = 0;
        if ((todo = args.first_argument())) {
            if ((meets(*todo))) {
                if ((expr = todo->next_argument())) {
                    do {
                        p.expand(out, *expr);
                    } while ((expr = expr->next_argument()));
                }
                out.write(*todo);
            }
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool meets(const function_argument& cond) const {
        if (0 < (cond.length())) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_then_if_function
  ("then-if", "then-if(todo,(do),...)");

///////////////////////////////////////////////////////////////////////
///  Class: then_else_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS then_else_function: public then_if_function {
public:
    typedef then_if_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    then_else_function(const char *name, const char *description)
    : Extends(name, description) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool meets(const function_argument& cond) const {
        if (1 > (cond.length())) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_then_else_function
  ("then-else", "then-else(todo,(else),...)");

///////////////////////////////////////////////////////////////////////
///  Class: if_no_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS if_no_function: public if_function {
public:
    typedef if_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    if_no_function
    (const char *name, const char *description, const char* no = "no")
    : Extends(name, description), no_(no) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool meets(const function_argument& cond) const {
        if (!(cond.compare(no_))) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string no_;
} the_if_no_function
  ("if-no", "if-no(cond,(do),(else),...)");

///////////////////////////////////////////////////////////////////////
///  Class: else_no_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS else_no_function: public if_no_function {
public:
    typedef if_no_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    else_no_function
    (const char *name, const char *description, const char* no = "no")
    : Extends(name, description, no) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool meets(const function_argument& cond) const {
        if ((cond.compare(no_)) && (0 < (cond.length()))) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_else_no_function
  ("else-no", "else-no(cond,(do),(else),...)");

///////////////////////////////////////////////////////////////////////
///  Class: if_yes_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS if_yes_function: public if_no_function {
public:
    typedef if_no_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    if_yes_function
    (const char *name, const char *description, const char* yes = "yes")
    : Extends(name, description, yes) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_if_yes_function
  ("if-yes", "if-yes(cond,(do),(else),...)");

///////////////////////////////////////////////////////////////////////
///  Class: else_yes_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS else_yes_function: public else_no_function {
public:
    typedef else_no_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    else_yes_function
    (const char *name, const char *description, const char* yes = "yes")
    : Extends(name, description, yes) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_else_yes_function
  ("else-yes", "else-yes(cond,(do),(else),...)");

///////////////////////////////////////////////////////////////////////
///  Class: not_no_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS not_no_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    not_no_function
    (const char *name, const char *description, const char *no = "no")
    : Extends(name, description), no_(no) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const function_argument_list &args) const {
        function_argument *a = 0;
        if ((a = args.first_argument())) {
            do {
                if ((meets((*a)))) {
                    p.expand(out, *a);
                }
            } while ((a = a->next_argument()));
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool meets(const function_argument& cond) const {
        if ((cond.compare(no_)) && (0 < (cond.length()))) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string no_;
} the_not_no_function
  ("not-no", "not-no(cond,...)");

///////////////////////////////////////////////////////////////////////
///  Class: not_yes_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS not_yes_function: public not_no_function {
public:
    typedef not_no_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    not_yes_function
    (const char *name, const char *description, const char *no = "yes")
    : Extends(name, description, no) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_not_yes_function
  ("not-yes", "not-yes(cond,...)");

///////////////////////////////////////////////////////////////////////
///  Class: equal_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS equal_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    equal_function(const char *name, const char *description)
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
        function_argument *test = 0, *value = 0;
        if ((test = args.first_argument())) {
            bool is_equal = false;
            if ((value = test->next_argument())) {
                do {
                    if (!(is_equal = equal(*test, *value))) {
                        break;
                    }
                } while ((value = value->next_argument()));
            }
            if ((is_equal)) {
                out.write(*test);
            }
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool equal
    (const function_argument& a, const function_argument& to) const {
        if (!(a.compare(to))) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_equal_function
  ("equal", "equal(string,...)");

///////////////////////////////////////////////////////////////////////
///  Class: unequal_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS unequal_function: public equal_function {
public:
    typedef equal_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    unequal_function(const char *name, const char *description)
    : Extends(name, description) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool equal
    (const function_argument& a, const function_argument& to) const {
        if ((a.compare(to))) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_unequal_function
  ("unequal", "unequal(string,...)");

///////////////////////////////////////////////////////////////////////
///  Class: case_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS case_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    case_function(const char *name, const char *description)
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
        function_argument *cond = 0, *expr = 0;
        if ((cond = args.first_argument())) {
            if ((expr = cond->next_argument())) {
                do {
                    if ((meets(*cond))) {
                        p.expand(out, *expr);
                        break;
                    }
                    if ((cond = expr->next_argument())) {
                        if ((expr = cond->next_argument())) {
                        } else {
                            p.expand(out, *cond);
                        }
                    }
                } while ((cond) && (expr));
            } else {
                p.expand(out, *cond);
            }
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool meets(const function_argument& cond) const {
        if (0 < (cond.length())) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_case_function
  ("case", "case(when,(do)[[,...,when,(do),](otherwise)])");

///////////////////////////////////////////////////////////////////////
///  Class: switch_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS switch_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    switch_function(const char *name, const char *description)
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
        function_argument *cond = 0, *value = 0, *expr = 0;
        if ((cond = args.first_argument())) {
            if ((value = cond->next_argument())) {
                if ((expr = value->next_argument())) {
                    do {
                        if ((meets(*cond, *value))) {
                            p.expand(out, *expr);
                            break;
                        }
                        if ((value = expr->next_argument())) {
                            if ((expr = value->next_argument())) {
                            } else {
                                p.expand(out, *value);
                            }
                        }
                    } while ((value) && (expr));
                } else {
                    p.expand(out, *value);
                }
            }
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool meets
    (const function_argument& cond, const function_argument& value) const {
        if (!(cond.compare(value))) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_switch_function
  ("switch", "switch(cond,case,(do)[[,...,case,(do),](otherwise)])");

///////////////////////////////////////////////////////////////////////
///  Class: while_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS while_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    while_function(const char *name, const char *description)
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
        function_argument *cond = 0, *expr = 0;
        if ((cond = args.first_argument())) {
            if ((expr = cond->next_argument())) {
                bool met = false;
                function_argument test;
                do {
                    if ((p.expand(test, *cond))) {
                        cond->seek(0);
                        if ((met = meets(test))) {
                            if ((p.expand(out, *expr))) {
                                expr->seek(0);
                                test.clear();
                                continue;
                            }
                        }
                    }
                    break;
                } while ((met));
            }
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool meets(const function_argument& cond) const {
        if (0 < (cond.length())) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_while_function
  ("while", "while(cond,(do),...)");

///////////////////////////////////////////////////////////////////////
///  Class: until_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS until_function: public while_function {
public:
    typedef while_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    until_function(const char *name, const char *description)
    : Extends(name, description) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool meets(const function_argument& cond) const {
        if (1 > (cond.length())) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_until_function
  ("until", "until(cond,(do),...)");

///////////////////////////////////////////////////////////////////////
///  Class: do_while_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS do_while_function: public while_function {
public:
    typedef while_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    do_while_function(const char *name, const char *description)
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
        function_argument *cond = 0, *expr = 0;
        if ((cond = args.first_argument())) {
            if ((expr = cond->next_argument())) {
                bool met = false;
                function_argument test;
                do {
                    if ((p.expand(test, *cond))) {
                        if ((met = meets(test))) {
                            test.clear();
                            do {
                                if ((met = p.expand(out, *expr))) {
                                    continue;
                                }
                                break;
                            } while ((expr = expr->next_argument()));
                            continue;
                        }
                    }
                    break;
                } while ((met));
            }
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_do_while_function
  ("do-while", "do-while(cond,(do),...)");

///////////////////////////////////////////////////////////////////////
///  Class: do_until_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS do_until_function: public do_while_function {
public:
    typedef do_while_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    do_until_function(const char *name, const char *description)
    : Extends(name, description) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool meets(const function_argument& cond) const {
        if (1 > (cond.length())) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_do_until_function
  ("do-until", "do-until(cond,(do),...)");

} // namespace t
} // namespace texta 
