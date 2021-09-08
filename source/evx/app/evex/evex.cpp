///////////////////////////////////////////////////////////////////////
//   File: evex.cpp
//
// Author: $author$
//   Date: 7/1/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////
#include "evex.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvExMain
//
// Author: $author$
//   Date: 7/1/2007
///////////////////////////////////////////////////////////////////////

CEvExMain g_exMain;

///////////////////////////////////////////////////////////////////////
//  Class: CEvExUserMainArg
//
// Author: $author$
//   Date: 7/1/2007
///////////////////////////////////////////////////////////////////////
class CEvExUserMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvExUserMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvExUserMainArg
    //
    //       Author: $author$
    //         Date: 7/1/2007
    ///////////////////////////////////////////////////////////////////////
    CEvExUserMainArg
    (const char* shortName="u",
     const char* longName="user",
     const char* description="User",
     const char* parameters="user:User")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 7/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char*  value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_exMain.SetUser(arg);
        else 
        {
            if ((name = GetLongName(length)))
            if ((value = g_exMain.GetUser(length)))
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_exUserArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvExGroupMainArg
//
// Author: $author$
//   Date: 7/1/2007
///////////////////////////////////////////////////////////////////////
class CEvExGroupMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvExGroupMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvExGroupMainArg
    //
    //       Author: $author$
    //         Date: 7/1/2007
    ///////////////////////////////////////////////////////////////////////
    CEvExGroupMainArg
    (const char* shortName="g",
     const char* longName="group",
     const char* description="Group",
     const char* parameters="group:Group")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 7/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char*  value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_exMain.SetGroup(arg);
        else 
        {
            if ((name = GetLongName(length)))
            if ((value = g_exMain.GetGroup(length)))
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_exGroupArg;
