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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 6/2/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_CONSOLE_MAIN_OPT_HPP
#define _TEXTA_CONSOLE_MAIN_OPT_HPP

#include "texta/base/main.hpp"

namespace texta {
namespace app {
namespace console {

typedef texta::console::main_opt_argument_t main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = texta::console::MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = texta::console::MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = texta::console::MAIN_OPT_ARGUMENT_OPTIONAL
};

} // namespace console
} // namespace app
} // namespace texta

#endif // _TEXTA_CONSOLE_MAIN_OPT_HPP 
