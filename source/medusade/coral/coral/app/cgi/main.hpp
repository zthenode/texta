///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2015 $organization$
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
///   Date: 1/26/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_APP_CGI_MAIN_HPP
#define _CORAL_APP_CGI_MAIN_HPP

#include "coral/inet/cgi/main.hpp"

namespace coral {
namespace app {
namespace cgi {

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
        io::main::err::writer err(*this);
        io::main::out::writer out(*this);
        io::main::argv::writer arguments;
        inet::cgi::environment::variables::writer environment;
        inet::http::form::fields::const_iterator b = form_.begin();
        inet::http::form::fields::const_iterator e = form_.end();
        const char_t *label, *name;

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
    virtual int run_console(int argc, char_t** argv, char_t** env) {
        outln("caught:");
        outln();
        return run_cgi(argc, argv, env);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace cgi 
} // namespace app 
} // namespace coral 

#endif // _CORAL_APP_CGI_MAIN_HPP 
