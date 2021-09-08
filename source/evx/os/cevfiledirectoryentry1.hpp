///////////////////////////////////////////////////////////////////////
//   File: cevfiledirectoryentry.hpp
//
// Author: $author$
//   Date: 5/3/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILEDIRECTORYENTRY_HPP
#define _CEVFILEDIRECTORYENTRY_HPP

#include "cevfilesystementrytimes.hpp"
#include "evfiledirectoryentry.hpp"
#include "cevattached.hpp"
#include "cevtstring.hpp"
#include "cevstring.hpp"
#include "evplatform_security.h"

///////////////////////////////////////////////////////////////////////
// Typedef: CEvDirectoryAttached
//
//  Author: $author$
//    Date: 5/4/2007
///////////////////////////////////////////////////////////////////////
typedef CEvAttached
<DIRECTORY, INVALID_DIRECTORY_T, INVALID_DIRECTORY, 
 EvDirectoryAttached, CEvBase> 
CEvDirectoryAttached;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvFileDirectoryExtends
//
//   Author: $author$
//     Date: 6/22/2007
///////////////////////////////////////////////////////////////////////
typedef CEvFileSystemEntryTimes
<CEvDirectoryAttached, EvFileDirectoryEntryImplements>
CEvFileDirectoryExtends;

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileDirectoryEntry
//
// Author: $author$
//   Date: 5/3/2007
///////////////////////////////////////////////////////////////////////
class CEvFileDirectoryEntry
: virtual public EvFileDirectoryEntry,
  public CEvDirectoryAttached
{
public:
    typedef EvFileDirectoryEntry CImplements;
    typedef CEvDirectoryAttached CExtends;
    typedef CEvFileDirectoryEntry CDerives;

    static const char m_separator;
    static const char* m_currentDirectoryName;
    static const char* m_parentDirectoryName;

#if defined(WIN32) 
// Windows
	WIN32_FIND_DATA m_ff;
	struct
	{
		SECURITY_DESCRIPTOR m_sd;
		BYTE m_data[DEFAULT_SECURITY_DESCRIPTOR_DATA_SIZE];
	} m_sd;
#else // defined(WIN32) 
// Unix
    struct dirent *m_dirent;
    struct stat m_stat;
    CEvString m_statDir;
    CEvString m_statPath;
#endif // defined(WIN32)

    EvType m_type;
    bool m_isCircular;
    bool m_isText;
    bool m_isArchive;
    bool m_isCompressed;
    bool m_isEncrypted;
    bool m_isHidden;
    bool m_isOffline;
    bool m_isReadOnly;
    bool m_isSystem;
    bool m_isTemporary;
    CEvString m_name;
    CEvTString m_namet;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileDirectoryEntry
    //
    //       Author: $author$
    //         Date: 5/3/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileDirectoryEntry
    (EvType type=EV_TYPE_NONE,
     bool isCircular=false,
     const char* name=0, LONG length=-1) 
    : m_type(type),
      m_isCircular(isCircular),
      m_isText(false),
      m_isArchive(false),
      m_isCompressed(false),
      m_isEncrypted(false),
      m_isHidden(false),
      m_isOffline(false),
      m_isReadOnly(false),
      m_isSystem(false),
      m_isTemporary(false)
    {
        EvError error;
        if (name)
        if (0 > (length = SetName(name, length)))
            throw(error = -length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileDirectoryEntry
    //
    //       Author: $author$
    //         Date: 5/3/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileDirectoryEntry
    (DIRECTORY attached,
     EvType type=EV_TYPE_NONE,
     bool isCircular=false) 
    : CExtends(attached),
      m_type(type),
      m_isCircular(isCircular)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvFileDirectoryEntry
    //
    //      Author: $author$
    //        Date: 5/3/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvFileDirectoryEntry()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetNextEntry
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetNextEntry() 
    {
        EvError error = EV_ERROR_FAILED;

        if (INVALID_DIRECTORY == m_attached)
            return EV_ERROR_NOT_ATTACHED;

        m_type = EV_TYPE_NONE;
        m_isCircular = false;

#if defined(WIN32) 
// Windows
        if (FindNextFile(m_attached, &m_ff))
            error = GetEntry(m_attached, m_ff);
#else // defined(WIN32) 
// Unix
        LONG length;
        const char* pathChars;
        if ((m_dirent = readdir(m_attached)))
        if ((pathChars = m_statDir.Chars(length))
            && (0 < length))
            error = GetEntry(m_attached, *m_dirent, pathChars);
#endif // defined(WIN32)

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetEntry
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError GetEntry
#if defined(WIN32) 
// Windows
    (DIRECTORY attached, WIN32_FIND_DATA& ff)
#else // defined(WIN32) 
// Unix
    (DIRECTORY attached, 
     struct dirent& dirent, 
     const char* pathChars)
#endif // defined(WIN32)
    {
        EvError error = EV_ERROR_FAILED;
        LONG length;
        int unequal;
        int type;
        int is;

        ClearAttributes();

#if defined(WIN32) 
// Windows
        if (0 < (length = SetNamet(ff.cFileName)))
        if (0 <= (type = SetType
            ((ff.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
             ?EV_TYPE_DIRECTORY:EV_TYPE_FILE)))
        if (0 <= (is = SetIsHidden
            (FILE_ATTRIBUTE_HIDDEN == 
             (ff.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN))))
            error = EV_ERROR_NONE;
#else // defined(WIN32) 
// Unix
        int err;

        //DBF("() dirent.d_name = \"%s\"\n", dirent.d_name);

        if (0 < (length = SetName(dirent.d_name)))
        if (0 < (length = m_statPath.Assign(pathChars)))
        if ((pathChars = m_statPath.Chars(length))
            && (0 < length))
        if (0 < (length = m_statDir.Assign(pathChars)))
        if (0 < (length = m_statPath.Append(&m_separator, 1)))
        if (0 < (length = m_statPath.Append(dirent.d_name)))
        {
            //DBF("() stat(\"%s\", ...)...\n", m_statPath.Chars(length));

            if ((err = stat(m_statPath.Chars(length), &m_stat)))
                DBE("() failed to stat \"%s\"\n", m_statPath.Chars(length));
            else if (0 <= (type = SetType
                    ((S_IFDIR == (m_stat.st_mode & S_IFDIR))
                     ?EV_TYPE_DIRECTORY:EV_TYPE_FILE)))
                    error = EV_ERROR_NONE;
        }
#endif // defined(WIN32)

        if (!error)
        if (!(unequal = m_name.Compare(m_currentDirectoryName))
            || !(unequal = m_name.Compare(m_parentDirectoryName)))
            SetIsCircular();

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ClearAttributes
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ClearAttributes() 
    {
        EvError error = EV_ERROR_NONE;
        SetType(EV_TYPE_NONE);
        SetIsCircular(false);
        SetIsText(false);
        SetIsArchive(false);
        SetIsCompressed(false);
        SetIsEncrypted(false);
        SetIsHidden(false);
        SetIsOffline(false);
        SetIsReadOnly(false);
        SetIsSystem(false);
        SetIsTemporary(false);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetNamet
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetNamet
    (const TCHAR* chars, LONG length=-1) 
    {
        m_name.Assignt(chars, length);
        m_namet.Assign(chars, length);
        length = m_namet.Length();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetNamet
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const TCHAR* GetNamet
    (LONG& length) const 
    {
        const TCHAR* chars = m_namet.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetName
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetName
    (const char* chars, LONG length=-1) 
    {
        m_namet.Assignc(chars, length);
        m_name.Assign(chars, length);
        length = m_name.Length();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetName
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetName
    (LONG& length) const 
    {
        const char* chars = m_name.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetType
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetType(EvType type) 
    {
        m_type = type;
        return m_type;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetType
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvType GetType() const 
    {
        return m_type;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsDirectory
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsDirectory(bool is=true) 
    {
        if (is)
            m_type |= EV_TYPE_DIRECTORY;
        else m_type &= ~((EvType)EV_TYPE_DIRECTORY);
        is = (EV_TYPE_DIRECTORY == (m_type & EV_TYPE_DIRECTORY));
        return is;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsDirectory
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsDirectory() const 
    {
        bool is = (EV_TYPE_DIRECTORY == (m_type & EV_TYPE_DIRECTORY));
        return is;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsCircular
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsCircular(bool is=true) 
    {
        m_isCircular = is;
        return m_isCircular;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsCircular
    //
    //   Author: $author$
    //     Date: 5/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsCircular() const 
    {
        return m_isCircular;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsText
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsText
    (bool is=true) 
    {
        m_isText = is;
        return m_isText;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsText
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsText() const 
    {
        return m_isText;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsArchive
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsArchive
    (bool is=true) 
    {
        m_isArchive = is;
        return m_isArchive;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsArchive
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsArchive() const 
    {
        return m_isArchive;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsCompressed
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsCompressed
    (bool is=true) 
    {
        m_isCompressed = is;
        return m_isCompressed;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsCompressed
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsCompressed() const 
    {
        return m_isCompressed;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsEncrypted
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsEncrypted
    (bool is=true) 
    {
        m_isEncrypted = is;
        return m_isEncrypted;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsEncrypted
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsEncrypted() const 
    {
        return m_isEncrypted;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsHidden
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsHidden
    (bool is=true) 
    {
        m_isHidden = is;
        return m_isHidden;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsHidden
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsHidden() const 
    {
        return m_isHidden;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsOffline
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsOffline
    (bool is=true) 
    {
        m_isOffline = is;
        return m_isOffline;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsOffline
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsOffline() const 
    {
        return m_isOffline;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsReadOnly
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsReadOnly
    (bool is=true) 
    {
        m_isReadOnly = is;
        return m_isReadOnly;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsReadOnly
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsReadOnly() const 
    {
        return m_isReadOnly;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsSystem
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsSystem
    (bool is=true) 
    {
        m_isSystem = is;
        return m_isSystem;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsSystem
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsSystem() const 
    {
        return m_isSystem;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsTemporary
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsTemporary
    (bool is=true) 
    {
        m_isTemporary = is;
        return m_isTemporary;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsTemporary
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsTemporary() const 
    {
        return m_isTemporary;
    }
};
#endif // _CEVFILEDIRECTORYENTRY_HPP
