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
///   File: path.hpp
///
/// Author: $author$
///   Date: 3/24/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_OS_WINDOWS_FS_DIRECTORY_PATH_HPP
#define _XOS_NADIR_XOS_OS_WINDOWS_FS_DIRECTORY_PATH_HPP

#include "xos/fs/directory/path.hpp"
#include "xos/os/windows/fs/directory/entry.hpp"
#include "xos/base/opened.hpp"

#define XOS_OS_FS_DIRECTORY_SEPARATOR_CHARS "/"
#define XOS_OS_FS_DIRECTORY_WILDCARD_CHARS "*"

namespace xos {
namespace os {
namespace windows {
namespace fs {
namespace directory {

typedef HANDLE path_attached_t;
///////////////////////////////////////////////////////////////////////
///  Class: patht
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,  typename TEnd = TChar, TEnd VEnd = 0,
 class TString = base::stringt<TChar, TEnd, VEnd>, 
 class TEntry = entryt<TChar, TEnd, VEnd>,
 class TImplements = xos::base::attachert
 <path_attached_t, int, 0, xos::fs::directory::patht
  <TChar, TEnd, VEnd, TString, TEntry> >,
 class TExtends = xos::base::openedt
 <path_attached_t, int, 0, TImplements, xos::base::attachedt
  <path_attached_t, int, 0, TImplements> > >

class _EXPORT_CLASS patht: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef patht Derives;

    typedef xos::fs::entry_type entry_type;
    enum { 
        entry_type_none          = xos::fs::entry_type_none,
        entry_type_file          = xos::fs::entry_type_file,
        entry_type_directory     = xos::fs::entry_type_directory,
        entry_type_symbolic_link = xos::fs::entry_type_symbolic_link,
        entry_type_hard_link     = xos::fs::entry_type_hard_link,
        entry_type_block_device  = xos::fs::entry_type_block_device,
        entry_type_char_device   = xos::fs::entry_type_char_device,
        entry_type_pipe          = xos::fs::entry_type_pipe,
        entry_type_socket        = xos::fs::entry_type_socket,
    };
    typedef TEntry entry_t;
    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    patht(): get_first_(0), get_next_(0) {
    }
    virtual ~patht() {
        if (!(this->closed())) {
            xos::base::opener_exception e = xos::base::failed_to_close;
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool open(const char_t* name) {
        if ((this->closed()) && (name) && (name[0])) {
            entry_type type = entry_type_none;
            if (entry_type_none != (type = this->entry_.exists(name))) {
                if (!(entry_type_directory != (entry_type_directory & type))) {
                    xos::base::tstring wmatch(name);
                    const wchar_t* wchars = 0;
                    HANDLE detached = 0;

                    wmatch.append(XOS_OS_FS_DIRECTORY_SEPARATOR_CHARS);
                    wmatch.append(XOS_OS_FS_DIRECTORY_WILDCARD_CHARS);
                    match_.assign(wmatch.chars());
                    if ((wchars = wmatch.has_chars()) && (name = match_.has_chars())) {
                        XOS_LOG_DEBUG("FindFirstFileW(\"" << name << "\",...)...");
                        if ((INVALID_HANDLE_VALUE != (detached = FindFirstFileW(wchars, &find_data_)))) {
                            XOS_LOG_DEBUG("...FindFirstFileW(\"" << name << "\",...)");
                            this->attach_opened(detached);
                            name_.assign(name);
                            entry_.assign(find_data_);
                            get_first_ = &Derives::get_first;
                            get_next_ = &Derives::get_next;
                            return true;
                        } else {
                            XOS_LOG_DEBUG("failed " << GetLastError() << " on FindFirstFileW(\"" << name << "\",...)");
                        }
                    }
                } else {
                    XOS_LOG_DEBUG("entry type != directory");
                }
            }
        }
        return false;
    }
    virtual bool close() {
        HANDLE detached = 0;
        get_first_ = 0;
        get_next_ = 0;
        name_.clear();
        if ((detached = this->detach())) {
            XOS_LOG_DEBUG("FindClose()...");
            if ((FindClose(detached))) {
                XOS_LOG_DEBUG("...FindClose()");
                return true;
            } else {
                XOS_LOG_ERROR("failed " << GetLastError() << " on FindClose()");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual entry_t* get_first_entry() {
        if ((get_first_)) {
            return (this->*get_first_)();
        }
        return 0;
    }
    virtual entry_t* get_next_entry() {
        if ((get_next_)) {
            return (this->*get_next_)();
        }
        return 0;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual entry_t* get_first_again() {
        return 0;
    }
    virtual entry_t* get_first() {
        get_first_ = &Derives::get_first_again;
        return &entry_;
    }
    virtual entry_t* get_next() {
        HANDLE detached = 0;
        const char_t* name = 0;
        if ((detached = (this->attached_to())) && (name = match_.has_chars())) {
            XOS_LOG_DEBUG("FindNextFileW()(\"" << name << "\")...");
            if (((FindNextFileW(detached, &find_data_)))) {
                XOS_LOG_DEBUG("...FindNextFileW()(\"" << name << "\")");
                entry_.assign(find_data_);
                return &entry_;
            } else {
                XOS_LOG_DEBUG("failed" << GetLastError() << " on FindNextFileW()(\"" << name << "\")...");
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef entry_t* (Derives::*get_t)();

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    get_t get_first_, get_next_;
    WIN32_FIND_DATAW find_data_;
    entry_t entry_;
    string_t name_, match_;
};
typedef patht<> path;

} // namespace directory 
} // namespace fs 
} // namespace windows 
} // namespace os 
} // namespace xos 

#endif // _XOS_NADIR_XOS_OS_WINDOWS_FS_DIRECTORY_PATH_HPP 
