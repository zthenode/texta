///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   File: cgi.hpp
///
/// Author: $author$
///   Date: 10/15/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_APP_CGI_HELLO_CGI_HPP
#define _CORAL_APP_CGI_HELLO_CGI_HPP

#include "coral/inet/cgi/main.hpp"

namespace coral {
namespace app {
namespace cgi {
namespace hello {

typedef ::coral::inet::cgi::main::Implements cgi_implements;
typedef ::coral::inet::cgi::main cgi_extends;
///////////////////////////////////////////////////////////////////////
///  Class: cgi
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS cgi: virtual public cgi_implements, public cgi_extends {
public:
    typedef cgi_implements Implements;
    typedef cgi_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    cgi(): _content_type(this->content_type_text()), _message("Hello") {}
    virtual ~cgi() {}
private:
    cgi(const cgi& copy) {}

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_cgi(int argc, char_t** argv, char_t** env) {
        const char_t* name = 0;
        int err = 0;

        this->set_content_type(_content_type = this->content_type_text());

        if ((name = ::coral::inet::http::message::header::name::of
             (::coral::inet::http::message::header::content_type))) {
            ::coral::inet::http::form::field* ff = 0;
            
            if ((ff = this->form().find(name)) && (ff->value().has_chars())) {
                const string_t& value = ff->value();
                
                if (!(value.compare(this->content_type_html()))) {
                    this->set_content_type(_content_type = this->content_type_html());
                } else {
                    if (!(value.compare(this->content_type_text()))) {
                        this->set_content_type(_content_type = this->content_type_text());
                    } else {
                        if (!(value.compare(this->content_type_xml()))) {
                            this->set_content_type(_content_type = this->content_type_xml());
                        } else {
                            if (!(value.compare(this->content_type_json()))) {
                                this->set_content_type(_content_type = this->content_type_json());
                            } else {
                                if (!(value.compare(this->content_type_javascript()))) {
                                    this->set_content_type(_content_type = this->content_type_javascript());
                                } else {
                                    _content_type = this->set_content_type(value);
                                }
                            }
                        }
                    }
                }
                _message_string.assignl(_message, " ", name, " = \\\"", _content_type, "\\\"", NULL);
                _message = _message_string.chars();
            }
        }

        if ((_content_type != this->content_type_xml())) {
            if ((_content_type != this->content_type_html())) {
                if ((_content_type != this->content_type_json())) {
                    this->outln(_message);
                } else {
                    this->outlln
                    ("{\n", 
                     "\"message\":\"", _message, "\"\n", 
                     "}\n", NULL);
                }
            } else {
                this->outlln
                ("<html><body>\n", 
                 "<b>", _message, "</b><br/>\n", 
                 "</body></html>", NULL);
            }
        } else {
            this->outlln
            ("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n", 
             "<message>", _message, "</message>", NULL);
        }
        return err;
    }
    virtual int run_console(int argc, char_t** argv, char_t** env) {
        return run_cgi(argc, argv, env);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t *_content_type, *_message;
    string_t _message_string;
};

} /// namespace hello
} /// namespace cgi
} /// namespace app
} /// namespace coral

#endif ///ndef _CORAL_APP_CGI_HELLO_CGI_HPP
