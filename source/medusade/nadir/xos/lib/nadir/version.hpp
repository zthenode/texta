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
///   File: version.hpp
///
/// Author: $author$
///   Date: 5/12/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_LIB_NADIR_VERSION_HPP
#define _XOS_NADIR_XOS_LIB_NADIR_VERSION_HPP

#include "xos/lib/version.hpp"

namespace xos {
namespace lib {
namespace nadir {

///////////////////////////////////////////////////////////////////////
///  Class: version
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS version {
public:
    static const lib::version& which();
};

} // namespace nadir
} // namespace lib
} // namespace xos

#endif // _XOS_NADIR_XOS_LIB_NADIR_VERSION_HPP 
