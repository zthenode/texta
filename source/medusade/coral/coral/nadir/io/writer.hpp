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
///   Date: 12/20/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_NADIR_IO_WRITER_HPP
#define _CORAL_NADIR_IO_WRITER_HPP

#include "coral/nadir/base/base.hpp"
#include "nadir/io/writer.hpp"

namespace coral {
namespace io {

typedef ::nadir::io::writer writer;
typedef ::nadir::io::byte_writer byte_writer;
typedef ::nadir::io::char_writer char_writer;
typedef ::nadir::io::wchar_writer wchar_writer;
typedef ::nadir::io::tchar_writer tchar_writer;

typedef ::nadir::io::writer::Implements writer_implements;
typedef ::nadir::io::byte_writer::Implements byte_writer_implements;
typedef ::nadir::io::char_writer::Implements char_writer_implements;
typedef ::nadir::io::wchar_writer::Implements wchar_writer_implements;
typedef ::nadir::io::tchar_writer::Implements tchar_writer_implements;

} /// namespace io
} /// namespace coral

#endif /// ndef _CORAL_NADIR_IO_WRITER_HPP
