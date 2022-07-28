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
///   Date: 1/9/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_INET_CGI_MAIN_HPP
#define _CORAL_INET_CGI_MAIN_HPP

#include "coral/console/main.hpp"
#include "coral/inet/cgi/main_opt.hpp"
#include "coral/inet/cgi/config/variables/reader.hpp"
#include "coral/inet/cgi/environment/variables/writer.hpp"
#include "coral/inet/cgi/environment/variables/reader.hpp"
#include "coral/inet/cgi/environment/variables/values.hpp"
#include "coral/inet/http/content.hpp"
#include "coral/inet/http/header.hpp"
#include "coral/inet/http/url.hpp"
#include "coral/io/file.hpp"
#include "coral/io/string.hpp"
#include "coral/io/types.hpp"
#include "coral/io/logger.hpp"

#define CORAL_INET_CGI_CONF_FILE_LABEL "config"
#define CORAL_INET_CGI_CONF_FILE_NAME "cgi-conf.txt"

#define CORAL_INET_CGI_CATCH_ARGV_FILE_LABEL "arguments"
#define CORAL_INET_CGI_CATCH_ENV_FILE_LABEL "environment"
#define CORAL_INET_CGI_CATCH_STDIN_FILE_LABEL "stdin"

#define CORAL_INET_CGI_CATCH_ARGV_FILE_NAME "cgicatch-argv.txt"
#define CORAL_INET_CGI_CATCH_ENV_FILE_NAME "cgicatch-env.txt"
#define CORAL_INET_CGI_CATCH_STDIN_FILE_NAME "cgicatch-stdin.txt"

