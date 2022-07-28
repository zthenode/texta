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
///   File: attacher.hpp
///
/// Author: $author$
///   Date: 9/7/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_FILE_ATTACHER_HPP
#define _XOS_NADIR_XOS_IO_FILE_ATTACHER_HPP

#include "xos/base/attacher.hpp"

namespace xos {
namespace io {
namespace file {

typedef FILE* attached_t;
typedef int unattached_t;
enum { unattached = 0 };

typedef base::attachert
<attached_t, unattached_t, unattached> attacher;

} // namespace file 
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_FILE_ATTACHER_HPP 
