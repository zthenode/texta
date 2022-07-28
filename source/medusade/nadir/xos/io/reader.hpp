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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 8/27/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_READER_HPP
#define _XOS_NADIR_XOS_IO_READER_HPP

#include "xos/io/sequence.hpp"
#include "xos/base/base.hpp"

namespace xos {
namespace io {

typedef sequencet<char> reader_implement;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = void, typename TSized = char,
 typename TEnd = int, TEnd VEnd = 0,
 class TImplements = reader_implement>

class _EXPORT_CLASS readert: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TWhat what_t;
    typedef TSized sized_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read(what_t* what, size_t size) { return 0; }
    virtual ssize_t fill() { return 0; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t seek(ssize_t offset, int whence) { return -1; }
    virtual ssize_t tell() { return -1; }
    virtual ssize_t eof() { return -1; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t readf(const what_t* format, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, format);
        count = readfv(format, va);
        va_end(va);
        return count;
    }
    virtual ssize_t readfv(const what_t* format, va_list va) {
        ssize_t count = 0;
        return count;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read64(void* in, size_t size) {
        ssize_t count = 0;
        uint8_t* byte = 0;

        if ((byte = (uint8_t*)(in)) && (0 < size)) {
            ssize_t amount = 0;
            uint8_t carry = 0, shift = 0, b[2];

            for (carry = 0, shift = 2; 0 < size; size += amount, byte += amount) {
                if (0 > (amount = this->get64(b, carry, shift))) {
                    return amount;
                } else {
                    if (0 < (amount)) {
                        for (ssize_t i = 0; i < amount; ++i) {
                            byte[i] = b[i];
                        }
                        count += amount;
                    } else {
                        break;
                    }
                }
            }
        }
        return count;
    }
    virtual ssize_t get64(uint8_t b[], uint8_t& carry, uint8_t& shift) {
        const uint8_t mask = ((uint8_t)-1);
        ssize_t count = 0, amount = 0;
        uint8_t n = 0;
        int8_t d = 0;
        sized_t x = (sized_t)(0);

        if (2 == (shift)) {
            for (n = 0; n < 2;) {
                if (0 >= (amount = this->read(&x, 1))) {
                    if (0 > (amount)) {
                        return amount;
                    } else {
                        shift = 2;
                        if (n < 1) {
                            carry = 0;
                            return 0;
                        } else {
                            b[0] = carry;
                            carry = 0;
                            return 1;
                        }
                    }
                } else {
                    if (0 <= (d = this->b64tod(x))) {
                        if (n < 1) {
                            carry = (((uint8_t)d) << 2);
                        } else {
                            shift += 2;
                            b[0] = (carry | (((uint8_t)d) >> 4));
                            carry = ((((uint8_t)d) & (mask >> 4)) << 4);
                            count = 1;
                        }
                        ++n;
                    }
                }
            }
        } else {
            if (4 == (shift)) {
                for (n = 0; n < 2;) {
                    if (0 >= (amount = this->read(&x, 1))) {
                        if (0 > amount) {
                            return amount;
                        } else {
                            b[n] = carry;
                            carry = 0;
                            shift = 2;
                            return 1;
                        }
                    } else {
                        if (0 <= (d = this->b64tod(x))) {
                            b[n] = (carry | (((uint8_t)d) >> (6 - shift)));
                            if (n < 1) {
                                carry = ((((uint8_t)d) & (mask >> 6)) << 6);
                                shift += 2;
                            } else {
                                carry = 0;
                                shift = 2;
                                count = 2;
                            }
                            ++n;
                        }
                    }
                }
            } else {
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef readert<void, char, int, 0> reader;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef readert<char, char, int, 0> char_reader;
typedef readert<wchar_t, wchar_t, int, 0> wchar_reader;
typedef readert<tchar_t, tchar_t, int, 0> tchar_reader;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef readert<word_t, word_t, int, 0> word_reader;
typedef readert<byte_t, byte_t, int, 0> byte_reader_implements;
class _EXPORT_CLASS byte_reader: virtual public byte_reader_implements {
public:
    typedef byte_reader_implements Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read_lsb(int16_t& lsb) {
        ssize_t count = 0;
        uint16_t ulsb = 0;
        if (sizeof(ulsb) == (count = read_lsb(ulsb))) {
            lsb = ((int16_t)ulsb);
        }
        return count;
    }
    virtual ssize_t read_lsb(int32_t& lsb) {
        ssize_t count = 0;
        uint32_t ulsb = 0;
        if (sizeof(ulsb) == (count = read_lsb(ulsb))) {
            lsb = ((int32_t)ulsb);
        }
        return count;
    }
    virtual ssize_t read_lsb(int64_t& lsb) {
        ssize_t count = 0;
        uint64_t ulsb = 0;
        if (sizeof(ulsb) == (count = read_lsb(ulsb))) {
            lsb = ((int64_t)ulsb);
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read_msb(int16_t& msb) {
        ssize_t count = 0;
        uint16_t umsb = 0;
        if (sizeof(umsb) == (count = read_msb(umsb))) {
            msb = ((int16_t)umsb);
        }
        return count;
    }
    virtual ssize_t read_msb(int32_t& msb) {
        ssize_t count = 0;
        uint32_t umsb = 0;
        if (sizeof(umsb) == (count = read_msb(umsb))) {
            msb = ((int32_t)umsb);
        }
        return count;
    }
    virtual ssize_t read_msb(int64_t& msb) {
        ssize_t count = 0;
        uint64_t umsb = 0;
        if (sizeof(umsb) == (count = read_msb(umsb))) {
            msb = ((int64_t)umsb);
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read_lsb(uint16_t& lsb) {
        ssize_t count = 0, amount = 0;
        uint16_t msb = 0;
        if (sizeof(msb) == (amount = read_msb(msb))) {
            for (lsb = 0; count < sizeof(msb); ++count) {
                lsb <<= 8;
                lsb |= (msb & 255);
                msb >>= 8;
            }
        }
        return count;
    }
    virtual ssize_t read_lsb(uint32_t& lsb) {
        ssize_t count = 0, amount = 0;
        uint32_t msb = 0;
        if (sizeof(msb) == (amount = read_msb(msb))) {
            for (lsb = 0; count < sizeof(msb); ++count) {
                lsb <<= 8;
                lsb |= (msb & 255);
                msb >>= 8;
            }
        }
        return count;
    }
    virtual ssize_t read_lsb(uint64_t& lsb) {
        ssize_t count = 0, amount = 0;
        uint64_t msb = 0;
        if (sizeof(msb) == (amount = read_msb(msb))) {
            for (lsb = 0; count < sizeof(msb); ++count) {
                lsb <<= 8;
                lsb |= (msb & 255);
                msb >>= 8;
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read_msb(uint16_t& msb) {
        ssize_t count = 0, amount = 0;
        byte_t b = 0;
        for (msb = 0; count < sizeof(msb); ++count) {
            if (sizeof(b) != (amount = this->read(&b, 1))) {
                return 0;
            }
            msb <<= 8;
            msb |= b;
        }
        return count;
    }
    virtual ssize_t read_msb(uint32_t& msb) {
        ssize_t count = 0, amount = 0;
        byte_t b = 0;
        for (msb = 0; count < sizeof(msb); ++count) {
            if (sizeof(b) != (amount = this->read(&b, 1))) {
                return 0;
            }
            msb <<= 8;
            msb |= b;
        }
        return count;
    }
    virtual ssize_t read_msb(uint64_t& msb) {
        ssize_t count = 0, amount = 0;
        byte_t b = 0;
        for (msb = 0; count < sizeof(msb); ++count) {
            if (sizeof(b) != (amount = this->read(&b, 1))) {
                return 0;
            }
            msb <<= 8;
            msb |= b;
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t WORD_read_lsb(WORD& lsb) {
        ssize_t count = 0, amount = 0;
        WORD msb = 0;
        if (sizeof(msb) == (amount = WORD_read_msb(msb))) {
            for (lsb = 0; count < sizeof(msb); ++count) {
                lsb <<= 8;
                lsb |= (msb & 255);
                msb >>= 8;
            }
        }
        return count;
    }
    virtual ssize_t DWORD_read_lsb(DWORD& lsb) {
        ssize_t count = 0, amount = 0;
        DWORD msb = 0;
        if (sizeof(msb) == (amount = DWORD_read_msb(msb))) {
            for (lsb = 0; count < sizeof(msb); ++count) {
                lsb <<= 8;
                lsb |= (msb & 255);
                msb >>= 8;
            }
        }
        return count;
    }
    virtual ssize_t LONG_read_lsb(LONG& lsb) {
        ssize_t count = 0, amount = 0;
        LONG msb = 0;
        if (sizeof(msb) == (amount = LONG_read_msb(msb))) {
            for (lsb = 0; count < sizeof(msb); ++count) {
                lsb <<= 8;
                lsb |= (msb & 255);
                msb >>= 8;
            }
        }
        return count;
    }

    virtual ssize_t WORD_read_msb(WORD& msb) {
        ssize_t count = 0, amount = 0;
        byte_t b = 0;
        for (msb = 0; count < sizeof(msb); ++count) {
            if (sizeof(b) != (amount = this->read(&b, 1))) {
                return 0;
            }
            msb <<= 8;
            msb |= b;
        }
        return count;
    }
    virtual ssize_t DWORD_read_msb(DWORD& msb) {
        ssize_t count = 0, amount = 0;
        byte_t b = 0;
        for (msb = 0; count < sizeof(msb); ++count) {
            if (sizeof(b) != (amount = this->read(&b, 1))) {
                return 0;
            }
            msb <<= 8;
            msb |= b;
        }
        return count;
    }
    virtual ssize_t LONG_read_msb(LONG& msb) {
        ssize_t count = 0, amount = 0;
        byte_t b = 0;
        for (msb = 0; count < sizeof(msb); ++count) {
            if (sizeof(b) != (amount = this->read(&b, 1))) {
                return 0;
            }
            msb <<= 8;
            msb |= b;
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace io
} // namespace xos

#endif // _XOS_NADIR_XOS_IO_READER_HPP
