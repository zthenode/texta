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
///   File: file.hpp
///
/// Author: $author$
///   Date: 12/21/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_NADIR_IO_FILE_HPP
#define _CORAL_NADIR_IO_FILE_HPP

#include "coral/nadir/io/stream.hpp"
#include "nadir/io/crt/file.hpp"
#include "nadir/io/crt/file_stream.hpp"

namespace coral {
namespace io {

namespace read {
typedef ::nadir::io::crt::read::file file;
} // namespace read

namespace write {
typedef ::nadir::io::crt::write::file file;
} // namespace write

namespace file {
typedef ::nadir::io::crt::file_stream stream;
} // namespace file

} /// namespace io
} /// namespace coral

#endif /// ndef _CORAL_NADIR_IO_FILE_HPP
