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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 4/14/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_LANGUAGE_TEXTA_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_LANGUAGE_TEXTA_MAIN_OPT_HPP

#include "xos/app/console/main.hpp"

namespace xos {
namespace app {
namespace console {
namespace language {
namespace texta {

/// class main_optt
template <class TExtends = console::main, class TImplements = typename TExtends::implements>
class exported main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    main_optt() {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy): extends(copy) {
    }
public:

protected:
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace texta
} /// namespace language
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_LANGUAGE_TEXTA_MAIN_OPT_HPP 
