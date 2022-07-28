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
///   File: file_or_buffer.hpp
///
/// Author: $author$
///   Date: 4/4/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_READ_FILE_OR_BUFFER_HPP
#define _XOS_NADIR_XOS_IO_READ_FILE_OR_BUFFER_HPP

#include "xos/io/read/buffer.hpp"
#include "xos/io/read/file.hpp"

namespace xos {
namespace io {
namespace read {

typedef io::reader file_or_buffer_reader;
typedef io::tellert<file_or_buffer_reader> file_or_buffer_teller;
typedef io::whencert<file_or_buffer_teller> file_or_buffer_whencer;
typedef io::seekert<file_or_buffer_whencer> file_or_buffer_seeker;
typedef read::filet<file_implemnents> file_or_buffer_file;
typedef io::buffert
<void, char, file_or_buffer_seeker> file_or_buffer_buffer_extend;
typedef read::buffert
<void, char, file_or_buffer_seeker,
 file_or_buffer_buffer_extend> file_or_buffer_buffer;
typedef file_or_buffer_seeker file_or_buffer_implements;
typedef base::base file_or_buffer_extends;
///////////////////////////////////////////////////////////////////////
///  Class: file_or_buffert
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = void, typename TSized = char,
 class TFile = file_or_buffer_file, class TBuffer = file_or_buffer_buffer,
 class TImplements = file_or_buffer_implements,
 class TExtends = file_or_buffer_extends>

class _EXPORT_CLASS file_or_buffert
: virtual public TImplements,  public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef file_or_buffert Derives;

    typedef TFile file_t;
    typedef TBuffer buffer_t;
    typedef TWhat what_t;
    typedef TSized sized_t;
    typedef typename Implements::whence_t whence_t;

    typedef ssize_t (Derives::*read_t)(what_t* what, size_t size);
    typedef ssize_t (Derives::*seek_t)(ssize_t offset, whence_t whence);
    typedef ssize_t (Derives::*tell_t)();
    typedef ssize_t (Derives::*eof_t)();

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    file_or_buffert()
    : read_(0), seek_(0), tell_(0), eof_(0) {
    }
    virtual ~file_or_buffert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool open(const char* name) {
        if ((open(name, file_.mode_read_binary()))) {
            return true;
        }
        return false;
    }
    virtual bool open(const char* name, const char* mode) {
        close();
        if ((file_.open(name, mode))) {
            read_ = &Derives::file_read;
            seek_ = &Derives::file_seek;
            tell_ = &Derives::file_tell;
            eof_ = &Derives::file_eof;
            return true;
        }
        return false;
    }
    virtual bool open(const sized_t* detached, ssize_t length) {
        close();
        if ((attach(detached, length))) {
            return true;
        }
        return false;
    }
    virtual bool close() {
        file_.close();
        detach();
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const sized_t* attach(const sized_t* detached, ssize_t length) {
        close();
        if ((buffer_.set_in(detached, length))) {
            read_ = &Derives::buffer_read;
            seek_ = &Derives::buffer_seek;
            tell_ = &Derives::buffer_tell;
            eof_ = &Derives::buffer_eof;
            return detached;
        }
        return 0;
    }
    virtual const sized_t* detach(ssize_t& length) {
        const sized_t* detached = buffer_.in(length);
        buffer_.set_in(0, 0);
        read_ = (0); seek_ = (0); tell_ = (0); eof_ = (0);
        return detached;
    }
    virtual const sized_t* detach() {
        const sized_t* detached = buffer_.in();
        buffer_.set_in(0, 0);
        read_ = (0); seek_ = (0); tell_ = (0); eof_ = (0);
        return detached;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t file_read(what_t* what, size_t size) {
        return file_.read(what, size);
    }
    virtual ssize_t file_seek(ssize_t offset, whence_t whence) {
        return file_.seek(offset, whence);
    }
    virtual ssize_t file_tell() {
        return file_.tell();
    }
    virtual ssize_t file_eof() {
        return file_.eof();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t buffer_read(what_t* what, size_t size) {
        return buffer_.read(what, size);
    }
    virtual ssize_t buffer_seek(ssize_t offset, whence_t whence) {
        return buffer_.seek(offset, whence);
    }
    virtual ssize_t buffer_tell() {
        return buffer_.tell();
    }
    virtual ssize_t buffer_eof() {
        return buffer_.eof();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read(what_t* what, size_t size) {
        if ((this->read_)) {
            return (this->*read_)(what, size);
        }
        return 0;
    }
    virtual ssize_t seek(ssize_t offset, whence_t whence) {
        if ((this->seek_)) {
            return (this->*seek_)(offset, whence);
        }
        return -1;
    }
    virtual ssize_t tell() {
        if ((this->tell_)) {
            return (this->*tell_)();
        }
        return -1;
    }
    virtual ssize_t eof() {
        if ((this->eof_)) {
            return (this->*eof_)();
        }
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    file_t file_;
    buffer_t buffer_;
    read_t read_;
    seek_t seek_;
    tell_t tell_;
    eof_t eof_;
};

// char
typedef io::char_reader char_file_or_buffer_reader;
typedef io::tellert<char_file_or_buffer_reader> char_file_or_buffer_teller;
typedef io::whencert<char_file_or_buffer_teller> char_file_or_buffer_whencer;
typedef io::seekert<char_file_or_buffer_whencer> char_file_or_buffer_seeker;
typedef char_file_or_buffer_seeker char_file_or_buffer_implements;
typedef read::filet<char_file_implemnents> char_file_or_buffer_file;
typedef io::buffert
<char, char,
 char_file_or_buffer_seeker> char_file_or_buffer_buffer_extend;
typedef read::buffert
<char, char, char_file_or_buffer_seeker,
 char_file_or_buffer_buffer_extend> char_file_or_buffer_buffer;
typedef file_or_buffert
<char, char,
 char_file_or_buffer_file, char_file_or_buffer_buffer,
 char_file_or_buffer_implements> char_file_or_buffer;

// byte
typedef io::byte_reader byte_file_or_buffer_reader;
typedef io::tellert<byte_file_or_buffer_reader> byte_file_or_buffer_teller;
typedef io::whencert<byte_file_or_buffer_teller> byte_file_or_buffer_whencer;
typedef io::seekert<byte_file_or_buffer_whencer> byte_file_or_buffer_seeker;
typedef byte_file_or_buffer_seeker byte_file_or_buffer_implements;
typedef read::filet<byte_file_implemnents> byte_file_or_buffer_file;
typedef io::buffert
<byte_t, byte_t,
 byte_file_or_buffer_seeker> byte_file_or_buffer_buffer_extend;
typedef read::buffert
<byte_t, byte_t, byte_file_or_buffer_seeker,
 byte_file_or_buffer_buffer_extend> byte_file_or_buffer_buffer;
typedef file_or_buffert
<byte_t, byte_t,
 byte_file_or_buffer_file, byte_file_or_buffer_buffer,
 byte_file_or_buffer_implements> byte_file_or_buffer;

} // namespace read
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_READ_FILE_OR_BUFFER_HPP 
