///////////////////////////////////////////////////////////////////////
//   File: evstat.cpp
//
// Author: $author$
//   Date: 9/1/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////
#include "evstat.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvStatMain
//
// Author: $author$
//   Date: 9/1/2007
///////////////////////////////////////////////////////////////////////
CEvStatMain g_statMain;

///////////////////////////////////////////////////////////////////////
//  Class: CEvStatInMainArg
//
// Author: $author$
//   Date: 9/4/2007
///////////////////////////////////////////////////////////////////////
class CEvStatInMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvStatInMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvStatInMainArg
    //
    //       Author: $author$
    //         Date: 9/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvStatInMainArg
    (const char* shortName="i",
     const char* longName="in",
     const char* description="In",
     const char* parameters="path:path")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 9/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_statMain.In(arg);
        return argn;
    }
} g_statInArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvStatOutMainArg
//
// Author: $author$
//   Date: 9/4/2007
///////////////////////////////////////////////////////////////////////
class CEvStatOutMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvStatOutMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvStatOutMainArg
    //
    //       Author: $author$
    //         Date: 9/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvStatOutMainArg
    (const char* shortName="o",
     const char* longName="out",
     const char* description="Out",
     const char* parameters="path:path")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 9/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_statMain.Out(arg);
        return argn;
    }
} g_statOutArg;
