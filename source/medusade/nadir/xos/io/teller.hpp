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
///   File: teller.hpp
///
/// Author: $author$
///   Date: 4/4/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_TELLER_HPP
#define _XOS_NADIR_XOS_IO_TELLER_HPP

#include "xos/io/whence.hpp"

namespace xos {
namespace io {

typedef base::implement_base teller_implements;
///////////////////////////////////////////////////////////////////////
///  Class: tellert
///////////////////////////////////////////////////////////////////////
template <class TImplements = teller_implements>
class _EXPORT_CLASS tellert: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t tell() {
        return -1;
    }
    virtual ssize_t eof() {
        return -1;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef tellert<> teller;

} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_TELLER_HPP 
