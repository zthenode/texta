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
///   File: output.hpp
///
/// Author: $author$
///   Date: 10/20/2017, 6/13/2021
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_LOGGER_OUTPUT_HPP
#define _XOS_NADIR_LOGGER_OUTPUT_HPP

#include "xos/logger/message.hpp"

namespace xos {
namespace logger {

} // namespace logger 
} // namespace xos 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_COSTREAM_LOG_PLAIN(ostream_, message_) \
{ ::xos::logger::message message; \
  ostream_ << message << message_ << "\n"; }

#define XOS_COSTREAM_LOG_FUNCTION(ostream_, message_) \
{ ::xos::logger::message message; \
  ostream_ << XOS_LOGGER_FUNCTION << ": " << message << message_ << "\n"; }

#define XOS_COSTREAM_LOG_LOCATION(ostream_, message_) \
{ ::xos::logger::location location = XOS_LOGGER_LOCATION; \
  ::xos::logger::message message; \
  ostream_ <<  location.file_name().chars() << "[" <<  location.line_number().chars() << "] " \
  <<  location.function_name().chars() << ": " << message << message_ << "\n"; }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_STDSTREAM_LOG_PLAIN(stream_, message_) \
{ ::xos::logger::message message; message << message_; \
  fprintf(stream_, "%s\n", message.chars()); }

#define XOS_STDSTREAM_LOG_FUNCTION(stream_, message_) \
{ ::xos::logger::function function = XOS_LOGGER_FUNCTION; \
  ::xos::logger::message message; message << message_; \
  fprintf(stream_, "%s: %s\n", function.chars(), message.chars()); }

#define XOS_STDSTREAM_LOG_LOCATION(stream_, message_) \
{ ::xos::logger::location location = XOS_LOGGER_LOCATION; \
  ::xos::logger::message message; message << message_; \
  fprintf(stream_, "%s[%s] %s: %s\n", location.file_name().chars(), \
  location.line_number().chars(), location.function_name().chars(), message.chars()); }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_CERR_LOG_PLAIN(message_) XOS_COSTREAM_LOG_PLAIN(::std::cerr, message_)
#define XOS_STDERR_LOG_PLAIN(message_) XOS_STDSTREAM_LOG_PLAIN(stderr, message_)
#define XOS_CERR_LOG_FUNCTION(message_) XOS_COSTREAM_LOG_FUNCTION(::std::cerr, message_)
#define XOS_STDERR_LOG_FUNCTION(message_) XOS_STDSTREAM_LOG_FUNCTION(stderr, message_)
#define XOS_CERR_LOG_LOCATION(message_) XOS_COSTREAM_LOG_LOCATION(::std::cerr, message_)
#define XOS_STDERR_LOG_LOCATION(message_) XOS_STDSTREAM_LOG_LOCATION(stderr, message_)

#if defined(XOS_PLAIN_LOGGING)
#define XOS_CERR_LOG XOS_CERR_LOG_PLAIN
#define XOS_STDERR_LOG XOS_STDERR_LOG_PLAIN
#else // defined(XOS_PLAIN_LOGGING)
#if defined(XOS_FUNCTION_LOGGING)
#define XOS_CERR_LOG XOS_CERR_LOG_FUNCTION
#define XOS_STDERR_LOG XOS_STDERR_LOG_FUNCTION
#else // defined(XOS_FUNCTION_LOGGING)
#define XOS_CERR_LOG XOS_CERR_LOG_LOCATION
#define XOS_STDERR_LOG XOS_STDERR_LOG_LOCATION
#endif // defined(XOS_FUNCTION_LOGGING)
#endif // defined(XOS_PLAIN_LOGGING)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(XOS_DEFAULT_LOG_ERROR)
#if defined(DEFAULT_LOG_ERROR) || defined(DEFAULT_LOGGING_LEVELS_ERROR)
#define XOS_DEFAULT_LOG_ERROR
#endif /// defined(DEFAULT_LOG_ERROR) || defined(DEFAULT_LOGGING_LEVELS_ERROR)
#endif /// !defined(XOS_DEFAULT_LOG_ERROR)

#if !defined(XOS_DEFAULT_LOG_DEBUG)
#if defined(DEFAULT_LOG_DEBUG) || defined(DEFAULT_LOGGING_LEVELS_DEBUG)
#define XOS_DEFAULT_LOG_DEBUG
#endif /// defined(DEFAULT_LOG_DEBUG) || defined(DEFAULT_LOGGING_LEVELS_DEBUG)
#endif /// !defined(XOS_DEFAULT_LOG_DEBUG)

