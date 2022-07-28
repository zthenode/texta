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
///   File: semaphore.hpp
///
/// Author: $author$
///   Date: 12/27/2017
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_MT_SEMAPHORE_HPP
#define _MEDUSA_MT_SEMAPHORE_HPP

#include "medusa/base/base.hpp"
#include "xos/mt/os/semaphore.hpp"
#include "xos/mt/wait.hpp"

namespace medusa {
namespace mt {

typedef xos::mt::wait_status wait_status;
static const wait_status wait_success = xos::mt::wait_success;
static const wait_status wait_failed = xos::mt::wait_failed;
static const wait_status wait_busy = xos::mt::wait_busy;
static const wait_status wait_interrupted = xos::mt::wait_interrupted;
static const wait_status wait_invalid = xos::mt::wait_invalid;

typedef xos::mt::waiter waited;
typedef xos::mt::wait wait;
typedef xos::mt::os::semaphore semaphore;

namespace os {
typedef xos::mt::os::semaphore semaphore;
} // namespace os

} // namespace mt 
} // namespace medusa 

#endif // _MEDUSA_MT_SEMAPHORE_HPP 
