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
///   File: function_argument.hpp
///
/// Author: $author$
///   Date: 3/21/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_FUNCTION_ARGUMENT_HPP
#define _TEXTA_T_FUNCTION_ARGUMENT_HPP

#include "texta/t/function_argument_item.hpp"
#include "texta/t/t.hpp"

namespace texta {
namespace t {

/*typedef string function_argument_extends;
///////////////////////////////////////////////////////////////////////
///  Class: function_argument_implements
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS function_argument_implements
: virtual public output, virtual public input {
};*/
typedef result_implements function_argument_implements;
typedef result function_argument_extends;
///////////////////////////////////////////////////////////////////////
///  Class: function_argument
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS function_argument
: virtual public function_argument_implements, public function_argument_extends {
public:
    typedef function_argument_implements Implements;
    typedef function_argument_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    function_argument(): item_(*this)/*, tell_(0)*/ {
    }
    virtual ~function_argument() {
    }
    /*///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t write(const char* out, ssize_t length) {
        this->append(out, length);
        return length;
    }
    virtual ssize_t read(char* in, size_t size) {
        ssize_t count = 0;
        if (size) {
            const char* chars = 0;
            if ((chars = this->chars())) {
                size_t length = this->length();
                if (tell_ + size > length) {
                    size = length - tell_;
                }
                if (size) {
                    chars_t::copy(in, chars + tell_, size);
                    tell_ += size;
                    count = size;
                }
            }
        }
        return count;
    }
    virtual size_t seek(size_t size) {
        size_t length = this->length();
        if (size > length) {
            size = length;
        }
        tell_ = size;
        return tell_;
    }*/
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual function_argument* next_argument() const {
        function_argument* arg = 0;
        function_argument_item* item = 0;
        if ((item = this->item().next())) {
            //arg = &item->what();
            arg = &((function_argument&)(item->what()));
        }
        return arg;
    }
    virtual function_argument_item& item() const {
        return (function_argument_item&)item_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    function_argument_item item_;
    //size_t tell_;
};

} // namespace t
} // namespace texta 

#endif // _TEXTA_T_FUNCTION_ARGUMENT_HPP 
