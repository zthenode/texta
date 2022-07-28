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
///   File: main.hpp
///
/// Author: $author$
///   Date: 3/21/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_APP_CONSOLE_STAT_MAIN_HPP
#define _XOS_NADIR_XOS_APP_CONSOLE_STAT_MAIN_HPP

#include "xos/base/getopt/main.hpp"
#include "xos/os/fs/entry.hpp"
#include "xos/fs/entry.hpp"
#include "xos/app/console/stat/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace stat {

typedef base::getopt::main_implement main_implement;
typedef base::getopt::main main_extend;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implement, public main_extend {
public:
    typedef main_implement Implements;
    typedef main_extend Extends;
    typedef main Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main(): on_entry_(0) {
    }
    virtual ~main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optind < (argc))) {
            const char_t* path = 0;
            fs::entry_type type = fs::entry_type_none;
            xos::os::fs::entry e;
            for (int arg = optind; arg < argc; ++arg) {
                if (((path = argv[arg])) && ((path[0]))) {
                    if (fs::entry_type_none != (type = e.exists(path))) {
                        err = on_entry(e, path);
                    } else {
                        outl("Unable to find \"", path, "\"", 0);
                        outln();
                    }
                }
            }
        } else {
            err = usage(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_entry
    (const xos::os::fs::entry& e, const char_t* path = 0) {
        if ((on_entry_)) {
            return (this->*on_entry_)(e, path);
        }
        return on_entry_default(e, path);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_entry_default
    (const xos::os::fs::entry& e, const char_t* path = 0) {
        const fs::time* tm = 0;
        outl("name = ", path, 0);
        outln();
        out("type =");
        for (fs::entry_type_which t = fs::first_entry_type; t < fs::next_entry_type; t <<= 1) {
            if ((t & (e.type()))) {
                string_t name(fs::entry_type::name(t));
                outl(" ", name.chars(), 0);
            }
        }
        outln();
        outf("size = %lu", e.size());
        outln();
        for (fs::time_when_which t = fs::first_time_when; t < fs::next_time_when; t <<= 1) {
            if ((t & e.times()) && (tm = e.time_which(t))) {
                outl(fs::time_when::name(t), " = ", 0);
                outf("%d/%d/%d", tm->month(), tm->day(), tm->year());
                outln();
            }
        }
        return 0;
    }

#include "xos/app/console/stat/main_opt.cpp"
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef int (Derives::*on_entry_t)
    (const xos::os::fs::entry& e, const char_t* path);

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    on_entry_t on_entry_;
};

} // namespace stat 
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_NADIR_XOS_APP_CONSOLE_STAT_MAIN_HPP 
        

