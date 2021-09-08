//   File: evcsd.cpp
//
// Author: $author$
//   Date: 7/30/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevcsdmain.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcsDMain
//
// Author: $author$
//   Date: 7/30/2007
///////////////////////////////////////////////////////////////////////

CEvEvcsDMain g_evcsdMain;

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcsdRunMainArg
//
// Author: $author$
//   Date: 7/31/2007
///////////////////////////////////////////////////////////////////////
class CEvEvcsdRunMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvEvcsdRunMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvcsdRunMainArg
    //
    //       Author: $author$
    //         Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvcsdRunMainArg
    (const char* shortName="r",
     const char* longName="run",
     const char* description="Run Server",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_evcsdMain.SetDidMain();
        g_evcsdMain.RunServer();
        return argn;
    }
} g_evcsdRunArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcsDCiDirectoryMainArg
//
// Author: $author$
//   Date: 7/31/2007
///////////////////////////////////////////////////////////////////////
class CEvEvcsDCiDirectoryMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvEvcsDCiDirectoryMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvcsDCiDirectoryMainArg
    //
    //       Author: $author$
    //         Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvcsDCiDirectoryMainArg
    (const char* shortName="i",
     const char* longName="ci-dir",
     const char* description="Check In Directory",
     const char* parameters="directory:Check In Directory")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char*  value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_evcsdMain.SetCiDirectory(arg);
        else 
        {
            g_evcsdMain.SetDidMain();
            if ((name = GetLongName(length)))
            if ((value = g_evcsdMain.GetCiDirectory(length)))
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_evcsdCiDirectoryArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvcsDCoDirectoryMainArg
//
// Author: $author$
//   Date: 7/31/2007
///////////////////////////////////////////////////////////////////////
class CEvEvcsDCoDirectoryMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvEvcsDCoDirectoryMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvcsDCoDirectoryMainArg
    //
    //       Author: $author$
    //         Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvcsDCoDirectoryMainArg
    (const char* shortName="o",
     const char* longName="co-dir",
     const char* description="Check Out Directory",
     const char* parameters="directory:Check Out Directory")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 7/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char*  value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_evcsdMain.SetCoDirectory(arg);
        else 
        {
            g_evcsdMain.SetDidMain();
            if ((name = GetLongName(length)))
            if ((value = g_evcsdMain.GetCoDirectory(length)))
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_evcsdCoDirectoryArg;
