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
///   Date: 2/19/2016
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_SERVER_DAEMON_PROCESSOR_HPP
#define _MEDUSA_INET_XTTP_SERVER_DAEMON_PROCESSOR_HPP

#include "medusa/inet/xttp/processor.hpp"

namespace medusa {
namespace inet {
namespace xttp {
namespace server {
namespace daemon {

typedef medusa::mt::signaler signaler;
typedef medusa::inet::xttp::response::message response;
typedef medusa::inet::xttp::request::message request;
typedef medusa::inet::xttp::processor_implements processor_implements;
typedef medusa::inet::xttp::processor processor_extends;
///////////////////////////////////////////////////////////////////////
///  Class: processort
///////////////////////////////////////////////////////////////////////
template
<class TSignaler = signaler, class TResponse = response, class TRequest = request,
 class TImplements = processor_implements, class TExtends = processor_extends>

class _EXPORT_CLASS processort: virtual public TImplements, public TExtends {
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
    ///////////////////////////////////////////////////////////////////////
    processort() {
    }
    virtual ~processort() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool init
    (int optind, int argc, const char_t*const* argv, const char_t*const* env) {
        bool err = 0;
        return err;
    }
    virtual bool fini
    (int optind, int argc, const char_t*const* argv, const char_t*const* env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual status_t process
    (signaler_t& restart, signaler_t& stop, response_t& rs, const request_t& rq) {
        return processing_none;
    }
    virtual status_t operator()
    (signaler_t& restart, signaler_t& stop, response_t& rs, const request_t& rq) {
        return processing_none;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef processort<> processor;

namespace named {
typedef daemon::processor::Implements processor_implements;
typedef daemon::processor processor_extends;
///////////////////////////////////////////////////////////////////////
///  Class: processort
///////////////////////////////////////////////////////////////////////
template
<class TDerives,
 class TImplements = processor_implements, class TExtends = processor_extends>
class _EXPORT_CLASS processort: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TDerives processor_t;
    typedef string_t name_t;
    typedef std::list<processor_t*> list_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    processort(const wchar_t* name): name_(name) {
    }
    processort(const char_t* name): name_(name) {
    }
    virtual ~processort() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void add(processor_t* this_p) {
        list_t& p = processors();
        p.push_back(this_p);
    }
    virtual void remove(processor_t* this_p) {
        list_t& p = processors();
        typename list_t::iterator b = p.begin();
        typename list_t::iterator e = p.end();
        for (typename list_t::iterator i = b; i != e; ++i) {
            if ((*i) == this_p) {
                p.erase(i, i);
                break;
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static list_t& processors() {
        static list_t the_processors;
        return the_processors;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual name_t& set_name(const wchar_t* to) {
        name_.assign(to);
        return name_;
    }
    virtual name_t& set_name(const char_t* to) {
        name_.assign(to);
        return name_;
    }
    virtual name_t& name() const {
        return (name_t&)name_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    name_t name_;
};
} // namespace named

} // namespace daemon
} // namespace server 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_SERVER_DAEMON_PROCESSOR_HPP 
