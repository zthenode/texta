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
///   File: opened.hpp
///
/// Author: $author$
///   Date: 1/25/2018
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_BASE_OPENED_HPP
#define _MEDUSA_BASE_OPENED_HPP

#include "medusa/base/base.hpp"
#include "xos/base/opened.hpp"

namespace medusa {

typedef ::xos::base::opener_exception opener_exception;
static const opener_exception failed_to_open = ::xos::base::failed_to_open;
static const opener_exception failed_to_close = ::xos::base::failed_to_close;

typedef ::xos::base::opener opener;
typedef ::xos::base::opened opened;

} // namespace medusa 

#endif // _MEDUSA_BASE_OPENED_HPP 
