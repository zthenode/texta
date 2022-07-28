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
///   File: processor_instance.hpp
///
/// Author: $author$
///   Date: 2/19/2016
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_SERVER_DAEMON_PROCESSOR_INSTANCE_HPP
#define _MEDUSA_INET_XTTP_SERVER_DAEMON_PROCESSOR_INSTANCE_HPP

#include "medusa/inet/xttp/server/daemon/processor.hpp"

namespace medusa {
namespace inet {
namespace xttp {
namespace server {
namespace daemon {

processor& the_processor();

} // namespace daemon
} // namespace server 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_SERVER_DAEMON_PROCESSOR_INSTANCE_HPP 
