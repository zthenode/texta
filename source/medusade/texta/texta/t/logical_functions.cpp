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
///   File: logical_functions.cpp
///
/// Author: $author$
///   Date: 5/23/2016
///////////////////////////////////////////////////////////////////////
#include "texta/t/functions.hpp"

namespace texta {
namespace t {

///////////////////////////////////////////////////////////////////////
///  Class: and_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS and_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    and_function(const char *name, const char *description)
    : Extends(name, description) {
        static function_parameter parameter[]
        = {{"cond", "cond,..."},
           {0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const function_argument_list &args) const {
        function_argument *arg = 0;
        if ((arg = args.first_argument())) {
           result r;
           do {
               if ((arg->length())) {
                   r.append(*arg);
               } else {
                   return true;
               }
           } while ((arg = arg->next_argument()));
           out.write(r);
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_and_function
  ("and", "and(cond,...)");

///////////////////////////////////////////////////////////////////////
///  Class: or_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS or_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    or_function(const char *name, const char *description)
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
        function_argument *arg = 0;
        if ((arg = args.first_argument())) {
           do {
               if ((arg->length())) {
                   out.write(*arg);
                   break;
               }
           } while ((arg = arg->next_argument()));
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_or_function
  ("or", "or(cond,...)");

///////////////////////////////////////////////////////////////////////
///  Class: xor_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS xor_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    xor_function(const char *name, const char *description)
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
        function_argument *arg = 0;
        if ((arg = args.first_argument())) {
           result r;
           do {
               if ((arg->length())) {
                   if ((r.length())) {
                       return true;
                   }
                   r.append(*arg);
               }
           } while ((arg = arg->next_argument()));
           out.write(r);
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_xor_function
  ("xor", "xor(cond,...)");

///////////////////////////////////////////////////////////////////////
///  Class: not_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS not_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    not_function
    (const char *name, const char *description, const char *_true = "true")
    : Extends(name, description), true_(_true) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const function_argument_list &args) const {
        function_argument *arg = 0;
        if ((arg = args.first_argument())) {
           result r;
           do {
               if ((arg->length())) {
                   return true;
               } else {
                   r.append(true_);
               }
           } while ((arg = arg->next_argument()));
           out.write(r);
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string true_;
} the_not_function
  ("not", "not(cond,...)");

} // namespace t
} // namespace texta
