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
///   Date: 11/1/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_APP_CGI_INTUIT_OAUTH2_CGI_HPP
#define _CORAL_APP_CGI_INTUIT_OAUTH2_CGI_HPP

#include "coral/inet/cgi/main.hpp"

#define CORAL_APP_CGI_INTUIT_OAUTH2_CGI_CONF_FILE_NAME \
    "intuit-oauth2-cgi-conf.txt"

namespace coral {
namespace app {
namespace cgi {
namespace intuit {
namespace oauth2 {

typedef ::coral::inet::cgi::main::Implements cgi_implements;
typedef ::coral::inet::cgi::main cgi_extends;
///////////////////////////////////////////////////////////////////////
///  Class: cgi
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS cgi: virtual public cgi_implements, public cgi_extends {
public:
    typedef cgi_implements Implements;
    typedef cgi_extends Extends;
    typedef cgi Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    cgi()
    : run_cgi_(0),

      intuit_openid_connect_uri_scheme_("https"),
      intuit_openid_connect_uri_authority_("appcenter.intuit.com"),
      intuit_openid_connect_uri_path_("connect/oauth2"),

      intuit_openid_authorization_uri_scheme_("https"),
      intuit_openid_authorization_uri_authority_("oauth.platform.intuit.com"),
      intuit_openid_authorization_uri_path_("oauth2/v1/tokens/bearer"),

      application_grant_type_name_("grant_type"), 
      application_grant_type_authorization_code_("authorization_code"),
      application_response_type_name_("response_type"), 
      application_response_type_code_("code"),
      application_client_id_name_("client_id"), 
      application_client_secret_name_("client_secret"), 
      application_scope_name_("scope"), 
      application_redirect_uri_name_("redirect_uri"), 
      application_redirect_uri_this_local_("http://localhost/coral-cgi/intuit-oauth2-cgi"),
      application_redirect_uri_this_("https://www.medusade.com/coral-cgi/intuit-oauth2-cgi"),
      application_state_name_("state"),
      application_state_authorization_request_("authorization-request"),
      application_state_authorization_response_("authorization-response"),

      application_authorization_response_uri_scheme_("http"),
      application_authorization_response_uri_authority_("localhost"),
      application_authorization_response_uri_path_("source/medusade/coral/webapp/coral/t/html/intuit-quickbooks-oauth2-response-html.t"),
      application_authorization_response_content_type_name_("content_type"),
      application_authorization_response_content_type_("text/html"),
      application_authorization_response_action_name_("action"),

      application_authorization_response_code_(""),
      application_authorization_response_(""),
      application_response_type_(""),
      application_client_id_(""),
      application_client_secret_(""),
      application_scope_(""),
      application_redirect_uri_(""),
      application_state_("") {
        this->set_conf_file_name(CORAL_APP_CGI_INTUIT_OAUTH2_CGI_CONF_FILE_NAME);
    }
    virtual ~cgi() {
    }

protected:
    int (Derives::*run_cgi_)(int argc, char_t** argv, char_t** env);
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_cgi_authorization_request(int argc, char_t** argv, char_t** env) {
        int err = 0;
        inet::http::url::encoded::form::fields form;
        inet::http::url::query query;
        inet::http::url::location url;

        get_client_info(argc, argv, env);
        form.add(application_client_id_name_, application_client_id_);
        form.add(application_scope_name_, application_scope_);
        form.add(application_redirect_uri_name_, application_redirect_uri_);
        form.add(application_response_type_name_, application_response_type_);
        form.add(application_state_name_, application_state_);
        form.write(query.writer());

        url.set_scheme(intuit_openid_connect_uri_scheme_);
        url.set_authority(intuit_openid_connect_uri_authority_);
        url.set_path(intuit_openid_connect_uri_path_);
        url.set_query(query);
        
        this->add_header("Location", url.chars());
        this->out_content_type();
        return err;
    }
    virtual int run_cgi_authorization_response(int argc, char_t** argv, char_t** env) {
        int err = 0;
        inet::http::url::encoded::form::fields form;
        inet::http::url::query query;
        inet::http::url::location url;

        get_client_info(argc, argv, env);
        
        url.set_scheme(intuit_openid_authorization_uri_scheme_);
        url.set_authority(intuit_openid_authorization_uri_authority_);
        url.set_path(intuit_openid_authorization_uri_path_);

        form.add(application_authorization_response_content_type_name_, application_authorization_response_content_type_);
        form.add(application_authorization_response_action_name_, url);
        form.add(application_grant_type_name_, application_grant_type_authorization_code_);
        form.add(application_response_type_code_, application_authorization_response_code_);
        form.add(application_redirect_uri_name_, application_redirect_uri_);
        form.add(application_client_id_name_, application_client_id_);
        form.add(application_client_secret_name_, application_client_secret_);
        form.write(query.writer());

        url.set_scheme(application_authorization_response_uri_scheme_);
        url.set_authority(application_authorization_response_uri_authority_);
        url.set_path(application_authorization_response_uri_path_);
        url.set_query(query);

        this->set_content_type_html();
        this->add_header("Location", url.chars());
        this->out_content_type();
        return err;
    }
    virtual int run_cgi_default(int argc, char_t** argv, char_t** env) {
        int err = 0;
        io::main::out::writer out(*this);
        inet::http::form::fields::const_iterator b = form_.begin();
        inet::http::form::fields::const_iterator e = form_.end();
        inet::cgi::environment::variables::writer environment;
        io::main::argv::writer arguments;

        this->outln("form:");
        for (inet::http::form::fields::const_iterator i = b; i != e; ++i) {
            inet::http::form::field f = *i;
            outl(f.name().chars(), " = \"", f.value().chars(), "\"", 0);
            outln();
        }
        outln();

        this->outln("environment:");
        environment.write(out, environment_);

        this->outln("arguments:");
        arguments.write(out, argc, argv);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_capplication_state(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0;
        inet::http::form::field* f = 0;

        if ((f = this->form().find(application_state_name_.chars()))) {
            if ((chars = f->value().has_chars())) {
                if (!(application_state_authorization_request_.compare(chars))) {
                    run_cgi_ = &Derives::run_cgi_authorization_request;
                } else {
                    if (!(application_state_authorization_response_.compare(chars))) {
                        run_cgi_ = &Derives::run_cgi_authorization_response;
                    } else {
                    }
                }
            }
        }
        return err;
    }
    virtual int get_client_info(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0;
        inet::http::form::field* f = 0;

        set_default_value(application_client_id_, application_client_id_name_);
        set_default_value(application_client_secret_, application_client_secret_name_);
        set_default_value(application_scope_, application_scope_name_);
        set_default_value(application_response_type_, application_response_type_code_);
        set_default_value(application_redirect_uri_, application_redirect_uri_this_local_);
        set_default_value(application_state_,  application_state_authorization_request_);

        if ((chars = application_state_.has_chars())) {
            if (!(application_state_authorization_request_.compare(chars))) {
                application_state_.assign(application_state_authorization_response_);
            } else {
                if (!(application_state_authorization_response_.compare(chars))) {
                } else {
                }
            }
        }
        if ((f = this->form().find(application_response_type_code_.chars()))) {
            application_authorization_response_code_.assign(f->value().chars());
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_cgi(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_capplication_state(argc, argv, env);
        if ((run_cgi_)) {
            err = (this->*run_cgi_)(argc, argv, env);
        } else {
            err = run_cgi_default(argc, argv, env);
        }
        return err;
    }
    virtual int run_console(int argc, char_t** argv, char_t** env) {
        return run_cgi(argc, argv, env);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_config_variable
    (const inet::cgi::config::variables::string_t& name, 
     const inet::cgi::config::variables::string_t& value) {
        if (!(name.compare(application_client_id_name_))) {
            application_client_id_.assign(value);
        } else {
            if (!(name.compare(application_client_secret_name_))) {
                application_client_secret_.assign(value);
            } else {
                if (!(name.compare(application_redirect_uri_name_))) {
                    application_redirect_uri_.assign(value);
                } else {
                    if (!(name.compare(application_response_type_name_))) {
                        application_response_type_.assign(value);
                    } else {
                        if (!(name.compare(application_scope_name_))) {
                            application_scope_.assign(value);
                        } else {
                        }
                    }
                }
            }
        }
        return true;
    }
    virtual string_t& set_default_value(string_t& of, const string_t& to) {
        if (!(of.has_chars())) {
            of.assign(to);
        }
        return of;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string_t intuit_openid_connect_uri_scheme_,
             intuit_openid_connect_uri_authority_,
             intuit_openid_connect_uri_path_,
    
             intuit_openid_authorization_uri_scheme_,
             intuit_openid_authorization_uri_authority_,
             intuit_openid_authorization_uri_path_,
    
             application_grant_type_name_, 
             application_grant_type_authorization_code_, 
             application_response_type_name_, 
             application_response_type_code_, 
             application_client_id_name_, 
             application_client_secret_name_, 
             application_scope_name_, 
             application_redirect_uri_name_, 
             application_redirect_uri_this_local_,
             application_redirect_uri_this_,
             application_state_name_,
             application_state_authorization_request_,
             application_state_authorization_response_,
    
             application_authorization_response_uri_scheme_,
             application_authorization_response_uri_authority_,
             application_authorization_response_uri_path_,
             application_authorization_response_content_type_name_,
             application_authorization_response_content_type_,
             application_authorization_response_action_name_,

             application_authorization_response_code_,
             application_authorization_response_,
             application_response_type_,
             application_client_id_,
             application_client_secret_,
             application_scope_,
             application_redirect_uri_,
             application_state_;
};

} /// namespace oauth2
} /// namespace intuit
} /// namespace cgi
} /// namespace app
} /// namespace coral

#endif ///ndef _CORAL_APP_CGI_INTUIT_OAUTH2_CGI_HPP
