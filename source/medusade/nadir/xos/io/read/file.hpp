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
///   File: file.hpp
///
/// Author: $author$
///   Date: 11/9/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_READ_FILE_HPP
#define _XOS_NADIR_XOS_IO_READ_FILE_HPP

#include "xos/io/file/reader.hpp"
#include "xos/io/file/opened.hpp"

namespace xos {
namespace io {
namespace read {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS file_implemnents
: virtual public io::file::reader,
  virtual public io::file::opened_implemnents {
};
typedef file::opened file_extends;
///////////////////////////////////////////////////////////////////////
///  Class: filet
///////////////////////////////////////////////////////////////////////
template
<class TImplements = file_implemnents, class TExtends = file_extends>

class _EXPORT_CLASS filet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    filet(FILE* attached = 0, bool is_open = false)
    : Extends(attached, is_open) {
    }
    virtual ~filet() {
        if (!(this->closed())) {
            xos::base::opener_exception e = xos::base::failed_to_close;
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::open;
    virtual bool open(const wchar_t* name) {
        const char* mode = this->mode_read_binary();
        if ((this->open(name, mode))) {
            return true;
        }
        return false;
    }
    virtual bool open(const char* name) {
        const char* mode = this->mode_read_binary();
        if ((this->open(name, mode))) {
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef filet<> file;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS char_file_implemnents
: virtual public io::file::char_reader,
  virtual public io::file::opened_implemnents {
};
typedef filet<char_file_implemnents> char_file;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS byte_file_implemnents
: virtual public io::file::byte_reader,
  virtual public io::file::opened_implemnents {
};
typedef filet<byte_file_implemnents> byte_file;

} // namespace read
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_READ_FILE_HPP 
