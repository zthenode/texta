///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2011 $organization$
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
//   File: cFilePath.hpp
//
// Author: $author$
//   Date: 8/4/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CFILEPATH_HPP) || defined(CFILEPATHT_MEMBERS_ONLY)
#if !defined(_CFILEPATH_HPP) && !defined(CFILEPATHT_MEMBERS_ONLY)
#define _CFILEPATH_HPP
#endif // !defined(_CFILEPATH_HPP) && !defined(CFILEPATHT_MEMBERS_ONLY) 

#if !defined(CFILEPATHT_MEMBERS_ONLY)
#include "cFilePathInterface.hpp"
#include "cFilePathParser.hpp"
#include "cString.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

class c_INSTANCE_CLASS cFilePath;

#undef CDB_CLASS
#define CDB_CLASS "cFilePathT"
///////////////////////////////////////////////////////////////////////
//  Class: cFilePathT
//
// Author: $author$
//   Date: 8/4/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement=cFilePathImplement,
 class TParser=cFilePathParser,
 class TParserEventsImplement=cFilePathParserEventsImplement,
 class TParserEventsInterface=cFilePathParserEventsInterface,
 class TStringInterface=cStringInterface,
 class TString=cString,
 class TChar=char,
 class TExtend=TString>

class c_INSTANCE_CLASS cFilePathT
: virtual public TImplement,
  virtual public TParserEventsImplement,
  public TExtend
{
public:
    typedef TImplement cImplements;
    typedef TExtend cExtends;

// include cFilePathT interface member definitions
//
#define CFILEPATHINTERFACET_MEMBERS_ONLY
#include "cFilePathInterface.hpp"
#undef CFILEPATHINTERFACET_MEMBERS_ONLY

    typedef TParserEventsInterface tParserEventsInterface;
    typedef TParser tParser;

    char_t m_volumeSeparatorChar;
    char_t m_directorySeparatorChar;
    char_t m_extensionSeparatorChar;

    tParser m_parser;

    bool m_isRootDirectory;
    bool m_isRelativeDirectory;

    tString m_fileHost;
    tString m_fileVolume;
    tString m_fileDirectory;
    tString m_fileBase;
    tString m_fileExtension;
    tString m_fileName;
    tString m_filePath;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cFilePathT
    //
    //       Author: $author$
    //         Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    cFilePathT
    (const char_t* chars=0, ssize_t length=-1)
    : cExtends(chars, length),
       m_volumeSeparatorChar((char_t)(PLATFORM_VOLUME_SEPARATOR_CHAR)),
       m_directorySeparatorChar((char_t)(PLATFORM_DIRECTORY_SEPARATOR_CHAR)),
       m_extensionSeparatorChar((char_t)(PLATFORM_EXTENSION_SEPARATOR_CHAR)),
       m_parser((tParserEventsInterface&)(*this)),
       m_isRootDirectory(false),
       m_isRelativeDirectory(false)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cFilePathT
    //
    //      Author: $author$
    //        Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cFilePathT()
    {
    }
#else // !defined(CFILEPATHT_MEMBERS_ONLY) 
#endif // !defined(CFILEPATHT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SeparateParts
    //
    //    Author: $author$
    //      Date: 8/8/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError SeparateParts()
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NONE;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t count = 0;
        if (0 > (count = ClearParts()))
            error = (eError)(-count);
        else
        error = m_parser.Parse(*this);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: CombineParts
    //
    //    Author: $author$
    //      Date: 8/8/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t CombineParts()
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length;
        const TChar* chars;
        bool hasHost;
        bool hasVolume;
        bool hasDirectory;
        bool hasFileBase;
        bool hasFileExtension;

        if (0 > (length = CTHIS Clear()))
            return length;

        if ((hasHost = (0 != (chars = m_fileHost.HasChars(length)))))
        {
            if (0 > (count = this->Append(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = this->Append(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = this->Append(chars, length)))
                return count;
        }

        if ((hasVolume = (0 != (chars = m_fileVolume.HasChars(length)))))
        {
            if (hasHost)
            if (0 > (count = this->Append(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = this->Append(chars, length)))
                return count;
            if (0 > (count = this->Append(&m_volumeSeparatorChar, 1)))
                return count;
        }

        if ((hasDirectory = (0 != (chars = m_fileDirectory.HasChars(length)))))
        {
            if ((hasHost && !hasVolume) || m_isRootDirectory)
            if (0 > (count = this->Append(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = this->Append(chars, length)))
                return count;
        }

        if ((hasFileBase = (0 != (chars = m_fileBase.HasChars(length)))))
        {
            if (hasDirectory || m_isRootDirectory || (hasHost && !hasVolume))
            if (0 > (count = this->Append(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = this->Append(chars, length)))
                return count;

            if ((hasFileExtension = (0 != (chars = m_fileExtension.HasChars(length)))))
            {
                if (0 > (count = this->Append(&m_extensionSeparatorChar, 1)))
                    return count;
                if (0 > (count = this->Append(chars, length)))
                    return count;
            }
        }
        else if (m_isRootDirectory)
        {
            if (0 > (count = this->Append(&m_directorySeparatorChar, 1)))
                return count;
        }
        count = CTHIS Length();
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: ClearParts
    //
    //    Author: $author$
    //      Date: 8/8/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ClearParts()
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        m_isRootDirectory = false;
        m_isRelativeDirectory = false;
        if (0 <= (count = m_fileHost.Clear()))
        if (0 <= (count = m_fileVolume.Clear()))
        if (0 <= (count = m_fileDirectory.Clear()))
        if (0 <= (count = m_fileBase.Clear()))
        if (0 <= (count = m_fileExtension.Clear()))
        if (0 <= (count = m_fileName.Clear()))
            count = m_filePath.Clear();
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 

    //
    // Set
    //

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetFileHost
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SetFileHost
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        count = m_fileHost.Assign(chars,length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetFileVolume
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SetFileVolume
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        count = m_fileVolume.Assign(chars,length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetFileDirectory
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SetFileDirectory
    (const char_t* chars,
     ssize_t length=-1,
     bool isRoot=false)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        if (0 > (count = m_fileDirectory.Clear()))
            return count;
        if ((isRoot))
        if (0 > (count = m_fileDirectory.Append(&m_directorySeparatorChar, 1)))
            return count;
        if (0 > (length = m_fileDirectory.Append(chars,length)))
            return length;
        count += length;
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: AppendFileDirectory
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t AppendFileDirectory
    (const char_t* chars,
     ssize_t length=-1,
     bool isRoot=false)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        if ((0 < (count = m_fileDirectory.Length())) || isRoot)
        if (0 > (count = m_fileDirectory.Append(&m_directorySeparatorChar, 1)))
            return count;
        if (0 > (length = m_fileDirectory.Append(chars,length)))
            return length;
        count += length;
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetFileBase
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SetFileBase
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        count = m_fileBase.Assign(chars,length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetFileExtension
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SetFileExtension
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        count = m_fileExtension.Assign(chars,length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetFileName
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SetFileName
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        count = m_fileName.Assign(chars,length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetFilePath
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SetFilePath
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        count = m_filePath.Assign(chars,length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetIsRootDirectory
    //
    //    Author: $author$
    //      Date: 8/8/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsRootDirectory
    (bool isTrue=true)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        bool is = false;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        is = (m_isRootDirectory = isTrue);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return is;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: SetIsRelativeDirectory
    //
    //    Author: $author$
    //      Date: 8/8/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsRelativeDirectory
    (bool isTrue=true)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        bool is = false;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        is = (m_isRelativeDirectory = isTrue);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return is;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 

    //
    // Get
    //

    ///////////////////////////////////////////////////////////////////////
    //  Function: GetFileHostChars
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* GetFileHostChars
    (ssize_t& length) const
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        const char_t* chars = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        chars = m_fileHost.HasChars(length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetFileVolumeChars
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* GetFileVolumeChars
    (ssize_t& length) const
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        const char_t* chars = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        chars = m_fileVolume.HasChars(length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetFileDirectoryChars
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* GetFileDirectoryChars
    (ssize_t& length) const
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        const char_t* chars = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        chars = m_fileDirectory.HasChars(length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetFileBaseChars
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* GetFileBaseChars
    (ssize_t& length) const
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        const char_t* chars = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        chars = m_fileBase.HasChars(length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetFileExtensionChars
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* GetFileExtensionChars
    (ssize_t& length) const
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        const char_t* chars = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        chars = m_fileExtension.HasChars(length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetFileNameChars
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* GetFileNameChars
    (ssize_t& length) const
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        const char_t* chars = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        chars = m_fileName.HasChars(length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetFilePathChars
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* GetFilePathChars
    (ssize_t& length) const
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        const char_t* chars = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        chars = m_filePath.HasChars(length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return chars;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetIsRootDirectory
    //
    //    Author: $author$
    //      Date: 8/8/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsRootDirectory() const
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        bool is = false;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        is = (m_isRootDirectory);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return is;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetIsRelativeDirectory
    //
    //    Author: $author$
    //      Date: 8/8/2011
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsRelativeDirectory() const
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        bool is = false;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        is = (m_isRelativeDirectory);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return is;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 

    //
    // On
    //

    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathHost
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathHost
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        count = SetFileHost(chars,length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathVolume
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathVolume
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        count = SetFileVolume(chars,length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathDirectory
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathDirectory
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        count = AppendFileDirectory(chars,length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathCurrentDirectory
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathCurrentDirectory
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        if (!m_isRootDirectory)
        if (1 > (count = m_fileHost.Length()))
        if (1 > (count = m_fileVolume.Length()))
        if (1 > (count = m_fileDirectory.Length()))
            m_isRelativeDirectory = true;
        count = AppendFileDirectory(chars,length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathParentDirectory
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathParentDirectory
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        if (!m_isRootDirectory)
        if (1 > (count = m_fileHost.Length()))
        if (1 > (count = m_fileVolume.Length()))
        if (1 > (count = m_fileDirectory.Length()))
            m_isRelativeDirectory = true;
        count = AppendFileDirectory(chars,length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathRootDirectory
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathRootDirectory
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        m_isRootDirectory = true;
        count = AppendFileDirectory(chars,length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathRootCurrentDirectory
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathRootCurrentDirectory
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        m_isRootDirectory = true;
        count = AppendFileDirectory(chars,length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathRootParentDirectory
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathRootParentDirectory
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        m_isRootDirectory = true;
        count = AppendFileDirectory(chars,length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathFileBase
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathFileBase
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        count = SetFileBase(chars,length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathRootFileBase
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathRootFileBase
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        m_isRootDirectory = true;
        count = SetFileBase(chars,length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnPathFileExtension
    //
    //    Author: $author$
    //      Date: 8/4/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OnPathFileExtension
    (const char_t* chars,
     ssize_t length=-1)
#if defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT)
        count = SetFileExtension(chars,length);
#else // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CFILEPATHT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CFILEPATHT_MEMBER_FUNCS_INTERFACE) 

#if !defined(CFILEPATHT_MEMBERS_ONLY)
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cFilePathExtend
//
//  Author: $author$
//    Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
typedef cFilePathT<>
cFilePathExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cFilePath
//
// Author: $author$
//   Date: 8/6/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cFilePath
: public cFilePathExtend
{
public:
    typedef cFilePathExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cFilePath
    //
    //       Author: $author$
    //         Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    cFilePath
    (const char_t* chars=0, ssize_t length=-1)
    : cExtends(chars, length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cFilePath
    //
    //      Author: $author$
    //        Date: 8/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cFilePath()
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CFILEPATHT_MEMBERS_ONLY) 
#endif // !defined(CFILEPATHT_MEMBERS_ONLY) 

#endif // !defined(_CFILEPATH_HPP) || defined(CFILEPATHT_MEMBERS_ONLY) 
        

