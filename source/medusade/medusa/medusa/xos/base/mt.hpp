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
///   File: mt.hpp
///
/// Author: $author$
///   Date: 6/4/2017
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_XOS_BASE_MT_HPP
#define _MEDUSA_XOS_BASE_MT_HPP

#include "medusa/xos/base/base.hpp"
#include "xos/mt/signaler.hpp"
#include "xos/mt/os/semaphore.hpp"
#include "xos/mt/os/mutex.hpp"
#include "xos/mt/lock.hpp"

namespace medusa {
namespace mt {

typedef xos::mt::signaler signaler;
typedef xos::mt::lock lock;

namespace os {

typedef xos::mt::os::mutex mutex;
typedef xos::mt::os::semaphore semaphore;

} // namespace os

} // namespace mt
} // namespace medusa 

#endif // _MEDUSA_XOS_BASE_MT_HPP 
