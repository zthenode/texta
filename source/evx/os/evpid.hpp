///////////////////////////////////////////////////////////////////////
//   File: evpid.hpp
//
// Author: $author$
//   Date: 7/19/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVPID_HPP
#define _EVPID_HPP

#include <stdarg.h>
#include "evplatform_uid.h"
#include "evplatform_gid.h"
#include "evplatform_pid.h"
#include "evplatform_chdir.h"
#include "evattached.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: EvPIDAttached
//
//   Author: $author$
//     Date: 7/19/2007
///////////////////////////////////////////////////////////////////////
typedef EvAttached<PID, EvBase>
EvPIDAttached;

///////////////////////////////////////////////////////////////////////
//  Class: EvPid
//
// Author: $author$
//   Date: 7/19/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvPid
: virtual public EvPIDAttached
{
public:
    typedef EvPIDAttached CImplements;
    typedef EvPid CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: CreateLP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CreateLP
    (const char* filename,...) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: CreateBackgroundLP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CreateBackgroundLP
    (const char* stdIn, const char* stdOut, const char* stdErr,
     const char* filename,...) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: CreateDaemonLP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CreateDaemonLP
    (const char* stdIn, const char* stdOut, const char* stdErr,
     const char* filename,...) = 0;

    ///////////////////////////////////////////////////////////////////////
    // Function: VCreateP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError VCreateP
    (const char* filename,
     va_list va) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: VCreateBackgroundP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError VCreateBackgroundP
    (const char* stdIn, const char* stdOut, const char* stdErr,
     const char* filename,
     va_list va) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: VCreateDaemonP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError VCreateDaemonP
    (const char* stdIn, const char* stdOut, const char* stdErr,
     const char* filename,
     va_list va) = 0;

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
     char*const argv[]) = 0;

    ///////////////////////////////////////////////////////////////////////
    // Function: CreateVP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CreateVP
    (const char* filename,
     char*const argv[]) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: CreateBackgroundVP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CreateBackgroundVP
    (const char* stdIn, const char* stdOut, const char* stdErr,
     const char* filename,
     char*const argv[]) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: CreateDaemonVP
    //
    //   Author: $author$
    //     Date: 7/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CreateDaemonVP
    (const char* stdIn, const char* stdOut, const char* stdErr,
     const char* filename,
     char*const argv[]) = 0;
};
#endif // _EVPID_HPP
