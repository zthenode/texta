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
///   File: acquire.hpp
///
/// Author: $author$
///   Date: 8/16/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_ACQUIRE_HPP
#define _XOS_NADIR_XOS_MT_ACQUIRE_HPP

#include "xos/mt/acquirer.hpp"

namespace xos {
namespace mt {

typedef base::implement_base acquire_implement;
typedef base::base acquire_extend;
///////////////////////////////////////////////////////////////////////
///  Class: acquiret
///////////////////////////////////////////////////////////////////////
template
<class TAcquirer = acquirer,
 class TExtends = acquire_extend,
 class TImplements = acquire_implement>

class _EXPORT_CLASS acquiret: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    acquiret(TAcquirer& acquirer): acquirer_(acquirer) {
        if (!(acquirer_.acquire())) {
            acquirer_exception e = acquire_failed;
            throw (e);
        }
    }
    virtual ~acquiret() {
        if (!(acquirer_.release())) {
            acquirer_exception e = release_failed;
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    TAcquirer& acquirer_;
};
typedef acquiret<> acquire;

} // namespace mt 
} // namespace xos 


#endif // _XOS_NADIR_XOS_MT_ACQUIRE_HPP 
        

