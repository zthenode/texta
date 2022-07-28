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
///   File: writer.hpp
///
/// Author: $author$
///   Date: 1/25/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_ECHOED_WRITER_HPP
#define _XOS_NADIR_XOS_IO_ECHOED_WRITER_HPP

#include "xos/io/writer.hpp"

namespace xos {
namespace io {
namespace echoed {

typedef base::base writer_extends;
///////////////////////////////////////////////////////////////////////
///  Class: writert
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = void, typename TSized = char,
 typename TEnd = int, TEnd VEnd = 0,
 class TWriter = io::writert<TWhat, TSized, TEnd, VEnd>,
 class TImplements = TWriter, class TExtends = writer_extends>

class _EXPORT_CLASS writert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TWriter writer_t;
    typedef TWhat what_t;
    typedef TSized sized_t;
    typedef TSized char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    writert(writer_t& written, writer_t& echoed)
    : written_(written), echoed_(echoed) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t write(const what_t* what, ssize_t size = -1) {
        ssize_t count = written_.write(what, size);
        echoed_.write(what, size);
        return count;
    }
    virtual ssize_t flush() {
        ssize_t count = written_.flush();
        echoed_.flush();
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    writer_t &written_, &echoed_;
};
typedef writert<> writer;

} // namespace echoed
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_ECHOED_WRITER_HPP
