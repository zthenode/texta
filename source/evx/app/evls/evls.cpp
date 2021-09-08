///////////////////////////////////////////////////////////////////////
//   File: evls.cpp
//
// Author: $author$
//   Date: 6/1/2007
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
//  Class: CEvLsBeforeDirectoryMainArg
//
// Author: $author$
//   Date: 6/30/2007
///////////////////////////////////////////////////////////////////////
class CEvLsBeforeDirectoryMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsBeforeDirectoryMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsBeforeDirectoryMainArg
    //
    //       Author: $author$
    //         Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsBeforeDirectoryMainArg
    (const char* shortName="B",
     const char* longName="before-directory",
     const char* description="Output Before Directory",
     const char* parameters="before:Output Before Directory")
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
            g_lsMain.SetOutputBeforeDirectory(arg);
        else 
        {
            if ((name = GetLongName(length)))
            if ((value = g_lsMain.GetOutputBeforeDirectory(length)))
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_lsBeforeDirectoryArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsAfterDirectoryMainArg
//
// Author: $author$
//   Date: 6/30/2007
///////////////////////////////////////////////////////////////////////
class CEvLsAfterDirectoryMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsAfterDirectoryMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsAfterDirectoryMainArg
    //
    //       Author: $author$
    //         Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsAfterDirectoryMainArg
    (const char* shortName="A",
     const char* longName="after-directory",
     const char* description="Output After Directory",
     const char* parameters="after:Output After Directory")
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
            g_lsMain.SetOutputAfterDirectory(arg);
        else 
        {
            if ((name = GetLongName(length)))
            if ((value = g_lsMain.GetOutputAfterDirectory(length)))
                printf("%s: %s \n", name, value);
        }
        return argn;
    }
} g_lsAfterDirectoryArg;

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
    (const char* shortName="w",
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
//  Class: CEvLsDirectoryOnlyMainArg
//
// Author: $author$
//   Date: 8/2/2007
///////////////////////////////////////////////////////////////////////
class CEvLsDirectoryOnlyMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsDirectoryOnlyMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsDirectoryOnlyMainArg
    //
    //       Author: $author$
    //         Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsDirectoryOnlyMainArg
    (const char* shortName="Y",
     const char* longName="directory-only",
     const char* description="Output Directory Only",
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
        g_lsMain.SetOutputDirectoryOnly();
        return argn;
    }
} g_lsDirectoryOnlyArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsNameMainArg
//
// Author: $author$
//   Date: 8/2/2007
///////////////////////////////////////////////////////////////////////
class CEvLsNameMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsNameMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsNameMainArg
    //
    //       Author: $author$
    //         Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsNameMainArg
    (const char* shortName="n",
     const char* longName="output-name",
     const char* description="Output Name Only",
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
        g_lsMain.SetOutputNameOnly();
        return argn;
    }
} g_lsNameArg;

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
//  Class: CEvLsIterativeMainArg
//
// Author: $author$
//   Date: 10/25/2020
///////////////////////////////////////////////////////////////////////
class CEvLsIterativeMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsIterativeMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsIterativeMainArg
    //
    //       Author: $author$
    //         Date: 10/25/2020
    ///////////////////////////////////////////////////////////////////////
    CEvLsIterativeMainArg
    (const char* shortName="1",
     const char* longName="iterative",
     const char* description="Iterative",
     const char* parameters="")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 10/25/2020
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        g_lsMain.SetIsRecursive(false);
        return argn;
    }
} g_lsIterativeArg;

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
     const char* parameters="")
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
//  Class: CEvLsSkipFileMainArg
//
// Author: $author$
//   Date: 11/13/2009
///////////////////////////////////////////////////////////////////////
class CEvLsSkipFileMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsSkipFileMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsSkipFileMainArg
    //
    //       Author: $author$
    //         Date: 11/13/2009
    ///////////////////////////////////////////////////////////////////////
    CEvLsSkipFileMainArg
    (const char* shortName="K",
     const char* longName="skip-file",
     const char* description="Use skip file",
     const char* parameters="filename:Skip filename to use")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 11/13/2009
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        const char* name;
        const char*  value;
        LONG length;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            g_lsMain.SetSkipFilename(arg);
        else 
        {
			g_lsMain.SetDidMain();
            if ((name = GetLongName(length)))
            if ((value = g_lsMain.GetSkipFilename(length)))
                printf("%s: %s\n", name, value);
        }
        return argn;
    }
} g_LsSkipFileArg;

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

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsExistingFilesMainArg
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////
class CEvLsExistingFilesMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsExistingFilesMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsExistingFilesMainArg
    //
    //       Author: $author$
    //         Date: 11/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsExistingFilesMainArg
    (const char* shortName="x",
     const char* longName="existing-files",
     const char* description="Existing files",
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
        g_lsMain.SetExistingFiles();
        return argn;
    }
} g_lsExistingFilesArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsMissingFilesMainArg
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////
class CEvLsMissingFilesMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsMissingFilesMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsMissingFilesMainArg
    //
    //       Author: $author$
    //         Date: 11/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsMissingFilesMainArg
    (const char* shortName="g",
     const char* longName="missing-files",
     const char* description="Missing files",
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
        g_lsMain.SetMissingFiles();
        return argn;
    }
} g_lsMissingFilesArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsOlderFilesMainArg
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////
class CEvLsOlderFilesMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsOlderFilesMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsOlderFilesMainArg
    //
    //       Author: $author$
    //         Date: 11/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsOlderFilesMainArg
    (const char* shortName="o",
     const char* longName="older-files",
     const char* description="Older files",
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
        g_lsMain.SetCompareOlderFiles();
        return argn;
    }
} g_lsOlderFilesArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsAllFilesMainArg
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////
class CEvLsAllFilesMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsAllFilesMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsAllFilesMainArg
    //
    //       Author: $author$
    //         Date: 11/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsAllFilesMainArg
    (const char* shortName="l",
     const char* longName="all-files",
     const char* description="All files",
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
        g_lsMain.SetCompareAllFiles();
        return argn;
    }
} g_lsAllFilesArg;


