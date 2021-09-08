///////////////////////////////////////////////////////////////////////
//   File: evls.hpp
//
// Author: $author$
//   Date: 6/1/2007
///////////////////////////////////////////////////////////////////////

#ifndef _EVLS_HPP
#define _EVLS_HPP

#include "cevfilesystementryreader.hpp"
#include "cevfilematch.hpp"
#include "cevfilematchwriter.hpp"
#include "cevfilepathstring.hpp"
#include "cevcomparedfile.hpp"
#include "cevcompares.hpp"
#include "cevmain.hpp"

#define DEFAULT_EVLS_PATH "c:/temp"

#define DEFAULT_EVLS_SKIP_PATTERNS \
	"*.o;*.obj"

#define DEFAULT_EVLS_MATCH_PATTERNS \
    "*.t;*.txt;*.xml;*.xsl;*.html;*.htm;*.css;*.js;*.php;" \
    "*.l;*.y;*.skl;*.h;*.c;*.hpp;*.cpp;*.hxx;*.cxx;*.rc;*.rc2;*.cs;*.java;" \
    "*.cmd;*.bat;*.001;*.mak;*.mdp;*.dsw;*.dsp;*.sln;*.vcproj;*.vsprops;" \
    "Makedefines;Makerules;Makedirs;Makefile;*.makefile;"\
    "DoMake;Makedefs;MakeTargets;buildit;" \
    "*.conf;*.crt;*.pem;*.pal;*.ico;*.bmp;*.gif;*.tif;*.jpg;*.png;" \
    "*.ai;*.sldprt;*.sldasm;*.dxf;*.pdf;*.doc;*.rtf;" \
    ""

#define EVLS_COMPARED_BYTES 4096

