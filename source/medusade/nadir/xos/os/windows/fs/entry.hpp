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
///   File: entry.hpp
///
/// Author: $author$
///   Date: 3/19/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_OS_WINDOWS_FS_ENTRY_HPP
#define _XOS_NADIR_XOS_OS_WINDOWS_FS_ENTRY_HPP

#include "xos/fs/directory/entry.hpp"
#include "xos/fs/entry.hpp"
#include "xos/fs/time.hpp"

namespace xos {
namespace os {
namespace windows {
namespace fs {

typedef xos::fs::entry_implements entry_implements;
typedef xos::fs::entry entry_extends;
///////////////////////////////////////////////////////////////////////
///  Class: entryt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TEnd = TChar, TEnd VEnd = 0,
 class TString = base::stringt<TChar, TEnd, VEnd>,
 class TExtends = entry_extends, class TImplements = entry_implements>

class _EXPORT_CLASS entryt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef xos::fs::time_when time_when;
    enum { 
        time_when_none     = xos::fs::time_when_none,
        time_when_modified = xos::fs::time_when_modified,
        time_when_accessed = xos::fs::time_when_accessed,
        time_when_changed  = xos::fs::time_when_changed,
        time_when_created  = xos::fs::time_when_created
    };
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
    typedef xos::fs::entry_ssize_t entry_ssize_t;

