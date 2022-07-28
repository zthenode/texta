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
///   File: fields.hpp
///
/// Author: $author$
///   Date: 10/29/2018
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_URL_ENCODED_FORM_FIELDS_HPP
#define _MEDUSA_INET_HTTP_URL_ENCODED_FORM_FIELDS_HPP

#include "medusa/inet/http/url/encoded/reader.hpp"
#include "medusa/inet/http/url/encoded/writer.hpp"
#include "medusa/inet/http/form/reader.hpp"
#include "medusa/inet/http/form/writer.hpp"
#include "medusa/inet/http/form/fields.hpp"

namespace medusa {
namespace inet {
namespace http {
namespace url {
namespace encoded {
namespace form {

typedef encoded::writer fieldst_encoder;
typedef encoded::reader fieldst_decoder;
typedef http::form::reader fieldst_reader;
typedef http::form::writer fieldst_writer;
typedef http::form::fields_implements fieldst_implements;
typedef http::form::fields fieldst_extends;
///////////////////////////////////////////////////////////////////////
///  Class: fieldst
///////////////////////////////////////////////////////////////////////
template 
<class TEncoder = fieldst_encoder,class TDecoder = fieldst_decoder,
 class TReader = fieldst_reader, class TWriter = fieldst_writer,
 class TImplements = fieldst_implements, class TExtends = fieldst_extends>

class _EXPORT_CLASS fieldst: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TReader fields_reader_t;
    typedef TWriter fields_writer_t;
    typedef TEncoder encoder_t;
    typedef TDecoder decoder_t;
    typedef typename encoder_t::writer_t writer_t;
    typedef typename decoder_t::reader_t reader_t;
    
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
    virtual ssize_t write(writer_t& writer) {
        encoder_t encoder(writer);
        fields_writer_t fields(*this);
        ssize_t count = 0, amount = 0;
        if (0 < (amount = fields.write(encoder))) {
            count += amount;
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS fieldst

typedef fieldst<> fields;

} /// namespace form
} /// namespace encoded
} /// namespace url
} /// namespace http
} /// namespace inet
} /// namespace medusa

#endif ///ndef _MEDUSA_INET_HTTP_URL_ENCODED_FORM_FIELDS_HPP
