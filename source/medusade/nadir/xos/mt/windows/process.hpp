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
///   File: process.hpp
///
/// Author: $author$
///   Date: 4/11/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_WINDOWS_PROCESS_HPP
#define _XOS_NADIR_XOS_MT_WINDOWS_PROCESS_HPP

#include "xos/mt/process.hpp"
#include "xos/mt/windows/pipe.hpp"
#include "xos/io/windows/file.hpp"
#include "xos/base/array.hpp"
#include "xos/base/created.hpp"
#include "xos/base/creator.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace mt {
namespace windows {

typedef int process_unattached_t;
enum { process_unattached = 0 };

///////////////////////////////////////////////////////////////////////
///  Struct: process_attached_t
///////////////////////////////////////////////////////////////////////
struct process_attached_t {
    HANDLE hProcess, hThread;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    process_attached_t(HANDLE _hProcess, HANDLE _hThread)
    : hProcess(_hProcess), hThread(_hThread) {
    }
    process_attached_t(process_unattached_t unattached = process_unattached)
    : hProcess((HANDLE)unattached), hThread((HANDLE)unattached) {
    }
    process_attached_t(const process_attached_t& copy)
    : hProcess(copy.hProcess), hThread(copy.hThread) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
	bool operator != (const process_attached_t& to) const {
		if ((hProcess != to.hProcess) || (hThread != to.hThread)) {
			return true;
		}
		return false;
	}
	/*bool operator != (process_unattached_t to) const {
        if (!(to != process_unattached)) {
            if ((hProcess != ((HANDLE)process_unattached)) 
                && (hThread != ((HANDLE)process_unattached))) {
                return true;
            }
        }
        return false;
    }*/
    /*operator bool() const {
        if ((hProcess != ((HANDLE)process_unattached)) 
            && (hThread != ((HANDLE)process_unattached))) {
            return true;
        }
        return false;
    }*/
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef base::creatort<xos::mt::process> process_creator;

typedef base::attachert
<process_attached_t, process_unattached_t, 
 process_unattached, process_creator> process_attacher;

typedef base::attachedt
<process_attached_t, process_unattached_t, 
 process_unattached, process_attacher, base::base> process_attached;

typedef base::createdt
<process_attached_t, process_unattached_t, process_unattached, 
 process_attacher, process_attached> process_created;

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

    typedef xos::io::windows::fd_t fd_t;
    typedef xos::io::windows::invalid_fd_t invalid_fd_t;
    static const invalid_fd_t invalid_fd = xos::io::windows::invalid_fd;

