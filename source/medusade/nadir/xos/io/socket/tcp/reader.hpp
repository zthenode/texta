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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 2/15/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_SOCKET_TCP_READER_HPP
#define _XOS_NADIR_XOS_IO_SOCKET_TCP_READER_HPP

#include "xos/io/socket/reader.hpp"

namespace xos {
namespace io {
namespace socket {
namespace tcp {

typedef io::socket::reader reader_implements;
typedef base::base reader_extends;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<class TImplements = reader_implements, class TExtends = reader_extends>
class _EXPORT_CLASS readert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename TImplements::what_t what_t;
    typedef typename TImplements::sized_t sized_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    readert(network::socket& sk): sk_(sk) {
    }
    virtual ~readert() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t recv(what_t* what, size_t size) {
        size_t count = sk_.recv(what, size, 0);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    network::socket& sk_;
};
typedef readert<> reader;

} // namespace tcp
} // namespace socket 
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_SOCKET_TCP_READER_HPP 
