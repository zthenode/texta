///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   File: processor.hpp
///
/// Author: $author$
///   Date: 2/20/2016
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_SERVER_DAEMON_HTTP_PROCESSOR_HPP
#define _MEDUSA_INET_XTTP_SERVER_DAEMON_HTTP_PROCESSOR_HPP

#include "medusa/inet/xttp/server/daemon/processors.hpp"
#include "medusa/inet/xttp/server/daemon/http/path/processor.hpp"
#include "medusa/inet/xttp/server/daemon/http/method/processor.hpp"
#include "medusa/inet/http/response.hpp"
#include "medusa/inet/http/request.hpp"
#include "medusa/inet/http/version.hpp"

namespace medusa {
namespace inet {
namespace xttp {
namespace server {
namespace daemon {
namespace http {

typedef processors::processor::Implements processor_implements;
typedef processors::processor processor_extends;
///////////////////////////////////////////////////////////////////////
///  Class: processor
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS processor
: virtual public processor_implements, public processor_extends {
public:
    typedef processor_implements Implements;
    typedef processor_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    processor(): Extends(MEDUSA_INET_HTTP_VERSION_PROTOCOL) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool init
    (int optind, int argc, const char_t*const* argv, const char_t*const* env) {
        bool err = 0;
        if (!(err = init_paths(optind, argc, argv, env))) {
            if (!(err = init_methods(optind, argc, argv, env))) {
            }
        }
        return err;
    }
    virtual bool fini
    (int optind, int argc, const char_t*const* argv, const char_t*const* env) {
        int err = 0, err2 = 0;
        if ((err2 = fini_methods(optind, argc, argv, env))) {
            if (!err) err = err2;
        }
        if ((err2 = fini_paths(optind, argc, argv, env))) {
            if (!err) err = err2;
        }
        return err;
    }
    virtual status_t process
    (signaler_t& restart, signaler_t& stop, response_t& rs, const request_t& rq) {
        status_t status = processing_none;
        if (!(processing_none != (status = process_paths(restart, stop, rs, rq)))) {
            if (!(processing_none != (status = process_methods(restart, stop, rs, rq)))) {
            }
        }
        return status;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool init_paths
    (int optind, int argc, const char_t*const* argv, const char_t*const* env) {
        bool err = 0, err2;
        path::processor::list_t& p = path::processor::processors();
        path::processor::list_t::iterator b = p.begin();
        path::processor::list_t::iterator e = p.end();
        for (path::processor::list_t::iterator i = b; i != e; ++i) {
            if ((err = (*i)->init(optind, argc, argv, env))) {
                for (path::processor::list_t::iterator j = b; j != i; ++j) {
                    if ((err2 = (*i)->fini(optind, argc, argv, env))) {
                    }
                }
                break;
            }
        }
        return err;
    }
    virtual bool fini_paths
    (int optind, int argc, const char_t*const* argv, const char_t*const* env) {
        int err = 0, err2 = 0;
        path::processor::list_t& p = path::processor::processors();
        path::processor::list_t::iterator b = p.begin();
        path::processor::list_t::iterator e = p.end();
        for (path::processor::list_t::iterator i = b; i != e; ++i) {
            if ((err2 = (*i)->fini(optind, argc, argv, env))) {
                if (!err) err = err2;
            }
        }
        return err;
    }
    virtual status_t process_paths
    (signaler_t& restart, signaler_t& stop, response_t& rs, const request_t& rq) {
        status_t status = processing_none;
        path::processor::list_t& p = path::processor::processors();
        path::processor::list_t::iterator b = p.begin();
        path::processor::list_t::iterator e = p.end();

        for (path::processor::list_t::iterator i = b; i != e; ++i) {
            path::processor* p = 0;
            if ((p = (*i))) {
                if (processing_none != (status = (*p)(restart, stop, rs, rq))) {
                    break;
                }
            }
        }
        return status;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool init_methods
    (int optind, int argc, const char_t*const* argv, const char_t*const* env) {
        bool err = 0, err2;
        method::processor::list_t& p = method::processor::processors();
        method::processor::list_t::iterator b = p.begin();
        method::processor::list_t::iterator e = p.end();
        for (method::processor::list_t::iterator i = b; i != e; ++i) {
            if ((err = (*i)->init(optind, argc, argv, env))) {
                for (method::processor::list_t::iterator j = b; j != i; ++j) {
                    if ((err2 = (*i)->fini(optind, argc, argv, env))) {
                    }
                }
                break;
            }
        }
        return err;
    }
    virtual bool fini_methods
    (int optind, int argc, const char_t*const* argv, const char_t*const* env) {
        int err = 0, err2 = 0;
        method::processor::list_t& p = method::processor::processors();
        method::processor::list_t::iterator b = p.begin();
        method::processor::list_t::iterator e = p.end();
        for (method::processor::list_t::iterator i = b; i != e; ++i) {
            if ((err2 = (*i)->fini(optind, argc, argv, env))) {
                if (!err) err = err2;
            }
        }
        return err;
    }
    virtual status_t process_methods
    (signaler_t& restart, signaler_t& stop, response_t& rs, const request_t& rq) {
        status_t status = processing_none;
        method::processor::list_t& p = method::processor::processors();
        method::processor::list_t::iterator b = p.begin();
        method::processor::list_t::iterator e = p.end();

        for (method::processor::list_t::iterator i = b; i != e; ++i) {
            method::processor* p = 0;
            if ((p = (*i))) {
                if (processing_none != (status = (*p)(restart, stop, rs, rq))) {
                    break;
                }
            }
        }
        if (!(status != processing_none)) {
            inet::http::response::status::code::which_t code
            = inet::http::response::status::code::Method_Not_Allowed;
            rs.line().set_code(string_t().assign_unsigned(code).chars());
            rs.combine();
            status = processing_done;
        }
        return status;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace http
} // namespace daemon 
} // namespace server 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_SERVER_DAEMON_HTTP_PROCESSOR_HPP 
