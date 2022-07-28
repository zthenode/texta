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
///   File: main_opt.cpp
///
/// Author: $author$
///   Date: 9/13/2014
///////////////////////////////////////////////////////////////////////
#include "xos/base/getopt/main_opt.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace base {
namespace getopt {

int on_logging_level(const char* optarg) {
    int err = 1;
    char c;

    if ((optarg) && (c = optarg[0])) {
        if (!(optarg[1])) {
            err = 0;
            switch(c) {
            case 'a':
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_ALL);
                break;

            case '0':
            case 'n':
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_NONE);
                break;

            case '1':
            case 'f':
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_FATAL);
                break;

            case '2':
            case 'e':
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_ERROR);
                break;

            case '3':
            case 'w':
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_WARN);
                break;

            case '4':
            case 'i':
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_INFO);
                break;

            case '5':
            case 'd':
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_DEBUG);
                break;

            case '6':
            case 't':
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_TRACE);
                break;

            case 'A':
                XOS_SET_LOGGING_LEVEL
                (XOS_LOGGING_LEVELS_ALL_MESSAGE | XOS_LOGGING_LEVELS_ERROR);
                break;

            case 'N':
                XOS_SET_LOGGING_LEVEL
                (XOS_LOGGING_LEVELS_NONE_MESSAGE | XOS_LOGGING_LEVELS_ERROR);
                break;

            case 'F':
                XOS_SET_LOGGING_LEVEL
                (XOS_LOGGING_LEVELS_FATAL_MESSAGE | XOS_LOGGING_LEVELS_ERROR);
                break;

            case 'E':
                XOS_SET_LOGGING_LEVEL
                (XOS_LOGGING_LEVELS_ERROR_MESSAGE | XOS_LOGGING_LEVELS_ERROR);
                break;

            case 'W':
                XOS_SET_LOGGING_LEVEL
                (XOS_LOGGING_LEVELS_WARN_MESSAGE | XOS_LOGGING_LEVELS_ERROR);
                break;

            case 'I':
                XOS_SET_LOGGING_LEVEL
                (XOS_LOGGING_LEVELS_INFO_MESSAGE | XOS_LOGGING_LEVELS_ERROR);
                break;

            case 'D':
                XOS_SET_LOGGING_LEVEL
                (XOS_LOGGING_LEVELS_DEBUG_MESSAGE | XOS_LOGGING_LEVELS_ERROR);
                break;

            case 'T':
                XOS_SET_LOGGING_LEVEL
                (XOS_LOGGING_LEVELS_TRACE_MESSAGE | XOS_LOGGING_LEVELS_ERROR);
                break;

            default:
                err = 1;
                break;
            }
        }
    }
    return err;
}

int on_logging_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 1;
    switch(optval) {
    case XOS_MAIN_LOGGING_OPTVAL_C:
        err = on_logging_level(optarg);
        break;
    }
    return err;
}

} // namespace getopt
} // namespace base 
} // namespace xos 
