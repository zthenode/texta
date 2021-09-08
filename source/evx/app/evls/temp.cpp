///////////////////////////////////////////////////////////////////////
//   File: evls.cpp
//
// Author: $author$
//   Date: 6/1/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "evls.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsMain
//
// Author: $author$
//   Date: 6/1/2007
///////////////////////////////////////////////////////////////////////

CEvLsMain g_lsMain;

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsBeforeMainArg
//
// Author: $author$
//   Date: 6/30/2007
///////////////////////////////////////////////////////////////////////
class CEvLsBeforeMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsBeforeMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsBeforeMainArg
    //
    //       Author: $author$
    //         Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsBeforeMainArg
    (const char* shortName="b",
     const char* longName="output-before",
     const char* description="Output Before",
     const char* parameters="before:Output Before")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char*  value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_lsMain.SetOutputBefore(arg);
        else 
        {
            if ((name = GetLongName(length)))
            if ((value = g_lsMain.GetOutputBefore(length)))
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_lsBeforeArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsBetweenMainArg
//
// Author: $author$
//   Date: 6/30/2007
///////////////////////////////////////////////////////////////////////
class CEvLsBetweenMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsBetweenMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsBetweenMainArg
    //
    //       Author: $author$
    //         Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsBetweenMainArg
    (const char* shortName="t",
     const char* longName="output-between",
     const char* description="Output Between",
     const char* parameters="between:Output Between")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char*  value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_lsMain.SetOutputBetween(arg);
        else 
        {
            if ((name = GetLongName(length)))
            if ((value = g_lsMain.GetOutputBetween(length)))
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_lsBetweenArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsAfterMainArg
//
// Author: $author$
//   Date: 6/30/2007
///////////////////////////////////////////////////////////////////////
class CEvLsAfterMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsAfterMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsAfterMainArg
    //
    //       Author: $author$
    //         Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsAfterMainArg
    (const char* shortName="a",
     const char* longName="output-after",
     const char* description="Output After",
     const char* parameters="after:Output After")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char*  value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_lsMain.SetOutputAfter(arg);
        else 
        {
            if ((name = GetLongName(length)))
            if ((value = g_lsMain.GetOutputAfter(length)))
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_lsAfterArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsSourceMainArg
//
// Author: $author$
//   Date: 8/2/2007
///////////////////////////////////////////////////////////////////////
class CEvLsSourceMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsSourceMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsSourceMainArg
    //
    //       Author: $author$
    //         Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsSourceMainArg
    (const char* shortName="s",
     const char* longName="output-source",
     const char* description="Output Source Only",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_lsMain.SetOutputSourceOnly();
        return argn;
    }
} g_lsSourceArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsTargetMainArg
//
// Author: $author$
//   Date: 8/2/2007
///////////////////////////////////////////////////////////////////////
class CEvLsTargetMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsTargetMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsTargetMainArg
    //
    //       Author: $author$
    //         Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsTargetMainArg
    (const char* shortName="t",
     const char* longName="output-target",
     const char* description="Output Target Only",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_lsMain.SetOutputTargetOnly();
        return argn;
    }
} g_lsTargetArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsRecursiveMainArg
//
// Author: $author$
//   Date: 6/29/2007
///////////////////////////////////////////////////////////////////////
class CEvLsRecursiveMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsRecursiveMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsRecursiveMainArg
    //
    //       Author: $author$
    //         Date: 6/29/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsRecursiveMainArg
    (const char* shortName="r",
     const char* longName="recursive",
     const char* description="Recursive",
     const char* parameters="recursive:Recursive")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 6/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_lsMain.SetIsRecursive();
        return argn;
    }
} g_lsRecursiveArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsReflectiveMainArg
//
// Author: $author$
//   Date: 6/29/2007
///////////////////////////////////////////////////////////////////////
class CEvLsReflectiveMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsReflectiveMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsReflectiveMainArg
    //
    //       Author: $author$
    //         Date: 6/29/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsReflectiveMainArg
    (const char* shortName="f",
     const char* longName="reflective",
     const char* description="Reflective",
     const char* parameters="reflective:Reflective")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 6/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_lsMain.SetIsReflective();
        return argn;
    }
} g_lsReflectiveArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsMatchFileMainArg
//
// Author: $author$
//   Date: 8/4/2008
///////////////////////////////////////////////////////////////////////
class CEvLsMatchFileMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsMatchFileMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsMatchFileMainArg
    //
    //       Author: $author$
    //         Date: 8/4/2008
    ///////////////////////////////////////////////////////////////////////
    CEvLsMatchFileMainArg
    (const char* shortName="M",
     const char* longName="match-file",
     const char* description="Use match file",
     const char* parameters="filename:Match filename to use")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 8/4/2008
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char* value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_lsMain.SetMatchFilename(arg);
        else 
        {
			g_lsMain.SetDidMain();
            if ((name = GetLongName(length)))
            if ((value = g_lsMain.GetMatchFilename(length)))
                printf("%s: %s\n", name, value);
        }
        return argn;
    }
} g_LsMatchFileArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsMatchMainArg
//
// Author: $author$
//   Date: 6/29/2007
///////////////////////////////////////////////////////////////////////
class CEvLsMatchMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsMatchMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsMatchMainArg
    //
    //       Author: $author$
    //         Date: 6/29/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsMatchMainArg
    (const char* shortName="m",
     const char* longName="match",
     const char* description="Match",
     const char* parameters="match:Match")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 6/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char* value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_lsMain.SetMatch(arg);
        else 
        {
			g_lsMain.SetDidMain();
            if ((name = GetLongName(length)))
            if ((value = g_lsMain.GetMatch(length)))
                printf("%s: %s\n", name, value);
        }
        return argn;
    }
} g_lsMatchArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsSkipMainArg
//
// Author: $author$
//   Date: 8/24/2007
///////////////////////////////////////////////////////////////////////
class CEvLsSkipMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsSkipMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsSkipMainArg
    //
    //       Author: $author$
    //         Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsSkipMainArg
    (const char* shortName="k",
     const char* longName="skip",
     const char* description="Skip",
     const char* parameters="skip:Skip")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char*  value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_lsMain.SetSkip(arg);
        else 
        {
			g_lsMain.SetDidMain();
            if ((name = GetLongName(length)))
            if ((value = g_lsMain.GetSkip(length)))
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_lsSkipArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsMatchCaseMainArg
//
// Author: $author$
//   Date: 7/25/2007
///////////////////////////////////////////////////////////////////////
class CEvLsMatchCaseMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsMatchCaseMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsMatchCaseMainArg
    //
    //       Author: $author$
    //         Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsMatchCaseMainArg
    (const char* shortName="c",
     const char* longName="match-case",
     const char* description="Match case on patterns",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_lsMain.SetMatchCase();
        return argn;
    }
} g_lsMatchCaseArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsIgnoreCaseMainArg
//
// Author: $author$
//   Date: 7/25/2007
///////////////////////////////////////////////////////////////////////
class CEvLsIgnoreCaseMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsIgnoreCaseMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsIgnoreCaseMainArg
    //
    //       Author: $author$
    //         Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsIgnoreCaseMainArg
    (const char* shortName="i",
     const char* longName="ignore-case",
     const char* description="Ignore case on patterns",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_lsMain.SetMatchCase(false);
        return argn;
    }
} g_lsIgnoreCaseArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsCompareFilesMainArg
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////
class CEvLsCompareFilesMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsCompareFilesMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsCompareFilesMainArg
    //
    //       Author: $author$
    //         Date: 11/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsCompareFilesMainArg
    (const char* shortName="p",
     const char* longName="compare-files",
     const char* description="Compare files",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 11/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_lsMain.SetCompareFiles();
        return argn;
    }
} g_lsCompareFilesArg;
