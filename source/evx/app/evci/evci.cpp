///////////////////////////////////////////////////////////////////////
//   File: evci.cpp
//
// Author: $author$
//   Date: 9/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////
#include "evci.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCiMain
//
// Author: $author$
//   Date: 9/5/2007
///////////////////////////////////////////////////////////////////////
CEvCiMain g_ciMain;

///////////////////////////////////////////////////////////////////////
//  Class: CEvCiInMainArg
//
// Author: $author$
//   Date: 9/6/2007
///////////////////////////////////////////////////////////////////////
class CEvCiInMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvCiInMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCiInMainArg
    //
    //       Author: $author$
    //         Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCiInMainArg
    (const char* shortName="i",
     const char* longName="in",
     const char* description="In",
     const char* parameters="path:Path")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* local;
        const char* control;
        if ((local = MainArgParam(argn, arg, argc, argv)))
        if ((control = MainArgParam(argn, arg, argc, argv)))
            g_ciMain.In(local, control);
        return argn;
    }
} g_ciInArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvCiOutMainArg
//
// Author: $author$
//   Date: 9/6/2007
///////////////////////////////////////////////////////////////////////
class CEvCiOutMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvCiOutMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCiOutMainArg
    //
    //       Author: $author$
    //         Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCiOutMainArg
    (const char* shortName="o",
     const char* longName="out",
     const char* description="Out",
     const char* parameters="path:Path")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* local;
        const char* control;
        if ((local = MainArgParam(argn, arg, argc, argv)))
        if ((control = MainArgParam(argn, arg, argc, argv)))
            g_ciMain.Out(local, control);
        return argn;
    }
} g_ciOutArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvCiConnectMainArg
//
// Author: $author$
//   Date: 9/6/2007
///////////////////////////////////////////////////////////////////////
class CEvCiConnectMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvCiConnectMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCiConnectMainArg
    //
    //       Author: $author$
    //         Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCiConnectMainArg
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
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* host;
        int port;

        if ((host = MainArgParam(argn, arg, argc, argv)))
        if ((arg = MainArgParam(argn, arg, argc, argv)))
        if (0 < (port = atoi(arg)))
            g_ciMain.Connect(host, port);
        return argn;
    }
} g_ciConnectArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvCiRecursiveMainArg
//
// Author: $author$
//   Date: 9/8/2007
///////////////////////////////////////////////////////////////////////
class CEvCiRecursiveMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvCiRecursiveMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCiRecursiveMainArg
    //
    //       Author: $author$
    //         Date: 9/8/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCiRecursiveMainArg
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
    //     Date: 9/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_ciMain.SetIsRecursive();
        return argn;
    }
} g_ciRecursiveArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvCiMatchMainArg
//
// Author: $author$
//   Date: 9/7/2007
///////////////////////////////////////////////////////////////////////
class CEvCiMatchMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvCiMatchMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCiMatchMainArg
    //
    //       Author: $author$
    //         Date: 9/7/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCiMatchMainArg
    (const char* shortName="m",
     const char* longName="match",
     const char* description="File Match Patterns",
     const char* parameters="patterns:File Match Patterns")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 9/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char*  value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_ciMain.SetMatch(arg);
        else 
        {
            if ((name = GetLongName(length)))
            if ((value = g_ciMain.GetMatch(length)))
            if (g_ciMain.SetDidMain())
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_ciMatchArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvCiBinaryMatchMainArg
//
// Author: $author$
//   Date: 9/7/2007
///////////////////////////////////////////////////////////////////////
class CEvCiBinaryMatchMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvCiBinaryMatchMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCiBinaryMatchMainArg
    //
    //       Author: $author$
    //         Date: 9/7/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCiBinaryMatchMainArg
    (const char* shortName="y",
     const char* longName="binary-match",
     const char* description="Binary File Match Patterns",
     const char* parameters="patterns:Binary File Match Patterns")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 9/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char*  value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_ciMain.SetBinaryMatch(arg);
        else 
        {
            if ((name = GetLongName(length)))
            if ((value = g_ciMain.GetBinaryMatch(length)))
            if (g_ciMain.SetDidMain())
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_ciBinaryMatchArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvCiSkipMatchMainArg
//
// Author: $author$
//   Date: 9/7/2007
///////////////////////////////////////////////////////////////////////
class CEvCiSkipMatchMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvCiSkipMatchMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCiSkipMatchMainArg
    //
    //       Author: $author$
    //         Date: 9/7/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCiSkipMatchMainArg
    (const char* shortName="k",
     const char* longName="skip-match",
     const char* description="Skip File Match Patterns",
     const char* parameters="patterns:Skip File Match Patterns")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 9/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char*  value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_ciMain.SetSkipMatch(arg);
        else 
        {
            if ((name = GetLongName(length)))
            if ((value = g_ciMain.GetSkipMatch(length)))
            if (g_ciMain.SetDidMain())
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_ciSkipMatchArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvCiBlockSizeMainArg
//
// Author: $author$
//   Date: 9/6/2007
///////////////////////////////////////////////////////////////////////
class CEvCiBlockSizeMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvCiBlockSizeMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCiBlockSizeMainArg
    //
    //       Author: $author$
    //         Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCiBlockSizeMainArg
    (const char* shortName="z",
     const char* longName="block-size",
     const char* description="BlockSize",
     const char* parameters="blocksize:BlockSize")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 9/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        int value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
        {
            if (0 < (value = atoi(arg)))
                g_ciMain.SetBlockSize(value);
            else DBE("() invalid block size %d\n", value);
        }
        else 
        {
            g_ciMain.SetDidMain();
            if ((name = GetLongName(length)))
            if ((value = g_ciMain.GetBlockSize()))
                printf("%s: %d \n", name, value);
        }
        return argn;
    }
} g_ciBlockSizeArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvCiBlockLengthMainArg
//
// Author: $author$
//   Date: 9/8/2007
///////////////////////////////////////////////////////////////////////
class CEvCiBlockLengthMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvCiBlockLengthMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCiBlockLengthMainArg
    //
    //       Author: $author$
    //         Date: 9/8/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCiBlockLengthMainArg
    (const char* shortName="l",
     const char* longName="block-length",
     const char* description="BlockLength",
     const char* parameters="blocklength:BlockLength")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 9/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        int length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
        if (!(length = atoi(arg)))
            g_ciMain.SetIsZeroBlockLength();
        return argn;
    }
} g_ciBlockLengthArg;
