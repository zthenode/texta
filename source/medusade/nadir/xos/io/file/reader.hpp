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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 11/9/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_FILE_READER_HPP
#define _XOS_NADIR_XOS_IO_FILE_READER_HPP

#include "xos/io/file/attacher.hpp"
#include "xos/io/reader.hpp"

namespace xos {
namespace io {
namespace file {

///////////////////////////////////////////////////////////////////////
///  Class: reader_implement
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS reader_implement
: virtual public io::reader, virtual public file::attacher {
};

///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<class TImplements = reader_implement,
 typename TWhat = void, typename TSized = char,
 typename TEnd = int, TEnd VEnd = 0,
 typename TAttached = file::attached_t,
 typename TUnattached = file::unattached_t,
 TUnattached VUnattached = file::unattached>

class _EXPORT_CLASS readert: virtual public TImplements {
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
    virtual ssize_t read(what_t* what, size_t size) {
        attached_t f;
        if ((what) && (size) && (f = this->attached_to())) {
            ssize_t count = fread(what, sizeof(sized_t), size, f);
            return count;
        }
        return 0;
    }
    virtual ssize_t fill() {
        attached_t f;
        if ((f = this->attached_to())) {
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t seek(ssize_t offset, int whence) {
        attached_t f;
        if ((f = this->attached_to())) {
            if (!(fseek(f, offset, whence))) {
                ssize_t told = 0;
                if (0 <= (told = ftell(f))) {
                    return told;
                } else {}
            } else {}
        }
        return -1;
    }
    virtual ssize_t tell() {
        attached_t f;
        if ((f = this->attached_to())) {
            ssize_t told = 0;
            if (0 <= (told = ftell(f))) {
                return told;
            } else {}
        }
        return -1;
    }
    virtual ssize_t eof() {
        attached_t f;
        if ((f = this->attached_to())) {
            int end = 0;
            if (0 <= (end = feof(f))) {
                return end;
            } else {}
        }
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t readfv(const char* format, va_list va) {
        attached_t f;
        if ((format) && (f = this->attached_to())) {
            ssize_t count = vfscanf(f, format, va);
            return count;
        }
        return 0;
    }
};
typedef readert<> reader;

///////////////////////////////////////////////////////////////////////
///  Class: char_reader_implement
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS char_reader_implement
: virtual public io::char_reader, virtual public file::attacher {
};
typedef readert<char_reader_implement, char, char> char_reader;

///////////////////////////////////////////////////////////////////////
///  Class: byte_reader_implement
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS byte_reader_implement
: virtual public io::byte_reader, virtual public file::attacher {
};
typedef readert<byte_reader_implement, byte_t, byte_t> byte_reader;

} // namespace file
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_FILE_READER_HPP 
