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
///   Date: 10/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_URL_ENCODED_WRITER_HPP
#define _MEDUSA_INET_HTTP_URL_ENCODED_WRITER_HPP

#include "medusa/inet/http/url/encoded/reader.hpp"
#include "xos/io/writer.hpp"

#define MEDUSA_INET_HTTP_URL_ENCODED_WRITER_CHAR_TO_X1(x, c) \
    (x = ((x = (((unsigned char)(c) >> 4) & 15)) > 9)?('A' + (x - 10)):('0' + x))

#define MEDUSA_INET_HTTP_URL_ENCODED_WRITER_CHAR_TO_X2(x, c) \
    (x = ((x = (((unsigned char)(c)) & 15)) > 9)?('A' + (x - 10)):('0' + x))

namespace medusa {
namespace inet {
namespace http {
namespace url {
namespace encoded {

typedef base writer_extends;
///////////////////////////////////////////////////////////////////////
///  Class: writert
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = void, typename TSized = char_t,
 typename TEnd = int, TEnd VEnd = 0,
 class TWriter = xos::io::writert<TWhat, TSized, TEnd, VEnd>,
 class TImplements = TWriter, class TExtends = writer_extends>

class _EXPORT_CLASS writert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef writert Derives;

    typedef TWriter writer_t;
    typedef TWhat what_t;
    typedef TSized sized_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    writert(writer_t& writer): writer_(writer) {
    }
    virtual ~writert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t write(const what_t* what, ssize_t size) {
        if (0 > (size)) {
            return write(what);
        }
        return write(what, ((size_t)size));
    }
    virtual ssize_t write(const what_t* what, size_t size) {
        const sized_t* sized = 0;

        if ((sized = ((const sized_t*)what)) && (size > 0)) {
            ssize_t count = 0, amount = 0;

            for (sized_t c = (*(sized)); size; --size, c = (*(++sized))) {
                if (0 < (amount = write(c))) {
                    count += amount;
                }
            }
            return count;
        }
        return 0;
    }
    virtual ssize_t write(const what_t* what) {
        const sized_t* sized = 0;

        if ((sized = ((const sized_t*)what))) {
            ssize_t count = 0, amount = 0;

            for (sized_t c = (*(sized)); c; c = (*(++sized))) {
                if (0 < (amount = write(c))) {
                    count += amount;
                }
            }
            return count;
        }
        return 0;
    }
    virtual ssize_t write(const sized_t& sized) {
        ssize_t count = 0, amount = 0;
        sized_t c = sized, x = ((sized_t)'%'), x1 = 0, x2 = 0;
        char cc = ((char)c);

        switch (cc) {
        case ' ':
            c = ((sized_t)'+');
            if (0 < (amount = writer_.write(&c, 1))) {
                count += amount;
            }
            break;
        case '-':
        case '_':
        case '.':
        case '=':
        case '&':
        case '/':
            if (0 < (amount = writer_.write(&c, 1))) {
                count += amount;
            }
            break;
        default:
            if (((cc >= '0') && (cc <= '9'))
                || ((cc >= 'A') && (cc <= 'Z')) 
                || ((cc >= 'a') && (cc <= 'z'))) {
                if (0 < (amount = writer_.write(&c, 1))) {
                    count += amount;
                }
            } else {
                MEDUSA_INET_HTTP_URL_ENCODED_WRITER_CHAR_TO_X1(x1, c);
                MEDUSA_INET_HTTP_URL_ENCODED_WRITER_CHAR_TO_X2(x2, c);
                if (0 < (amount = writer_.write(&x, 1))) {
                    count += amount;
                    if (0 < (amount = writer_.write(&x1, 1))) {
                        count += amount;
                        if (0 < (amount = writer_.write(&x2, 1))) {
                            count += amount;
                        }
                    }
                }
            }
            break;
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    writer_t& writer_;
}; /// class _EXPORT_CLASS writert

typedef writert<> writer;

} /// namespace encoded
} /// namespace url
} /// namespace http
} /// namespace inet
} /// namespace medusa

#endif ///ndef _MEDUSA_INET_HTTP_URL_ENCODED_WRITER_HPP
