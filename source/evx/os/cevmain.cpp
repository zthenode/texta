///////////////////////////////////////////////////////////////////////
//   File: cevmain.cpp
//
// Author: $author$
//   Date: 4/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////
#include "cevmainarg.hpp"
#include "cevmain.hpp"
#include "evdebug.h"

///////////////////////////////////////////////////////////////////////
//  Class: CEvMainArgList
//
// Author: $author$
//   Date: 4/4/2007
///////////////////////////////////////////////////////////////////////
template<>
CEvMainArgItem* CEvMainArgList::CExtends::m_firstItem = 0;

template<>
CEvMainArgItem* CEvMainArgList::CExtends::m_lastItem = 0;

///////////////////////////////////////////////////////////////////////
//  Class: CEvMainArg
//
// Author: $author$
//   Date: 4/4/2007
///////////////////////////////////////////////////////////////////////
CEvMainArgList CEvMainArg::m_list;

///////////////////////////////////////////////////////////////////////
//  Class: CEvMain
//
// Author: $author$
//   Date: 4/3/2007
///////////////////////////////////////////////////////////////////////
CEvMain* CEvMain::m_main = 0;

///////////////////////////////////////////////////////////////////////
//  Class: CEvDebugMainArg
//
// Author: $author$
//   Date: 4/4/2007
///////////////////////////////////////////////////////////////////////
class CEvDebugMainArg
: public CEvMainArg
{
public:
    typedef CEvMainArg CExtends;
    typedef CEvDebugMainArg CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvDebugMainArg
    //
    //       Author: $author$
    //         Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvDebugMainArg
	(const char* shortName="d",
	 const char* longName="db",
     const char* description="Debug levels",
     const char* parameters="levels:Debug levels")
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
        const char* name;
        LONG length;
        int level;

        if ((arg = MainArgParam(argn, arg, argc, argv)))
        {
            if ((0 > (level = atoi(arg)))
                || ((int)(sizeof(EvDebugLevels)*8) < level))
            {
                SET_EV_DEBUG_LEVELS(DEFAULT_EV_DEBUG_LEVELS);
                DBE("() invalid debug level %d\n", level);
            }
            else SET_EV_DEBUG_LEVELS(level);
        }
        else 
        {
            if ((name = GetLongName(length)))
                printf("%s: %x\n", name, GET_EV_DEBUG_LEVELS());
        }
        return argn;
    }
} g_debugArg;