///////////////////////////////////////////////////////////////////////
//  Class: CEvLsOutputReverseMainArg
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////
class CEvLsOutputReverseMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsOutputReverseMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsOutputReverseMainArg
    //
    //       Author: $author$
    //         Date: 11/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsOutputReverseMainArg
    (const char* shortName="v",
     const char* longName="output-reverse",
     const char* description="Output in reverse",
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
        g_lsMain.SetOutputReverse();
        return argn;
    }
} g_lsOutputReverseArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsOutputDirectoryMainArg
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////
class CEvLsOutputDirectoryMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsOutputDirectoryMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsOutputDirectoryMainArg
    //
    //       Author: $author$
    //         Date: 11/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsOutputDirectoryMainArg
    (const char* shortName="y",
     const char* longName="output-directory",
     const char* description="Output directory entries",
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
        g_lsMain.SetOutputDirectory();
        return argn;
    }
} g_lsOutputDirectoryArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsExcludeFileSymbolicLinksMainArg
//
// Author: $author$
//   Date: 11/21/2007
///////////////////////////////////////////////////////////////////////
class CEvLsExcludeFileSymbolicLinksMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvLsExcludeFileSymbolicLinksMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsExcludeFileSymbolicLinksMainArg
    //
    //       Author: $author$
    //         Date: 11/21/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsExcludeFileSymbolicLinksMainArg
    (const char* shortName="u",
     const char* longName="exclude-file-links",
     const char* description="Exclude file links",
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
        g_lsMain.SetExcludeFileSymbolicLinks();
        return argn;
    }
} g_lsExcludeFileSymbolicLinksArg;

