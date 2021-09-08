///////////////////////////////////////////////////////////////////////
//   File: evd.cpp
//
// Author: $author$
//   Date: 4/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////
#include "cevdmain.hpp"

CEvDMain g_evdMain;

///////////////////////////////////////////////////////////////////////
//  Class: CEvPortMainArg
//
// Author: $author$
//   Date: 4/6/2007
///////////////////////////////////////////////////////////////////////
class CEvPortMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvPortMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvPortMainArg
    //
    //       Author: $author$
    //         Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    CEvPortMainArg
	(const char* shortName="p",
	 const char* longName="port",
     const char* description="Tcp port number",
     const char* parameters="number:Tcp port number")
	: CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        int level;
        const char* chars;
        LONG length;

        if ((arg = MainArgParam(argn, arg, argc, argv)))
        if ((0 > (level = atoi(arg))))
            DBE("() invalid port number %d\n", level);
        else g_evdMain.m_tcpPort = level;
        else if ((chars = GetLongName(length)))
        {
            g_evdMain.SetDidMain();
            printf("--%s %d\n", chars, g_evdMain.m_tcpPort);
        }

        return argn;
    }
} g_portArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvThreadsMainArg
//
// Author: $author$
//   Date: 4/6/2007
///////////////////////////////////////////////////////////////////////
class CEvThreadsMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvThreadsMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvThreadsMainArg
    //
    //       Author: $author$
    //         Date: 4/6/2007
    ///////////////////////////////////////////////////////////////////////
    CEvThreadsMainArg
	(const char* shortName="t",
	 const char* longName="threads",
     const char* description="Server threads",
     const char* parameters="number:Server threads")
	: CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        int level;

        if ((arg = MainArgParam(argn, arg, argc, argv)))
        if ((0 >= (level = atoi(arg))))
            DBE("() invalid number of threads %d\n", level);
        else g_evdMain.m_tcpThreads = level;

        return argn;
    }
} g_threadsArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvServletMainArg
//
// Author: $author$
//   Date: 4/16/2007
///////////////////////////////////////////////////////////////////////
class CEvServletMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvServletMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvServletMainArg
    //
    //       Author: $author$
    //         Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    CEvServletMainArg
	(const char* shortName="s",
	 const char* longName="servlet",
     const char* description="Servlet Dll filename",
     const char* parameters="filename:Servlet Dll filename")
	: CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 4/16/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_evdMain.m_servletDllFilename = arg;
        return argn;
    }
} g_servletArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvRunMainArg
//
// Author: $author$
//   Date: 5/10/2007
///////////////////////////////////////////////////////////////////////
class CEvRunMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvRunMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvRunMainArg
    //
    //       Author: $author$
    //         Date: 5/10/2007
    ///////////////////////////////////////////////////////////////////////
    CEvRunMainArg
    (const char* shortName="r",
     const char* longName="run",
     const char* description="Run server",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 5/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_evdMain.Runit();
        return argn;
    }
} g_runArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvdDirMainArg
//
// Author: $author$
//   Date: 7/28/2007
///////////////////////////////////////////////////////////////////////
class CEvEvdDirMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvEvdDirMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvdDirMainArg
    //
    //       Author: $author$
    //         Date: 7/28/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvdDirMainArg
    (const char* shortName="e",
     const char* longName="server-dir",
     const char* description="Server Directory",
     const char* parameters="path:Server Directory")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 7/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char*  value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_evdMain.SetDir(arg);
        else 
        {
            if ((name = GetLongName(length)))
            if ((value = g_evdMain.GetDir(length)))
            if (g_evdMain.SetDidMain())
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_evdDirArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvdVcsDirMainArg
//
// Author: $author$
//   Date: 7/28/2007
///////////////////////////////////////////////////////////////////////
class CEvEvdVcsDirMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvEvdVcsDirMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvdVcsDirMainArg
    //
    //       Author: $author$
    //         Date: 7/28/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvdVcsDirMainArg
    (const char* shortName="c",
     const char* longName="vcs-dir",
     const char* description="Evcs Directory",
     const char* parameters="path:Evcs Directory")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 7/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char*  value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_evdMain.SetVcsDir(arg);
        else 
        {
            if ((name = GetLongName(length)))
            if ((value = g_evdMain.GetVcsDir(length)))
            if (g_evdMain.SetDidMain())
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_evdVcsDirArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvdCiDirMainArg
//
// Author: $author$
//   Date: 7/28/2007
///////////////////////////////////////////////////////////////////////
class CEvEvdCiDirMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvEvdCiDirMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvdCiDirMainArg
    //
    //       Author: $author$
    //         Date: 7/28/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvdCiDirMainArg
    (const char* shortName="i",
     const char* longName="ci-dir",
     const char* description="Evcs Check In Directory",
     const char* parameters="path:Evcs Check In Directory")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 7/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char*  value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_evdMain.SetCiDir(arg);
        else 
        {
            if ((name = GetLongName(length)))
            if ((value = g_evdMain.GetCiDir(length)))
            if (g_evdMain.SetDidMain())
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_evdCiDirArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvdCoDirMainArg
//
// Author: $author$
//   Date: 7/28/2007
///////////////////////////////////////////////////////////////////////
class CEvEvdCoDirMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvEvdCoDirMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvdCoDirMainArg
    //
    //       Author: $author$
    //         Date: 7/28/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvdCoDirMainArg
    (const char* shortName="o",
     const char* longName="co-dir",
     const char* description="Evcs Check Out Directory",
     const char* parameters="path:Evcs Check Out Directory")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 7/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char*  value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_evdMain.SetCoDir(arg);
        else 
        {
            if ((name = GetLongName(length)))
            if ((value = g_evdMain.GetCoDir(length)))
            if (g_evdMain.SetDidMain())
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_evdCoDirArg;
