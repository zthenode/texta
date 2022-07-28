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
///   File: mutex.hpp
///
/// Author: $author$
///   Date: 10/30/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_MAIN_MUTEX_HPP
#define _XOS_NADIR_XOS_MT_MAIN_MUTEX_HPP

#include "xos/base/main.hpp"
#include "xos/mt/os/mutex.hpp"

namespace xos {
namespace mt {
namespace main {

typedef base::main mutex_main;
typedef mt::os::mutex::Implements mutex_implements;
typedef mt::os::mutex mutex_extends;
///////////////////////////////////////////////////////////////////////
///  Class: mutext
///////////////////////////////////////////////////////////////////////
template
<class TMain = mutex_main,
 class TImplements = mutex_implements, class TExtends = mutex_extends>

class _EXPORT_CLASS mutext: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    mutext(TMain& main): Extends(false), main_(main) {
        main_.attach(this);
    }
    virtual ~mutext() {
        main_.detach();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    TMain& main_;
};
typedef mutext<> mutex;

} // namespace main 
} // namespace mt 
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_MAIN_MUTEX_HPP 
