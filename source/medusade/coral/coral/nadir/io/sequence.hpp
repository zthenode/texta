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
///   File: sequence.hpp
///
/// Author: $author$
///   Date: 12/20/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_NADIR_IO_SEQUENCE_HPP
#define _CORAL_NADIR_IO_SEQUENCE_HPP

#include "coral/nadir/base/base.hpp"
#include "nadir/io/sequence.hpp"

namespace coral {
namespace io {

typedef ::nadir::io::sequence sequence;
typedef ::nadir::io::byte_sequence byte_sequence;
typedef ::nadir::io::char_sequence char_sequence;
typedef ::nadir::io::tchar_sequence tchar_sequence;
typedef ::nadir::io::wchar_sequence wchar_sequence;

} /// namespace io
} /// namespace coral

#endif /// ndef _CORAL_NADIR_IO_SEQUENCE_HPP
