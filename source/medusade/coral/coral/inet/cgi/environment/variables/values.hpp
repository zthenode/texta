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
///   File: values.hpp
///
/// Author: $author$
///   Date: 1/4/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_INET_CGI_ENVIRONMENT_VARIABLES_VALUES_HPP
#define _CORAL_INET_CGI_ENVIRONMENT_VARIABLES_VALUES_HPP

#include "coral/inet/cgi/environment/variable/value.hpp"
#include "coral/inet/cgi/environment/variable/name.hpp"
#include "coral/inet/cgi/environment/variable/which.hpp"
#include "coral/base/array.hpp"
#include "coral/io/logger.hpp"

namespace coral {
namespace inet {
namespace cgi {
namespace environment {
namespace variables {

enum exception {
    invalid_which = 1
};
typedef array_implements values_implements;
///////////////////////////////////////////////////////////////////////
///  Class: valuest
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char_t,
 typename TWhich = variable::which_t,
 TWhich VFirst = variable::first,
 TWhich VLast = variable::last,
 typename TSize = size_t,
 TSize VSize = variable::count,
 class TName = variable::namet<TChar, TWhich>,
 class TValue = variable::valuet<TChar, TWhich>,
 class TExtends = xos::base::arrayt<TValue, TSize, VSize>,
 class TImplements = values_implements>

class _EXPORT_CLASS valuest: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TValue value_t;
    typedef TName name_t;
    typedef TWhich which_t;
    enum { first = VFirst, last = VLast };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    valuest(const valuest& copy): Extends(copy) {
    }
    valuest() {
    }
    virtual ~valuest() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual valuest& get() {
        for (which_t which = first; which <= last; ++which) {
            this->operator[](which).get(which);
        }
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual value_t* operator[](const char_t* named) const {
        if ((named) && (named[0])) {
            which_t which = name_t::which(named);
            if ((which >= first) && (which <= last)) {
                return &(Extends::operator[](which-first));
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual value_t& operator[](which_t which) const {
        if ((which < first) || (which > last)) {
            exception e = invalid_which;
            CORAL_LOG_ERROR("throwing invalid_which[" << which << "]...");
            throw (e);
        }
        return (value_t&)(Extends::operator[](which-first));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef valuest<> values;

} // namespace variables
} // namespace environment 
} // namespace cgi 
} // namespace inet 
} // namespace coral 

#endif // _CORAL_INET_CGI_ENVIRONMENT_VARIABLES_VALUES_HPP
