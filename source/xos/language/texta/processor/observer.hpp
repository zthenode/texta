///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
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
///   File: observer.hpp
///
/// Author: $author$
///   Date: 4/14/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_LANGUAGE_TEXTA_PROCESSOR_OBSERVER_HPP
#define XOS_LANGUAGE_TEXTA_PROCESSOR_OBSERVER_HPP

#include "xos/language/texta/processor/exception.hpp"

namespace xos {
namespace language {
namespace texta {
namespace processor {

class exported implement;

/// class observert
template <class TProcessor = processor::implement, class TImplements = xos::implement>
class exported observert: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef observert derives;

    typedef TProcessor processor_t;
    typedef processor::exception exception_t;
    
    /// on_processor_exception
    virtual void on_processor_exception(processor_t& p, const exception_t& e) {
    }
}; /// class observert
typedef observert<> observer;

} /// namespace processor
} /// namespace texta
} /// namespace language
} /// namespace xos

#endif /// ndef XOS_LANGUAGE_TEXTA_PROCESSOR_OBSERVER_HPP 
