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
///   File: main_implement.hpp
///
/// Author: $author$
///   Date: 6/16/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_GETOPT_MAIN_IMPLEMENT_HPP
#define _XOS_NADIR_XOS_BASE_GETOPT_MAIN_IMPLEMENT_HPP

#include "xos/base/getopt/main_opt.hpp"
#include "xos/base/main.hpp"

namespace xos {
namespace base {
namespace getopt {

typedef xos::base::main_implement main_implement_implements;
///////////////////////////////////////////////////////////////////////
///  Class: main_implementt
///////////////////////////////////////////////////////////////////////
template 
<typename TChar = char, typename TEnd = int, TEnd VEnd = 0,
 class TImplements = main_implement_implements>

class _EXPORT_CLASS main_implementt: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef stringt<TChar, TEnd, VEnd> string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int before_main(int argc, char_t** argv, char_t** env) {
        int err = 0;

        if (!(err = before_get_options(argc, argv, env))) {
            int err2 = 0;

            err = get_options(argc, argv, env);

            if ((err2 = after_get_options(argc, argv, env))) {
                if (!(err)) err = err2;
            } else {

                if ((err2 = before_get_arguments(argc, argv, env))) {
                    if (!(err)) err = err2;
                } else {

                    if ((err2 = get_arguments(argc, argv, env))) {
                        if (!(err)) err = err2;
                    }

                    if ((err2 = after_get_arguments(argc, argv, env))) {
                        if (!(err)) err = err2;
                    }
                }
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_options(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_get_options(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_options(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 1;
        return err;
    }
    virtual const char_t* option_usage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = 0;
        static struct option optstruct[]= {
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_arguments(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_get_arguments(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_arguments(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_argument
    (const char_t* arg, int argind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int missing_argument(const char_t* arg) {
        int err = 1;
        return err;
    }
    virtual const char* arguments(const char_t**& args) {
        args = 0;
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int usage(int argc, char_t** argv, char_t** env) {
        int err = 0;
        set_did_usage();
        return err;
    }
    virtual const char_t* usage_name
    (int argc, char_t** argv, char_t** env) const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_did_usage(bool to = true) {
        return false;
    }
    virtual bool did_usage() const {
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace getopt 
} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_GETOPT_MAIN_IMPLEMENT_HPP 
