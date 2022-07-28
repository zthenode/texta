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
///   File: name.hpp
///
/// Author: $author$
///   Date: 1/7/2015
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_HPP
#define _MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_HPP

#include "medusa/inet/http/content/type/which.hpp"
#include "medusa/base/string.hpp"

#define MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_TEXT "text/plain"
#define MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_HTML "text/html"
#define MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_XML "text/xml"
#define MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_OCTET_STREAM "application/octet-stream"
#define MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_URLENCODED_FORM_DATA "application/x-www-form-urlencoded"
#define MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_MULTIPART_FORM_DATA "multipart/form-data"
#define MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_JSON "application/json"
#define MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_JAVASCRIPT "application/javascript"
#define MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_UNKNOWN "unknown"

#define MEDUSA_INET_HTTP_CONTENT_TYPE_NAMES \
    MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_TEXT, \
    MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_HTML, \
    MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_XML, \
    MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_OCTET_STREAM, \
    MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_URLENCODED_FORM_DATA, \
    MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_MULTIPART_FORM_DATA, \
    MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_JSON, \
    MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_JAVASCRIPT \

namespace medusa {
namespace inet {
namespace http {
namespace content {
namespace type {

typedef string_implements name_implements;
///////////////////////////////////////////////////////////////////////
///  Class: namet
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char_t,
 typename TWhich = which_t,
 class TExtends = xos::base::stringt<TChar>,
 class TImplements = name_implements>

class _EXPORT_CLASS namet: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TWhich which_t;
    typedef TChar char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    namet(const char_t* name, size_t length)
    : Extends(MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_UNKNOWN),
      which_(none) {
        set_which(name, length);
    }
    namet(const char_t* name)
    : Extends(MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_UNKNOWN),
      which_(none) {
        set_which(name);
    }
    namet(which_t which)
    : Extends(MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_UNKNOWN),
      which_(none) {
        const char* chars = 0;
        if ((chars = of(which))) {
            this->assign(chars);
            which_ = which;
        }
    }
    namet(const namet& copy)
    : Extends(copy),
      which_(copy.which_) {
    }
    namet()
    : Extends(MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_UNKNOWN),
      which_(none) {
    }
    virtual ~namet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual which_t set_which(const char_t* name, size_t length) {
        medusa::string_t string(name);
        const char* chars = 0;
        if ((chars = string.has_chars())) {
            which_t which = none;
            if (none != (which = namet::which(chars))) {
                this->assign(name, length);
                which_ = which;
            }
        }
        return which_;
    }
    virtual which_t set_which(const char_t* name) {
        medusa::string_t string(name);
        const char* chars = 0;
        if ((chars = string.has_chars())) {
            which_t which = none;
            if (none != (which = namet::which(chars))) {
                this->assign(name);
                which_ = which;
            }
        }
        return which_;
    }
    virtual which_t which() const {
        return which_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual namet& operator = (which_t which) {
        const char* chars = 0;
        this->assign(MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_UNKNOWN);
        which_ = none;
        if ((chars = of(which))) {
            this->assign(chars);
            which_ = which;
        }
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static const char* of(which_t which) {
		static const char* name[type::count] = {
            MEDUSA_INET_HTTP_CONTENT_TYPE_NAMES
        };
        if ((which >= first) && (which <= last))
            return name[which - first];
        return 0;
    }
    static which_t which(const char* of) {
        if ((of)) {
            const char* to;
            for (which_t which = first; which <= last; ++which) {
                if ((to = namet::of(which))) {
                    if (!(chars_t::compare(of, to)))
                        return which;
                }
            }
        }
        return none;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    which_t which_;
};
typedef namet<> name;

} // namespace type 
} // namespace content 
} // namespace http 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_HTTP_CONTENT_TYPE_NAME_HPP 
