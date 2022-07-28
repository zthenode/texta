///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
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
///   Date: 2/27/2017
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_APP_CGI_ODBC_MAIN_HPP
#define _CORAL_APP_CGI_ODBC_MAIN_HPP

#include "etiris/db/odbc/cgi/Main.hpp"
#include "coral/app/cgi/main.hpp"

namespace coral {
namespace app {
namespace cgi {
namespace odbc {

typedef inet::cgi::main_implements main_implements;
typedef etiris::db::odbc::cgi::MainT
<main_implements, inet::cgi::main> main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main() {
    }
    virtual ~main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_cgi(int argc, char_t** argv, char_t** env) {
        RunQuery();
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* get_param_source(size_t& length) const {
        const char_t* chars = get_form_parameter_value_has_chars
        (length, param_source_names());
        return chars;
    }
    virtual const char_t* get_param_table(size_t& length) const {
        const char_t* chars = get_form_parameter_value_has_chars
        (length, param_table_names());
        return chars;
    }
    virtual const char_t* get_param_select(size_t& length) const {
        const char_t* chars = get_form_parameter_value_has_chars
        (length, param_select_names());
        return chars;
    }
    virtual const char_t* get_param_where(size_t& length) const {
        const char_t* chars = get_form_parameter_value_has_chars
        (length, param_where_names());
        return chars;
    }
    virtual const char_t* get_param_query(size_t& length) const {
        const char_t* chars = get_form_parameter_value_has_chars
        (length, param_query_names());
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* get_form_parameter_value_has_chars
    (size_t& length, const char_t** names, bool is_from_query_string = false) const {
        const char_t* value = 0;
        inet::http::form::field* f;
        if ((f = form().find(names))) {
            value = (f->value().has_chars());
            length = (f->value().length());
        }
        return value;
    }
    virtual const char_t* get_form_parameter_value_chars
    (size_t& length, const char_t** names, bool is_from_query_string = false) const {
        const char_t* value = 0;
        inet::http::form::field* f;
        if ((f = form().find(names))) {
            value = (f->value().chars());
            length = (f->value().length());
        }
        return value;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace odbc 
} // namespace cgi 
} // namespace app 
} // namespace coral 

#endif // _CORAL_APP_CGI_ODBC_MAIN_HPP 
