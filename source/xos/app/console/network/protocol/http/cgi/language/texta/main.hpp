///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
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
///   Date: 4/17/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_PROTOCOL_HTTP_CGI_LANGUAGE_TEXTA_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_HTTP_CGI_LANGUAGE_TEXTA_MAIN_HPP

#include "xos/app/console/network/protocol/http/cgi/language/texta/main_opt.hpp"
#include "xos/language/texta/processor/implement.hpp"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace protocol {
namespace http {
namespace cgi {
namespace language {
namespace texta {

/// class maint
template <class TExtends = main_opt, class TImplements = typename TExtends::implements>
class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    maint(): t_(0) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy): t_(0) {
    }
public:

protected:
    typedef derives main_t;
    typedef xos::protocol::http::form::field form_field_t;
    typedef xos::protocol::http::form::fields form_fields_t;
    typedef xos::language::texta::processor::implement t_processor_t;
    typedef xos::language::texta::processor::implement::input_t t_input_t;
    typedef xos::language::texta::processor::implement::output_t t_output_t;
    typedef xos::io::crt::file::readert<t_input_t> t_input_file_t;

    /// class t_input
    class exported t_input: virtual public t_input_t {
    public:
        typedef t_input_t implements;
        typedef typename implements::what_t what_t;
        typedef typename implements::sized_t sized_t;
        t_input(main_t& main): main_(main) {
        }
        virtual ssize_t read(what_t* what, size_t size) {
            sized_t* sized = 0; ssize_t count = 0;
            if ((sized = ((sized_t*)what)) && (size)) {
                count = main_.t_read(sized, size);
            }
            return count;
        }    
    protected:
        main_t& main_;
    }; /// class t_input

    /// class t_output
    class exported t_output: virtual public t_output_t {
    public:
        typedef t_output_t implements;
        typedef typename implements::what_t what_t;
        typedef typename implements::sized_t sized_t;
        t_output(main_t& main): main_(main) {
        }
        virtual ssize_t write(const what_t* what, size_t size) {
            const sized_t* sized = 0; ssize_t count = 0;
            if ((sized = ((const sized_t*)what)) && (size)) {
                count = main_.t_write(sized, size);
            }
            return count;
        }    
    protected:
        main_t& main_;
    }; /// class t_output
    
protected:
    /// ...console_gateway_out_run
    virtual int console_gateway_out_run(int argc, char_t** argv, char_t** env) {
        int err = 0;        

        if ((t_)) {
            const char_t *setting = 0;

            if ((setting = this->environment_setting_PATH_TRANSLATED()) && (setting[0])) {
                const form_field_t *f = 0;
                form_fields_t::const_iterator_t i;

                for (f = this->first_form_field(i); f; f = this->next_form_field(i)) {
                    t_->set_variable(f->name(), f->value());
                }
                for (f = this->first_query_field(i); f; f = this->next_query_field(i)) {
                    t_->set_variable(f->name(), f->value());
                }
                if ((t_input_file_.open(setting))) {
                    derives::t_input input(*this);
                    derives::t_output output(*this);

                    t_->set_input_variable(setting);
                    t_->expand(output, input);
                    t_input_file_.close();
                } else {
                    this->outlln("...failed to open file \"", setting, "\"...", null);
                }
            } else {
                this->outlln("...environment variable PATH_TRANSLATED ", ((setting)?("= \"\""):("missing")), "...", null);
            }
        }
        return err;
    }
    virtual int before_console_gateway_out_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        this->out_std_out();
        if ((t_ = t_processor_t::get_instance())) {
            if (!(t_->init())) {
                t_ = 0;
            }
        } else {
        }
        return err;
    }
    virtual int after_console_gateway_out_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((t_)) {
            if (!(t_->fini())) {
            }
            t_processor_t::free_instance(t_);
            t_ = 0;
        } else {
        }
        return err;
    }
    
    /// t_read / t_write
    virtual ssize_t t_read(char_t* chars, size_t length) {
        ssize_t count = 0;
        count = t_input_file_.read(chars, length);
        return count;
    }
    virtual ssize_t t_write(const char_t* chars, size_t length) {
        ssize_t count = 0;
        count = this->out(chars, length);
        return count;
    }

protected:
    t_processor_t* t_;
    t_input_file_t t_input_file_;
}; /// class maint
typedef maint<> main;

} /// namespace texta
} /// namespace language
} /// namespace cgi
} /// namespace http
} /// namespace protocol
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_PROTOCOL_HTTP_CGI_LANGUAGE_TEXTA_MAIN_HPP 
