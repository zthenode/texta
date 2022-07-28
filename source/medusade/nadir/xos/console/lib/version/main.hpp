///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2019 $organization$
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
///   File: main.hpp
///
/// Author: $author$
///   Date: 3/13/2019, 6/14/2021
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_LIB_VERSION_MAIN_HPP
#define _XOS_CONSOLE_LIB_VERSION_MAIN_HPP

#include "xos/base/exception.hpp"
#include "xos/base/getopt/main.hpp"
#include "xos/lib/nadir/version.hpp"

namespace xos {
namespace console {
namespace lib {
namespace version {

typedef ::xos::base::getopt::main::Implements maint_implements;
typedef ::xos::base::getopt::main maint_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template 
<class TVersion = ::xos::lib::nadir::version, 
 class TImplements = maint_implements, class TExtends = maint_extends>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TVersion version_t;
    typedef typename Extends::char_t char_t;
    typedef typename Extends::end_t endchar_t;
    enum { endchar = Extends::end };
    typedef endchar_t end_char_t;
    enum { end_char = endchar };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint() {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = version_run(argc, argv, env);
        return err;
    }
    virtual int version_run(int argc, char_t** argv, char_t** env) {
        const ::xos::lib::version& version = version_t::which();
        this->outl(version.name(), " version = ", version.to_string().chars(), NULL);
        this->outln();
        this->out_flush();
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS maint
typedef maint<> main;

} /// namespace version
} /// namespace lib
} /// namespace console
} /// namespace xos

#endif /// ndef _XOS_CONSOLE_LIB_VERSION_MAIN_HPP
