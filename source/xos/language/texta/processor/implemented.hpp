///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
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
///   File: implemented.hpp
///
/// Author: $author$
///   Date: 7/26/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_LANGUAGE_TEXTA_PROCESSOR_IMPLEMENTED_HPP
#define XOS_LANGUAGE_TEXTA_PROCESSOR_IMPLEMENTED_HPP

#include "xos/language/texta/processor/implement.hpp"

namespace xos {
namespace language {
namespace texta {
namespace processor {

/// class implementedt
template <class TExtends = processor::extend, class TImplements = typename TExtends::implements>
class exported implementedt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef implementedt derives; 
    
    /// constructors / destructor
    implementedt(const implementedt& copy): extends(copy) {
    }
    implementedt() {
    }
    virtual ~implementedt() {
    }
}; /// class implementedt
typedef implementedt<> implemented;

} /// namespace processor
} /// namespace texta
} /// namespace language
} /// namespace xos

#endif /// ndef XOS_LANGUAGE_TEXTA_PROCESSOR_IMPLEMENTED_HPP
