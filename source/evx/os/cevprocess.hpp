///////////////////////////////////////////////////////////////////////
//   File: cevprocess.hpp
//
// Author: $author$
//   Date: 5/2/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVPROCESS_HPP
#define _CEVPROCESS_HPP

#include "cevbuffer.hpp"
#include "evprocess.hpp"
#include "cevattached.hpp"

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

///////////////////////////////////////////////////////////////////////
// Typedef: CEvProcessAttached
//
//  Author: $author$
//    Date: 5/2/2007
///////////////////////////////////////////////////////////////////////
typedef CEvAttached
<PROCESS, INVALID_PROCESS_T, INVALID_PROCESS, 
 EvProcessAttached, CEvBase> 
CEvProcessAttached;

///////////////////////////////////////////////////////////////////////
//  Class: CEvProcess
//
// Author: $author$
//   Date: 5/2/2007
///////////////////////////////////////////////////////////////////////
class CEvProcess
: virtual public EvProcess,
  public CEvProcessAttached
{
public:
    typedef EvProcess CImplements;
    typedef CEvProcessAttached CExtends;
    typedef CEvProcess CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvProcess
    //
    //       Author: $author$
    //         Date: 5/2/2007
    ///////////////////////////////////////////////////////////////////////
    CEvProcess(PROCESS attached=INVALID_PROCESS)
    : CExtends(attached)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvProcess
    //
    //       Author: $author$
    //         Date: 5/2/2007
    ///////////////////////////////////////////////////////////////////////
    CEvProcess(const CEvProcess& process)
    : CExtends(process.Attached())
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvProcess
    //
    //      Author: $author$
    //        Date: 5/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvProcess()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CreateLP
    //
    //   Author: $author$
    //     Date: 5/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CreateLP
    (const char* filename, ...) 
    {
        EvError error = EV_ERROR_FAILED;
        va_list va;

        if (INVALID_PROCESS != m_attached)
            return error = EV_ERROR_ALREADY_ATTACHED;

        va_start(va, filename);
        error = VCreateP(filename, va);
        va_end(va);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: VCreateP
    //
    //   Author: $author$
    //     Date: 5/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError VCreateP
    (const char* filename, va_list va) 
    {
        EvError error = EV_ERROR_FAILED;
        LONG length;
        const char*const* argv;
        CEvBuffer<const char*> argvBuffer;

        if (INVALID_PROCESS != m_attached)
            return error = EV_ERROR_ALREADY_ATTACHED;

        argvBuffer.Append(&filename, 1);
        argvBuffer.VAppend(va);

        if ((argv = argvBuffer.Buffer(length)))
            error = CreateVP(filename, argv);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CreateVP
    //
    //   Author: $author$
    //     Date: 5/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CreateVP
    (const char* filename, const char*const* argv) 
    {
        EvError error = EV_ERROR_FAILED;

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
        pid_t pid;
        int err;

        if (!(pid = fork()))
        {
            DBF("() forked %d...\n", getpid());
            if ((err = execvp(filename, (char*const*)argv)))
                DBE("() failed to execvp(\"%s\", ...)\n", filename);
            exit(1);
        }

        if (0 < pid)
        {
            m_attached = pid;
            error = EV_ERROR_NONE;
        }
        else DBE("() failed to fork\n");
#endif // defined(WIN32)

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Wait
    //
    //   Author: $author$
    //     Date: 5/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Wait(LONG milliseconds=INFINITE) 
    {
        EvError error = EV_ERROR_FAILED;

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
        pid_t pid;
        int err;
        
        DBF("(LONG milliseconds=%d) in...\n", milliseconds);

        if (INFINITE != milliseconds)
            return EV_ERROR_NOT_IMPLEMENTED;

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

        DBF("(LONG milliseconds=%d) ...out\n", milliseconds);
#endif // defined(WIN32)

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Hup
    //
    //   Author: $author$
    //     Date: 5/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Hup() 
    {
        EvError error = EV_ERROR_FAILED;

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Term
    //
    //   Author: $author$
    //     Date: 5/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Term() 
    {
        EvError error = EV_ERROR_FAILED;

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Kill
    //
    //   Author: $author$
    //     Date: 5/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Kill() 
    {
        EvError error = EV_ERROR_FAILED;

#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)

        return error;
    }
};
#endif // _CEVPROCESS_HPP
