///////////////////////////////////////////////////////////////////////
//   File: cevcryptomain.cpp
//
// Author: $author$
//   Date: 11/5/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevcryptomain.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCryptoMain
//
// Author: $author$
//   Date: 11/5/2007
///////////////////////////////////////////////////////////////////////
CEvCryptoMain* CEvCryptoMain::m_theMain = 0;

///////////////////////////////////////////////////////////////////////
//  Class: CEvCrytpoMbFileMainArg
//
// Author: $author$
//   Date: 11/6/2007
///////////////////////////////////////////////////////////////////////
class CEvCrytpoMbFileMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvCrytpoMbFileMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCrytpoMbFileMainArg
    //
    //       Author: $author$
    //         Date: 11/6/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCrytpoMbFileMainArg
    (const char* shortName="m",
     const char* longName="mb-file",
     const char* description="Create a Megabyte file",
     const char* parameters="filename:Name of Megabyte File")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 11/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        CEvCryptoMain* theMain;
        if ((arg = MainArgParam(argn, arg, argc, argv)))
        if ((theMain = CEvCryptoMain::m_theMain))
            theMain->MegaByteFile(arg);
        return argn;
    }
} g_crytpoMbFileArg;

///////////////////////////////////////////////////////////////////////
//  Class: CEvCryptoDllFileMainArg
//
// Author: $author$
//   Date: 11/19/2007
///////////////////////////////////////////////////////////////////////
class CEvCryptoDllFileMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvCryptoDllFileMainArg CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCryptoDllFileMainArg
    //
    //       Author: $author$
    //         Date: 11/19/2007
    ///////////////////////////////////////////////////////////////////////
    CEvCryptoDllFileMainArg
    (const char* shortName="l",
     const char* longName="dll-file",
     const char* description="Crypto DLL filename",
     const char* parameters="filename:Crypto DLL filename")
    : CExtends(shortName, longName, description, parameters) 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 11/19/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        CEvCryptoMain* theMain;
        if ((theMain = CEvCryptoMain::m_theMain))
        if ((arg = MainArgParam(argn, arg, argc, argv)))
            theMain->SetDllFilename(arg);
        else 
        {
            theMain->OutputDllFilename();
            theMain->SetDidMain();
        }
        return argn;
    }
} g_cryptoDllFileArg;
