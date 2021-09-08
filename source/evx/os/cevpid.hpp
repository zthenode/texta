///////////////////////////////////////////////////////////////////////
//   File: cevpid.hpp
//
// Author: $author$
//   Date: 7/19/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVPID_HPP
#define _CEVPID_HPP

#include "evplatform_error.h"
#include "evplatform_wait.h"
#include "evplatform_fork.h"
#include "evplatform_exec.h"
#include "evpid.hpp"
#include "cevattached.hpp"
#include "cevpcchar2pcharbuffer.hpp"
#include "cevpccharbuffer.hpp"
#include "cevpcharbuffer.hpp"
#include "cevbuffer.hpp"
#include "cevpasswd.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvPIDAttached
//
//   Author: $author$
//     Date: 7/19/2007
///////////////////////////////////////////////////////////////////////
typedef CEvAttached
<PID, PID, INVALID_PID,
 EvPIDAttached, CEvBase>
CEvPIDAttached;

///////////////////////////////////////////////////////////////////////
//  Class: CEvPid
//
// Author: $author$
//   Date: 7/19/2007
///////////////////////////////////////////////////////////////////////
class CEvPid
: virtual public EvPid,
  public CEvPIDAttached
{
public:
    typedef EvPid CImplements;
    typedef CEvPIDAttached CExtends;
    typedef CEvPid CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvPid
    //
    //       Author: $author$
    //         Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvPid(PID pid=INVALID_PID) 
    : CExtends(pid)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvPid
    //
    //      Author: $author$
    //        Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvPid()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CDCreateLP
    //
    //   Author: $author$
    //     Date: 7/32/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CDCreateLP
    (const char* directory, const char* filename, ...) 
    {
        EvError error = EV_ERROR_FAILED;
        va_list va;
        va_start(va, filename);
        error = CDVCreateP(directory, filename, va);
        va_end(va);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CreateLP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CreateLP
    (const char* filename,...) 
    {
        EvError error = EV_ERROR_FAILED;
        va_list va;
        va_start(va, filename);
        error = VCreateP(filename,va);
        va_end(va);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CreateBackgroundLP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CreateBackgroundLP
    (const char* stdIn, const char* stdOut, const char* stdErr,
     const char* filename,...) 
    {
        EvError error = EV_ERROR_FAILED;
        va_list va;
        va_start(va, filename);
        error = VCreateBackgroundP(stdIn, stdOut, stdErr, filename,va);
        va_end(va);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CreateDaemonLP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CreateDaemonLP
    (const char* stdIn, const char* stdOut, const char* stdErr,
     const char* filename,...) 
    {
        EvError error = EV_ERROR_FAILED;
        va_list va;
        va_start(va, filename);
        error = VCreateDaemonP(stdIn, stdOut, stdErr, filename,va);
        va_end(va);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CDVCreateP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CDVCreateP
    (const char* directory,
     const char* filename,
     va_list va) 
    {
        EvError error = EV_ERROR_FAILED;
        LONG length;
        const PCHAR* argv;
        CEvPCCHAR2PCHARBuffer argvBuffer;

        if (0 > (length = argvBuffer.Append(&filename, 1)))
            return error;

        if (0 > (length = argvBuffer.VAppend(va)))
            return error;

        if ((argv = argvBuffer.Buffer(length)) && (0 <= length))
            error = CDCreateVP(directory, filename, argv);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: VCreateP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError VCreateP
    (const char* filename,
     va_list va) 
    {
        EvError error = EV_ERROR_FAILED;
        LONG length;
        const PCHAR* argv;
        CEvPCCHAR2PCHARBuffer argvBuffer;

        if (0 > (length = argvBuffer.Append(&filename, 1)))
            return error;

        if (0 > (length = argvBuffer.VAppend(va)))
            return error;

        if ((argv = argvBuffer.Buffer(length)) && (0 <= length))
            error = CreateVP(filename,argv);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: VCreateBackgroundP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError VCreateBackgroundP
    (const char* stdIn, const char* stdOut, const char* stdErr,
     const char* filename,
     va_list va) 
    {
        EvError error = EV_ERROR_FAILED;
        LONG length;
        const PCHAR* argv;
        CEvPCCHAR2PCHARBuffer argvBuffer;

        if (0 > (length = argvBuffer.Append(&filename, 1)))
            return error;

        if (0 > (length = argvBuffer.VAppend(va)))
            return error;

        if ((argv = argvBuffer.Buffer(length)) && (0 <= length))
            error = CreateBackgroundVP(stdIn, stdOut, stdErr, filename,argv);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: VCreateDaemonP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError VCreateDaemonP
    (const char* stdIn, const char* stdOut, const char* stdErr,
     const char* filename,
     va_list va) 
    {
        EvError error = EV_ERROR_FAILED;
        LONG length;
        const PCHAR* argv;
        CEvPCCHAR2PCHARBuffer argvBuffer;

        if (0 > (length = argvBuffer.Append(&filename, 1)))
            return error;

        if (0 > (length = argvBuffer.VAppend(va)))
            return error;

        if ((argv = argvBuffer.Buffer(length)) && (0 <= length))
            error = CreateDaemonVP(stdIn, stdOut, stdErr, filename,argv);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: UGCreateVP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError UGCreateVP
    (const char* userName, 
     const char* groupName,
     const char* userHome,
     const char* filename,
     char*const argv[]) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;
        LONG length;
        UID uid;
        GID gid;
        CEvPasswd passwd;

        if (!(error2 = passwd.FindUser(userName)))
        {
            uid = passwd.GetUid();
            gid = passwd.GetGid();

            if (!userHome)
                userHome = passwd.GetUserHome(length);

            error = UGCreateVP
            (uid, gid, userHome, filename, argv);
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: UGCreateVP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError UGCreateVP
    (UID uid, GID gid,
     const char* userHome,
     const char* filename,
     char*const argv[]) 
    {
        EvError error = EV_ERROR_FAILED;
        PID pid;
        int err;

        if (!(pid = fork()))
        {
            if ((err = setgid(gid)))
                DBE("() failed to set gid to %d\n", gid);
            else if ((err = setuid(uid)))
                    DBE("() failed to set uid to %d\n", uid);
            else 
            {
                if (userHome)
                if (userHome[0])
                if ((err = chdir(userHome)))
                {
                    DBE("() failed to cd to \"%s\"\n", userHome);
                    exit(1);
                }
                err = execvp(filename, argv);
            }
            exit(1);
        }

        if (0 >= pid)
            DBE("() failed to fork\n");
        else 
        {
            m_attached = pid;
            error = EV_ERROR_NONE;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CDCreateVP
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CDCreateVP
    (const char* directory,
     const char* filename,
     char*const argv[]) 
    {
        EvError error = EV_ERROR_FAILED;
        PID pid;
        int err;

        if (!(pid = fork()))
        {
            if (directory)
            if (directory[0])
            if ((err = chdir(directory)))
            {
                DBE("() failed to cd to \"%s\"\n", directory);
                exit(1);
            }
            err = execvp(filename, argv);
            exit(1);
        }

        if (0 >= pid)
            DBE("() failed to fork\n");
        else 
        {
            m_attached = pid;
            error = EV_ERROR_NONE;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CreateVP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CreateVP
    (const char* filename,
     char*const argv[]) 
    {
        EvError error = EV_ERROR_FAILED;
        PID pid;
        int err;

        if (!(pid = fork()))
        {
            err = execvp(filename, argv);
            exit(1);
        }

        if (0 >= pid)
            DBE("() failed to fork\n");
        else 
        {
            m_attached = pid;
            error = EV_ERROR_NONE;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CreateBackgroundVP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CreateBackgroundVP
    (const char* stdIn, const char* stdOut, const char* stdErr,
     const char* filename,
     char*const argv[]) 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CreateDaemonVP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CreateDaemonVP
    (const char* stdIn, const char* stdOut, const char* stdErr,
     const char* filename,
     char*const argv[]) 
    {
        EvError error = EV_ERROR_FAILED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Wait
    //
    //   Author: $author$
    //     Date: 7/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Wait() 
    {
        EvError error = EV_ERROR_FAILED;
        PID pid;
        int err;

        if (0 >= m_attached)
            DBE("() invalid pid %d\n", m_attached);

        else if (m_attached != (pid = waitpid(m_attached, &err, 0)))
        {
            if (pid >= 0)
                DBE("() %d != (%d == waitpid(%d,...))\n", m_attached, pid, m_attached);

            else if (ECHILD == errno)
            {
                DBF("() pid %d is not child of pid %d\n", m_attached, getpid());
                error = EV_ERROR_NONE;
            }
            else if (EINTR == errno)
                    DBF("() waitpid(%d,...) was interrupted\n", m_attached);

            else if (EINVAL == errno)
                    DBF("() invalid options for waitpid(%d,...)\n", m_attached);

            else DBE("() failed on waitpid(%d,...)\n", m_attached);
        }
        else error = EV_ERROR_NONE;
        return error;
    }
};
#endif // _CEVPID_HPP
