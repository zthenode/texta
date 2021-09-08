///////////////////////////////////////////////////////////////////////
//   File: evls.hpp
//
// Author: $author$
//   Date: 6/1/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVLS_HPP
#define _EVLS_HPP

#include "cevfiledirectory.hpp"
#include "cevfilepath.hpp"
#include "cevsystemdate.hpp"
#include "cevsystemtime.hpp"
#include "cevdate.hpp"
#include "cevtime.hpp"
#include "cevfilepath.hpp"
#include "cevcharfile.hpp"
#include "cevmain.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsMain
//
// Author: $author$
//   Date: 6/1/2007
///////////////////////////////////////////////////////////////////////
class CEvLsMain
: public CEvMain
{
public:
    typedef CEvMain CExtends;
    typedef CEvLsMain CDerives;

    CEvFilePath m_filePath;
    CEvCharFile m_file;
    CEvSystemDate m_date;
    CEvSystemTime m_time;
    CEvFileSystemEntry m_fileEntry;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsMain
    //
    //       Author: $author$
    //         Date: 6/1/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsMain() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvLsMain
    //
    //      Author: $author$
    //        Date: 6/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvLsMain()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //    Author: $author$
    //      Date: 6/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, const char** argv, const char** env) 
    {
        int err = 0;
        const char* path = "C:/source/chipcon.tgz";
        EvError error = EV_ERROR_FAILED;
        UINT y,d;
        UINT h,m,s;
        bool pm;
        LONG length;
        int i, type;
        const char* chars;
        const EvFileTime* fileTime;
        const_CEvFileTimesIterator fileTimes;
        CEvFilePath filePath;
        CEvFileDirectory fileDir;
        EvFileDirectoryEntry* fileEntry;

        if (0 < (length = filePath.Assign(path)))
        if ((chars = filePath.GetFileDirectory(length)) && (0 < length))
        if (!(error = fileDir.OpenPath(chars)))
        {
            if ((fileEntry = fileDir.GetFirstEntry(error)))
            do
            {
                printf("%s", fileEntry->GetName(length));
                if ((fileTime = fileEntry->GetFirstFileTime(fileTimes)))
                do
                {
                    printf("%s %d/%d/%d\n", fileTime->GetTypeName(fileTime->GetType()), fileTime->GetYear(), fileTime->GetMonth(), fileTime->GetDay());
                }
                while ((fileTime = fileEntry->GetNextFileTime(fileTimes)));
            }
            while (!(error = fileEntry->GetNextEntry()));
            fileDir.Close();
        }
        return err;

        if (0 < (type = m_fileEntry.Exists(path)))
        if ((fileTime = m_fileEntry.GetFirstFileTime(fileTimes)))
        do
        {
            printf("%s %d/%d/%d\n", fileTime->GetTypeName(fileTime->GetType()), fileTime->GetYear(), fileTime->GetMonth(), fileTime->GetDay());
        }
        while ((fileTime = m_fileEntry.GetNextFileTime(fileTimes)));
        return err;

        if (!(error = m_time.GetCurrentTime
            (h, m, s, pm, true, true)))
            printf("%u:%u:%u", h, m, s);

        if (!(error = m_date.GetCurrentDate
            (y, m, d, true)))
            printf("%u:/%u/%u", m, d, y);

        if (!(error = m_file.Open("T4096.txt","wb")))
        {
            if (0 < (length = m_file.Write("1", 1)))
            {
                for (i = 0; i < 4094; i++)
                    m_file.Write("2", 1);
                m_file.Write("3", 1);
            }
            m_file.Close();
        }

        do
        {
            if (0 < (length = m_filePath.Assign(path)))
                error = m_filePath.MakeDirectory();
        }
        while (!error);

        return err;
    }
};
#endif // _EVLS_HPP
