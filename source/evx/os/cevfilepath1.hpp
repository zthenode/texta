///////////////////////////////////////////////////////////////////////
//   File: cevfilepath.hpp
//
// Author: $author$
//   Date: 5/6/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILEPATH_HPP
#define _CEVFILEPATH_HPP

#include <vector>
#include "evplatform_stat.h"
#include "evfiledirectoryentry.hpp"
#include "cevfilepathstring.hpp"
#include "cevfilepathwriter.hpp"
#include "evfilepathevents.hpp"
#include "evfilepath.hpp"
#include "cevstring.hpp"
#include "evinstance.hpp"
#include "evdebug.h"

///////////////////////////////////////////////////////////////////////
//  Class: EvFilePathDirectory
//
// Author: $author$
//   Date: 6/1/2007
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvFilePathDirectory
: virtual public EvInstance
{
public:
    typedef EvInstance CImplements;
    typedef EvFilePathDirectory CDerives;
    typedef int Type;

    ///////////////////////////////////////////////////////////////////////
    //   Enum:  
    //
    // Author: $author$
    //   Date: 5/31/2007
    ///////////////////////////////////////////////////////////////////////
    enum 
    {
        EV_FIRST_TYPE = 0,

        EV_TYPE_NONE = EV_FIRST_TYPE,
        EV_TYPE_CURRENT,
        EV_TYPE_PARENT,
        EV_TYPE_ROOT,

        EV_NEXT_TYPE,
        EV_LAST_TYPE = (EV_NEXT_TYPE-1)
    };
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvFilePathDirectory
//
// Author: $author$
//   Date: 5/31/2007
///////////////////////////////////////////////////////////////////////
class CEvFilePathDirectory
: virtual public EvFilePathDirectory,
  public CEvString
{
public:
    typedef EvFilePathDirectory CImplements;
    typedef CEvString CExtends;
    typedef CEvFilePathDirectory CDerives;

    Type m_type;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFilePathDirectory
    //
    //       Author: $author$
    //         Date: 5/31/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFilePathDirectory
    (Type type=EV_TYPE_NONE, 
     const char* chars=0, LONG length=-1) 
    : CExtends(chars, length),
      m_type(type)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteInstance
    //
    //   Author: $author$
    //     Date: 5/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteInstance() 
    {
        return DeleteThis();
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 5/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis() 
    {
        delete this;
        return EV_ERROR_NONE;
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvFilePathDirectories
//
//   Author: $author$
//     Date: 5/31/2007
///////////////////////////////////////////////////////////////////////
typedef ::std::vector<CEvFilePathDirectory*>
CEvFilePathDirectories;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvFilePathDirectoriesIterator
//
//   Author: $author$
//     Date: 5/31/2007
///////////////////////////////////////////////////////////////////////
typedef CEvFilePathDirectories::iterator
CEvFilePathDirectoriesIterator;

///////////////////////////////////////////////////////////////////////
//  Typedef: const_CEvFilePathDirectoriesIterator
//
//   Author: $author$
//     Date: 5/31/2007
///////////////////////////////////////////////////////////////////////
typedef CEvFilePathDirectories::const_iterator
const_CEvFilePathDirectoriesIterator;

///////////////////////////////////////////////////////////////////////
//  Class: CEvFilePath
//
// Author: $author$
//   Date: 5/6/2007
///////////////////////////////////////////////////////////////////////
class CEvFilePath
: virtual public EvFilePath,
  virtual public EvFilePathEvents,
  public CEvFilePathString
{
public:
    typedef EvFilePath CImplements;
    typedef CEvFilePathString CExtends;
    typedef CEvFilePath CDerives;

    static const char m_volumeSeparator;
    static const char m_extensionSeparator;
    static const char m_separator;

    CEvFilePathWriter m_writer;

    CEvString m_host;
    CEvString m_volume;
    CEvFilePathString m_directory;
    CEvFilePathString m_fileDirectory;
    CEvString m_makeDirectory;
    CEvString m_fileName;
    CEvString m_fileBase;
    CEvString m_fileExtension;

    bool m_isRootDirectory;
    bool m_isParentDirectory;
    bool m_isCurrentDirectory;

    bool m_isRoot;
    bool m_isParent;
    bool m_isCurrent;
    bool m_isCircular;

    CEvFilePathDirectories m_directories;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFilePath
    //
    //       Author: $author$
    //         Date: 5/6/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFilePath
    (const char* chars=0, LONG length=-1) 
    : m_writer(((EvFilePathEvents&)(*this))),
      m_isRootDirectory(false),
      m_isParentDirectory(false),
      m_isCurrentDirectory(false),
      m_isRoot(false),
      m_isParent(false),
      m_isCurrent(false),
      m_isCircular(false)
    {
        EvError error;
        if (chars)
        if (0 > (length = Assign(chars, length)))
            throw(error = -length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvFilePath
    //
    //      Author: $author$
    //        Date: 5/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvFilePath()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: MakeDirectory
    //
    //   Author: $author$
    //     Date: 6/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError MakeDirectory
    (bool doesNotExistOnly=false) 
    {
        DF(MakeDirectory)

        EvError error = EV_ERROR_FAILED;
        EvFileDirectoryEntry::EvType type;
        const_CEvFilePathDirectoriesIterator i;
        CEvFilePathDirectory* d;
        const char* chars;
        LONG length, count;
        bool doesNotExist;
        bool done;
        int err;

        m_makeDirectory.Clear();

        if ((chars = m_fileDirectory.Chars(length)) && (0 < length))
        if (EvFileDirectoryEntry::EV_TYPE_NONE 
            < (type = Exists(chars, length, true)))
        {
            if ((EvFileDirectoryEntry::EV_TYPE_DIRECTORY == type)
                 && !doesNotExistOnly)
                 error = EV_ERROR_NONE;
        }
        else
        {
            if ((chars = m_volume.Chars(length)) && (0 < length))
            if (0 >= (length = m_makeDirectory.Append(chars, length)))
                return error;
            else if (0 >= (length = m_makeDirectory.Append(&m_volumeSeparator, 1)))
                    return error;

            doesNotExist = false;

            for (i = m_directories.begin(); 
                 !(done = (i == m_directories.end())); i++)
            {
                if (d = *i)
                if ((chars = d->Chars(length)) && (0 < length))
                if (0 < (count = AppendMakeDirectory(chars, length)))
                if ((chars = m_makeDirectory.Chars(length)) && (0 < length))
                {
                    if (!doesNotExist)
                    if (EvFileDirectoryEntry::EV_TYPE_NONE
                        >= (type = Exists(chars, length, true)))
                        doesNotExist = true;

                    if (doesNotExist)
                    if ((err = mkdir(chars, S_IRWX)))
                    {
                        DBE("() failed to mkdir \"%s\"\n", chars);
                        break;
                    }
                    continue;
                }
                break;
            }

            if (done)
                error = EV_ERROR_NONE;
        }

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Exists
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int Exists
    (const char* chars=0, LONG length=-1, 
     bool dontAssign=false) 
    {
        int type = EvFileDirectoryEntry::EV_TYPE_NONE;
        int err;
        struct stat st;

        if (chars && !dontAssign)
        if (0 > (length = Assign(chars, length)))
            return length;
        else chars = Chars(length);

        if ((chars) && (0 != length))
        if (!(err = stat(chars, &st)))
        if (S_IFDIR == (S_IFDIR & st.st_mode))
            type = EvFileDirectoryEntry::EV_TYPE_DIRECTORY;
        else type = EvFileDirectoryEntry::EV_TYPE_FILE;
        return type;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AppendDirectory
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG AppendDirectory
    (const char* chars, LONG length=-1,
     bool isRoot=false) 
    {
        length = AppendName(chars, length, isRoot);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AppendFileName
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG AppendFileName
    (const char* chars, LONG length=-1,
     bool isRoot=false) 
    {
        length = AppendName(chars, length, isRoot);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AppendName
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG AppendName
    (const char* chars, LONG length=-1,
     bool isRoot=false) 
    {
        bool beginsWithSeparator = false;
        bool endsWithSeparator = false;
        bool isSeparator = false;
        const char* pChars;
        LONG pLength;

        if (!chars || !length)
            return -EV_ERROR_INVALID_PARAMETER;

        beginsWithSeparator
        = ((m_nativeSeparator == *chars)
           || (m_foriegnSeparator == *chars));

        if ((pChars = Chars(pLength)) && (0 < pLength))
            endsWithSeparator 
            = ((m_nativeSeparator == pChars[pLength-1])
               || (m_foriegnSeparator == pChars[pLength-1]));

        isSeparator 
        = (beginsWithSeparator 
           && endsWithSeparator
           && (1 == pLength));

        if (!endsWithSeparator && (isRoot || (0 < pLength)))
        if (0 > (pLength = AppendChars(&m_separator, 1)))
            return pLength;

        if (0 < (length = Append(chars, length)))
            length += pLength;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AppendExtension
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG AppendExtension
    (const char* chars, LONG length=-1) 
    {
        bool endsWithExtensionSeparator = false;
        const char* p;
        LONG pLength;

        if ((p = Chars(pLength)) && (0 < pLength))
            endsWithExtensionSeparator = (m_extensionSeparator == p[pLength-1]);

        if (!endsWithExtensionSeparator)
        if (0 > (pLength = AppendChars(&m_extensionSeparator, 1)))
            return pLength;

        if (0 < (length = Append(chars, length)))
            length += pLength;
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Clear
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Clear() 
    {
        LONG length;
        EvError error;

        if ((error = ClearParts()))
            length = -error;
        else length = ClearChars();
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Assign
    //
    //   Author: $author$
    //     Date: 5/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Assign
    (const char* chars, LONG length=-1) 
    {
        EvError error;
        LONG count;

        if (0 > (count = Clear()))
            return count;

        if (0 <= (length = AssignChars(chars, length)))
        if ((error = Parse()))
            length = -error;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Append
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Append
    (const char* chars, LONG length=-1) 
    {
        EvError error;

        if ((error = ClearParts()))
            return length = -error;

        if (0 <= (length = AppendChars(chars, length)))
        if ((error = Parse()))
            length = -error;
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Parse
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Parse() 
    {
        EvError error = EV_ERROR_NONE;
        const char* chars;
        LONG length;
        LONG written;

        if ((chars = Chars(length)) && (0 < length))
        if (!(error = ClearParts()))
        if (!(error = m_writer.Initialize()))
        if (0 <= (written = m_writer.Write(chars, length)))
            error = m_writer.Finalize();
        else if (0 > written)
                error = -written;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ClearParts
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ClearParts() 
    {
        EvError error = ClearDirectories();

        m_isRootDirectory = false;
        m_isParentDirectory = false;
        m_isCurrentDirectory = false;

        m_isRoot = false;
        m_isParent = false;
        m_isCurrent = false;
        m_isCircular = false;

        m_host.Clear();
        m_volume.Clear();
        m_directory.Clear();
        m_fileDirectory.Clear();
        m_makeDirectory.Clear();
        m_fileName.Clear();
        m_fileBase.Clear();
        m_fileExtension.Clear();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AddParentDirectory
    //
    //   Author: $author$
    //     Date: 5/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AddParentDirectory
    (const char* chars,
     LONG length=-1) 
    {
        EvError error = AddDirectory
        (CEvFilePathDirectory::EV_TYPE_PARENT,
         chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AddCurrentDirectory
    //
    //   Author: $author$
    //     Date: 5/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AddCurrentDirectory
    (const char* chars,
     LONG length=-1) 
    {
        EvError error = AddDirectory
        (CEvFilePathDirectory::EV_TYPE_CURRENT,
         chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AddRootDirectory
    //
    //   Author: $author$
    //     Date: 5/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AddRootDirectory
    (const char* chars,
     LONG length=-1) 
    {
        EvError error = AddDirectory
        (CEvFilePathDirectory::EV_TYPE_ROOT,
         chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AddDirectory
    //
    //   Author: $author$
    //     Date: 5/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AddDirectory
    (const char* chars,
     LONG length=-1) 
    {
        EvError error = AddDirectory
        (CEvFilePathDirectory::EV_TYPE_NONE,
         chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AddDirectory
    //
    //   Author: $author$
    //     Date: 5/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError AddDirectory
    (CEvFilePathDirectory::Type type, 
     const char* chars,
     LONG length=-1) 
    {
        EvError error = EV_ERROR_FAILED;
        CEvFilePathDirectory* d;

        if ((d = new CEvFilePathDirectory
            (type, chars, length)))
            m_directories.push_back(d);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ClearDirectories
    //
    //   Author: $author$
    //     Date: 5/31/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError ClearDirectories() 
    {
        EvError error = EV_ERROR_NONE;
        EvError error2;
        CEvFilePathDirectory* d;
        CEvFilePathDirectoriesIterator i;

        for (i = m_directories.end(); i != m_directories.begin();)
        {
            if (d = *(--i))
            if ((error2 = d->DeleteInstance()) && !error)
                error = error2;
        }
        m_directories.clear();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ClearChars
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ClearChars() 
    {
        LONG length = CExtends::Clear();
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AssignChars
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG AssignChars
    (const char* chars, LONG length=-1) 
    {
        length = NormalAssign(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AppendChars
    //
    //   Author: $author$
    //     Date: 5/22/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG AppendChars
    (const char* chars, LONG length=-1) 
    {
        length = NormalAppend(chars, length);
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AppendFileDirectoryVolumeChars
    //
    //   Author: $author$
    //     Date: 7/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG AppendFileDirectoryVolumeChars
    (const char* chars, LONG length=-1, 
     bool omitSeparator=false) 
    {
        LONG count = 0;
        if (length && chars && chars[0])
        {
            if (0 >= (count = m_fileDirectory.Append(chars, length)))
                return count;

            if (!omitSeparator && (0 < m_fileDirectory.Length()))
            if (0 >= (length = m_fileDirectory.Append(&m_volumeSeparator, 1)))
                return length;
            else count += length;
       }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AppendDirectoryChars
    //
    //   Author: $author$
    //     Date: 6/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG AppendDirectoryChars
    (const char* chars, LONG length=-1, 
     bool omitSeparator=false) 
    {
        LONG count = 0;
        if (length && chars && chars[0])
        {
            if (0 >= (count = AppendFileDirectoryChars
                (chars, length, omitSeparator)))
                return count;

            if (!omitSeparator && (0 < m_fileDirectory.Length()))
            if (0 >= (count = m_directory.Append(&m_separator, 1)))
                return count;

            if (0 >= (length = m_directory.Append(chars, length)))
                return length;
            else count += length;
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: AppendFileDirectoryChars
    //
    //   Author: $author$
    //     Date: 6/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG AppendFileDirectoryChars
    (const char* chars, LONG length=-1, 
     bool omitSeparator=false) 
    {
        LONG count = 0;
        if (length && chars && chars[0])
        {
            if (!omitSeparator && (0 < m_fileDirectory.Length()))
            if (0 >= (count = m_fileDirectory.Append(&m_separator, 1)))
                return count;

            if (0 >= (length = m_fileDirectory.Append(chars, length)))
                return length;
            else count += length;
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetFirstDirectory
    //
    //   Author: $author$
    //     Date: 7/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual CEvFilePathDirectory* GetFirstDirectory
    (const_CEvFilePathDirectoriesIterator& i) 
    {
        CEvFilePathDirectory* d = 0;

        if ((i = m_directories.begin()) != m_directories.end())
            d = *i;
        return d;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetNextDirectory
    //
    //   Author: $author$
    //     Date: 7/5/2007
    ///////////////////////////////////////////////////////////////////////
    virtual CEvFilePathDirectory* GetNextDirectory
    (const_CEvFilePathDirectoriesIterator& i) 
    {
        CEvFilePathDirectory* d = 0;

        if (i != m_directories.end())
        if ((++i) != m_directories.end())
            d = *i;
        return d;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetHost
    //
    //   Author: $author$
    //     Date: 5/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetHost
    (const char* chars,
     LONG length=-1) 
    {
        length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetHost
    //
    //   Author: $author$
    //     Date: 5/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetHost
    (LONG& length) const 
    {
        const char* chars = 0;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetVolume
    //
    //   Author: $author$
    //     Date: 5/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetVolume
    (const char* chars,
     LONG length=-1) 
    {
        length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetVolume
    //
    //   Author: $author$
    //     Date: 5/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetVolume
    (LONG& length) const 
    {
        const char* chars = 0;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetDirectory
    //
    //   Author: $author$
    //     Date: 5/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetDirectory
    (const char* chars,
     LONG length=-1) 
    {
        length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetDirectory
    //
    //   Author: $author$
    //     Date: 5/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetDirectory
    (LONG& length) const 
    {
        const char* chars = 0;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFileDirectory
    //
    //   Author: $author$
    //     Date: 6/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetFileDirectory
    (const char* chars,
     LONG length=-1) 
    {
        length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFileDirectory
    //
    //   Author: $author$
    //     Date: 6/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetFileDirectory
    (LONG& length) const 
    {
        const char* chars = m_fileDirectory.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: AppendMakeDirectory
    //
    //   Author: $author$
    //     Date: 6/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG AppendMakeDirectory
    (const char* chars, LONG length=-1) 
    {
        LONG count;

        if (0 < (count = m_makeDirectory.Length()))
        if (0 >= (count = m_makeDirectory.Append(&m_separator, 1)))
            return count;

        length = m_makeDirectory.Append(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetMakeDirectory
    //
    //   Author: $author$
    //     Date: 6/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetMakeDirectory
    (const char* chars,
     LONG length=-1) 
    {
        length = m_makeDirectory.Assign(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMakeDirectory
    //
    //   Author: $author$
    //     Date: 6/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetMakeDirectory
    (LONG& length) const 
    {
        const char* chars = m_makeDirectory.Chars(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetFileName
    //
    //   Author: $author$
    //     Date: 5/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetFileName
    (const char* chars,
     LONG length=-1) 
    {
        length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFileName
    //
    //   Author: $author$
    //     Date: 5/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetFileName
    (LONG& length) const 
    {
        const char* chars = m_fileName.Chars(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetFileBase
    //
    //   Author: $author$
    //     Date: 5/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetFileBase
    (const char* chars,
     LONG length=-1) 
    {
        length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFileBase
    //
    //   Author: $author$
    //     Date: 5/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetFileBase
    (LONG& length) const 
    {
        const char* chars = 0;
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetFileExtension
    //
    //   Author: $author$
    //     Date: 5/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetFileExtension
    (const char* chars,
     LONG length=-1) 
    {
        length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFileExtension
    //
    //   Author: $author$
    //     Date: 5/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetFileExtension
    (LONG& length) const 
    {
        const char* chars = m_fileExtension.Chars(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetFileVersionExtension
    //
    //   Author: $author$
    //     Date: 5/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetFileVersionExtension
    (const char* chars,
     LONG length=-1) 
    {
        length = -EV_ERROR_FAILED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFileVersionExtension
    //
    //   Author: $author$
    //     Date: 5/6/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetFileVersionExtension
    (LONG& length) const 
    {
        const char* chars = 0;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsRootDirectory
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsRootDirectory
    (bool is=true) 
    {
        m_isRootDirectory = is;
        return m_isRootDirectory;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsRootDirectory
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsRootDirectory() const 
    {
        return m_isRootDirectory;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsParentDirectory
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsParentDirectory
    (bool is=true) 
    {
        m_isParentDirectory = is;
        return m_isParentDirectory;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsParentDirectory
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsParentDirectory() const 
    {
        return m_isParentDirectory;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsCurrentDirectory
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsCurrentDirectory
    (bool is=true) 
    {
        m_isCurrentDirectory = is;
        return m_isCurrentDirectory;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsCurrentDirectory
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsCurrentDirectory() const 
    {
        return m_isCurrentDirectory;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsRoot
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsRoot
    (bool is=true) 
    {
        m_isRoot = is;
        return m_isRoot;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsRoot
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsRoot() const 
    {
        return m_isRoot;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsParent
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsParent
    (bool is=true) 
    {
        m_isParent = is;
        return m_isParent;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsParent
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsParent() const 
    {
        return m_isParent;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsCurrent
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsCurrent
    (bool is=true) 
    {
        m_isCurrent = is;
        return m_isCurrent;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsCurrent
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsCurrent() const 
    {
        return m_isCurrent;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsCircular
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsCircular
    (bool is=true) 
    {
        m_isCircular = is;
        return m_isCircular;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsCircular
    //
    //   Author: $author$
    //     Date: 5/9/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsCircular() const 
    {
        return m_isCircular;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnHost
    //
    //   Author: $author$
    //     Date: 5/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG OnHost
    (const char* chars,
     LONG length=-1) 
    {
        DF(OnHost)
        DBF("(\"%s\")...\n", chars);
        length = m_host.Assign(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnVolume
    //
    //   Author: $author$
    //     Date: 5/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG OnVolume
    (const char* chars,
     LONG length=-1) 
    {
        DF(OnVolume)
        DBF("(\"%s\")...\n", chars);
        length = m_volume.Assign(chars, length);
        AppendFileDirectoryVolumeChars(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnDirectory
    //
    //   Author: $author$
    //     Date: 5/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG OnDirectory
    (const char* chars,
     LONG length=-1) 
    {
        DF(OnDirectory)
        DBF("(\"%s\")...\n", chars);
        if (length && chars[0])
        {
            AppendDirectoryChars(chars, length);
            AddDirectory(chars, length);
        }
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnParentDirectory
    //
    //   Author: $author$
    //     Date: 5/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG OnParentDirectory
    (const char* chars,
     LONG length=-1) 
    {
        DF(On)
        DBF("(\"%s\")...\n", chars);
        if (length && chars[0])
        {
            AppendDirectoryChars(chars, length);
            AddParentDirectory(chars, length);
        }
        SetIsCircular();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnCurrentDirectory
    //
    //   Author: $author$
    //     Date: 5/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG OnCurrentDirectory
    (const char* chars,
     LONG length=-1) 
    {
        DF(On)
        DBF("(\"%s\")...\n", chars);
        if (length && chars[0])
        {
            AppendDirectoryChars(chars, length);
            AddCurrentDirectory(chars, length);
        }
        SetIsCircular();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnRootDirectory
    //
    //   Author: $author$
    //     Date: 5/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG OnRootDirectory
    (const char* chars,
     LONG length=-1) 
    {
        DF(On)
        DBF("(\"%s\")...\n", chars);
        AppendDirectoryChars(&m_separator, 1, true);
        if (length && chars[0])
        {
            AppendDirectoryChars(chars, length, true);
            AddRootDirectory(chars, length);
        }
        else 
        {
            SetIsRootDirectory();
            AddRootDirectory(&m_separator, 1);
        }
        SetIsRoot();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnRootParentDirectory
    //
    //   Author: $author$
    //     Date: 5/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG OnRootParentDirectory
    (const char* chars,
     LONG length=-1) 
    {
        DF(On)
        DBF("(\"%s\")...\n", chars);
        AppendDirectoryChars(&m_separator, 1, true);
        if (length && chars[0])
        {
            AppendDirectoryChars(chars, length, true);
            AddRootDirectory(chars, length);
        }
        SetIsRoot();
        SetIsParent();
        SetIsCircular();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnRootCurrentDirectory
    //
    //   Author: $author$
    //     Date: 5/8/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG OnRootCurrentDirectory
    (const char* chars,
     LONG length=-1) 
    {
        DF(On)
        DBF("(\"%s\")...\n", chars);
        AppendDirectoryChars(&m_separator, 1, true);
        if (length && chars[0])
        {
            AppendDirectoryChars(chars, length, true);
            AddCurrentDirectory(chars, length);
        }
        SetIsRoot();
        SetIsCurrent();
        SetIsCircular();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnRootFileName
    //
    //   Author: $author$
    //     Date: 5/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG OnRootFileName
    (const char* chars,
     LONG length=-1) 
    {
        DF(On)
        DBF("(\"%s\")...\n", chars);
        if (length && chars[0])
        {
            m_fileName.Assign(chars, length);
            m_fileBase.Assign(chars, length);
        }
        else 
        {
            m_directory.Append(&m_separator, 1);
            m_fileDirectory.Append(&m_separator, 1);
            AddRootDirectory(&m_separator, 1);
        }
        SetIsRoot();
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileName
    //
    //   Author: $author$
    //     Date: 5/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG OnFileName
    (const char* chars,
     LONG length=-1) 
    {
        DF(On)
        DBF("(\"%s\")...\n", chars);
        m_fileName.Assign(chars, length);
        m_fileBase.Assign(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileExtension
    //
    //   Author: $author$
    //     Date: 5/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG OnFileExtension
    (const char* chars,
     LONG length=-1) 
    {
        DF(On)
        DBF("(\"%s\")...\n", chars);
        m_fileExtension.Assign(chars, length);
        m_fileName.Append(&m_extensionSeparator, 1);
        m_fileName.Append(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileVersionExtension
    //
    //   Author: $author$
    //     Date: 5/7/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG OnFileVersionExtension
    (const char* chars,
     LONG length=-1) 
    {
        DF(On)
        DBF("(\"%s\")...\n", chars);
        return length;
    }
};
#endif // _CEVFILEPATH_HPP
