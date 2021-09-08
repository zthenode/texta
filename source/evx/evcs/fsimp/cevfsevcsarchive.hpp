///////////////////////////////////////////////////////////////////////
//   File: cevfsevcsarchive.hpp
//
// Author: $author$
//   Date: 10/1/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFSEVCSARCHIVE_HPP
#define _CEVFSEVCSARCHIVE_HPP

#include "cevcsarchive.hpp"
#include "cevfsevcsget.hpp"
#include "cevfsevcsput.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvfsEvcsArchive
//
// Author: $author$
//   Date: 10/1/2007
///////////////////////////////////////////////////////////////////////
class CEvfsEvcsArchive
: public CEvcsArchive
{
public:
    typedef CEvcsArchive CExtends;
    typedef CEvfsEvcsArchive CDerives;

    CEvFilePath m_vcDirectory;
    CEvFilePath m_vcPath;
    CEvFilePath m_vcFilePath;
    CEvFilePath m_vcLockPath;
    CEvFilePath m_vcLockFilePath;

    CEvFilePath m_entryPath;

    const char* m_versionDirectoryChars;
    const char* m_versionExtensionChars;

    const char* m_lockDirectoryChars;
    const char* m_lockExtensionChars;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvfsEvcsArchive
    //
    //       Author: $author$
    //         Date: 10/1/2007
    ///////////////////////////////////////////////////////////////////////
    CEvfsEvcsArchive
    (const char* vcDirectory=DEFAULT_EVFSEVCS_VC_DIRECTORY) 
    : m_versionDirectoryChars(0),
      m_versionExtensionChars(0),
      m_lockDirectoryChars(DEFAULT_EVFSEVCS_LOCK_DIRECTORY),
      m_lockExtensionChars(DEFAULT_EVFSEVCS_LOCK_EXTENSION)
    {
        EvError error;
        LONG length;

        if (vcDirectory)
        if (0 > (length = m_vcDirectory.AssignChars(vcDirectory)))
            throw(error = -length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvfsEvcsArchive
    //
    //      Author: $author$
    //        Date: 10/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvfsEvcsArchive()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Close() 
    {
        EvError error = DeleteInstance();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetEntry
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsGet* GetEntry
    (EvError& error,
     EvcsEntry& entry,
     const char* entryPathName,
     bool isRecursive=false) 
    {
        EvcsGet* get = 0;
        EvError error2;
        
        error = EV_ERROR_NONE;

        if ((get = new CEvfsEvcsGet(*this)))
        {
            if ((error2 = get->OpenFirst
                (entry, entryPathName, isRecursive)))
                error = EV_ERROR_FAILED;
            else 
            {
                AddAction(*get);
                return get;
            }

            get->DeleteInstance();
        }
        else error = EV_ERROR_NEW;
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: PutEntry
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsPut* PutEntry
    (EvError& error,
     const EvcsEntry& entry,
     const char* entryPathName) 
    {
        EvcsPut* put = 0;
        EvError error2;
        
        error = EV_ERROR_NONE;

        if ((put = new CEvfsEvcsPut(*this)))
        {
            if ((error2 = put->Open
                (entry, entryPathName)))
                error = EV_ERROR_FAILED;
            else 
            {
                AddAction(*put);
                return put;
            }

            put->DeleteInstance();
        }
        else error = EV_ERROR_NEW;
        return put;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: LockEntry
    //
    //   Author: $author$
    //     Date: 10/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError LockEntry
    (const EvcsEntry& entry,
     const char* entryPathName,
     bool isExclusive=false,
     bool isDefered=false) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if (!(error2 = MakeVcLockPath(entryPathName)))
            error = EV_ERROR_NONE;

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: UnlockEntry
    //
    //   Author: $author$
    //     Date: 10/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError UnlockEntry
    (const EvcsEntry& entry,
     const char* entryPathName) 
    {
        EvError error = EV_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: MakeVcPath
    //
    //   Author: $author$
    //     Date: 10/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError MakeVcPath
    (const char* entryPathName) 
    {
        EvError error = EV_ERROR_FAILED;
        const char* vcPathName;
        const char* chars;
        LONG length;

        if ((chars = m_vcDirectory.Chars(length)))
        if (0 < (length = m_vcPath.AssignChars(chars)))
        if (0 < (length = m_vcFilePath.AssignChars(chars)))
        if (0 < (length = m_vcFilePath.AppendFileName(entryPathName)))
        if ((vcPathName = m_vcFilePath.HasChars(length)))
            error = EV_ERROR_NONE;

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: MakeVcLockPath
    //
    //   Author: $author$
    //     Date: 10/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError MakeVcLockPath
    (const char* entryPathName) 
    {
        EvError error = EV_ERROR_FAILED;
        const char* vcLockPathName;
        const char* chars;
        LONG length;

        if (0 < (length = m_entryPath.Assign(entryPathName)))
        if ((chars = m_vcDirectory.Chars(length)))
        if (0 < (length = m_vcLockPath.AssignChars(chars)))
        if (0 < (length = m_vcLockFilePath.AssignChars(chars)))
        if ((chars = m_entryPath.GetFileDirectory
            (length)) && (0 < length))
        {
            if ((entryPathName = m_entryPath.GetFileName
                (length)) && (0 < length))
            if (0 < (length = m_vcLockPath.AppendDirectory(chars)))
            if (0 < (length = m_vcLockFilePath.AppendDirectory(chars)))
            if (0 < (length = m_vcLockPath.AppendDirectory(m_lockDirectoryChars)))
            if (0 < (length = m_vcLockFilePath.AppendDirectory(m_lockDirectoryChars)))
            if (0 < (length = m_vcLockFilePath.AppendFileName(entryPathName)))
            if (0 < (length = m_vcLockFilePath.AppendExtension(m_lockExtensionChars)))
            if ((vcLockPathName = m_vcLockFilePath.HasChars(length)))
                error = EV_ERROR_NONE;
        }
        else
        {
            if (0 < (length = m_vcLockPath.AppendDirectory(m_lockDirectoryChars)))
            if (0 < (length = m_vcLockFilePath.AppendDirectory(m_lockDirectoryChars)))
            if (0 < (length = m_vcLockFilePath.AppendFileName(entryPathName)))
            if (0 < (length = m_vcLockFilePath.AppendExtension(m_lockExtensionChars)))
            if ((vcLockPathName = m_vcLockFilePath.HasChars(length)))
                error = EV_ERROR_NONE;
        }

        return error;
    }
};
#endif // _CEVFSEVCSARCHIVE_HPP
