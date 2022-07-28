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
///   File: main.hpp
///
/// Author: $author$
///   Date: 11/24/2014
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_APP_CONSOLE_MEDUSAD_MAIN_HPP
#define _MEDUSA_APP_CONSOLE_MEDUSAD_MAIN_HPP

#include "medusa/console/main.hpp"
#include "medusa/inet/medusa/server/response.hpp"
#include "medusa/inet/medusa/server/request.hpp"
#include "medusa/inet/http/request.hpp"
#include "medusa/inet/http/requests.hpp"
#include "medusa/inet/http/version.hpp"

namespace medusa {
namespace app {
namespace console {
namespace medusad {

typedef console::main_implement main_implement;
typedef console::main main_extend;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual protected main_implement, public main_extend {
public:
    typedef main_implement Implements;
    typedef main_extend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main() {
    }
    virtual ~main() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char** argv, char** env) {
        inet::medusa::server::restart::request rq;
        inet::medusa::server::success::response rs;
        inet::http::GET::request::message m("/");
        out(m.chars());
        out(rq.chars());
        out(rs.chars());
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace medusad 
} // namespace console 
} // namespace app 
} // namespace medusa 

#endif // _MEDUSA_APP_CONSOLE_MEDUSAD_MAIN_HPP 
