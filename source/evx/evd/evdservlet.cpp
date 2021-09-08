///////////////////////////////////////////////////////////////////////
//   File: evdservlet.cpp
//
// Author: $author$
//   Date: 4/13/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "evdservlet.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvdServletMain
//
// Author: $author$
//   Date: 9/10/2007
///////////////////////////////////////////////////////////////////////
CEvdServletMain g_evdServletMain;

///////////////////////////////////////////////////////////////////////
//  Class: CEvevdServletRequestFileMainArg
//
// Author: $author$
//   Date: 9/10/2007
///////////////////////////////////////////////////////////////////////
class CEvevdServletRequestFileMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvevdServletRequestFileMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvevdServletRequestFileMainArg
    //
    //       Author: $author$
    //         Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    CEvevdServletRequestFileMainArg
    (const char* shortName="f",
     const char* longName="request-filename",
     const char* description="Request Filename",
     const char* parameters="filename:Request Filename")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 9/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char*  value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_evdServletMain.SetRequestFilename(arg);
        else 
        {
            g_evdServletMain.SetDidMain();
            if ((name = GetLongName(length)))
            if ((value = g_evdServletMain.GetRequestFilename(length)))
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_evdservletRequestFileArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvdServletDllMainArg
//
// Author: $author$
//   Date: 9/19/2007
///////////////////////////////////////////////////////////////////////
class CEvdServletDllMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvdServletDllMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvdServletDllMainArg
    //
    //       Author: $author$
    //         Date: 9/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvdServletDllMainArg
    (const char* shortName="s",
     const char* longName="servlet-dll",
     const char* description="Servlet Dll filename",
     const char* parameters="filename:Servlet Dll filename")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 9/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char*  value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_evdServletMain.SetServletDllFilename(arg);
        else 
        {
            if (g_evdServletMain.SetDidMain())
            if ((name = GetLongName(length)))
            if ((value = g_evdServletMain.GetServletDllFilename(length)))
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_evdServletDllArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvdServletListenMainArg
//
// Author: $author$
//   Date: 12/11/2007
///////////////////////////////////////////////////////////////////////
class CEvdServletListenMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvdServletListenMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvdServletListenMainArg
    //
    //       Author: $author$
    //         Date: 12/11/2007
    ///////////////////////////////////////////////////////////////////////
    CEvdServletListenMainArg
    (const char* shortName="l",
     const char* longName="listen",
     const char* description="Listen on tcp socket",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 12/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_evdServletMain.SetDidMain();
        g_evdServletMain.Listen();
        return argn;
    }
} g_evdServletListenArg;

