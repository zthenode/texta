///////////////////////////////////////////////////////////////////////
//   File: evdm.cpp
//
// Author: $author$
//   Date: 8/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////
#include "cevdmanagermain.hpp"
///////////////////////////////////////////////////////////////////////
//  Class: CEvdManagerMain
//
// Author: $author$
//   Date: 8/3/2007
///////////////////////////////////////////////////////////////////////
CEvdManagerMain g_evdManagerMain;

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvdManagerRestartServerMainArg
//
// Author: $author$
//   Date: 8/4/2007
///////////////////////////////////////////////////////////////////////
class CEvEvdManagerRestartServerMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvEvdManagerRestartServerMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvdManagerRestartServerMainArg
    //
    //       Author: $author$
    //         Date: 8/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvdManagerRestartServerMainArg
    (const char* shortName="r",
     const char* longName="restart",
     const char* description="Restart Server",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 8/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_evdManagerMain.RestartServer();
        g_evdManagerMain.SetDidMain();
        return argn;
    }
} g_evdManagerRestartServerArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvdManagerStartServerMainArg
//
// Author: $author$
//   Date: 8/4/2007
///////////////////////////////////////////////////////////////////////
class CEvEvdManagerStartServerMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvEvdManagerStartServerMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvdManagerStartServerMainArg
    //
    //       Author: $author$
    //         Date: 8/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvdManagerStartServerMainArg
    (const char* shortName="s",
     const char* longName="start",
     const char* description="Start Server",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 8/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_evdManagerMain.StartServer();
        g_evdManagerMain.SetDidMain();
        return argn;
    }
} g_evdManagerStartServerArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvEvdManagerStopServerMainArg
//
// Author: $author$
//   Date: 8/4/2007
///////////////////////////////////////////////////////////////////////
class CEvEvdManagerStopServerMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvEvdManagerStopServerMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvEvdManagerStopServerMainArg
    //
    //       Author: $author$
    //         Date: 8/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvEvdManagerStopServerMainArg
    (const char* shortName="t",
     const char* longName="stop",
     const char* description="Stop Server",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 8/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_evdManagerMain.StopServer();
        g_evdManagerMain.SetDidMain();
        return argn;
    }
} g_evdManagerStopServerArg;