#if !defined(XOS_DEFAULT_LOG_TRACE)
#if defined(DEFAULT_LOG_TRACE) || defined(DEFAULT_LOGGING_LEVELS_TRACE)
#define XOS_DEFAULT_LOG_TRACE
#endif /// defined(DEFAULT_LOG_TRACE) || defined(DEFAULT_LOGGING_LEVELS_TRACE)
#endif /// !defined(XOS_DEFAULT_LOG_TRACE)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(XOS_NO_ERR_LOG_TRACE)
#if defined(XOS_DEFAULT_LOG_NONE) || defined(XOS_DEFAULT_LOG_DEBUG) || defined(XOS_DEFAULT_LOG_ERROR)
#define XOS_NO_ERR_LOG_TRACE
#endif // defined(XOS_DEFAULT_LOG_NONE) || defined(XOS_DEFAULT_LOG_DEBUG) || defined(XOS_DEFAULT_LOG_ERROR)
#endif // !defined(XOS_NO_ERR_LOG_TRACE)

#if !defined(XOS_NO_ERR_LOG_DEBUG)
#if defined(XOS_DEFAULT_LOG_NONE) || defined(XOS_DEFAULT_LOG_ERROR)
#define XOS_NO_ERR_LOG_DEBUG
#endif // defined(XOS_DEFAULT_LOG_NONE) || defined(XOS_DEFAULT_LOG_ERROR)
#endif // !defined(XOS_NO_ERR_LOG_DEBUG)

#if !defined(XOS_NO_ERR_LOG_ERROR)
#if defined(XOS_DEFAULT_LOG_NONE)
#define XOS_NO_ERR_LOG_ERROR
#endif // defined(XOS_DEFAULT_LOG_NONE)
#endif // !defined(XOS_NO_ERR_LOG_ERROR)

#if defined(TRACE_BUILD) && !defined(XOS_NO_ERR_LOG_TRACE)
#define XOS_CERR_LOG_TRACE(message_) XOS_CERR_LOG(message_)
#define XOS_STDERR_LOG_TRACE(message_) XOS_STDERR_LOG(message_)
#define XOS_CERR_LOG_PLAIN_TRACE(message_) XOS_CERR_LOG_PLAIN(message_)
#define XOS_STDERR_LOG_PLAIN_TRACE(message_) XOS_STDERR_LOG_PLAIN(message_)
#define XOS_CERR_LOG_FUNCTION_TRACE(message_) XOS_CERR_LOG_FUNCTION(message_)
#define XOS_STDERR_LOG_FUNCTION_TRACE(message_) XOS_STDERR_LOG_FUNCTION(message_)
#define XOS_CERR_LOG_LOCATION_TRACE(message_) XOS_CERR_LOG_LOCATION(message_)
#define XOS_STDERR_LOG_LOCATION_TRACE(message_) XOS_STDERR_LOG_LOCATION(message_)
#else // defined(TRACE_BUILD) && !defined(XOS_NO_ERR_LOG_TRACE)
#define XOS_CERR_LOG_TRACE(message_)
#define XOS_STDERR_LOG_TRACE(message_)
#define XOS_CERR_LOG_PLAIN_TRACE(message_)
#define XOS_STDERR_LOG_PLAIN_TRACE(message_)
#define XOS_CERR_LOG_FUNCTION_TRACE(message_)
#define XOS_STDERR_LOG_FUNCTION_TRACE(message_)
#define XOS_CERR_LOG_LOCATION_TRACE(message_)
#define XOS_STDERR_LOG_LOCATION_TRACE(message_)
#endif // defined(TRACE_BUILD) && !defined(XOS_NO_ERR_LOG_TRACE)

#if defined(DEBUG_BUILD) && !defined(XOS_NO_ERR_LOG_DEBUG)
#define XOS_CERR_LOG_DEBUG(message_) XOS_CERR_LOG(message_)
#define XOS_STDERR_LOG_DEBUG(message_) XOS_STDERR_LOG(message_)
#define XOS_CERR_LOG_PLAIN_DEBUG(message_) XOS_CERR_LOG_PLAIN(message_)
#define XOS_STDERR_LOG_PLAIN_DEBUG(message_) XOS_STDERR_LOG_PLAIN(message_)
#define XOS_CERR_LOG_FUNCTION_DEBUG(message_) XOS_CERR_LOG_FUNCTION(message_)
#define XOS_STDERR_LOG_FUNCTION_DEBUG(message_) XOS_STDERR_LOG_FUNCTION(message_)
#define XOS_CERR_LOG_LOCATION_DEBUG(message_) XOS_CERR_LOG_LOCATION(message_)
#define XOS_STDERR_LOG_LOCATION_DEBUG(message_) XOS_STDERR_LOG_LOCATION(message_)
#else // defined(DEBUG_BUILD) && !defined(XOS_NO_ERR_LOG_DEBUG)
#define XOS_CERR_LOG_DEBUG(message_)
#define XOS_STDERR_LOG_DEBUG(message_)
#define XOS_CERR_LOG_PLAIN_DEBUG(message_)
#define XOS_STDERR_LOG_PLAIN_DEBUG(message_)
#define XOS_CERR_LOG_FUNCTION_DEBUG(message_)
#define XOS_STDERR_LOG_FUNCTION_DEBUG(message_)
#define XOS_CERR_LOG_LOCATION_DEBUG(message_)
#define XOS_STDERR_LOG_LOCATION_DEBUG(message_)
#endif // defined(DEBUG_BUILD) && !defined(XOS_NO_ERR_LOG_DEBUG)