namespace coral {
namespace inet {
namespace cgi {

typedef console::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main_implements
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main_implements
: virtual public console::main_implements,
  virtual public http::content::read::observer,
  virtual public config::variables::reader_events {
};
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main()
    : cr_((char_t)'\r'), lf_((char_t)'\n'),
      conf_file_label_(CORAL_INET_CGI_CONF_FILE_LABEL),
      catch_argv_file_label_(CORAL_INET_CGI_CATCH_ARGV_FILE_LABEL),
      catch_env_file_label_(CORAL_INET_CGI_CATCH_ENV_FILE_LABEL),
      catch_stdin_file_label_(CORAL_INET_CGI_CATCH_STDIN_FILE_LABEL),
      conf_file_name_(CORAL_INET_CGI_CONF_FILE_NAME),
      catch_argv_file_name_(CORAL_INET_CGI_CATCH_ARGV_FILE_NAME),
      catch_env_file_name_(CORAL_INET_CGI_CATCH_ENV_FILE_NAME),
      catch_stdin_file_name_(CORAL_INET_CGI_CATCH_STDIN_FILE_NAME),
      content_type_name_(http::message::header::name::of(http::message::header::content_type)),
      content_type_value_(http::content::type::name::of(http::content::type::text)),
      is_cgi_run_(false), out_headers_(false), 
      out_content_type_(0), content_length_(0) {
    }
    virtual ~main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_cgi(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_run_cgi(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_run_cgi(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_console(int argc, char_t** argv, char_t** env) {
        int err = run_cgi(argc, argv, env);
        return err;
    }
    virtual int before_run_console(int argc, char_t** argv, char_t** env) {
        int err = before_run_cgi(argc, argv, env);
        return err;
    }
    virtual int after_run_console(int argc, char_t** argv, char_t** env) {
        int err = after_run_cgi(argc, argv, env);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_cgi_query_form_data(int argc, char_t** argv, char_t** env) {
        const environment::variable::value& query_string = environment_[environment::variable::QUERY_STRING];
        const char_t* chars = 0;
        size_t length = 0;
        int err = 0;

        /*string_t default_query_string;
        default_query_string.append(content_type_name_);
        default_query_string.append("=");
        default_query_string.append(content_type_value_);
        chars = default_query_string.has_chars(length);*/

        if (!(chars)) {
            chars = query_string.has_chars(length);
        }
        if ((chars) && (length)) {
            io::chars::reader creader(chars, length);
            http::url::encoded::reader qreader(creader);
            http::form::reader form(form_);
            form.read_more(qreader);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_cgi_form_data(int argc, char_t** argv, char_t** env) {
        const environment::variable::value& content_length = environment_[environment::variable::CONTENT_LENGTH];
        const char_t* chars = 0;
        size_t length = 0;
        int err = 0;
        if ((chars = content_length.has_chars(length))) {
            if ((content_length_ = chars_t::to_unsigned(chars, length))) {
                err = get_cgi_form_data(content_length_, argc, argv, env);
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_cgi_form_data
    (size_t content_length, int argc, char_t** argv, char_t** env) {
        const environment::variable::value& content_type = environment_[environment::variable::CONTENT_TYPE];
        const char_t* chars = 0;
        size_t length = 0;
        int err = 0;

        if ((content_length)) {
            if (!(err = before_read_cgi_form_data(content_length, argc, argv, env))) {
                if ((chars = content_type.has_chars(length))) {
                    http::content::type::name name(chars, length);
                    http::content::type::which_t which = name.which();
                    switch(which) {
                    case http::content::type::urlencoded_form_data:
                        err = get_cgi_urlencoded_form_data(content_length, argc, argv, env);
                        break;
                    case http::content::type::multipart_form_data:
                        err = get_cgi_multipart_form_data(content_length, argc, argv, env);
                        break;
                    default:
                        break;
                    }
                }
                if (!(err = after_read_cgi_form_data(content_length, argc, argv, env))) {
                }
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int before_read_cgi_form_data
    (size_t content_length, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_read_cgi_form_data
    (size_t content_length, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual void on_read_content
    (const what_t* what, const sized_t* sized, size_t size) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_cgi_urlencoded_form_data
    (size_t content_length, int argc, char_t** argv, char_t** env) {
        io::main::in::reader in(*this);
        http::content::reader content(*this, in, content_length);
        http::url::encoded::reader encoded(content);
        http::form::reader form(form_);
        int err = 0;
        form.read_more(encoded);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_cgi_multipart_form_data
    (size_t content_length, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_cgi_form(int argc, char_t** argv, char_t** env) {
        int err = 0;
        form_.clear();
        if (!(err = get_cgi_query_form_data(argc, argv, env))) {
            if (!(err = get_cgi_form_data(argc, argv, env))) {
            }
        }
        return err;
    }
    virtual int before_get_cgi_form(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_cgi_form(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_cgi_content(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_get_cgi_content(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_cgi_content(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_cgi_environment(int argc, char_t** argv, char_t** env) {
        int err = 0;
        environment_.get();
        return err;
    }
    virtual int before_get_cgi_environment(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_cgi_environment(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int begin_read_cgi_content(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((open_content_file(content_))) {
        }
        return err;
    }
    virtual int end_read_cgi_content(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((close_file(content_))) {
        }
        return err;
    }
    virtual int before_read_cgi_content(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_read_cgi_content(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int read_cgi_environment(int argc, char_t** argv, char_t** env) {
        int err = 0;
        coral::io::read::file f;

        if ((open_file(f, catch_env_file_label_, catch_env_file_name_, true))) {
            inet::cgi::environment::variables::reader e;
            e.read(environment_, f);
            f.close();
        }
        return err;
    }
    virtual int before_read_cgi_environment(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_read_cgi_environment(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int read_cgi_config(int argc, char_t** argv, char_t** env) {
        int err = 0;
        coral::io::read::file f;

        if ((open_file(f, conf_file_label_, conf_file_name_, true))) {
            inet::cgi::config::variables::reader e(*this);
            e.read(f);
            f.close();
        }
        return err;
    }
    virtual int before_read_cgi_config(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_read_cgi_config(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int cgi_main(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_get_cgi_form(argc, argv, env))) {
            if (!(err = get_cgi_form(argc, argv, env))) {
                if (!(err = before_run_cgi(argc, argv, env))) {
                    if (!(err = run_cgi(argc, argv, env))) {
                    }
                    if ((err2 = after_run_cgi(argc, argv, env)) && (!err)) {
                        err = err2;
                    }
                }
            }
            if ((err2 = after_get_cgi_form(argc, argv, env)) && (!err)) {
                err = err2;
            }
        }
        return err;
    }
    virtual int console_main(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_get_cgi_form(argc, argv, env))) {
            if (!(err = get_cgi_form(argc, argv, env))) {
                if (!(err = before_run_console(argc, argv, env))) {
                    if (!(err = run_console(argc, argv, env))) {
                    }
                    if ((err2 = after_run_console(argc, argv, env)) && (!err)) {
                        err = err2;
                    }
                }
            }
            if ((err2 = after_get_cgi_form(argc, argv, env)) && (!err)) {
                err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int cgi_run(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_read_cgi_config(argc, argv, env))) {
            if (!(err = read_cgi_config(argc, argv, env))) {
                if (!(err = after_read_cgi_config(argc, argv, env))) {
                    if (!(err = before_get_cgi_environment(argc, argv, env))) {
                        if (!(err = get_cgi_environment(argc, argv, env))) {
                            if (!(err = before_get_cgi_content(argc, argv, env))) {
                                if (!(err = get_cgi_content(argc, argv, env))) {
                                    if (!(err = cgi_main(argc, argv, env))) {
                                    }
                                }
                                if ((err2 = after_get_cgi_content(argc, argv, env)) && (!err)) {
                                    err = err2;
                                }
                            }
                        }
                        if ((err2 = after_get_cgi_environment(argc, argv, env)) && (!err)) {
                            err = err2;
                        }
                    }
                }
            }
        }
        return err;
    }
    virtual int before_cgi_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        set_file_mode_is_binary(std_in());
        set_file_mode_is_binary(std_out());
        return err;
    }
    virtual int after_cgi_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int console_run(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_read_cgi_config(argc, argv, env))) {
            if (!(err = read_cgi_config(argc, argv, env))) {
                if (!(err = after_read_cgi_config(argc, argv, env))) {
                    if (!(err = before_read_cgi_environment(argc, argv, env))) {
                        if (!(err = read_cgi_environment(argc, argv, env))) {
                            if (!(err = before_read_cgi_content(argc, argv, env))) {
                                if (!(err = begin_read_cgi_content(argc, argv, env))) {
                                    if (!(err = console_main(argc, argv, env))) {
                                    }
                                    if ((err2 = end_read_cgi_content(argc, argv, env)) && (!err)) {
                                        err = err2;
                                    }
                                }
                                if ((err2 = after_read_cgi_content(argc, argv, env)) && (!err)) {
                                    err = err2;
                                }
                            }
                        }
                        if ((err2 = after_read_cgi_environment(argc, argv, env)) && (!err)) {
                            err = err2;
                        }
                    }
                }
            }
        }
        return err;
    }
    virtual int before_console_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_console_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        inet::cgi::environment::variable::value gateway_interface(inet::cgi::environment::variable::GATEWAY_INTERFACE);
        if ((is_cgi_run_ = (gateway_interface.has_chars()))) {
            if (!(err = before_cgi_run(argc, argv, env))) {
                err = cgi_run(argc, argv, env);
                if ((err2 = after_cgi_run(argc, argv, env))) {
                    if (!(err)) err = err2;
                }
            }
        } else {
            if (!(err = before_console_run(argc, argv, env))) {
                err = console_run(argc, argv, env);
                if ((err2 = after_console_run(argc, argv, env))) {
                    if (!(err)) err = err2;
                }
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_options(int argc, char_t** argv, char_t** env) {
        inet::cgi::environment::variable::value gateway_interface(inet::cgi::environment::variable::GATEWAY_INTERFACE);
        if ((gateway_interface.has_chars())) {
            return 0;
        }
        return Extends::get_options(argc, argv, env);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* set_content_type(const string_t& to) {
        return set_content_type(to.chars());
    }
    virtual const char_t* set_content_type(const char_t* chars) {
        if ((chars) && (chars[0])) {
            content_type_value_.assign(chars);
        }
        chars = content_type_value_.chars();
        return chars;
    }
    virtual const char_t* content_type() const {
        return content_type_value_.chars();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* set_content_type_text() {
        return set_content_type(content_type_text());
    }
    virtual const char_t* set_content_type_html() {
        return set_content_type(content_type_html());
    }
    virtual const char_t* set_content_type_xml() {
        return set_content_type(content_type_xml());
    }
    virtual const char_t* set_content_type_json() {
        return set_content_type(content_type_json());
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* content_type_text() const {
        const char* chars = inet::http::content::type::name::of(inet::http::content::type::text);
        return chars;
    }
    virtual const char_t* content_type_html() const {
        const char* chars = inet::http::content::type::name::of(inet::http::content::type::html);
        return chars;
    }
    virtual const char_t* content_type_xml() const {
        const char* chars = inet::http::content::type::name::of(inet::http::content::type::xml);
        return chars;
    }
    virtual const char_t* content_type_json() const {
        const char* chars = inet::http::content::type::name::of(inet::http::content::type::json);
        return chars;
    }
    virtual const char_t* content_type_javascript() const {
        const char* chars = inet::http::content::type::name::of(inet::http::content::type::javascript);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* set_content_type() {
        const char_t* chars = 0;
        if (!(chars = content_type_.has_chars())) {
            content_type_.assign(content_type_name_.chars());
            content_type_.append(": ");
            content_type_.append(content_type_value_.chars());
            chars = content_type_.has_chars();
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t out_content_type() {
        if (!(out_content_type_)) {
            ssize_t count = 0, amount = 0;
            out_content_type_ = set_content_type();
            out_headers();
            if (0 < (count = this->outln(out_content_type_))) {
                if (0 < (amount = this->outln())) {
                    count += amount;
                }
            }
            return count;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void add_header(const char_t* name, const char_t* value) {
        const string_t n(name), v(value);
        add_header(n, v);
    }
    virtual void add_header(const string_t& name, const string_t& value) {
        const http::message::header::name n(name);
        const http::message::header::value v(value);
        const http::message::header::field f(n, v);
        headers_.push_back(f);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t out_headers() {
        if (!(out_headers_)) {
            http::message::header::fields::const_iterator 
                i = headers_.begin(), end = headers_.end();
            out_headers_ = true;
            if ((i != end)) {
                const char_t* chars = 0;
                size_t length = 0;
                ssize_t count = 0, amount = 0;
                do {
                    const http::message::header::field& f = *i;
                    if ((chars = f.has_chars(length))) {
                        if ((0 < (amount = this->out(chars, length)))) {
                            count += amount;
                        }
                    }
                } while (++i != end);
                return count;
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual FILE* out_std_out() {
        out_content_type();
        return this->std_out();
    }
    virtual FILE* std_in() const {
        FILE* file = 0;
        if ((file = content_.attached_to())) {
            return file;
        }
        return stdin;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool open_content_file(io::read::file& file) {
        return open_file(file, catch_stdin_file_label_, catch_stdin_file_name_, true);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool open_file
    (io::read::file& file, const string_t& line,
     const string_t& name, bool mode_is_binary = false) {
        size_t length;

        if ((line.has_chars(length))) {
#if defined(__GNUC__)
            char_t chars[length + 3];
#else // defined(__GNUC__)
            xos::base::arrayt<char_t> a(length + 3);
            char_t* chars = a.elements();
#endif // defined(__GNUC__)

            if ((file.open(name.chars(), (mode_is_binary)
                ?(file.mode_read_binary()):(file.mode_read())))) {
                if (!((length + 1) != (file.read(chars, length + 1)))) {
                    if (!(line.compare(chars, length))) {
                        if (!(lf_ != chars[length])) {
                            return true;
                        } else {
                            if (!(cr_ != chars[length])) {
                                if (!(1 != file.read(chars + length + 1, 1))) {
                                    if (!(lf_ != chars[length+1])) {
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
                file.close();
            }
        }
        return false;
    }
    virtual bool close_file(io::read::file& file) {
        return file.close();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual io::write::file* safe_open_file
    (io::write::file& file, const char_t* line,
     const char_t* name, bool mode_is_binary = false) {
        if ((line) && (line[0]) && (name) && (name[0])) {
            ssize_t length = chars_t::count(line);
            ssize_t amount = 0;
            io::read::file f;

            if ((f.open(name, (mode_is_binary)
                ?(f.mode_read_binary()):(f.mode_read())))) {
#if defined(__GNUC__)
                char_t chars[length+3];
#else // defined(__GNUC__)
                xos::base::arrayt<char_t> a(length + 3);
                char_t* chars = a.elements();
#endif // defined(__GNUC__)

                if (!((length + 2) != (amount = f.read(chars, length + 2)))) {
                    if ((chars_t::compare(line, chars, length))
                        || (chars[length] != cr_) || (chars[length+1] != lf_)) {
                        outl("file \"", name, "\" already exists", 0);
                        outln();
                        f.close();
                        return 0;
                    }
                }
                f.close();
            }
            if ((file.open(name, (mode_is_binary)
                ?(file.mode_write_binary()):(file.mode_write())))) {
                if (!(length != (amount = file.write(line, length)))) {
                    if (!(1 != (amount = file.write(&cr_, 1)))) {
                        if (!(1 != (amount = file.write(&lf_, 1)))) {
                            return &file;
                        }
                    }
                }
                file.close();
            }
        }
        return 0;
    }
    virtual bool close_file(io::write::file& file) {
        return file.close();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_file_mode_is_binary
    (io::read::file& file, bool mode_is_binary = true) {
        FILE* detached = 0;
        if ((detached = file.attached_to())) {
            return set_file_mode_is_binary(detached, mode_is_binary);
        }
        return false;
    }
    virtual bool set_file_mode_is_binary
    (FILE* file, bool mode_is_binary = true) {
        if ((file)) {
            io::file::stream fs(file);
            if ((fs.set_mode_is_binary(mode_is_binary))) {
                return true;
            }
        }
        return false;
    }

public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual http::form::fields& form() const {
        return ((http::form::fields&)form_);
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_config_variable
    (const config::variables::string_t& name, const config::variables::string_t& value) {
        return true;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* set_conf_file_name(const char_t* to) {
        if ((to) && (to[0])) {
            conf_file_name_.assign(to);
        }
        return to;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* set_argv_file_name(const char_t* to) {
        if ((to) && (to[0])) {
            catch_argv_file_name_.assign(to);
        }
        return to;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* set_env_file_name(const char_t* to) {
        if ((to) && (to[0])) {
            catch_env_file_name_.assign(to);
        }
        return to;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* set_stdin_file_name(const char_t* to) {
        if ((to) && (to[0])) {
            catch_stdin_file_name_.assign(to);
        }
        return to;
    }
#include "coral/inet/cgi/main_opt.cpp"

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t cr_, lf_;
    string_t conf_file_label_,
             catch_argv_file_label_,
             catch_env_file_label_,
             catch_stdin_file_label_,
             conf_file_name_,
             catch_argv_file_name_,
             catch_env_file_name_,
             catch_stdin_file_name_,
             content_type_name_,
             content_type_value_,
             content_type_;
    bool is_cgi_run_;
    bool out_headers_;
    const char_t* out_content_type_;
    size_t content_length_;
    environment::variables::values environment_;
    http::message::header::fields headers_;
    http::form::fields form_;
    io::read::file content_;
};

} // namespace cgi 
} // namespace inet 
} // namespace coral 

#endif // _CORAL_INET_CGI_MAIN_HPP 
