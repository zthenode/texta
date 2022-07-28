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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 6/23/2022
///////////////////////////////////////////////////////////////////////
#ifndef MEDUSA_APP_CONSOLE_MEDUSA_MAIN_OPT_HPP
#define MEDUSA_APP_CONSOLE_MEDUSA_MAIN_OPT_HPP

#include "medusa/console/main.hpp"

namespace medusa {
namespace app {
namespace console {
namespace medusa {

typedef ::medusa::console::main::Implements main_opt_implement;
typedef ::medusa::console::main main_opt_extend;
///////////////////////////////////////////////////////////////////////
/// class main_opt
///////////////////////////////////////////////////////////////////////
class EXPORT_CLASS main_opt: virtual public main_opt_implement, public main_opt_extend {
public:
    typedef main_opt_implement Implements;
    typedef main_opt_extend Extends;
    typedef main_opt Derives;

    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    main_opt() {
    }
    virtual ~main_opt() {
    }
private:
    main_opt(const main_opt& copy) {
    }
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
}; /// class main_opt

} /// namespace medusa 
} /// namespace console 
} /// namespace app 
} /// namespace medusa 

#endif /// ndef MEDUSA_APP_CONSOLE_MEDUSA_MAIN_OPT_HPP 