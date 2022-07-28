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
///   File: string_functions.cpp
///
/// Author: $author$
///   Date: 3/22/2016
///////////////////////////////////////////////////////////////////////
#include "texta/t/functions.hpp"

namespace texta {
namespace t {

///////////////////////////////////////////////////////////////////////
///  Class: parse_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS parse_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    parse_function(const char *name, const char *description)
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
        function_argument
            *val = 0, *delim = 0,
            *before = 0, *between = 0, *after = 0,
            *expr = 0, *var = 0;

        if ((val = args.first_argument()) && (0 < val->length())
            && ((delim = val->next_argument())) && (0 < delim->length())) {
            if ((before = delim->next_argument())) {
                if ((between = before->next_argument())) {
                    if ((after = between->next_argument())) {
                        if ((expr = after->next_argument())) {
                            if ((var = expr->next_argument())) {
                                // parse(val,delim,before,between,after,expr,var)
                                if (1 > (var->length())) var = 0;
                            } else {
                                // parse(val,delim,before,between,expr,var)
                                var = expr;
                                expr = after;
                                after = 0;
                            }
                            if ((expr) && (1 > (expr->length()))) expr = 0;
                        } else {
                            // parse(val,delim,before,between,after)
                        }
                        if ((after) && (1 > (after->length()))) after = 0;
                    } else {
                        // parse(val,delim,before,between)
                    }
                    if ((between) && (1 > (between->length()))) between = 0;
                } else {
                    // parse(val,delim,before)
                }
                if ((before) && (1 > (before->length()))) before = 0;
            } else {
                // parse(val,delim)
            }
            expand
            (out, p, val->chars(), val->length(),
             delim->chars(), delim->length(),
             before, between, after, expr, var);
        }
        return true;
    }
    virtual bool expand
    (output &out, processor &p,
     const char *val, size_t val_length, const char *delim, size_t delim_length,
     function_argument *before, function_argument *between, function_argument *after,
     function_argument *expr, function_argument *var) const {
        if (val_length) {
            const char *chars = val, *found = 0;
            TEXTA_LOG_MESSAGE_DEBUG("chars_t::find(\"" << chars << "\", \"" << delim << "\")...");
            if ((found = chars_t::find(chars, delim))) {
                TEXTA_LOG_MESSAGE_DEBUG("..." << chars_to_string(chars, found - chars) << " = chars_t::find(\"" << chars << "\", \"" << delim << "\")");
                do {
                    if ((before)) {
                        p.expand(out, *before);
                        before->seek(0);
                    }
                    expand(out, p, chars, found - chars, expr, var);
                    if ((between)) {
                        p.expand(out, *between);
                        between->seek(0);
                    }
                    chars = (found + delim_length);
                    TEXTA_LOG_MESSAGE_DEBUG("chars_t::find(\"" << chars << "\", \"" << delim << "\")...");
                    if (!(found = chars_t::find(chars, delim))) {
                        if (val_length > (chars - val)) {
                            expand(out, p, chars, val_length - (chars - val), expr, var);
                        }
                    } else {
                        TEXTA_LOG_MESSAGE_DEBUG("..." << chars_to_string(chars, found - chars) << " = chars_t::find(\"" << chars << "\", \"" << delim << "\")");
                    }
                    if ((after)) {
                        p.expand(out, *after);
                        after->seek(0);
                    }
                } while (found);
            } else {
                expand(out, p, chars, val_length, before, after, expr, var);
            }
        }
        return true;
    }
    virtual bool expand
    (output &out, processor &p,
     const char *chars, size_t length,
     function_argument *before, function_argument *after,
     function_argument *expr, function_argument *var) const {
        if ((before)) {
            p.expand(out, *before);
            before->seek(0);
        }
        expand(out, p, chars, length, expr, var);
        if ((after)) {
            p.expand(out, *after);
            after->seek(0);
        }
        return true;
    }
    virtual bool expand
    (output &out, processor &p,
     const char *chars, size_t length,
     function_argument *expr, function_argument *var) const {
        if ((expr)) {
            if ((var)) {
                string val(chars, length);
                p.push_variable(*var, val);
            }
            p.expand(out, *expr);
            expr->seek(0);
            if ((var)) {
                p.pop_variable(*var);
            }
        } else {
            out.write(chars, length);
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_parse_function
  ("parse", "parse(string,delim[,(before)[,(between)[,[(after),](expr),var]]])"),
  the_lparse_function
  ("lparse", "lparse(string,delim[,(before)[,(between)[,[(after),](expr),var]]])");

///////////////////////////////////////////////////////////////////////
///  Class: reverse_parse_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS reverse_parse_function: public parse_function {
public:
    typedef parse_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    reverse_parse_function(const char *name, const char *description)
    : Extends(name, description) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::expand;
    virtual bool expand
    (output &out, processor &p,
     const char *val, size_t val_length, const char *delim, size_t delim_length,
     function_argument *before, function_argument *between, function_argument *after,
     function_argument *expr, function_argument *var) const {
        if (val_length) {
            const char *chars = val, *begin = chars, *end = chars + val_length, *found = 0;
            TEXTA_LOG_MESSAGE_DEBUG("chars_t::find_reverse(\"" << chars << "\", \"" << delim << "\", 0, " << delim_length << ", " << (end - chars) << ")...");
            if ((found = chars_t::find_reverse(chars, delim))) {
                begin = found + delim_length;
                TEXTA_LOG_MESSAGE_DEBUG("..." << chars_to_string(begin, end - begin) << " = chars_t::find_reverse(\"" << chars << "\", \"" << delim << "\", 0, " << delim_length << ", " << (end - chars) << ")");
                do {
                    if ((before)) {
                        p.expand(out, *before);
                        before->seek(0);
                    }
                    expand(out, p, begin, end - begin, expr, var);
                    if ((between)) {
                        p.expand(out, *between);
                        between->seek(0);
                    }
                    end = found;
                    TEXTA_LOG_MESSAGE_DEBUG("chars_t::find_reverse(" << chars_to_string(chars, end - chars) << ", \"" << delim << "\", 0, " << delim_length << ", " << (end - chars) << ")...");
                    if (!(found = chars_t::find_reverse (chars, delim, 0, delim_length, end - chars))) {
                        if (0 < (end - chars)) {
                            expand(out, p, chars, (end - chars), expr, var);
                        }
                    } else {
                        begin = found + delim_length;
                        TEXTA_LOG_MESSAGE_DEBUG("..." << chars_to_string(begin, end - begin) << " = chars_t::find_reverse(" << chars_to_string(chars, end - chars) << ", \"" << delim << "\", 0, " << delim_length << ", " << (end - chars) << ")");
                    }
                    if ((after)) {
                        p.expand(out, *after);
                        after->seek(0);
                    }
                } while (found);
            } else {
                expand(out, p, val, val_length, before, after, expr, var);
            }
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_reverse_parse_function
  ("reverse-parse", "reverse-parse(string,delim[,(before)[,(between)[,[(after),](expr),var]]])"),
  the_rparse_function
  ("rparse", "rparse(string,delim[,(before)[,(between)[,[(after),](expr),var]]])");

  ///////////////////////////////////////////////////////////////////////
  ///  Class: parseln_function
  ///////////////////////////////////////////////////////////////////////
  class _EXPORT_CLASS parseln_function: public parse_function {
  public:
      typedef parse_function Extends;
      typedef parseln_function Derives;
      ///////////////////////////////////////////////////////////////////////
      ///////////////////////////////////////////////////////////////////////
      parseln_function(const char *name, const char *description)
      : Extends(name, description) {
          static function_parameter parameter[]
          = {{0,0}};
          set_parameter(parameter);
      }
      ///////////////////////////////////////////////////////////////////////
      ///////////////////////////////////////////////////////////////////////
      using Extends::expand;
      virtual bool expand
      (output &out, processor &p,
       const function_argument_list &args) const {
          function_argument
              *val = 0,
              *before = 0, *between = 0, *after = 0,
              *expr = 0, *var = 0;

          if ((val = args.first_argument()) && (0 < val->length())) {
              if ((before = val->next_argument())) {
                  if ((between = before->next_argument())) {
                      if ((after = between->next_argument())) {
                          if ((expr = after->next_argument())) {
                              if ((var = expr->next_argument())) {
                                  if (1 > (var->length())) var = 0;
                              }
                              if (1 > (expr->length())) expr = 0;
                          }
                          if (1 > (after->length())) after = 0;
                      }
                      if (1 > (between->length())) between = 0;
                  }
                  if (1 > (before->length())) before = 0;
              }
              expand
              (out, p, val->chars(), val->length(),
               before, between, after, expr, var);
          }
          return true;
      }
      virtual bool expand
      (output &out, processor &p,
       const char *val, size_t val_length,
       function_argument *before, function_argument *between, function_argument *after,
       function_argument *expr, function_argument *var) const {
          if (val_length) {
              size_t begin = 0; on_t on = on_char;
              const char *chars = val, *found = 0;
              TEXTA_LOG_MESSAGE_DEBUG("find(\"" << chars << "\")...");
              if ((found = find(chars, begin, on))) {
                  TEXTA_LOG_MESSAGE_DEBUG("..." << chars_to_string(chars, found - chars) << " = find(\"" << chars << "\")");
                  do {
                      chars += begin;
                      expand
                      (out, p, chars, found - chars,
                       before, after, expr, var);
                      if ((between)) {
                          out.write(between->chars());
                      }
                      chars = (found + 1);
                      TEXTA_LOG_MESSAGE_DEBUG("find(\"" << chars << "\")...");
                      if ((found = find(chars, begin, on))) {
                          TEXTA_LOG_MESSAGE_DEBUG("..." << chars_to_string(chars, found - chars) << " = find(\"" << chars << "\")");
                      } else {
                          if (val_length > (chars - val)) {
                              expand
                              (out, p, chars,
                               val_length - (chars - val),
                               before, after, expr, var);
                          }
                      }
                  } while (found);
              } else {
                  expand
                  (out, p, chars, val_length,
                   before, after, expr, var);
              }
          }
          return true;
      }
      ///////////////////////////////////////////////////////////////////////
      ///////////////////////////////////////////////////////////////////////
      enum on_t { on_char, on_cr, on_lf };
      virtual const char* find(const char* chars, size_t& begin, on_t& on) const {
          begin = 0;
          for (char c = *chars; c; c = *++chars) {
              switch(c) {
              case '\r':
                  on = on_cr;
                  return chars;
                  break;
              case '\n':
                  switch(on) {
                  case on_cr: // '\r''\n'
                      begin = 1;
                      on = on_char;
                      break;
                  default:
                      on = on_lf;
                      return chars;
                      break;
                  }
                  break;
              default:
                  on = on_char;
                  break;
              }
          }
          return 0;
      }
      ///////////////////////////////////////////////////////////////////////
      ///////////////////////////////////////////////////////////////////////
  } the_parseln_function
    ("parseln", "parse(string,[,(before)[,(between)[,[(after),](expr),var]]])"),
    the_lparseln_function
    ("lparseln", "lparse(string,[,(before)[,(between)[,[(after),](expr),var]]])");

///////////////////////////////////////////////////////////////////////
///  Class: left_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS left_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    left_function(const char *name, const char *description)
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
        function_argument *val = 0, *delim = 0;
        if ((val = args.first_argument()) && (0 < val->length())
            && (delim = val->next_argument()) && (0 < delim->length())) {
            return expand
            (out, p, val->chars(), val->length(),
             delim->chars(), delim->length());
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const char *val_chars, size_t val_length,
     const char *delim_chars, size_t delim_length) const {
        const char *found = 0;
        TEXTA_LOG_MESSAGE_DEBUG("chars_t::find(" << chars_to_string(val_chars) << ", " << chars_to_string(delim_chars) << ")...");
        if ((found = chars_t::find(val_chars, delim_chars))) {
            TEXTA_LOG_MESSAGE_DEBUG("..." << chars_to_string(val_chars, found - val_chars) << " = chars_t::find(" << chars_to_string(val_chars) << ", " << chars_to_string(delim_chars) << ")");
            expand(out, p, found, val_chars, val_length, delim_chars, delim_length);
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const char *found,
     const char *val_chars, size_t val_length,
     const char *delim_chars, size_t delim_length) const {
        out.write(val_chars, found - val_chars);
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_left_function
  ("left", "left(string,pattern)"),
  the_l_function
  ("l", "l(string,pattern)");

///////////////////////////////////////////////////////////////////////
///  Class: right_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS right_function: public left_function {
public:
    typedef left_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    right_function(const char *name, const char *description)
    : Extends(name, description) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const char *val_chars, size_t val_length,
     const char *delim_chars, size_t delim_length) const {
        const char *found = 0;
        TEXTA_LOG_MESSAGE_DEBUG("chars_t::find_reverse(" << chars_to_string(val_chars) << ", " << chars_to_string(delim_chars) << ")...");
        if ((found = chars_t::find_reverse(val_chars, delim_chars))) {
            TEXTA_LOG_MESSAGE_DEBUG("..." << chars_to_string(found + delim_length) << " = chars_t::find_reverse(" << chars_to_string(val_chars) << ", " << chars_to_string(delim_chars) << ")");
            expand(out, p, found, val_chars, val_length, delim_chars, delim_length);
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const char *found,
     const char *val_chars, size_t val_length,
     const char *delim_chars, size_t delim_length) const {
        out.write(found + delim_length, val_chars + val_length - (found + delim_length));
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_right_function
  ("right", "right(string,pattern)"),
  the_r_function
   ("r", "r(string,pattern)");

///////////////////////////////////////////////////////////////////////
///  Class: left_of_right_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS left_of_right_function: public right_function {
public:
    typedef right_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    left_of_right_function(const char *name, const char *description)
    : Extends(name, description) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const char *found,
     const char *val_chars, size_t val_length,
     const char *delim_chars, size_t delim_length) const {
        out.write(val_chars, found - val_chars);
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_left_of_right_function
  ("left-of-right", "left-of-right(string,pattern)"),
  the_lr_function
  ("lr", "lr(string,pattern)");

///////////////////////////////////////////////////////////////////////
///  Class: right_of_left_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS right_of_left_function: public left_function {
public:
    typedef left_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    right_of_left_function(const char *name, const char *description)
    : Extends(name, description) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const char *found,
     const char *val_chars, size_t val_length,
     const char *delim_chars, size_t delim_length) const {
        out.write(found + delim_length, val_length - (found + delim_length - val_chars));
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_right_of_left_function
  ("right-of-left", "right-of-left(string,pattern)"),
  the_rl_function
  ("rl", "rl(string,pattern)");

///////////////////////////////////////////////////////////////////////
///  Class: left_char_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS left_char_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    left_char_function(const char *name, const char *description)
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
        function_argument *val = 0;
        if ((val = args.first_argument()) && (0 < val->length())) {
            out.write(val->chars(), 1);
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_left_char_function
  ("left-char", "left-char(string)"),
  the_lc_function
  ("lc", "lc(string)");

///////////////////////////////////////////////////////////////////////
///  Class: right_char_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS right_char_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    right_char_function(const char *name, const char *description)
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
        function_argument *val = 0;
        if ((val = args.first_argument()) && (0 < val->length())) {
            out.write(val->chars() + val->length() - 1, 1);
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_right_char_function
  ("right-char", "right-char(string)"),
  the_rc_function
  ("rc", "rc(string)");

///////////////////////////////////////////////////////////////////////
///  Class: left_of_right_char_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS left_of_right_char_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    left_of_right_char_function(const char *name, const char *description)
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
        function_argument *val = 0;
        if ((val = args.first_argument()) && (1 < val->length())) {
            out.write(val->chars(), val->length() - 1);
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_left_of_right_char_function
  ("left-of-right-char", "left-of-right-char(string)"),
  the_lrc_function
  ("lrc", "lrc(string)"),
  the_left_chars_function
  ("left-chars", "left-chars(string)");

///////////////////////////////////////////////////////////////////////
///  Class: right_of_left_char_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS right_of_left_char_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    right_of_left_char_function(const char *name, const char *description)
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
        function_argument *val = 0;
        if ((val = args.first_argument()) && (1 < val->length())) {
            out.write(val->chars() + 1, val->length() - 1);
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_right_of_left_char_function
  ("right-of-left-char", "right-of-left-char(string)"),
  the_rlc_function
  ("rlc", "rlc(string)"),
  the_right_chars_function
  ("right-chars", "right-chars(string)");

///////////////////////////////////////////////////////////////////////
///  Class: padd_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS padd_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    padd_function(const char *name, const char *description)
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
        size_t length = 0;
        if ((arg = args.first_argument())) {
            out.write(arg->chars(), (length = arg->length()));
            expand(out, p, arg, length);
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     function_argument *arg, size_t length) const {
        function_argument *padding = 0, *paddlen = 0;
        size_t padding_length = 0, padd_length = 0;
        if ((padding = arg->next_argument()) && (padding_length = padding->length())
            && (paddlen = padding->next_argument()) && (paddlen->length())) {
            if ((0 < (padd_length = paddlen->to_unsigned())) && (padd_length > length)) {
                do {
                    if (length + padding_length > padd_length) {
                        padding_length = padd_length - length;
                    }
                    out.write(padding->chars(), padding_length);
                    padd_length -= padding_length;
                } while (padd_length > length);
            }
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_padd_function
  ("padd", "padd(string,...,padding,padlen)"),
  the_rpadd_function
  ("rpadd", "rpadd(string,...,padding,padlen)"),
  the_right_padd_function
  ("right-padd", "right-padd(string,...,padding,padlen)"),
  the_strpad_function
  ("strpad", "strpad(string,...,padding,padlen)");

///////////////////////////////////////////////////////////////////////
///  Class: left_padd_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS left_padd_function: public padd_function {
public:
    typedef padd_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    left_padd_function(const char *name, const char *description)
    : Extends(name, description) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::expand;
    virtual bool expand
    (output &out, processor &p,
     const function_argument_list &args) const {
        function_argument *arg = 0;
        size_t length = 0;
        if ((arg = args.first_argument())) {
            expand(out, p, arg, length = arg->length());
            out.write(arg->chars(), length);
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_left_padd_function
  ("left-padd", "left-padd(string,...,padding,padlen)"),
  the_lpadd_function
  ("lpadd", "lpadd(string,...,padding,padlen)"),
  the_lp_function
  ("lp", "lp(string,...,padding,padlen)");

///////////////////////////////////////////////////////////////////////
///  Class: replace_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS replace_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    replace_function(const char *name, const char *description)
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
        function_argument *from = 0, *to = 0, *arg = 0;
        if ((from = args.first_argument())
            && (to = from->next_argument())
            && (arg = to->next_argument())){
            do {
                if (!(expand
                    (out, p,
                     from->chars(), from->length(),
                     to->chars(), to->length(),
                     arg->chars(), arg->length()))) {
                    break;
                }
            } while ((arg = arg->next_argument()));
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const char *from, size_t from_length,
     const char *to, size_t to_length,
     const char *chars, size_t length) const {
        if ((length)) {
            if ((from_length)) {
                const char *found = 0;
                do {
                    if ((found = chars_t::find(chars, from))) {
                        out.write(chars, found - chars);
                        out.write(to, to_length);
                        length -= ((found - chars) + from_length);
                        chars = found + from_length;
                    } else {
                        out.write(chars, length);
                    }
                } while ((found));
            } else {
                out.write(chars, length);
            }
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_replace_function
  ("replace", "replace(from,to,string,...)");

///////////////////////////////////////////////////////////////////////
///  Class: tolower_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS tolower_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    tolower_function(const char *name, const char *description)
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
        for (arg = args.first_argument(); arg; arg = arg->next_argument()) {
            expand(out, p, arg->chars(), arg->length());
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const char *chars, size_t length) const {
        for (char c = 0; (chars) && (length); --length, ++chars) {
            if (((c = *chars) >= 'A') && (c <= 'Z')) {
                c = (c - 'A') + 'a';
            }
            out.write(&c, 1);
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_tolower_function
  ("tolower", "tolower(string,...)");

///////////////////////////////////////////////////////////////////////
///  Class: toupper_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS toupper_function: public tolower_function {
public:
    typedef tolower_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    toupper_function(const char *name, const char *description)
    : Extends(name, description) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const char *chars, size_t length) const {
        for (char c = 0; (chars) && (length); --length, ++chars) {
            if (((c = *chars) >= 'a') && (c <= 'z')) {
                c = (c - 'a') + 'A';
            }
            out.write(&c, 1);
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_toupper_function
  ("toupper", "toupper(string,...)");

///////////////////////////////////////////////////////////////////////
///  Class: length_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS length_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    length_function(const char *name, const char *description)
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
        size_t length = 0;
        for (arg = args.first_argument(); arg; arg = arg->next_argument()) {
            length += arg->length();
        }
        out.write(length);
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_length_function
  ("length", "length(string,...)"),
  the_strlen_function
  ("strlen", "strlen(string,...)");

} // namespace t
} // namespace texta
