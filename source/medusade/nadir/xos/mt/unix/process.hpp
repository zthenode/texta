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
///   File: process.hpp
///
/// Author: $author$
///   Date: 9/18/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_UNIX_PROCESS_HPP
#define _XOS_NADIR_XOS_MT_UNIX_PROCESS_HPP

#include "xos/mt/process.hpp"
#include "xos/mt/unix/pipe.hpp"
#include "xos/io/unix/file.hpp"
#include "xos/base/created.hpp"
#include "xos/base/creator.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"
#include "xos/io/logger.hpp"
#include "thirdparty/gnu/glibc/posix/execvpe.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

namespace xos {
namespace mt {
namespace unix {

typedef pid_t process_attached_t;
typedef int process_unattached_t;
enum { process_unattached = -1};

typedef base::creatort<mt::process> process_creator;
typedef base::attachert<pid_t, int, -1, process_creator> process_attacher;
typedef base::attachedt<pid_t, int, -1, process_attacher, base::base> process_attached;
typedef base::createdt<pid_t, int, -1, process_attacher, process_attached> process_created;
typedef process_attacher process_implements;
typedef process_created process_extends;
///////////////////////////////////////////////////////////////////////
///  Class: processt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TEnd = TChar, TEnd VEnd = 0,
 class TImplements = process_implements, class TExtends = process_extends>

class _EXPORT_CLASS processt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef xos::io::unix::fd_t fd_t;
    typedef xos::io::unix::invalid_fd_t invalid_fd_t;
    static const invalid_fd_t invalid_fd = xos::io::unix::invalid_fd;

    typedef xos::mt::unix::pipe_fd_t pipe_fd_t;
    typedef xos::mt::unix::invalid_pipe_fd_t invalid_pipe_fd_t;
    static const invalid_pipe_fd_t invalid_pipe_fd = xos::mt::unix::invalid_pipe_fd;

    typedef xos::mt::wait_status wait_status_t;
    static const wait_status_t wait_success = xos::mt::wait_success;
    static const wait_status_t wait_failed = xos::mt::wait_failed;
    static const wait_status_t wait_busy = xos::mt::wait_busy;
    static const wait_status_t wait_interrupted = xos::mt::wait_interrupted;
    static const wait_status_t wait_invalid = xos::mt::wait_invalid;

