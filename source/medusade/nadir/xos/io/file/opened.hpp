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
///   File: opened.hpp
///
/// Author: $author$
///   Date: 11/9/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_FILE_OPENED_HPP
#define _XOS_NADIR_XOS_IO_FILE_OPENED_HPP

#include "xos/io/file/attached.hpp"
#include "xos/io/file/attacher.hpp"
#include "xos/io/logger.hpp"
#include "xos/base/opened.hpp"
#include "xos/base/opener.hpp"
#include "xos/base/string.hpp"
#include "xos/base/to_string.hpp"

#define XOS_NADIR_XOS_IO_FILE_MODE_READ "r"
#define XOS_NADIR_XOS_IO_FILE_MODE_WRITE "w"
#define XOS_NADIR_XOS_IO_FILE_MODE_APPEND "w+"

#define XOS_NADIR_XOS_IO_FILE_MODE_READ_BINARY "rb"
#define XOS_NADIR_XOS_IO_FILE_MODE_WRITE_BINARY "wb"
#define XOS_NADIR_XOS_IO_FILE_MODE_APPEND_BINARY "wb+"

namespace xos {
namespace io {
namespace file {

typedef base::openert<attacher> opened_implemnents;
typedef base::openedt
<attached_t, unattached_t, unattached,
 opened_implemnents, attached> opened_extends;
///////////////////////////////////////////////////////////////////////
///  Class: openedt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TEnd = TChar, TEnd VEnd = 0,
 class TString = base::stringt<TChar, TEnd, VEnd>,
 class TImplements = opened_implemnents, class TExtends = opened_extends>

class _EXPORT_CLASS openedt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    openedt
    (FILE* attached = 0, bool is_open = false)
    : TExtends(attached, is_open),
      mode_read_(XOS_NADIR_XOS_IO_FILE_MODE_READ),
      mode_write_(XOS_NADIR_XOS_IO_FILE_MODE_WRITE),
      mode_append_(XOS_NADIR_XOS_IO_FILE_MODE_APPEND),
      mode_read_binary_(XOS_NADIR_XOS_IO_FILE_MODE_READ_BINARY),
      mode_write_binary_(XOS_NADIR_XOS_IO_FILE_MODE_WRITE_BINARY),
      mode_append_binary_(XOS_NADIR_XOS_IO_FILE_MODE_APPEND_BINARY) {
    }
    virtual ~openedt() {
        if (!(this->closed())) {
            xos::base::opener_exception e = xos::base::failed_to_close;
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool open
    (const wchar_t* name, const wchar_t* mode) {
        if ((name) && (mode)) {
            xos::base::string s_name(name), s_mode(mode);
            return open(s_name.chars(), s_mode.chars());
        }
        return false;
    }
    virtual bool open
    (const wchar_t* name, const char* mode) {
        if ((name) && (mode)) {
            xos::base::string s_name(name);
            return open(s_name.chars(), mode);
        }
        return false;
    }
    virtual bool open
    (const char* name, const char* mode) {
        if ((name) && (mode)) {
            if ((this->closed())) {
                FILE* detached = 0;
                XOS_LOG_DEBUG("::fopen(name = \"" << name << "\", mode = \"" << mode << "\")...");
                if ((detached = fopen(name, mode))) {
                    XOS_LOG_DEBUG("..." << pointer_to_string(detached) << " = ::fopen(name = \"" << name << "\", mode = \"" << mode << "\")");
                    this->attach_opened(detached);
                    return true;
                } else {
                    XOS_LOG_ERROR("...failed " << errno << " on ::fopen(\"" << name << "\", \"" << mode << "\")")
                }
            }
        }
        return false;
    }
    virtual bool close() {
        FILE* detached = 0;
        if ((detached = this->detach())) {
            int err = 0;
            if (!(err = fclose(detached))) {
                return true;
            } else {
                XOS_LOG_ERROR("...failed " << errno << " on ::fclose()");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* mode_read() const {
        return mode_read_.chars();
    }
    virtual const char_t* mode_write() const {
        return mode_write_.chars();
    }
    virtual const char_t* mode_append() const {
        return mode_append_.chars();
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* mode_read_binary() const {
        return mode_read_binary_.chars();
    }
    virtual const char_t* mode_write_binary() const {
        return mode_write_binary_.chars();
    }
    virtual const char_t* mode_append_binary() const {
        return mode_append_binary_.chars();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const string_t mode_read_, mode_write_, mode_append_,
                   mode_read_binary_, mode_write_binary_, mode_append_binary_;
};
typedef openedt<> opened;

} // namespace file 
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_FILE_OPENED_HPP 
