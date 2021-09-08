///////////////////////////////////////////////////////////////////////
//   File: cevcsentry.hpp
//
// Author: $author$
//   Date: 9/28/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCSENTRY_HPP
#define _CEVCSENTRY_HPP

#include "evcsentry.hpp"
#include "cevinstance.hpp"
#include "cevfilepath.hpp"
#include "cevfilesystementrytimes.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsEntry
//
// Author: $author$
//   Date: 9/28/2007
///////////////////////////////////////////////////////////////////////
class CEvcsEntry
: virtual public EvcsEntry,
  public CEvInstance
{
public:
    typedef EvcsEntry CImplements;
    typedef CEvInstance CExtends;
    typedef CEvcsEntry CDerives;

    CEvFilePath m_fileName;
    CEvFilePath m_filePath;
    CEvFilePath m_relativeFilePath;

    CEvFileSystemEntryTimes m_fileTimes;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsEntry
    //
    //       Author: $author$
    //         Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsEntry() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetName
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetName
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_fileName.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetName
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetName
    (LONG& length) const 
    {
        const char* chars = m_fileName.Chars(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetPathName
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetPathName
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_filePath.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetPathName
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetPathName
    (LONG& length) const 
    {
        const char* chars = m_filePath.Chars(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetRelativePathName
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetRelativePathName
    (const char* chars,
     LONG length=-1) 
    {
        LONG count = m_relativeFilePath.Assign(chars,length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetRelativePathName
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetRelativePathName
    (LONG& length) const 
    {
        const char* chars = m_relativeFilePath.Chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetFilePath
    //
    //   Author: $author$
    //     Date: 10/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvFilePath& GetFilePath() const 
    {
        return (EvFilePath&)(m_filePath);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetRelativeFilePath
    //
    //   Author: $author$
    //     Date: 10/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvFilePath& GetRelativeFilePath() const 
    {
        return (EvFilePath&)(m_relativeFilePath);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFileTimes
    //
    //   Author: $author$
    //     Date: 10/1/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvFileSystemEntryTimes& GetFileTimes() const 
    {
        return (EvFileSystemEntryTimes&)(m_fileTimes);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 9/28/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis() 
    {
        delete this;
        return EV_ERROR_NONE;
    }
};
#endif // _CEVCSENTRY_HPP
