///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
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
///   File: main.hpp
///
/// Author: $author$
///   Date: 2/27/2021
///////////////////////////////////////////////////////////////////////
#ifndef TEXTA_APP_CGI_CATCHER_MAIN_HPP
#define TEXTA_APP_CGI_CATCHER_MAIN_HPP

#include "coral/app/cgi/catcher/main.hpp"

namespace texta {
namespace app {
namespace cgi {
namespace catcher {

///////////////////////////////////////////////////////////////////////
/// class maint
///////////////////////////////////////////////////////////////////////
template <class TExtends = coral::app::cgi::catcher::main, class TImplements = typename TExtends::Implements>
class EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef maint Derives;

    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    maint() {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy): Extends(copy) {
    }
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
}; /// class maint
typedef maint<> main;

} /// namespace catcher 
} /// namespace cgi 
} /// namespace app 
} /// namespace texta 

#endif /// ndef TEXTA_APP_CGI_CATCHER_MAIN_HPP 