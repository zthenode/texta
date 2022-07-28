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
///   File: pipe.hpp
///
/// Author: $author$
///   Date: 4/12/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_WINDOWS_PIPE_HPP
#define _XOS_NADIR_XOS_MT_WINDOWS_PIPE_HPP

#include "xos/mt/pipe.hpp"
#include "xos/io/writer.hpp"
#include "xos/io/reader.hpp"
#include "xos/base/created.hpp"
#include "xos/io/logger.hpp"
#include "xos/os/windows/security/attributes.hpp"

namespace xos {
namespace mt {
namespace windows {

typedef HANDLE pipe_fd_t;
typedef int invalid_pipe_fd_t;
enum { invalid_pipe_fd = 0 };

typedef pipe_fd_t* pipe_attached_t;
typedef int pipe_unattached_t;
enum { pipe_unattached = 0 };

typedef base::creatort<mt::pipe> pipe_creator;

typedef base::attachert
<pipe_attached_t, pipe_unattached_t,
 pipe_unattached, pipe_creator> pipe_attacher;

typedef base::attachedt
<pipe_attached_t, pipe_unattached_t,
 pipe_unattached,  pipe_attacher, base::base> pipe_attached;

typedef base::createdt
<pipe_attached_t, pipe_unattached_t,
 pipe_unattached,  pipe_attacher, pipe_attached> pipe_created;

typedef pipe_attacher pipe_implements;
typedef pipe_created pipe_extends;
///////////////////////////////////////////////////////////////////////
///  Class: pipet
///////////////////////////////////////////////////////////////////////
template
<class TImplements = pipe_implements, class TExtends = pipe_extends>

class _EXPORT_CLASS pipet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef xos::mt::windows::pipe_fd_t fd_t;
    typedef xos::mt::windows::invalid_pipe_fd_t invalid_fd_t;
    static const invalid_fd_t invalid_fd = xos::mt::windows::invalid_pipe_fd;

    typedef int end_t;
    enum { in = 0, out = 1, ends = 2 };

