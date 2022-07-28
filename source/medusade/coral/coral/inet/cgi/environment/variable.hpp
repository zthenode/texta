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
///   File: variable.hpp
///
/// Author: $author$
///   Date: 12/23/2014
///////////////////////////////////////////////////////////////////////
#ifndef _CORAL_INET_CGI_ENVIRONMENT_VARIABLE_HPP
#define _CORAL_INET_CGI_ENVIRONMENT_VARIABLE_HPP
#include "coral/base/base.hpp"

namespace coral {
namespace inet {
namespace cgi {
namespace environment {


///////////////////////////////////////////////////////////////////////
///  Class: variablet
///////////////////////////////////////////////////////////////////////
template
<class TImplements = variablet_implemets, class TExtends = variablet_extends>
class _EXPORT_CLASS variablet: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    variablet() {
    }
    virtual ~variablet() {
    }
};


} // namespace environment 
} // namespace cgi 
} // namespace inet 
} // namespace coral 


#endif // _CORAL_INET_CGI_ENVIRONMENT_VARIABLE_HPP 
        

