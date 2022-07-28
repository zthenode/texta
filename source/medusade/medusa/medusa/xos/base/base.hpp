///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
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
///   File: base.hpp
///
/// Author: $author$
///   Date: 6/3/2017
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_XOS_BASE_BASE_HPP
#define _MEDUSA_XOS_BASE_BASE_HPP

#include "xos/base/base.hpp"
#include "xos/base/types.hpp"
#include "xos/base/array.hpp"
#include "xos/base/string.hpp"
#include "xos/base/to_string.hpp"
#include "xos/io/sequence.hpp"
#include "xos/io/reader.hpp"
#include "xos/io/writer.hpp"
#include "xos/io/string/reader.hpp"
#include "xos/io/file/attached.hpp"
#include "xos/io/file/opened.hpp"
#include "xos/io/file/reader.hpp"
#include "xos/io/file/writer.hpp"
#include "xos/io/read/file.hpp"
#include "xos/io/write/file.hpp"

namespace medusa {

typedef xos::base::implement_base implement_base;
typedef xos::base::base base;

typedef xos::base::chars_t chars_t;
typedef xos::base::tchars_t tchars_t;
typedef xos::base::wchars_t wchars_t;
typedef xos::base::bytes_t bytes_t;

typedef xos::base::byte_array byte_array;
typedef xos::base::char_array char_array;
typedef xos::base::wchar_array wchar_array;
typedef xos::base::tchar_array tchar_array;

typedef xos::base::string_implements string_implements;
typedef xos::base::string string_extends;

typedef string_implements string_t_implements;
typedef string_implements wstring_t_implements;
typedef string_implements tstring_t_implements;
typedef string_implements bstring_t_implements;

typedef xos::base::string string_t;
typedef xos::base::tstring tstring_t;
typedef xos::base::wstring wstring_t;
typedef xos::base::bstring bstring_t;

namespace io {

typedef xos::io::sequence sequence;
typedef xos::io::byte_sequence byte_sequence;
typedef xos::io::char_sequence char_sequence;
typedef xos::io::wchar_sequence wchar_sequence;
typedef xos::io::tchar_sequence tchar_sequence;

typedef xos::io::reader reader;
typedef xos::io::byte_reader byte_reader;
typedef xos::io::char_reader char_reader;
typedef xos::io::wchar_reader wchar_reader;
typedef xos::io::tchar_reader tchar_reader;

namespace string {

typedef xos::io::string::readert<string_t> reader;

} // namespace string

namespace bstring {

typedef xos::io::string::readert<bstring_t> reader;

} // namespace bstring

namespace file {

typedef xos::io::file::reader reader;
typedef xos::io::file::writer writer;

typedef xos::io::file::attacher attacher;
typedef xos::io::file::attached attached;
typedef xos::io::file::opened opened;

} // namespace file

namespace read {

typedef xos::io::read::file file;

} // namespace read

namespace write {

typedef xos::io::write::file file;

} // namespace write

} // namespace io

} // namespace medusa

#endif // _MEDUSA_XOS_BASE_BASE_HPP 
