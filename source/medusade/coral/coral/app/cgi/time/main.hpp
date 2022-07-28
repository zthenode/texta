///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
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
///   File: main.hpp
///
/// Author: $author$
///   Date: 1/17/2017
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_APP_CGI_TIME_MAIN_HPP
#define _CORAL_APP_CGI_TIME_MAIN_HPP

#include "coral/app/cgi/main.hpp"
#include "coral/os/time.hpp"

namespace coral {
namespace app {
namespace cgi {
namespace time {

typedef inet::cgi::main_implements main_implements;
typedef inet::cgi::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main(bool has_date = false, bool has_time = true)
    : has_date_(has_date), has_time_(has_time),
      is_gmt_(false), is_12_(false) {
    }
    virtual ~main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_cgi(int argc, char_t** argv, char_t** env) {
        const char* chars = 0;
        size_t length = 0;
        string_t date;

        set_is(has_date_, "has_date");
        set_is(has_time_, "has_time");
        set_is(is_gmt_, "is_gmt");
        set_is(is_12_, "is_12");

        try {
            os::current::time t(is_gmt_, is_12_);

            if ((has_date_)) {
                date.append_unsigned(t.month());
                date.append("/");
                date.append_unsigned(t.day());
                date.append("/");
                date.append_unsigned(t.year());
            }

            if ((has_time_)) {
                if ((has_date_)) {
                    date.append(" ");
                }
                date.append_unsigned(t.hour());
                date.append(":");
                date.append_unsigned(t.minute());
                date.append(":");
                date.append_unsigned(t.second());
                if ((t.is_12())) {
                    date.append(" ");
                    if ((t.is_pm())) {
                        date.append("PM");
                    } else {
                        date.append("AM");
                    }
                }
            }
        } catch (const time_exception& e) {
            if ((has_date_)) {
                date.append("**/**/**");
            }
            if ((has_time_)) {
                if ((has_date_)) {
                    date.append(" ");
                }
                date.append("**:**:**");
            }
        }

        if ((chars = date.has_chars(length))) {
            this->out(chars, length);
        }
        return 0;
    }
    virtual bool set_is
    (bool& is, const char* name, const char* yes = "yes") {
        inet::http::form::field* f = 0;
        const char* chars = 0;
        size_t length = 0;

        if ((f = form().find(name))) {
            if ((chars = (f->value().has_chars()))) {
                if (!(chars_t::compare_uncased(chars, yes))) {
                    is = true;
                }
            }
        }
        return is;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool has_date_, has_time_, is_gmt_, is_12_;
};

} // namespace time
} // namespace cgi 
} // namespace app 
} // namespace coral 

#endif // _CORAL_APP_CGI_TIME_MAIN_HPP 
