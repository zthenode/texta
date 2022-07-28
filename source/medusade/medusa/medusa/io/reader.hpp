///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2015 $organization$
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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 4/9/2015
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_IO_READER_HPP
#define _MEDUSA_IO_READER_HPP

#include "medusa/io/sequence.hpp"
#include "xos/io/string/reader.hpp"

namespace medusa {
namespace io {

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

} // namespace io
} // namespace medusa 

#endif // _MEDUSA_IO_READER_HPP 
