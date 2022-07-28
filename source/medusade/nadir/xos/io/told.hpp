///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2019 $organization$
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
///   File: told.hpp
///
/// Author: $author$
///   Date: 3/31/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_TOLD_HPP
#define _XOS_NADIR_XOS_IO_TOLD_HPP

#include "xos/io/sequence.hpp"

namespace xos {
namespace io {

///////////////////////////////////////////////////////////////////////
///  Enum: from_t
///////////////////////////////////////////////////////////////////////
typedef int from_t;
enum {
    from_begin,
    from_end,
    from_current
};

typedef sequence toldt_implements;
typedef base::base toldt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: toldt
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = toldt_implements, class TExtends = toldt_extends>

class _EXPORT_CLASS toldt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef toldt Derives;

    typedef typename TImplements::what_t what_t;
    typedef typename TImplements::sized_t sized_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    toldt(const toldt& copy): tell_(0) {
    }
    toldt(): tell_(0) {
    }
    virtual ~toldt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t reset() {
        ssize_t told = tell_;
        tell_ = 0;
        return told;
    }
    virtual ssize_t seek(size_t to, int whence) {
        size_t length = this->length();
        if (from_end == (whence)) {
            if (length < (to)) {
                to = 0;
            } else {
                to = length - to;
            }
        } else {
            if (from_current == (whence)) {
                if (length < (to += tell_)) {
                    to = length;
                }
            } else {
                if (length < (to)) {
                    to = length;
                }
            }
        }
        tell_ = to;
        return tell_;
    }
    virtual ssize_t tell() const {
        return tell_;
    }
    virtual size_t length() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    size_t tell_;
}; /// class _EXPORT_CLASS toldt

typedef toldt<> told;
typedef toldt<byte_sequence> byte_told;
typedef toldt<char_sequence> char_told;
typedef toldt<wchar_sequence> wchar_told;
typedef toldt<tchar_sequence> tchar_told;

} /// namespace io
} /// namespace xos

#endif /// ndef _XOS_NADIR_XOS_IO_TOLD_HPP
