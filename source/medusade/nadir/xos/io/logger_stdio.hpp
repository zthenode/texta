///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   File: logger_stdio.hpp
///
/// Author: $author$
///   Date: 1/8/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_LOGGER_STDIO_HPP
#define _XOS_NADIR_XOS_IO_LOGGER_STDIO_HPP

#include "xos/base/base.hpp"
#include <iostream>

namespace xos {
namespace io {

} // namespace io 
} // namespace xos 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(XOS_STD_CERR_LOG_LOCATION)
#define XOS_STD_CERR_LOG_LOCATION(__message__) \
    ::std::cerr << __FILE__ << "[" << __LINE__ << "] " << __FUNCTION__ << " " << __message__ << "\n"
#endif // !defined(XOS_STD_CERR_LOG_LOCATION)

#if !defined(XOS_STD_CERR_LOG_FUNCTION)
#define XOS_STD_CERR_LOG_FUNCTION(__message__) \
    ::std::cerr << __FUNCTION__ << " " << __message__ << "\n"
#endif // !defined(XOS_STD_CERR_LOG_FUNCTION)

#if !defined(XOS_STD_CERR_LOG_PLAIN)
#define XOS_STD_CERR_LOG_PLAIN(__message__) \
    ::std::cerr << __message__ << "\n"
#endif // !defined(XOS_STD_CERR_LOG_PLAIN)

#if defined(XOS_STD_CERR_PLAIN_LOGGING)
// plain logging
#define XOS_STD_CERR_LOG XOS_STD_CERR_LOG_PLAIN
#else // defined(XOS_STD_CERR_PLAIN_LOGGING)
#if defined(XOS_STD_CERR_FUNCTION_LOGGING)
// function logging
#define XOS_STD_CERR_LOG XOS_STD_CERR_LOG_FUNCTION
#else // defined(XOS_STD_CERR_FUNCTION_LOGGING)
// location logging
#define XOS_STD_CERR_LOG XOS_STD_CERR_LOG_LOCATION
#endif // defined(XOS_STD_CERR_FUNCTION_LOGGING)
#endif // defined(XOS_STD_CERR_PLAIN_LOGGING)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(XOS_STD_CERR_LOG_TRACE)
#if defined(TRACE_BUILD)
#define XOS_STD_CERR_LOG_TRACE(__message__) XOS_STD_CERR_LOG(__message__)
#else // defined(TRACE_BUILD)
#define XOS_STD_CERR_LOG_TRACE(__message__)
#endif // defined(TRACE_BUILD)
#endif // !defined(XOS_STD_CERR_LOG_TRACE)

#if !defined(XOS_STD_CERR_LOG_DEBUG)
#if defined(DEBUG_BUILD)
#define XOS_STD_CERR_LOG_DEBUG(__message__) XOS_STD_CERR_LOG(__message__)
#else // defined(DEBUG_BUILD)
#define XOS_STD_CERR_LOG_DEBUG(__message__)
#endif // defined(DEBUG_BUILD)
#endif // !defined(XOS_STD_CERR_LOG_DEBUG)

#if !defined(XOS_STD_CERR_LOG_ERROR)
#define XOS_STD_CERR_LOG_ERROR(__message__) XOS_STD_CERR_LOG(__message__)
#endif // !defined(XOS_STD_CERR_LOG_ERROR)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(XOS_ERR_LOG_TRACE) || defined(NDEF_XOS_ERR_LOG)
#define XOS_ERR_LOG_TRACE(__message__) XOS_STD_CERR_LOG_TRACE(__message__)
#endif // !defined(XOS_LOG_TRACE) || defined(NDEF_XOS_ERR_LOG)

#if !defined(XOS_ERR_LOG_DEBUG) || defined(NDEF_XOS_ERR_LOG)
#define XOS_ERR_LOG_DEBUG(__message__) XOS_STD_CERR_LOG_DEBUG(__message__)
#endif // !defined(XOS_LOG_DEBUG) || defined(NDEF_XOS_ERR_LOG)

#if !defined(XOS_ERR_LOG_ERROR) || defined(NDEF_XOS_ERR_LOG)
#define XOS_ERR_LOG_ERROR(__message__) XOS_STD_CERR_LOG_ERROR(__message__)
#endif // !defined(XOS_LOG_ERROR) || defined(NDEF_XOS_ERR_LOG)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#endif // _XOS_NADIR_XOS_IO_LOGGER_STDIO_HPP 
