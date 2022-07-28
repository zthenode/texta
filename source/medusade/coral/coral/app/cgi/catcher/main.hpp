///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2014 $organization$
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
///   Date: 12/30/2014
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_APP_CGI_CATCHER_MAIN_HPP
#define _CORAL_APP_CGI_CATCHER_MAIN_HPP

#include "coral/inet/cgi/main.hpp"

namespace coral {
namespace app {
namespace cgi {
namespace catcher {

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
    main() {
    }
    virtual ~main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_cgi(int argc, char_t** argv, char_t** env) {
        io::main::out::writer out(*this);
        io::main::argv::writer arguments;
        inet::cgi::environment::variables::writer environment;
        inet::http::form::fields::const_iterator b = form_.begin();
        inet::http::form::fields::const_iterator e = form_.end();
        const char_t *label, *name;

        outln("catching:");
        outln();

        for (inet::http::form::fields::const_iterator i = b; i != e; ++i) {
            inet::http::form::field f = *i;
            outl(f.name().chars(), " = \"", f.value().chars(), "\"", 0);
            outln();
        }
        outln();

        if ((label = catch_env_file_label_.chars())
            && (name = catch_env_file_name_.chars())) {
            if ((safe_open_file(file_, label, name, true))) {
                io::echoed::writer echoed(file_, out);
                outl(label, ": ", name, 0);
                outln();
                outln();
                environment.write(echoed, environment_);
                close_file(file_);
            }
        }

        if ((label = catch_argv_file_label_.chars())
            && (name = catch_argv_file_name_.chars())) {
            if ((safe_open_file(file_, label, name, true))) {
                io::echoed::writer echoed(file_, out);
                outl(label, ": ", name, 0);
                outln();
                outln();
                arguments.write(echoed, argc, argv);
                close_file(file_);
            }
        }

        if ((label = catch_stdin_file_label_.chars())
            && (name = catch_stdin_file_name_.chars())) {
            outl(label, ": ", name, 0);
            outln();
            outln();
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_console(int argc, char_t** argv, char_t** env) {
        io::main::out::writer out(*this);
        io::main::argv::writer arguments;
        inet::cgi::environment::variables::writer environment;
        inet::http::form::fields::const_iterator b = form_.begin();
        inet::http::form::fields::const_iterator e = form_.end();
        const char_t *label, *name;

        outln("caught:");
        outln();

        for (inet::http::form::fields::const_iterator i = b; i != e; ++i) {
            inet::http::form::field f = *i;
            outl(f.name().chars(), " = \"", f.value().chars(), "\"", 0);
            outln();
        }
        outln();

        if ((label = catch_env_file_label_.chars())
            && (name = catch_env_file_name_.chars())) {
            outl(label, ": ", name, 0);
            outln();
            outln();
            environment.write(out, environment_);
        }

        if ((label = catch_argv_file_label_.chars())
            && (name = catch_argv_file_name_.chars())) {
            outl(label, ": ", name, 0);
            outln();
            outln();
            arguments.write(out, argc, argv);
        }

        if ((label = catch_stdin_file_label_.chars())
            && (name = catch_stdin_file_name_.chars())) {
            outl(label, ": ", name, 0);
            outln();
            outln();
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int before_read_cgi_form_data
    (size_t content_length, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((is_cgi_run_)) {
            const char_t *label, *name;

            if ((label = catch_stdin_file_label_.chars())
                && (name = catch_stdin_file_name_.chars())) {
                if ((safe_open_file(file_, label, name, true))) {
                } else {
                    return 1;
                }
            }
        }
        return err;
    }
    virtual int after_read_cgi_form_data
    (size_t content_length, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((is_cgi_run_)) {
            close_file(file_);
        }
        return err;
    }
    virtual void on_read_content
    (const what_t* what, const sized_t* sized, size_t size) {
        if ((is_cgi_run_)) {
            ssize_t amount = file_.write(what, size);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    io::write::file file_;
};

} // namespace catcher
} // namespace cgi 
} // namespace app 
} // namespace coral 

#endif // _CORAL_APP_CGI_CATCHER_MAIN_HPP
