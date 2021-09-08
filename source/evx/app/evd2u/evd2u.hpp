///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2012 $author$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: evd2u.hpp
//
// Author: $author$
//   Date: 2/21/2012
///////////////////////////////////////////////////////////////////////
#ifndef _EVD2U_HPP
#define _EVD2U_HPP

#include "cevfilesystem.hpp"
#include "cevfilesystementry.hpp"
#include "cevfilepath.hpp"
#include "cevfilepathstring.hpp"
#include "cevmain.hpp"
#include "cevcharfile.hpp"
#include "evdebug.h"

#define DEFAULT_CP_KB_BLOCKSIZE 64
#define DEFAULT_CP_BLOCKSIZE (DEFAULT_CP_KB_BLOCKSIZE<<10)

///////////////////////////////////////////////////////////////////////
//  Class: CEvD2UMain
//
// Author: $author$
//   Date: 2/21/2012
///////////////////////////////////////////////////////////////////////
class CEvD2UMain
: public CEvMain
{
public:
    typedef CEvMain CExtends;
    typedef CEvD2UMain CDerives;

    ULONG m_blockSize;
    char m_blockChars[DEFAULT_CP_BLOCKSIZE];

    CEvFilePath m_sourcePath;
    CEvFilePath m_targetPath;
    CEvFileSystemEntry m_sourceEntry;
    CEvFileSystemEntry m_targetEntry;

    CEvFilePath m_filePath;
    CEvFileSystem m_fileSystem;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvD2UMain
    //
    //      Author: $author$
    //        Date: 2/21/2012
    ///////////////////////////////////////////////////////////////////////
    CEvD2UMain() 
    : m_blockSize(DEFAULT_CP_BLOCKSIZE)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvD2UMain
    //
    //      Author: $author$
    //        Date: 2/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvD2UMain()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //   Author: $author$
    //     Date: 2/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, const char** argv, const char** env) 
    {
        int err = 0;
        int type;
        const char *chars, *chars2;
        LONG length, length2;

        if ((chars = m_sourcePath.Chars(length)) && (0 < length))
        if ((chars2 = m_targetPath.Chars(length2)) && (0 < length2))
        {
            if (EvFileSystemEntry::EV_TYPE_NONE
                < (type = m_sourceEntry.Exists(chars, length)))
            switch(type)
            {
            case EvFileSystemEntry::EV_TYPE_FILE:
                CopyFile(chars, chars2);
                break;
            case EvFileSystemEntry::EV_TYPE_DIRECTORY:
                break;
            }
            return err;
        }
        Help(argc, argv, env);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CopyFile
    //
    //   Author: $author$
    //     Date: 2/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CopyFile
    (const char* chars,
     const char* chars2) 
    {
        EvError error = EV_ERROR_FAILED;
        int type;

        DBT("(const char* chars=\"%s\", const chars2=\"%s\")...\n", chars, chars2);

        if (EvFileSystemEntry::EV_TYPE_NONE
            < (type = m_targetEntry.Exists(chars2)))
        switch(type)
        {
        case EvFileSystemEntry::EV_TYPE_FILE:
            error = CopyFile2File(chars, chars2);
            break;
        case EvFileSystemEntry::EV_TYPE_DIRECTORY:
            break;
        }
        else error = CopyFile2File(chars, chars2);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: 
    //
    //   Author: $author$
    //     Date: 2/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual EvError CopyFile2File
    (const char* chars,
     const char* chars2) 
    {
        EvError error = EV_ERROR_FAILED;
        bool complete = false;
        bool modified = false;
        const char* fileDir;
        CEvCharFile file, file2;
        LONG length, count;

        DBT("(const char* chars=\"%s\", const chars2=\"%s\")...\n", chars, chars2);

        if (0 < (length = m_filePath.Assign(chars2)))
        if ((fileDir = m_filePath.GetFileDirectory(length)))
        if (!(error = m_fileSystem.MakeDirectory(fileDir)))
        if (!(error = file.Open(chars, EVFILE_MODE_READ_BINARY)))
        {
#if defined(WIN32) 
            if (!(m_targetEntry.TruncateExisting(chars2)))
            if (EvFileSystemEntry::EV_TYPE_FILE & (m_targetEntry.Exists(chars2)))
            if (0 < ((m_targetEntry.GetSize())))
                unlink(chars2);
#else // defined(WIN32) 
#endif // defined(WIN32)
            if (!(error = file2.Open(chars2, EVFILE_MODE_WRITE_BINARY)))
            {
                complete = true;
                modified = false;
                do
                {
                    if (0 <= (length = file.Read
                        (m_blockChars, m_blockSize)))
                    if (length <= (count = Write2File
                        (modified, file2, m_blockChars, length)))
                        continue;
                    complete = false;
                    break;
                }
                while((LONG)m_blockSize <= length);
                file2.Flush();
                file2.Close();
            }
            file.Close();
        }
        if (modified)
            DBI("() CRs removed from \"%s\"\n", chars2);
        else
        if (complete)
            error = m_targetEntry.
            SetExistingTimes(m_sourceEntry, chars2);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: 
    //
    //   Author: $author$
    //     Date: 2/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write2File
    (bool& modified, CEvCharFile& file, 
     const char* chars, LONG length)
    {
        LONG count, i;
        for (i = 0; i < length; ++i)
        {
            char c;
            if ('\r' != (c = chars[i]))
            {
                if (1 != (count = file.Write(&c, 1)))
                    return count;
            }
            else
            modified = true;
        }
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: 
    //
    //   Author: $author$
    //     Date: 2/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArgn
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        if (arg)
        if (1 > (args = (m_mainArgs++)))
            m_sourcePath.Assign(arg);
        else if (2 > args)
            m_targetPath.Assign(arg);
        return argn;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: 
    //
    //   Author: $author$
    //     Date: 2/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetHelpArgn(int arg) const 
    {
        const char* chars = 0;
        switch(arg)
        {
        case 1:
            chars = "<source>:Source file name";
            break;
        case 2:
            chars = "<target>:Target file name";
            break;
        }
        return chars;
    }
};
#endif // _EVD2U_HPP 
