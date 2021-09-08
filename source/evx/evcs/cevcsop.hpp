///////////////////////////////////////////////////////////////////////
//   File: cevcsop.hpp
//
// Author: $author$
//   Date: 5/29/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCSOP_HPP
#define _CEVCSOP_HPP

#include "evcsop.hpp"
#include "cevinstance.hpp"

#define CEVCSOP_FILE_MODE_WRITE_BINARY EVFILE_MODE_WRITE_BINARY
#define CEVCSOP_FILE_MODE_WRITE_TEXT EVFILE_MODE_WRITE_BINARY

#define CEVCSOP_FILE_MODE_READ_BINARY EVFILE_MODE_READ_BINARY
#define CEVCSOP_FILE_MODE_READ_TEXT EVFILE_MODE_READ_BINARY

///////////////////////////////////////////////////////////////////////
//  Class: CEvcsOp
//
// Author: $author$
//   Date: 5/29/2007
///////////////////////////////////////////////////////////////////////
class CEvcsOp
: virtual public EvcsOp,
  public CEvInstance
{
public:
    typedef EvcsOp CImplements;
    typedef CEvInstance CExtends;
    typedef CEvcsOp CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvcsOp
    //
    //       Author: $author$
    //         Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    CEvcsOp() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvcsOp
    //
    //      Author: $author$
    //        Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvcsOp()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OpenNext
    //
    //   Author: $author$
    //     Date: 8/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenNext
    (EvFileSystemEntry& fileEntry)
    {
        EvError error = EV_ERROR_NOT_ALLOWED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OpenNext
    //
    //   Author: $author$
    //     Date: 8/21/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OpenNext
    (CEvFilePath& filePath,
     EvFileSystemEntry& fileEntry)
    {
        EvError error = EV_ERROR_NOT_ALLOWED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Write
    //
    //   Author: $author$
    //     Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Write
    (const char* chars, LONG length=-1) 
    {
        length = -EV_ERROR_NOT_ALLOWED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 8/17/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (char* chars, ULONG size) 
    {
        LONG length = -EV_ERROR_NOT_ALLOWED;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Begin
    //
    //   Author: $author$
    //     Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Begin() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Continue
    //
    //   Author: $author$
    //     Date: 6/2/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Continue()
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Commit
    //
    //   Author: $author$
    //     Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Commit() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Cancel
    //
    //   Author: $author$
    //     Date: 5/29/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Cancel() 
    {
        EvError error = EV_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetStack
    //
    //   Author: $author$
    //     Date: 5/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetStack
    (EvcsOpStack* stack) 
    {
        EvError error = EV_ERROR_NOT_ALLOWED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetStack
    //
    //   Author: $author$
    //     Date: 5/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsOpStack* GetStack
    (EvError& error) const 
    {
        EvcsOpStack* stack = 0;
        error = EV_ERROR_NOT_ALLOWED;
        return stack;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetParent
    //
    //   Author: $author$
    //     Date: 5/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetParent
    (EvcsOp* parent) 
    {
        EvError error = EV_ERROR_NOT_ALLOWED;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetParent
    //
    //   Author: $author$
    //     Date: 5/30/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvcsOp* GetParent
    (EvError& error) const 
    {
        EvcsOp* parent = 0;
        error = EV_ERROR_NOT_ALLOWED;
        return parent;
    }
};
#endif // _CEVCSOP_HPP
