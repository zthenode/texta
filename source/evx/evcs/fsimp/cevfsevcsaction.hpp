///////////////////////////////////////////////////////////////////////
//   File: cevfsevcsaction.hpp
//
// Author: $author$
//   Date: 10/4/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFSEVCSACTION_HPP
#define _CEVFSEVCSACTION_HPP

#include "cevcsaction.hpp"
#include "cevfilesystementry.hpp"
#include "cevfilesystem.hpp"
#include "cevfilepath.hpp"
#include "cevcscharfile.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvfsEvcsAction
//
// Author: $author$
//   Date: 10/4/2007
///////////////////////////////////////////////////////////////////////
template
<class TExtends=CEvAction>

class CEvfsEvcsAction
: public TExtends
{
public:
    typedef TExtends CExtends;
    typedef CEvfsEvcsAction CDerives;

    EvcsArchive& m_archive;

    CEvFilePath m_vcDirectory;
    CEvFilePath m_vcPath;
    CEvFilePath m_vcFilePath;

    CEvFilePath m_tempDirectory;
    CEvFilePath m_tempPath;
    CEvFilePath m_tempFilePath;

    CEvFilePath m_entryPath;

    CEvcsCharFile m_vcFile;
    CEvcsCharFile m_tempFile;

    CEvFileSystemEntry m_fileSystemEntry;
    CEvFileSystem m_fileSystem;

    bool m_isBinary;
    const char* m_versionDirectory;
    const char* m_versionExtension;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvfsEvcsAction
    //
    //       Author: $author$
    //         Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvfsEvcsAction
    (EvcsArchive& archive,
     const char* vcDirectory=0,
     const char* tempDirectory=0) 
    : m_archive(archive),
      m_isBinary(false),
      m_versionDirectory(0),
      m_versionExtension(0) 
    {
        EvError error;
        LONG length;

        if (0 > (length = m_vcDirectory.AssignChars(vcDirectory)))
            throw(error = -length);

        if (0 > (length = m_tempDirectory.AssignChars(tempDirectory)))
            throw(error = -length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvfsEvcsAction
    //
    //      Author: $author$
    //        Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvfsEvcsAction()
    {
    }
};
#endif // _CEVFSEVCSACTION_HPP
