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
///   File: types.hpp
///
/// Author: $author$
///   Date: 4/8/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_BASE_TYPES_HPP
#define _CORAL_BASE_TYPES_HPP

#include "coral/base/base.hpp"
#include "xos/base/types.hpp"

namespace coral {

///////////////////////////////////////////////////////////////////////
///  Class: typest
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<class TWhat = char, class TEndWhat = TWhat, TEndWhat VEndWhat = 0,
 class TInt = int, class TUInt = unsigned, class TSize = size_t,
 class TLength = ssize_t, TLength VUndefinedLength = -1>

using typest = typename xos::base::typest
<TWhat, TEndWhat, VEndWhat, TInt, TUInt, TSize, TLength, VUndefinedLength>;
#else // defined(USE_CPP_11)
template
<class TWhat = char, class TEndWhat = TWhat, TEndWhat VEndWhat = 0,
 class TInt = int, class TUInt = unsigned, class TSize = size_t,
 class TLength = ssize_t, TLength VUndefinedLength = -1,
 class TExtends = xos::base::typest
 <TWhat, TEndWhat, VEndWhat, TInt, TUInt, TSize, TLength, VUndefinedLength> >

class XOS_TYPES_EXPORT_CLASS typest: virtual public TExtends {
public:
};
#endif // defined(USE_CPP_11)

typedef xos::base::chars_t chars_t;
typedef xos::base::tchars_t tchars_t;
typedef xos::base::wchars_t wchars_t;

typedef xos::base::bytes_t bytes_t;
typedef xos::base::words_t words_t;

} // namespace coral

#endif // _CORAL_BASE_TYPES_HPP 
