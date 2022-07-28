///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
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
///   Date: 6/4/2017
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_XOS_BASE_MAIN_HPP
#define _MEDUSA_XOS_BASE_MAIN_HPP

#include "medusa/xos/base/base.hpp"
#include "xos/base/getopt/main.hpp"
#include "xos/base/getopt/main_opt.hpp"

#define MEDUSA_MAIN_LOGGING_OPTVAL_C XOS_MAIN_LOGGING_OPTVAL_C
#define MEDUSA_MAIN_LOGGING_OPTARG XOS_MAIN_LOGGING_OPTARG
#define MEDUSA_MAIN_LOGGING_OPTUSE XOS_MAIN_LOGGING_OPTUSE

#define MEDUSA_MAIN_HELP_OPTVAL_C XOS_MAIN_HELP_OPTVAL_C
#define MEDUSA_MAIN_HELP_OPTARG XOS_MAIN_HELP_OPTARG
#define MEDUSA_MAIN_HELP_OPTUSE XOS_MAIN_HELP_OPTUSE

enum {
    MEDUSA_MAIN_OPT_ARGUMENT_NONE     = XOS_MAIN_OPT_ARGUMENT_NONE,
    MEDUSA_MAIN_OPT_ARGUMENT_REQUIRED = XOS_MAIN_OPT_ARGUMENT_REQUIRED,
    MEDUSA_MAIN_OPT_ARGUMENT_OPTIONAL = XOS_MAIN_OPT_ARGUMENT_OPTIONAL
};

namespace medusa {
namespace console {

typedef xos::base::getopt::main_implement main_implements;
typedef xos::base::getopt::main main_extends;

} // namespace console
} // namespace medusa 

#endif // _MEDUSA_XOS_BASE_MAIN_HPP 
