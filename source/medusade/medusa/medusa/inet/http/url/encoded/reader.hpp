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
///   Date: 1/11/2015
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_URL_ENCODED_READER_HPP
#define _MEDUSA_INET_HTTP_URL_ENCODED_READER_HPP

#include "medusa/base/base.hpp"
#include "xos/io/reader.hpp"

#define MEDUSA_INET_HTTP_URL_ENCODED_READER_CHAR_IS_X(x) \
    (((x) >= '0' && (x) <= '9') \
    || ((x) >= 'a' && (x) <= 'f') \
    || ((x) >= 'A' && (x) <= 'F'))

#define MEDUSA_INET_HTTP_URL_ENCODED_READER_X_TO_CHAR(x) \
    (((x) >= '0' && (x) <= '9')?((x)-'0') \
    :(((x) >= 'a' && (x) <= 'f')?((x)-'a'+10) \
    :((x)-'A'+10)))

namespace medusa {
namespace inet {
namespace http {
namespace url {
namespace encoded {

typedef base reader_extends;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = void, typename TSized = char_t,
 typename TEnd = int, TEnd VEnd = 0,
 class TReader = xos::io::readert<TWhat, TSized, TEnd, VEnd>,
 class TImplements = TReader, class TExtends = reader_extends>

class _EXPORT_CLASS readert: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef readert Derives;

    typedef TReader reader_t;
    typedef TWhat what_t;
    typedef TSized sized_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    readert(reader_t& reader): reader_(reader) {
    }
    virtual ~readert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read(what_t* what, size_t size) {
        sized_t* sized = 0;
        if ((sized = ((sized_t*)what)) && (size)) {
            ssize_t count = 0, amount = 0;
            byte_t x1 = 0, x2 = 0;
            char c = 0;
            while (count < size) {
                if (0 < (amount = reader_.read(sized, 1))) {
                    switch (c = ((char)*sized)) {
                    case '%':
                        if (0 < (amount = readx(x1, sized))) {
                            if (0 < (amount = readx(x2, sized))) {
                                *sized = ((sized_t)((x1 << 4) | x2));
                            } else {
                                return amount;
                            }
                        } else {
                            return amount;
                        }
                        break;
                    case '+':
                        *sized = ((sized_t)' ');
                        break;
                    default:
                        break;
                    }
                    ++sized;
                    ++count;
                } else {
                    return amount;
                }
            }
            return count;
        }
        return 0;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t readx(byte_t& x, what_t* what) {
        sized_t* sized = 0;
        if ((sized = ((sized_t*)what))) {
            ssize_t amount = 0;
            if (0 < (amount = reader_.read(what, 1))) {
                const char c = ((char)*sized);
                if (MEDUSA_INET_HTTP_URL_ENCODED_READER_CHAR_IS_X(c)) {
                    x = MEDUSA_INET_HTTP_URL_ENCODED_READER_X_TO_CHAR(c);
                } else {
                    return 0;
                }
            }
            return amount;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    reader_t& reader_;
};

typedef readert<> reader;

} // namespace encoded 
} // namespace url 
} // namespace http 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_HTTP_URL_ENCODED_READER_HPP 
