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
///   File: main.hpp
///
/// Author: $author$
///   Date: 3/18/2016, 6/28/2022
/// 
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_APP_CONSOLE_TEXTA_MAIN_HPP
#define _TEXTA_APP_CONSOLE_TEXTA_MAIN_HPP

#include "texta/console/main.hpp"
#include "texta/t/processor.hpp"
#include "texta/t/function_list.hpp"
#include "texta/io/logger.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define TEXTA_APP_CONSOLE_TEXTA_MAIN_PARAMETER_OPT "parameter"
#define TEXTA_APP_CONSOLE_TEXTA_MAIN_PARAMETER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define TEXTA_APP_CONSOLE_TEXTA_MAIN_PARAMETER_OPTARG_RESULT 0
#define TEXTA_APP_CONSOLE_TEXTA_MAIN_PARAMETER_OPTARG ""
#define TEXTA_APP_CONSOLE_TEXTA_MAIN_PARAMETER_OPTUSE ""
#define TEXTA_APP_CONSOLE_TEXTA_MAIN_PARAMETER_OPTVAL_S "p:"
#define TEXTA_APP_CONSOLE_TEXTA_MAIN_PARAMETER_OPTVAL_C 'p'
#define TEXTA_APP_CONSOLE_TEXTA_MAIN_PARAMETER_OPTION \
   {TEXTA_APP_CONSOLE_TEXTA_MAIN_PARAMETER_OPT, \
    TEXTA_APP_CONSOLE_TEXTA_MAIN_PARAMETER_OPTARG_REQUIRED, \
    TEXTA_APP_CONSOLE_TEXTA_MAIN_PARAMETER_OPTARG_RESULT, \
    TEXTA_APP_CONSOLE_TEXTA_MAIN_PARAMETER_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define TEXTA_APP_CONSOLE_TEXTA_MAIN_OPTIONS_CHARS \
   TEXTA_APP_CONSOLE_TEXTA_MAIN_PARAMETER_OPTVAL_S \
   TEXTA_CONSOLE_MAIN_OPTIONS_CHARS

#define TEXTA_APP_CONSOLE_TEXTA_MAIN_OPTIONS_OPTIONS \
   TEXTA_APP_CONSOLE_TEXTA_MAIN_PARAMETER_OPTION \
   TEXTA_CONSOLE_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define TEXTA_APP_CONSOLE_TEXTA_MAIN_ARGS 0
#define TEXTA_APP_CONSOLE_TEXTA_MAIN_ARGV

namespace texta {
namespace app {
namespace console {
namespace texta {

typedef ::texta::console::main_implements main_implements;
typedef ::texta::console::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main
: virtual public main_implements, public main_extends {
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
    class _EXPORT_CLASS output: public ::texta::t::output {
    public:
        output(main_extends& main): main_(main) {}
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual ssize_t write(const char* out, ssize_t length) {
            ssize_t count = main_.out(out, length);
            return count;
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
        main_extends& main_;
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS input: public ::texta::t::input {
    public:
        input(main_extends& main): main_(main) {}
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual ssize_t read(char* in, size_t size) {
            ssize_t count = main_.in(in, size);
            return count;
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
        main_extends& main_;
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        ::texta::t::processor p;

        if ((p.init())) {
            if ((set_variables(p, parameters_))) {
                ssize_t count = 0;
                output out(*this);
                
                if ((optind >= argc)) {
                    input in(*this);

                    count = p.expand(out, in);
                } else {
                    const char_t* arg = 0;

                    if ((argv) && (arg = argv[optind]) && (arg[0])) {
                        ::texta::t::input_file in;

                        if ((in.open(arg))) {
                            count = p.expand(out, in);
                            in.close();
                        }
                    }
                }
            }
            p.fini();
        }
        return err;
    }
    virtual bool set_variables
    (::texta::t::processor &p, ::texta::t::variable_list &l) {
        ::texta::t::variable_item *i = 0;
        bool success = true;
        for (i = l.first(); i; i = i->next()) {
            //if (!(success = p.set_variable(i->what(), i->what().value()))) {
            ::texta::t::variable& v = ((::texta::t::variable&)(i->what()));
            if (!(success = p.set_variable(v, v.value()))) {
                break;
            }
        }
        while ((i = l.pop())) {
            //delete &i->what();
            delete &((::texta::t::variable&)(i->what()));
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_parameter_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            const char_t *found = 0;
            TEXTA_LOG_MESSAGE_DEBUG("on_parameter_option(..., optarg = \"" << optarg << "\"...)...");
            if ((found = chars_t::find(optarg, "="))
                && (found > optarg) && (found[1])) {
                string name(optarg, found - optarg), value(found + 1);
                ::texta::t::variable *p = 0;
                TEXTA_LOG_MESSAGE_DEBUG("...name = \"" << name << "\" value = \"" << value << "\" on_parameter_option(..., optarg = \"" << optarg << "\"...)");
                if ((p = new ::texta::t::variable(name, value))) {
                    parameters_.queue(p->item());
                }
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case TEXTA_APP_CONSOLE_TEXTA_MAIN_PARAMETER_OPTVAL_C:
            err = on_parameter_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Extends::on_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* option_usage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case TEXTA_APP_CONSOLE_TEXTA_MAIN_PARAMETER_OPTVAL_C:
            optarg = TEXTA_APP_CONSOLE_TEXTA_MAIN_PARAMETER_OPTARG;
            chars = TEXTA_APP_CONSOLE_TEXTA_MAIN_PARAMETER_OPTUSE;
            break;
        default:
            chars = Extends::option_usage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = TEXTA_APP_CONSOLE_TEXTA_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            TEXTA_APP_CONSOLE_TEXTA_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = TEXTA_APP_CONSOLE_TEXTA_MAIN_ARGS;
        static const char_t* _argv[] = {
            TEXTA_APP_CONSOLE_TEXTA_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    ::texta::t::variable_list parameters_;
};

} // namespace texta 
} // namespace console 
} // namespace app 
} // namespace texta 

#endif // _TEXTA_APP_CONSOLE_TEXTA_MAIN_HPP 
        

