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
///   Date: 12/21/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_NADIR_IO_STRING_HPP
#define _CORAL_NADIR_IO_STRING_HPP

#include "coral/nadir/base/string.hpp"
#include "coral/nadir/io/stream.hpp"
#include "nadir/io/string.hpp"

namespace coral {
namespace io {

namespace string {
typedef ::nadir::io::string::readert<coral::string> reader;
typedef ::nadir::io::string::writert<coral::string> writer;
} /// namespace string

namespace tstring {
typedef ::nadir::io::string::readert<coral::tstring> reader;
typedef ::nadir::io::string::writert<coral::tstring> writer;
} /// namespace tstring

namespace wstring {
typedef ::nadir::io::string::readert<coral::wstring> reader;
typedef ::nadir::io::string::writert<coral::wstring> writer;
} /// namespace wstring

} /// namespace io
} /// namespace coral

#endif /// ndef _CORAL_NADIR_IO_STRING_HPP
