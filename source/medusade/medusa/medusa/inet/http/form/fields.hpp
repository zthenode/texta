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
///   File: fields.hpp
///
/// Author: $author$
///   Date: 1/12/2015
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_FORM_FIELDS_HPP
#define _MEDUSA_INET_HTTP_FORM_FIELDS_HPP

#include "medusa/inet/http/form/field.hpp"
#include "medusa/base/base.hpp"

#include <list>

namespace medusa {
namespace inet {
namespace http {
namespace form {

typedef implement_base fields_implements;
///////////////////////////////////////////////////////////////////////
///  Class: fieldst
///////////////////////////////////////////////////////////////////////
template
<class TField = field, class TFields = std::list<TField>,
 class TExtends = TFields, class TImplements = fields_implements>

class _EXPORT_CLASS fieldst: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename TFields::const_iterator const_iterator;
    typedef typename TFields::iterator iterator;
    typedef typename TField::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef TField field_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    fieldst(const fieldst& copy): Extends(copy) {
    }
    fieldst() {
    }
    virtual ~fieldst() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    field_t& add(const string_t& name, const string_t& value) {
        const field_t field(name, value);
        return add(field);
    }
    field_t& add(const string_t& name) {
        const field_t field(name);
        return add(field);
    }
    field_t& add(const char_t* name, const char_t* value) {
        const field_t field(name, value);
        return add(field);
    }
    field_t& add(const char_t* name) {
        const field_t field(name);
        return add(field);
    }
    field_t& add(const field_t& field) {
        this->push_back(field);
        return this->back();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    field_t* find(const string_t& name, field_t* from = 0) {
        return find(name.chars(), from);
    }
    field_t* find(const char_t** names, field_t* from = 0) {
        if ((names) && (names[0])) {
            const iterator begin = this->begin();
            const iterator end = this->end();
            for (iterator i = begin; i != end; ++i) {
                field_t& found = *i;
                if ((from)) {
                    if (from == &found) {
                        from = 0;
                    }
                } else {
                    size_t n = 0;
                    for (const char_t* name = names[n]; name; name = names[++n]) {
                        if (!(found.name().compare(name))) {
                            return &found;
                        }
                    }
                }
            }
        }
        return 0;
    }
    field_t* find(const char_t* name, field_t* from = 0) {
        const iterator begin = this->begin();
        const iterator end = this->end();
        for (iterator i = begin; i != end; ++i) {
            field_t& found = *i;
            if ((from)) {
                if (from == &found) {
                    from = 0;
                }
            } else {
                if (!(found.name().compare(name))) {
                    return &found;
                }
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef fieldst<> fields;

} // namespace form 
} // namespace http 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_HTTP_FORM_FIELDS_HPP 
