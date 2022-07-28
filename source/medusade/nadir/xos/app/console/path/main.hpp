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
///   File: main.hpp
///
/// Author: $author$
///   Date: 5/27/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_APP_CONSOLE_PATH_MAIN_HPP
#define _XOS_NADIR_XOS_APP_CONSOLE_PATH_MAIN_HPP

#include "xos/base/getopt/main.hpp"
#include "xos/fs/path.hpp"

namespace xos {
namespace app {
namespace console {
namespace path {

typedef base::getopt::main_implements main_implements;
typedef base::getopt::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template
<class TImplements = main_implements, class TExtends = main_extends>

class _EXPORT_CLASS maint: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint() {
    }
    virtual ~maint() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char **argv, char **env) {
        int err = 0;
        const char *arg = 0;
        if ((optind < argc) && (argv) && ((arg = argv[optind])) && (arg[0])) {
            fs::path p(arg);
            this->outl("file_name = \"", p.file_name().chars(), "\"\n", NULL);
            this->outl("file_base = \"", p.file_base().chars(), "\"\n", NULL);
            this->outl("file_extension = \"", p.file_extension().chars(), "\"\n", NULL);
            this->outl("file_path = \"", p.file_path().chars(), "\"\n", NULL);
            this->outl("file_base_path = \"", p.file_base_path().chars(), "\"\n", NULL);
            this->outl("path = \"", p.chars(), "\"\n", NULL);
        } else {
            this->usage(argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef maint<> main;

} // namespace path 
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_NADIR_XOS_APP_CONSOLE_PATH_MAIN_HPP 
