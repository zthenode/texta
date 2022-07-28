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
///   File: stream.hpp
///
/// Author: $author$
///   Date: 12/21/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_NADIR_IO_STREAM_HPP
#define _CORAL_NADIR_IO_STREAM_HPP

#include "coral/nadir/io/sequence.hpp"
#include "coral/nadir/io/reader.hpp"
#include "coral/nadir/io/writer.hpp"
#include "nadir/io/stream.hpp"

namespace coral {
namespace io {

typedef ::nadir::io::stream stream;
typedef ::nadir::io::char_stream char_stream;
typedef ::nadir::io::tchar_stream tchar_stream;
typedef ::nadir::io::wchar_stream wchar_stream;
typedef ::nadir::io::byte_stream byte_stream;
typedef ::nadir::io::word_stream word_stream;

} /// namespace io
} /// namespace coral

#endif /// ndef _CORAL_NADIR_IO_STREAM_HPP
