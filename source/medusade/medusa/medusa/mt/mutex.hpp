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
///   File: mutex.hpp
///
/// Author: $author$
///   Date: 12/27/2017
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_MT_MUTEX_HPP
#define _MEDUSA_MT_MUTEX_HPP

#include "medusa/base/base.hpp"
#include "xos/mt/os/mutex.hpp"
#include "xos/mt/lock.hpp"

namespace medusa {
namespace mt {

typedef xos::mt::locker_exception lock_exception;
typedef xos::mt::locker locked;
typedef xos::mt::lock lock;
typedef xos::mt::os::mutex mutex;

namespace os {
typedef xos::mt::os::mutex mutex;
} // namespace os

} // namespace mt 
} // namespace medusa 

#endif // _MEDUSA_MT_MUTEX_HPP 
