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
///   File: writer.hpp
///
/// Author: $author$
///   Date: 1/5/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_INET_CGI_ENVIRONMENT_VARIABLES_WRITER_HPP
#define _CORAL_INET_CGI_ENVIRONMENT_VARIABLES_WRITER_HPP

#include "coral/inet/cgi/environment/variables/values.hpp"
#include "coral/io/writer.hpp"

namespace coral {
namespace inet {
namespace cgi {
namespace environment {
namespace variables {

typedef implement_base writer_implements;
typedef base writer_extends;
///////////////////////////////////////////////////////////////////////
///  Class: writert
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char_t,
 typename TWhat = void,
 class TWriter = xos::io::writert<TWhat, TChar>,
 typename TWhich = variable::which_t,
 TWhich VFirst = variable::first, TWhich VLast = variable::last,
 class TName = variable::namet<TChar, TWhich>,
 class TValues = valuest<TChar, TWhich, VFirst, VLast>,
 class TImplements = writer_implements, class TExtends = writer_extends>

class _EXPORT_CLASS writert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename TValues::value_t value_t;
    typedef TName name_t;
    typedef TValues values_t;
    typedef TWhich which_t;
    enum { first = VFirst, last = VLast };
    typedef TWriter writer_t;
    typedef TChar char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    writert(): eq_((char_t)'='), cr_((char_t)'\r'), lf_((char_t)'\n') {
    }
    virtual ~writert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t write(writer_t& writer, const values_t& values) {
        ssize_t count = 0;
        ssize_t amount = 0;
        ssize_t length = 0;
        const char_t* chars = 0;
        for (which_t e = first; e <= last; ++e) {
            const value_t& v = values[e];
            const name_t n(e);
            if ((chars = n.wrapped()) && (0 < (length = n.length()))) {
                if (0 < (amount = writer.write(chars, length))) {
                    count += amount;
                    if ((chars = v.wrapped()) && (0 < (length = v.length()))) {
                        if (0 < (amount = writer.write(&eq_, 1))) {
                            count += amount;
                            if (0 < (amount = writer.write(chars, length))) {
                                count += amount;
                            }
                        }
                    }
                    if (0 < (amount = writer.write(&cr_, 1))) {
                        count += amount;
                        if (0 < (amount = writer.write(&lf_, 1))) {
                            count += amount;
                        }
                    }
                }
            }
        }
        if (0 < (amount = writer.write(&cr_, 1))) {
            count += amount;
            if (0 < (amount = writer.write(&lf_, 1))) {
                count += amount;
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t eq_, cr_, lf_;
};
typedef writert<> writer;

} // namespace variables 
} // namespace environment 
} // namespace cgi 
} // namespace inet 
} // namespace coral 

#endif // _CORAL_INET_CGI_ENVIRONMENT_VARIABLES_WRITER_HPP 
