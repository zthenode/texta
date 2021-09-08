///////////////////////////////////////////////////////////////////////
//   File: cevfilesystementrytimesdeligate.hpp
//
// Author: $author$
//   Date: 7/10/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILESYSTEMENTRYTIMESDELIGATE_HPP
#define _CEVFILESYSTEMENTRYTIMESDELIGATE_HPP

#include "evfilesystementrytimes.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileSystemEntryTimesDeligateT
//
// Author: $author$
//   Date: 7/10/2007
///////////////////////////////////////////////////////////////////////
template
<class TDeligate,
 class TExtends=CEvBase,
 class TImplements=EvFileSystemEntryTimes>

class CEvFileSystemEntryTimesDeligateT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements CImplements;
    typedef TExtends CExtends;
    typedef CEvFileSystemEntryTimesDeligateT CDerives;

    const TDeligate& m_deligate;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileSystemEntryTimesDeligateT
    //
    //       Author: $author$
    //         Date: 7/10/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileSystemEntryTimesDeligateT
    (const TDeligate& deligate)
    : m_deligate(deligate) 
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetCreatedFileTime
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetCreatedFileTime
    (const EvFileTime& fileTime) 
    {
        EvError error = EV_ERROR_NOT_ALLOWED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCreatedFileTime
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvFileTime& GetCreatedFileTime() const
    {
        return m_deligate.GetCreatedFileTime();
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetChangedFileTime
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetChangedFileTime
    (const EvFileTime& fileTime) 
    {
        EvError error = EV_ERROR_NOT_ALLOWED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetChangedFileTime
    //
    //   Author: $author$
    //     Date: 8/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvFileTime& GetChangedFileTime() const
    {
        return m_deligate.GetChangedFileTime();
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetModifiedFileTime
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetModifiedFileTime
    (const EvFileTime& fileTime) 
    {
        EvError error = EV_ERROR_NOT_ALLOWED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetModifiedFileTime
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvFileTime& GetModifiedFileTime() const
    {
        return m_deligate.GetModifiedFileTime();
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetAccessedFileTime
    //
    //   Author: $author$
    //     Date: 8/24/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetAccessedFileTime
    (const EvFileTime& fileTime) 
    {
        EvError error = EV_ERROR_NOT_ALLOWED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetAccessedFileTime
    //
    //   Author: $author$
    //     Date: 6/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvFileTime& GetAccessedFileTime() const
    {
        return m_deligate.GetAccessedFileTime();
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetFirstFileTime
    //
    //   Author: $author$
    //     Date: 6/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvFileTime* GetFirstFileTime
    (const_CEvFileTimesIterator& iterator) const
    {
        return m_deligate.GetFirstFileTime(iterator);
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetNextFileTime
    //
    //   Author: $author$
    //     Date: 6/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const EvFileTime* GetNextFileTime
    (const_CEvFileTimesIterator& iterator) const
    {
        return m_deligate.GetNextFileTime(iterator);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFirstFileTime
    //
    //   Author: $author$
    //     Date: 6/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvFileTime* SetFirstFileTime
    (CEvFileTimesIterator& iterator)
    {
        EvFileTime* fileTime = 0;
        return fileTime;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetNextFileTime
    //
    //   Author: $author$
    //     Date: 6/20/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvFileTime* SetNextFileTime
    (CEvFileTimesIterator& iterator)
    {
        EvFileTime* fileTime = 0;
        return fileTime;
    }
};
#endif // _CEVFILESYSTEMENTRYTIMESDELIGATE_HPP
