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
///   Date: 2/7/2015
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_DAEMON_MAIN_HPP
#define _MEDUSA_DAEMON_MAIN_HPP

#include "medusa/console/main.hpp"
#include "medusa/daemon/main_opt.hpp"

namespace medusa {
namespace daemon {

typedef console::main_implements main_implements;
typedef console::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template
<class TImplements = main_implements, class TExtends = main_extends>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef maint Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint()
    : run_(0) {
    }
    virtual ~maint() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char_t**argv, char_t**env) {
        int err = (run_)
        ?((this->*run_)(argc, argv, env))
        :(this->usage(argc, argv, env));
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int restart_run(int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = before_run_restart(argc, argv, env))) {
            int err2 = 0;
            err = run_restart(argc, argv, env);
            if ((err2 = after_run_restart(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int run_restart(int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int before_run_restart(int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int after_run_restart(int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int start_run(int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = before_run_start(argc, argv, env))) {
            int err2 = 0;
            err = run_start(argc, argv, env);
            if ((err2 = after_run_start(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int run_start(int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int before_run_start(int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int after_run_start(int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int stop_run(int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = before_run_stop(argc, argv, env))) {
            int err2 = 0;
            err = run_stop(argc, argv, env);
            if ((err2 = after_run_stop(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int run_stop(int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int before_run_stop(int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int after_run_stop(int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_restart_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &Derives::restart_run;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_start_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &Derives::start_run;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_stop_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &Derives::stop_run;
        return err;
    }

#include "medusa/daemon/main_opt.cpp"

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool run_is_start() const {
        if ((run_ != &Derives::start_run))
            return false;
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef int (Derives::*run_t)(int argc, char_t**argv, char_t**env);

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    run_t run_;
};
typedef maint<> main;

} // namespace daemon 
} // namespace medusa 

#endif // _MEDUSA_DAEMON_MAIN_HPP 
