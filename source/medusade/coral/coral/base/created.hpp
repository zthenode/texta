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
///   File: created.hpp
///
/// Author: $author$
///   Date: 4/8/2015
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_BASE_CREATED_HPP
#define _CORAL_BASE_CREATED_HPP

#include "coral/base/attached.hpp"
#include "coral/base/creator.hpp"
#include "xos/base/created.hpp"

namespace coral {

typedef xos::base::creator created_implements;
typedef xos::base::base created_extends;
///////////////////////////////////////////////////////////////////////
///  Class: createdt
///////////////////////////////////////////////////////////////////////
#if defined(USE_CPP_11)
template
<typename TAttached = void*,
 typename TUnattached = int, TUnattached VUnattached = 0,
 class TImplements = attachert
 <TAttached, TUnattached, VUnattached, created_implements>,
 class TExtends = attachedt
 <TAttached, TUnattached, VUnattached, TImplements, created_extends> >

using createdt = typename xos::base::createdt
<TAttached, TUnattached, VUnattached, TImplements, TExtends>;
#else // defined(USE_CPP_11)
#endif // defined(USE_CPP_11)

} // namespace coral

#endif // _CORAL_BASE_CREATED_HPP 
