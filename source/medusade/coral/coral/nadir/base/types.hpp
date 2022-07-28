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
///   File: types.hpp
///
/// Author: $author$
///   Date: 12/20/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_NADIR_BASE_TYPES_HPP
#define _CORAL_NADIR_BASE_TYPES_HPP

#include "coral/nadir/base/base.hpp"
#include "nadir/base/chars.hpp"

namespace coral {

///////////////////////////////////////////////////////////////////////
///  Class: typest
///////////////////////////////////////////////////////////////////////
template
<class TWhat = char, class TEndWhat = TWhat, TEndWhat VEndWhat = 0,
 class TInt = int, class TUInt = unsigned, class TSize = size_t,
 class TLength = ssize_t, TLength VUndefinedLength = -1,
 class TExtends = ::nadir::charst<TWhat, TEndWhat, VEndWhat> >

class _EXPORT_CLASS typest: virtual public TExtends {
public:
};

typedef ::nadir::chars_t chars_t;
typedef ::nadir::tchars_t tchars_t;
typedef ::nadir::wchars_t wchars_t;

typedef ::nadir::bytes_t bytes_t;
typedef ::nadir::words_t words_t;

} /// namespace coral

#endif /// ndef _CORAL_NADIR_BASE_TYPES_HPP
