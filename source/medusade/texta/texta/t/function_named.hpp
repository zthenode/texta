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
///   File: function_named.hpp
///
/// Author: $author$
///   Date: 5/23/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_FUNCTION_NAMED_HPP
#define _TEXTA_T_FUNCTION_NAMED_HPP

#include "texta/t/function_branch.hpp"
#include "texta/t/function_item.hpp"
#include "texta/t/function.hpp"

namespace texta {
namespace t {

typedef function function_named_implements;
typedef base function_named_extends;
///////////////////////////////////////////////////////////////////////
///  Class: function_named
///////////////////////////////////////////////////////////////////////
class function_named
: virtual public function_named_implements, public function_named_extends {
public:
    typedef function_named_implements Implements;
    typedef function_named_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    function_named(const string& name)
    : item_(*this), branch_(*this), name_(name) {
    }
    function_named
    (const function_named& copy)
    : item_(*this), branch_(*this), name_(copy.name()) {
    }
    virtual ~function_named() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool init(processor &p) {
        return false;
    }
    virtual bool fini(processor &p) {
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const function_argument_list &args) const {
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_name(const char* to) const {
        return name_.compare(to);
    }
    virtual const char *name() const {
        return name_.chars();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::description;
    virtual const char *description
    (const function_parameter *&parameter, size_t &parameters) const {
        parameter = 0;
        parameters = 0;
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::parameter;
    virtual const function_parameter* parameter(size_t &parameters) const {
        parameters = 0;
        return 0;
    }
    virtual size_t parameters() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual function_item& item() const {
        return (function_item&)item_;
    }
    virtual function_branch& branch() const {
        return (function_branch&)branch_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    function_item item_;
    function_branch branch_;
    string name_;
};

} // namespace t
} // namespace texta

#endif // _TEXTA_T_FUNCTION_NAMED_HPP
