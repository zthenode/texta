///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2014 $organization$
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
///   File: platform.hpp
///
/// Author: $author$
///   Date: 8/12/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_PLATFORM_HPP
#define _XOS_NADIR_XOS_BASE_PLATFORM_HPP

#include "xos/base/platform_build.hpp"
#include "xos/base/platform_compiler.hpp"
#include "xos/base/platform_includes.hpp"
#include "xos/base/platform_defines.hpp"
#include "xos/base/platform_types.hpp"
#include "xos/base/platform_api.hpp"

#if defined(WINDOWS)
#include "xos/base/platform_windows.hpp"
#else // defined(WINDOWS)
#endif // defined(WINDOWS)

namespace xos {
namespace base {

} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_PLATFORM_HPP 
