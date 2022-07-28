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
///   File: boolean.hpp
///
/// Author: $author$
///   Date: 4/3/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_BOOLEAN_HPP
#define _XOS_NADIR_XOS_BASE_BOOLEAN_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace base {

typedef implement_base boolean_implements;
typedef base boolean_extends;
///////////////////////////////////////////////////////////////////////
///  Class: booleant
///////////////////////////////////////////////////////////////////////
template
<class TImplements = boolean_implements, class TExtends = boolean_extends>

class _EXPORT_CLASS booleant: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    booleant(bool is_true = false): is_true_(is_true) {
    }
    booleant(const booleant& copy): is_true_(copy.is_true_) {
    }
    virtual ~booleant() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    booleant& operator = (bool is_true) {
        is_true_ = is_true;
        return *this;
    }
    operator bool() const {
        return is_true_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool is_true_;
};
typedef booleant<> boolean;

} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_BOOLEAN_HPP 
