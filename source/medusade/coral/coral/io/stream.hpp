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
///   File: stream.hpp
///
/// Author: $author$
///   Date: 12/25/2017
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_IO_STREAM_HPP
#define _CORAL_IO_STREAM_HPP

#include "xos/io/stream.hpp"
#include "coral/io/writer.hpp"
#include "coral/io/reader.hpp"
#include "coral/io/sequence.hpp"

namespace coral {
namespace io {

///////////////////////////////////////////////////////////////////////
///  Class: streamt
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TWhat = void, typename TSized = char,
 typename TEnd = int, TEnd VEnd = 0,
 class TSequence = ::xos::io::sequencet<TWhat, TEnd, VEnd>,
 class TReader = ::xos::io::readert<TWhat, TSized, TEnd, VEnd, TSequence>, 
 class TWriter = ::xos::io::writert<TWhat, TSized, TEnd, VEnd, TSequence>,
 class TReaderImplements = TReader, class TWriterImplements = TWriter>

using streamt = typename xos::io::streamt
<TWhat, TSized, TEnd, VEnd, TSequence, TReader, TWriter>;
#else // defined(USE_CPP_11)
#endif // defined(USE_CPP_11)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef ::xos::io::stream stream;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef ::xos::io::char_stream char_stream;
typedef ::xos::io::tchar_stream tchar_stream;
typedef ::xos::io::wchar_stream wchar_stream;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef ::xos::io::byte_stream byte_stream;
typedef ::xos::io::word_stream word_stream;

} // namespace io 
} // namespace coral 

#endif // _CORAL_IO_STREAM_HPP 
