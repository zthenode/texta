///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
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
///   File: sockets.hpp
///
/// Author: $author$
///   Date: 6/4/2017
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_XOS_BASE_SOCKETS_HPP
#define _MEDUSA_XOS_BASE_SOCKETS_HPP

#include "medusa/xos/base/base.hpp"
#include "xos/io/socket/tcp/reader.hpp"
#include "xos/io/socket/tcp/writer.hpp"

namespace medusa {

namespace io {
namespace socket {

namespace tcp {

typedef xos::io::socket::tcp::reader reader;
typedef xos::io::socket::tcp::writer writer;

} // namespace tcp

} // namespace socket 
} // namespace io 

} // namespace medusa 

#endif // _MEDUSA_XOS_BASE_SOCKETS_HPP 
