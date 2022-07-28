///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   File: string.hpp
///
/// Author: $author$
///   Date: 10/30/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_IO_STRING_HPP
#define _CORAL_IO_STRING_HPP

#include "coral/base/string.hpp"
#include "coral/io/reader.hpp"
#include "coral/io/writer.hpp"
#include "xos/io/string/reader.hpp"
#include "xos/io/string/writer.hpp"

namespace coral {
namespace io {
namespace string {

typedef ::xos::io::string::readert<string_t> reader;
typedef ::xos::io::string::writert<string_t> writer;

} /// namespace string
} /// namespace io
} /// namespace coral

#endif ///ndef _CORAL_IO_STRING_HPP
