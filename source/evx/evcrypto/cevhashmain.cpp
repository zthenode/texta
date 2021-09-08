///////////////////////////////////////////////////////////////////////
//   File: cevhashmain.cpp
//
// Author: $author$
//   Date: 11/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////
#include "cevhashmain.hpp"
///////////////////////////////////////////////////////////////////////
//  Class: CEvHashMain
//
// Author: $author$
//   Date: 11/5/2007
///////////////////////////////////////////////////////////////////////
CEvHashMain* CEvHashMain::m_theMain = 0;

///////////////////////////////////////////////////////////////////////
//  Class: CEvHashFileMainArg
//
// Author: $author$
//   Date: 11/5/2007
///////////////////////////////////////////////////////////////////////
class CEvHashFileMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvHashFileMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvHashFileMainArg
    //
    //       Author: $author$
    //         Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    CEvHashFileMainArg
    (const char* shortName="f",
     const char* longName="file",
     const char* description="File to hash",
     const char* parameters="file:File to hash")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 11/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        CEvHashMain* theMain;
        if ((theMain = CEvHashMain::m_theMain))
        {
            if ((arg = MainArgParam(argn, arg, argc, argv)))
                theMain->HashFile(arg);
            theMain->SetDidMain();
        }
        return argn;
    }
} g_hashFileArg;
