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
///   File: sequence.hpp
///
/// Author: $author$
///   Date: 4/8/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_IO_SEQUENCE_HPP
#define _CORAL_IO_SEQUENCE_HPP

#include "coral/base/base.hpp"
#include "xos/io/sequence.hpp"

namespace coral {
namespace io {

typedef xos::io::sequence_implement sequence_implement;
///////////////////////////////////////////////////////////////////////
///  Class: sequencet
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TWhat = char_t, typename TEnd = int, TEnd VEnd = 0,
 class TImplements = xos::io::sequence_implement>

using sequencet = typename xos::io::sequencet
<TWhat, TEnd, VEnd, TImplements>;
#else // defined(USE_CPP_11)
#endif // defined(USE_CPP_11)

typedef xos::io::sequence sequence;
typedef xos::io::char_sequence char_sequence;
typedef xos::io::wchar_sequence wchar_sequence;
typedef xos::io::tchar_sequence tchar_sequence;

} // namespace io
} // namespace coral 

#endif // _CORAL_IO_SEQUENCE_HPP 
