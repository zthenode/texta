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
///   File: array.hpp
///
/// Author: $author$
///   Date: 1/31/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_INET_CGI_ENVIRONMENT_VARIABLES_ARRAY_HPP
#define _CORAL_INET_CGI_ENVIRONMENT_VARIABLES_ARRAY_HPP

#include "coral/inet/cgi/environment/variables/values.hpp"
#include "coral/inet/cgi/environment/variable/name.hpp"
#include "coral/inet/cgi/environment/variable/which.hpp"
#include "coral/base/string.hpp"

namespace coral {
namespace inet {
namespace cgi {
namespace environment {
namespace variables {

typedef array_implements array_implements;
typedef xos::base::arrayt<char_t*, size_t, variable::count+1> array_extends;
///////////////////////////////////////////////////////////////////////
///  Class: array
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS array: virtual public array_implements, public array_extends {
public:
    typedef array_implements Implements;
    typedef array_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    array(const variables::values& values): eq_((char_t)'=') {
        set(values);
    }
    array(): eq_((char_t)'=') {
        clear();
    }
    virtual ~array() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t set(const variables::values& values) {
        size_t count = 0;
        if (!(variable::count != (count = clear()))) {
            string_base_t* s = s_.elements();
            char_t** e = elements();
            for (variable::which_t i = variable::first; i <= variable::last; ++i) {
                const char_t* chars = values[i].has_chars();
                if ((chars)) {
                    s[i-variable::first].append(chars);
                    e[i-variable::first] = s[i-variable::first].buffer();
                }
            }
        }
        return count;
    }
    virtual size_t clear() {
        size_t count = 0;
        if ((count = set_length(variable::count)) < (size())) {
            string_base_t* s = s_.elements();
            char_t** e = elements();
            for (variable::which_t i = variable::first; i <= variable::last; ++i) {
                s[i-variable::first].assign(variable::name::of(i));
                s[i-variable::first].append(&eq_, 1);
                e[i-variable::first] = s[i-variable::first].buffer();
            }
            e[variable::count] = 0;
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* set(variable::which_t i, const char_t* chars) {
        if ((i >= variable::first) && (i <= variable::last)) {
            const char_t* result = 0;
            if ((result = clear(i))) {
                if ((chars)) {
                    string_base_t* s = s_.elements();
                    char_t** e = elements();
                    s[i-variable::first].append(chars);
                    e[i-variable::first] = s[i-variable::first].buffer();
                    result = e[i-variable::first];
                }
                return result;
            }
        }
        return 0;
    }
    virtual const char_t* clear(variable::which_t i) {
        if ((i >= variable::first) && (i <= variable::last)) {
            string_base_t* s = s_.elements();
            char_t** e = elements();
            s[i-variable::first].assign(variable::name::of(i));
            s[i-variable::first].append(&eq_, 1);
            e[i-variable::first] = s[i-variable::first].buffer();
            return e[i-variable::first];
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef arrayt<string_base_t, size_t, variable::count> strings_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t eq_;
    strings_t s_;
};

} // namespace variables 
} // namespace environment 
} // namespace cgi 
} // namespace inet 
} // namespace coral 

#endif // _CORAL_INET_CGI_ENVIRONMENT_VARIABLES_ARRAY_HPP 
