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
///   File: processors.hpp
///
/// Author: $author$
///   Date: 2/19/2016
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_SERVER_DAEMON_PROCESSORS_HPP
#define _MEDUSA_INET_XTTP_SERVER_DAEMON_PROCESSORS_HPP

#include "medusa/inet/xttp/server/daemon/processor.hpp"

namespace medusa {
namespace inet {
namespace xttp {
namespace server {
namespace daemon {

typedef medusa::mt::signaler signaler;
typedef medusa::inet::xttp::response::message response;
typedef medusa::inet::xttp::request::message request;
typedef processor_implements processors_implements;
typedef processor processors_extends;
///////////////////////////////////////////////////////////////////////
///  Class: processorst
///////////////////////////////////////////////////////////////////////
template
<class TSignaler = signaler, class TResponse = response, class TRequest = request,
 class TImplements = processors_implements, class TExtends = processors_extends>

class _EXPORT_CLASS processorst: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename TExtends::status_t status_t;
    enum {
        processing_none = TExtends::processing_none,
        processing_done = TExtends::processing_done,
        processing_failed = TExtends::processing_failed,
        processing_continued = TExtends::processing_continued
    };
    typedef TSignaler signaler_t;
    typedef TResponse response_t;
    typedef TRequest request_t;

    ///////////////////////////////////////////////////////////////////////
    ///  Class: processor
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS processor: virtual public TImplements, public TExtends {
    public:
        typedef TImplements Implements;
        typedef TExtends Extends;
        typedef typename TExtends::status_t status_t;
        enum {
            processing_none = TExtends::processing_none,
            processing_done = TExtends::processing_done,
            processing_failed = TExtends::processing_failed,
            processing_continued = TExtends::processing_continued
        };
        typedef TSignaler signaler_t;
        typedef TResponse response_t;
        typedef TRequest request_t;
        typedef std::list<processor*> list_t;
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        processor(string_t protocol): protocol_(protocol) {
            add();
        }
        processor() {
            add();
        }
        virtual ~processor() {
            remove();
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual status_t operator()
        (signaler_t& restart, signaler_t& stop, response_t& rs, const request_t& rq) {
            status_t status = processing_none;
            typename request_t::line_t::protocol_t& protocol = rq.line().protocol();
            if (!(protocol_.compare(protocol.name().chars()))) {
                MEDUSA_LOG_MESSAGE_DEBUG("protocol = \"" << protocol_ << "\"...");
                rs.line().set_protocol(protocol);
                status = this->process(restart, stop, rs, rq);
                MEDUSA_LOG_MESSAGE_DEBUG("...protocol = \"" << protocol_ << "\"");
            }
            return status;
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual void add() {
            list_t& p = processors();
            p.push_back(this);
        }
        virtual void remove() {
            list_t& p = processors();
            typename list_t::iterator b = p.begin();
            typename list_t::iterator e = p.end();
            for (typename list_t::iterator i = b; i != e; ++i) {
                if ((*i) == this) {
                    p.erase(i, i);
                    break;
                }
            }
        }
        static list_t& processors() {
            static list_t the_processors;
            return the_processors;
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
        string_t protocol_;
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    processorst() {
    }
    virtual ~processorst() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool init
    (int optind, int argc, const char_t*const* argv, const char_t*const* env) {
        bool err = 0, err2;
        typename processor::list_t& p = processor::processors();
        typename processor::list_t::iterator b = p.begin();
        typename processor::list_t::iterator e = p.end();
        for (typename processor::list_t::iterator i = b; i != e; ++i) {
            if ((err = (*i)->init(optind, argc, argv, env))) {
                for (typename processor::list_t::iterator j = b; j != i; ++j) {
                    if ((err2 = (*i)->fini(optind, argc, argv, env))) {
                    }
                }
                break;
            }
        }
        return err;
    }
    virtual bool fini
    (int optind, int argc, const char_t*const* argv, const char_t*const* env) {
        int err = 0, err2 = 0;
        typename processor::list_t& p = processor::processors();
        typename processor::list_t::iterator b = p.begin();
        typename processor::list_t::iterator e = p.end();
        for (typename processor::list_t::iterator i = b; i != e; ++i) {
            if ((err2 = (*i)->fini(optind, argc, argv, env))) {
                if (!err) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual status_t operator()
    (signaler_t& restart, signaler_t& stop, response_t& rs, const request_t& rq) {
        status_t status = processing_none;
        typename processor::list_t& p = processor::processors();
        typename processor::list_t::iterator b = p.begin();
        typename processor::list_t::iterator e = p.end();
        for (typename processor::list_t::iterator i = b; i != e; ++i) {
            processor* p = 0;
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
};
typedef processorst<> processors;

} // namespace daemon 
} // namespace server 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_SERVER_DAEMON_PROCESSORS_HPP 
