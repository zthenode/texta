///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
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
///   File: extend.hpp
///
/// Author: $author$
///   Date: 1/11/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_BASE_EXTEND_HPP
#define XOS_BASE_EXTEND_HPP

#include "xos/base/implement.hpp"

namespace xos {
namespace base {

///////////////////////////////////////////////////////////////////////
/// class extend
///////////////////////////////////////////////////////////////////////
class EXPORT_CLASS extend: virtual public implement, public base {
public:
    typedef implement Implements;
    typedef base Extends;
    typedef extend Derives;

    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    extend(const extend& copy): Extends(copy) {
    }
    extend() {
    }
    virtual ~extend() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
}; /// class extend

} /// namespace base
} /// namespace xos

#endif /// ndef XOS_BASE_EXTEND_HPP 
