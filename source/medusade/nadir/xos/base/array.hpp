///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2015 $organization$
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
///   File: array.hpp
///
/// Author: $author$
///   Date: 1/4/2015, 1/22/20201
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_ARRAY_HPP
#define _XOS_NADIR_XOS_BASE_ARRAY_HPP

#include "xos/base/base.hpp"

#define XOS_ARRAY_DEFAULT_SIZE 128

namespace xos {
namespace base {

typedef implement_base array_implements;
///////////////////////////////////////////////////////////////////////
///  Class: array_implementt
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = char, typename TSize = size_t, 
 TSize VSize = XOS_ARRAY_DEFAULT_SIZE, class TImplements = array_implements>

class _EXPORT_CLASS array_implementt: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TWhat what_t;
    typedef TSize size_t;
    enum { default_size = VSize };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef base array_extends;
///////////////////////////////////////////////////////////////////////
///  Class: arrayt
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = char, 
 typename TSize = size_t, TSize VSize = XOS_ARRAY_DEFAULT_SIZE,
 class TExtends = array_extends, class TImplements = array_implements>

class _EXPORT_CLASS arrayt: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TWhat what_t;
    typedef TSize size_t;
    enum { default_size = VSize };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    arrayt(ssize_t length)
    : elements_(sized_),
      size_(default_size),
      length_(0) {
        set_length(length);
    }
    arrayt(const arrayt& copy)
    : elements_(sized_),
      size_(default_size),
      length_(0) {
        append(copy.elements(), copy.length());
    }
    arrayt()
    : elements_(sized_),
      size_(default_size),
      length_(0) {
    }
    virtual ~arrayt() {
        clear();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t assign(const what_t* elements, size_t elementsLength){
        size_t count = 0;
        size_t newelementsLength;

        if ((!elements) || (!elements_) || (elementsLength < 1))
            return 0;

        if (size_ <= (newelementsLength = (elementsLength)))
        if (0 >= (count = adjust_to_size(new_size(newelementsLength))))
            return count;

        copy_elements(elements_, elements, elementsLength);
        length_ = (count = elementsLength);
        return count;
    }
    virtual size_t append(const what_t* elements, size_t elementsLength){
        size_t count = 0;
        size_t newelementsLength;

        if ((!elements) || (!elements_) || (elementsLength < 1))
            return 0;

        if (size_ <= (newelementsLength = (length_ + elementsLength)))
        if (0 >= (count = adjust_to_size(new_size(newelementsLength))))
            return count;

        copy_elements(elements_+length_, elements, elementsLength);
        length_ += (count = elementsLength);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t set(const what_t& element){
        return set(element, length_);
    }
    virtual size_t set(const what_t& element, size_t elementsLength){
        size_t count = 0;
        size_t newelementsLength;

        if ((!elements_) || (elementsLength < 1))
            return 0;

        if (size_ <= (newelementsLength = (elementsLength)))
        if (0 >= (count = adjust_to_size(new_size(newelementsLength))))
            return count;

        set_elements(elements_, element, elementsLength);
        length_ = (count = elementsLength);
        return count;
    }
    virtual size_t clear(){
        size_t count = length_;
        if (elements_)
        if (elements_ != sized_)
            delete[] elements_;
        elements_ = sized_;
        size_ = default_size;
        length_ = 0;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t set_length(ssize_t toLength){
        size_t toSize;

        if (!elements_)
            return 0;

        if (0 > toLength)
            toLength = default_size;

        if ((toSize = (size_t)(toLength)) >= size_)
        if (toLength > ((ssize_t)(set_size(toSize))))
            return 0;

        length_ = toLength;
        return length_;
    }
    virtual size_t length() const {
        return length_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t set_size(size_t toSize){
        if (toSize != size_) {
            size_t size = 0;
            if (0 < toSize) {
                size = new_size(toSize);
            }
            adjust_to_size(size);
        }
        return size_;
    }
    virtual size_t size() const {
        return size_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual what_t* elements() const {
        return elements_;
    }
    virtual what_t& operator[](size_t index) const {
        return (what_t&)(elements_[index]);
    }
#if !defined(__MSC__)
    virtual operator what_t*() const {
        return (what_t*)(elements_);
    }
#endif // !defined(__MSC__)

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t adjust_to_size(size_t size) {
        size_t count = 0;
        what_t* elements;

        if (!elements_) {
            return 0;
        }

        if (size <= size_) {
            /// 
            /// elements is already big enough
            /// 
            return size_;
        }

        if (!(elements = new what_t[size])) {
            return 0;
        }

        if (elements_) {
            if (length_ > 0) {
                copy_elements(elements, elements_, length_);
            }
            if (elements_ != sized_) {
                delete elements_;
            }
        }

        elements_ = elements;
        size_ = size;
        count = size_;
        return count;
    }
    virtual size_t new_size(size_t size) const {
        size_t count = 0;
        /// 
        /// Increase the buffer size by default buffer
        /// sized chunks. Note the desired new size is always
        /// needed size + 1. The size in chunks is calculated
        /// as (new size + (chunk size - 1)) / chunk size.
        /// since new size = needed size + 1 then we have
        /// chunks = (needed size + chunk size) / chunk size.
        /// Finally we need bytes which is chunks * chunk size
        /// which can be reduced to
        /// ((needed size / chunk size) + 1) * chunk size
        /// 
        count = (size = ((size / default_size) + 1) * default_size);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t set_elements
    (what_t* to, const what_t& from, size_t size) const {
        size_t count = 0;
        if ((to))
        for (count = 0; size > 0; --size, count++)
            (*to++) = from;
        return count;
    }
    virtual size_t copy_elements
    (what_t* to, const what_t* from, size_t size) const {
        size_t count = 0;
        if ((to) && (from))
        for (count = 0; size > 0; --size, count++)
            (*to++) = (*from++);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    what_t sized_[default_size], *elements_;
    size_t size_, length_;
};
typedef arrayt<> array;

typedef arrayt<char_t> char_array;
typedef arrayt<wchar_t> wchar_array;
typedef arrayt<tchar_t> tchar_array;

typedef arrayt<byte_t> byte_array;
typedef arrayt<word_t> word_array;

} // namespace base
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_ARRAY_HPP 
