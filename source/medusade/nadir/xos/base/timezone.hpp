///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2015 $organization$
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
///   File: timezone.hpp
///
/// Author: $author$
///   Date: 3/15/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_TIMEZONE_HPP
#define _XOS_NADIR_XOS_BASE_TIMEZONE_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace base {

typedef implement_base timezone_implements;
typedef base timezone_extends;
///////////////////////////////////////////////////////////////////////
///  Class: timezonet
///////////////////////////////////////////////////////////////////////
template
<class TImplements=timezone_implements, class TExtends=timezone_extends>

class _EXPORT_CLASS timezonet: virtual protected TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    timezonet() {
    }
    virtual ~timezonet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef timezonet<> timezone;
typedef timezone* timezone_t;

} // namespace base 
} // namespace xos 


#endif // _XOS_NADIR_XOS_BASE_TIMEZONE_HPP 
        

