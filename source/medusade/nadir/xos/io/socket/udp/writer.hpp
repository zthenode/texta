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
///   File: writer.hpp
///
/// Author: $author$
///   Date: 2/16/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_SOCKET_UDP_WRITER_HPP
#define _XOS_NADIR_XOS_IO_SOCKET_UDP_WRITER_HPP

#include "xos/io/socket/writer.hpp"

namespace xos {
namespace io {
namespace socket {
namespace udp {

typedef io::socket::writer writer_implements;
typedef base::base writer_extends;
///////////////////////////////////////////////////////////////////////
///  Class: writert
///////////////////////////////////////////////////////////////////////
template
<class TImplements = writer_implements, class TExtends = writer_extends>
class _EXPORT_CLASS writert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename TImplements::what_t what_t;
    typedef typename TImplements::sized_t sized_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    writert(network::socket& sk, network::endpoint& ep)
    : sk_(sk), ep_(ep) {
    }
    virtual ~writert() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t send(const what_t* what, size_t size) {
        ssize_t count = sk_.sendto(what, size, 0, ep_);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    network::socket& sk_;
    network::endpoint& ep_;
};
typedef writert<> writer;

} // namespace udp
} // namespace socket 
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_SOCKET_UDP_WRITER_HPP 
