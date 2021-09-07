///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
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
///   File: cDebug.cpp
///
/// Author: $author$
///   Date: 4/17/2020
///////////////////////////////////////////////////////////////////////
#include "xos/language/texta/processor/xde/cDebug.hpp"

namespace xos {
namespace language {
namespace texta {
namespace processor {
namespace xde {

} /// namespace xde
} /// namespace processor
} /// namespace texta
} /// namespace language
} /// namespace xos

#if defined(CDEBUG_VPRINTF)
int CDEBUG_VPRINTF(const char* format, va_list va) {
    int count = 0;
    LOGGER_INTERFACE* logger = 0;

    if ((logger = DEFAULT_LOGGER)) {
       LOGGING_LEVELS level = LOGGING_LEVEL_DEBUG;

       count = logger->vlogf(level, format, va); 
    } 
    return count;
}
#endif /// defined(CDEBUG_VPRINTF)

#if defined(CDEBUG_PRINTF)
int CDEBUG_PRINTF(const char* format, ...) {
    int count = 0;
    va_list va;
    va_start(va, format);
    count = CDEBUG_VPRINTF(format, va);
    va_end(va);
    return count;
}
#endif /// defined(CDEBUG_PRINTF)
