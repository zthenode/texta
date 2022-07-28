///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   File: buffer.hpp
///
/// Author: $author$
///   Date: 4/4/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_BUFFER_HPP
#define _XOS_NADIR_XOS_IO_BUFFER_HPP

#include "xos/io/seeker.hpp"
#include "xos/io/teller.hpp"
#include "xos/io/whence.hpp"

namespace xos {
namespace io {

typedef seeker buffer_implements;
typedef base::base buffer_extends;
///////////////////////////////////////////////////////////////////////
///  Class: buffert
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = void, typename TSized = char,
 class TImplements = buffer_implements, class TExtends = buffer_extends>
class _EXPORT_CLASS buffert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TWhat what_t;
    typedef TSized sized_t;
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    buffert(ssize_t length = -1, size_t tell = 0)
    : length_(length), tell_(tell) {
    }
    virtual ~buffert() {
    }
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t copy(what_t* to, const what_t* from, size_t size) {
        const sized_t* sized_from = (const sized_t*)from;
        sized_t* sized_to = (sized_t*)to;
        if ((sized_to) && (sized_from) && (size)) {
            for (; size; --size, ++to, ++from) {
                *to = *from;
            }
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_length(ssize_t to) {
        length_ = to;
        return length_;
    }
    virtual ssize_t length() const {
        return length_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t set_tell(size_t to) {
        tell_ = to;
        return tell_;
    }
    virtual size_t tell() const {
        return tell_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    ssize_t length_;
    size_t tell_;
};
typedef buffert<> buffer;

} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_BUFFER_HPP 
