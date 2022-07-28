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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 1/12/2015
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_INET_HTTP_CONTENT_READER_HPP
#define _MEDUSA_INET_HTTP_CONTENT_READER_HPP

#include "medusa/io/reader.hpp"

namespace medusa {
namespace inet {
namespace http {
namespace content {

namespace read {
typedef implement_base observer_implements;
///////////////////////////////////////////////////////////////////////
///  Class: observert
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = void, typename TSized = char,
 class TImplements = observer_implements>

class _EXPORT_CLASS observert: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TWhat what_t;
    typedef TSized sized_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_read_content
    (const what_t* what, const sized_t* sized, size_t size) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef observert<> observer;
} // namespace read

typedef base reader_extends;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = void, typename TSized = char,
 typename TEnd = int, TEnd VEnd = 0,
 class TReader = xos::io::readert<TWhat, TSized, TEnd, VEnd>,
 class TObserver = read::observert<TWhat, TSized>,
 class TImplements = TReader, class TExtends = reader_extends>

class _EXPORT_CLASS readert: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TObserver observer_t;
    typedef TReader reader_t;
    typedef TWhat what_t;
    typedef TSized sized_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    readert(observer_t& observer, reader_t& reader, size_t length)
    : reader_(reader), length_(length), tell_(0), observer_(&observer) {
    }
    readert(reader_t& reader, size_t length)
    : reader_(reader), length_(length), tell_(0), observer_(0) {
    }
    virtual ~readert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read(what_t* what, size_t size) {
        sized_t* sized = 0;
        if ((sized = ((sized_t*)what)) && (size)) {
            if (length_ < (tell_ + size)) {
                size = tell_ - length_;
            }
            if ((size)) {
                ssize_t count = 0;
                if (0 < (count = reader_.read(what, size))) {
                    if ((observer_)) {
                        observer_->on_read_content(what, sized, size);
                    }
                    tell_ += count;
                }
                return count;
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    reader_t& reader_;
    size_t length_, tell_;
    observer_t* observer_;
};
typedef readert<> reader;

} // namespace content 
} // namespace http 
} // namespace inet 
} // namespace medusa 

#endif // _MEDUSA_INET_HTTP_CONTENT_READER_HPP 
