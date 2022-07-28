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
///   File: opener.hpp
///
/// Author: $author$
///   Date: 10/31/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_OPENER_HPP
#define _XOS_NADIR_XOS_BASE_OPENER_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace base {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum opener_exception {
    failed_to_open,
    failed_to_close,
    open_failed,
    close_failed
};
typedef opener_exception open_exception;

typedef implement_base opener_implements;
///////////////////////////////////////////////////////////////////////
///  Class: openert
///////////////////////////////////////////////////////////////////////
template <class TImplements = opener_implements>

class _EXPORT_CLASS openert: virtual public TImplements {
public:
    typedef TImplements Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool open() {
        if ((this->closed())) {
            if ((this->set_is_open())) {
                return true;
            }
        }
        return false;
    }
    virtual bool close() {
        if ((this->is_open())) {
            this->set_is_open(false);
            if ((this->is_closed())) {
                return true;
            }
        }
        return false;
    }
    virtual bool closed() {
        if ((this->is_open())) {
            if ((this->close())) {
                return true;
            }
        }
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_is_open(bool is_true = true) {
        return false;
    }
    virtual bool is_open() const {
        return false;
    }
    virtual bool is_closed() const {
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef openert<> opener;

} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_OPENER_HPP 
