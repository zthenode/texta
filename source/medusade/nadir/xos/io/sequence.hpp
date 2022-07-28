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
///   File: sequence.hpp
///
/// Author: $author$
///   Date: 11/16/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_SEQUENCE_HPP
#define _XOS_NADIR_XOS_IO_SEQUENCE_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace io {

typedef base::implement_base sequence_implement;
///////////////////////////////////////////////////////////////////////
///  Class: sequencet
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = char, typename TEnd = int, TEnd VEnd = 0,
 class TImplements = sequence_implement>

class _EXPORT_CLASS sequencet: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TWhat what_t;
    typedef TWhat char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual char_t dtox(uint8_t d, bool upper_case = false) const {
        const char a = (upper_case)?('A'):('a');
        char_t x = (char_t)(0);
        if ((0 <= d) && (9 >= d)) {
            x = (char_t)(('0') +  d);
        } else {
            if ((10 <= d) && (15 >= d)) {
                x = (char_t)((a) + (d - 10));
            } else {
                x = invalid_dtox(d);
            }
        }
        return x;
    }
    virtual int8_t xtod(const char_t& x) const {
        int8_t d = (int8_t)(0);
        if (((char_t)('A') <= x) && ((char_t)('F') >= x)) {
            d = ((x - (char_t)('A')) + 10);
        } else {
            if (((char_t)('a') <= x) && ((char_t)('f') >= x)) {
                d = ((x - (char_t)('a')) + 10);
            } else {
                if (((char_t)('0') <= x) && ((char_t)('9') >= x)) {
                    d = ((x - (char_t)('0')));
                } else {
                    d = invalid_xtod(x);
                }
            }
        }
        return d;
    }
    virtual char_t invalid_dtox(uint8_t d) const {
        return (char_t)(0);
    }
    virtual int8_t invalid_xtod(const char_t& x) const {
        return (int8_t)(-1);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual char_t dtob64(uint8_t d) const {
        char_t x = (char_t)(0);
        if ((0 <= d) && (25 >= d)) {
            x = (char_t)(('A') + d);
        } else {
            if ((26 <= d) && (51 >= d)) {
                x = (char_t)(('a') + (d - 26));
            } else {
                if ((52 <= d) && (61 >= d)) {
                    x = (char_t)(('0') + (d - 52));
                } else {
                    if ((62 == d)) {
                        x = (char_t)(('+'));
                    } else {
                        if ((63 == d)) {
                            x = (char_t)(('/'));
                        } else {
                            x = invalid_dtob64(d);
                        }
                    }
                }
            }
        }
        return x;
    }
    virtual int8_t b64tod(const char_t& x) const {
        int8_t d = (int8_t)(0);
        if (((char_t)('A') <= x) && ((char_t)('Z') >= x)) {
            d = (x - (char_t)('A'));
        } else {
            if (((char_t)('a') <= x) && ((char_t)('z') >= x)) {
                d = ((x - (char_t)('a')) + 26);
            } else {
                if (((char_t)('0') <= x) && ((char_t)('9') >= x)) {
                    d = ((x - (char_t)('0')) + 52);
                } else {
                    if (((char_t)('+') == x)) {
                        d = (62);
                    } else {
                        if (((char_t)('/') == x)) {
                            d = (63);
                        } else {
                            d = invalid_b64tod(x);
                        }
                    }
                }
            }
        }
        return d;
    }
    virtual char_t invalid_dtob64(uint8_t d) const {
        return (char_t)(0);
    }
    virtual int8_t invalid_b64tod(const char_t& x) const {
        return (int8_t)(-1);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef sequencet<> sequence;
typedef sequencet<byte_t> byte_sequence;
typedef sequencet<char_t> char_sequence;
typedef sequencet<wchar_t> wchar_sequence;
typedef sequencet<tchar_t> tchar_sequence;

} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_SEQUENCE_HPP 
