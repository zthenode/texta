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
///   File: logger.hpp
///
/// Author: $author$
///   Date: 4/8/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_IO_LOGGER_HPP
#define _CORAL_IO_LOGGER_HPP

#if !defined(NO_USE_NADIR_BASE)
#include "coral/nadir/io/logger.hpp"
#else /// !defined(NO_USE_NADIR_BASE)
#include "coral/base/base.hpp"
#include "xos/io/logger.hpp"

#define CORAL_LOG_ANY XOS_LOG_ANY
#define CORAL_LOG_FATAL XOS_LOG_FATAL
#define CORAL_LOG_ERROR XOS_LOG_ERROR
#define CORAL_LOG_WARN XOS_LOG_WARN
#define CORAL_LOG_INFO XOS_LOG_INFO
#define CORAL_LOG_DEBUG XOS_LOG_DEBUG
#define CORAL_LOG_TRACE XOS_LOG_TRACE

#define CORAL_LOG_ANYF XOS_LOG_ANYF
#define CORAL_LOG_FATALF XOS_LOG_FATALF
#define CORAL_LOG_ERRORF XOS_LOG_ERRORF
#define CORAL_LOG_WARNF XOS_LOG_WARNF
#define CORAL_LOG_INFOF XOS_LOG_INFOF
#define CORAL_LOG_DEBUGF XOS_LOG_DEBUGF
#define CORAL_LOG_TRACEF XOS_LOG_TRACEF

#define CORAL_LOG_MESSAGE_ANY XOS_LOG_MESSAGE_ANY
#define CORAL_LOG_MESSAGE_FATAL XOS_LOG_MESSAGE_FATAL
#define CORAL_LOG_MESSAGE_ERROR XOS_LOG_MESSAGE_ERROR
#define CORAL_LOG_MESSAGE_WARN XOS_LOG_MESSAGE_WARN
#define CORAL_LOG_MESSAGE_INFO XOS_LOG_MESSAGE_INFO
#define CORAL_LOG_MESSAGE_DEBUG XOS_LOG_MESSAGE_DEBUG
#define CORAL_LOG_MESSAGE_TRACE XOS_LOG_MESSAGE_TRACE

#define CORAL_LOG_MESSAGE_ANYF XOS_LOG_MESSAGE_ANYF
#define CORAL_LOG_MESSAGE_FATALF XOS_LOG_MESSAGE_FATALF
#define CORAL_LOG_MESSAGE_ERRORF XOS_LOG_MESSAGE_ERRORF
#define CORAL_LOG_MESSAGE_WARNF XOS_LOG_MESSAGE_WARNF
#define CORAL_LOG_MESSAGE_INFOF XOS_LOG_MESSAGE_INFOF
#define CORAL_LOG_MESSAGE_DEBUGF XOS_LOG_MESSAGE_DEBUGF
#define CORAL_LOG_MESSAGE_TRACEF XOS_LOG_MESSAGE_TRACEF

namespace coral {
namespace io {

} // namespace io 
} // namespace coral 

#endif // _CORAL_IO_LOGGER_HPP 
#endif /// !defined(NO_USE_NADIR_BASE)
