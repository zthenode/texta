///////////////////////////////////////////////////////////////////////
//   File: evex.hpp
//
// Author: $author$
//   Date: 7/1/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVEX_HPP
#define _EVEX_HPP

#include "cevmain.hpp"
#include "cevpid.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvExMain
//
// Author: $author$
//   Date: 7/1/2007
///////////////////////////////////////////////////////////////////////
class CEvExMain
: public CEvMain
{
public:
    typedef CEvMain CExtends;
    typedef CEvExMain CDerives;

    CEvString m_user;
    CEvString m_group;
    CEvString m_home;

    int m_argn;
    CEvString m_filename;
    CEvPCCHAR2PCHARBuffer m_argv;
    CEvPid m_pid;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvExMain
    //
    //       Author: $author$
    //         Date: 7/1/2007
    ///////////////////////////////////////////////////////////////////////
    CEvExMain() 
    : m_argn(0)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //    Author: $author$
    //      Date: 7/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, const char** argv, const char** env) 
    {
        int err = 0;
        EvError error;
        LONG length;
        const char* userChars;
        const char* groupChars;
        const char* homeChars;
        const char* filenameChars;
        const PCHAR* argvPChars;

        if (0 >= m_argn)
            return Help(argc, argv, env);

        if ((homeChars = m_home.Chars(length)) && (0 >= length))
            homeChars = 0;

        if ((groupChars = m_group.Chars(length)) && (0 >= length))
            groupChars = 0;

        if ((userChars = m_user.Chars(length)) && (0 < length))
        if ((filenameChars = m_filename.Chars(length)) && (0 < length))
        if ((argvPChars = m_argv.Buffer(length)) && (0 <= length))
        if (!(error = m_pid.UGCreateVP
            (userChars, groupChars, homeChars, filenameChars, argvPChars)))
        {
            error = m_pid.Wait();
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArgn
    //
    //   Author: $author$
    //     Date: 7/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArgn
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        if (1 > (m_argn++))
            m_filename.Assign(arg);
        m_argv.Append(&arg, 1);
        return argn;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetUser
    //
    //   Author: $author$
    //     Date: 7/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetUser
    (const char* chars,
     LONG length=-1) 
    {
        const char* gChars;
        LONG gLength;

        if (0 < (length = m_user.Assign(chars,length)))
        if (!(gChars = GetGroup(gLength)) || (0 >= gLength))
            m_group.Assign(chars,length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetUser
    //
    //   Author: $author$
    //     Date: 7/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetUser
    (LONG& length) const 
    {
        const char* chars = m_user.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetGroup
    //
    //   Author: $author$
    //     Date: 7/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetGroup
    (const char* chars,
     LONG length=-1) 
    {
        length = m_group.Assign(chars,length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetGroup
    //
    //   Author: $author$
    //     Date: 7/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetGroup
    (LONG& length) const 
    {
        const char* chars = m_group.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetHelpArgn
    //
    //   Author: $author$
    //     Date: 7/23/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetHelpArgn(int argn) const 
    {
        const char* chars = 0;

        if (1 == argn)
            chars = "file:executable file name";
        else if (2 == argn)
                chars = "arg ...:executable arguments";
        return chars;
    }
};

#endif // _EVEX_HPP
