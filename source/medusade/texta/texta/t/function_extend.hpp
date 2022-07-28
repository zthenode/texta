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
///   File: function_extend.hpp
///
/// Author: $author$
///   Date: 3/20/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_FUNCTION_EXTEND_HPP
#define _TEXTA_T_FUNCTION_EXTEND_HPP

#include "texta/t/variable.hpp"
#include "texta/t/function_argument.hpp"
#include "texta/t/function_parameter.hpp"
#include "texta/t/function_tree.hpp"
#include "texta/t/function_list.hpp"
#include "texta/t/function.hpp"
#include "texta/io/logger.hpp"
#include "xos/base/string.hpp"

namespace texta {
namespace t {

typedef function function_implements;
typedef base function_extends;
///////////////////////////////////////////////////////////////////////
///  Class: function_extend
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS function_extend
: virtual public function_implements, public function_extends {
public:
    typedef function_implements Implements;
    typedef function_extends Extends;
    typedef function Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
private:
    function_extend
    (const function_extend& copy)
    : item_(*this), branch_(*this),
      name_(copy.name()), description_(copy.description()),
      parameter_(copy.parameter()), parameters_(copy.parameters()) {
    }
public:
    function_extend
    (const char *name, const char *description,
     const function_parameter *parameter = 0, size_t parameters = 0)
    : item_(*this), branch_(*this),
      name_(name), description_(description),
      parameter_(parameter), parameters_(parameters) {
        function_list& the_list = function_list::the_list();
        the_list.queue(this->item());
    }
    virtual ~function_extend() {
        function_list& the_list = function_list::the_list();
        the_list.remove(this->item());
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool init(processor &p) {
        return true;
    }
    virtual bool fini(processor &p) {
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const function_argument_list &args) const {
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare_name(const char* to) const {
        return name_.compare(to);
    }
    virtual const char *name() const {
        return name_.chars();
    }
    using Implements::description;
    virtual const char *description
    (const function_parameter *&parameter, size_t &parameters) const {
        parameter = parameter_;
        parameters = parameters_;
        return description_.chars();
    }
    using Implements::parameter;
    virtual const function_parameter* parameter(size_t &parameters) const {
        parameters = parameters_;
        return parameter_;
    }
    virtual size_t parameters() const {
        return parameters_;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void set_parameter(const function_parameter *to) {
        parameters_ = 0;
        if ((parameter_ = to)) {
            while ((to++)->name()) {
                ++parameters_;
            }
        }
    }

public:
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
    string name_, description_;
    const function_parameter *parameter_;
    size_t parameters_;
};

} // namespace t 
} // namespace texta 

#endif // _TEXTA_T_FUNCTION_EXTEND_HPP 
