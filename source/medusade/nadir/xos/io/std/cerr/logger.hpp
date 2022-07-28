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
///   File: logger.hpp
///
/// Author: $author$
///   Date: 9/11/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_STD_CERR_LOGGER_HPP
#define _XOS_NADIR_XOS_IO_STD_CERR_LOGGER_HPP

#include "xos/io/logger.hpp"
#include <iostream>

#if !defined(XOS_STD_CERR_LOG_ERROR)
#define XOS_STD_CERR_LOG_ERROR(args) \
    ::std::cerr << __FUNCTION__ << ": " << args << "\n"
#endif // !defined(XOS_STD_CERR_LOG_ERROR)

namespace xos {
namespace io {
namespace std {
namespace cerr {

} // namespace cerr 
} // namespace std 
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_STD_CERR_LOGGER_HPP 
