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
///   Date: 2/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_PROCESSOR_HPP
#define _MEDUSA_INET_HTTP_PROCESSOR_HPP

#include "medusa/inet/http/response.hpp"
#include "medusa/inet/http/request.hpp"
#include "medusa/mt/mt.hpp"

namespace medusa {
namespace inet {
namespace http {

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

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    enum status {
        processing_done,
        processing_failed,
        processing_continued
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    processort() {
    }
    virtual ~processort() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual status operator()
    (mt::signaler& stop, response::message& rs, const request::message& rq) {
        status done = processing_done;
        return done;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef processort<> processor;

} // namespace http 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_HTTP_PROCESSOR_HPP 
