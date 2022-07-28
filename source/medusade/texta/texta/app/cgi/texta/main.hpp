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
///   Date: 6/5/2016, 7/30/2021
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_APP_CGI_TEXTA_MAIN_HPP
#define _TEXTA_APP_CGI_TEXTA_MAIN_HPP

#include "texta/inet/cgi/main.hpp"
#include "texta/t/processor.hpp"

#define TEXTA_INET_CGI_NAME "textacgi"
#define TEXTA_INET_CGI_INPUT_NAME "input"

#define TEXTA_INET_CGI_PARAM_TEMPLATE_FILE_NAMES \
    "t_file", \
    "t_filename", \
    "template_file", \
    "template_filename", \
    "input_file", \
    "input_filename", \

#define TEXTA_INET_CGI_PARAM_CONTENT_TYPE_NAMES \
    "content_type", \
    CORAL_INET_HTTP_MESSAGE_HEADER_NAME_CONTENT_TYPE, \

namespace texta {
namespace app {
namespace cgi {
namespace texta {

typedef inet::cgi::main_implements main_implements;
typedef inet::cgi::main main_extends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <class TImplements = main_implements, class TExtends = main_extends>
class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint()
    : cgi_name_(TEXTA_INET_CGI_NAME),
      input_name_(TEXTA_INET_CGI_INPUT_NAME) {
    }
    virtual ~maint() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS output: public ::texta::t::output {
    public:
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        output(main_extends& main): main_(main) {
        }
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
    virtual int run_cgi(int argc, char_t** argv, char_t** env) {
        const char_t** names = 0;
        const char_t* chars = 0;
        size_t length = 0;
        output out(*this);
        ::texta::t::input_file in;
        ::texta::t::processor p;

        if ((chars = this->content_type_html())) {
            this->set_content_type(chars);
        }

        if ((chars = param_template_file(length))) {
            template_file_.assign(chars, length);
        } else {
            this->outl
            (H1_, cgi_name_.chars(), _H1,
             B_, "missing template source (", NULL_POINTER);
            if ((names = param_template_file_names()) && (chars = *names)) {
                do {
                    this->outl("\"", _B, chars, B_, "\"", NULL_POINTER);
                    if ((chars = *(++names))) {
                        this->out(" or ");
                    }
                } while (chars);
            }
            this->outl(")", _B, BR, NULL_POINTER);
        }

        if ((chars = template_file_.has_chars())) {
            if ((in.open(chars))) {
                if ((p.init())) {
                    p.set_variable(input_name_, template_file_);
                    set_variables_from_form(p);
                    set_parameters_from_form(p);
                    if ((chars = param_content_type(length))) {
                        this->set_content_type(chars);
                    } else {
                        if ((chars = this->content_type_text())) {
                            this->set_content_type(chars);
                        }
                    }
                    this->out_content_type();
                    p.expand(out, in);
                    p.fini();
                }
                in.close();
            } else {
                this->outl
                (H1_, cgi_name_.chars(), _H1,
                 B_, "failed to open template file \"", _B,
                 chars, B_, "\"", _B, BR, NULL_POINTER);
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_variables_from_form(::texta::t::processor &p) {
        ssize_t count = 0;
        inet::http::form::fields::iterator
        b = this->form().begin(), e = this->form().end(), i;

        for (i = b; i != e; ++i) {
            inet::http::form::field& f = *i;
            const char_t *name = f.name().has_chars(), *value = f.value().has_chars();

            TEXTA_LOG_MESSAGE_DEBUG("form name = " << chars_to_string(name) << " value = " << chars_to_string(value));
            if ((name) && (value)) {
                if ((p.set_variable(f.name(), f.value()))) {
                    ++count;
                }
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_parameters_from_form(::texta::t::processor &p) {
        ssize_t count = 0;
        inet::http::form::fields::iterator
        b = this->form().begin(), e = this->form().end(), i;

        for (i = b; i != e; ++i) {
            inet::http::form::field& f = *i;
            const char_t *name = f.name().has_chars(), *value = f.value().chars();

            TEXTA_LOG_MESSAGE_DEBUG("form name = " << chars_to_string(name) << " value = " << chars_to_string(value));
            if ((name) && (value)) {
                if ((p.set_parameter(f.name(), f.value()))) {
                    ++count;
                }
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* param_template_file
    (size_t& length, bool only_from_emplate_file_names = false) const {
        const char_t* chars = 0;
        if (!(chars = this->form_value_has_chars(length, param_template_file_names()))) {
            if (!(only_from_emplate_file_names)) {
                chars = this->env_path_translated_has_chars(length);
            }
        }
        return chars;
    }
    virtual const char_t* param_content_type(size_t& length) const {
        const char_t* chars = 0;
        chars = this->form_value_has_chars(length, param_content_type_names());
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t** param_template_file_names() const {
        static const char_t* names[] = {
            TEXTA_INET_CGI_PARAM_TEMPLATE_FILE_NAMES
            0
        };
        return names;
    }
    virtual const char_t** param_content_type_names() const {
        static const char_t* names[] = {
            TEXTA_INET_CGI_PARAM_CONTENT_TYPE_NAMES
            0
        };
        return names;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string cgi_name_, input_name_, template_file_;
};
typedef maint<> main;

} // namespace texta
} // namespace cgi 
} // namespace app 
} // namespace texta 

#endif // _TEXTA_APP_CGI_TEXTA_MAIN_HPP 
