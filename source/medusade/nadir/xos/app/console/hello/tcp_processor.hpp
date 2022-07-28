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
///   File: tcp_processor.hpp
///
/// Author: $author$
///   Date: 12/12/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_APP_CONSOLE_HELLO_TCP_PROCESSOR_HPP
#define _XOS_NADIR_XOS_APP_CONSOLE_HELLO_TCP_PROCESSOR_HPP

#include "xos/app/console/hello/tcp_connections.hpp"
#include "xos/app/console/hello/response.hpp"
#include "xos/app/console/hello/request.hpp"
#include "xos/app/console/hello/base.hpp"

namespace xos {
namespace app {
namespace console {
namespace hello {

///////////////////////////////////////////////////////////////////////
///  Class: tcp_processor
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS tcp_processor {
public:
    enum status {
        processing_done,
        processing_failed,
        processing_continued
    };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    tcp_processor
    (const string_t& bye_message, const string_t& hello_message,
     int optind, int argc, const char_t*const* argv, const char_t*const* env)
    : bye_message_(bye_message), hello_message_(hello_message),
      optind_(optind), argc_(argc), argv_(argv), env_(env) {
    }
    virtual ~tcp_processor() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual status operator()
    (network::socket& s, const request& rq) {
        status done = processing_done;
        const char_t* chars = 0;
        size_t length = 0;
        if (!(bye_message_.compare(rq.line()))) {
            chars = bye_message_.has_chars(length);
        } else {
            if (!(hello_message_.compare(rq.line()))) {
                chars = hello_message_.has_chars(length);
            } else {
            }
        }
        if ((chars)) {
            response rs;
            if ((rs.on_write_start())) {
                XOS_LOG_MESSAGE_DEBUG("line = \"" << chars << "\"");
                if ((rs.on_write_line(chars, length))) {
                    for (int i = optind_; i < argc_; ++i) {
                        if ((chars = argv_[i]) && (chars[0])
                            && (length = (chars_t::count(chars)))) {
                            XOS_LOG_MESSAGE_DEBUG("header = \"" << chars << "\"");
                            if (!(rs.on_write_header(chars, length))) {
                                return processing_failed;
                            }
                        }
                    }
                    request::list_t::const_iterator end = rq.headers().end();
                    for (request::list_t::const_iterator i = rq.headers().begin(); i != end; ++i) {
                        const string_t& header = *i;
                        if ((chars = header.has_chars(length))) {
                            XOS_LOG_MESSAGE_DEBUG("header \"" << chars << "\"");
                            if (!(rs.on_write_header(chars, length))) {
                                return processing_failed;
                            }
                        }
                    }
                    if ((rs.on_write_finish())) {
                        if ((chars = rs.has_chars(length))) {
                            XOS_LOG_MESSAGE_DEBUG("send \"" << chars << "\"...");
                            if (length <= (s.send(chars, length, 0))) {
                                XOS_LOG_MESSAGE_DEBUG("...sent \"" << chars << "\"");
                                return done;
                            } else {
                                XOS_LOG_MESSAGE_DEBUG("...failed to send \"" << chars << "\"");
                            }
                        }
                    }
                }
            }
        }
        return processing_failed;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const string_t& bye_message_, & hello_message_;
    int optind_, argc_;
    const char_t *const* argv_, *const* env_;
};

} // namespace hello 
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_NADIR_XOS_APP_CONSOLE_HELLO_TCP_PROCESSOR_HPP 
