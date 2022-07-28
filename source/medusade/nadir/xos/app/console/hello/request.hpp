///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2014 $organization$
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
///   File: request.hpp
///
/// Author: $author$
///   Date: 12/12/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_APP_CONSOLE_HELLO_REQUEST_HPP
#define _XOS_NADIR_XOS_APP_CONSOLE_HELLO_REQUEST_HPP

#include "xos/app/console/hello/message.hpp"

namespace xos {
namespace app {
namespace console {
namespace hello {

///////////////////////////////////////////////////////////////////////
///  Class: request
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS request: public message {
public:
    typedef message Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    request() {
    }
    virtual ~request() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace hello 
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_NADIR_XOS_APP_CONSOLE_HELLO_REQUEST_HPP 
