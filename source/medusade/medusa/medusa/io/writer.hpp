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
///   File: writer.hpp
///
/// Author: $author$
///   Date: 10/29/2018
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_IO_WRITER_HPP
#define _MEDUSA_IO_WRITER_HPP

#include "medusa/io/sequence.hpp"
#include "xos/io/string/writer.hpp"

namespace medusa {
namespace io {

typedef xos::io::writer writer;
typedef xos::io::byte_writer byte_writer;
typedef xos::io::char_writer char_writer;
typedef xos::io::wchar_writer wchar_writer;
typedef xos::io::tchar_writer tchar_writer;

namespace string {
typedef xos::io::string::writert<string_t> writer;
} // namespace string

namespace bstring {
typedef xos::io::string::writert<bstring_t> writer;
} // namespace bstring

} /// namespace io
} /// namespace medusa

#endif ///ndef _MEDUSA_IO_WRITER_HPP
