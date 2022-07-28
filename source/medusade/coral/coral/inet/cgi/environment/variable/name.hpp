///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2014 $organization$
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
///   Date: 12/23/2014
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_INET_CGI_ENVIRONMENT_VARIABLE_NAME_HPP
#define _CORAL_INET_CGI_ENVIRONMENT_VARIABLE_NAME_HPP

#include "coral/inet/cgi/environment/variable/which.hpp"
#include "coral/base/types.hpp"
#include "coral/base/wrapped.hpp"

namespace coral {
namespace inet {
namespace cgi {
namespace environment {
namespace variable {

typedef implement_base name_implements;
///////////////////////////////////////////////////////////////////////
///  Class: namet
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char_t,
 typename TWhich = which_t,
 typename TChars = xos::base::typest<TChar>,
 class TExtends = xos::base::wrappedt<const TChar*>,
 class TImplements = name_implements>

class _EXPORT_CLASS namet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TWhich which_t;
    typedef TChar char_t;
    typedef TChars chars_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    namet(which_t which): which_(which) {
        this->wrapped_ = of(which_);
    }
    namet(const namet& copy): Extends(copy), which_(copy.which_t) {
    }
    namet(): which_(none) {
    }
    virtual ~namet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual namet& operator = (which_t which) {
        this->wrapped_ = of(which_ = which);
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static const char_t** of() {
        static const char_t* name[count + 1] = {
            CORAL_INET_CGI_ENVIRONMENT_VARIABLE_NAMES
            0
        };
        return name;
    }
    static const char_t* of(which_t which) {
        const char_t** name = of();
        if ((name) && (which >= first) && (which <= last)) {
            return name[which - first];
        }
        return 0;
    }
    static which_t which(const char_t* of) {
        if ((of)) {
            const char_t* to;
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
    virtual ssize_t length() const {
        ssize_t length = 0;
        const char_t* chars = 0;
        if ((chars = this->wrapped())) {
            length = chars_t::count(chars);
        }
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    which_t which_;
};
typedef namet<> name;

} // namespace variable 
} // namespace environment 
} // namespace cgi 
} // namespace inet 
} // namespace coral 

#endif // _CORAL_INET_CGI_ENVIRONMENT_VARIABLE_NAME_HPP 
