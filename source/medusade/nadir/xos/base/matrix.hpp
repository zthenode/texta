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
///   File: matrix.hpp
///
/// Author: $author$
///   Date: 3/11/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_MATRIX_HPP
#define _XOS_NADIR_XOS_BASE_MATRIX_HPP

#include "xos/base/vector.hpp"

namespace xos {
namespace base {

typedef implement_base matrix_implements;
typedef base matrix_extends;
///////////////////////////////////////////////////////////////////////
///  Class: matrixt
///////////////////////////////////////////////////////////////////////
template
<typename TWhat, typename TSize, TSize VRows, TSize VCols,
 class TVector = vectort<TWhat, TSize, VCols>,
 class TExtends = arrayt<TVector, TSize, VRows>,
 class TImplements = matrix_implements>

class _EXPORT_CLASS matrixt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TWhat what_t;
    typedef TSize size_t;
    typedef TVector vector_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    matrixt(const vector_t* vector, size_t length): Extends(length) {
        this->assign(vector, length);
    }
    matrixt(const matrixt& copy): Extends(copy) {}
    matrixt() {}
    virtual ~matrixt() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual vector_t& mul(vector_t& prod, const vector_t& of) {
        size_t rn = this->length();
        vector_t* r = this->elements();
        if ((rn) && (r) && (r[0].length() == of.length())) {
            for (size_t i = 0; i < rn; ++i) {
                r[i].dot(prod[i], of);
            }
        }
        return prod;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

///////////////////////////////////////////////////////////////////////
///  Class: numeric_matrixt
///////////////////////////////////////////////////////////////////////
template
<typename TWhat, size_t VRows, size_t VCols,
 class TExtends = matrixt<TWhat, size_t, VRows, VCols>,
 class TImplements = matrix_implements>

class _EXPORT_CLASS numeric_matrixt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TWhat what_t;
    typedef typename TExtends::vector_t vector_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    numeric_matrixt
    (const vector_t* vector, size_t length): Extends(vector, length) {}
    numeric_matrixt(const numeric_matrixt& copy): Extends(copy) {}
    numeric_matrixt() {}
    virtual ~numeric_matrixt() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

///////////////////////////////////////////////////////////////////////
///  Class: double_matrixt
///////////////////////////////////////////////////////////////////////
template
<size_t VRows, size_t VCols,
 class TExtends = numeric_matrixt<double, VRows, VCols>,
 class TImplements = matrix_implements>

class _EXPORT_CLASS double_matrixt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef double what_t;
    typedef typename TExtends::vector_t vector_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    double_matrixt
    (const vector_t* vector, size_t length): Extends(vector, length) {}
    double_matrixt(const double_matrixt& copy): Extends(copy) {}
    double_matrixt() {}
    virtual ~double_matrixt() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace base
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_MATRIX_HPP 
