///////////////////////////////////////////////////////////////////////
//   File: cevfilesystementryfilter.hpp
//
// Author: $author$
//   Date: 9/27/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILESYSTEMENTRYFILTER_HPP
#define _CEVFILESYSTEMENTRYFILTER_HPP

#include "evfilesystementryfilter.hpp"
#include "cevfilesystementryreader.hpp"
#include "cevfilematch.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileSystemEntryFilter
//
// Author: $author$
//   Date: 9/27/2007
///////////////////////////////////////////////////////////////////////
class CEvFileSystemEntryFilter
: virtual public EvFileSystemEntryFilter,
  public CEvBase
{
public:
    typedef EvFileSystemEntryFilter CImplements;
    typedef CEvBase CExtends;
    typedef CEvFileSystemEntryFilter CDerives;

    CEvFileSystemEntryReader m_entryReader;

    CEvFileMatch m_match;
    CEvFileMatch m_skipMatch;

    CEvString m_matchPatterns;
    CEvString m_skipMatchPatterns;

    bool m_ignoreMatchCase;
    bool m_ignoreSkipMatchCase;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileSystemEntryFilter
    //
    //       Author: $author$
    //         Date: 9/27/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileSystemEntryFilter
    (const char* matchPatterns=0,
     const char* skipMatchPatterns=0) 
    : m_ignoreMatchCase(false),
      m_ignoreSkipMatchCase(false)
    {
        EvError error;

        if (matchPatterns)
        if ((error = SetMatch(matchPatterns)))
            throw(error);

        if (skipMatchPatterns)
        if ((error = SetSkipMatch(skipMatchPatterns)))
            throw(error);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvFileSystemEntryFilter
    //
    //      Author: $author$
    //        Date: 9/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvFileSystemEntryFilter()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadFirst
    //
    //   Author: $author$
    //     Date: 9/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int ReadFirst
    (EvFilePath& filePath,
     EvFileSystemEntryTimes& fileTimes,
     const char* chars,
     const char* chars2=0,
     bool isRecursive=false,
     bool isReflective=false) 
    {
        int pathEntryType = EvFileSystemEntry::EV_TYPE_NONE;
        int entryType = ReadFirst
        (filePath, fileTimes, pathEntryType,
         chars, chars2, isRecursive, isReflective);
        return entryType;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadFirst
    //
    //   Author: $author$
    //     Date: 9/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int ReadFirst
    (EvFilePath& filePath,
     EvFileSystemEntryTimes& fileTimes,
     int& pathEntryType,
     const char* chars,
     const char* chars2=0,
     bool isRecursive=false,
     bool isReflective=false) 
    {
        int entryType = EvFileSystemEntry::EV_TYPE_NONE;
        int type;

        if (0 < (type = m_entryReader.ReadFirst
            (filePath, fileTimes, pathEntryType, 
             chars, chars2, isRecursive, isReflective)))
        do
        {
            if (Matches(filePath))
                return entryType = type;
        }
        while (0 < (type = m_entryReader.ReadNext
               (filePath, fileTimes)));

        return entryType;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: ReadNext
    //
    //   Author: $author$
    //     Date: 9/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int ReadNext
    (EvFilePath& filePath,
     EvFileSystemEntryTimes& fileTimes) 
    {
        int entryType = EvFileSystemEntry::EV_TYPE_NONE;
        int type;

        while (0 < (type = m_entryReader.ReadNext
               (filePath, fileTimes)))
        {
            if (Matches(filePath))
                return entryType = type;
        }
        return entryType;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Matches
    //
    //   Author: $author$
    //     Date: 9/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool Matches
    (const EvFilePath& filePath) 
    {
        bool does = true;
        const char* chars;
        LONG length;

        if ((chars = filePath.HasChars(length)))
        if ((chars = m_skipMatchPatterns.HasChars(length)))
        if ((m_skipMatch.Matches(filePath)))
            return false;

        if ((chars = m_matchPatterns.HasChars(length)))
            does = m_match.Matches(filePath, m_ignoreMatchCase);
        return does;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetMatch
    //
    //   Author: $author$
    //     Date: 9/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetMatch
    (const char* chars,
     LONG length=-1) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if (0 <= (length = m_matchPatterns.Assign(chars, length)))
        if ((chars = m_matchPatterns.Chars(length)))
        if (!(error2 = m_match.Match(chars, length)))
            error = EV_ERROR_NONE;

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMatch
    //
    //   Author: $author$
    //     Date: 9/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetMatch
    (LONG& length) const 
    {
        const char* chars = m_matchPatterns.Chars(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetSkipMatch
    //
    //   Author: $author$
    //     Date: 9/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetSkipMatch
    (const char* chars,
     LONG length=-1) 
    {
        EvError error = EV_ERROR_FAILED;
        EvError error2;

        if (0 <= (length = m_skipMatchPatterns.Assign(chars, length)))
        if ((chars = m_skipMatchPatterns.Chars(length)))
        if (!(error2 = m_skipMatch.Match(chars, length)))
            error = EV_ERROR_NONE;

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetSkipMatch
    //
    //   Author: $author$
    //     Date: 9/27/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetSkipMatch
    (LONG& length) const 
    {
        const char* chars = m_skipMatchPatterns.Chars(length);
        return chars;
    }
};
#endif // _CEVFILESYSTEMENTRYFILTER_HPP
