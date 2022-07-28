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
///   Date: 8/13/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_APP_CONSOLE_MSG_MAIN_HPP
#define _XOS_NADIR_XOS_APP_CONSOLE_MSG_MAIN_HPP

#include "xos/base/getopt/main.hpp"
#include "xos/ipc/os/message_queue.hpp"
#include "xos/ipc/os/key.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_MSG_MAIN_SEND_OPT "send"
#define XOS_APP_CONSOLE_MSG_MAIN_SEND_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_APP_CONSOLE_MSG_MAIN_SEND_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_MSG_MAIN_SEND_OPTARG "message"
#define XOS_APP_CONSOLE_MSG_MAIN_SEND_OPTUSE "message to send"
#define XOS_APP_CONSOLE_MSG_MAIN_SEND_OPTVAL_S "s:"
#define XOS_APP_CONSOLE_MSG_MAIN_SEND_OPTVAL_C 's'
#define XOS_APP_CONSOLE_MSG_MAIN_SEND_OPTION \
   {XOS_APP_CONSOLE_MSG_MAIN_SEND_OPT, \
    XOS_APP_CONSOLE_MSG_MAIN_SEND_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_MSG_MAIN_SEND_OPTARG_RESULT, \
    XOS_APP_CONSOLE_MSG_MAIN_SEND_OPTVAL_C}, \

#define XOS_APP_CONSOLE_MSG_MAIN_RECEIVE_OPT "receive"
#define XOS_APP_CONSOLE_MSG_MAIN_RECEIVE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_APP_CONSOLE_MSG_MAIN_RECEIVE_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_MSG_MAIN_RECEIVE_OPTARG "message"
#define XOS_APP_CONSOLE_MSG_MAIN_RECEIVE_OPTUSE "message to wait to receive"
#define XOS_APP_CONSOLE_MSG_MAIN_RECEIVE_OPTVAL_S "r:"
#define XOS_APP_CONSOLE_MSG_MAIN_RECEIVE_OPTVAL_C 'r'
#define XOS_APP_CONSOLE_MSG_MAIN_RECEIVE_OPTION \
   {XOS_APP_CONSOLE_MSG_MAIN_RECEIVE_OPT, \
    XOS_APP_CONSOLE_MSG_MAIN_RECEIVE_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_MSG_MAIN_RECEIVE_OPTARG_RESULT, \
    XOS_APP_CONSOLE_MSG_MAIN_RECEIVE_OPTVAL_C}, \


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_MSG_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_MSG_MAIN_SEND_OPTVAL_S \
   XOS_APP_CONSOLE_MSG_MAIN_RECEIVE_OPTVAL_S \
   XOS_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_MSG_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_MSG_MAIN_SEND_OPTION \
   XOS_APP_CONSOLE_MSG_MAIN_RECEIVE_OPTION \
   XOS_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_MSG_MAIN_ARGS "queue"
#define XOS_APP_CONSOLE_MSG_MAIN_ARGV "queue - message queue name",

namespace xos {
namespace app {
namespace console {
namespace msg {

typedef base::getopt::main_implements main_implements;
typedef base::getopt::main main_extends;
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
    maint(): run_(0) {
    }
    virtual ~maint() {
    }

protected:
    typedef int (Derives::*run_t)(int argc, char_t **argv, char_t **env);
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char_t **argv, char_t **env) {
        int err = 1;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            this->usage(argc, argv, env);
        }
        return err;
    }
    virtual int run_receive(int argc, char_t **argv, char_t **env) {
        int err = 1;
        const char* arg = 0;

        if ((optind < argc) && (argv) && (arg = (argv[optind])) && (arg[0])) {
            ipc::os::os::message_queue q;

            if ((q.open(arg, ipc::message_queue::mode_create))) {
                ssize_t count = 0;

                do {
                    XOS_LOG_MESSAGE_DEBUG("q.receive(" << base::pointer_to_string(received_) << ", " << (sizeof(received_)-1) << ")...");
                    if ((count = q.receive(received_, sizeof(received_)-1))) {
                        received_[sizeof(received_)-1] = 0;
                        XOS_LOG_MESSAGE_DEBUG("..." << count << " = q.receive(\"" << received_ << "\", " << (sizeof(received_)-1) << ")");
                        if (!(message_.compare(received_))) {
                            break;
                        }
                        sleep(5);
                    } else {
                        XOS_LOG_MESSAGE_DEBUG("...failed on " << count << " = q.receive(" << base::pointer_to_string(received_) << ", " << (sizeof(received_)-1) << ")");
                    }
                } while (0 < (count));
                q.close();
                err = 0;
            }
        } else {
            this->usage(argc, argv, env);
        }
        return err;
    }
    virtual int run_send(int argc, char_t **argv, char_t **env) {
        int err = 1;
        const char* arg = 0;

        if ((optind < argc) && (argv) && (arg = (argv[optind])) && (arg[0])) {
            ipc::os::os::message_queue q;

            if ((q.open(arg))) {
                ssize_t count = 0;

                XOS_LOG_MESSAGE_DEBUG("q.send(\"" << message_ << "\", " << message_.length() << ")...");
                if ((count = q.send(message_.chars(), message_.length()))) {
                    XOS_LOG_MESSAGE_DEBUG("..." << count << " = q.send(\"" << message_ << "\", " << message_.length() << ")");
                } else {
                    XOS_LOG_MESSAGE_DEBUG("...failed on " << count << " = q.send(\"" << message_ << "\", " << message_.length() << ")");
                }
                q.close();
                err = 0;
            }
        } else {
            this->usage(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* set_send(const char_t* to) {
        if ((to) && (to[0])) {
            XOS_LOG_MESSAGE_DEBUG("set send = \"" << to << "\"...");
            message_.assign(to);
            run_ = &Derives::run_send;
        }
        return to;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* set_receive(const char_t* to) {
        if ((to) && (to[0])) {
            XOS_LOG_MESSAGE_DEBUG("set receive = \"" << to << "\"...");
            message_.assign(to);
            run_ = &Derives::run_receive;
        }
        return to;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_send_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(set_send(optarg))) {
            XOS_LOG_ERROR("...failed on set_send(\"" << optarg << "\")");
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_receive_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(set_receive(optarg))) {
            XOS_LOG_ERROR("...failed on set_receive(\"" << optarg << "\")");
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
        case XOS_APP_CONSOLE_MSG_MAIN_SEND_OPTVAL_C:
            err = on_send_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_MSG_MAIN_RECEIVE_OPTVAL_C:
            err = on_receive_option
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
        case XOS_APP_CONSOLE_MSG_MAIN_SEND_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_MSG_MAIN_SEND_OPTARG;
            chars = XOS_APP_CONSOLE_MSG_MAIN_SEND_OPTUSE;
            break;
        case XOS_APP_CONSOLE_MSG_MAIN_RECEIVE_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_MSG_MAIN_RECEIVE_OPTARG;
            chars = XOS_APP_CONSOLE_MSG_MAIN_RECEIVE_OPTUSE;
            break;
        default:
            chars = Extends::option_usage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = XOS_APP_CONSOLE_MSG_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_MSG_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_MSG_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_MSG_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    run_t run_;
    base::string message_;
    char received_[1024];
};
typedef maint<> main;

} // namespace msg 
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_NADIR_XOS_APP_CONSOLE_MSG_MAIN_HPP 