    typedef xos::mt::wait_time wait_time;
    static const wait_time wait_none = xos::mt::wait_none;
    static const wait_time wait_forever = xos::mt::wait_forever;

    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    processt() {
    }
    virtual ~processt() {
        if (!(this->destroyed())) {
            base::creator_exception e = base::failed_to_destroy;
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create
    (const char_t* path, char_t** argv, char_t** env,
     int* fdup, int** pdup, bool is_detached = false) {
        if ((this->destroyed())) {
            pid_t pid = (pid_t)(-1);

            if (0 < (pid = this->fork(path, argv, env, fdup, pdup, is_detached))) {
                this->attach_created(pid);
                return true;
            }
        }
        return false;
    }
    virtual bool destroy() {
        if ((this->joined())) {
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual pid_t fork
    (const char_t* path, char_t** argv, char_t** env,
     int* fdup, int** pdup, bool is_detached = false) {
        pid_t pid = (pid_t)(-1);

        XOS_LOG_DEBUG("::fork()...");
        if (0 < (pid = ::fork())) {
            XOS_LOG_DEBUG("... pid = " << pid << " on ::fork()");
        } else {
            if (0 > (pid)) {
                XOS_LOG_ERROR("failed errno = " << errno << "on ::fork()");
            } else {
                int err = 1;

                XOS_LOG_DEBUG("chlid process...");
                this->exec(path, argv, env, fdup, pdup, is_detached);
                XOS_LOG_DEBUG("...chlid process");
                exit(err);
            }
        }
        return pid;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool exec
    (const char_t* path, char_t** argv, char_t** env,
     int* fdup, int** pdup, bool is_detached = false) {
        if ((path) && (argv)) {
            int err = 0;

            if ((fdup)) {
                int fd = 0;
                for (int i = 0; (i < 3) && (fd = fdup[i]); ++i) {
                    XOS_LOG_DEBUG("::dup2(" << fd << ", " << i << ")...");
                    if (0 > (err = dup2(fd, i))) {
                        XOS_LOG_ERROR("...failed errno = " << errno << " on ::dup2(" << fd << ", " << i << ")");
                        return false;
                    } else {
                        close(fd);
                    }
                }
            }

            if ((pdup)) {
                int* p = 0;
                for (int i = 0; (i < 3) && (p = pdup[i]); ++i) {
                    int fd = p[(i)?(1):(0)];
                    XOS_LOG_DEBUG("::dup2(" << fd << ", " << i << ")...");
                    if (0 > (err = dup2(fd, i))) {
                        XOS_LOG_ERROR("...failed errno = " << errno << " on ::dup2(" << fd << ", " << i << ")");
                        return false;
                    } else {
                        close(p[0]);
                        close(p[1]);
                    }
                }
            }

            if ((env)) {
                XOS_LOG_DEBUG("::execvpe(\"" << path << "\", ...)...");
                if ((err = execvpe(path, argv, env))) {
                    XOS_LOG_ERROR("...failed errno = " << errno << " on ::execvpe(\"" << path << "\",...)");
                }
            } else {
                XOS_LOG_DEBUG("::execvp(\"" << path << "\", ...)...");
                if ((err = execvp(path, argv))) {
                    XOS_LOG_ERROR("...failed errno = " << errno << " on ::execvp(\"" << path << "\",...)");
                }
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool joined() {
        if ((this->is_forked())) {
            return this->join();
        }
        return true;
    }
    virtual bool join() {
        return this->wait();
    }
    virtual wait_status try_join() {
        return this->try_wait();
    }
    virtual wait_status timed_join(mseconds_t milliseconds) {
        return this->timed_wait(milliseconds);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool wait() {
        pid_t pid = (pid_t)(-1);

        this->set_is_forked(false);
        if (0 < (pid = this->attached_to())) {
            int options = 0;
            int status = 0;

            XOS_LOG_DEBUG("waitpid(" << pid << ",...)...");
            if (!(pid != waitpid(pid, &status, options))) {
                XOS_LOG_DEBUG("...waitpid(" << pid << ",...)");
                return true;
            } else {
                XOS_LOG_ERROR("failed " << errno << " on waitpid(" << pid << ",...)");
            }
        }
        return false;
    }
    virtual wait_status try_wait() {
        pid_t pid = (pid_t)(-1);

        if (0 < (pid = this->attached_to())) {
            int options = WNOHANG;
            int status = 0;

            XOS_LOG_TRACE("waitpid(" << pid << ",...)...");
            if (!(pid != waitpid(pid, &status, options))) {
                XOS_LOG_TRACE("...waitpid(" << pid << ",...)");
                this->set_is_forked(false);
                return wait_success;
            } else {
                if (EBUSY != (errno)) {
                    XOS_LOG_ERROR("failed " << errno << " on waitpid(" << pid << ",...)");
                    this->set_is_forked(false);
                } else {
                    XOS_LOG_ERROR("busy " << errno << " on waitpid(" << pid << ",...)");
                    return wait_busy;
                }
            }
        }
        return wait_failed;
    }
    virtual wait_status timed_wait(mseconds_t milliseconds) {
        XOS_LOG_ERROR("failed timed_waitpid(..., " << milliseconds << ") unavailable");
        return wait_invalid;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_is_forked(bool to = true) {
        is_forked_ = to;
        return is_forked_;
    }
    virtual bool is_forked() const {
        return is_forked_;
    }
    virtual bool is_joined() const {
        return !is_forked_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual pid_t attach_created(pid_t detached, bool is_created = true) {
        pid_t attached = Extends::attach_created(detached);
        this->set_is_forked(is_created);
        return attached;
    }
    virtual pid_t detach_created(bool& is_created) {
        pid_t detached = Extends::detach_created(is_created);
        this->set_is_forked(false);
        return detached;
    }
    virtual pid_t detach() {
        pid_t detached = Extends::detach();
        this->set_is_forked(false);
        return detached;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool is_forked_;
};
typedef processt<> process;

} // namespace unix 
} // namespace mt 
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_UNIX_PROCESS_HPP 
