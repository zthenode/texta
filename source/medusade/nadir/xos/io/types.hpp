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
///   File: types.hpp
///
/// Author: $author$
///   Date: 1/11/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_TYPES_HPP
#define _XOS_NADIR_XOS_IO_TYPES_HPP

#include "xos/io/stream.hpp"
#include "xos/base/types.hpp"

namespace xos {
namespace io {
namespace types {

typedef base::base reader_extends;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = void, typename TSized = char,
 typename TEnd = int, TEnd VEnd = 0,
 class TTypes = base::typest<TSized, TEnd, VEnd>,
 class TImplements = io::readert<TWhat, TSized, TEnd, VEnd>,
 class TExtends = reader_extends>

class _EXPORT_CLASS readert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TTypes types_t;
    typedef TWhat what_t;
    typedef TSized sized_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    readert
    (const what_t* what, size_t length)
    : what_(what), length_(length), tell_(0) {
    }
    virtual ~readert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read(what_t* what, size_t size) {
        sized_t* sized = 0;
        if (length_ < (tell_ + size)) {
            size = length_ - tell_;
        }
        if ((sized = ((sized_t*)what)) && (size)) {
            types_t::copy(sized, ((const sized_t*)what_)+tell_, size);
            tell_ += size;
            return size;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const what_t* what_;
    size_t length_, tell_;
};
typedef readert<> reader;

} // namespace types 

namespace chars {
typedef types::readert<void, char_t> reader;
} // namespace chars
namespace wchars {
typedef types::readert<void, wchar_t> reader;
} // namespace wchars
namespace tchars {
typedef types::readert<void, tchar_t> reader;
} // namespace tchars

} // namespace io
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_TYPES_HPP 
