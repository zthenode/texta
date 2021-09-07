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
///   File: cDebug.hpp
///
/// Author: $author$
///   Date: 4/17/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_LANGUAGE_TEXTA_PROCESSOR_XDE_CDEBUG_HPP
#define XOS_LANGUAGE_TEXTA_PROCESSOR_XDE_CDEBUG_HPP

#include "xos/base/logger.hpp"
#include "cdebug_printf.h"

extern "C" {
extern int CDEBUG_VPRINTF(const char* format, va_list va);
} /// extern "C"

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

#endif /// ndef XOS_LANGUAGE_TEXTA_PROCESSOR_XDE_CDEBUG_HPP 
