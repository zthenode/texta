///////////////////////////////////////////////////////////////////////
//   File: cevcmain.cpp
//
// Author: $author$
//   Date: 9/11/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////
#include "cevcmain.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcMain
//
// Author: $author$
//   Date: 9/11/2007
///////////////////////////////////////////////////////////////////////
CEvcMain* CEvcMain::m_main = 0;

///////////////////////////////////////////////////////////////////////
//  Class: CEvcConnectMainArg
//
// Author: $author$
//   Date: 9/11/2007
///////////////////////////////////////////////////////////////////////
class CEvcConnectMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvcConnectMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcConnectMainArg
    //
    //       Author: $author$
    //         Date: 9/11/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcConnectMainArg
    (const char* shortName="c",
     const char* longName="connect",
     const char* description="Connect",
     const char* parameters="host:host;port:port")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 9/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        CEvcMain* evcMain;
        const char* host;
        int port;

        if ((host = MainArgParam(argn, arg, argc, argv)))
        if ((arg = MainArgParam(argn, arg, argc, argv)))
        if (0 < (port = atoi(arg)))
        if ((evcMain = CEvcMain::GetMain()))
            evcMain->Connect(host, port);
        return argn;
    }
} g_evcConnectArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvcFileMainArg
//
// Author: $author$
//   Date: 9/12/2007
///////////////////////////////////////////////////////////////////////
class CEvcFileMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvcFileMainArg CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcFileMainArg
    //
    //       Author: $author$
    //         Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcFileMainArg
    (const char* shortName="f",
     const char* longName="file",
     const char* description="Response file",
     const char* parameters="filename:Response file")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 9/12/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        CEvcMain* evcMain;

        if ((arg = MainArgParam(argn, arg, argc, argv)))
        if ((evcMain = CEvcMain::GetMain()))
            evcMain->OpenResponseFile(arg);
        return argn;
    }
} g_evcFileArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvcBinaryMainArg
//
// Author: $author$
//   Date: 9/24/2007
///////////////////////////////////////////////////////////////////////
class CEvcBinaryMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvcBinaryMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcBinaryMainArg
    //
    //       Author: $author$
    //         Date: 9/24/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcBinaryMainArg
    (const char* shortName="b",
     const char* longName="binary",
     const char* description="Binary",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 9/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        CEvcMain* evcMain;
        if ((evcMain = CEvcMain::GetMain()))
            evcMain->SetIsBinary();
        return argn;
    }
} g_evcBinaryArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvcRecursiveMainArg
//
// Author: $author$
//   Date: 9/24/2007
///////////////////////////////////////////////////////////////////////
class CEvcRecursiveMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvcRecursiveMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcRecursiveMainArg
    //
    //       Author: $author$
    //         Date: 9/24/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcRecursiveMainArg
    (const char* shortName="r",
     const char* longName="recursive",
     const char* description="Recursive",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 9/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        CEvcMain* evcMain;
        if ((evcMain = CEvcMain::GetMain()))
            evcMain->SetIsRecursive();
        return argn;
    }
} g_evcRecursiveArg;
