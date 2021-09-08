///////////////////////////////////////////////////////////////////////
//   File: evwhat.hpp
//
// Author: $author$
//   Date: 7/24/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVWHAT_HPP
#define _EVWHAT_HPP

#include "cevmain.hpp"
#include "cevpasswd.hpp"
#include "cevuid.hpp"
#include "cevgid.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvWhatMain
//
// Author: $author$
//   Date: 7/24/2007
///////////////////////////////////////////////////////////////////////
class CEvWhatMain
: public CEvMain
{
public:
    typedef CEvMain CExtends;
    typedef CEvWhatMain CDerives;

    CEvUid m_uid;
    CEvGid m_gid;
    CEvPasswd m_passwd;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvWhatMain
    //
    //       Author: $author$
    //         Date: 7/24/2007
    ///////////////////////////////////////////////////////////////////////
    CEvWhatMain() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //    Author: $author$
    //      Date: 7/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, const char** argv, const char** env) 
    {
        int err = 0;
        EvError error;
        UID uid;
        GID gid;
        const char* chars;
        LONG length;

        if ((error = m_gid.GetCurrentGid(gid)))
            DBE("() failed to get current gid\n");
        else printf("GID: %d\n", gid);

        if ((error = m_uid.GetCurrentUid(uid)))
            DBE("() failed to get current uid\n");
        else 
        {
            printf("UID: %d\n", uid);

            if (!(error = m_passwd.FindUser(uid)))
            {
                if ((chars = m_passwd.GetUserName(length)))
                    printf("User: %s\n", chars);

                if ((chars = m_passwd.GetUserHome(length)))
                    printf("Home: %s\n", chars);
            }
        }
        return err;
    }
};

#endif // _EVWHAT_HPP
