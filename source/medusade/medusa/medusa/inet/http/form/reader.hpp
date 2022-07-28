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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 1/12/2015
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_FORM_READER_HPP
#define _MEDUSA_INET_HTTP_FORM_READER_HPP

#include "medusa/inet/http/form/fields.hpp"
#include "medusa/inet/http/form/field.hpp"
#include "medusa/io/reader.hpp"

namespace medusa {
namespace inet {
namespace http {
namespace form {

typedef implement_base reader_implements;
typedef base reader_extends;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = void, typename TSized = char_t,
 typename TEnd = int, TEnd VEnd = 0,
 class TReader = xos::io::readert<TWhat, TSized, TEnd, VEnd>,
 class TField = fieldt<TSized, TEnd, VEnd>, class TFields = fieldst<TField>,
 class TImplements = reader_implements, class TExtends = reader_extends>

class _EXPORT_CLASS readert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef readert Derives;

    typedef TFields fields_t;
    typedef TField field_t;
    typedef TReader reader_t;
    typedef TWhat what_t;
    typedef TSized sized_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    readert(fields_t& fields)
    : eq_((sized_t)'='), amp_((sized_t)'&'),
      /*end_(empty_.end()),*/ 
      fields_(fields), end_(fields_.end()), field_(end_), on_(0) {
    }
    virtual ~readert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read(reader_t& reader) {
        fields_.clear();
        return read_more(reader);
    }
    virtual ssize_t read_more(reader_t& reader) {
        ssize_t count = 0, amount = 0;
        sized_t sized;
        on_begin();
        while (0 < (amount = reader.read(&sized, 1))) {
            on(sized);
        }
        on_end();
        return count;
    }

protected:
    typedef void (Derives::*on_t)(const sized_t& sized);
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_begin() {
        field_t field;
        fields_.push_back(field);
        --(field_ = (end_ = fields_.end()));
        on_ = &Derives::on_name;
    }
    virtual void on_end() {
        if ((field_ != end_)) {
            if (!((*field_).name().length())) {
                fields_.pop_back();
            }
            field_ = (end_ = fields_.end());
        }
        on_ = 0;
    }
    virtual void on_next() {
        field_t field;
        fields_.push_back(field);
        --(field_ = fields_.end());
        on_ = &Derives::on_name;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on(const sized_t& sized) {
        if ((on_)) {
            (this->*on_)(sized);
        }
    }
    virtual void on_name(const sized_t& sized) {
        if ((field_ != end_)) {
            if ((sized != eq_)) {
                if ((sized != amp_)) {
                    (*field_).name().append(&sized, 1);
                } else {
                    if (0 < ((*field_).name().length())) {
                        on_next();
                    }
                }
            } else {
                if (0 < ((*field_).name().length())) {
                    on_ = &Derives::on_value;
                } else {
                    on_ = &Derives::on_no_name;
                }
            }
        }
    }
    virtual void on_value(const sized_t& sized) {
        if ((field_ != end_)) {
            if ((sized != amp_)) {
                (*field_).value().append(&sized, 1);
            } else {
                on_next();
            }
        }
    }
    virtual void on_no_name(const sized_t& sized) {
        if ((sized == amp_)) {
            on_ = &Derives::on_name;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const sized_t eq_;
    const sized_t amp_;
    /*fields_t empty_;
    const typename fields_t::iterator end_;*/
    fields_t& fields_;
    typename fields_t::iterator end_;
    typename fields_t::iterator field_;
    on_t on_;
};
typedef readert<> reader;

} // namespace form 
} // namespace http 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_HTTP_FORM_READER_HPP 
