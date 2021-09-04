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
//   File: cUnixFileSystemEntry.hpp
//
// Author: $author$
//   Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CUNIXFILESYSTEMENTRY_HPP) || defined(CUNIXFILESYSTEMENTRY_MEMBERS_ONLY)
#if !defined(_CUNIXFILESYSTEMENTRY_HPP) && !defined(CUNIXFILESYSTEMENTRY_MEMBERS_ONLY)
#define _CUNIXFILESYSTEMENTRY_HPP
#endif // !defined(_CUNIXFILESYSTEMENTRY_HPP) && !defined(CUNIXFILESYSTEMENTRY_MEMBERS_ONLY) 

#if !defined(CUNIXFILESYSTEMENTRY_MEMBERS_ONLY)
#include "cUnixFileSystemEntryInterface.hpp"
#include "cUnixFileSystemEntryTime.hpp"
#include "cFileSystemEntryBase.hpp"
#include "cUnixFileStat.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cUnixFileSystemEntryExtend
//
//  Author: $author$
//    Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
typedef cFileSystemEntryBase
cUnixFileSystemEntryExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cUnixFileSystemEntry
//
// Author: $author$
//   Date: 8/24/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cUnixFileSystemEntry
: virtual public cUnixFileSystemEntryImplement,
  public cUnixFileSystemEntryExtend
{
public:
    typedef cUnixFileSystemEntryImplement cImplements;
    typedef cUnixFileSystemEntryExtend cExtends;

    cUnixFileStat m_fileStat;

    cUnixFileSystemEntryTime m_timeModified;
    cUnixFileSystemEntryTime m_timeAccessed;
    cUnixFileSystemEntryTime m_timeChanged;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cUnixFileSystemEntry
    //
    //       Author: $author$
    //         Date: 8/24/2011
    ///////////////////////////////////////////////////////////////////////
    cUnixFileSystemEntry
    (time_t timeModified=(time_t)(-1),
     time_t timeAccessed=(time_t)(-1),
     time_t timeChanged=(time_t)(-1))
    : m_timeModified(e_FILE_SYSTEM_ENTRY_TIME_WHEN_MODIFIED, timeModified),
      m_timeAccessed(e_FILE_SYSTEM_ENTRY_TIME_WHEN_ACCESSED, timeAccessed),
      m_timeChanged(e_FILE_SYSTEM_ENTRY_TIME_WHEN_CHANGED, timeChanged)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cUnixFileSystemEntry
    //
    //      Author: $author$
    //        Date: 8/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cUnixFileSystemEntry()
    {
    }
#else // !defined(CUNIXFILESYSTEMENTRY_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESYSTEMENTRY_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: SetStatAttributes
    //
    //    Author: $author$
    //      Date: 8/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eFileSystemEntryType SetStatAttributes
    (const struct stat& st)
#if defined(CUNIXFILESYSTEMENTRY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CUNIXFILESYSTEMENTRY_MEMBER_FUNCS_INTERFACE) 
    {
        eFileSystemEntryType type = e_FILE_SYSTEM_ENTRY_TYPE_NONE;
#if !defined(CUNIXFILESYSTEMENTRY_MEMBER_FUNCS_IMPLEMENT)

        if (S_IFDIR == (S_IFDIR & st.st_mode))
            type = SetType(e_FILE_SYSTEM_ENTRY_TYPE_DIRECTORY);
        else
        type = SetType(e_FILE_SYSTEM_ENTRY_TYPE_FILE);

        m_timeModified.Set(st.st_mtime);
        m_timeAccessed.Set(st.st_atime);
        m_timeChanged.Set(st.st_ctime);

#else // !defined(CUNIXFILESYSTEMENTRY_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CUNIXFILESYSTEMENTRY_MEMBER_FUNCS_IMPLEMENT) 
        return type;
    }
#endif // defined(CUNIXFILESYSTEMENTRY_MEMBER_FUNCS_INTERFACE) 

#if !defined(CUNIXFILESYSTEMENTRY_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Exists
    //
    //    Author: $author$
    //      Date: 8/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eFileSystemEntryType Exists
    (const cString& fileName)
    {
        eFileSystemEntryType type = e_FILE_SYSTEM_ENTRY_TYPE_NONE;
        struct stat& st = m_fileStat;
        const char* fileNameChars;
        int err;

        if ((fileNameChars = fileName.HasChars()))
        if (!(err = stat(fileNameChars, &st)))
            type = SetStatAttributes(st);
        else
        c_DB_TRACE("() failed on stat(\"" << fileNameChars << "\",...)");
        return type;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CUNIXFILESYSTEMENTRY_MEMBERS_ONLY) 
#endif // !defined(CUNIXFILESYSTEMENTRY_MEMBERS_ONLY) 

#endif // !defined(_CUNIXFILESYSTEMENTRY_HPP) || defined(CUNIXFILESYSTEMENTRY_MEMBERS_ONLY) 
        

