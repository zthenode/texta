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
///   File: writer.hpp
///
/// Author: $author$
///   Date: 8/26/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_WRITER_HPP
#define _XOS_NADIR_XOS_IO_WRITER_HPP

#include "xos/io/sequence.hpp"
#include "xos/base/base.hpp"

namespace xos {
namespace io {

typedef sequencet<char> writer_implement;
///////////////////////////////////////////////////////////////////////
///  Class: writert
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = void, typename TSized = char,
 typename TEnd = int, TEnd VEnd = 0,
 class TImplements = sequencet<TSized, TEnd, VEnd> >

class _EXPORT_CLASS writert: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TWhat what_t;
    typedef TSized sized_t;
    typedef TSized char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t write(const what_t* what, ssize_t size = -1) { return 0; }
    virtual ssize_t flush() { return 0; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t writel(const what_t* what, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, what);
        count = writev(what, va);
        va_end(va);
        return count;
    }
    virtual ssize_t writev(const what_t* what, va_list va) {
        ssize_t count = 0;
        ssize_t length = 0;
        for (count = 0; what; count += length) {
            if (0 > (length = write(what)))
                return count;
            what = va_arg(va, const sized_t*);
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t writef(const what_t* format, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, format);
        count = writefv(format, va);
        va_end(va);
        return count;
    }
    virtual ssize_t writefv(const what_t* format, va_list va) {
        ssize_t count = 0;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t writeln(const what_t* out, ssize_t length = -1) {
        ssize_t count = 0;
        ssize_t amount;
        if (0 <= (amount = this->write(out, length))) {
            count += amount;
            if (0 <= (amount = this->writeln())) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t writeln() {
        const char_t ln = ((char_t)'\n');
        ssize_t count = this->write(&ln, 1);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t writexln(const void* out, size_t length, bool upper_case = false) {
        ssize_t count = 0, amount = 0;
        if (0 <= (amount = this->writex(out, length, upper_case))) {
            count += amount;
            if (0 <= (amount = this->writeln())) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t writex(const void* out, size_t length, bool upper_case = false) {
        ssize_t count = 0;
        const uint8_t* bytes = 0;

        if ((bytes = (const uint8_t*)(out)) && (length)) {
            ssize_t amount = 0;
            uint8_t b = 0;
            char_t x[2];

            for (; 0 < length; --length) {
                b = (*bytes++);
                x[0] = this->dtox(b >> 4, upper_case);
                x[1] = this->dtox(b & 15, upper_case);

                if (0 < (amount = this->write(x, 2))) {
                    count += amount;
                } else {
                    return amount;
                }
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t write0xln(const void* out, size_t length, bool upper_case = false) {
        ssize_t count = 0, amount = 0;
        if (0 <= (amount = this->write0x(out, length, upper_case))) {
            count += amount;
            if (0 <= (amount = this->writeln())) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t write0x(const void* out, size_t length, bool upper_case = false) {
        ssize_t count = 0;
        const uint8_t* bytes = 0;

        if ((bytes = (const uint8_t*)(out)) && (length)) {
            uint8_t b = (*bytes);
            ssize_t amount = 0;
            char_t x[5];

            x[0] = ((char_t)',');
            x[1] = ((char_t)'0');
            x[2] = ((char_t)((upper_case)?('X'):('x')));
            x[3] = this->dtox(b >> 4, upper_case);
            x[4] = this->dtox(b & 15, upper_case);

            if (0 < (amount = this->write(x+1, 4))) {
                count += amount;

                for (++bytes, --length; length > 0; --length, ++bytes) {
                    b = (*bytes);
                    x[3] = this->dtox(b >> 4, upper_case);
                    x[4] = this->dtox(b & 15, upper_case);

                    if (0 < (amount = this->write(x, 5))) {
                        count += amount;
                    } else {
                        return amount;
                    }
                }
            } else {
                return amount;
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t write64ln(const void* out, size_t length) {
        ssize_t count = 0, amount = 0;

        if (0 <= (amount = this->write64(out, length))) {
            count += amount;
            if (0 <= (amount = this->writeln())) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t write64(const void* out, size_t length) {
        ssize_t count = 0;
        const uint8_t* byte = 0;

        if ((byte = (const uint8_t*)(out)) && (length)) {
            ssize_t amount = 0;
            uint8_t b = 0, carry = 0, shift = 0;
            if (0 <= length) {
                for (carry = 0, shift = 2; 0 < length; --length, ++byte) {
                    b = (*byte);
                    if (0 > (amount = this->put64(b, carry, shift))) {
                        return amount;
                    }
                    count += amount;
                }
            } else {
                for (carry = 0, shift = 2; (b = (*byte)); ++byte) {
                    if (0 > (amount = this->put64(b, carry, shift))) {
                        return amount;
                    }
                    count += amount;
                }
            }
            if ((2 != (shift))) {
                if (0 > (amount = this->put64_end(carry, shift))) {
                    return amount;
                }
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t put64(uint8_t b, uint8_t& carry, uint8_t& shift) {
        const uint8_t mask = ((uint8_t)-1);
        ssize_t count = 0, amount = 0;
        sized_t x = (sized_t)(0);
        x = (sized_t)(this->dtob64(carry | (b >> shift)));
        if (0 > (amount = this->write((const what_t*)(&x), 1))) {
            return amount;
        }
        count += amount;
        carry = (b & (mask >> (8 - shift))) << (6 - shift);
        if (6 > (shift)) {
            shift += 2;
        } else {
            x = (sized_t)(this->dtob64(carry));
            if (0 > (amount = this->write((const what_t*)(&x), 1))) {
                return amount;
            }
            count += amount;
            carry = 0;
            shift = 2;
        }
        return count;
    }
    virtual ssize_t put64_end(uint8_t& carry, uint8_t& shift) {
        ssize_t count = 0, amount = 0;
        sized_t x = (sized_t)(0);
        x = (sized_t)(this->dtob64(carry));
        if (0 > (amount = this->write((const what_t*)(&x), 1))) {
            return amount;
        }
        count += amount;
        for (x = ((sized_t)'='); shift != 2;) {
            if (0 > (amount = this->write((const what_t*)(&x), 1))) {
                return amount;
            }
            count += amount;
            if (6 > (shift)) {
                shift += 2;
            } else {
                shift = 2;
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef writert<void, char, int, 0> writer;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef writert<char, char, int, 0> char_writer;
typedef writert<wchar_t, wchar_t, int, 0> wchar_writer;
typedef writert<tchar_t, tchar_t, int, 0> tchar_writer;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef writert<byte_t, byte_t, int, 0> byte_writer;
typedef writert<word_t, word_t, int, 0> word_writer;

} // namespace io
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_WRITER_HPP 
