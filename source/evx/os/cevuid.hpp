///////////////////////////////////////////////////////////////////////
//   File: cevuid.hpp
//
// Author: $author$
//   Date: 7/18/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVUID_HPP
#define _CEVUID_HPP

#include "evplatform_pwd.h"
#include "evplatform_uid.h"
#include "evuid.hpp"
#include "cevattached.hpp"
#include "cevstring.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvUIDAttached
//
//   Author: $author$
//     Date: 7/18/2007
///////////////////////////////////////////////////////////////////////
typedef CEvAttached
<UID, UID, INVALID_UID, 
 EvUIDAttached, CEvBase>
CEvUIDAttached;

///////////////////////////////////////////////////////////////////////
//  Class: CEvUid
//
// Author: $author$
//   Date: 7/18/2007
///////////////////////////////////////////////////////////////////////
class CEvUid
: virtual public EvUid,
  public CEvUIDAttached
{
public:
    typedef EvUid CImplements;
    typedef CEvUIDAttached CExtends;
    typedef CEvUid CDerives;

    CEvString m_userName;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvUid
    //
    //       Author: $author$
    //         Date: 7/18/2007
    ///////////////////////////////////////////////////////////////////////
    CEvUid() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvUid
    //
    //      Author: $author$
    //        Date: 7/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvUid()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetCurrentUid
    //
    //   Author: $author$
    //     Date: 7/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetCurrentUid
    (UID uid) 
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
    // Function: GetCurrentUid
    //
    //   Author: $author$
    //     Date: 7/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetCurrentUid
    (UID& uid) 
    {
        EvError error = EV_ERROR_NONE;
        uid = (m_attached = getuid());
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetUidOf
    //
    //   Author: $author$
    //     Date: 7/18/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetUidOf
    (UID& uid, const char* userName, LONG length=-1)
    {
        EvError error = EV_ERROR_FAILED;
#if defined(WIN32) 
// Windows
#else // defined(WIN32) 
// Unix
#endif // defined(WIN32)
        struct passwd* passwd;
        int unequal;

        if (0 > (length = m_userName.Assign(userName, length)))
            return error;

        setpwent();
        while ((passwd = getpwent()))
        {
            if (!(unequal = m_userName.Compare(passwd->pw_name)))
            {
                uid = passwd->pw_uid;
                error = EV_ERROR_NONE;
                break;
            }
        }
        endpwent();
        return error;
    }
};
#endif // _CEVUID_HPP