///////////////////////////////////////////////////////////////////////
//  Class: CEvLsMain
//
// Author: $author$
//   Date: 6/1/2007
///////////////////////////////////////////////////////////////////////
class CEvLsMain
: virtual public EvFileSystemEntryReaderEvents,
  public CEvMain
{
public:
    typedef CEvMain CExtends;
    typedef CEvLsMain CDerives;

    EvFileSystemEntryReaderEvents* m_oldEvents;

    bool m_isRecursive;
    bool m_isReflective;

    CEvCompares m_fileTimeCompares;

    bool m_matchCase;
    bool m_compareFiles;
    bool m_existingFiles;
    bool m_missingFiles;
    bool m_outputReverse;
    bool m_outputDirectory;
    bool m_outputDirectoryOnly;
    bool m_outputNameOnly;
    bool m_outputSourceOnly;
    bool m_outputTargetOnly;
    bool m_excludeFileSymbolicLinks;

    CEvString m_skip;
    CEvFileMatch m_fileSkip;

    CEvString m_match;
    CEvFileMatch m_fileMatch;

    CEvString m_skipFilename;
    CEvString m_matchFilename;
    CEvCharFile m_patternFile;

    CEvFilePath m_filePath;
    CEvFilePath m_reflectedPath;

    CEvFilePath m_entryPath;
    CEvFilePath m_reflectedEntryPath;
    CEvFilePathString m_nativeEntryPath;
    CEvFilePathString m_nativeReflectedEntryPath;
    CEvFileSystemEntryReader m_entryReader;

    CEvString m_outputBeforeDirectory;
    CEvString m_outputBetweenDirectory;
    CEvString m_outputAfterDirectory;

    CEvString m_outputBefore;
    CEvString m_outputBetween;
    CEvString m_outputAfter;

    CEvFileSystemEntry m_fileEntry;

    CEvComparedFile m_comparedFile;
    BYTE m_comparedBytes[EVLS_COMPARED_BYTES];

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvLsMain
    //
    //       Author: $author$
    //         Date: 6/1/2007
    ///////////////////////////////////////////////////////////////////////
    CEvLsMain
    (const char* skip=DEFAULT_EVLS_SKIP_PATTERNS,
     const char* match=DEFAULT_EVLS_MATCH_PATTERNS,
     bool matchCase=false,
     bool compareFiles=false,
     bool existingFiles=false,
     bool missingFiles=false,
     bool outputReverse=false,
     bool outputDirectory=false,
     bool outputDirectoryOnly=false,
     bool outputNameOnly=false,
     bool outputSourceOnly=false,
     bool outputTargetOnly=false,
     bool excludeFileSymbolicLinks=false)
    : m_oldEvents(0),
      m_isRecursive(false),
      m_isReflective(false),
      m_fileTimeCompares(EV_COMPARES_GT),
      m_matchCase(matchCase),
      m_compareFiles(compareFiles),
      m_existingFiles(existingFiles),
      m_missingFiles(missingFiles),
      m_outputReverse(outputReverse),
      m_outputDirectory(outputDirectory),
      m_outputDirectoryOnly(outputDirectoryOnly),
      m_outputNameOnly(outputNameOnly),
      m_outputSourceOnly(outputSourceOnly),
      m_outputTargetOnly(outputTargetOnly),
      m_excludeFileSymbolicLinks(excludeFileSymbolicLinks),
      m_outputBetween(" ")
    {
        EvError error;
        LONG length;

        if (skip)
        if (0 > (length = m_skip.Assign(skip)))
            throw(error = -length);

        if (match)
        if (0 > (length = m_match.Assign(match)))
            throw(error = -length);

        m_oldEvents = m_entryReader.SetEvents(this);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvLsMain
    //
    //      Author: $author$
    //        Date: 6/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvLsMain()
    {
        m_entryReader.SetEvents(m_oldEvents);
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
        bool isRecursive = GetIsRecursive();
        bool isReflective = GetIsReflective();
        int err = 0;
        EvError error;
        const char* chars;
        const char* chars2;
        LONG length;

        if (0 >= m_mainArgn)
            return Help(argc, argv, env);

        //
        // process skip patterns
        //
        if ((chars = m_skipFilename.HasChars(length)))
        {
            // process skip patterns from file
            //
            if ((error = m_patternFile.Open(chars)))
                DBE("() failed to open skip file \"", chars, "\"\n");
            else
            {
                if ((error = m_fileSkip.Match(m_patternFile)))
                    DBE("() failed to process skip file \"", chars, "\"\n");
                m_patternFile.Close();
            }
            if (error)
                return 1;
        }
        else
        if ((chars = m_skip.HasChars(length)))
        {
            // process skip patterns from string
            //
            if ((error = m_fileSkip.Match(chars, length)))
                return 1;
        }

        //
        // process match patterns
        //
        if ((chars = m_matchFilename.HasChars(length)))
        {
            // process match patterns from file
            //
            if ((error = m_patternFile.Open(chars)))
                DBE("() failed to open match file \"", chars, "\"\n");
            else
            {
                if ((error = m_fileMatch.Match(m_patternFile)))
                    DBE("() failed to process match file \"", chars, "\"\n");
                m_patternFile.Close();
            }
            if (error)
                return 1;
        }
        else
        if ((chars = m_match.Chars(length)))
        {
            // process match patterns from string
            //
            if ((error = m_fileMatch.Match(chars, length)))
                return 1;
        }

        if ((chars2 = m_reflectedPath.Chars(length)) && (1 > length))
            chars2 = 0;

        if ((chars = m_filePath.Chars(length)) && (0 < length))
            m_entryReader.Read
            (chars, chars2, isRecursive, isReflective);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArgn
    //
    //   Author: $author$
    //     Date: 6/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArgn
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        if (arg)
        if (1 > (args = (m_mainArgn++)))
            m_filePath.Assign(arg);
        else if (2 > args)
        {
            SetIsReflective();
            m_reflectedPath.Assign(arg);
        }
        return argn;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnMatchedFileDirectoryFileEntry
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMatchedFileDirectoryFileEntry
    (const EvFileDirectoryEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     const EvFilePath& entryPath,
     const EvFilePath& reflectedEntryPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        const EvFileTime& entryTime = entry.GetModifiedFileTime();
        EvFileDirectoryEntry::EvType entryType;
        EvFileDirectoryEntry::EvType reflectedEntryType;
        ULONGLONG entrySize;
        ULONGLONG reflectedEntrySize;
        EvError error = EV_ERROR_NONE;
        const char* chars;
        const char* chars2;
        LONG length2;
        LONG length;
        int unequal;

        if ((GetOutputDirectoryOnly()))
            return error;

        if (0 >= (entryType = entry.GetType()))
            return error;

        if (!(chars = entryPath.HasChars(length)))
            return error;

        if (!(chars2 = reflectedEntryPath.HasChars(length2)))
            return error;

        if (0 >= (reflectedEntryType = m_fileEntry.Exists(chars2, length2)))
        {
            if ((GetExistingFiles()))
                return error;
        }
        else
        if ((GetMissingFiles()))
            return error;
        else
        if (reflectedEntryType == entryType)
        {
            const EvFileTime& reflectedEntryTime 
            = m_fileEntry.GetModifiedFileTime();

            if (!m_fileTimeCompares.Compares
                (unequal = entryTime.CompareDateTime(reflectedEntryTime)))
                return error;
            else
            if (!m_fileTimeCompares.Compares
                (unequal = entryTime.CompareDateTime(reflectedEntryTime)))
                return error;

            if (GetCompareFiles())
            if (0 <= (entrySize = entry.GetSize()))
            if (0 <= (reflectedEntrySize = m_fileEntry.GetSize()))
            if ((entrySize == reflectedEntrySize) && (1 > entrySize))
                return error;
            else
            if (!(unequal = m_comparedFile.Compare
                (m_comparedBytes, sizeof(m_comparedBytes), chars2, chars)))
                return error;
        }

        if ((GetOutputNameOnly()))
            chars = (chars2 = entry.GetName(length));

        if (GetOutputReverse())
        {
            const char* chars3 = chars2;
            chars2 = chars;
            chars = chars3;
        }

        if (GetOutputSourceOnly())
            OutputPath(chars);
        else if (GetOutputTargetOnly())
                OutputPath(chars2);
        else OutputPaths(chars, chars2);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMatchedFileDirectoryFileEntry
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMatchedFileDirectoryFileEntry
    (const EvFileDirectoryEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& entryPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        EvError error = EV_ERROR_NONE;
        const char* chars;
        LONG length;

        if ((GetOutputDirectoryOnly()))
            return error;

        if ((GetOutputNameOnly()))
            chars = entry.GetName(length);
        else chars = entryPath.Chars(length);

        if ((chars) && (0 < length))
            OutputPath(chars);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OutputBeforeDirectory
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG OutputBeforeDirectory
    (const char* pathChars) 
    {
        LONG count = 0;
        LONG length;
        const char* chars;
        
        if ((chars = m_outputBefore.Chars(length)) && (0 < length))
            count += printf("%s", chars);

        count += printf("%s", pathChars);

        if ((chars = m_outputAfter.Chars(length)) && (0 < length))
            count += printf("%s", chars);

        count += printf("\n");

        if ((chars = m_outputBeforeDirectory.Chars(length)) && (0 < length))
            count += printf("%s\n", chars);

        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OutputAfterDirectory
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG OutputAfterDirectory() 
    {
        LONG count = 0;
        LONG length;
        const char* chars;
        
        if ((chars = m_outputAfterDirectory.Chars(length)) && (0 < length))
            count += printf("%s\n", chars);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OutputPath
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG OutputPath
    (const char* pathChars) 
    {
        LONG count = 0;
        LONG length;
        const char* chars;
        
        if (0 < (length = m_nativeEntryPath.NativeAssign(pathChars)))
        if ((chars = m_nativeEntryPath.Chars(length)) && (0 < length))
            pathChars = chars;

        if ((chars = m_outputBefore.Chars(length)) && (0 < length))
            count += printf("%s", chars);

        count += printf("%s", pathChars);

        if ((chars = m_outputAfter.Chars(length)) && (0 < length))
            count += printf("%s", chars);

        count += printf("\n");
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OutputPaths
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG OutputPaths
    (const char* pathChars, const char* pathChars2) 
    {
        LONG count = 0;
        LONG length;
        const char* chars;
        
        if (0 < (length = m_nativeEntryPath.NativeAssign(pathChars)))
        if ((chars = m_nativeEntryPath.Chars(length)) && (0 < length))
            pathChars = chars;

        if (0 < (length = m_nativeReflectedEntryPath.NativeAssign(pathChars2)))
        if ((chars = m_nativeReflectedEntryPath.Chars(length)) && (0 < length))
            pathChars2 = chars;

        if ((chars = m_outputBefore.Chars(length)) && (0 < length))
            count += printf("%s", chars);

        count += printf("%s", pathChars);

        if ((chars = m_outputBetween.Chars(length)) && (0 < length))
            count += printf("%s", chars);

        count += printf("%s", pathChars2);

        if ((chars = m_outputAfter.Chars(length)) && (0 < length))
            count += printf("%s", chars);

        count += printf("\n");
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemEntry
    (const EvFileSystemEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        EvError error = EV_ERROR_NONE;
        if (deligate)
            error = deligate->OnFileSystemEntry
            (entry, path, reflectedPath);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemFileEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemFileEntry
    (const EvFileSystemEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        EvError error = EV_ERROR_NONE;

        if (deligate)
            error = deligate->OnFileSystemFileEntry
            (entry, path, reflectedPath);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemFileEntrySymbolicLink
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemFileEntrySymbolicLink
    (const EvFileSystemEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0)
    {
        EvError error = EV_ERROR_NONE;

        if (deligate)
            error = deligate->OnFileSystemFileEntrySymbolicLink
            (entry, path, reflectedPath);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemDirectoryEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemDirectoryEntry
    (const EvFileSystemEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        EvError error = EV_ERROR_NONE;

        if (deligate)
            error = deligate->OnFileSystemDirectoryEntry
            (entry, path, reflectedPath);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileSystemDirectoryEntrySymbolicLink
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileSystemDirectoryEntrySymbolicLink
    (const EvFileSystemEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0)
    {
        EvError error = EV_ERROR_NONE;

        if (deligate)
            error = deligate->OnFileSystemDirectoryEntrySymbolicLink
            (entry, path, reflectedPath);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryEntry
    (const EvFileDirectoryEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        EvError error = EV_ERROR_NONE;
        if (deligate)
            error = deligate->OnFileDirectoryEntry
            (entry, path, reflectedPath);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryFileEntrySymbolicLink
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryFileEntrySymbolicLink
    (const EvFileDirectoryEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0)
    {
        EvError error = EV_ERROR_NONE;
        if (!(m_excludeFileSymbolicLinks))
            error = OnFileDirectoryFileEntry(entry, path, reflectedPath, deligate);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryFileEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryFileEntry
    (const EvFileDirectoryEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        EvError error = EV_ERROR_NONE;
        const char* chars;
        const char* entryChars;
        LONG entryLength;
        LONG length;
        bool matches;
        bool isReflective;

        if ((entryChars = entry.GetName(entryLength)) && (0 < entryLength))
        if ((chars = path.Chars(length)) && (0 <= length))
        if (0 <= (length = m_entryPath.AssignChars(chars, length)))
        if (0 < (length = m_entryPath.AppendFileName(entryChars, entryLength)))
        if ((chars = m_entryPath.Chars(length)) && (0 < length))
        if (!(matches = m_fileSkip.Matches(m_entryPath, !m_matchCase)))
        if ((matches = m_fileMatch.Matches(m_entryPath, !m_matchCase)))
        if ((isReflective = GetIsReflective()))
        {
            if ((chars = reflectedPath.Chars(length)) && (0 <= length))
            if (0 <= (length = m_reflectedEntryPath.AssignChars(chars, length)))
            if (0 < (length = m_reflectedEntryPath.AppendFileName(entryChars, entryLength)))
            if ((chars = m_reflectedEntryPath.Chars(length)) && (0 < length))
                error = OnMatchedFileDirectoryFileEntry
                (entry, path, reflectedPath,
                 m_entryPath, m_reflectedEntryPath, deligate);
        }
        else error = OnMatchedFileDirectoryFileEntry
             (entry, path, m_entryPath, deligate);

        if (deligate)
            error = deligate->OnFileDirectoryFileEntry
            (entry, path, reflectedPath);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryDirectoryEntrySymbolicLink
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryDirectoryEntrySymbolicLink
    (const EvFileDirectoryEntry& entry,
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0)
    {
        EvError error = EV_ERROR_NONE;
        if (!(m_excludeFileSymbolicLinks))
            error = OnFileDirectoryDirectoryEntry
            (entry, path, reflectedPath, deligate);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnFileDirectoryDirectoryEntry
    //
    //   Author: $author$
    //     Date: 6/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnFileDirectoryDirectoryEntry
    (const EvFileDirectoryEntry& entry, 
     const EvFilePath& path,
     const EvFilePath& reflectedPath,
     EvFileSystemEntryReaderEvents* deligate=0) 
    {
        EvError error = EV_ERROR_NONE;
        LONG length;
/*
        const char* chars;
        LONG length;

        printf("Directory: ");
        if ((chars = path.Chars(length)) && (0 < length))
            printf("%s/", chars);
        if ((chars = entry.GetName(length)) && (0 < length))
            printf("%s", chars);
        printf("\n");

        printf("        @: ");
        if ((chars = reflectedPath.Chars(length)) && (0 < length))
            printf("%s/", chars);
        printf("\n");
*/
        if ((GetOutputDirectory()))
        if (!(entry.GetIsCurrent()))
        if (!(entry.GetIsParent()))
            OutputBeforeDirectory(entry.GetName(length));

        if (deligate)
            error = deligate->OnFileDirectoryDirectoryEntry
            (entry, path, reflectedPath);

        if (!(error))
        if ((GetOutputDirectory()))
        if (!(entry.GetIsCurrent()))
        if (!(entry.GetIsParent()))
            OutputAfterDirectory();

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFilePath
    //
    //   Author: $author$
    //     Date: 6/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetFilePath
    (const char* chars,
     LONG length=-1) 
    {
        length = m_filePath.Assign(chars,length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFilePath
    //
    //   Author: $author$
    //     Date: 6/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetFilePath
    (LONG& length) const 
    {
        const char* chars = m_filePath.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetReflectedPath
    //
    //   Author: $author$
    //     Date: 6/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetReflectedPath
    (const char* chars,
     LONG length=-1) 
    {
        length = m_reflectedPath.Assign(chars,length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetReflectedPath
    //
    //   Author: $author$
    //     Date: 6/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetReflectedPath
    (LONG& length) const 
    {
        const char* chars = m_reflectedPath.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetMatchFilename
    //
    //   Author: $author$
    //     Date: 8/4/2008
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetMatchFilename
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_matchFilename.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMatchFilename
    //
    //   Author: $author$
    //     Date: 8/4/2008
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetMatchFilename
    (LONG& length) const 
    {
        const char* chars = m_matchFilename.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetSkipFilename
    //
    //   Author: $author$
    //     Date: 11/13/2009
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetSkipFilename
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_skipFilename.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetSkipFilename
    //
    //   Author: $author$
    //     Date: 11/13/2009
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetSkipFilename
    (LONG& length) const 
    {
        const char* chars = m_skipFilename.Chars(length);
        return chars;
    }
    
    ///////////////////////////////////////////////////////////////////////
    // Function: SetMatch
    //
    //   Author: $author$
    //     Date: 6/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetMatch
    (const char* chars,
     LONG length=-1) 
    {
        length = m_match.Assign(chars,length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMatch
    //
    //   Author: $author$
    //     Date: 6/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetMatch
    (LONG& length) const 
    {
        const char* chars = m_match.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetSkip
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetSkip
    (const char* chars,
     LONG length=-1) 
    {
        length = m_skip.Assign(chars,length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetSkip
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetSkip
    (LONG& length) const 
    {
        const char* chars = m_skip.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetOutputBeforeDirectory
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetOutputBeforeDirectory
    (const char* chars,
     LONG length=-1) 
    {
        LONG lengthBefore = m_outputBeforeDirectory.Assign(chars,length);
        return lengthBefore;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetOutputBeforeDirectory
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetOutputBeforeDirectory
    (LONG& length) const 
    {
        const char* charsBefore = m_outputBeforeDirectory.Chars(length);
        return charsBefore;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetOutputBetweenDirectory
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetOutputBetweenDirectory
    (const char* chars,
     LONG length=-1) 
    {
        LONG lengthBetween = m_outputBetweenDirectory.Assign(chars,length);
        return lengthBetween;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetOutputBetweenDirectory
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetOutputBetweenDirectory
    (LONG& length) const 
    {
        const char* charsBetween = m_outputBetweenDirectory.Chars(length);
        return charsBetween;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetOutputAfterDirectory
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetOutputAfterDirectory
    (const char* chars,
     LONG length=-1) 
    {
        LONG lengthAfter = m_outputAfterDirectory.Assign(chars,length);
        return lengthAfter;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetOutputAfterDirectory
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetOutputAfterDirectory
    (LONG& length) const 
    {
        const char* charsAfter = m_outputAfterDirectory.Chars(length);
        return charsAfter;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetOutputBefore
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetOutputBefore
    (const char* chars,
     LONG length=-1) 
    {
        LONG lengthBefore = m_outputBefore.Assign(chars,length);
        return lengthBefore;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetOutputBefore
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetOutputBefore
    (LONG& length) const 
    {
        const char* charsBefore = m_outputBefore.Chars(length);
        return charsBefore;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetOutputBetween
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetOutputBetween
    (const char* chars,
     LONG length=-1) 
    {
        LONG lengthBetween = m_outputBetween.Assign(chars,length);
        return lengthBetween;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetOutputBetween
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetOutputBetween
    (LONG& length) const 
    {
        const char* charsBetween = m_outputBetween.Chars(length);
        return charsBetween;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetOutputAfter
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetOutputAfter
    (const char* chars,
     LONG length=-1) 
    {
        LONG lengthAfter = m_outputAfter.Assign(chars,length);
        return lengthAfter;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetOutputAfter
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetOutputAfter
    (LONG& length) const 
    {
        const char* charsAfter = m_outputAfter.Chars(length);
        return charsAfter;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsRecursive
    //
    //   Author: $author$
    //     Date: 6/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsRecursive
    (bool is=true) 
    {
        m_isRecursive = is;
        return m_isRecursive;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsRecursive
    //
    //   Author: $author$
    //     Date: 6/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsRecursive
    (bool is=true) const 
    {
        return m_isRecursive;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetIsReflective
    //
    //   Author: $author$
    //     Date: 6/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsReflective
    (bool is=true) 
    {
        m_isReflective = is;
        return m_isReflective;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetIsReflective
    //
    //   Author: $author$
    //     Date: 6/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetIsReflective
    (bool is=true) const 
    {
        return m_isReflective;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetOutputReverse
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetOutputReverse
    (bool on=true)
    {
        m_outputReverse = on;
        return m_outputReverse;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetOutputReverse
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetOutputReverse() const
    {
        return m_outputReverse;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetOutputDirectory
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetOutputDirectory
    (bool on=true)
    {
        m_outputDirectory = on;
        return m_outputDirectory;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetOutputDirectory
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetOutputDirectory() const
    {
        return m_outputDirectory;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetOutputDirectoryOnly
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetOutputDirectoryOnly
    (bool on=true)
    {
        m_outputDirectoryOnly = on;
        return m_outputDirectoryOnly;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetOutputDirectoryOnly
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetOutputDirectoryOnly() const
    {
        return m_outputDirectoryOnly;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetOutputNameOnly
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetOutputNameOnly
    (bool on=true)
    {
        m_outputNameOnly = on;
        return m_outputNameOnly;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetOutputNameOnly
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetOutputNameOnly() const
    {
        return m_outputNameOnly;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetOutputSourceOnly
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetOutputSourceOnly
    (bool on=true) 
    {
        m_outputSourceOnly = on;
        return m_outputSourceOnly;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetOutputSourceOnly
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetOutputSourceOnly() const 
    {
        return m_outputSourceOnly;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetOutputTargetOnly
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetOutputTargetOnly
    (bool on=true) 
    {
        m_outputTargetOnly = on;
        return m_outputTargetOnly;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetOutputTargetOnly
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetOutputTargetOnly() const 
    {
        return m_outputTargetOnly;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetCompareFiles
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetCompareFiles
    (bool on=true) 
    {
        m_compareFiles = on;
        return m_compareFiles;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCompareFiles
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetCompareFiles() const 
    {
        return m_compareFiles;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetCompareOlderFiles
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetCompareOlderFiles
    (bool on=true)
    {
        CEvCompares::ComparesWhat compares = (on)?(EV_COMPARES_LT):(EV_COMPARES_GT);
        m_fileTimeCompares.m_compares = compares;
        return (EV_COMPARES_LT == m_fileTimeCompares.m_compares);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCompareOlderFiles
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetCompareOlderFiles() const
    {
        return (EV_COMPARES_LT == m_fileTimeCompares.m_compares);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetCompareAllFiles
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetCompareAllFiles
    (bool on=true)
    {
        CEvCompares::ComparesWhat compares = (on)?(EV_COMPARES_TRUE):(EV_COMPARES_GT);
        m_fileTimeCompares.m_compares = compares;
        return (EV_COMPARES_TRUE == m_fileTimeCompares.m_compares);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCompareAllFiles
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetCompareAllFiles() const
    {
        return (EV_COMPARES_TRUE == m_fileTimeCompares.m_compares);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetExistingFiles
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetExistingFiles
    (bool on=true)
    {
        m_existingFiles = on;
        return m_existingFiles;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetExistingFiles
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetExistingFiles() const
    {
        return m_existingFiles;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetMissingFiles
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetMissingFiles
    (bool on=true)
    {
        m_missingFiles = on;
        return m_missingFiles;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMissingFiles
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetMissingFiles() const
    {
        return m_missingFiles;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetMatchCase
    //
    //   Author: $author$
    //     Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetMatchCase(bool on=true) 
    {
        m_matchCase = on;
        return m_matchCase;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMatchCase
    //
    //   Author: $author$
    //     Date: 7/25/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetMatchCase() const 
    {
        return m_matchCase;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetExcludeFileSymbolicLinks
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int SetExcludeFileSymbolicLinks
    (bool on=true)
    {
        m_excludeFileSymbolicLinks = on;
        return m_excludeFileSymbolicLinks;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetExcludeFileSymbolicLinks
    //
    //   Author: $author$
    //     Date: 8/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetExcludeFileSymbolicLinks() const
    {
        return m_excludeFileSymbolicLinks;
    }
};
#endif // _EVLS_HPP
