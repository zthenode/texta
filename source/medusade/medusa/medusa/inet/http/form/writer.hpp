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
///   File: writer.hpp
///
/// Author: $author$
///   Date: 10/29/2018
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_FORM_WRITER_HPP
#define _MEDUSA_INET_HTTP_FORM_WRITER_HPP

#include "medusa/inet/http/form/fields.hpp"
#include "medusa/inet/http/form/field.hpp"
#include "medusa/io/writer.hpp"

namespace medusa {
namespace inet {
namespace http {
namespace form {

typedef implement_base writer_implements;
typedef base writer_extends;
///////////////////////////////////////////////////////////////////////
///  Class: writert
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = void, typename TSized = char_t,
 typename TEnd = int, TEnd VEnd = 0,
 class TWriter = xos::io::writert<TWhat, TSized, TEnd, VEnd>,
 class TField = fieldt<TSized, TEnd, VEnd>, class TFields = fieldst<TField>,
 class TImplements = writer_implements, class TExtends = writer_extends>

class _EXPORT_CLASS writert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef writert Derives;

    typedef TFields fields_t;
    typedef TField field_t;
    typedef TWriter writer_t;
    typedef TWhat what_t;
    typedef TSized sized_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    writert(const writert& copy)
    : Extends(copy), fields_(copy.fields_), eq_(copy.eq_), amp_(copy.amp_) {
    }
    writert(fields_t& fields)
    : fields_(fields), eq_((sized_t)'='), amp_((sized_t)'&') {
    }
    writert()
    : fields_(this_fields_), eq_((sized_t)'='), amp_((sized_t)'&') {
    }
    virtual ~writert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t write(writer_t& writer) {
        ssize_t count = 0, amount = 0;
        typename fields_t::const_iterator end = fields_.end();
        typename fields_t::const_iterator at = fields_.begin();
        if ((at != end)) {
            if (0 < (amount = write(writer, *at))) {
                count += amount;
                while (++at != end) {
                    if (0 < (amount = writer.write(&amp_, 1))) {
                        count += amount;
                        if (0 < (amount = write(writer, *at))) {
                            count += amount;
                        }
                    }
                }
            }
        }
        return count;
    }
    virtual ssize_t write(writer_t& writer, const field_t& field) {
        ssize_t count = 0, amount = 0;
        const char_t* chars = 0;
        size_t length = 0;
        if ((chars = field.name().has_chars(length))) {
            if (0 < (amount = writer.write(chars, length))) {
                count += amount;
                if (0 < (amount = writer.write(&eq_, 1))) {
                    count += amount;
                    if ((chars = field.value().has_chars(length))) {
                        if (0 < (amount = writer.write(chars, length))) {
                            count += amount;
                        }
                    }
                }
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual fields_t& fields() const {
        return ((fields_t&)this_fields_);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    fields_t this_fields_;
    const fields_t& fields_;
    const sized_t eq_;
    const sized_t amp_;
}; /// class _EXPORT_CLASS writert

typedef writert<> writer;

} /// namespace form
} /// namespace http
} /// namespace inet
} /// namespace medusa

#endif ///ndef _MEDUSA_INET_HTTP_FORM_WRITER_HPP
