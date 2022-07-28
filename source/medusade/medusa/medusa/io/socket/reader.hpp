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
#ifndef _MEDUSA_IO_SOCKET_READER_HPP
#define _MEDUSA_IO_SOCKET_READER_HPP

#include "medusa/network/sockets.hpp"
#include "xos/io/socket/tcp/reader.hpp"

namespace medusa {
namespace io {
namespace socket {
namespace tcp {

typedef xos::io::socket::tcp::reader reader;

} // namespace tcp
} // namespace socket
} // namespace io 
} // namespace medusa 

#endif // _MEDUSA_IO_SOCKET_READER_HPP 
