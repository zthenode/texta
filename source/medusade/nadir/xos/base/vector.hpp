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
///   File: vector.hpp
///
/// Author: $author$
///   Date: 3/11/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_VECTOR_HPP
#define _XOS_NADIR_XOS_BASE_VECTOR_HPP

#include "xos/base/array.hpp"

namespace xos {
namespace base {

typedef implement_base vector_implements;
typedef base vector_extends;
///////////////////////////////////////////////////////////////////////
///  Class: vectort
///////////////////////////////////////////////////////////////////////
template
<typename TWhat, typename TSize, TSize VSize,
 class TExtends = arrayt<TWhat, TSize, VSize>,
 class TImplements = vector_implements>

class _EXPORT_CLASS vectort: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TWhat what_t;
    typedef TSize size_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    vectort(const what_t& what, size_t length): Extends(length) {
        this->assign(&what, length);
    }
    vectort(size_t length): Extends(length) {}
    vectort(const vectort& copy): Extends(copy) {}
    vectort() {}
    virtual ~vectort() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual what_t& dot(what_t& prod, const vectort& of) const {
        size_t an = this->length(), bn = of.length();
        const what_t *a = this->elements(), *b = of.elements();
        if ((a) && (b) && (an) && (bn) && (an == bn)) {
            prod = a[0]*b[0];
            for (size_t i = 1; i < an; ++i) {
                prod += a[i]*b[i];
            }
        }
        return prod;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual vectort& operator = (const vectort& copy) {
        const what_t* what = copy.elements();
        size_t length = copy.length();
        if ((what) && (length)) {
            this->assign(what, length);
        }
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

///////////////////////////////////////////////////////////////////////
///  Class: numeric_vectort
///////////////////////////////////////////////////////////////////////
template
<typename TWhat, size_t VSize,
 class TExtends = vectort<TWhat, size_t, VSize>,
 class TImplements = vector_implements>

class _EXPORT_CLASS numeric_vectort: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TWhat what_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    numeric_vectort(const what_t& what, size_t length): Extends(what, length) {}
    numeric_vectort(size_t length): Extends(length) {}
    numeric_vectort(const numeric_vectort& copy): Extends(copy) {}
    numeric_vectort() {}
    virtual ~numeric_vectort() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

///////////////////////////////////////////////////////////////////////
///  Class: double_vectort
///////////////////////////////////////////////////////////////////////
template
<size_t VSize,
 class TExtends = numeric_vectort<double, VSize>,
 class TImplements = vector_implements>

class _EXPORT_CLASS double_vectort: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef double what_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    double_vectort(const what_t& what, size_t length): Extends(what, length) {}
    double_vectort(size_t length): Extends(length) {}
    double_vectort(const double_vectort& copy): Extends(copy) {}
    double_vectort() {}
    virtual ~double_vectort() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace base
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_VECTOR_HPP 
