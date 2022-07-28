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
///   File: attacher.hpp
///
/// Author: $author$
///   Date: 4/8/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_BASE_ATTACHER_HPP
#define _CORAL_BASE_ATTACHER_HPP

#include "coral/base/base.hpp"
#include "xos/base/attacher.hpp"

namespace coral {

typedef xos::base::implement_base attacher_implements;
///////////////////////////////////////////////////////////////////////
///  Class: attachert
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TAttached = void*, typename TUnattached = int,
 TUnattached VUnattached = 0, class TImplements = attacher_implements>

using attachert = typename xos::base::attachert
<TAttached, TUnattached, VUnattached, TImplements>;
#else // defined(USE_CPP_11)
#endif // defined(USE_CPP_11)

} // namespace coral

#endif // _CORAL_BASE_ATTACHER_HPP 
