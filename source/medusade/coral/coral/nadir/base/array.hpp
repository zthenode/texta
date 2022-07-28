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
///   File: array.hpp
///
/// Author: $author$
///   Date: 12/20/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_NADIR_BASE_ARRAY_HPP
#define _CORAL_NADIR_BASE_ARRAY_HPP

#include "coral/nadir/base/types.hpp"
#include "nadir/base/array.hpp"

namespace coral {

#define CORAL_ARRAY_DEFAULT_SIZE NADIR_ARRAY_DEFAULT_SIZE
typedef ::nadir::arrayt_implements array_implements;
typedef ::nadir::arrayt_extends array_extends;
///////////////////////////////////////////////////////////////////////
///  Class: arrayt
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = char, 
 typename TSize = size_t, TSize VSize = CORAL_ARRAY_DEFAULT_SIZE,
 class TExtend = array_extends, class TImplements = array_implements,
 class TExtends = ::nadir::arrayt<TWhat, TSize, VSize, TImplements, TExtend> >

class _EXPORT_CLASS arrayt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TWhat what_t;
    typedef TSize size_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    arrayt(ssize_t length): Extends(length) {
    }
    arrayt(const arrayt& copy): Extends(copy) {
    }
    arrayt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef ::nadir::char_array char_array;
typedef ::nadir::tchar_array tchar_array;
typedef ::nadir::wchar_array wchar_array;

} /// namespace coral

#endif /// ndef _CORAL_NADIR_BASE_ARRAY_HPP
