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
///   Date: 1/6/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_MAIN_IN_READER_HPP
#define _XOS_NADIR_XOS_IO_MAIN_IN_READER_HPP

#include "xos/io/reader.hpp"
#include "xos/base/main.hpp"

namespace xos {
namespace io {
namespace main {
namespace in {

typedef base::base reader_extends;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = void, typename TSized = char,
 typename TEnd = int, TEnd VEnd = 0,
 class TMain = base::maint<TSized, TEnd, VEnd>,
 class TImplements = io::readert<TWhat, TSized, TEnd, VEnd>,
 class TExtends = reader_extends>

class _EXPORT_CLASS readert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TMain main_t;
    typedef TWhat what_t;
    typedef TSized sized_t;
    typedef TSized char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    readert(main_t& main): main_(main) {
    }
    virtual ~readert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read(what_t* what, size_t size) {
        sized_t* chars = 0;
        if ((chars = ((sized_t*)what))) {
            return main_.in(chars, size);
        }
        return 0;
    }
    virtual ssize_t fill() {
        return main_.in_fill();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    main_t& main_;
};
typedef readert<> reader;

} // namespace in 
} // namespace main 
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_MAIN_IN_READER_HPP 
