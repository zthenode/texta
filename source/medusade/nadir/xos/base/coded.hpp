///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   File: coded.hpp
///
/// Author: $author$
///   Date: 3/2/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_CODED_HPP
#define _XOS_BASE_CODED_HPP

#include "xos/base/coder.hpp"

namespace xos {
namespace base {

typedef implement_base codedt_implements;
typedef base codedt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: codedt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = codedt_implements, class TExtends = codedt_extends>

class _EXPORT_CLASS codedt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    codedt() {
    }
    virtual ~codedt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef codedt<> coded;

} // namespace base 
} // namespace xos 

#endif // _XOS_BASE_CODED_HPP 
