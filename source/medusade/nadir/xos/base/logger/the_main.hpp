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
///   File: the_main.hpp
///
/// Author: $author$
///   Date: 9/11/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_LOGGER_THE_MAIN_HPP
#define _XOS_NADIR_XOS_BASE_LOGGER_THE_MAIN_HPP

#include "xos/base/main.hpp"
#include "xos/io/main/logger.hpp"
#include "xos/mt/main/mutex.hpp"
#include "xos/io/std/cerr/logger.hpp"

namespace xos {
namespace base {

///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template
<typename TChar, typename TEnd, TEnd VEnd,
 class TImplements, class TExtends>

int maint<TChar, TEnd, VEnd, TImplements, TExtends>::the_main
(int argc, char_t** argv, char_t** env) {
    int err = 1;
    maint* main;

    if ((main = get_the_main())) {
        XOS_ERR_LOG_DEBUG("try {...");
        try {
            mt::main::mutext<maint> mutex(*main);
            io::main::loggert<TChar, TEnd, VEnd, maint> logger(*main);
    
            // initialize logger
            //
            XOS_LOGGER_INIT();
    
            XOS_LOG_DEBUG("(*main)(argc, argv, env)...");
            err = (*main)(argc, argv, env);
            XOS_LOG_DEBUG("err = " << err << " on (*main)(argc, argv, env)...");
    
            // finalize logger
            //
            XOS_LOGGER_FINI();
            XOS_ERR_LOG_DEBUG("...} try");
        } catch (...) {
            XOS_ERR_LOG_ERROR("...catch (...)");
        }
    } else {
        XOS_ERR_LOG_ERROR("...failed on 0 = get_the_main()");
    }
    return err;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template
<typename TChar, typename TEnd, TEnd VEnd,
 class TImplements, class TExtends>
maint<TChar, TEnd, VEnd, TImplements, TExtends>*&
maint<TChar, TEnd, VEnd, TImplements, TExtends>::get_the_main() {
    static maint<TChar, TEnd, VEnd, TImplements, TExtends>* the_main = 0;
    return the_main;
}

namespace logger {

} // namespace logger 
} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_LOGGER_THE_MAIN_HPP 
