///////////////////////////////////////////////////////////////////////
//   File: cevpasswd.hpp
//
// Author: $author$
//   Date: 7/23/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVPASSWD_HPP
#define _CEVPASSWD_HPP

#include "evplatform_pwd.h"
#include "evpasswd.hpp"
#include "cevstring.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvPasswd
//
// Author: $author$
//   Date: 7/23/2007
///////////////////////////////////////////////////////////////////////
class CEvPasswd
: virtual public EvPasswd,
  public CEvBase
{
public:
    typedef EvPasswd CImplements;
    typedef CEvBase CExtends;
    typedef CEvPasswd CDerives;


    UID m_uid;
    GID m_gid;
    CEvString m_userHome;
    CEvString m_userName;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvPasswd
    //
    //       Author: $author$
    //         Date: 7/23/2007
    ///////////////////////////////////////////////////////////////////////
    CEvPasswd
    (const char* chars=0,
     LONG length=-1)
    : m_uid(INVALID_UID),
      m_gid(INVALID_GID)
    {
        EvError error;
        if (chars)
        if ((error = FindUser(chars, length)))
            throw(error);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvPasswd
    //
    //      Author: $author$
    //        Date: 7/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvPasswd()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: FindUser
    //
    //   Author: $author$
    //     Date: 7/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FindUser
    (const char* chars,
     LONG length=-1) 
    {
        EvError error = EV_ERROR_FAILED;
        struct passwd* passwd;
        int unequal;

        if (0 > (length = m_userName.Assign(chars, length)))
            return error;

        setpwent();
        while ((passwd = getpwent()))
        {
            if (!(unequal = m_userName.Compare(passwd->pw_name)))
            {
                if (0 < (length = m_userHome.Assign(passwd->pw_dir)))
                {
                    m_uid = passwd->pw_uid;
                    m_gid = passwd->pw_gid;
                    error = EV_ERROR_NONE;
                }
                break;
            }
        }
        endpwent();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FindUser
    //
    //   Author: $author$
    //     Date: 7/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError FindUser(UID uid) 
    {
        EvError error = EV_ERROR_FAILED;
        struct passwd* passwd;
        LONG length;

        setpwent();
        while ((passwd = getpwent()))
        {
            if (uid != passwd->pw_uid)
                continue;

            if (0 < (length = m_userName.Assign(passwd->pw_name)))
            if (0 < (length = m_userHome.Assign(passwd->pw_dir)))
            {
                m_uid = passwd->pw_uid;
                m_gid = passwd->pw_gid;
                error = EV_ERROR_NONE;
            }
            break;
        }
        endpwent();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetUserName
    //
    //   Author: $author$
    //     Date: 7/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetUserName
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_userName.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetUserName
    //
    //   Author: $author$
    //     Date: 7/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetUserName
    (LONG& length) const 
    {
        const char* chars = m_userName.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetUserHome
    //
    //   Author: $author$
    //     Date: 7/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetUserHome
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_userHome.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetUserHome
    //
    //   Author: $author$
    //     Date: 7/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetUserHome
    (LONG& length) const 
    {
        const char* chars = m_userHome.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetUid
    //
    //   Author: $author$
    //     Date: 7/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual UID SetUid
    (UID id) 
    {
        m_uid = id;
        return m_uid;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetUid
    //
    //   Author: $author$
    //     Date: 7/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual UID GetUid() const 
    {
        return m_uid;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetGid
    //
    //   Author: $author$
    //     Date: 7/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual GID SetGid
    (GID id) 
    {
        m_gid = id;
        return m_gid;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetGid
    //
    //   Author: $author$
    //     Date: 7/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual GID GetGid() const 
    {
        return m_gid;
    }
};
#endif // _CEVPASSWD_HPP
