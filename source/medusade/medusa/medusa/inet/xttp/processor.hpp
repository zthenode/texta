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
///   Date: 2/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_XTTP_PROCESSOR_HPP
#define _MEDUSA_INET_XTTP_PROCESSOR_HPP

#include "medusa/inet/xttp/response/message.hpp"
#include "medusa/inet/xttp/request/message.hpp"
#include "medusa/inet/xttp/xttp.hpp"
#include "medusa/mt/mt.hpp"
#include "medusa/base/base.hpp"

namespace medusa {
namespace inet {
namespace xttp {

typedef implement_base processor_implements;
typedef base processor_extends;
///////////////////////////////////////////////////////////////////////
///  Class: processort
///////////////////////////////////////////////////////////////////////
template
<class TImplements = processor_implements, class TExtends = processor_extends>

class _EXPORT_CLASS processort: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef int status;
    enum {
        processing_none,
        processing_done,
        processing_failed,
        processing_continued
    };
    typedef status status_t;
    typedef inet::xttp::response::message response_t;
    typedef inet::xttp::request::message request_t;
    typedef mt::signaler signaler_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    processort() {
    }
    virtual ~processort() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual status_t operator()
    (signaler_t& restart, signaler_t& stop, response_t& rs, const request_t& rq) {
        return processing_none;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef processort<> processor;

} // namespace xttp 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_XTTP_PROCESSOR_HPP 