    typedef xos::mt::windows::pipe_fd_t pipe_fd_t;
    typedef xos::mt::windows::invalid_pipe_fd_t invalid_pipe_fd_t;
    static const invalid_pipe_fd_t invalid_pipe_fd = xos::mt::windows::invalid_pipe_fd;

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
    processt
    (process_attached_t attached = process_unattached, bool is_created = false)
     : Extends(attached, is_created), 
       is_forked_(false) {
    }
    processt(const processt& copy)
    : Extends(copy), 
      is_forked_(false) {
    }
    virtual ~processt() {
        if (!(this->destroyed())) {
            xos::base::creator_exception e = xos::base::failed_to_destroy;
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create
    (const char_t* path, char_t** argv, char_t** env,
     fd_t* fdup, pipe_fd_t** pdup, bool is_detached = false) {
        if ((this->destroyed())) {
            process_attached_t detached = (process_attached_t)(process_unattached);
            if ((process_attached_t)(process_unattached) != (detached = this->fork(path, argv, env, fdup, pdup, is_detached)) != process_unattached) {
                this->attach_created(detached);
                return true;
            }
        }
        return false;
    }
    virtual bool destroy() {
        if ((this->joined())) {
            process_attached_t detached = process_unattached;

            if ((process_attached_t)(process_unattached) != (detached = this->detach())) {
                HANDLE hProcess = detached.hProcess;
                HANDLE hThread = detached.hThread;

                if ((hProcess)) {
                    bool success = false;

                    if ((hThread)) {
                        XOS_LOG_TRACE("CloseHandle()...");
                        if (!(success = (FALSE != CloseHandle(hThread)))) {
                            XOS_LOG_ERROR("failed " << GetLastError() << " on CloseHandle()");
                        } else {
                            XOS_LOG_TRACE("...CloseHandle()");
                        }
                    } else {
                        XOS_LOG_ERROR("unexpected hThread == NULL");
                    }

                    XOS_LOG_TRACE("CloseHandle()...");
                    if (FALSE != (CloseHandle(hProcess))) {
                        XOS_LOG_TRACE("...CloseHandle()");
                        return success;
                    } else {
                        XOS_LOG_ERROR("failed " << GetLastError() << " on CloseHandle()");
                    }
                } else {
                    XOS_LOG_ERROR("unexpected hProcess == NULL");
                }
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual process_attached_t fork
    (const char_t* path, char_t** argv, char_t** env,
     fd_t* fdup, pipe_fd_t** pdup, bool is_detached = false) {
        process_attached_t detached = (process_attached_t)(process_unattached);
        if ((path)) {
            ApplicationName applicationName(path);
            CommandLine commandLine(argv);
            Environment environment(env);
            StartupInfo startupInfo(0);
            ProcessInformation processInformation(0);
            LPCWSTR lpApplicationName = (applicationName.length())?(applicationName.c_str()):(0);
            LPWSTR lpCommandLine = (commandLine.length())?(commandLine.str()):(0);
            LPSECURITY_ATTRIBUTES lpProcessAttributes = 0;
            LPSECURITY_ATTRIBUTES lpThreadAttributes = 0;
            BOOL bInheritHandles = FALSE;
            DWORD dwCreationFlags = ((is_detached)?(DETACHED_PROCESS):(0))
                                    | ((sizeof(wchar_t) == environment.sizeof_char())
                                       ?(CREATE_UNICODE_ENVIRONMENT):(0));
            LPVOID lpEnvironment = (environment.length())?(environment.str()):(0);
            LPTSTR lpCurrentDirectory = 0;
            LPSTARTUPINFO lpStartupInfo = &startupInfo.wrapped();
            LPPROCESS_INFORMATION lpProcessInformation = &processInformation.wrapped();

            if ((fdup)) {
                fd_t fd = 0;
                for (int i = 0; (i < 3) && (fd = fdup[i]); ++i) {
                    bInheritHandles = TRUE;
                    lpStartupInfo->dwFlags |= STARTF_USESTDHANDLES;
                    switch(i) {
                    case 0:
                        lpStartupInfo->hStdInput = fd;
                        break;
                    case 1:
                        lpStartupInfo->hStdOutput = fd;
                        break;
                    case 2:
                        lpStartupInfo->hStdError = fd;
                        break;
                    }
                }
            }

            if ((pdup)) {
                pipe_fd_t* p = 0;
                pipe_fd_t fd = 0;
                for (int i = 0; (i < 3) && (p = pdup[i]); ++i) {
                    if ((fd = p[(i)?(1):(0)])) {
                        bInheritHandles = TRUE;
                        lpStartupInfo->dwFlags |= STARTF_USESTDHANDLES;
                        switch(i) {
                        case 0:
                            lpStartupInfo->hStdInput = fd;
                            break;
                        case 1:
                            lpStartupInfo->hStdOutput = fd;
                            break;
                        case 2:
                            lpStartupInfo->hStdError = fd;
                            break;
                        }
                    }
                }
            }

            XOS_LOG_TRACE("CreateProcessW()...");
            if (FALSE != (CreateProcessW
                (lpApplicationName, lpCommandLine, 
                 lpProcessAttributes,lpThreadAttributes, bInheritHandles, dwCreationFlags,
                 lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation))) {
                HANDLE hProcess = processInformation.wrapped().hProcess;
                HANDLE hThread = processInformation.wrapped().hThread;
                XOS_LOG_TRACE("...CreateProcessW()");
                detached = process_attached_t(hProcess, hThread);
            } else {
                xos::base::string applicationName(path);
                XOS_LOG_ERROR("failed " << GetLastError() << " on CreateProcessW(\"" << applicationName << "\", ...)");
            }
        }
        return detached;
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
        this->set_is_forked(false);
        return this->wait();
    }
    virtual wait_status_t try_join() {
        wait_status_t wait_status = this->try_wait();
        if (wait_busy != (wait_status)) {
            this->set_is_forked(false);
        }
        return wait_status;
    }
    virtual wait_status_t timed_join(mseconds_t milliseconds) {
        wait_status_t wait_status = this->timed_wait(milliseconds);
        if (wait_busy != (wait_status)) {
            this->set_is_forked(false);
        }
        return wait_status;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool wait() {
        wait_status_t wait_status = timed_wait(wait_forever);
        if (wait_success == (wait_status)) {
            return true;
        }
        return false;
    }
    virtual wait_status_t try_wait() {
        wait_status_t wait_status = timed_wait(wait_none);
        return wait_status;
    }
    virtual wait_status_t timed_wait(mseconds_t milliseconds) {
        process_attached_t detached = process_unattached;

        if ((process_attached_t)(process_unattached) != (detached = this->attached_to())) {
            HANDLE handle = 0;

            if ((handle = detached.hProcess)) {
                DWORD dwWaitMilliSeconds = (DWORD)(wait_forever != milliseconds)?(milliseconds):(INFINITE);
                DWORD dwResult = 0;

                XOS_LOG_TRACE("wait on WaitForSingleObject()...");
                if (WAIT_OBJECT_0 == (dwResult = WaitForSingleObject(handle, dwWaitMilliSeconds))) {
                    XOS_LOG_TRACE("...WAIT_OBJECT_0 on WaitForSingleObject()");
                    return wait_success;
                } else {
                    switch(dwResult) {
                    case WAIT_TIMEOUT:
                        XOS_LOG_TRACE("...WAIT_TIMEOUT on WaitForSingleObject()");
                        return wait_busy;
                        break;

                    case WAIT_ABANDONED:
                         XOS_LOG_ERROR("...WAIT_ABANDONED on WaitForSingleObject()");
                         return wait_interrupted;
                        break;

                    default:
                        XOS_LOG_ERROR("...failed on WaitForSingleObject()");
                    }
                }
            }
        }
        return wait_failed;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual process_attached_t attach_created
    (process_attached_t detached, bool is_created = true) {
        process_attached_t attached = Extends::attach_created(detached);
        this->set_is_forked(is_created);
        return attached;
    }
    virtual process_attached_t detach_created(bool& is_created) {
        process_attached_t detached = Extends::detach_created(is_created);
        this->set_is_forked(false);
        return detached;
    }
    virtual process_attached_t detach() {
        process_attached_t detached = Extends::detach();
        this->set_is_forked(false);
        return detached;
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
protected:
    typedef xos::base::wrappedt<PROCESS_INFORMATION> ProcessInformation;
    typedef xos::base::wrappedt<STARTUPINFO> StartupInfoExtends;
    class _EXPORT_CLASS StartupInfo: public StartupInfoExtends {
    public:
        typedef StartupInfoExtends Extends;
        StartupInfo(initialized_t initialized): Extends(initialized) {
            wrapped().cb = sizeof(STARTUPINFO);
        }
    };
    typedef xos::base::wstring ApplicationName;
    typedef xos::base::wstring CommandLineExtends;
    class _EXPORT_CLASS CommandLine: public CommandLineExtends {
    public:
        typedef CommandLineExtends Extends;
        CommandLine(char** argv) {
            wchar_t null = 0;
            const char* arg = 0;
            if ((arg = *(argv++))) {
                append(arg);
                while ((arg = *(argv++))) {
                    append(" ");
                    append(arg);
                }
            }
            m_str.append(c_str(), length());
            m_str.append(&null, 1);
        }
        CommandLine(wchar_t** argv) {
            wchar_t null = 0;
            const wchar_t* arg = 0;
            if ((arg = *(argv++))) {
                append(arg);
                while ((arg = *(argv++))) {
                    append(" ");
                    append(arg);
                }
            }
            m_str.append(c_str(), length());
            m_str.append(&null, 1);
        }
        inline wchar_t* str() const { 
            return m_str.elements(); 
        }
    protected:
        xos::base::arrayt<wchar_t> m_str;
    };
    typedef xos::base::wstring EnvironmentExtends;
    class _EXPORT_CLASS Environment: public EnvironmentExtends {
    public:
        typedef EnvironmentExtends Extends;
        Environment(char** argv) {
            wchar_t null = 0;
            const char* arg = 0;
            if ((arg = *(argv++))) {
                do {
                    append(arg);
                    append(&null, 1);
                } while ((arg = *(argv++)));
                m_str.append(c_str(), length());
            } else {
                m_str.append(&null, 1);
            }
            m_str.append(&null, 1);
        }
        Environment(wchar_t** argv) {
            wchar_t null = 0;
            const wchar_t* arg = 0;
            if ((arg = *(argv++))) {
                do {
                    wppend(arg);
                    wppend(&null, 1);
                } while ((arg = *(argv++)));
                m_str.wppend(c_str(), length());
            } else {
                m_str.wppend(&null, 1);
            }
            m_str.wppend(&null, 1);
        }
        inline wchar_t* str() const { 
            return m_str.elements(); 
        }
        inline size_t sizeof_char() const {
            return sizeof(wchar_t);
        }
    protected:
        xos::base::arrayt<wchar_t> m_str;
    };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool is_forked_;
};
typedef processt<> process;

} // namespace windows 
} // namespace mt 
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_WINDOWS_PROCESS_HPP 
