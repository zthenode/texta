///////////////////////////////////////////////////////////////////////
//   File: evc.cpp
//
// Author: $author$
//   Date: 5/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#include "cevfilepath.hpp"
#include "cevfiledirectory.hpp"
#include "cevmain.hpp"
#include "cevprocess.hpp"
#include "evdebug.h"

#define F_SYMBOLX(s) "" #s ""
#define F_SYMBOL(s) F_SYMBOLX(s)

#define F_N XX

///////////////////////////////////////////////////////////////////////
//  Class: CEvcMain
//
// Author: $author$
//   Date: 5/3/2007
///////////////////////////////////////////////////////////////////////
class CEvcMain
: public CEvMain
{
public:
    typedef CEvMain CExtends;
    typedef CEvcMain CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcMain
    //
    //       Author: $author$
    //         Date: 5/3/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcMain() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //   Author: $author$
    //     Date: 5/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc,
     const char** argv,
     const char** env) 
    {
        static const char* paths[]
        = {
        "/",
        ".",
        "..",
        "/.",
        "/..",
        "//host/user/source/project/c/src/file.c",
        "" __FILE__ "",
        "S:\\evx\\src\\os\\cevfilepathwriter.hpp",
        "\\\\S:\\evx\\src\\os\\cevfilepathwriter.hpp",
        "/.././../.hello.txt",
        ".././../.hello.txt",
        0};
        int err = 0;
        EvError error;
        CEvProcess p;
        CEvFilePath f;
        CEvFileDirectory d;
        EvFileDirectoryEntry* e;
        const char** s;
        const char* n;
        LONG l;

        DBF("() f = \"%s\"\n", F_SYMBOL(F_N));

        DBF("() in...\n");

        for (s=paths; *s; s++)
        {
            f.Assign(*s);
            DBF("() path = \"%s\"\n", f.c_str());
            DBF("() does %sexist\n", f.Exist()?"":"not ");
            DBF("() host = \"%s\"\n", f.m_host.c_str());
            DBF("() volume = \"%s\"\n", f.m_volume.c_str());
            DBF("() dir = \"%s\"\n", f.m_directory.c_str());
            DBF("() file = \"%s\"\n", f.m_fileName.c_str());
            DBF("() base = \"%s\"\n", f.m_fileBase.c_str());
            DBF("() extension = \"%s\"\n", f.m_fileExtension.c_str());
        }

        if ((error = d.OpenPath(".")))
            DBE("() failed to open directory\n");
        else
        {
            if (!(e = d.GetFirstEntry(error)))
                DBE("() failed to get first directory entry\n");
            else
            {
                do
                {
                    if ((n = e->GetName(l)))
                        DBF("() %s\"%s\"\n", (e->GetIsDirectory())?"/":" ", n);
                }
                while (!(error = e->GetNextEntry()));
            }
        }

        if (!(error = p.CreateLP("ls", "-l", 0)))
        {
            p.Wait();
        }

        DBF("() ...out\n");
        return err;
    }
} g_evcMain;
