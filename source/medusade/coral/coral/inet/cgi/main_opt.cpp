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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 2/2/2015
///////////////////////////////////////////////////////////////////////
#if !defined(_CORAL_INET_CGI_MAIN_HPP)
#include "coral/inet/cgi/main_opt.hpp"

namespace coral {
namespace inet {
namespace cgi {

typedef console::main main_extends;
typedef console::main_implements main_implements;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;
protected:
#endif // !defined(_CORAL_INET_CGI_MAIN_HPP)

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_argv_file_name_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            CORAL_LOG_DEBUG("optarg = \"" << optarg << "\"...");
            if (!(set_argv_file_name(optarg))) {
                CORAL_LOG_ERROR("...failed on set_argv_file_name(\"" << optarg << "\")");
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_env_file_name_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            CORAL_LOG_DEBUG("optarg = \"" << optarg << "\"...");
            if (!(set_env_file_name(optarg))) {
                CORAL_LOG_ERROR("...failed on set_env_file_name(\"" << optarg << "\")");
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_stdin_file_name_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            CORAL_LOG_DEBUG("optarg = \"" << optarg << "\"...");
            if (!(set_stdin_file_name(optarg))) {
                CORAL_LOG_ERROR("...failed on set_stdin_file_name(\"" << optarg << "\")");
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
        case CORAL_INET_CGI_MAIN_ARGV_FILE_NAME_OPTVAL_C:
            err = on_argv_file_name_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case CORAL_INET_CGI_MAIN_ENV_FILE_NAME_OPTVAL_C:
            err = on_env_file_name_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case CORAL_INET_CGI_MAIN_STDIN_FILE_NAME_OPTVAL_C:
            err = on_stdin_file_name_option
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
        case CORAL_INET_CGI_MAIN_ARGV_FILE_NAME_OPTVAL_C:
            optarg = CORAL_INET_CGI_MAIN_ARGV_FILE_NAME_OPTARG;
            chars = CORAL_INET_CGI_MAIN_ARGV_FILE_NAME_OPTUSE;
            break;
        case CORAL_INET_CGI_MAIN_ENV_FILE_NAME_OPTVAL_C:
            optarg = CORAL_INET_CGI_MAIN_ENV_FILE_NAME_OPTARG;
            chars = CORAL_INET_CGI_MAIN_ENV_FILE_NAME_OPTUSE;
            break;
        case CORAL_INET_CGI_MAIN_STDIN_FILE_NAME_OPTVAL_C:
            optarg = CORAL_INET_CGI_MAIN_STDIN_FILE_NAME_OPTARG;
            chars = CORAL_INET_CGI_MAIN_STDIN_FILE_NAME_OPTUSE;
            break;
        default:
            chars = Extends::option_usage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = CORAL_INET_CGI_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            CORAL_INET_CGI_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

#if !defined(_CORAL_INET_CGI_MAIN_HPP)
};

} // namespace cgi
} // namespace inet
} // namespace coral 
#endif // !defined(_CORAL_INET_CGI_MAIN_HPP)