    typedef TString string_t; 
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    entryt() {
    }
    entryt(const entryt& copy): Extends(copy) {
    }
    virtual ~entryt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual entry_type exists(const char_t* path) {
        xos::base::wstring wpath(path);
        const wchar_t* wchars = 0;
        if ((wchars = wpath.has_chars())) {
            if ((is_found(wchars))) {
                entry_type type = entry_type_none;
                if (entry_type_none != (type = get_found_attributes())) {
                    return type;
                }
            }
        }
        return entry_type_none;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool is_found(const wchar_t* path) {
        if ((path)) {
            HANDLE handle = INVALID_HANDLE_VALUE;
            XOS_LOG_DEBUG("FindFirstFileW(\"" << path << "\",...)...");
            if ((INVALID_HANDLE_VALUE != (handle = FindFirstFileW(path, &find_data_)))) {
                XOS_LOG_DEBUG("...FindFirstFileW(\"" << path << "\",...)");
                if ((FindClose(handle))) {
                    return true;
                } else {
                    XOS_LOG_ERROR("failed " << GetLastError() << " on FindClose()");
                }
            } else {
                XOS_LOG_DEBUG("failed " << GetLastError() << " on FindFirstFileW(\"" << path << "\",...)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual entry_type get_found_attributes() {
        entry_ssize_t size = -1;
        if (0 <= (size = get_found_size())) {
            entry_type type = entry_type_none;
            if (entry_type_none != (type = get_found_type())) {
                time_when times = time_when_none;
                if (time_when_none != (times = get_found_times())) {
                    return type;
                }
            }
        }
        return entry_type_none;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual time_when get_found_times() {
        time_when time = time_when_none;
        bool is_local = false;
        const FILETIME& file_time_modified = find_data_.ftLastWriteTime, 
                        file_time_accessed = find_data_.ftLastAccessTime, 
                        file_time_created = find_data_.ftCreationTime;
        SYSTEMTIME system_time;

        if ((to_system_time(system_time, file_time_modified, is_local))) {
            if ((to_time(this->time_modified_, file_time_modified, is_local))) {
                XOS_LOG_DEBUG("time modified  = " << this->time_modified_.month() << "/" << this->time_modified_.day() << "/" << this->time_modified_.year());
                time |= time_when_modified;
            }
        }
        if ((to_system_time(system_time, file_time_accessed, is_local))) {
            if ((to_time(this->time_accessed_, file_time_accessed, is_local))) {
                XOS_LOG_DEBUG("time accessed  = " << this->time_accessed_.month() << "/" << this->time_accessed_.day() << "/" << this->time_accessed_.year());
                time |= time_when_accessed;
            }
        }
        if ((to_system_time(system_time, file_time_created, is_local))) {
            if ((to_time(this->time_created_, file_time_created, is_local))) {
                XOS_LOG_DEBUG("time created  = " << this->time_created_.month() << "/" << this->time_created_.day() << "/" << this->time_created_.year());
                time |= time_when_created;
            }
        }
        this->set_times(time);
        return time;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual entry_type get_found_type() {
        entry_type type = entry_type_none;

        if (FILE_ATTRIBUTE_DIRECTORY == 
            (FILE_ATTRIBUTE_DIRECTORY & find_data_.dwFileAttributes)) {
            XOS_LOG_DEBUG("FILE_ATTRIBUTE_DIRECTORY");
            type &= ~entry_type_file;
            type |= entry_type_directory;
        } else {
            type &= ~entry_type_directory;
            type |= entry_type_file;
        }
        if (FILE_ATTRIBUTE_REPARSE_POINT ==
            (FILE_ATTRIBUTE_REPARSE_POINT & find_data_.dwFileAttributes)) {
            XOS_LOG_DEBUG("FILE_ATTRIBUTE_REPARSE_POINT");
            type &= ~entry_type_hard_link;
            type |= entry_type_symbolic_link;
        }
        this->set_type(type);

        if (FILE_ATTRIBUTE_HIDDEN ==
            (FILE_ATTRIBUTE_HIDDEN & find_data_.dwFileAttributes)) {
            XOS_LOG_DEBUG("FILE_ATTRIBUTE_HIDDEN");
            this->set_is_hidden();
        }
        return type;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual entry_ssize_t get_found_size() {
        ULONGLONG size = 0;
        size = find_data_.nFileSizeHigh;
        size <<= (sizeof(LONG) << 3);
        size |= find_data_.nFileSizeLow;
        this->set_size(size);
        return size;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual xos::fs::time* to_time
    (xos::fs::time& to, const FILETIME& from, bool is_local = false) {
        SYSTEMTIME system_time;
        if ((to_system_time(system_time, from, is_local))) {
            to.clear();
            to.set_year(system_time.wYear);
            to.set_month(system_time.wMonth);
            to.set_day(system_time.wDay);
            to.set_hour(system_time.wHour);
            to.set_minute(system_time.wMinute);
            to.set_second(system_time.wSecond);
            to.set_msecond(system_time.wMilliseconds);
            return &to;
        }
        return 0;
    }
    virtual FILETIME* from_time
    (FILETIME& to, const xos::fs::time& from, bool is_local = false) {
        SYSTEMTIME system_time;
        xos::base::chars_t::set((char*)(&system_time), 0, sizeof(to));
        system_time.wYear = from.year();
        system_time.wMonth = from.month();
        system_time.wDay = from.day();
        system_time.wHour = from.hour();
        system_time.wMinute = from.minute();
        system_time.wSecond = from.second();
        system_time.wMilliseconds = from.msecond();
        if ((from_system_time(to, system_time, is_local))) {
            return &to;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SYSTEMTIME* to_system_time
    (SYSTEMTIME& to, const FILETIME& from, bool is_local = false) const {
        FILETIME file_time;

        if ((is_local)) {
            if (!(FileTimeToLocalFileTime(&from, &file_time))) {
                XOS_LOG_ERROR("failed " << GetLastError() << " on FileTimeToLocalFileTime()");
                return 0;
            }
        }
        if ((FileTimeToSystemTime((is_local)?(&file_time):(&from), &to))) {
            return &to;
        } else {
            XOS_LOG_ERROR("failed " << GetLastError() << " on FileTimeToSystemTime()");
        }
        return 0;
    }
    virtual FILETIME* from_system_time
    (FILETIME& to, const SYSTEMTIME& from, bool is_local = false) const {
        FILETIME file_time;

        if ((SystemTimeToFileTime(&from, (is_local)?(&file_time):(&to)))) {
            if ((is_local)) {
                if (!(FileTimeToLocalFileTime(&file_time, &to))) {
                    XOS_LOG_ERROR("failed " << GetLastError() << " on FileTimeToLocalFileTime()");
                    return 0;
                }
            }
            return &to;
        } else {
            XOS_LOG_ERROR("failed " << GetLastError() << " on SystemTimeToFileTime()");
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    WIN32_FIND_DATAW find_data_;
};
typedef entryt<> entry;

} // namespace fs 
} // namespace windows 
} // namespace os 
} // namespace xos 

#endif // _XOS_NADIR_XOS_OS_WINDOWS_FS_ENTRY_HPP 
