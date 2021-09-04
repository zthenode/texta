/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cfilepath.hxx
 *
 * Author: $author$
 *   Date: 9/7/2008
 **********************************************************************
 */
#ifndef _CFILEPATH_HXX
#define _CFILEPATH_HXX

#include "cplatform_path.h"
#include "cfilepathinterface.hxx"
#include "cfilepatheventinterface.hxx"
#include "ctofilepathwriter.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cFilePathT"
/**
 **********************************************************************
 *  Class: cFilePathT
 *
 * Author: $author$
 *   Date: 9/7/2008
 **********************************************************************
 */
template
<class TChar=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 TChar VNullChar=NULL_CHAR,
 class TString=cString,
 class TStringInterface=cStringInterface,
 class TToFilePathWriter=cToFilePathWriter,
 class TFilePathEventImplement=cFilePathEventImplement,
 class TImplements=cFilePathImplement,
 class TExtends=cString>
 
class cFilePathT
: virtual public TFilePathEventImplement,
  virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cFilePathT cDerives;

    TChar m_volumeSeparatorChar;
    TChar m_directorySeparatorChar;
    TChar m_extensionSeparatorChar;
    TToFilePathWriter m_writer;

    bool m_isRootDirectory;
    bool m_isRelativeDirectory;
    TString m_fileHost;
    TString m_fileVolume;
    TString m_fileDirectory;
    TString m_fileBase;
    TString m_fileExtension;
    TString m_fileName;
    TString m_filePath;

    /**
     **********************************************************************
     * Constructor: cFilePathT
     *
     *      Author: $author$
     *        Date: 9/7/2008
     **********************************************************************
     */
    cFilePathT
    (const TChar* chars=0,
     TLength length=VUndefinedLength) 
    : m_volumeSeparatorChar(PLATFORM_VOLUME_SEPARATOR_CHAR),
      m_directorySeparatorChar(PLATFORM_DIRECTORY_SEPARATOR_CHAR),
      m_extensionSeparatorChar(PLATFORM_EXTENSION_SEPARATOR_CHAR),
      m_writer((TFilePathEventImplement&)(*this)),
      m_isRootDirectory(false),
      m_isRelativeDirectory(false)
    {
        eError error;
        if (chars)
        if (0 > (length = Assign(chars, length)))
            throw(error = -length);
    }

    /**
     **********************************************************************
     * Function: MakeFileName
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual TLength MakeFileName
    (TStringInterface& path, const TChar* fileNameChars,
     TLength fileNameLength=VUndefinedLength) 
    {
        TLength count = 0;
        TLength length;
        const TChar* chars;
        if (0 > (length = path.Clear()))
            return length;
        if ((chars = m_filePath.HasChars(length)))
        {
            if (0 > (length = path.Append(chars, length)))
                return length;
            count += length;
            if (0 > (length = path.Append(&m_directorySeparatorChar, 1)))
                return length;
            count += length;
        }
        if (0 > (length = path.Append(fileNameChars, fileNameLength)))
            return length;
        count += length;
        return count;
    }
    /**
     **********************************************************************
     * Function: MakeFileExtension
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual TLength MakeFileExtension
    (TStringInterface& path, const TChar* fileExtensionChars,
     TLength fileExtensionLength=VUndefinedLength) 
    {
        TLength count = 0;
        TLength length;
        const TChar* chars;
        if (0 > (length = path.Clear()))
            return length;
        if ((chars = m_filePath.HasChars(length)))
        {
            if (0 > (length = path.Append(chars, length)))
                return length;
            count += length;
            if (0 > (length = path.Append(&m_directorySeparatorChar, 1)))
                return length;
            count += length;
        }
        if ((chars = m_fileBase.HasChars(length)))
        {
            if (0 > (length = path.Append(chars, length)))
                return length;
            count += length;
            if (0 > (length = path.Append(&m_extensionSeparatorChar, 1)))
                return length;
            count += length;
        }
        if (0 > (length = path.Append(fileExtensionChars, fileExtensionLength)))
            return length;
        count += length;
        return count;
    }

    /**
     **********************************************************************
     * Function: AppendFileName
     *
     *   Author: $author$
     *     Date: 9/9/2008
     **********************************************************************
     */
    virtual TLength AppendFileName
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = 0;
        TLength hasLength;
        const TChar* hasChars;
        eError error;

        if ((hasChars = this->HasChars(hasLength)))
        if (m_volumeSeparatorChar != hasChars[hasLength-1])
        if (m_directorySeparatorChar != hasChars[hasLength-1])
        if (0 > (count = this->AppendChars(&m_directorySeparatorChar, 1)))
            return count;

        if (0 < (length = this->AppendChars(chars, length)))
        if ((error = SeparateParts()))
            count = -error;
        else count += length;
        return count;
    }

    /**
     **********************************************************************
     * Function: Assign
     *
     *   Author: $author$
     *     Date: 9/7/2008
     **********************************************************************
     */
    virtual TLength Assign
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count;
        eError error;
        if (0 < (count = this->AssignChars(chars, length)))
        if ((error = SeparateParts()))
            return length = -error;
        return count;
    }
    /**
     **********************************************************************
     * Function: Append
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual TLength Append
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count;
        eError error;
        if (0 < (count = this->AppendChars(chars, length)))
        if ((error = SeparateParts()))
            return length = -error;
        return count;
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual TLength Clear() 
    {
        TLength count;
        TLength length;
        if (0 <= (count = CTHIS ClearChars()))
        if (0 > (length = CTHIS ClearParts()))
            return length;
        return count;
    }

    /**
     **********************************************************************
     * Function: SeparateParts
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual eError SeparateParts() 
    {
        eError error = e_ERROR_NONE;
        TLength length;
        const TChar* chars;

        if (0 > (length = ClearParts()))
            return error = -length;

        if ((chars = this->HasChars(length)))
        if (!(error = m_writer.Initialize()))
        {
            for (; 0<length; --length, chars++)
                m_writer.Put(*chars);

            if (!(error = m_writer.Finalize()))
            if (0 > (length = CombinePathParts()))
                error = -length;
            else
            if (0 > (length = CombineNameParts()))
                error = -length;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: CombinePathParts
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual TLength CombinePathParts() 
    {
        TLength count = 0;
        TLength length;
        const TChar* chars;
        bool hasHost;
        bool hasVolume;
        bool hasDirectory;

        if (0 > (length = m_filePath.ClearChars()))
            return length;

        if ((hasHost = (0 != (chars = m_fileHost.HasChars(length)))))
        {
            if (0 > (count = m_filePath.AppendChars(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = m_filePath.AppendChars(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = m_filePath.AppendChars(chars, length)))
                return count;
        }

        if ((hasVolume = (0 != (chars = m_fileVolume.HasChars(length)))))
        {
            if (hasHost)
            if (0 > (count = m_filePath.AppendChars(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = m_filePath.AppendChars(chars, length)))
                return count;
            if (0 > (count = m_filePath.AppendChars(&m_volumeSeparatorChar, 1)))
                return count;
        }

        if ((hasDirectory = (0 != (chars = m_fileDirectory.HasChars(length)))))
        {
            if ((hasHost && !hasVolume) || m_isRootDirectory)
            if (0 > (count = m_filePath.AppendChars(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = m_filePath.AppendChars(chars, length)))
                return count;
        }
        else if (m_isRootDirectory)
        {
            if (0 > (count = m_filePath.AppendChars(&m_directorySeparatorChar, 1)))
                return count;
        }
        count = m_filePath.Length();
        return count;
    }
    /**
     **********************************************************************
     * Function: CombineNameParts
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual TLength CombineNameParts() 
    {
        TLength count = 0;
        TLength length;
        const TChar* chars;
        bool hasFileBase;
        bool hasFileExtension;

        if (0 > (length = m_fileName.ClearChars()))
            return length;

        if ((hasFileBase = (0 != (chars = m_fileBase.HasChars(length)))))
        {
            if (0 > (count = m_fileName.AppendChars(chars, length)))
                return count;

            if ((hasFileExtension = (0 != (chars = m_fileExtension.HasChars(length)))))
            {
                if (0 > (count = m_fileName.AppendChars(&m_extensionSeparatorChar, 1)))
                    return count;
                if (0 > (count = m_fileName.AppendChars(chars, length)))
                    return count;
            }
        }
        count = m_fileName.Length();
        return count;
    }
    /**
     **********************************************************************
     * Function: CombineParts
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual TLength CombineParts() 
    {
        TLength count = 0;
        TLength length;
        const TChar* chars;
        bool hasHost;
        bool hasVolume;
        bool hasDirectory;
        bool hasFileBase;
        bool hasFileExtension;

        if (0 > (length = CTHIS ClearChars()))
            return length;

        if ((hasHost = (0 != (chars = m_fileHost.HasChars(length)))))
        {
            if (0 > (count = this->AppendChars(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = this->AppendChars(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = this->AppendChars(chars, length)))
                return count;
        }

        if ((hasVolume = (0 != (chars = m_fileVolume.HasChars(length)))))
        {
            if (hasHost)
            if (0 > (count = this->AppendChars(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = this->AppendChars(chars, length)))
                return count;
            if (0 > (count = this->AppendChars(&m_volumeSeparatorChar, 1)))
                return count;
        }

        if ((hasDirectory = (0 != (chars = m_fileDirectory.HasChars(length)))))
        {
            if ((hasHost && !hasVolume) || m_isRootDirectory)
            if (0 > (count = this->AppendChars(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = this->AppendChars(chars, length)))
                return count;
        }

        if ((hasFileBase = (0 != (chars = m_fileBase.HasChars(length)))))
        {
            if (hasDirectory || m_isRootDirectory || (hasHost && !hasVolume))
            if (0 > (count = this->AppendChars(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = this->AppendChars(chars, length)))
                return count;

            if ((hasFileExtension = (0 != (chars = m_fileExtension.HasChars(length)))))
            {
                if (0 > (count = this->AppendChars(&m_extensionSeparatorChar, 1)))
                    return count;
                if (0 > (count = this->AppendChars(chars, length)))
                    return count;
            }
        }
        else if (m_isRootDirectory)
        {
            if (0 > (count = this->AppendChars(&m_directorySeparatorChar, 1)))
                return count;
        }
        count = CTHIS Length();
        return count;
    }
    /**
     **********************************************************************
     * Function: ClearParts
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual TLength ClearParts() 
    {
        TLength count = 0;
        m_isRootDirectory = false;
        m_isRelativeDirectory = false;
        if (0 <= (count = m_fileHost.Clear()))
        if (0 <= (count = m_fileVolume.Clear()))
        if (0 <= (count = m_fileDirectory.Clear()))
        if (0 <= (count = m_fileBase.Clear()))
        if (0 <= (count = m_fileExtension.Clear()))
        if (0 <= (count = m_fileName.Clear()))
            count = m_filePath.Clear();
        return count;
    }

    /**
     **********************************************************************
     * Function: OnPathHost
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathHost
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = SetFileHost(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathVolume
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathVolume
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = SetFileVolume(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathDirectory
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = AppendFileDirectory(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathRootDirectory
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathRootDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count;
        m_isRootDirectory = true;
        count = AppendFileDirectory(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathCurrentDirectory
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathCurrentDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count;

        if (!m_isRootDirectory)
        if (1 > (count = m_fileHost.Length()))
        if (1 > (count = m_fileVolume.Length()))
        if (1 > (count = m_fileDirectory.Length()))
            m_isRelativeDirectory = true;

        count = AppendFileDirectory(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathRootCurrentDirectory
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathRootCurrentDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count;
        m_isRootDirectory = true;
        count = AppendFileDirectory(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathParentDirectory
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathParentDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count;

        if (!m_isRootDirectory)
        if (1 > (count = m_fileHost.Length()))
        if (1 > (count = m_fileVolume.Length()))
        if (1 > (count = m_fileDirectory.Length()))
            m_isRelativeDirectory = true;

        count = AppendFileDirectory(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathRootParentDirectory
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathRootParentDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count;
        m_isRootDirectory = true;
        count = AppendFileDirectory(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathFileBase
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathFileBase
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = SetFileBase(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathRootFileBase
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathRootFileBase
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count;
        m_isRootDirectory = true;
        count = SetFileBase(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathFileExtension
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength OnPathFileExtension
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = SetFileExtension(chars,length);
        return count;
    }
    /*
     * Set
     */
    /**
     **********************************************************************
     * Function: SetFileHost
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual TLength SetFileHost
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = m_fileHost.Assign(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: SetFileVolume
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual TLength SetFileVolume
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = m_fileVolume.Assign(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: AppendFileDirectory
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual TLength AppendFileDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength,
     bool isRoot=false) 
    {
        TLength count;
        if ((0 < (count = m_fileDirectory.Length())) || isRoot)
        if (0 > (count = m_fileDirectory.Append(&m_directorySeparatorChar, 1)))
            return count;
        if (0 > (length = m_fileDirectory.Append(chars,length)))
            return length;
        count += length;
        return count;
    }
    /**
     **********************************************************************
     * Function: SetFileDirectory
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual TLength SetFileDirectory
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = m_fileDirectory.Assign(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: SetFileBase
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual TLength SetFileBase
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = m_fileBase.Assign(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: SetFileExtension
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual TLength SetFileExtension
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = m_fileExtension.Assign(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: SetFileName
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual TLength SetFileName
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = m_fileName.Assign(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: SetFilePath
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual TLength SetFilePath
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count = m_filePath.Assign(chars,length);
        return count;
    }
    /*
     * Get
     */
    /**
     **********************************************************************
     * Function: GetFileHost
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual const TChar* GetFileHost
    (TLength& length) const 
    {
        const TChar* chars = m_fileHost.HasChars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetFileVolume
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual const TChar* GetFileVolume
    (TLength& length) const 
    {
        const TChar* chars = m_fileVolume.HasChars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetFileDirectory
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual const TChar* GetFileDirectory
    (TLength& length) const 
    {
        const TChar* chars = m_fileDirectory.HasChars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetFileBase
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual const TChar* GetFileBase
    (TLength& length) const 
    {
        const TChar* chars = m_fileBase.HasChars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetFileExtension
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual const TChar* GetFileExtension
    (TLength& length) const 
    {
        const TChar* chars = m_fileExtension.HasChars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetFileName
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual const TChar* GetFileName
    (TLength& length) const 
    {
        const TChar* chars = m_fileName.HasChars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetFilePath
     *
     *   Author: $author$
     *     Date: 9/8/2008
     **********************************************************************
     */
    virtual const TChar* GetFilePath
    (TLength& length) const 
    {
        const TChar* chars = m_filePath.HasChars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetIsRelativeDirectory
     *
     *   Author: $author$
     *     Date: 9/15/2008
     **********************************************************************
     */
    virtual int SetIsRelativeDirectory
    (bool is=true) 
    {
        m_isRelativeDirectory = is;
        return is;
    }
    /**
     **********************************************************************
     * Function: GetIsRelativeDirectory
     *
     *   Author: $author$
     *     Date: 9/15/2008
     **********************************************************************
     */
    virtual bool GetIsRelativeDirectory() const 
    {
        bool is = m_isRelativeDirectory;
        return is;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFilePath
 *
 *  Author: $author$
 *    Date: 9/7/2008
 **********************************************************************
 */
typedef cFilePathT<>
cFilePath;

#endif /* _CFILEPATH_HXX */
