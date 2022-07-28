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
///   File: attributes.hpp
///
/// Author: $author$
///   Date: 4/13/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_OS_WINDOWS_SECURITY_ATTRIBUTES_HPP
#define _XOS_NADIR_XOS_OS_WINDOWS_SECURITY_ATTRIBUTES_HPP

#include "xos/base/wrapped.hpp"

namespace xos {
namespace os {
namespace windows {
namespace security {

typedef base::wrapped_implements attributes_implements;
typedef base::wrappedt<SECURITY_ATTRIBUTES> attributes_extends;
///////////////////////////////////////////////////////////////////////
///  Class: attributest
///////////////////////////////////////////////////////////////////////
template
<class TExtends = attributes_extends, class TImplements = attributes_implements>

class _EXPORT_CLASS attributest: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    attributest() {
        this->wrapped_.nLength = sizeof(SECURITY_ATTRIBUTES);
    }
    attributest(const attributest& copy): Extends(copy) {
        this->wrapped_.nLength = sizeof(SECURITY_ATTRIBUTES);
    }
    virtual ~attributest() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef attributest<> attributes;

} // namespace security 
} // namespace windows 
} // namespace os 
} // namespace xos 

#endif // _XOS_NADIR_XOS_OS_WINDOWS_SECURITY_ATTRIBUTES_HPP 
