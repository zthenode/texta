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
///   File: logger.hpp
///
/// Author: $author$
///   Date: 6/3/2017
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_XOS_BASE_LOGGER_HPP
#define _MEDUSA_XOS_BASE_LOGGER_HPP

#include "medusa/xos/base/base.hpp"
#include "xos/io/logger.hpp"

#define MEDUSA_LOG_ANY XOS_LOG_ANY
#define MEDUSA_LOG_FATAL XOS_LOG_FATAL
#define MEDUSA_LOG_ERROR XOS_LOG_ERROR
#define MEDUSA_LOG_WARN XOS_LOG_WARN
#define MEDUSA_LOG_INFO XOS_LOG_INFO
#define MEDUSA_LOG_DEBUG XOS_LOG_DEBUG
#define MEDUSA_LOG_TRACE XOS_LOG_TRACE

#define MEDUSA_LOG_MESSAGE_ANY XOS_LOG_MESSAGE_ANY
#define MEDUSA_LOG_MESSAGE_FATAL XOS_LOG_MESSAGE_FATAL
#define MEDUSA_LOG_MESSAGE_ERROR XOS_LOG_MESSAGE_ERROR
#define MEDUSA_LOG_MESSAGE_WARN XOS_LOG_MESSAGE_WARN
#define MEDUSA_LOG_MESSAGE_INFO XOS_LOG_MESSAGE_INFO
#define MEDUSA_LOG_MESSAGE_DEBUG XOS_LOG_MESSAGE_DEBUG
#define MEDUSA_LOG_MESSAGE_TRACE XOS_LOG_MESSAGE_TRACE

namespace medusa {
namespace io {

typedef xos::io::logger logger_t;

} // namespace io
} // namespace medusa 

#endif // _MEDUSA_XOS_BASE_LOGGER_HPP 
