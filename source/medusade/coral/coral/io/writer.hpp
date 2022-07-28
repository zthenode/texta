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
///   File: writer.hpp
///
/// Author: $author$
///   Date: 4/8/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_IO_WRITER_HPP
#define _CORAL_IO_WRITER_HPP

#include "xos/io/echoed/writer.hpp"
#include "xos/io/writer.hpp"
#include "xos/io/sequence.hpp"

namespace coral {
namespace io {

///////////////////////////////////////////////////////////////////////
///  Class: writert
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TWhat = void, typename TSized = char_t,
 typename TEnd = int, TEnd VEnd = 0,
 class TImplements = xos::io::sequencet<TSized, TEnd, VEnd> >

using writert = typename xos::io::writert
<TWhat, TSized, TEnd, VEnd, TImplements>;
#else // defined(USE_CPP_11)
#endif // defined(USE_CPP_11)

typedef xos::io::writer writer;
typedef xos::io::char_writer char_writer;
typedef xos::io::wchar_writer wchar_writer;
typedef xos::io::tchar_writer tchar_writer;

typedef xos::io::writer::Implements writer_implements;
typedef xos::io::char_writer::Implements char_writer_implements;
typedef xos::io::wchar_writer::Implements wchar_writer_implements;
typedef xos::io::tchar_writer::Implements tchar_writer_implements;

namespace echoed {

///////////////////////////////////////////////////////////////////////
///  Class: writert
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TWhat = void, typename TSized = char_t,
 typename TEnd = int, TEnd VEnd = 0,
 class TWriter = xos::io::writert<TWhat, TSized, TEnd, VEnd>,
 class TImplements = TWriter, class TExtends = xos::io::echoed::writer_extends>

using writert = typename xos::io::echoed::writert
<TWhat, TSized, TEnd, VEnd, TWriter, TImplements, TExtends>;
#else // defined(USE_CPP_11)
#endif // defined(USE_CPP_11)

typedef xos::io::echoed::writer writer;

} // namespace echoed

} // namespace io
} // namespace coral 

#endif // _CORAL_IO_WRITER_HPP 
