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
///   File: attached.hpp
///
/// Author: $author$
///   Date: 11/9/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_FILE_ATTACHED_HPP
#define _XOS_NADIR_XOS_IO_FILE_ATTACHED_HPP

#include "xos/io/file/attacher.hpp"
#include "xos/base/attached.hpp"

namespace xos {
namespace io {
namespace file {

typedef base::attachedt
<attached_t, unattached_t, unattached, attacher> attached;

} // namespace file 
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_FILE_ATTACHED_HPP 
