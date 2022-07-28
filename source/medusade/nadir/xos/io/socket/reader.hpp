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
///   Date: 2/16/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_SOCKET_READER_HPP
#define _XOS_NADIR_XOS_IO_SOCKET_READER_HPP

#include "xos/io/reader.hpp"
#include "xos/network/socket.hpp"

namespace xos {
namespace io {
namespace socket {

typedef io::reader reader_implements;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<class TImplements = reader_implements>
class _EXPORT_CLASS readert: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef typename TImplements::what_t what_t;
    typedef typename TImplements::sized_t sized_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read(what_t* what, size_t size) {
        size_t count = 0;
        if ((what) && (size)) {
            count = recv(what, size);
        }
        return count;
    }
    virtual ssize_t recv(what_t* what, size_t size) {
        size_t count = 0;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef readert<> reader;

} // namespace socket
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_SOCKET_READER_HPP 
