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
///   Date: 6/4/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_INET_CGI_MAIN_HPP
#define _TEXTA_INET_CGI_MAIN_HPP

#include "texta/base/cgi_main.hpp"

#define BR (((this->is_content_type_html()))?("<br>\n"):("\n"))
#define H1_ (((this->is_content_type_html()))?("<h1>\n"):(""))
#define _H1 (((this->is_content_type_html()))?("</h1>\n"):("\n\n"))
#define B_ (((this->is_content_type_html()))?("<b>"):(""))
#define _B (((this->is_content_type_html()))?("</b>"):(""))
#define UL_ (((this->is_content_type_html()))?("<ul>"):(""))
#define _UL (((this->is_content_type_html()))?("</ul>"):("\n"))
#define LI_ (((this->is_content_type_html()))?("<li>"):(""))
#define _LI (((this->is_content_type_html()))?("</li>"):("\n"))

namespace texta {
namespace inet {
namespace cgi {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template
<class TImplements = main_implements, class TExtends = main_extends>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint() {
    }
    virtual ~maint() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_cgi(int argc, char_t** argv, char_t** env) {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_console(int argc, char_t** argv, char_t** env) {
        return run_cgi(argc, argv, env);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t*
    form_value_has_chars(size_t& length, const char_t** names) const {
        const char_t* value = 0;
        http::form::field* f;
        if ((f = this->form().find(names))) {
            value = (f->value().has_chars(length));
        }
        return value;
    }
    virtual const char_t*
    form_value_chars(size_t& length, const char_t** names) const {
        const char_t* value = 0;
        http::form::field* f;
        if ((f = this->form().find(names))) {
            value = (f->value().chars(length));
        }
        return value;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* env_path_translated_has_chars(size_t& length) const {
        environment::variable::value& value
        = this->environment_[environment::variable::PATH_TRANSLATED];
        const char_t* chars = value.has_chars(length);
        return chars;
    }
    virtual const char_t* env_path_info_has_chars(size_t& length) const {
        environment::variable::value& value
        = this->environment_[environment::variable::PATH_INFO];
        const char_t* chars = value.has_chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool is_content_type_html() const {
        const char_t *chars = 0, *chars2 = 0;
        if ((chars = this->content_type())
            && (chars2 = content_type_html())) {
            if (!(chars_t::compare(chars, chars2))) {
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* content_type_text() const {
        const char_t* chars = http::content::type::name::of(http::content::type::text);
        return chars;
    }
    virtual const char_t* content_type_html() const {
        const char_t* chars = http::content::type::name::of(http::content::type::html);
        return chars;
    }
    virtual const char_t* content_type_xml() const {
        const char_t* chars = http::content::type::name::of(http::content::type::xml);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef maint<> main;

} // namespace cgi 
} // namespace inet 
} // namespace texta 

#endif // _TEXTA_INET_CGI_MAINT_HPP 