#if !defined(XOS_NO_ERR_LOG_ERROR)
#define XOS_CERR_LOG_ERROR(message_) XOS_CERR_LOG(message_)
#define XOS_STDERR_LOG_ERROR(message_) XOS_STDERR_LOG(message_)
#define XOS_CERR_LOG_PLAIN_ERROR(message_) XOS_CERR_LOG_PLAIN(message_)
#define XOS_STDERR_LOG_PLAIN_ERROR(message_) XOS_STDERR_LOG_PLAIN(message_)
#define XOS_CERR_LOG_FUNCTION_ERROR(message_) XOS_CERR_LOG_FUNCTION(message_)
#define XOS_STDERR_LOG_FUNCTION_ERROR(message_) XOS_STDERR_LOG_FUNCTION(message_)
#define XOS_CERR_LOG_LOCATION_ERROR(message_) XOS_CERR_LOG_LOCATION(message_)
#define XOS_STDERR_LOG_LOCATION_ERROR(message_) XOS_STDERR_LOG_LOCATION(message_)
#else // !defined(XOS_NO_ERR_LOG_ERROR)
#define XOS_CERR_LOG_ERROR(message_)
#define XOS_STDERR_LOG_ERROR(message_)
#define XOS_CERR_LOG_PLAIN_ERROR(message_)
#define XOS_STDERR_LOG_PLAIN_ERROR(message_)
#define XOS_CERR_LOG_FUNCTION_ERROR(message_)
#define XOS_STDERR_LOG_FUNCTION_ERROR(message_)
#define XOS_CERR_LOG_LOCATION_ERROR(message_)
#define XOS_STDERR_LOG_LOCATION_ERROR(message_)
#endif // !defined(XOS_NO_ERR_LOG_ERROR)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if defined(XOS_CERR_LOGGING)
#define XOS_ERR_LOG(message_) XOS_CERR_LOG(message_)
#define XOS_ERR_LOG_TRACE(message_) XOS_CERR_LOG_TRACE(message_)
#define XOS_ERR_LOG_FUNCTION_TRACE(message_) XOS_CERR_LOG_FUNCTION_TRACE(message_)
#define XOS_ERR_LOG_LOCATION_TRACE(message_) XOS_CERR_LOG_LOCATION_TRACE(message_)
#define XOS_ERR_LOG_DEBUG(message_) XOS_CERR_LOG_DEBUG(message_)
#define XOS_ERR_LOG_FUNCTION_DEBUG(message_) XOS_CERR_LOG_FUNCTION_DEBUG(message_)
#define XOS_ERR_LOG_LOCATION_DEBUG(message_) XOS_CERR_LOG_LOCATION_DEBUG(message_)
#define XOS_ERR_LOG_ERROR(message_) XOS_CERR_LOG_ERROR(message_)
#define XOS_ERR_LOG_FUNCTION_ERROR(message_) XOS_CERR_LOG_FUNCTION_ERROR(message_)
#define XOS_ERR_LOG_LOCATION_ERROR(message_) XOS_CERR_LOG_LOCATION_ERROR(message_)
#else // defined(XOS_CERR_LOGGING)
#define XOS_ERR_LOG(message_) XOS_STDERR_LOG(message_)
#define XOS_ERR_LOG_TRACE(message_) XOS_STDERR_LOG_TRACE(message_)
#define XOS_ERR_LOG_FUNCTION_TRACE(message_) XOS_STDERR_LOG_FUNCTION_TRACE(message_)
#define XOS_ERR_LOG_LOCATION_TRACE(message_) XOS_STDERR_LOG_LOCATION_TRACE(message_)
#define XOS_ERR_LOG_DEBUG(message_) XOS_STDERR_LOG_DEBUG(message_)
#define XOS_ERR_LOG_FUNCTION_DEBUG(message_) XOS_STDERR_LOG_FUNCTION_DEBUG(message_)
#define XOS_ERR_LOG_LOCATION_DEBUG(message_) XOS_STDERR_LOG_LOCATION_DEBUG(message_)
#define XOS_ERR_LOG_ERROR(message_) XOS_STDERR_LOG_ERROR(message_)
#define XOS_ERR_LOG_FUNCTION_ERROR(message_) XOS_STDERR_LOG_FUNCTION_ERROR(message_)
#define XOS_ERR_LOG_LOCATION_ERROR(message_) XOS_STDERR_LOG_LOCATION_ERROR(message_)
#endif // defined(XOS_CERR_LOGGING)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_STDERR_LOG_LOCATION_FATAL XOS_STDERR_LOG_LOCATION_ERROR
#define XOS_STDERR_LOG_LOCATION_WARN XOS_STDERR_LOG_LOCATION_DEBUG
#define XOS_STDERR_LOG_LOCATION_INFO XOS_STDERR_LOG_LOCATION_DEBUG

