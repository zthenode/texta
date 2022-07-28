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
///   Date: 2/1/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_UNIX_PIPE_HPP
#define _XOS_NADIR_XOS_MT_UNIX_PIPE_HPP

#include "xos/mt/pipe.hpp"
#include "xos/io/writer.hpp"
#include "xos/io/reader.hpp"
#include "xos/base/created.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace mt {
namespace unix {

typedef int pipe_fd_t;
typedef int invalid_pipe_fd_t;
enum { invalid_pipe_fd = -1 };

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

class _EXPORT_CLASS pipet: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef unix::pipe_fd_t fd_t;
    typedef unix::invalid_pipe_fd_t invalid_fd_t;
    static const invalid_fd_t invalid_fd = unix::invalid_pipe_fd;

    typedef int end_t;
    enum { in = 0, out = 1, ends = 2 };

    typedef void what_t;
    typedef char sized_t;
    typedef int endof_t;
    enum { endof = 0 };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    pipet(): invalid_fd_(invalid_fd) {
    }
    virtual ~pipet() {
        if (!(this->destroyed())) {
            base::creator_exception e = base::failed_to_destroy;
            XOS_LOG_ERROR("...throwing base::creator_exception e = " << e);
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create_inherited(end_t end) {
        if ((end >= in) && (end <= out)) {
            if ((create())) {
                return true;
            }
        }
        return false;
    }
    virtual bool create() {
        if ((this->destroyed())) {
            int err = 0;
            if (!(err = ::pipe(ends_))) {
                this->attach_created(ends_);
                return true;
            } else {
                XOS_LOG_ERROR("failed " << errno << " on pipe(...)");
            }
        }
        return false;
    }
    virtual bool destroy() {
        pipe_attached_t detached = 0;
        if ((detached = this->detach())) {
            bool success = true;
            fd_t fd = invalid_fd;
            int err = 0;
            for (end_t end = in; end < ends; ++end) {
                if (invalid_fd != (fd = detached[end])) {
                    if ((err = ::close(fd))) {
                        XOS_LOG_ERROR("failed " << errno << " on close(" << fd << ")");
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
        sized_t* sized = 0;
        if ((sized = ((sized_t*)what)) && (size)) {
            pipe_attached_t detached = 0;
            if ((detached = this->attached_to())) {
                fd_t fd = invalid_fd;
                if (invalid_fd != (fd = detached[in])) {
                    ssize_t count = 0, amount = 0;
                    for (count = 0, amount = 0; count < size; ++sized, ++count) {
                        if (0 > (amount = ::read(fd, sized, sizeof(sized_t)))) {
                            return amount;
                        } else {
                            if (1 > amount)
                                break;
                        }
                    }
                    return count;
                }
            }
        }
        return 0;
    }
    virtual ssize_t write(const what_t* what, ssize_t size = -1) {
        const sized_t* sized = 0;
        if ((sized = ((const sized_t*)what)) && (size)) {
            pipe_attached_t detached = 0;
            if ((detached = this->attached_to())) {
                fd_t fd = invalid_fd;
                if (invalid_fd != (fd = detached[out])) {
                    ssize_t amount = 0;
                    if (0 > (size)) {
                        const sized_t sized_endof = ((sized_t)endof);
                        ssize_t count = 0;
                        for (count = 0; sized_endof != (*sized); ++sized, ++count) {
                            if (0 > (amount = ::write(fd, sized, sizeof(sized_t)))) {
                                return amount;
                            }
                        }
                        return count;
                    } else {
                        if (0 > (amount = ::write(fd, what, size*sizeof(sized_t)))) {
                            return amount;
                        }
                        return size;
                    }
                }
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool close(end_t end) {
        if ((end >= in) && (end <= out)) {
            pipe_attached_t detached = 0;
            if ((detached = this->attached_to())) {
                fd_t fd = invalid_fd;
                if (invalid_fd != (fd = detached[end])) {
                    int err = 0;
                    detached[end] = invalid_fd;
                    if ((err = ::close(fd))) {
                        XOS_LOG_ERROR("failed " << errno << " on close(" << fd << ")");
                    } else {
                        return true;
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
        return ((fd_t&)invalid_fd_);
    }
    virtual operator pipe_attached_t() const {
        return this->attached_to();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    fd_t invalid_fd_;
    fd_t ends_[ends];
};
typedef pipet<> pipe;

} // namespace unix 
} // namespace mt 
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_UNIX_PIPE_HPP 
