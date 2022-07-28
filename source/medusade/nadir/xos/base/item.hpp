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
///   File: item.hpp
///
/// Author: $author$
///   Date: 3/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_ITEM_HPP
#define _XOS_NADIR_XOS_BASE_ITEM_HPP

#include "xos/base/string.hpp"
#include "xos/base/base.hpp"

namespace xos {
namespace base {

class _EXPORT_CLASS item;
typedef string item_what;
typedef implement_base item_implements;
typedef base item_extends;
///////////////////////////////////////////////////////////////////////
///  Class: itemt
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = item_what, class TItem = item,
 class TImplements = item_implements, class TExtends = item_extends>
class _EXPORT_CLASS itemt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TItem Derives;
    typedef TWhat what_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    itemt(const what_t& what, Derives* prev = 0, Derives* next = 0)
    : prev_(prev), next_(next), what_(what) {
    }
    itemt(const itemt& copy)
    : prev_(0), next_(0), what_(copy.what()) {
    }
    virtual ~itemt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Derives* set_prev(Derives* to) {
        prev_ = to;
        return prev_;
    }
    virtual Derives* prev() const {
        return prev_;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual Derives* set_next(Derives* to) {
        next_ = to;
        return next_;
    }
    virtual Derives* next() const {
        return next_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual what_t& set_what(const what_t& to) {
        return what_;
    }
    virtual what_t& what() const {
        return (what_t&)what_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Derives *prev_, *next_;
    what_t what_;
};

///////////////////////////////////////////////////////////////////////
///  Class: item
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS item
: virtual public item_implements,
  public itemt<item_what, item, item_implements, item_extends> {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual what_t& set_what(const what_t& to) {
        what_ = to;
        return what_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_ITEM_HPP 
        

