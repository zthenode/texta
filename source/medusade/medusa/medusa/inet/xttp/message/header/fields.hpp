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
///   File: fields.hpp
///
/// Author: $author$
///   Date: 11/23/2014
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_MESSAGE_HEADER_FIELDS_HPP
#define _MEDUSA_INET_XTTP_MESSAGE_HEADER_FIELDS_HPP

#include "medusa/inet/xttp/message/header/field.hpp"
#include <list>

namespace medusa {
namespace inet {
namespace xttp {
namespace message {
namespace header {

typedef std::list<field> field_list;
typedef string_t_implements fields_implements;
typedef string_t fields_extends;
///////////////////////////////////////////////////////////////////////
///  Class: fieldst
///////////////////////////////////////////////////////////////////////
template
<typename TFieldList = field_list, typename TField = field,
 class TImplements = fields_implements, class TExtends = fields_extends>

class _EXPORT_CLASS fieldst: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TField field_t;
    typedef TFieldList field_list_t;
    typedef typename TFieldList::const_iterator field_list_iterator_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    fieldst(const fieldst& copy)
    : Extends(copy),
      list_(copy.list_) {
    }
    fieldst() {
    }
    virtual ~fieldst() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual fieldst& clear() {
        Extends::clear();
        list_.clear();
        return *this;
    }
    virtual fieldst& combine() {
        Extends::clear();
        for (field_list_iterator_t i = list_.begin(); i != list_.end(); ++i) {
            Extends::append(i->chars());
        }
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual fieldst& assign(const fieldst& fields) {
        clear();
        append(fields);
        return *this;
    }
    virtual fieldst& append(const fieldst& fields) {
        const field_list_t& list = fields.list();
        for (field_list_iterator_t i = list.begin(); i != list.end(); ++i) {
            list_.push_back(*i);
        }
        combine();
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual fieldst& assign(const field_t* fields, size_t length) {
        clear();
        append(fields, length);
        return *this;
    }
    virtual fieldst& append(const field_t* fields, size_t length) {
        if ((fields)) {
            for (; length; --length, ++fields) {
                list_.push_back(*fields);
            }
        }
        combine();
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual field_list_t& list() const {
        return (field_list_t&)list_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    field_list_t list_;
};
typedef fieldst<> fields;

} // namespace header 
} // namespace message 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_MESSAGE_HEADER_FIELDS_HPP 
