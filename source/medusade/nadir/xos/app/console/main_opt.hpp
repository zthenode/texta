///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
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
///   Date: 6/14/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_MAIN_OPT_HPP

#include "xos/base/exception.hpp"
#include "xos/base/getopt/main.hpp"

#define XOS_APP_CONSOLE_MAIN_OPTIONS_CHARS_EXTEND \

#define XOS_APP_CONSOLE_MAIN_OPTIONS_OPTIONS_EXTEND \

#define XOS_APP_CONSOLE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_MAIN_OPTIONS_OPTIONS

#define XOS_APP_CONSOLE_MAIN_ARGS 0
#define XOS_APP_CONSOLE_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {

/// class main_optt
template 
<class TExtends = xos::base::getopt::main, 
 class TImplements = typename TExtends::Implements>

class exported main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_t end_char_t;
    enum { end_char = extends::end };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::stream_t stream_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    main_optt(): run_(0), in_reader_(*this), out_writer_(*this), err_writer_(*this) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
        throw exception(exception_unexpected);
    }

protected:
    /// ...run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = default_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->usage(argc, argv, env);
        return err;
    }
    
protected:
    typedef extends io_t;
    typedef extend io_extends_t;

    /// class io_extend_t
    class exported io_extend_t: public io_extends_t {
    public:
        typedef io_extends_t extends;
        typedef io_extend_t derives;
    
        /// constructor / destructor
        io_extend_t(const io_extend_t& copy): extends(copy), io_(copy.io_) {
        }
        io_extend_t(io_t& io): io_(io) {
        }
        virtual ~io_extend_t() {
        }
    protected:
        io_t& io_;
    }; /// class io_extend_t
    
    /// class in_reader_t
    class exported in_reader_t: virtual public reader_t, public io_extend_t {
    public:
        typedef reader_t implements;
        typedef io_extend_t extends;
        typedef in_reader_t derives;
    
        typedef typename implements::what_t what_t;
        typedef typename implements::sized_t sized_t;

        /// constructor / destructor
        in_reader_t(const in_reader_t& copy): extends(copy) {
        }
        in_reader_t(io_t& io): extends(io) {
        }
        virtual ~in_reader_t() {
        }
        virtual ssize_t read(what_t* what, size_t size) {
            ssize_t count = 0;
            count = this->io_.in(what, size);
            return count;
        }    
    }; /// class in_reader_t
    
    /// class out_writer_t
    class exported out_writer_t: virtual public writer_t, public io_extend_t {
    public:
        typedef writer_t implements;
        typedef io_extend_t extends;
        typedef out_writer_t derives;
    
        typedef typename implements::what_t what_t;
        typedef typename implements::sized_t sized_t;

        /// constructor / destructor
        out_writer_t(const out_writer_t& copy): extends(copy) {
        }
        out_writer_t(io_t& io): extends(io) {
        }
        virtual ~out_writer_t() {
        }
        virtual ssize_t write(const what_t* what, size_t size) {
            ssize_t count = 0;
            count = this->io_.out(what, size);
            return count;
        }    
        virtual ssize_t flush() {
            ssize_t count = 0;
            count = this->io_.out_flush();
            return count;
        }    
    }; /// class out_writer_t
    
    /// class err_writer_t
    class exported err_writer_t: virtual public writer_t, public io_extend_t {
    public:
        typedef writer_t implements;
        typedef io_extend_t extends;
        typedef err_writer_t derives;
    
        typedef typename implements::what_t what_t;
        typedef typename implements::sized_t sized_t;

        /// constructor / destructor
        err_writer_t(const err_writer_t& copy): extends(copy) {
        }
        err_writer_t(io_t& io): extends(io) {
        }
        virtual ~err_writer_t() {
        }
        virtual ssize_t write(const what_t* what, size_t size) {
            ssize_t count = 0;
            count = this->io_.err(what, size);
            return count;
        }    
        virtual ssize_t flush() {
            ssize_t count = 0;
            count = this->io_.err_flush();
            return count;
        }    
    }; /// class err_writer_t

    /// ...reader / ...writer
    virtual in_reader_t& in_reader() const {
        return (in_reader_t&)in_reader_;
    }
    virtual out_writer_t& out_writer() const {
        return (out_writer_t&)out_writer_;
    }
    virtual err_writer_t& err_writer() const {
        return (err_writer_t&)err_writer_;
    }

    /// ...option...
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

protected:
    in_reader_t in_reader_;
    out_writer_t out_writer_;
    err_writer_t err_writer_;
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_MAIN_OPT_HPP
