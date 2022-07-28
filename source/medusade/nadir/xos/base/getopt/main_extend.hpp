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
///   File: main_extend.hpp
///
/// Author: $author$
///   Date: 6/17/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_GETOPT_MAIN_EXTEND_HPP
#define _XOS_NADIR_XOS_BASE_GETOPT_MAIN_EXTEND_HPP

#include "xos/base/getopt/main_implement.hpp"

namespace xos {
namespace base {
namespace getopt {

///////////////////////////////////////////////////////////////////////
///  Class: main_extendt
///////////////////////////////////////////////////////////////////////
template <class TImplements, class TExtends>
class _EXPORT_CLASS main_extendt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main_extendt() {
    }
    virtual ~main_extendt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_options(int argc, char** argv, char** env) {
        int err = 0;
        int longindex = 0;
        const struct option* longopts = 0;
        char optvaluename[2] = {0,0};
        const char* optname = optvaluename;
        const char* optstring;
        int optvalue;

        if ((optstring = options(longopts)) && (longopts)) {
            while (0 <= (optvalue = getopt_long(argc, argv, optstring, longopts, &longindex))) {
                optvaluename[0] = optvalue;
                optname = (longindex)?(longopts[longindex].name):(optvaluename);

                if ((err = on_option (optvalue, optarg, optname, longindex, argc, argv, env)))
                    break;
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_logging_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = xos::base::getopt::on_logging_option
        (optval, optarg, optname, optind, argc, argv, env);
        return err;
    }
    virtual int on_usage_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = usage(argc, argv, env);
        return err;
    }
    virtual int on_invalid_option_arg
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 1;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        switch(optval) {
        case XOS_MAIN_LOGGING_OPTVAL_C:
            err = on_logging_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_MAIN_HELP_OPTVAL_C:
            err = on_usage_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Implements::on_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char* option_usage
    (const char*& optarg, const struct option* longopt) {
        const char* chars = "";
        switch(longopt->val) {
        case XOS_MAIN_LOGGING_OPTVAL_C:
            optarg = XOS_MAIN_LOGGING_OPTARG;
            break;
        case XOS_MAIN_HELP_OPTVAL_C:
            chars = XOS_MAIN_HELP_OPTUSE;
            break;
        default:
            chars = Implements::option_usage(optarg, longopt);
        }
        return chars;
    }
    virtual const char* options(const struct option*& longopts) {
        static const char* chars = XOS_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_arguments(int argc, char** argv, char** env) {
        int err = 0;
        if (argc > (optind)) {
            for (int argind = optind; argind < argc; ++argind) {
                if ((err = on_argument(argv[argind], argind-optind, argc, argv, env))) {
                    break;
                }
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace getopt 
} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_GETOPT_MAIN_EXTEND_HPP 
