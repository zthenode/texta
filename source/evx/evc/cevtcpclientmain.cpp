///////////////////////////////////////////////////////////////////////
//   File: cevtcpclientmain.cpp
//
// Author: $author$
//   Date: 8/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevtcpclientmain.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvTcpClientMain
//
// Author: $author$
//   Date: 8/3/2007
///////////////////////////////////////////////////////////////////////
CEvTcpClientMain* CEvTcpClientMain::m_instance = 0;

///////////////////////////////////////////////////////////////////////
//  Class: CEvTcpClientConnectMainArg
//
// Author: $author$
//   Date: 8/3/2007
///////////////////////////////////////////////////////////////////////
class CEvTcpClientConnectMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvTcpClientConnectMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvTcpClientConnectMainArg
    //
    //       Author: $author$
    //         Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    CEvTcpClientConnectMainArg
    (const char* shortName="c",
     const char* longName="connect",
     const char* description="Connect",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        CEvTcpClientMain* theMain;
        bool disconnect;
        if ((theMain = CEvTcpClientMain::GetInstance()))
            theMain->Connect(disconnect);
        return argn;
    }
} g_tcpclientConnectArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvTcpClientHostMainArg
//
// Author: $author$
//   Date: 8/3/2007
///////////////////////////////////////////////////////////////////////
class CEvTcpClientHostMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvTcpClientHostMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvTcpClientHostMainArg
    //
    //       Author: $author$
    //         Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    CEvTcpClientHostMainArg
    (const char* shortName="h",
     const char* longName="host",
     const char* description="Tcp Host",
     const char* parameters="host:Tcp Host")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        CEvTcpClientMain* theMain;
        const char* name;
        const char*  value;
        LONG length;
        if ((theMain = CEvTcpClientMain::GetInstance()))
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            theMain->SetHost(arg);
        else 
        {
            if ((name = GetLongName(length)))
            if ((value = theMain->GetHost(length)))
            if (theMain->SetDidMain())
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_tcpclientHostArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvTcpClientPortMainArg
//
// Author: $author$
//   Date: 8/3/2007
///////////////////////////////////////////////////////////////////////
class CEvTcpClientPortMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvTcpClientPortMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvTcpClientPortMainArg
    //
    //       Author: $author$
    //         Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    CEvTcpClientPortMainArg
    (const char* shortName="p",
     const char* longName="port",
     const char* description="Tcp Port",
     const char* parameters="port:Tcp Port")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 8/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        CEvTcpClientMain* theMain;
        const char* name;
        const char* value;
        int ivalue;
        LONG length;
        if ((theMain = CEvTcpClientMain::GetInstance()))
        if ((arg = MainArgParam(argn, arg, argc, argv)))
        {
            if (0 < (ivalue = atoi(arg)))
                theMain->SetPort(ivalue);
        }
        else 
        {
            if ((name = GetLongName(length)))
            if ((ivalue = theMain->GetPort()))
            if (theMain->SetDidMain())
                printf("%s: %d \n", name, ivalue);
        }
        return argn;
    }
} g_tcpclientPortArg;
