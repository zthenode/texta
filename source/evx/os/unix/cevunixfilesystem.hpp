///////////////////////////////////////////////////////////////////////
//   File: cevunixfilesystem.hpp
//
// Author: $author$
//   Date: 8/11/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVUNIXFILESYSTEM_HPP
#define _CEVUNIXFILESYSTEM_HPP

#include "cevunixfiletime.hpp"
#include "evplatform_utime.h"
#include "evdebug.h"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvUnixFileSystemExtends
//
//   Author: $author$
//     Date: 8/11/2007
///////////////////////////////////////////////////////////////////////
typedef CEvBase
CEvUnixFileSystemExtends;

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvUnixFileSystemImplements
//
//   Author: $author$
//     Date: 8/11/2007
///////////////////////////////////////////////////////////////////////
typedef EvBase
CEvUnixFileSystemImplements;

///////////////////////////////////////////////////////////////////////
//  Class: CEvUnixFileSystem
//
// Author: $author$
//   Date: 8/11/2007
///////////////////////////////////////////////////////////////////////
class CEvUnixFileSystem
: virtual public CEvUnixFileSystemImplements,
  public CEvUnixFileSystemExtends
{
public:
    typedef CEvUnixFileSystemImplements CImplements;
    typedef CEvUnixFileSystemExtends CExtends;
    typedef CEvUnixFileSystem CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvUnixFileSystem
    //
    //       Author: $author$
    //         Date: 8/11/2007
    ///////////////////////////////////////////////////////////////////////
    CEvUnixFileSystem() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvUnixFileSystem
    //
    //      Author: $author$
    //        Date: 8/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvUnixFileSystem()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetFileTime
    //
    //   Author: $author$
    //     Date: 8/11/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetFileTime
    (const char* filename,
     const CEvUnixFileTime* changedTime,
     const CEvUnixFileTime* accessedTime,
     const CEvUnixFileTime* modifiedTime) 
    {
        EvError error = EV_ERROR_FAILED;
        int err;
		struct utimbuf ut;

        DBF("() in...\n");

        if (!accessedTime)
            error = EV_ERROR_NOT_IMPLEMENTED;
        else if (!modifiedTime)
                error = EV_ERROR_NOT_IMPLEMENTED;
        else 
		{
			ut.actime = accessedTime->m_time;
			ut.modtime = modifiedTime->m_time;
			if (!(err = utime(filename, &ut)))
                error = EV_ERROR_NONE;
		}
        DBF("() ...out\n");
        return error;
    }
};
#endif // _CEVUNIXFILESYSTEM_HPP
