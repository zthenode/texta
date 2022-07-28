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
///   Date: 4/8/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_IO_READER_HPP
#define _CORAL_IO_READER_HPP

#include "coral/io/sequence.hpp"
#include "xos/io/reader.hpp"

namespace coral {
namespace io {

///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TWhat = void, typename TSized = char_t,
 typename TEnd = int, TEnd VEnd = 0,
 class TImplements = xos::io::reader_implement>

using readert = typename xos::io::readert
<TWhat, TSized, TEnd, VEnd, TImplements>;
#else // defined(USE_CPP_11)
#endif // defined(USE_CPP_11)

typedef xos::io::reader reader;
typedef xos::io::char_reader char_reader;
typedef xos::io::wchar_reader wchar_reader;
typedef xos::io::tchar_reader tchar_reader;

typedef xos::io::reader::Implements reader_implements;
typedef xos::io::char_reader::Implements char_reader_implements;
typedef xos::io::wchar_reader::Implements wchar_reader_implements;
typedef xos::io::tchar_reader::Implements tchar_reader_implements;

} // namespace io
} // namespace coral 

#endif // _CORAL_IO_READER_HPP 