#define XOS_STDERR_LOG_FUNCTION_FATAL XOS_STDERR_LOG_FUNCTION_ERROR
#define XOS_STDERR_LOG_FUNCTION_WARN XOS_STDERR_LOG_FUNCTION_DEBUG
#define XOS_STDERR_LOG_FUNCTION_INFO XOS_STDERR_LOG_FUNCTION_DEBUG

#define XOS_STDERR_LOG_PLAIN_FATAL XOS_STDERR_LOG_PLAIN_ERROR
#define XOS_STDERR_LOG_PLAIN_WARN XOS_STDERR_LOG_PLAIN_DEBUG
#define XOS_STDERR_LOG_PLAIN_INFO XOS_STDERR_LOG_PLAIN_DEBUG

#define XOS_STDERR_LOG_FATAL XOS_STDERR_LOG_ERROR
#define XOS_STDERR_LOG_WARN XOS_STDERR_LOG_DEBUG
#define XOS_STDERR_LOG_INFO XOS_STDERR_LOG_DEBUG

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_CERR_LOG_LOCATION_FATAL XOS_CERR_LOG_LOCATION_ERROR
#define XOS_CERR_LOG_LOCATION_WARN XOS_CERR_LOG_LOCATION_DEBUG
#define XOS_CERR_LOG_LOCATION_INFO XOS_CERR_LOG_LOCATION_DEBUG

#define XOS_CERR_LOG_FUNCTION_FATAL XOS_CERR_LOG_FUNCTION_ERROR
#define XOS_CERR_LOG_FUNCTION_WARN XOS_CERR_LOG_FUNCTION_DEBUG
#define XOS_CERR_LOG_FUNCTION_INFO XOS_CERR_LOG_FUNCTION_DEBUG

#define XOS_CERR_LOG_PLAIN_FATAL XOS_CERR_LOG_PLAIN_ERROR
#define XOS_CERR_LOG_PLAIN_WARN XOS_CERR_LOG_PLAIN_DEBUG
#define XOS_CERR_LOG_PLAIN_INFO XOS_CERR_LOG_PLAIN_DEBUG

#define XOS_CERR_LOG_FATAL XOS_CERR_LOG_ERROR
#define XOS_CERR_LOG_WARN XOS_CERR_LOG_DEBUG
#define XOS_CERR_LOG_INFO XOS_CERR_LOG_DEBUG

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_ERR_LOG_LOCATION_FATAL XOS_ERR_LOG_LOCATION_ERROR
#define XOS_ERR_LOG_LOCATION_WARN XOS_ERR_LOG_LOCATION_DEBUG
#define XOS_ERR_LOG_LOCATION_INFO XOS_ERR_LOG_LOCATION_DEBUG

#define XOS_ERR_LOG_FUNCTION_FATAL XOS_ERR_LOG_FUNCTION_ERROR
#define XOS_ERR_LOG_FUNCTION_WARN XOS_ERR_LOG_FUNCTION_DEBUG
#define XOS_ERR_LOG_FUNCTION_INFO XOS_ERR_LOG_FUNCTION_DEBUG

#define XOS_ERR_LOG_PLAIN_FATAL XOS_ERR_LOG_PLAIN_ERROR
#define XOS_ERR_LOG_PLAIN_WARN XOS_ERR_LOG_PLAIN_DEBUG
#define XOS_ERR_LOG_PLAIN_INFO XOS_ERR_LOG_PLAIN_DEBUG

#define XOS_ERR_LOG_FATAL XOS_ERR_LOG_ERROR
#define XOS_ERR_LOG_WARN XOS_ERR_LOG_DEBUG
#define XOS_ERR_LOG_INFO XOS_ERR_LOG_DEBUG

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#endif // _XOS_NADIR_LOGGER_OUTPUT_HPP 
