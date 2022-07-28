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
///   File: writer.hpp
///
/// Author: $author$
///   Date: 9/7/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_FILE_WRITER_HPP
#define _XOS_NADIR_XOS_IO_FILE_WRITER_HPP

#include "xos/io/file/attacher.hpp"
#include "xos/io/writer.hpp"

namespace xos {
namespace io {
namespace file {

///////////////////////////////////////////////////////////////////////
///  Class: writer_implement
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS writer_implement
: virtual public io::writer,
  virtual public file::attacher {};

///////////////////////////////////////////////////////////////////////
///  Class: writert
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = void, typename TSized = char,
 typename TEnd = int, TEnd VEnd = 0,
 typename TAttached = file::attached_t,
 typename TUnattached = file::unattached_t,
 TUnattached VUnattached = file::unattached,
 class TImplements = writer_implement>

class _EXPORT_CLASS writert: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TWhat what_t;
    typedef TSized sized_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t write(const what_t* what, ssize_t size = -1) {
        attached_t f;
        if ((what) && (size) && (f = this->attached_to())) {
            ssize_t count = 0;
            ssize_t amount = 0;
            if (0 > (size)) {
                for (const sized_t* sized = (const sized_t*)(what); *sized != end; ++sized) {
                    if (1 != (amount = fwrite(sized, sizeof(sized_t), 1, f))) {
                        return amount;
                    }
                    count += amount;
                }
            } else {
                count = fwrite(what, sizeof(sized_t), size, f);
            }
            return count;
        }
        return 0;
    }
    virtual ssize_t flush() {
        attached_t f;
        if ((f = this->attached_to())) {
            int err;
            if ((err = fflush(f))) {
                return -1;
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t writefv(const void* format, va_list va) {
        ssize_t count = writefv((const char*)(format), va);
        return count;
    }
    virtual ssize_t writefv(const char* format, va_list va) {
        attached_t f;
        if ((format) && (f = this->attached_to())) {
            ssize_t count = vfprintf(f, format, va);
            return count;
        }
        return 0;
    }
};
typedef writert<> writer;

} // namespace file 
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_FILE_WRITER_HPP 
