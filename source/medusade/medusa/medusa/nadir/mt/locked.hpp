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
///   File: locked.hpp
///
/// Author: $author$
///   Date: 12/19/2018
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_NADIR_MT_LOCKED_HPP
#define _MEDUSA_NADIR_MT_LOCKED_HPP

#include "medusa/nadir/base/base.hpp"
#include "nadir/base/locked.hpp"

namespace medusa {
namespace mt {

typedef nadir::lock_exception lock_exception;
typedef nadir::locker lock;
typedef nadir::locked locked;

} /// namespace mt
} /// namespace medusa

#endif /// ndef _MEDUSA_NADIR_MT_LOCKED_HPP
