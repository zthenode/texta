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
///   File: seeker.hpp
///
/// Author: $author$
///   Date: 4/4/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_SEEKER_HPP
#define _XOS_NADIR_XOS_IO_SEEKER_HPP

#include "xos/io/teller.hpp"
#include "xos/io/whencer.hpp"
#include "xos/io/whence.hpp"

namespace xos {
namespace io {

typedef whencert<teller> seeker_implements;
///////////////////////////////////////////////////////////////////////
///  Class: seekert
///////////////////////////////////////////////////////////////////////
template
<class TImplements = seeker_implements, typename TWhence = whence_t>
class _EXPORT_CLASS seekert: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TWhence whence_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t seek(ssize_t offset, whence_t whence) {
        return -1;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef seekert<> seeker;

} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_SEEKER_HPP 