    typedef void what_t;
    typedef char sized_t;
    typedef int endof_t;
    enum { endof = 0 };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    pipet() {
    }
    virtual ~pipet() {
        if (!(this->destroyed())) {
            xos::base::creator_exception e = xos::base::failed_to_destroy;
            XOS_LOG_ERROR("...throwing base::creator_exception e = " << e);
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create_inherited(end_t end) {
        if ((end >= in) && (end <= out)) {
            if ((create(true))) {
                end_t other_end = (end != in)?(in):(out);
                if ((set_inherited(other_end, false))) {
                    return true;
                }
                destroy();
            }
        }
        return false;
    }
    virtual bool create(bool inherited = true) {
        if ((this->destroyed())) {
            xos::os::windows::security::attributes a;
            SECURITY_ATTRIBUTES& sa = a.wrapped();
            LPSECURITY_ATTRIBUTES lpPipeAttributes = &sa;
            PHANDLE hReadPipe = &ends_[in];
            PHANDLE hWritePipe = &ends_[out];
            DWORD nSize = 0;

            sa.bInheritHandle = (inherited)?(TRUE):(FALSE);
            if ((CreatePipe(hReadPipe, hWritePipe, lpPipeAttributes, nSize))) {
                this->attach_created(ends_);
                return true;
            } else {
                XOS_LOG_ERROR("failed " << GetLastError() << " on CreatePipe()");
            }
        }
        return false;
    }
    virtual bool destroy() {
        pipe_attached_t detached;
        if ((detached = this->detach())) {
            bool success = true;
            fd_t fd;
            for (end_t end = in; end < ends; ++end) {
                if (invalid_fd != (fd = detached[end])) {
                    if (!(CloseHandle(fd))) {
                        XOS_LOG_ERROR("failed " << GetLastError() << " on CloseHandle()");
                        success = false;
                    }
                }
            }
            return success;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read(what_t* what, size_t size) {
        pipe_attached_t detached;
        if ((detached = this->attached_to())) {
            fd_t fd = detached[in];
            sized_t* sized;
            if ((sized = ((sized_t*)what))) {
                DWORD nNumberOfBytesToRead = sizeof(sized_t);
                DWORD nNumberOfBytesRead = 0;
                ssize_t count;
                for (count = 0; count < size; ++sized, ++count) {
                    if (!(ReadFile(fd, sized, nNumberOfBytesToRead, &nNumberOfBytesRead, NULL))) {
                        XOS_LOG_ERROR("failed " << GetLastError() << " on ReadFile()");
                        return -1;
                    }
                    if (1 > nNumberOfBytesToRead)
                        break;
                }
                return count;
            }
        }
        return 0;
    }
    virtual ssize_t write(const what_t* what, ssize_t size = -1) {
        pipe_attached_t detached;
        if ((detached = this->attached_to())) {
            fd_t fd = detached[out];
            const sized_t* sized;
            if ((sized = ((const sized_t*)what))) {
                DWORD nNumberOfBytesToWrite = sizeof(sized_t);
                DWORD nNumberOfBytesWritten = 0;
                if (0 > (size)) {
                    const sized_t sized_endof = ((sized_t)endof);
                    ssize_t count;
                    for (count = 0; sized_endof != (*sized); ++sized, ++count) {
                        if (!(WriteFile(fd, sized, nNumberOfBytesToWrite, &nNumberOfBytesWritten, NULL))) {
                            XOS_LOG_ERROR("failed " << GetLastError() << " on WriteFile()");
                            return -1;
                        }
                    }
                    return count;
                } else {
                    nNumberOfBytesToWrite *= size;
                    if (!(WriteFile(detached[out], sized, nNumberOfBytesToWrite, &nNumberOfBytesWritten, NULL))) {
                        XOS_LOG_ERROR("failed " << GetLastError() << " on WriteFile()");
                        return -1;
                    }
                    return size;
                }
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_inherited(end_t end, bool inherited = true) {
        if ((end >= in) && (end <= out)) {
            pipe_attached_t detached;
            if ((detached = this->attached_to())) {
                fd_t fd;
                if (invalid_fd != (fd = detached[end])) {
                    DWORD dwInherited = (inherited)?(HANDLE_FLAG_INHERIT):(0);
                    if ((SetHandleInformation(fd, HANDLE_FLAG_INHERIT, dwInherited))) {
                        return true;
                    } else {
                        XOS_LOG_ERROR("failed " << GetLastError() << " on SetHandleInformation()");
                    }
                }
            }
        }
        return false;
    }
    virtual bool inherited(end_t end) const {
        if ((end >= in) && (end <= out)) {
            pipe_attached_t detached;
            if ((detached = this->attached_to())) {
                fd_t fd;
                if (invalid_fd != (fd = detached[end])) {
                    DWORD dwFlags = 0;
                    if ((GetHandleInformation(fd, &dwFlags))) {
                        if (HANDLE_FLAG_INHERIT == (dwFlags & HANDLE_FLAG_INHERIT)) {
                            return true;
                        }
                    } else {
                        XOS_LOG_ERROR("failed " << GetLastError() << " on GetHandleInformation()");
                    }
                }
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool close(end_t end) {
        if ((end >= in) && (end <= out)) {
            pipe_attached_t detached;
            if ((detached = this->attached_to())) {
                fd_t fd;
                if (invalid_fd != (fd = detached[end])) {
                    detached[end] = invalid_fd;
                    if ((CloseHandle(fd))) {
                        return true;
                    } else {
                        XOS_LOG_ERROR("failed " << GetLastError() << " on CloseHandle()");
                    }
                }
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual fd_t& operator[](end_t end) const {
        if ((end >= in) && (end <= out)) {
            return ((fd_t&)ends_[end]);
        }
        return ((fd_t&)invalid_fd);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    fd_t ends_[ends];
};
typedef pipet<> pipe;

} // namespace windows 
} // namespace mt 
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_WINDOWS_PIPE_HPP 
